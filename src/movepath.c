
#include "movepath.h"

#include "hardware.h"
#include "sprite.h"
#include "util.h"
#include "unit.h"
#include "map.h"
#include "mapwork.h"
#include "action.h"

#include "constants/video-global.h"

enum { MOVEPATH_MAX = 20 };

enum
{
    MOVEPATH_DIR_NONE,
    MOVEPATH_DIR_RIGHT,
    MOVEPATH_DIR_DOWN,
    MOVEPATH_DIR_LEFT,
    MOVEPATH_DIR_UP,
};

struct MovePath
{
#if !BUGFIX
    // This is just unused/padding, but a proc header happen to fit here perfectly
    /* 00 */ PROC_HEADER;
#endif

    /* 29 */ s8 xLast;
    /* 2A */ s8 yLast;
    /* 2B */ u8 initMove;
    /* 2C */ s8 path;
    /* 2D */ s8 x[MOVEPATH_MAX];
    /* 41 */ s8 y[MOVEPATH_MAX];
    /* 55 */ s8 move[MOVEPATH_MAX];
};

static void SetMovePathLastCursorPosition(u16 x, u16 y);
static void CutMovePath(s8 path);
static void AddMovePathSquare(s8 x, s8 y);
static int FindMovePathSquare(s8 x, s8 y);
static void MovePathFloodFromTail(void);
static void RebuildMovePath(void);
static Bool MovePathIsValid(void);
static void UpdateMovePath(void);
static u8 GetMovePathDirFrom(u8 path);
static u8 GetMovePathDirTo(u8 path);
static Bool ShouldDrawMovePathBitAt(short x, short y, u8 xEdge, u8 yEdge);
static void DrawMovePath(void);

u16 CONST_DATA gUnk_085C7E0C[5][5] =
{
    // TODO: make those into OAM2_... expressions
    { 0x3AF0, 0x3B04, 0x3B06, 0x3B00, 0x3B02 },
    { 0x3AF0, 0x3AF0, 0x3AF8, 0x3B0C, 0x3AFC },
    { 0x3AF2, 0x3AF8, 0x3AF2, 0x3AFA, 0x3B08 },
    { 0x3AF4, 0x3B0E, 0x3AFA, 0x3AF4, 0x3AFE },
    { 0x3AF6, 0x3AFC, 0x3B0A, 0x3AFE, 0x3AF6 },
};

static struct MovePath EWRAM_DATA sMovePathObj = {};
struct MovePath* CONST_DATA gMovePath = &sMovePathObj;

static void SetMovePathLastCursorPosition(u16 x, u16 y)
{
    gMovePath->xLast = x;
    gMovePath->yLast = y;
}

static void CutMovePath(s8 path)
{
    s8 i;

    if (gMovePath->path < path)
        return;

    gMovePath->path = path-1;

    gMovePath->move[gMovePath->path] = gMovePath->initMove;

    for (i = 1; i <= gMovePath->path; ++i)
    {
        gMovePath->move[i] = gMovePath->move[i-1]
            - GetWorkingMovTable()[gMapTerrain[gMovePath->y[i]][gMovePath->x[i]]];
    }
}

static void AddMovePathSquare(s8 x, s8 y)
{
    gMovePath->path++;

    gMovePath->x[gMovePath->path] = x;
    gMovePath->y[gMovePath->path] = y;

    gMovePath->move[gMovePath->path] = gMovePath->move[gMovePath->path-1]
        - GetWorkingMovTable()[gMapTerrain[y][x]];
}

static int FindMovePathSquare(s8 x, s8 y)
{
    s8 i;

    for (i = 0; i <= gMovePath->path; ++i)
    {
        if (gMovePath->x[i] == x && gMovePath->y[i] == y)
            return i;
    }

    return -1;
}

void GenMovePathFromMoveScript(void)
{
    s8 i = 0;

    for (;;)
    {
        switch (gWorkingMoveScr[i++])
        {

        case MOVE_CMD_FACE_LEFT:
        case MOVE_CMD_FACE_RIGHT:
        case MOVE_CMD_FACE_DOWN:
        case MOVE_CMD_FACE_UP:
        case MOVE_CMD_WAIT:
            continue;

        case MOVE_CMD_END:
        case MOVE_CMD_HALT:
            return;

        case MOVE_CMD_MOVE_LEFT:
            AddMovePathSquare(gMovePath->x[gMovePath->path] - 1, gMovePath->y[gMovePath->path]);
            break;

        case MOVE_CMD_MOVE_RIGHT:
            AddMovePathSquare(gMovePath->x[gMovePath->path] + 1, gMovePath->y[gMovePath->path]);
            break;

        case MOVE_CMD_MOVE_UP:
            AddMovePathSquare(gMovePath->x[gMovePath->path], gMovePath->y[gMovePath->path] - 1);
            break;

        case MOVE_CMD_MOVE_DOWN:
            AddMovePathSquare(gMovePath->x[gMovePath->path], gMovePath->y[gMovePath->path] + 1);
            break;

        }
    }
}

void GenMoveScriptFromMovePath(void)
{
    s8 i;

    for (i = 1; i <= gMovePath->path; ++i)
    {
        if (gMovePath->x[i] < gMovePath->x[i-1])
            gWorkingMoveScr[i-1] = MOVE_CMD_MOVE_LEFT;
        else if (gMovePath->x[i] > gMovePath->x[i-1])
            gWorkingMoveScr[i-1] = MOVE_CMD_MOVE_RIGHT;
        else if (gMovePath->y[i] < gMovePath->y[i-1])
            gWorkingMoveScr[i-1] = MOVE_CMD_MOVE_UP;
        else
            gWorkingMoveScr[i-1] = MOVE_CMD_MOVE_DOWN;
    }

    gWorkingMoveScr[i-1] = MOVE_CMD_HALT;
}

