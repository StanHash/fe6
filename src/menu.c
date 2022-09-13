#include "menu.h"

#include "hardware.h"
#include "sound.h"
#include "text.h"
#include "face.h"
#include "ui.h"

#include "constants/songs.h"

struct ProcScr CONST_DATA ProcScr_MenuMain[] =
{
    PROC_REPEAT(Menu_Main),
    PROC_CALL(EndGreenText),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_Menu[] =
{
    PROC_19,
    PROC_SLEEP(0),
    PROC_WHILE_EXISTS(ProcScr_CamMove),
    PROC_CALL(StartGreenText),
    PROC_CALL(Menu_Draw),
    PROC_CALL(Menu_Init),
    PROC_GOTO_SCR(ProcScr_MenuMain),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_MenuItem[] =
{
    PROC_BLOCK,
};

struct ProcScr CONST_DATA ProcScr_MenuHelpBox[] =
{
    PROC_CALL(Menu_HelpBoxInit),
    PROC_REPEAT(Menu_HelpBoxMain),
    PROC_END,
};

struct ProcScr CONST_DATA ProcScr_MenuFrozenHelpBox[] =
{
    PROC_REPEAT(Menu_FrozenHelpBoxMain),
    PROC_END,
};

struct MenuProc * StartAdjustedMenu(struct MenuInfo const * info, int x, int left, int right)
{
    struct MenuRect rect = info->rect;

    if (x < DISPLAY_WIDTH / 2) // TODO: constant
        rect.x = right;
    else
        rect.x = left;

    return StartLockingMenuExt(info, rect, NULL);
}

struct MenuProc * StartLockingMenu(struct MenuInfo const * info, ProcPtr parent)
{
    return StartLockingMenuExt(info, info->rect, parent);
}

struct MenuProc * StartMenuExt(struct MenuInfo const * info, struct MenuRect rect)
{
    return StartLockingMenuExt(info, rect, NULL);
}

struct MenuProc * StartMenu(struct MenuInfo const * info)
{
    return StartLockingMenuExt(info, info->rect, NULL);
}

struct MenuProc * StartLockingMenuExt(struct MenuInfo const * info, struct MenuRect rect, ProcPtr parent)
{
    struct MenuProc * proc;
    int i, menu_item_count;

    int x_ent = rect.x + 1;
    int y_ent = rect.y + 1;

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);

    PlaySe(SONG_68);

    if (parent != NULL)
    {
        proc = SpawnProcLocking(ProcScr_Menu, parent);
        proc->flags = 0;
    }
    else
    {
        LockGame();

        proc = SpawnProc(ProcScr_Menu, PROC_TREE_3);
        proc->flags = MENU_FLAG_GAMELOCK;
    }

    if (rect.h < 0)
        proc->flags |= MENU_FLAG_HIDDEN;

    for (i = 0, menu_item_count = 0; info->entries[i].available != NULL; i++)
    {
        int availability = info->entries[i].available(&info->entries[i], i);

        if (availability != MENU_ENTRY_HIDDEN)
        {
            struct MenuEntProc * ent_proc;

            ent_proc = SpawnProc(ProcScr_MenuItem, proc);
            proc->entries[menu_item_count++] = ent_proc;

            ent_proc->info = &info->entries[i];
            ent_proc->id = i;
            ent_proc->availability = availability;

            ent_proc->x = x_ent;
            ent_proc->y = y_ent;

            if (!(proc->flags & MENU_FLAG_HIDDEN))
                InitText(&ent_proc->text, rect.w - 2);

            y_ent += 2;
        }
    }

    proc->info = info;
    proc->rect = rect;
    proc->entry_count = menu_item_count;
    proc->active_entry = 0;
    proc->previous_entry = -1;

    if (rect.y + rect.h < y_ent)
        proc->rect.h = y_ent + 1 - rect.y;

    gKeySt->pressed = 0;

    return proc;
}

ProcPtr EndMenu(struct MenuProc * proc)
{
    struct MenuEntProc * active_ent_proc = proc->entries[proc->active_entry];

    proc->flags |= MENU_FLAG_ENDING;

    if (active_ent_proc->info->on_switch_out != NULL)
        active_ent_proc->info->on_switch_out(proc, active_ent_proc);

    if (proc->info->on_end != NULL)
        proc->info->on_end(proc);

    if (proc->flags & MENU_FLAG_GAMELOCK)
        UnlockGame();

    Proc_End(proc);

    SetBgOffset(0, 0, 0);
    SetBgOffset(1, 0, 0);

    return proc->proc_parent;
}

void EndMenus(void)
{
    Proc_ForEach(ProcScr_Menu, (ProcFunc) EndMenu);
}

inline bool HasMenuChangedItem(struct MenuProc * proc)
{
    return proc->active_entry != proc->previous_entry;
}

void Menu_Init(struct MenuProc * proc)
{
    if (proc->info->on_init != NULL)
        proc->info->on_init(proc);

    if (proc->entries[proc->active_entry]->info->on_switch_in != NULL)
        proc->entries[proc->active_entry]->info->on_switch_in(proc, proc->entries[proc->active_entry]);
}

void Menu_Draw(struct MenuProc * proc)
{
    int i;

    if (proc->flags & MENU_FLAG_HIDDEN)
        return;

    PutUiWindowFrame(proc->rect.x, proc->rect.y, proc->rect.w, proc->rect.h, proc->info->window_kind);

    for (i = 0; i < proc->entry_count; i++)
    {
        struct MenuEntProc * ent_proc = proc->entries[i];

        if (ent_proc->info->display != NULL)
        {
            ent_proc->info->display(proc, ent_proc);
            continue;
        }

        if (ent_proc->info->text_color)
            Text_SetColor(&ent_proc->text, ent_proc->info->text_color);

        if (ent_proc->availability == MENU_ENTRY_DISABLED)
            Text_SetColor(&ent_proc->text, TEXT_COLOR_SYSTEM_GRAY);

        Text_DrawString(&ent_proc->text, ent_proc->info->label);

        PutText(&ent_proc->text, gBg0Tm + TM_OFFSET(ent_proc->x, ent_proc->y));
    }

    PutMenuEntryHover(proc, proc->active_entry, TRUE);

    EnableBgSync(BG0_SYNC_BIT | BG1_SYNC_BIT);
}

void PutMenuEntryHover(struct MenuProc * proc, int entry_id, bool shown)
{
    int x, y, w;

    if (proc->flags & MENU_FLAG_FLAT)
        return;

    x = proc->rect.x + 1;
    y = proc->entries[entry_id]->y;
    w = proc->rect.w - 2;

    switch (shown)
    {

    case TRUE:
        PutUiEntryHover(x, y, w);
        break;

    case FALSE:
        RemoveUiEntryHover(x, y, w);
        break;

    }
}

void Menu_Main(struct MenuProc * proc)
{
    int x, y;
    u32 actions;

    if (proc->flags & MENU_FLAG_FROZEN)
    {
        GetMenuCursorPosition(proc, &x, &y);
        PutFrozenUiHand(x, y);

        return;
    }

    if (proc->flags & MENU_FLAG_DOOMED)
    {
        EndMenu(proc);
        return;
    }

    HandleMenuSwitching(proc);
    actions = HandleMenuActions(proc);

    if (actions & MENU_ACTION_END)
        EndMenu(proc);

    if (actions & MENU_ACTION_SE_6A)
        PlaySe(SONG_6A);

    if (actions & MENU_ACTION_SE_6B)
        PlaySe(SONG_6B);

    if (actions & MENU_ACTION_CLEAR)
        ClearUi();

    if (actions & MENU_ACTION_ENDFACE)
        EndFaceById(0);

    if (actions & MENU_ACTION_DOOM)
        proc->flags |= MENU_FLAG_DOOMED;

    if (!(actions & MENU_ACTION_NOCURSOR) && !(proc->flags & MENU_FLAG_NOCURSOR))
    {
        GetMenuCursorPosition(proc, &x, &y);
        ApplyMenuCursorScroll(proc, &x, &y);

        PutUiHand(x, y);
    }
}

void HandleMenuSwitching(struct MenuProc * proc)
{
    proc->previous_entry = proc->active_entry;

    // Handle Up keyin

    if (gKeySt->repeated & KEY_DPAD_UP)
    {
        if (proc->active_entry == 0)
        {
            if (gKeySt->repeated != gKeySt->pressed)
                return;

            proc->active_entry = proc->entry_count;
        }

        proc->active_entry--;
    }

    // Handle Down keyin

    if (gKeySt->repeated & KEY_DPAD_DOWN)
    {
        if (proc->active_entry == (proc->entry_count - 1))
        {
            if (gKeySt->repeated != gKeySt->pressed)
                return;

            proc->active_entry = -1;
        }

        proc->active_entry++;
    }

    // Update hover display

    if (proc->previous_entry != proc->active_entry)
    {
        PutMenuEntryHover(proc, proc->previous_entry, FALSE);
        PutMenuEntryHover(proc, proc->active_entry, TRUE);

        PlaySe(SONG_66);
    }

    // Invoke switch in/out funcs

    if (proc->active_entry != proc->previous_entry)
    {
        if (proc->entries[proc->previous_entry]->info->on_switch_out != NULL)
            proc->entries[proc->previous_entry]->info->on_switch_out(proc, proc->entries[proc->previous_entry]);

        if (proc->entries[proc->active_entry]->info->on_switch_in != NULL)
            proc->entries[proc->active_entry]->info->on_switch_in(proc, proc->entries[proc->active_entry]);
    }
}

u32 HandleMenuActions(struct MenuProc * proc)
{
    u32 result = 0;

    struct MenuEntProc * ent_proc = proc->entries[proc->active_entry];
    struct MenuEntInfo const * ent_info = ent_proc->info;

    if (ent_info->on_idle)
        ent_info->on_idle(proc, ent_proc);

    if (gKeySt->pressed & KEY_BUTTON_A)
    {
        if (ent_info->on_select != NULL)
            result = ent_info->on_select(proc, ent_proc);
    }
    else if (gKeySt->pressed & KEY_BUTTON_B)
    {
        if (proc->info->on_b_press != NULL)
            result = proc->info->on_b_press(proc, ent_proc);
    }
    else if (gKeySt->pressed & KEY_BUTTON_R)
    {
        if (proc->info->on_r_press != NULL)
            proc->info->on_r_press(proc);
    }

    return result;
}

void GetMenuCursorPosition(struct MenuProc * proc, int * x_out, int * y_out)
{
    *x_out = proc->entries[proc->active_entry]->x * 8;
    *y_out = proc->entries[proc->active_entry]->y * 8;

    if (proc->info->window_kind != 0)
        *x_out -= 4;
}

fu8 MenuEntryEnabled(struct MenuEntInfo const * info, int id)
{
    return MENU_ENTRY_ENABLED;
}

fu8 MenuEntryDisabled(struct MenuEntInfo const * info, int id)
{
    return MENU_ENTRY_DISABLED;
}

fu8 MenuActionClose(struct MenuProc * proc, struct MenuEntProc * ent)
{
    return MENU_ACTION_NOCURSOR | MENU_ACTION_CLEAR | MENU_ACTION_END | MENU_ACTION_SE_6B;
}

fu8 MenuHelpBoxRegular(struct MenuProc * proc, struct MenuEntProc * ent)
{
    StartHelpBox(ent->x * 8, ent->y * 8, ent->info->msg_help);

#if BUGFIX
    return 0;
#endif
}

void Menu_HelpBoxInit(struct MenuProc * proc)
{
    func_fe6_08070E70(NULL, -1);
    proc->info->on_help_box(proc, proc->entries[proc->active_entry]);
}

void Menu_HelpBoxMain(struct MenuProc * proc)
{
    int x, y;

    HandleMenuSwitching(proc);

    GetMenuCursorPosition(proc, &x, &y);
    ApplyMenuCursorScroll(proc, &x, &y);

    PutUiHand(x, y);

    if (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R))
    {
        CloseHelpBox();
        Proc_GotoScript(proc, ProcScr_MenuMain);

        return;
    }

    if (proc->active_entry != proc->previous_entry)
    {
        proc->info->on_help_box(proc, proc->entries[proc->active_entry]);
    }
}

fu8 MenuActionHelpBox(struct MenuProc * proc)
{
    Proc_GotoScript(proc, ProcScr_MenuHelpBox);

#if BUGFIX
    return 0;
#endif
}

void Menu_FrozenHelpBoxMain(struct MenuProc * proc)
{
    int x, y;

    GetMenuCursorPosition(proc, &x, &y);
    ApplyMenuCursorScroll(proc, &x, &y);

    PutFrozenUiHand(x, y);

    if (gKeySt->pressed & (KEY_BUTTON_B | KEY_BUTTON_R))
    {
        CloseHelpBox();
        Proc_GotoScript(proc, ProcScr_MenuMain);
    }
}

fu8 MenuFrozenHelpBox(struct MenuProc * proc, int msg)
{
    Proc_GotoScript(proc, ProcScr_MenuFrozenHelpBox);

    func_fe6_08070E70(NULL, -1);
    StartHelpBox(GetUiHandPrevX(), GetUiHandPrevY(), msg);

#if BUGFIX
    return 0;
#endif
}

void FreezeMenu(void)
{
    struct MenuProc * proc = Proc_Find(ProcScr_Menu);

    if (proc != NULL)
        proc->flags |= MENU_FLAG_FROZEN;
}

void ResumeMenu(void)
{
    struct MenuProc * proc = Proc_Find(ProcScr_Menu);

    if (proc != NULL)
        proc->flags &= ~MENU_FLAG_FROZEN;
}

u8 CONST_DATA gLongMenuCenteringOffsetLut[] = { 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 3, 3 };

struct MenuProc * StartCenteredMenu(struct MenuInfo const * info, int x, int left, int right)
{
    struct MenuProc * proc;
    int i;

    proc = StartAdjustedMenu(info, x, left, right);

    if (proc->entry_count <= 6)
        return proc;

    proc->rect.y -= gLongMenuCenteringOffsetLut[proc->entry_count];

    for (i = 0; i < proc->entry_count; i++)
        proc->entries[i]->y -= gLongMenuCenteringOffsetLut[proc->entry_count];

    return proc;
}

void ApplyMenuCursorScroll(struct MenuProc * proc, int * x_ref, int * y_ref)
{
    enum { THRESHOLD = 9 };

    if (proc->entry_count > THRESHOLD)
    {
        int offset = (proc->entry_count * 16 - THRESHOLD * 16) * proc->active_entry / THRESHOLD;

        SetBgOffset(0, 0, offset);
        SetBgOffset(1, 0, offset);

        *y_ref -= offset;
    }
}
