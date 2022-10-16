#include "menuinfo.h"

#include "bmfx.h"
#include "itemuse.h"
#include "prepphase.h"
#include "battlepreview.h"
#include "debugmenu.h"
#include "mapmenu.h"
#include "ui.h"

#include "constants/msg.h"

// we use this to denote when the function signature doesn't quite fit the pointer type in the relevant info struct
#define MISMATCHED_SIGNATURE(func) ((void const *) (func))

struct MenuEntInfo CONST_DATA MenuEntInfo_TutorialInterruptMenu[] =
{
    {
        .label = JTEXT("　チュートリアルを続ける"),
        .available = MenuEntryEnabled,
        .on_select = TutorialInterruptMenu_Continue_Select,
    },

    {
        .label = JTEXT("　チュートリアルをやめる"),
        .available = MenuEntryEnabled,
        .on_select = TutorialInterruptMenu_Quit_Select,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_Debug_085C64B4[] =
{
    {
        .label = JTEXT("ファイルをクリアずみに"),
        .available = MenuEntryEnabled,
    },

    {
        .label = JTEXT("しますか？"),
        .available = MenuEntryEnabled,
    },

    {
        .label = JTEXT("クリアずみファイルでは"),
        .available = MenuEntryEnabled,
    },

    {
        .label = JTEXT("以後プレイできません"),
        .available = MenuEntryEnabled,
    },

    {
        .label = JTEXT("　　　　　　　　　了解"),
        .text_color = TEXT_COLOR_SYSTEM_GREEN,
        .available = MenuEntryEnabled,
        .on_select = func_fe6_0801AA8C,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_DebugCpControl[] =
{
    {
        .label = "",
        .available = MenuEntryEnabled,
        .display = DebugCpControlMenu_Entry_Display,
        .on_idle = DebugCpControlMenu_Entry_Idle,
    },

    {
        .label = "",
        .available = MenuEntryEnabled,
        .display = DebugCpControlMenu_Entry_Display,
        .on_idle = DebugCpControlMenu_Entry_Idle,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_Debug_085C65F8[] =
{
    {
        .label = JTEXT("　リリースエントリ"),
        .available = MenuEntryEnabled,
        .on_select = func_fe6_0801AEBC,
    },

    {
        .label = JTEXT("　どこでも再開"),
        .available = func_fe6_0801ADB4,
        .on_select = func_fe6_0801ADCC,
    },

    {
        .label = JTEXT("　手再開"),
        .available = func_fe6_0801AD6C,
        .on_select = func_fe6_0801AD84,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_Debug_085C6688[] =
{
    {
        .label = JTEXT("　手中断"),
        .available = func_fe6_0801AD4C,
        .on_select = func_fe6_0801AD50,
    },

    {
        .label = JTEXT("　手再開"),
        .available = func_fe6_0801AD6C,
        .on_select = func_fe6_0801AD84,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_Debug_085C66F4[] =
{
    {
        .label = JTEXT("　マップ"),
        .available = MenuEntryEnabled,
        .on_select = func_fe6_0801A724,
        .on_idle = func_fe6_0801A698,
    },

    {
        .label = JTEXT("　デブ情報"),
        .available = MenuEntryEnabled,
        .display = func_fe6_0801A760,
        .on_select = func_fe6_0801A81C,
        .on_idle = func_fe6_0801A7D4,
    },

    {
        .label = JTEXT("　天気"),
        .available = MenuEntryEnabled,
        .display = func_fe6_0801A820,
        .on_select = func_fe6_0801A940,
        .on_idle = func_fe6_0801A89C,
    },

    {
        .label = JTEXT("　索敵"),
        .available = MenuEntryEnabled,
        .display = func_fe6_0801ADEC,
        .on_select = func_fe6_0801AEB8,
        .on_idle = func_fe6_0801AE60,
    },

    {
        .label = JTEXT("　周回数"),
        .available = MenuEntryEnabled,
        .display = func_fe6_0801A944,
        .on_select = func_fe6_0801AA70,
        .on_idle = func_fe6_0801A9A8,
    },

    {
        .label = JTEXT("　クリアずみ"),
        .available = MenuEntryEnabled,
        .on_select = func_fe6_0801AA74,
    },

    {
        .label = "",
        .available = MenuEntryEnabled,
    },

    {
        .label = JTEXT("　おやすみなさい"),
        .available = MenuEntryEnabled,
        .on_select = func_fe6_0801AEC8,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_RepairItem[] =
{
    {
        .label = "",
        .available = RepairItemMenu_Entry_Available,
        .display = RepairItemMenu_Entry_Display,
        .on_select = RepairItemMenu_Entry_Select,
        .on_switch_in = RepairItemMenu_Entry_SwitchIn,
        .on_switch_out = RepairItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = RepairItemMenu_Entry_Available,
        .display = RepairItemMenu_Entry_Display,
        .on_select = RepairItemMenu_Entry_Select,
        .on_switch_in = RepairItemMenu_Entry_SwitchIn,
        .on_switch_out = RepairItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = RepairItemMenu_Entry_Available,
        .display = RepairItemMenu_Entry_Display,
        .on_select = RepairItemMenu_Entry_Select,
        .on_switch_in = RepairItemMenu_Entry_SwitchIn,
        .on_switch_out = RepairItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = RepairItemMenu_Entry_Available,
        .display = RepairItemMenu_Entry_Display,
        .on_select = RepairItemMenu_Entry_Select,
        .on_switch_in = RepairItemMenu_Entry_SwitchIn,
        .on_switch_out = RepairItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = RepairItemMenu_Entry_Available,
        .display = RepairItemMenu_Entry_Display,
        .on_select = RepairItemMenu_Entry_Select,
        .on_switch_in = RepairItemMenu_Entry_SwitchIn,
        .on_switch_out = RepairItemMenu_Entry_SwitchOut,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_StealItem[] =
{
    {
        .label = "",
        .available = StealItemMenu_Entry_Available,
        .display = StealItemMenu_Entry_Display,
        .on_select = StealItemMenu_Entry_Select,
    },

    {
        .label = "",
        .available = StealItemMenu_Entry_Available,
        .display = StealItemMenu_Entry_Display,
        .on_select = StealItemMenu_Entry_Select,
    },

    {
        .label = "",
        .available = StealItemMenu_Entry_Available,
        .display = StealItemMenu_Entry_Display,
        .on_select = StealItemMenu_Entry_Select,
    },

    {
        .label = "",
        .available = StealItemMenu_Entry_Available,
        .display = StealItemMenu_Entry_Display,
        .on_select = StealItemMenu_Entry_Select,
    },

    {
        .label = "",
        .available = StealItemMenu_Entry_Available,
        .display = StealItemMenu_Entry_Display,
        .on_select = StealItemMenu_Entry_Select,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_DiscardItem[] =
{
    {
        .label = "",
        .available = MenuEntryEnabled,
        .display = DiscardItemMenu_InventoryEntry_Display,
        .on_select = DiscardItemMenu_InventoryEntry_Select,
        .on_switch_in = SingleItemMenu_Entry_SwitchIn,
        .on_switch_out = SingleItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = MenuEntryEnabled,
        .display = DiscardItemMenu_InventoryEntry_Display,
        .on_select = DiscardItemMenu_InventoryEntry_Select,
        .on_switch_in = SingleItemMenu_Entry_SwitchIn,
        .on_switch_out = SingleItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = MenuEntryEnabled,
        .display = DiscardItemMenu_InventoryEntry_Display,
        .on_select = DiscardItemMenu_InventoryEntry_Select,
        .on_switch_in = SingleItemMenu_Entry_SwitchIn,
        .on_switch_out = SingleItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = MenuEntryEnabled,
        .display = DiscardItemMenu_InventoryEntry_Display,
        .on_select = DiscardItemMenu_InventoryEntry_Select,
        .on_switch_in = SingleItemMenu_Entry_SwitchIn,
        .on_switch_out = SingleItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = MenuEntryEnabled,
        .display = DiscardItemMenu_InventoryEntry_Display,
        .on_select = DiscardItemMenu_InventoryEntry_Select,
        .on_switch_in = SingleItemMenu_Entry_SwitchIn,
        .on_switch_out = SingleItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = MenuEntryEnabled,
        .display = DiscardItemMenu_ExtraEntry_Display,
        .on_select = DiscardItemMenu_ExtraEntry_Select,
        .on_switch_in = SingleItemMenu_Entry_SwitchIn,
        .on_switch_out = SingleItemMenu_Entry_SwitchOut,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_UnitAttackMethodPrompt[] =
{
    {
        .label = JTEXT("　アーチ攻撃"),
        .msg_help = MSG_650,
        .available = MenuEntryEnabled,
        .on_select = UnitActionMenu_AttackBallista_Select,
    },

    {
        .label = JTEXT("　通常攻撃"),
        .msg_help = MSG_64F,
        .available = MenuEntryEnabled,
        .on_select = UnitActionMenu_AttackRegular_Select,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_UnitItemDiscardPrompt[] =
{
    {
        .label = JTEXT("はい"),
        .available = MenuEntryEnabled,
        .on_select = UnitItemDiscardPromptMenu_Yes_Select,
    },

    {
        .label = JTEXT("いいえ"),
        .available = MenuEntryEnabled,
        .on_select = MISMATCHED_SIGNATURE(MenuActionReturnToUnitItemMenu),
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_UnitItemAction[] =
{
    {
        .label = TEXT("使う", "Use"),
        .msg_help = MSG_652,
        .available = UnitItemActionMenu_Use_Available,
        .on_select = UnitItemActionMenu_Use_Select,
    },

    {
        .label = TEXT("装備", "Equip"),
        .msg_help = MSG_651,
        .text_color = TEXT_COLOR_SYSTEM_GREEN,
        .available = UnitItemActionMenu_Equip_Available,
        .on_select = UnitItemActionMenu_Equip_Select,
    },

    {
        .label = TEXT("交換", "Trade"),
        .msg_help = MSG_64D,
        .text_color = TEXT_COLOR_SYSTEM_GREEN,
        .available = AnyMenu_Trade_Available,
        .on_select = UnitItemActionMenu_Trade_Select,
    },

    {
        .label = TEXT("捨てる", "Discard"),
        .msg_help = MSG_653,
        .text_color = TEXT_COLOR_SYSTEM_GREEN,
        .available = UnitItemActionMenu_Discard_Available,
        .on_select = UnitItemActionMenu_Discard_Select,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_UnitStaffItem[] =
{
    {
        .label = "",
        .available = UnitStaffItemMenu_Entry_Available,
        .display = UnitStaffItemMenu_Entry_Display,
        .on_select = UnitStaffItemMenu_Entry_Select,
        .on_switch_in = UnitStaffItemMenu_Entry_SwitchIn,
        .on_switch_out = UnitStaffItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitStaffItemMenu_Entry_Available,
        .display = UnitStaffItemMenu_Entry_Display,
        .on_select = UnitStaffItemMenu_Entry_Select,
        .on_switch_in = UnitStaffItemMenu_Entry_SwitchIn,
        .on_switch_out = UnitStaffItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitStaffItemMenu_Entry_Available,
        .display = UnitStaffItemMenu_Entry_Display,
        .on_select = UnitStaffItemMenu_Entry_Select,
        .on_switch_in = UnitStaffItemMenu_Entry_SwitchIn,
        .on_switch_out = UnitStaffItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitStaffItemMenu_Entry_Available,
        .display = UnitStaffItemMenu_Entry_Display,
        .on_select = UnitStaffItemMenu_Entry_Select,
        .on_switch_in = UnitStaffItemMenu_Entry_SwitchIn,
        .on_switch_out = UnitStaffItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitStaffItemMenu_Entry_Available,
        .display = UnitStaffItemMenu_Entry_Display,
        .on_select = UnitStaffItemMenu_Entry_Select,
        .on_switch_in = UnitStaffItemMenu_Entry_SwitchIn,
        .on_switch_out = UnitStaffItemMenu_Entry_SwitchOut,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_UnitItem[] =
{
    {
        .label = "",
        .available = UnitItemMenu_Entry_Available,
        .display = UnitItemMenu_Entry_Display,
        .on_select = UnitItemMenu_Entry_Select,
        .on_switch_in = SingleItemMenu_Entry_SwitchIn,
        .on_switch_out = SingleItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitItemMenu_Entry_Available,
        .display = UnitItemMenu_Entry_Display,
        .on_select = UnitItemMenu_Entry_Select,
        .on_switch_in = SingleItemMenu_Entry_SwitchIn,
        .on_switch_out = SingleItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitItemMenu_Entry_Available,
        .display = UnitItemMenu_Entry_Display,
        .on_select = UnitItemMenu_Entry_Select,
        .on_switch_in = SingleItemMenu_Entry_SwitchIn,
        .on_switch_out = SingleItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitItemMenu_Entry_Available,
        .display = UnitItemMenu_Entry_Display,
        .on_select = UnitItemMenu_Entry_Select,
        .on_switch_in = SingleItemMenu_Entry_SwitchIn,
        .on_switch_out = SingleItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitItemMenu_Entry_Available,
        .display = UnitItemMenu_Entry_Display,
        .on_select = UnitItemMenu_Entry_Select,
        .on_switch_in = SingleItemMenu_Entry_SwitchIn,
        .on_switch_out = SingleItemMenu_Entry_SwitchOut,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_UnitAttackBallista[] =
{
    {
        .label = "",
        .available = UnitAttackBallista_Entry_Available,
        .display = UnitAttackBallista_Entry_Display,
        .on_select = UnitAttackBallista_Entry_Select,
        .on_switch_in = UnitAttackBallista_Entry_SwitchIn,
        .on_switch_out = UnitAttackItemMenu_Entry_SwitchOut,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_UnitAttackItem[] =
{
    {
        .label = "",
        .available = UnitAttackItemMenu_Entry_Available,
        .display = UnitAttackItemMenu_Entry_Display,
        .on_select = UnitAttackItemMenu_Entry_Select,
        .on_switch_in = UnitAttackItemMenu_Entry_SwitchIn,
        .on_switch_out = UnitAttackItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitAttackItemMenu_Entry_Available,
        .display = UnitAttackItemMenu_Entry_Display,
        .on_select = UnitAttackItemMenu_Entry_Select,
        .on_switch_in = UnitAttackItemMenu_Entry_SwitchIn,
        .on_switch_out = UnitAttackItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitAttackItemMenu_Entry_Available,
        .display = UnitAttackItemMenu_Entry_Display,
        .on_select = UnitAttackItemMenu_Entry_Select,
        .on_switch_in = UnitAttackItemMenu_Entry_SwitchIn,
        .on_switch_out = UnitAttackItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitAttackItemMenu_Entry_Available,
        .display = UnitAttackItemMenu_Entry_Display,
        .on_select = UnitAttackItemMenu_Entry_Select,
        .on_switch_in = UnitAttackItemMenu_Entry_SwitchIn,
        .on_switch_out = UnitAttackItemMenu_Entry_SwitchOut,
    },

    {
        .label = "",
        .available = UnitAttackItemMenu_Entry_Available,
        .display = UnitAttackItemMenu_Entry_Display,
        .on_select = UnitAttackItemMenu_Entry_Select,
        .on_switch_in = UnitAttackItemMenu_Entry_SwitchIn,
        .on_switch_out = UnitAttackItemMenu_Entry_SwitchOut,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_UnitAction[] =
{
    {
        .label = TEXT("　制圧", " Seize"),
        .msg_help = MSG_644,
        .available = UnitActionMenu_Seize_Available,
        .on_select = UnitActionMenu_Seize_Select,
    },

    {
        .label = TEXT("　攻撃", " Attack"),
        .msg_help = MSG_638,
        .available = UnitActionMenu_Attack_Available,
        .on_select = UnitActionMenu_Attack_Select,
        .on_switch_in = UnitActionMenu_Attack_SwitchIn,
        .on_switch_out = UnitActionMenu_Attack_SwitchOut,
    },

    {
        .label = TEXT("　杖", " Staff"),
        .msg_help = MSG_639,
        .available = UnitActionMenu_Staff_Available,
        .on_select = UnitActionMenu_Staff_Select,
        .on_switch_in = UnitActionMenu_Staff_SwitchIn,
        .on_switch_out = UnitActionMenu_Staff_SwitchOut,
    },

    {
        .label = TEXT("　奏でる", " Play"),
        .msg_help = MSG_63B,
        .available = UnitActionMenu_Play_Available,
        .on_select = UnitActionMenu_Refresh_Select,
    },

    {
        .label = TEXT("　踊る", " Dance"),
        .msg_help = MSG_63A,
        .available = UnitActionMenu_Dance_Available,
        .on_select = UnitActionMenu_Refresh_Select,
    },

    {
        .label = TEXT("　盗む", " Steal"),
        .msg_help = MSG_63C,
        .available = UnitActionMenu_Steal_Available,
        .on_select = UnitActionMenu_Steal_Select,
    },

    {
        .label = TEXT("　話す", " Talk"),
        .msg_help = MSG_642,
        .available = UnitActionMenu_Talk_Available,
        .on_select = UnitActionMenu_Talk_Select,
    },

    {
        .label = TEXT("　支援", " Support"),
        .msg_help = MSG_6F0,
        .available = UnitActionMenu_Support_Available,
        .on_select = UnitActionMenu_Support_Select,
    },

    {
        .label = TEXT("　訪問", " Visit"),
        .msg_help = MSG_643,
        .available = UnitActionMenu_Visit_Available,
        .on_select = UnitActionMenu_Visit_Select,
    },

    {
        .label = TEXT("　宝箱", " Chest"),
        .msg_help = MSG_647,
        .available = UnitActionMenu_Chest_Available,
        .on_select = UnitActionMenu_Chest_Select,
    },

    {
        .label = TEXT("　扉", " Door"),
        .msg_help = MSG_645,
        .available = UnitActionMenu_Door_Available,
        .on_select = UnitActionMenu_Door_Select,
    },

    {
        .label = TEXT("　武器屋", " Armory"),
        .msg_help = MSG_648,
        .available = UnitActionMenu_Armory_Available,
        .on_select = UnitActionMenu_Armory_Select,
    },

    {
        .label = TEXT("　道具屋", " Vendor"),
        .msg_help = MSG_649,
        .available = UnitActionMenu_Vendor_Available,
        .on_select = UnitActionMenu_Vendor_Select,
    },

    {
        .label = TEXT("　秘密店", " Secret"),
        .msg_help = MSG_64A,
        .available = UnitActionMenu_Secret_Available,
        .on_select = UnitActionMenu_Secret_Select,
    },

    {
        .label = TEXT("　闘技場", " Arena"),
        .msg_help = MSG_64B,
        .available = UnitActionMenu_Arena_Available,
        .on_select = UnitActionMenu_Arena_Select,
    },

    {
        .label = TEXT("　救出", " Rescue"),
        .msg_help = MSG_63D,
        .available = UnitActionMenu_Rescue_Available,
        .on_select = UnitActionMenu_Rescue_Select,
    },

    {
        .label = TEXT("　降ろす", " Drop"),
        .msg_help = MSG_63E,
        .available = UnitActionMenu_Drop_Available,
        .on_select = UnitActionMenu_Drop_Select,
    },

    {
        .label = TEXT("　引受け", " Take"),
        .msg_help = MSG_640,
        .text_color = TEXT_COLOR_SYSTEM_GREEN,
        .available = UnitActionMenu_Take_Available,
        .on_select = UnitActionMenu_Take_Select,
    },

    {
        .label = TEXT("　引渡し", " Give"),
        .msg_help = MSG_63F,
        .text_color = TEXT_COLOR_SYSTEM_GREEN,
        .available = UnitActionMenu_Give_Available,
        .on_select = UnitActionMenu_Give_Select,
    },

    {
        .label = TEXT("　持ち物", " Item"),
        .msg_help = MSG_64C,
        .available = UnitActionMenu_Item_Available,
        .on_select = UnitActionMenu_Item_Select,
    },

    {
        .label = TEXT("　交換", " Trade"),
        .msg_help = MSG_64D,
        .text_color = TEXT_COLOR_SYSTEM_GREEN,
        .available = AnyMenu_Trade_Available,
        .on_select = UnitActionMenu_Trade_Select,
    },

    {
        .label = TEXT("　輸送隊", " Supply"),
        .msg_help = MSG_64E,
        .text_color = TEXT_COLOR_SYSTEM_GREEN,
        .available = UnitActionMenu_Supply_Available,
        .on_select = UnitActionMenu_Supply_Select,
    },

    {
        .label = TEXT("　待機", " Wait"),
        .msg_help = MSG_637,
        .available = MenuEntryEnabled,
        .on_select = UnitActionMenu_Wait_Select,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_PrepMap[] =
{
    {
        .label = JTEXT("　進撃準備へ"),
        .available = MenuEntryEnabled,
        .on_select = PrepMapMenuConfirm,
    },

    { 0 }, // end
};

struct MenuEntInfo CONST_DATA MenuEntInfo_Map[] =
{
    {
        .label = TEXT("　部隊", " Unit"),
        .msg_help = MSG_654,
        .available = MenuEntryEnabled,
        .on_select = MapMenu_Unit_Select,
    },

    {
        .label = TEXT("　状況", " Status"),
        .msg_help = MSG_655,
        .available = MenuEntryEnabled,
        .on_select = MapMenu_Status_Select,
    },

    {
        .label = TEXT("　設定", " Options"),
        .msg_help = MSG_656,
        .available = MenuEntryEnabled,
        .on_select = MapMenu_Options_Select,
    },

    {
        .label = TEXT("　中断", " Suspend"),
        .msg_help = MSG_657,
        .available = MapMenu_Suspend_Available,
        .on_select = MapMenu_Suspend_Select,
    },

    {
        .label = TEXT("　終了", " End"),
        .msg_help = MSG_658,
        .available = MenuEntryEnabled,
        .on_select = MapMenu_End_Select,
    },

    { 0 }, // end
};

struct MenuInfo CONST_DATA MenuInfo_TutorialInterruptMenu =
{
    .rect = { 8, 9, 14, 0 },
    .entries = MenuEntInfo_TutorialInterruptMenu,
    .on_b_press = MenuActionClose,
};

struct MenuInfo CONST_DATA MenuInfo_Debug_085C73E4 =
{
    .rect = { 1, 6, 13, 0 },
    .entries = MenuEntInfo_Debug_085C64B4,
    .on_b_press = func_fe6_0801A748,
};

struct MenuInfo CONST_DATA MenuInfo_DebugCpControl =
{
    .rect = { 1, 1, 10, 0 },
    .entries = MenuEntInfo_DebugCpControl,
    .on_b_press = func_fe6_0801A748,
};

struct MenuInfo CONST_DATA MenuInfo_Debug_085C742C =
{
    .rect = { 9, 4, 12, 0 },
    .entries = MenuEntInfo_Debug_085C65F8,
    .on_init = func_fe6_0801AB64,
    .on_end = func_fe6_0801ABE8,
};

struct MenuInfo CONST_DATA MenuInfo_Debug_085C7450 =
{
    .rect = { 1, 1, 8, 0 },
    .entries = MenuEntInfo_Debug_085C6688,
    .on_b_press = func_fe6_0801A748,
};

struct MenuInfo CONST_DATA MenuInfo_Debug_085C7474 =
{
    .rect = { 1, 1, 14, 0 },
    .entries = MenuEntInfo_Debug_085C66F4,
    .on_init = func_fe6_0801AABC,
    .on_b_press = func_fe6_0801A748,
};

struct MenuInfo CONST_DATA MenuInfo_RepairItem =
{
    .rect = { 0, 1, 16, 0 },
    .entries = MenuEntInfo_RepairItem,
    .on_b_press = MenuActionReturnToUnitActionMenu,
    .on_r_press = MenuActionHelpBox,
    .on_help_box = MenuHelpBoxTargetUnitInventory,
};

struct MenuInfo CONST_DATA MenuInfo_StealItem =
{
    .rect = { 14, 4, 14, 0 },
    .entries = MenuEntInfo_StealItem,
    .on_b_press = MenuActionReturnToUnitActionMenu,
    .on_r_press = MenuActionHelpBox,
    .on_help_box = MenuHelpBoxTargetUnitInventory,
};

struct MenuInfo CONST_DATA MenuInfo_DiscardItem =
{
    .rect = { 1, 1, 14, 0 },
    .entries = MenuEntInfo_DiscardItem,
    .on_r_press = MenuActionHelpBox,
    .on_help_box = MenuHelpBoxActiveUnitInventory,
};

struct MenuInfo CONST_DATA MenuInfo_UnitAttackMethodPrompt =
{
    .rect = { 20, 3, 9, 0 },
    .entries = MenuEntInfo_UnitAttackMethodPrompt,
    .on_b_press = MenuActionReturnToUnitActionMenu,
    .on_r_press = MenuActionHelpBox,
    .on_help_box = MenuHelpBoxRegular,
};

struct MenuInfo CONST_DATA MenuInfo_UnitItemDiscardPrompt =
{
    .rect = { 0, 0, 5, 0 },
    .window_kind = UI_WINDOW_FILL,
    .entries = MenuEntInfo_UnitItemDiscardPrompt,
    .on_b_press = MISMATCHED_SIGNATURE(MenuActionReturnToUnitItemMenu),
};

struct MenuInfo CONST_DATA MenuInfo_UnitItemAction =
{
    .rect = { 0, 0, 5, 0 },
    .window_kind = UI_WINDOW_FILL,
    .entries = MenuEntInfo_UnitItemAction,
    .on_end = MISMATCHED_SIGNATURE(UnitItemActionMenu_End),
    .on_b_press = MISMATCHED_SIGNATURE(MenuActionReturnToUnitItemMenu),
    .on_r_press = MenuActionHelpBox,
    .on_help_box = MenuHelpBoxRegular,
};

struct MenuInfo CONST_DATA MenuInfo_UnitStaffItem =
{
    .rect = { 1, 1, 14, 0 },
    .entries = MenuEntInfo_UnitStaffItem,
    .on_b_press = MenuActionReturnToUnitActionMenu,
    .on_r_press = MenuActionHelpBox,
    .on_help_box = MenuHelpBoxActiveUnitInventory,
};

struct MenuInfo CONST_DATA MenuInfo_UnitItem =
{
    .rect = { 1, 1, 14, 0 },
    .entries = MenuEntInfo_UnitItem,
    .on_b_press = MenuActionReturnToUnitActionMenu,
    .on_r_press = MenuActionHelpBox,
    .on_help_box = MenuHelpBoxActiveUnitInventory,
};

struct MenuInfo CONST_DATA MenuInfo_UnitAttackBallista =
{
    .rect = { 1, 1, 14, 0 },
    .entries = MenuEntInfo_UnitAttackBallista,
    .on_b_press = MenuActionReturnToUnitActionMenu,
    .on_r_press = MenuActionHelpBox,
    .on_help_box = MenuHelpBoxActiveUnitBallista,
};

struct MenuInfo CONST_DATA MenuInfo_UnitAttackItem =
{
    .rect = { 1, 1, 14, 0 },
    .entries = MenuEntInfo_UnitAttackItem,
    .on_b_press = MenuActionReturnToUnitActionMenu,
    .on_r_press = MenuActionHelpBox,
    .on_help_box = MenuHelpBoxActiveUnitInventory,
};

struct MenuInfo CONST_DATA MenuInfo_UnitAction =
{
    .rect = { 1, 3, 7, 0 },
    .entries = MenuEntInfo_UnitAction,
    .on_b_press = MenuActionClose,
    .on_r_press = MenuActionHelpBox,
    .on_help_box = MenuHelpBoxRegular,
};

struct MenuInfo CONST_DATA MenuInfo_PrepMap =
{
    .rect = { 1, 2, 9, 0 },
    .entries = MenuEntInfo_PrepMap,
    .on_b_press = MenuActionClose,
};

struct MenuInfo CONST_DATA MenuInfo_Map =
{
    .rect = { 1, 2, 6, 0 },
    .entries = MenuEntInfo_Map,
    .on_b_press = MenuActionClose,
    .on_r_press = MenuActionHelpBox,
    .on_help_box = MenuHelpBoxRegular,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_AttackStaff =
{
    .on_init = MISMATCHED_SIGNATURE(AttackStaffMapSelect_Init),
    .on_end = MISMATCHED_SIGNATURE(ClearUi),
    .on_switch_in = AttackStaffMapSelect_SwitchIn,
    .on_a_press = StaffMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenu,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Barrier =
{
    .on_init = MISMATCHED_SIGNATURE(BarrierMapSelect_Init),
    .on_end = MISMATCHED_SIGNATURE(ClearUi),
    .on_switch_in = BarrierMapSelect_SwitchIn,
    .on_a_press = StaffMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Restore =
{
    .on_init = MISMATCHED_SIGNATURE(RestoreMapSelect_Init),
    .on_end = MISMATCHED_SIGNATURE(ClearUi),
    .on_switch_in = RestoreMapSelect_SwitchIn,
    .on_a_press = StaffMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Heal =
{
    .on_init = HealMapSelect_Init,
    .on_end = MISMATCHED_SIGNATURE(ClearUi),
    .on_switch_in = HealMapSelect_SwitchIn,
    .on_a_press = StaffMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenu,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Refresh =
{
    .on_init = RefreshMapSelect_Init,
    .on_end = MISMATCHED_SIGNATURE(ClearUi),
    .on_switch_in = RefreshMapSelect_SwitchIn,
    .on_a_press = RefreshMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Unlock =
{
    .on_end = SubtitleMapSelect_End,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_WarpUnit =
{
    .on_init = WarpUnitMapSelect_Init,
    .on_end = SubtitleMapSelect_End,
    .on_switch_in = WarpUnitMapSelect_SwitchIn,
    .on_b_press = MapSelectActionReturnToUnitActionMenu,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Steal =
{
    .on_init = StealMapSelect_Init,
    .on_end = MISMATCHED_SIGNATURE(ClearUi),
    .on_switch_in = StealMapSelect_SwitchIn,
    .on_a_press = StealMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Support =
{
    .on_init = TalkMapSelect_Init,
    .on_end = MISMATCHED_SIGNATURE(ClearUi),
    .on_switch_in = TalkMapSelect_SwitchIn,
    .on_a_press = SupportMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Talk =
{
    .on_init = TalkMapSelect_Init,
    .on_end = MISMATCHED_SIGNATURE(ClearUi),
    .on_switch_in = TalkMapSelect_SwitchIn,
    .on_a_press = TalkMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Repair =
{
    .on_init = RepairMapSelect_Init,
    .on_switch_in = RepairMapSelect_SwitchIn,
    .on_a_press = RepairMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Trade =
{
    .on_init = TradeMapSelect_Init,
    .on_end = MISMATCHED_SIGNATURE(ClearUi),
    .on_switch_in = TradeMapSelect_SwitchIn,
    .on_a_press = TradeMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Attack =
{
    .on_init = StartBattlePreview, // TODO: is this MISMATCHED_SIGNATURE?
    .on_end = MISMATCHED_SIGNATURE(AttackMapSelect_End),
    .on_switch_in = AttackMapSelect_SwitchIn,
    .on_a_press = AttackMapSelect_Select,
    .on_b_press = AttackMapSelect_Cancel,
    .on_r_press = StartBattlePreviewHelpBox, // TODO: is this MISMATCHED_SIGNATURE?
};

struct MapSelectInfo CONST_DATA MapSelectInfo_GiveRescue =
{
    .on_init = GiveRescueMapSelect_Init,
    .on_switch_in = GiveRescueMapSelect_SwitchIn,
    .on_a_press = GiveRescueMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_TakeRescue =
{
    .on_init = TakeRescueMapSelect_Init,
    .on_switch_in = TakeRescueMapSelect_SwitchIn,
    .on_a_press = TakeRescueMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_DropRescue =
{
    .on_init = DropRescueMapSelect_Init,
    .on_end = MISMATCHED_SIGNATURE(ClearUi),
    .on_a_press = DropRescueMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
};

struct MapSelectInfo CONST_DATA MapSelectInfo_Rescue =
{
    .on_init = RescueMapSelect_Init,
    .on_switch_in = RescueMapSelect_SwitchIn,
    .on_a_press = RescueMapSelect_Select,
    .on_b_press = MapSelectActionReturnToUnitActionMenuWithCamera,
    .on_r_press = RescueMapSelect_Help,
};