static void MovePathFloodFromTail(void)
{
    MapFlood_08019454(gActiveUnit,
        gMovePath->x[gMovePath->path], gMovePath->y[gMovePath->path],
        gMovePath->move[gMovePath->path]);
}

static void RebuildMovePath(void)
{
    CutMovePath(1);
    MovePathFloodFromTail();
    BuildBestMoveScript(gBmSt.cursor.x, gBmSt.cursor.y, gWorkingMoveScr);
    GenMovePathFromMoveScript();
}

static Bool MovePathIsValid(void)
{
    s8 i, j;

    for (i = gMovePath->path; i > 0; --i)
    {
        for (j = i-1; j >= 0; --j)
        {
            if (gMovePath->x[i] == gMovePath->x[j] && gMovePath->y[i] == gMovePath->y[j])
                return FALSE;
        }
    }

    return TRUE;
}

void InitMovePath(Bool displayOnly)
{
    Decompress(Img_MovePath, OBJ_VRAM0 + CHR_SIZE*OBJCHR_MOVEPATH);
    ApplyPalette(Pal_MovePath, 0x10 + OBJPAL_MOVEPATH);

    if (!displayOnly)
    {
        gMovePath->initMove = UNIT_MOV(gActiveUnit) - gAction.moveCount;

        CutMovePath(0);
        AddMovePathSquare(gActiveUnit->x, gActiveUnit->y);

        gMovePath->move[0] = gMovePath->initMove;

        SetMovePathLastCursorPosition(-1, -1);

        UpdateMovePath();
    }
}

static void UpdateMovePath(void)
{
    if (gMovePath->xLast != gBmSt.cursor.x || gMovePath->yLast != gBmSt.cursor.y)
    {
        SetMovePathLastCursorPosition(gBmSt.cursor.x, gBmSt.cursor.y);

        SetWorkingMap(gMapMovement);

        if (gWorkingMapSigned[gBmSt.cursor.y][gBmSt.cursor.x] != -1)
        {
            s8 cut;

            if ((cut = FindMovePathSquare(gBmSt.cursor.x, gBmSt.cursor.y)) != -1)
            {
                CutMovePath(cut+1);
                return;
            }

            if ((gMovePath->move[gMovePath->path] >= GetWorkingMovTable()[gMapTerrain[gBmSt.cursor.y][gBmSt.cursor.x]])
                && (RECT_DISTANCE(gMovePath->x[gMovePath->path], gMovePath->y[gMovePath->path], gBmSt.cursor.x, gBmSt.cursor.y) == 1))
            {
                AddMovePathSquare(gBmSt.cursor.x, gBmSt.cursor.y);
                return;
            }

            if (gMovePath->move[gMovePath->path] == 0)
                CutMovePath(1);

            SetWorkingMap(gMapOther);
            MovePathFloodFromTail();

            if (gWorkingMapSigned[gBmSt.cursor.y][gBmSt.cursor.x] == -1)
            {
                RebuildMovePath();
                return;
            }

            BuildBestMoveScript(gBmSt.cursor.x, gBmSt.cursor.y, gWorkingMoveScr);
            GenMovePathFromMoveScript();

            if (!MovePathIsValid())
                RebuildMovePath();
        }
    }
}

static u8 GetMovePathDirFrom(u8 path)
{
    if (path == 0)
        return MOVEPATH_DIR_NONE;

    if (gMovePath->x[path-1] < gMovePath->x[path])
        return MOVEPATH_DIR_LEFT;

    if (gMovePath->x[path-1] > gMovePath->x[path])
        return MOVEPATH_DIR_RIGHT;

    if (gMovePath->y[path-1] < gMovePath->y[path])
        return MOVEPATH_DIR_UP;

    if (gMovePath->y[path-1] > gMovePath->y[path])
        return MOVEPATH_DIR_DOWN;
}

static u8 GetMovePathDirTo(u8 path)
{
    if (path == gMovePath->path)
        return MOVEPATH_DIR_NONE;

    if (gMovePath->x[path] < gMovePath->x[path+1])
        return MOVEPATH_DIR_RIGHT;

    if (gMovePath->x[path] > gMovePath->x[path+1])
        return MOVEPATH_DIR_LEFT;

    if (gMovePath->y[path] < gMovePath->y[path+1])
        return MOVEPATH_DIR_DOWN;

    if (gMovePath->y[path] > gMovePath->y[path+1])
        return MOVEPATH_DIR_UP;
}

static Bool ShouldDrawMovePathBitAt(short x, short y, u8 xEdge, u8 yEdge)
{
    if ((y-gBmSt.camera.y) > -yEdge && (y-gBmSt.camera.y) < DISPLAY_HEIGHT
        && (x-gBmSt.camera.x) > -xEdge && (x-gBmSt.camera.x) < DISPLAY_WIDTH)
        return TRUE;

    return FALSE;
}

static void DrawMovePath(void)
{
    s8 i;

    if (gMovePath->path == 0)
        return;

    for (i = gMovePath->path; i >= 0; --i)
    {
        short x = gMovePath->x[i] * 0x10;
        short y = gMovePath->y[i] * 0x10;

        if (ShouldDrawMovePathBitAt(x, y, 0x10, 0x10))
        {
            PutSprite(11, x - gBmSt.camera.x, y - gBmSt.camera.y,
                Sprite_16x16, gUnk_085C7E0C[GetMovePathDirTo(i)][GetMovePathDirFrom(i)]);
        }
    }
}

void RefreshMovePath(void)
{
    UpdateMovePath();
    DrawMovePath();
}
