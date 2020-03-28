
ifeq ($(OS),Windows_NT)
  EXE := .exe
else
  EXE :=
endif

UNAME := $(shell uname)

CC1     := tools/agbcc/bin/old_agbcc$(EXE)
CC1_NEW := tools/agbcc/bin/agbcc$(EXE)

PREFIX := $(LOCAL_PREFIX)arm-none-eabi-

CPP := $(PREFIX)cpp$(EXE)
AS := $(PREFIX)as$(EXE)
LD := $(PREFIX)ld$(EXE)
OBJCOPY := $(PREFIX)objcopy$(EXE)

SHASUM := sha1sum

CC1FLAGS := -mthumb-interwork -Wimplicit -Wparentheses -Werror -fhex-asm -O2
CPPFLAGS := -I tools/agbcc/include -iquote include -iquote . -nostdinc -undef
ASFLAGS  := -mcpu=arm7tdmi -mthumb-interwork -I asm/include

ROM          := fe6.gba
ELF          := $(ROM:.gba=.elf)
MAP          := $(ROM:.gba=.map)
LDSCRIPT     := ldscr.txt
SYM_FILES    := 
CFILES       := $(wildcard src/*.c)
ASM_S_FILES  := $(wildcard asm/*.s)
LIBC_S_FILES := $(wildcard asm/libc/*.s)
DATA_S_FILES := $(wildcard data/*.s)
SFILES       := $(ASM_S_FILES) $(LIBC_S_FILES) $(DATA_S_FILES)
C_OBJECTS    := $(CFILES:.c=.o)
ASM_OBJECTS  := $(SFILES:.s=.o)
ALL_OBJECTS  := $(C_OBJECTS) $(ASM_OBJECTS)
DEPS_DIR     := .dep

src/irq.o:            CC1FLAGS += -O0
src/random.o:         CC1FLAGS += -O0
src/hardware.o:       CC1FLAGS += -O0
src/move.o:           CC1FLAGS += -O0
src/oam.o:            CC1FLAGS += -O0
src/sound.o:          CC1FLAGS += -O0
src/ramfunc.o:        CC1FLAGS += -O0
src/proc.o:           CC1FLAGS += -O0
src/icon.o:           CC1FLAGS += -O0
src/debug-text.o:     CC1FLAGS += -O0
src/text.o:           CC1FLAGS += -O0
src/banim-sprite.o:   CC1FLAGS += -O0
src/sprite.o:         CC1FLAGS += -O0
src/face.o:           CC1FLAGS += -O0
src/talk.o:           CC1FLAGS += -O0
src/dispos-helpers.o: CC1FLAGS += -O0
src/popup.o:          CC1FLAGS += -O0

src/agb_sram.o:       CC1FLAGS += -O1

compare: $(ROM)
	$(SHASUM) -c fe6.sha1

clean:
	$(RM) $(ROM) $(ELF) $(MAP) $(ALL_OBJECTS) src/*.s graphics/*.h
	$(RM) -rf $(DEPS_DIR)

MAKEDEP = mkdir -p $(DEPS_DIR)/$(dir $*) && $(CPP) $(CPPFLAGS) $< -MM -MG -MT $*.o > $(DEPS_DIR)/$*.d

-include $(addprefix $(DEPS_DIR)/,$(CFILES:.c=.d))

$(DEPS_DIR)/%.d: %.c
	@$(MAKEDEP)

$(ELF): $(ALL_OBJECTS) $(LDSCRIPT) $(SYM_FILES)
	$(LD) -T $(LDSCRIPT) -Map $(MAP) $(ALL_OBJECTS) tools/agbcc/lib/libgcc.a tools/agbcc/lib/libc.a -o $@

%.gba: %.elf
	$(OBJCOPY) --strip-debug -O binary --pad-to 0x8800000 --gap-fill=0xff $< $@

$(C_OBJECTS): %.o: %.c $(DEPS_DIR)/%.d
	@$(MAKEDEP)
	$(CPP) $(CPPFLAGS) $< | $(CC1) $(CC1FLAGS) -o $*.s
	echo '.text' >> $*.s
	echo '.align 2, 0' >> $*.s
	$(AS) $(ASFLAGS) $*.s -o $@

.SECONDEXPANSION:
$(ASM_OBJECTS): %.o: %.s
	$(AS) $(ASFLAGS) -g $< -o $@

# Don't delete intermediate files
.SECONDARY:
