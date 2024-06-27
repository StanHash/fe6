OUTPUT_ARCH(arm)

gMusicPlayerTable       = 0x0839946C;
gSongTable              = 0x083994D8;

gNumMusicPlayers = 9;
gMaxLines = 0;

SECTIONS
{
    __ewram_overlay_beg = 0x02000000;
    __ewram_overlay_end = __ewram_overlay_beg;

    /* I wonder if there's not two distinct overlays here */
    /* or one with one instance split in two? */

    . = __ewram_overlay_beg;
    ewram_overlay_0 (NOLOAD) : ALIGN(4)
    {
        . = 0x000000; gMinimapWinBuf = .; /* minimap */
        . = 0x000500; gMinimapFrontWinBuf = .; /* minimap */
        . = 0x000504; gMinimapBackWinBuf = .; /* minimap */
        . = 0x000508; gMinimapDisplayedWinBuf = .; /* minimap */
        . = 0x00050C; gMinimapObjectFlashPal = .; /* minimap */
        /* skip */
        . = 0x001000; gMapBuf = .; /* map */
        . = 0x001F70; gChapterIntroMotifTmBuf = .; /* bmfx */
        . = 0x002770; gFont_Unk_02002770 = .; /* mapmenu */
        . = 0x002788; gTradeMenuText = .; /* trademenu */
        . = 0x0027D8, gWeatherEffect = .; /* bmio */
        . = 0x002AD8; gWeatherGradient = .; /* bmio */
        . = 0x002FD8; gBattlePreviewLabels = .; /* battlepreview */
        . = 0x003008; gBattlePreviewIconPalBuf = .; /* battlepreview */
        . = 0x003108; gStatScreenSt = .; /* statscreen */
        . = 0x003238; gUiTmScratchA = .; /* statscreen? size = 0x500 */
        . = 0x003738; gUiTmScratchB = .; /* statscreen? size = 0x500 */
        . = 0x003C38; gUiTmScratchC = .; /* statscreen? size = 0x480? */
        . = 0x0040B8; gStatusScreenSt = .; /* statusscreen (almost statscreen but not quite) */
        . = 0x004138; gMuImgBuf = .; /* mu. size = 0x8800 */
        . = 0x00C938; gSortedUnitsBuf = .; /* unitlistscreen */
        . = 0x00CC38; gSortedUnits = .; /* unitlistscreen */
        . = 0x00CD38; gUnk_0200CD38 = .;
        . = 0x00CD3A; gUnk_0200CD3A = .;
        . = 0x00D53A; gUnk_0200D53A = .;
        . = 0x00D5BC; gUnk_0200D5BC = .;
        . = 0x00D5F4; gUnk_0200D5F4 = .;
        . = 0x00D69C; gUnk_0200D69C = .;
        . = 0x00D6A4; gUnk_0200D6A4 = .;
        . = 0x00D6AC; gUnk_0200D6AC = .;
        . = 0x00D6B4; gUnk_0200D6B4 = .;
        . = 0x00E6B4; gUnk_0200E6B4 = .;
        . = 0x00E6D4; gUnk_0200E6D4 = .;
        . = 0x00E7D4; gUnk_0200E7D4 = .; /* this is a u8 */
        . = 0x00E7D8; gUnk_0200E7D8 = .;
        . = 0x00E7DC; gUnk_0200E7DC = .; /* this is a text */
        . = 0x00E7E4; gUnk_0200E7E4 = .; /* this is multiple text */
        . = 0x00E864; gUnk_0200E864 = .; /* this is multiple text */
        . = 0x00E88C; gUnk_0200E88C = .; /* this is multiple (2?) text */
        . = 0x00E89C; gUnk_0200E89C = .; /* this is a text */
        . = 0x00E8A4; gUnk_0200E8A4 = .; /* this is a tilemap */
        . = 0x00F0A4; gUnk_0200F0A4 = .; /* this is units */
        . = 0x0104A4; gUnk_020104A4 = .; /* buf? */
        . = 0x016874; gUnk_02016874 = .; /* big jump here? */
    }
    __ewram_overlay_end = MAX(., __ewram_overlay_end);

    . = __ewram_overlay_beg;
    ewram_overlay_savemenu (NOLOAD) : ALIGN(4)
    {
        . = ALIGN(4); src/savemenu.o(ewram_overlay_savemenu);
        . = ALIGN(4); src/savemenu_2.o(ewram_overlay_savemenu);
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
        . = 0x000000; gAnims = .;
        . = 0x000010; gEkrDebugTimer = .;
        . = 0x000014; gEkrDebugFlag1 = .;
        . = 0x000018; gEkrDebugFlag2 = .;
        . = 0x00001C; gAnimC01Blocking = .;
        . = 0x000020; gEkrXPosReal = .;
        . = 0x000024; gEkrYPosReal = .;
        . = 0x000028; gEkrXPosBase = .;
        . = 0x00002C; gEkrYPosBase = .;
        . = 0x000030; gEkrBg0QuakeVec = .;
        . = 0x000034; gUnk_Banim_02000034 = .;
        . = 0x00003C; gUnk_Banim_0200003C = .;
        . = 0x000044; gUnk_Banim_02000044 = .;
        . = 0x00004C; gpEfxUnitPaletteBackup = .;
        . = 0x000054; gUnk_Banim_02000054 = .;
        . = 0x000058; gUnk_Banim_02000058 = .;
        . = 0x00005C; gpProcEkrBattle = .;
        . = 0x000060; gpProcEkrGauge = .;
        . = 0x000064; gpProcEkrDispUP = .;
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
        . = 0x0165C0; gEfxPal = .;
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
        . = 0x01771C; gEkrBattleEndFlag = .;
        . = 0x017720; gEkrHpBarCount = .;
        . = 0x017724; gEfxSpellAnimExists = .;
        . = 0x017728; gUnk_Banim_02017728 = .;
        . = 0x01772C; gUnk_Banim_0201772C = .;
        . = 0x017730; gEkrDeadEventExist = .;
        . = 0x017734; gEfxQuakeExist = .;
        . = 0x017738; gUnk_Banim_02017738 = .;
        . = 0x01773C; gEkrInitPosReal = .;
        . = 0x017740; gEfxFarAttackExist = .;
        . = 0x017744; gEfxBgSemaphore = .;
        . = 0x017748; gEfxHpBarResireFlag = .;
        . = 0x01774C; gUnk_Banim_0201774C = .;
        . = 0x017750; gUnk_Banim_02017750 = .;
        . = 0x017754; gUnk_Banim_02017754 = .;
        . = 0x017758; gEkrBg2QuakeVec = .;
        . = 0x01775C; gUnk_Banim_0201775C = .;
        . = 0x017760; gUnk_Banim_02017760 = .;
        . = 0x017764; gUnk_Banim_02017764 = .;
        . = 0x01776C; gUnk_Banim_0201776C = .;
        . = 0x017770; gUnk_Banim_02017770 = .;
        . = 0x017774; gUnk_Banim_02017774 = .;
        . = 0x017778; gEkrHitNow = .;
        . = 0x01777C; gSpellAnimBgfx = .;
        . = 0x01947C; gEkrBarfxBuf = .;
        . = 0x01977C; gEkrTsaBuffer = .;
        . = 0x01A77C; gBuf_Banim = .;
        . = 0x01C77C; gPal_Banim = .;
        . = 0x01C8BC; gTmA_Banim = .;
        . = 0x01D414; gTmB_Banim = .;
        . = 0x01D424; gUnk_Banim_0201D424 = .;
        . = 0x01D456; gUnk_Banim_0201D456 = .;
        . = 0x01DF6C; gUnk_Banim_0201DF6C = .;
        . = 0x01DFCC; gUnk_Banim_0201DFCC = .;
        . = 0x01E02C; gUnk_Banim_0201E02C = .;
        . = 0x01E0EC; gUnk_Banim_0201E0EC = .;
        . = 0x01E0F0; gUnk_Banim_0201E0F0 = .;
        . = 0x01E0F4; gProcEkrBaseAppearExist = .;
        . = 0x01E0F8; gUnk_Banim_0201E0F8 = .;
        . = 0x01E0FC; gUnk_Banim_0201E0FC = .;
        . = 0x01E124; gBanimDoneFlag = .;
        . = 0x01E12C; gEkrBgPosition = .;
        . = 0x01E138; gpProcEfxAnimeDrv = .;
        . = 0x01E13C; gpImgSheet = .;
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
        . = 0x01E7AC; EkrDragonProcs = .;
        . = 0x01E7B4; gEkrDragonDeamonProcs = .;
        . = 0x01E7BC; gpProcEkrIdunnBodyFlashing = .;
        . = 0x01E7C0; gEkrDragonIntroDone = .;
        . = 0x01E7C4; gEkrDragonFastenConf = .;
        . = 0x01E7C8; gEkrDragonState = .;
        . = 0x01E7CC; gUnk_Banim_0201E7CC = .;
        . = 0x01EFCC; gEkrBgPaletteBackup1 = .;
        . = 0x01EFEC; gEkrBgPaletteBackup2 = .;
        . = 0x01F00C; gEkrBgPaletteBackup3 = .;
        . = 0x01F04C; gUnk_Banim_0201F04C = .;
        . = 0x01F050; gUnk_Banim_0201F050 = .;
        . = 0x01F054; gpProcEkrClasschg = .;
        . = 0x01F058; gpProcEkrLevelup = .;
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
        . = 0x01F0DC; gEkrTriangleInvalid = .;
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

        . = 0x0203CCE4 - __ewram_overlay_end;
        . = ALIGN(4); src/banim_ekrbattle.o(ewram_data);

        . = 0x0203CCF2 - __ewram_overlay_end; gBanimBackgroundIndex = .;
        . = 0x0203CCF4 - __ewram_overlay_end; gEkrInitialHitSide = .;
        . = 0x0203CCF6 - __ewram_overlay_end; gEkrSnowWeather = .;
        . = 0x0203CCF8 - __ewram_overlay_end; gBanimValid = .;
        . = 0x0203CD00 - __ewram_overlay_end; gBanimIdx_bak = .;
        . = 0x0203CD04 - __ewram_overlay_end; gBanimUniquePal = .;
        . = 0x0203CD08 - __ewram_overlay_end; gBanimFactionPal = .;
        . = 0x0203CD0C - __ewram_overlay_end; gEkrSpellAnimIndex = .;
        . = 0x0203CD10 - __ewram_overlay_end; gBanimFloorfx = .;
        . = 0x0203CD14 - __ewram_overlay_end; gEkrDistanceType = .;
        . = 0x0203CD16 - __ewram_overlay_end; gEkrBmLocation = .;
        . = 0x0203CD46 - __ewram_overlay_end; gEfxHpLutOff = .;
        . = 0x0203CD4A - __ewram_overlay_end; gEfxHpLut = .;
        . = 0x0203CD76 - __ewram_overlay_end; gBanimIdx = .;
        . = 0x0203CD7C - __ewram_overlay_end; gpEkrBattleUnitLeft = .;
        . = 0x0203CD80 - __ewram_overlay_end; gpEkrBattleUnitRight = .;
        . = 0x0203CD84 - __ewram_overlay_end; gEkrPids = .;
        . = 0x0203CD88 - __ewram_overlay_end; gpEkrTriangleUnits = .;
        . = 0x0203CDA0 - __ewram_overlay_end; gEkrGaugeHp = .;
        . = 0x0203CDB8 - __ewram_overlay_end; gEkrPairExpPrevious = .;
        . = 0x0203CDBC - __ewram_overlay_end; gEkrPairExpGain = .;
        . = 0x0203CDCC - __ewram_overlay_end; gEkrPairEffectiveAgainst = .;
        . = 0x0203CDE0 - __ewram_overlay_end; gEkrDragonJid = .;

        . = 0x0203CDE4 - __ewram_overlay_end;
        . = ALIGN(4); src/manim.o(ewram_data);
        . = ALIGN(4); gUnk_0203D354 = .; . = . + 4;
        . = ALIGN(4); gUnk_0203D358 = .; . = . + 4;
        . = ALIGN(1); gUnk_0203D35C = .; . = . + 1;
        . = ALIGN(1); gUnk_0203D35D = .; . = . + 1;
        . = ALIGN(4); gUnk_0203D360 = .; . = . + 1;
        . = ALIGN(1); gUnk_0203D361 = .; . = . + 1;
        . = ALIGN(1); gUnk_0203D362 = .; . = . + 1;
        . = ALIGN(2); gUnk_0203D364 = .; . = . + 2;
        . = ALIGN(4); gUnk_0203D368 = .; . = . + 4;
        . = ALIGN(4); gUnk_0203D36C = .; . = . + 4;
        . = ALIGN(4); gUnkText_0203D370 = .;

        . = 0x0203D3A0 - __ewram_overlay_end;
        . = ALIGN(4); gUnkText_0203D3A0 = .;

        . = 0x0203D3D8 - __ewram_overlay_end;
        . = ALIGN(1); gUnk_0203D3D8 = .; . = . + 1;
        . = ALIGN(1); gUnk_0203D3D9 = .; . = . + 1;

        . = 0x0203D3DC - __ewram_overlay_end;
        . = ALIGN(4); src/statscreen.o(ewram_data);
        . = ALIGN(4); src/helpbox.o(ewram_data);
        . = ALIGN(4); src/helpbox_2.o(ewram_data);
        . = ALIGN(4); gUnk_0203D494 = .;

        . = 0x0203D524 - __ewram_overlay_end;
        . = ALIGN(4); src/save_core.o(ewram_data);
        . = ALIGN(4); src/save_stats.o(ewram_data);
        . = ALIGN(4); src/save_game.o(ewram_data);
        . = ALIGN(4); src/save_multiarena.o(ewram_data);
        . = ALIGN(4); src/save_xmap.o(ewram_data);

        . = 0x0203DCA7 - __ewram_overlay_end;
        . = ALIGN(1); gUnk_0203DCA7 = .;

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
        . = 0x0026A0; *(COMMON.gOamLoPutIt);
        . = 0x0026B0; *(COMMON.gDispIo);
        . = 0x002720; gIrqFuncs = .;
        . = 0x002758; MapFloodCoreRamFunc = .;
        . = 0x00275C; *(COMMON.gOamAffinePutId);
        . = 0x002760; PutOamHiRamFunc = .;
        . = 0x002764; *(COMMON.gOnHBlankA);
        . = 0x002770; *(COMMON.gOam);
        . = 0x002D70; DrawGlyphRamFunc = .;
        . = 0x002D74; *(COMMON.gOamHiPutIt);
        . = 0x002D78; *(COMMON.gOnHBlankB);
        . = 0x002D80; RamFuncArea = .;
        . = 0x003780; DecodeStringRamFunc = .;
        . = 0x003784; PutOamLoRamFunc = .;
        . = 0x003788; *(COMMON.gOamAffinePutIt);
        . = 0x003790; IntrMainRam = .;
        . = 0x003F90; MapFloodCoreStepRamFunc = .;
        . = 0x003FA0; gEventScriptQueueIt = .;
        . = 0x003FB0; gEventScriptQueue = .;
        . = 0x003FD0; gSpriteAllocIt = .;
        . = 0x004000; *(COMMON.gFaces);
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
        . = 0x004570; *(COMMON.AiDecideFunc);
        . = 0x004580; gUnk_03004580 = .;
        . = 0x004600; *(COMMON.gManimDebugStObj);
        . = 0x0046D0; *(COMMON.gUnk_030046D0);
        . = 0x004750; *(COMMON.gUnk_03004750);
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
        src/armfunc.o(.text);
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
        asm/code-sio.o(.text);
        src/ui.o(.text);
        src/menu.o(.text);
        src/mapselect.o(.text);
        src/banim_ekrbattle.o(.text);
        src/banim_ekrlvupfan.o(.text);
        src/banim_ekrgauge.o(.text);
        asm/banim_ekrgauge.o(.text);
        asm/banim_ekrdispup.o(.text);
        asm/banim_ekrmisc.o(.text);
        src/banim_efxhpbar.o(.text);
        asm/banim_efxdeath.o(.text);
        asm/banim_efxfarattack.o(.text);
        src/banim_efxquake.o(.text);
        asm/banim_efxquake.o(.text);
        asm/banim_efxflashing.o(.text);
        src/banim_efxflashing.o(.text);
        asm/banim_efxstatusunit.o(.text);
        asm/banim_efxflashobj.o(.text);
        asm/banim_ekrutils.o(.text);
        asm/banim_ekrbattlestarting.o(.text);
        asm/banim_ekrbattleending.o(.text);
        asm/banim_ekrbattleintrofx.o(.text);
        asm/banim_ekrcmd.o(.text);
        asm/banim_main.o(.text);
        asm/banim_ekrmain.o(.text);
        asm/banim_ekrmainmini.o(.text);
        asm/banim_ekrarena.o(.text);
        asm/banim_efxmagic.o(.text);
        asm/banim_efxhit.o(.text);
        asm/code-banim.o(.text);
        src/banim_dragon.o(.text);
        src/banim_dragonfx_manakete.o(.text);
        src/banim_dragonfx_fae.o(.text);
        src/banim_dragonfx_idunn.o(.text);
        asm/banim_dragonfx.o(.text);
        asm/banim_efxutils.o(.text);
        asm/banim_efxsound.o(.text);
        asm/banim_ekrclasschg.o(.text);
        asm/banim_ekrlvup.o(.text);
        asm/banim_ekrtriangle.o(.text);
        asm/banim_bg.o(.text);
        asm/banim_ekrpopup.o(.text);
        src/mu.o(.text);
        src/manim.o(.text);
        src/eventinfo.o(.text);
        src/eventfunctions.o(.text);
        src/statscreen.o(.text);
        src/helpbox.o(.text);
        src/helpbox_2.o(.text);
        src/mapui.o(.text);
        src/sioerror.o(.text);
        src/statusscreen.o(.text);
        src/unitlistscreen.o(.text);
        src/prepmenu.o(.text);
        asm/code_8073548.o(.text);
        src/save_core.o(.text);
        src/save_stats.o(.text);
        src/save_game.o(.text);
        src/save_multiarena.o(.text);
        src/save_xmap.o(.text);
        src/minimap.o(.text);
        src/savemenu.o(.text);
        src/savemenu_2.o(.text);

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

        asm/code_linker_stubs.o(.text);

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
        . = ALIGN(4); src/gamedata.o(.rodata);
        . = ALIGN(4); data/rodata_279E60.o(.rodata);
        . = ALIGN(4); src/mu.o(.rodata);
        . = ALIGN(4); src/manim.o(.rodata);
        . = ALIGN(4); data/rodata_307544.o(.rodata);
        . = ALIGN(4); src/statscreen.o(.rodata);
        . = ALIGN(4); src/helpbox.o(.rodata);
        . = ALIGN(4); src/helpbox_2.o(.rodata);
        . = ALIGN(4); src/statusscreen.o(.rodata);
        . = ALIGN(4); data/rodata_3198C0.o(.rodata);
        . = ALIGN(4); src/unitlistscreen.o(.rodata);
        . = ALIGN(4); src/prepmenu.o(.rodata);
        . = ALIGN(4); data/rodata_327254.o(.rodata);
        . = ALIGN(4); src/save_core.o(.rodata);
        . = ALIGN(4); src/save_multiarena.o(.rodata);
        . = ALIGN(4); data/rodata_3273E4.o(.rodata);
        . = ALIGN(4); src/minimap.o(.rodata);
        . = ALIGN(4); data/rodata_3278AC.o(.rodata);
        . = ALIGN(4); src/savemenu.o(.rodata);
        . = ALIGN(4); src/savemenu_2.o(.rodata);
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
        . = ALIGN(4); src/banim_ekrbattle.o(.data);
        . = ALIGN(4); src/banim_ekrlvupfan.o(.data);
        . = ALIGN(4); asm/banim_ekrgauge.o(.data);
        . = ALIGN(4); asm/banim_ekrdispup.o(.data);
        . = ALIGN(4); src/banim_efxhpbar.o(.data);
        . = ALIGN(4); asm/banim_efxdeath.o(.data);
        . = ALIGN(4); asm/banim_efxfarattack.o(.data);
        . = ALIGN(4); src/banim_efxquake.o(.data);
        . = ALIGN(4); asm/banim_efxquake.o(.data);
        . = ALIGN(4); asm/banim_efxflashing.o(.data);
        . = ALIGN(4); src/banim_efxflashing.o(.data);
        . = ALIGN(4); asm/banim_efxstatusunit.o(.data);
        . = ALIGN(4); asm/banim_efxflashobj.o(.data);
        . = ALIGN(4); asm/banim_ekrbattlestarting.o(.data);
        . = ALIGN(4); asm/banim_ekrbattleending.o(.data);
        . = ALIGN(4); asm/banim_ekrbattleintrofx.o(.data);
        . = ALIGN(4); asm/banim_ekrmain.o(.data);
        . = ALIGN(4); asm/banim_ekrmainmini.o(.data);
        . = ALIGN(4); asm/banim_ekrarena.o(.data);
        . = ALIGN(4); data/data-code-banim.o(.data);
        . = ALIGN(4); src/banim_dragon.o(.data);
        . = ALIGN(4); src/banim_dragonfx_manakete.o(.data);
        . = ALIGN(4); src/banim_dragonfx_fae.o(.data);
        . = ALIGN(4); src/banim_dragonfx_idunn.o(.data);
        . = ALIGN(4); data/data-banim-dragon.o(.data);
        . = ALIGN(4); asm/banim_efxutils.o(.data);
        . = ALIGN(4); asm/banim_efxsound.o(.data);
        . = ALIGN(4); asm/banim_ekrclasschg.o(.data);
        . = ALIGN(4); asm/banim_ekrlvup.o(.data);
        . = ALIGN(4); data/data-code-banim2.o(.data);
        . = ALIGN(4); src/gamedata.o(.data);
        . = ALIGN(4), data/data-game-info.o(.data);
        . = ALIGN(4); src/mu.o(.data);
        . = ALIGN(4); data/data-code-mu.o(.data);
        . = ALIGN(4); src/manim.o(.data);
        . = ALIGN(4); src/eventinfo.o(.data);
        . = ALIGN(4); data/data_66618C.o(.data);
        . = ALIGN(4); src/chapterevents.o(.data);
        . = ALIGN(4); data/data_67619C.o(.data);
        . = ALIGN(4); src/statscreen.o(.data);
        . = ALIGN(4); src/helpbox.o(.data);
        . = ALIGN(4); src/helpbox_2.o(.data);
        . = ALIGN(4); src/mapui.o(.data);
        . = ALIGN(4); src/statusscreen.o(.data);
        . = ALIGN(4); src/unitlistscreen.o(.data);
        . = ALIGN(4); src/prepmenu.o(.data);
        . = ALIGN(4); data/data_67829C.o(.data);
        . = ALIGN(4); src/chapterunits.o(.data);
        . = ALIGN(4); data/data_mapchangeinfo.o(.data);
        . = ALIGN(4); src/save_core.o(.data);
        . = ALIGN(4); src/save_xmap.o(.data);
        . = ALIGN(4); src/minimap.o(.data);
        . = ALIGN(4); src/savemenu.o(.data);
        . = ALIGN(4); src/savemenu_2.o(.data);
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
