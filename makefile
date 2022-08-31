.SUFFIXES:

# ==================
# = PROJECT CONFIG =
# ==================

BUILD_NAME := fe6

SRC_DIR = src
ASM_DIR = asm
BUILD_DIR = build

# ====================
# = TOOL DEFINITIONS =
# ====================

ifeq ($(OS),Windows_NT)
  EXE := .exe
else
  EXE :=
endif

TOOLCHAIN ?= $(DEVKITARM)
AGBCC_HOME ?= tools/agbcc

ifneq (,$(TOOLCHAIN))
  export PATH := $(TOOLCHAIN)/bin:$(PATH)
endif

PREFIX := arm-none-eabi-

export OBJCOPY := $(PREFIX)objcopy
export AS := $(PREFIX)as
export CPP := $(PREFIX)cpp
export LD := $(PREFIX)ld
export STRIP := $(PREFIX)strip

CC1     := $(AGBCC_HOME)/bin/old_agbcc$(EXE)
CC1_NEW := $(AGBCC_HOME)/bin/agbcc$(EXE)

SHASUM ?= sha1sum

# ================
# = BUILD CONFIG =
# ================

CPPFLAGS := -I $(AGBCC_HOME)/include -iquote include -iquote . -nostdinc -undef
CFLAGS := -g -mthumb-interwork -Wimplicit -Wparentheses -Werror -fhex-asm -O2
ASFLAGS := -mcpu=arm7tdmi -I asm/include

LDS := $(BUILD_NAME).lds

ROM := $(BUILD_NAME).gba

ELF := $(ROM:%.gba=%.elf)
MAP := $(ROM:%.gba=%.map)

C_SRCS := $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/lib/*.c)
C_OBJS := $(C_SRCS:%.c=$(BUILD_DIR)/%.o)

ASM_SRCS := $(wildcard $(ASM_DIR)/*.s) $(wildcard $(ASM_DIR)/lib/*.s)
ASM_OBJS := $(ASM_SRCS:%.s=$(BUILD_DIR)/%.o)

DATA_SRCS := $(wildcard data/*.s)
DATA_OBJS := $(DATA_SRCS:%.s=$(BUILD_DIR)/%.o)

ALL_OBJS := $(C_OBJS) $(ASM_OBJS) $(DATA_OBJS)
ALL_DEPS := $(ALL_OBJS:%.o=%.d)

SUBDIRS := $(sort $(dir $(ALL_OBJS)))
$(shell mkdir -p $(SUBDIRS))

# ===========
# = RECIPES =
# ===========

compare: $(ROM)
	$(SHASUM) -c fe6.sha1

.PHONY: compare

clean:
	@echo "RM $(ROM) $(ELF) $(MAP) $(BUILD_DIR)/"
	@rm -f $(ROM) $(ELF) $(MAP) 
	@rm -fr $(BUILD_DIR)/

.PHONY: clean

%.gba: %.elf
	$(OBJCOPY) --strip-debug -O binary $< $@

$(ELF): $(ALL_OBJS) $(LDS)
	@echo "LD $(LDS) $(ALL_OBJS:$(BUILD_DIR)/%=%)"
	@cd $(BUILD_DIR) && $(LD) -T ../$(LDS) -Map ../$(MAP) -L../tools/agbcc/lib $(ALL_OBJS:$(BUILD_DIR)/%=%) -lc -lgcc -o ../$@

# C dependency file
$(BUILD_DIR)/%.d: %.c
	@$(CPP) $(CPPFLAGS) $< -o $@ -MM -MG -MT $@ -MT $(BUILD_DIR)/$*.o

# C object
$(BUILD_DIR)/%.o: %.c
	@echo "CC $<"
	@$(CPP) $(CPPFLAGS) $< | $(CC1) $(CFLAGS) -o $(BUILD_DIR)/$*.s
	@echo ".text\n\t.align\t2, 0\n" >> $(BUILD_DIR)/$*.s
	@$(AS) $(ASFLAGS) $(BUILD_DIR)/$*.s -o $@
	@$(STRIP) -N .gcc2_compiled. $@

# ASM dependency file (dummy, generated with the object)
$(BUILD_DIR)/%.d: $(BUILD_DIR)/%.o
	@touch $@

# ASM object
$(BUILD_DIR)/%.o: %.s
	@echo "AS $<"
	@$(AS) $(ASFLAGS) $< -o $@ --MD $(BUILD_DIR)/$*.d

ifneq (clean,$(MAKECMDGOALS))
  -include $(ALL_DEPS)
  .PRECIOUS: $(BUILD_DIR)/%.d
endif

# ======================
# = CFLAGS overrides =
# ======================

# not yet supported by agbcc :/
# %/main.o:            CFLAGS += -mtpcs-frame

%/irq.o:             CFLAGS += -O0
%/random.o:          CFLAGS += -O0
%/hardware.o:        CFLAGS += -O0
%/move.o:            CFLAGS += -O0
%/oam.o:             CFLAGS += -O0
%/sound.o:           CFLAGS += -O0
%/ramfunc.o:         CFLAGS += -O0
%/proc.o:            CFLAGS += -O0
%/icon.o:            CFLAGS += -O0
%/debug-text.o:      CFLAGS += -O0
%/text.o:            CFLAGS += -O0
%/banim-sprite.o:    CFLAGS += -O0
%/sprite.o:          CFLAGS += -O0
%/face.o:            CFLAGS += -O0
%/talk.o:            CFLAGS += -O0
%/event.o:           CFLAGS += -O0
%/sprite-anim.o:     CFLAGS += -O0
%/game-controller.o: CFLAGS += -O0
%/msg.o:             CFLAGS += -O0

%/mu.o:              CFLAGS += -O0
%/manim.o:           CFLAGS += -O0

%/agb-sram.o:        CFLAGS += -O1
