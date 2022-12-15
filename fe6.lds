OUTPUT_ARCH(arm)

gMusicPlayerTable       = 0x0839946C;
gSongTable              = 0x083994D8;

gNumMusicPlayers = 9;
gMaxLines = 0;

SECTIONS
{
    __ewram_overlay_beg = 0x02000000;
    __ewram_overlay_end = 0x02000000;

    . = __ewram_overlay_beg;
    ewram_overlay_0 (NOLOAD) : ALIGN(4)
    {
        . = 0x001000; gMapBuf = .; /* map */
        . = 0x001F70; gChapterIntroMotifTmBuf = .; /* bmfx */
        . = 0x002770; gFont_Unk_02002770 = .; /* mapmenu */
        . = 0x002788; gTradeMenuText = .; /* trademenu */
        . = 0x0027D8, gWeatherEffect = .; /* bmio */
        . = 0x002AD8; gWeatherGradient = .; /* bmio */
        . = 0x002FD8; gBattlePreviewLabels = .; /* battlepreview */
        . = 0x003008; gBattlePreviewIconPalBuf = .; /* battlepreview */
        . = 0x003108; gStatScreenSt = .; /* statscreen */
        . = 0x003238; gUnk_Tm_02003238 = .; /* statscreen? */
        . = 0x003738; gUnk_Tm_02003738 = .; /* statscreen? */
        . = 0x003C38; gUnk_Tm_02003C38 = .; /* statscreen? */

        . = 0x004138; gMuImgBuf = .; /* mu */
        . = 0x00C938; /* end */
    }
    __ewram_overlay_end = MAX(., __ewram_overlay_end);

    . = __ewram_overlay_beg;
    ewram_overlay_sio (NOLOAD) : ALIGN(4)
    {
        . = 0x000000; gUnk_Sio_02000000 = .;
        . = 0x001000; gFont_Unk_Sio_02001000 = .;
        . = 0x001018; gText_Unk_Sio_02001018 = .;
        /* gap? */
        . = 0x0012A0; gUnk_Sio_020012A0 = .;
        /* gap? */
        . = 0x001520; gUnk_Sio_02001520 = .;
        . = 0x001524; gUnk_Sio_02001524 = .;
        . = 0x001528; gUnk_Sio_02001528 = .;
        . = 0x00152C; gUnk_Sio_0200152C = .;
    }
    __ewram_overlay_end = MAX(., __ewram_overlay_end);

    . = __ewram_overlay_beg;
    ewram_overlay_banim (NOLOAD) : ALIGN(4)
    {
        . = 0x000000; gUnk_Banim_02000000 = .;
        . = 0x000010; gUnk_Banim_02000010 = .;
        . = 0x000014; gUnk_Banim_02000014 = .;
        . = 0x000018; gUnk_Banim_02000018 = .;
        . = 0x00001C; gUnk_Banim_0200001C = .;
        . = 0x000020; gUnk_Banim_02000020 = .;
        . = 0x000024; gUnk_Banim_02000024 = .;
        . = 0x000028; gUnk_Banim_02000028 = .;
        . = 0x00002C; gUnk_Banim_0200002C = .;
        . = 0x000030; gUnk_Banim_02000030 = .;
        . = 0x000034; gUnk_Banim_02000034 = .;
        . = 0x00003C; gUnk_Banim_0200003C = .;
        . = 0x000044; gUnk_Banim_02000044 = .;
        . = 0x00004C; gUnk_Banim_0200004C = .;
        . = 0x000054; gUnk_Banim_02000054 = .;
        . = 0x000058; gUnk_Banim_02000058 = .;
        . = 0x00005C; gUnk_Banim_0200005C = .;
        . = 0x000060; gUnk_Banim_02000060 = .;
        . = 0x000064; gUnk_Banim_02000064 = .;
        . = 0x000080; gUnk_Banim_02000080 = .;
        . = 0x001080; gUnk_Banim_02001080 = .;
        . = 0x002080; gUnk_Banim_02002080 = .;
        . = 0x003080; gUnk_Banim_02003080 = .;
        . = 0x004080; gUnk_Banim_02004080 = .;
        . = 0x004120; gUnk_Banim_02004120 = .;
        . = 0x0041C0; gUnk_Banim_020041C0 = .;
        . = 0x0099B0; gUnk_Banim_020099B0 = .;
        . = 0x0099C0; gUnk_Banim_020099C0 = .;
        . = 0x00F1C0; gUnk_Banim_0200F1C0 = .;
        . = 0x011BC0; gUnk_Banim_02011BC0 = .;
        . = 0x0145C0; gUnk_Banim_020145C0 = .;
        . = 0x014DC0; gUnk_Banim_02014DC0 = .;
        . = 0x0165C0; gUnk_Banim_020165C0 = .;
        . = 0x0169C0; gUnk_Banim_020169C0 = .;
        . = 0x016DC0; gUnk_Banim_02016DC0 = .;
        . = 0x016E40; gUnk_Banim_02016E40 = .;
        . = 0x017040; gUnk_Banim_02017040 = .;
        . = 0x017240; gUnk_Banim_02017240 = .;
        . = 0x017440; gUnk_Banim_02017440 = .;
        . = 0x017640; gUnk_Banim_02017640 = .;
        . = 0x017658; gUnk_Banim_02017658 = .;
        . = 0x017660; gUnk_Banim_02017660 = .;
        . = 0x017668; gUnk_Banim_02017668 = .;
        . = 0x017670; gUnk_Banim_02017670 = .;
        . = 0x017698; gUnk_Banim_02017698 = .;
        . = 0x0176D8; gUnk_Banim_020176D8 = .;
        . = 0x0176E8; gUnk_Banim_020176E8 = .;
        . = 0x0176F8; gUnk_Banim_020176F8 = .;
        . = 0x01771C; gUnk_Banim_0201771C = .;
        . = 0x017720; gUnk_Banim_02017720 = .;
        . = 0x017724; gUnk_Banim_02017724 = .;
        . = 0x017728; gUnk_Banim_02017728 = .;
        . = 0x01772C; gUnk_Banim_0201772C = .;
        . = 0x017730; gUnk_Banim_02017730 = .;
        . = 0x017734; gUnk_Banim_02017734 = .;
        . = 0x017738; gUnk_Banim_02017738 = .;
        . = 0x01773C; gUnk_Banim_0201773C = .;
        . = 0x017740; gUnk_Banim_02017740 = .;
        . = 0x017744; gUnk_Banim_02017744 = .;
        . = 0x017748; gUnk_Banim_02017748 = .;
        . = 0x01774C; gUnk_Banim_0201774C = .;
        . = 0x017750; gUnk_Banim_02017750 = .;
        . = 0x017754; gUnk_Banim_02017754 = .;
        . = 0x017758; gUnk_Banim_02017758 = .;
        . = 0x01775C; gUnk_Banim_0201775C = .;
        . = 0x017760; gUnk_Banim_02017760 = .;
        . = 0x017764; gUnk_Banim_02017764 = .;
        . = 0x01776C; gUnk_Banim_0201776C = .;
        . = 0x017770; gUnk_Banim_02017770 = .;
        . = 0x017774; gUnk_Banim_02017774 = .;
        . = 0x017778; gUnk_Banim_02017778 = .;
        . = 0x01777C; gUnk_Banim_0201777C = .;
        . = 0x01947C; gUnk_Banim_0201947C = .;
        . = 0x01977C; gUnk_Banim_0201977C = .;
        . = 0x019F7C; gUnk_Banim_02019F7C = .;
        . = 0x01A77C; gUnk_Banim_0201A77C = .;
        . = 0x01AF7C; gUnk_Banim_0201AF7C = .;
        . = 0x01B77C; gUnk_Banim_0201B77C = .;
        . = 0x01C77C; gUnk_Banim_0201C77C = .;
        . = 0x01C8BC; gUnk_Banim_0201C8BC = .;
        . = 0x01C8FE; gUnk_Banim_0201C8FE = .;
        . = 0x01CF70; gUnk_Banim_0201CF70 = .;
        . = 0x01D414; gUnk_Banim_0201D414 = .;
        . = 0x01D424; gUnk_Banim_0201D424 = .;
        . = 0x01D456; gUnk_Banim_0201D456 = .;
        . = 0x01DF6C; gUnk_Banim_0201DF6C = .;
        . = 0x01DFCC; gUnk_Banim_0201DFCC = .;
        . = 0x01E02C; gUnk_Banim_0201E02C = .;
        . = 0x01E0EC; gUnk_Banim_0201E0EC = .;
        . = 0x01E0F0; gUnk_Banim_0201E0F0 = .;
        . = 0x01E0F4; gUnk_Banim_0201E0F4 = .;
        . = 0x01E0F8; gUnk_Banim_0201E0F8 = .;
        . = 0x01E0FC; gUnk_Banim_0201E0FC = .;
        . = 0x01E124; gUnk_Banim_0201E124 = .;
        . = 0x01E12C; gUnk_Banim_0201E12C = .;
        . = 0x01E138; gUnk_Banim_0201E138 = .;
        . = 0x01E13C; gUnk_Banim_0201E13C = .;
        . = 0x01E144; gUnk_Banim_0201E144 = .;
        . = 0x01E14C; gUnk_Banim_0201E14C = .;
        . = 0x01E150; gUnk_Banim_0201E150 = .;
        . = 0x01E154; gUnk_Banim_0201E154 = .;
        . = 0x01E158; gUnk_Banim_0201E158 = .;
        . = 0x01E298; gUnk_Banim_0201E298 = .;
        . = 0x01E3D8; gUnk_Banim_0201E3D8 = .;
        . = 0x01E3DC; gUnk_Banim_0201E3DC = .;
        . = 0x01E3E0; gUnk_Banim_0201E3E0 = .;
        . = 0x01E3E4; gUnk_Banim_0201E3E4 = .;
        . = 0x01E524; gUnk_Banim_0201E524 = .;
        . = 0x01E7A4; gUnk_Banim_0201E7A4 = .;
        . = 0x01E7A8; gUnk_Banim_0201E7A8 = .;
        . = 0x01E7AC; gUnk_Banim_0201E7AC = .;
        . = 0x01E7B4; gUnk_Banim_0201E7B4 = .;
        . = 0x01E7BC; gUnk_Banim_0201E7BC = .;
        . = 0x01E7C0; gUnk_Banim_0201E7C0 = .;
        . = 0x01E7C4; gUnk_Banim_0201E7C4 = .;
        . = 0x01E7C8; gUnk_Banim_0201E7C8 = .;
        . = 0x01E7CC; gUnk_Banim_0201E7CC = .;
        . = 0x01EFCC; gUnk_Banim_0201EFCC = .;
        . = 0x01EFEC; gUnk_Banim_0201EFEC = .;
        . = 0x01F00C; gUnk_Banim_0201F00C = .;
        . = 0x01F04C; gUnk_Banim_0201F04C = .;
        . = 0x01F050; gUnk_Banim_0201F050 = .;
        . = 0x01F054; gUnk_Banim_0201F054 = .;
        . = 0x01F058; gUnk_Banim_0201F058 = .;
        . = 0x01F05C; gUnk_Banim_0201F05C = .;
        . = 0x01F07C; gUnk_Banim_0201F07C = .;
        . = 0x01F080; gUnk_Banim_0201F080 = .;
        . = 0x01F084; gUnk_Banim_0201F084 = .;
        . = 0x01F0AC; gUnk_Banim_0201F0AC = .;
        . = 0x01F0B0; gUnk_Banim_0201F0B0 = .;
        . = 0x01F0B4; gUnk_Banim_0201F0B4 = .;
        . = 0x01F0B6; gUnk_Banim_0201F0B6 = .;
        . = 0x01F0B8; gUnk_Banim_0201F0B8 = .;
        . = 0x01F0C8; gUnk_Banim_0201F0C8 = .;
        . = 0x01F0D8; gUnk_Banim_0201F0D8 = .;
        . = 0x01F0DA; gUnk_Banim_0201F0DA = .;
        . = 0x01F0DC; gUnk_Banim_0201F0DC = .;
        . = 0x01F0E0; gUnk_Banim_0201F0E0 = .;
        . = 0x01F0E4; gUnk_Banim_0201F0E4 = .;
        . = 0x01F0E8; /* end */
    }
    __ewram_overlay_end = MAX(., __ewram_overlay_end);

    . = __ewram_overlay_end;
    ewram_data (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/hardware.o(ewram_data);
        . = ALIGN(4); src/move.o(ewram_data);
        . = ALIGN(4); src/sound.o(ewram_data);
        . = ALIGN(4); src/proc.o(ewram_data);
        . = ALIGN(4); src/icon.o(ewram_data);
        . = ALIGN(4); src/debugtext.o(ewram_data);
        . = ALIGN(4); src/text.o(ewram_data);
        . = ALIGN(4); src/banim_sprite.o(ewram_data);
        . = ALIGN(4); src/sprite.o(ewram_data);
        . = ALIGN(4); src/face.o(ewram_data);
        . = ALIGN(4); src/msg.o(ewram_data);
        . = ALIGN(4); src/util.o(ewram_data);
        . = ALIGN(4); src/bm.o(ewram_data);
        . = ALIGN(4); src/unit.o(ewram_data);
        . = ALIGN(4); src/map.o(ewram_data);
        . = ALIGN(4); src/mapwork.o(ewram_data);
        . = ALIGN(4); src/targetlist.o(ewram_data);
        . = ALIGN(4); src/unitsprite.o(ewram_data);
        . = ALIGN(4); src/battle.o(ewram_data);
        . = ALIGN(4); src/trap.o(ewram_data);
        . = ALIGN(4); src/supply.o(ewram_data);
        . = ALIGN(4); src/unitrearrange.o(ewram_data);
        . = ALIGN(4); src/arena.o(ewram_data);
        . = ALIGN(4); src/action.o(ewram_data);
        . = ALIGN(4); src/movepath.o(ewram_data);
        . = ALIGN(4); src/unitpanel.o(ewram_data);
        . = ALIGN(4); src/ai_phase.o(ewram_data);
        . = ALIGN(4); src/ai_decide.o(ewram_data);
        . = ALIGN(4); src/ai_080326C4.o(ewram_data);

        . = 0x0203C9D4 - __ewram_overlay_end;
        . = ALIGN(4); src/ui.o(ewram_data);
        . = ALIGN(4); src/mapselect.o(ewram_data);
        . = ALIGN(4); . = . + 0x100; /* TODO */
        . = ALIGN(4); src/manim.o(ewram_data);

        . = 0x0203D3DC - __ewram_overlay_end;
        . = ALIGN(4); src/statscreen.o(ewram_data);
        . = ALIGN(4); src/helpbox.o(ewram_data);

        . = 0x02040000 - __ewram_overlay_end; /* end */
    }

    . = 0x03000000;
    IWRAM (NOLOAD) : ALIGN(4)
    {
        /* .bss */
        . = ALIGN(4); src/random.o(.bss);
        . = ALIGN(4); src/hardware.o(.bss);
        . = ALIGN(4); src/oam.o(.bss);
        . = ALIGN(4); src/talk.o(.bss);
        . = ALIGN(4); src/event.o(.bss);
        . = ALIGN(4); src/spriteanim.o(.bss);
        . = ALIGN(4); src/util.o(.bss);
        . = ALIGN(4); src/map.o(.bss);
        . = ALIGN(4); src/ai_script.o(.bss);
        . = ALIGN(4); src/ai_battle.o(.bss);

        . = 0x0013B8; gUnk_030013B8 = .;
        . = 0x0013BC; gUnk_030013BC = .;
        . = 0x0013C0; gUnk_030013C0 = .;
        . = 0x0013C4; gUnk_030013C4 = .;
        . = 0x0013C8; gUnk_030013C8 = .;
        . = 0x0013CA; gUnk_030013CA = .;
        . = 0x0013D0; gUnk_030013D0 = .;
        . = 0x0013D8; gUnk_030013D8 = .;
        . = 0x0013E0; gUnk_030013E0 = .;
        . = 0x0013E4; gUnk_030013E4 = .;
        . = 0x0013E8; gUnk_030013E8 = .;
        . = 0x0013F0; gUnk_030013F0 = .;
        . = 0x001404; gUnk_03001404 = .;
        . = 0x001408; gUnk_03001408 = .;
        . = 0x00140C; gUnk_0300140C = .;
        . = 0x001410; gUnk_03001410 = .;
        . = 0x001418; gUnk_03001418 = .;
        . = 0x001428; gUnk_03001428 = .;
        . = 0x001438; gUnk_03001438 = .;

        . = 0x001440; src/mu.o(.bss);

        . = 0x001570; gUnk_03001570 = .;

        . = 0x002158; src/gbasram.o(.bss);
        . = ALIGN(4); *libgcc.a:dp-bit.o(.bss);
        . = ALIGN(4); *libgcc.a:fp-bit.o(.bss);

        . = ALIGN(4); *(.iwram.SoundMainRam);

        /* COMMON */
        . = 0x0026A0; gOamLoPutIt = .;
        . = 0x0026B0; gDispIo = .;
        . = 0x0026E4; gUnk_Banim_030026E4 = .;
        . = 0x0026F4; gUnk_030026F4 = .;
        . = 0x0026F5; gUnk_030026F5 = .;
        . = 0x0026F8; gUnk_030026F8 = .;
        . = 0x0026FA; gUnk_030026FA = .;
        . = 0x0026FE; gUnk_030026FE = .;
        . = 0x002708; gUnk_03002708 = .;
        . = 0x002720; gIrqFuncs = .;
        . = 0x002758; MapFloodCoreRamFunc = .;
        . = 0x00275C; gOamAffinePutId = .;
        . = 0x002760; PutOamHiRamFunc = .;
        . = 0x002764; gOnHBlankA = .;
        . = 0x002770; gOam = .;
        . = 0x002D70; DrawGlyphRamFunc = .;
        . = 0x002D74; gOamHiPutIt = .;
        . = 0x002D78; gOnHBlankB = .;
        . = 0x002D80; RamFuncArea = .;
        . = 0x003780; DecodeStringRamFunc = .;
        . = 0x003784; PutOamLoRamFunc = .;
        . = 0x003788; gOamAffinePutIt = .;
        . = 0x003790; IntrMainRam = .;
        . = 0x003F90; MapFloodCoreStepRamFunc = .;
        . = 0x003FA0; gEventScriptQueueIt = .;
        . = 0x003FB0; gEventScriptQueue = .;
        . = 0x003FD0; gSpriteAllocIt = .;
        . = 0x004000; gFaces = .;
        . = 0x004010; gWorkingMap = .;
        . = 0x004020; gMapFloodSquareBufB = .;
        . = 0x004220; gWorkingMovTable = .;
        . = 0x004260; gStatGainSimUnit = .;
        . = 0x0042B0; gMapFloodSquareBufA = .;
        . = 0x0044B0; gActiveUnit = .;
        . = 0x0044C0; gMapFloodSt = .;
        . = 0x0044D0; gUnk_030044D0 = .;
        . = 0x0044D4; gUnk_030044D4 = .;
        . = 0x0044E0; gUnk_030044E0 = .;
        . = 0x0044E6; gUnk_030044E6 = .;
        . = 0x004568; gUnk_03004568 = .;
        . = 0x00456C; gUnk_0300456C = .;
        . = 0x004570; AiDecideFunc = .;
        . = 0x004580; gUnk_03004580 = .;
        . = 0x004600; gManimDebugStObj = .;
        . = 0x0046D0; gUnk_030046D0 = .;
        . = 0x004750; gUnk_03004750 = .;
        . = 0x004890; gPermanentFlagBits = .;
        . = 0x004898; gChapterFlagBits = .;
        . = 0x0048A4; gUnk_030048A4 = .;
        . = 0x0048A8; gUnk_030048A8 = .;
        . = 0x0048B8; gUnk_030048B8 = .;
        . = 0x0048C0; gUnk_030048C0 = .;
        . = 0x0048D4; gUnk_030048D4 = .;
        . = 0x0048E0; gUnk_030048E0 = .;
        . = 0x005280; gUnk_03005280 = .;
        . = 0x005284; gUnk_03005284 = .;
        . = 0x005290; gUnk_03005290 = .;
        . = 0x0052B0; *(.iwram.gSoundInfo);
        . = 0x006260; gMusicPlayer_03006260 = .;
        . = 0x0062A0; gMusicPlayer_030062A0 = .;
        . = 0x0062E0; gMusicPlayer_FightBgm = .;
        . = 0x006320; *(.iwram.gMPlayJumpTable);
        . = 0x0063B0; *(.iwram.gCgbChans);
        . = 0x0064B0; gMusicPlayer_030064B0 = .;
        . = 0x0064F0; gMusicPlayer_MainBgm = .;
        . = 0x006530; gMusicPlayer_03006530 = .;
        . = 0x006570; gMusicPlayer_03006570 = .;
        . = 0x0065B0; *(.iwram.gMPlayMemAccArea);
        . = 0x006600; gMusicPlayer_03006600 = .;
        . = 0x006640; ReadSramFast = .;
        . = 0x006644; VerifySramFast = .;

        . = 0x008000; /* end */
    }

    . = 0x08000000;
    ROM : ALIGN(4)
    {
        asm/crt0.o(.text);
        asm/arm.o(.text);

        src/main.o(.text);
        src/irq.o(.text);
        src/random.o(.text);
        src/hardware.o(.text);
        src/move.o(.text);
        src/oam.o(.text);
        src/sound.o(.text);
        src/ramfunc.o(.text);
        src/proc.o(.text);
        src/icon.o(.text);
        src/debugtext.o(.text);
        src/text.o(.text);
        src/banim_sprite.o(.text);
        src/sprite.o(.text);
        src/face.o(.text);
        src/talk.o(.text);
        src/event.o(.text);
        src/spriteanim.o(.text);
        src/gamecontroller.o(.text);
        src/msg.o(.text);
        src/util.o(.text);
        src/bm.o(.text);
        src/item.o(.text);
        src/unit.o(.text);
        src/map.o(.text);
        src/mapwork.o(.text);
        src/debugmenu.o(.text);
        src/playerphase.o(.text);
        src/bmfx.o(.text);
        src/mapmenu.o(.text);
        src/faction.o(.text);
        src/gold.o(.text);
        src/targetlist.o(.text);
        src/unitsprite.o(.text);
        src/support.o(.text);
        src/itemuse.o(.text);
        src/battle.o(.text);
        src/trademenu.o(.text);
        src/trap.o(.text);
        src/itemaction.o(.text);
        src/bmio.o(.text);
        src/chapter.o(.text);
        src/supply.o(.text);
        src/unitrearrange.o(.text);
        src/arena.o(.text);
        src/action.o(.text);
        src/movepath.o(.text);
        src/prepphase.o(.text);
        src/code_0802B814.o(.text);
        src/chapterinfo.o(.text);
        src/unitpanel.o(.text);
        src/subtitlehelp.o(.text);
        src/masseffect.o(.text);
        src/battlepreview.o(.text);
        src/ai_phase.o(.text);
        src/ai_order.o(.text);
        src/ai_decide.o(.text);
        src/ai_perform.o(.text);
        src/ai_utility.o(.text);
        src/ai_script.o(.text);
        src/ai_battle.o(.text);
        src/ai_080326C4.o(.text);
        asm/code-ai.o(.text);
        asm/code-sio.o(.text);
        src/ui.o(.text);
        src/menu.o(.text);
        src/mapselect.o(.text);
        asm/code-banim.o(.text);
        src/mu.o(.text);
        src/manim.o(.text);
        asm/code-manim.o(.text);
        src/eventinfo.o(.text);
        src/eventfunctions.o(.text);
        asm/code_eventfunctions.o(.text);
        src/statscreen.o(.text);
        src/helpbox.o(.text);
        asm/code_mapui.o(.text);
        asm/code_sioerror.o(.text);

        asm/code.o(.text);

        src/m4a_1.o(.text);
        src/m4a.o(.text);
        asm/gbasyscall.o(.text);
        src/gbasram.o(.text);
        *libgcc.a:_ashldi3.o(.text);
        *libgcc.a:_call_via_rX.o(.text);
        *libgcc.a:_divsi3.o(.text);
        *libgcc.a:_dvmd_tls.o(.text);
        *libgcc.a:_modsi3.o(.text);
        *libgcc.a:_udivsi3.o(.text);
        *libgcc.a:_umodsi3.o(.text);
        *libgcc.a:dp-bit.o(.text);
        *libgcc.a:fp-bit.o(.text);
        *libgcc.a:_lshrdi3.o(.text);
        *libgcc.a:_muldi3.o(.text);
        *libgcc.a:_negdi2.o(.text);
        *libc.a:memcpy.o(.text);
        *libc.a:memset.o(.text);
        *libc.a:strcpy.o(.text);

        asm/code_blx_stub.o(.text);

        /* .rodata */
        . = ALIGN(4); data/rodata_msg.o(.rodata);
        . = ALIGN(4); src/main.o(.rodata);
        . = ALIGN(4); src/irq.o(.rodata);
        . = ALIGN(4); src/random.o(.rodata);
        . = ALIGN(4); src/hardware.o(.rodata);
        . = ALIGN(4); data/rodata_trig.o(.rodata);
        . = ALIGN(4); src/move.o(.rodata);
        . = ALIGN(4); src/oam.o(.rodata);
        . = ALIGN(4); src/sound.o(.rodata);
        . = ALIGN(4); src/ramfunc.o(.rodata);
        . = ALIGN(4); data/rodata_icon.o(.rodata);
        . = ALIGN(4); src/proc.o(.rodata);
        . = ALIGN(4); src/icon.o(.rodata);
        . = ALIGN(4); src/debugtext.o(.rodata);
        . = ALIGN(4); src/text.o(.rodata);
        . = ALIGN(4); src/banim_sprite.o(.rodata);
        . = ALIGN(4); src/sprite.o(.rodata);
        . = ALIGN(4); src/face.o(.rodata);
        . = ALIGN(4); src/talk.o(.rodata);
        . = ALIGN(4); src/event.o(.rodata);
        . = ALIGN(4); src/spriteanim.o(.rodata);
        . = ALIGN(4); src/gamecontroller.o(.rodata);
        . = ALIGN(4); src/msg.o(.rodata);
        . = ALIGN(4); src/util.o(.rodata);
        . = ALIGN(4); data/rodata_1004A4.o(.rodata);
        . = ALIGN(4); src/item.o(.rodata);
        . = ALIGN(4); src/unit.o(.rodata);
        . = ALIGN(4); src/debugmenu.o(.rodata);
        . = ALIGN(4); src/bmfx.o(.rodata);
        . = ALIGN(4); src/unitsprite.o(.rodata);
        . = ALIGN(4); src/support.o(.rodata);
        . = ALIGN(4); src/battle.o(.rodata);
        . = ALIGN(4); src/trademenu.o(.rodata);
        . = ALIGN(4); src/menuinfo.o(.rodata);
        . = ALIGN(4); src/bmio.o(.rodata);
        . = ALIGN(4); src/chapter.o(.rodata);
        . = ALIGN(4); src/arena.o(.rodata);
        . = ALIGN(4); src/unitpanel.o(.rodata);
        . = ALIGN(4); src/battlepreview.o(.rodata);
        . = ALIGN(4); data/rodata_105DD0.o(.rodata);
        . = ALIGN(4); src/ai_order.o(.rodata);
        . = ALIGN(4); src/ai_perform.o(.rodata);
        . = ALIGN(4); src/ai_utility.o(.rodata);
        . = ALIGN(4); src/ai_script.o(.rodata);
        . = ALIGN(4); src/ai_data.o(.rodata);
        . = ALIGN(4); src/ai_battle.o(.rodata);
        . = ALIGN(4); src/ai_080326C4.o(.rodata);

        . = ALIGN(4); src/code_sio.o(.rodata);
        . = ALIGN(4); data/data-code-sio.o(.rodata);
        . = ALIGN(4); src/ui.o(.rodata);
        . = ALIGN(4); data/rodata_10F744.o(.rodata);
        . = ALIGN(4); src/mu.o(.rodata);
        . = ALIGN(4); data/rodata_307544.o(.rodata);
        . = ALIGN(4); src/statscreen.o(.rodata);
        . = ALIGN(4); src/systemlabels.o(.rodata);
        . = ALIGN(4); src/helpbox.o(.rodata);
        . = ALIGN(4); data/rodata.o(.rodata);

        . = ALIGN(4); src/m4a.o(.rodata);
        . = ALIGN(4); data/rodata_lib.o(.rodata);

        /* .data */
        . = ALIGN(4); src/hardware.o(.data);
        . = ALIGN(4); src/sound.o(.data);
        . = ALIGN(4); src/proc.o(.data);
        . = ALIGN(4); data/data_dbgfont.o(.data);
        . = ALIGN(4); src/text.o(.data);
        . = ALIGN(4); data/data_textglyphs.o(.data);
        . = ALIGN(4); src/sprite.o(.data);
        . = ALIGN(4); src/face.o(.data);
        . = ALIGN(4); src/talk.o(.data);
        . = ALIGN(4); src/event.o(.data);
        . = ALIGN(4); src/spriteanim.o(.data);
        . = ALIGN(4); src/gamecontroller.o(.data);
        . = ALIGN(4); src/util.o(.data);
        . = ALIGN(4); src/bm.o(.data);
        . = ALIGN(4); src/unit.o(.data);
        . = ALIGN(4); src/map.o(.data);
        . = ALIGN(4); src/debugmenu.o(.data);
        . = ALIGN(4); src/playerphase.o(.data);
        . = ALIGN(4); src/bmfx.o(.data);
        . = ALIGN(4); src/mapmenu.o(.data);
        . = ALIGN(4); src/unitsprite.o(.data);
        . = ALIGN(4); src/support.o(.data);
        . = ALIGN(4); src/itemuse.o(.data);
        . = ALIGN(4); src/battle.o(.data);
        . = ALIGN(4); src/trademenu.o(.data);
        . = ALIGN(4); src/trap.o(.data);
        . = ALIGN(4); src/itemaction.o(.data);
        . = ALIGN(4); src/menuinfo.o(.data);
        . = ALIGN(4); src/bmio.o(.data);
        . = ALIGN(4); src/chapter.o(.data);
        . = ALIGN(4); src/arena.o(.data);
        . = ALIGN(4); src/action.o(.data);
        . = ALIGN(4); src/movepath.o(.data);
        . = ALIGN(4); src/prepphase.o(.data);
        . = ALIGN(4); src/unitpanel.o(.data);
        . = ALIGN(4); src/subtitlehelp.o(.data);
        . = ALIGN(4); src/masseffect.o(.data);
        . = ALIGN(4); src/battlepreview.o(.data);
        . = ALIGN(4); src/ai_phase.o(.data);
        . = ALIGN(4); src/ai_order.o(.data);
        . = ALIGN(4); src/ai_decide.o(.data);
        . = ALIGN(4); src/ai_perform.o(.data);
        . = ALIGN(4); src/ai_utility.o(.data);
        . = ALIGN(4); src/ai_data.o(.data);
        . = ALIGN(4); src/ai_battle.o(.data);
        . = ALIGN(4); src/ai_080326C4.o(.data);
        . = ALIGN(4); data/data-code-sio.o(.data);
        . = ALIGN(4); src/ui.o(.data);
        . = ALIGN(4); src/menu.o(.data);
        . = ALIGN(4); src/mapselect.o(.data);
        . = ALIGN(4); data/data-code-banim.o(.data);
        . = ALIGN(4), data/data-game-info.o(.data);
        . = ALIGN(4); src/mu.o(.data);
        . = ALIGN(4); data/data-code-mu.o(.data);
        . = ALIGN(4); src/manim.o(.data);
        . = ALIGN(4); data/data-code-manim.o(.data);
        . = ALIGN(4); src/eventinfo.o(.data);
        . = ALIGN(4); data/data_66618C.o(.data);
        . = ALIGN(4); src/statscreen.o(.data);
        . = ALIGN(4); src/helpbox.o(.data);
        . = ALIGN(4); data/data.o(.data_helpbox);
        . = ALIGN(4); src/systemlabels.o(.data);
        . = ALIGN(4); data/data.o(.data);

        . = ALIGN(4); FILL(0xFF);

        . = 0x6A0000; data/data-banim.o(.data);

        . = ALIGN(4); FILL(0xFF);

        . = 0x800000; /* end */
    } = 0

    /* DWARF 2 sections */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    .debug_info     0 : { *(.debug_info) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }

    /* Discard everything not specifically mentioned above. */
    /DISCARD/ :
    {
        *(*);
    }
}
