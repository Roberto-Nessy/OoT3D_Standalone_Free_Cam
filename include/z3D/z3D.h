#ifndef _Z3D_H_
#define _Z3D_H_

#include "z3Dactor.h"
#include "z3Dvec.h"

// Save Context (ram start: 0x00587958)
typedef struct {
    /* 0x0000 */ s32 entranceIndex;
    /* 0x0004 */ s32 linkAge; // 0: Adult; 1: Child
    /* 0x0008 */ s32 cutsceneIndex;
    /* 0x000C */ u16 dayTime;
    /* 0x000E */ u8 masterQuestFlag;
    char unk000F[0x14D5];
    /* 0x14E4 */ s32 gameMode;
    char unk14E8[0x00DC];
} SaveContext; // size = 0x15C4

//typedef struct GraphicsContext GraphicsContext; // TODO
typedef struct GlobalContext GlobalContext;
typedef struct {
    /* 0x000 */ char unk_000[0x080];
    /* 0x080 */ Vec3f at;
    /* 0x08C */ Vec3f eye;
    /* 0x098 */ Vec3f up;
    /* 0x0A4 */ Vec3f eyeNext;
    /* 0x0B0 */ Vec3f skyboxOffset;
    /* 0x0BC */ char unk_0BC[0x018];
    /* 0x0D4 */ GlobalContext* globalCtx;
    /* 0x0D8 */ Player* player;
    /* 0x0DC */ PosRot playerPosRot;
    /* 0x0F0 */ Actor* target;
    /* 0x0F4 */ PosRot targetPosRot;
    /* 0x108 */ f32 rUpdateRateInv;
    /* 0x10C */ f32 pitchUpdateRateInv;
    /* 0x110 */ f32 yawUpdateRateInv;
    /* 0x114 */ f32 xzOffsetUpdateRate;
    /* 0x118 */ f32 yOffsetUpdateRate;
    /* 0x11C */ f32 fovUpdateRate;
    /* 0x120 */ f32 xzSpeed;
    /* 0x124 */ f32 dist;
    /* 0x128 */ f32 speedRatio;
    /* 0x12C */ Vec3f playerToAtOffset;
    /* 0x138 */ Vec3f playerPosDelta;
    /* 0x144 */ f32 fov;
    /* 0x148 */ f32 atLERPStepScale;
    /* 0x14C */ f32 playerGroundY;
    /* 0x150 */ Vec3f floorNorm;
    /* 0x15C */ f32 waterYPos;
    /* 0x160 */ s32 waterPrevCamIdx;
    /* 0x164 */ s32 waterPrevCamSetting;
    /* 0x168 */ s32 waterQuakeIdx;
    /* 0x16C */ char unk_16C[0x00C];
    /* 0x178 */ s16 uid;
    /* 0x17A */ char unk_17A[0x002];
    /* 0x17C */ Vec3s inputDir;
    /* 0x182 */ Vec3s camDir;
    /* 0x188 */ s16 status;
    /* 0x18A */ s16 setting;
    /* 0x18C */ s16 mode;
    /* 0x18E */ s16 bgCheckId;
    /* 0x190 */ s16 camDataIdx;
    /* 0x192 */ s16 behaviorFlags;
    /* 0x194 */ s16 stateFlags;
    /* 0x196 */ s16 childCamIdx;
    /* 0x198 */ s16 waterDistortionTimer;
    /* 0x19A */ s16 distortionFlags;
    /* 0x19C */ s16 prevSetting;
    /* 0x19E */ s16 nextCamDataIdx;
    /* 0x1A0 */ s16 nextBgCheckId;
    /* 0x1A2 */ s16 roll;
    /* 0x1A4 */ s16 paramFlags;
    /* 0x1A6 */ s16 animState;
    /* 0x1A8 */ s16 timer;
    /* 0x1AA */ s16 parentCamIdx;
    /* 0x1AC */ s16 thisIdx;
    /* 0x1AE */ s16 prevCamDataIdx;
    /* 0x1B0 */ s16 csId;
    /* 0x1B2 */ char unk_1B2[0x00A];
} Camera; // size = 0x1BC

typedef struct {
    /* 0x0 */ u16 setting;
    /* 0x2 */ s16 count;
    /* 0x4 */ Vec3s* camFuncData;
} CamData; // size = 0x8

typedef struct {
    /* 0x00 */ Vec3f atOffset;
    /* 0x0C */ Vec3f eyeOffset;
    /* 0x18 */ s16 upPitchOffset;
    /* 0x1A */ s16 upYawOffset;
    /* 0x1C */ s16 fovOffset;
    /* 0x20 */ f32 maxOffset;
} ShakeInfo; // size = 0x24

typedef struct {
    /* 0x00 */ char unk_00[0x04];
    /* 0x04 */ Vec3s minBounds;
    /* 0x0A */ Vec3s maxBounds;
    /* 0x10 */ u16 numVertices;
    /* 0x12 */ u16 numPolygons;
    /* 0x14 */ u16 numWaterboxes;
    /* 0x18 */ Vec3s* vtxList;
    /* 0x1C */ CollisionPoly* polyList;
    /* 0x20 */ void* surfaceTypeList;
    /* 0x24 */ CamData* camDataList;
    /* 0x28 */ void* waterboxes;
} CollisionHeader; // size = 0x2C

typedef struct {
    /* 0x00 */ CollisionHeader* colHeader;
    /* 0x04 */ char unk_04[0x4C];
} StaticCollisionContext; // size = 0x50

typedef struct {
    /* 0x00 */ Actor* actor;
    /* 0x04 */ CollisionHeader* colHeader;
    /* 0x08 */ char unk_04[0x0C];
    /* 0x14 */ Vec3f scale1;
    /* 0x20 */ Vec3s rot1;
    /* 0x28 */ Vec3f pos1;
    /* 0x34 */ Vec3f scale2;
    /* 0x40 */ Vec3s rot2;
    /* 0x48 */ Vec3f pos2;
    /* 0x54 */ char unk_54[0x18];
} ActorMesh; // size = 0x6C

typedef struct {
    /* 0x0000 */ char unk_00[0x04];
    /* 0x0004 */ ActorMesh actorMeshArr[50];
    /* 0x151C */ u16 flags[50];
    /* 0x1580 */ char unk_13F0[0x24];
} DynaCollisionContext; // size = 0x15A4

typedef struct {
    /* 0x0000 */ StaticCollisionContext stat;
    /* 0x0050 */ DynaCollisionContext dyna;
} CollisionContext; // size = 0x15F4

typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f norm;
    /* 0x18 */ CollisionPoly* poly;
    struct {
        /* 0x1C */ f32 radius;
        /* 0x20 */ s16 pitch;
        /* 0x22 */ s16 yaw;
    } geoNorm;
    /* 0x24 */ s32 bgId;
} CamColChk; // size = 0x28

// Global Context (ram start: 0871E840)
typedef struct GlobalContext {
    char unk0000[0x0104];
    /* 0x0104 */ s16 sceneNum;
    char unk0106[0x0082];
    struct {
        /* 0x0188 */ s32 topY;
        /* 0x018C */ s32 bottomY;
        /* 0x0190 */ s32 leftX;
        /* 0x0194 */ s32 rightX;
        /* 0x0198 */ f32 fovY;
        /* 0x019C */ f32 zNear;
        /* 0x01A0 */ f32 zFar;
        /* 0x01A4 */ f32 scale;
        /* 0x01A8 */ char unk_01A8[0x0010];
        /* 0x01B8 */ Vec3f eye;
        /* 0x01C4 */ Vec3f at;
        /* 0x01D0 */ Vec3f up;
        /* 0x01DC */ char unk_01DC[0x0150];
        /* 0x032C */ Vec3f distortionOrientation;
        /* 0x0338 */ Vec3f distortionScale;
        /* 0x0344 */ char unk_0344[0x0018];
        /* 0x035C */ f32 distortionSpeed;
        /* 0x0360 */ char unk_0360[0x0004];
    } view;
    /* 0x0364 */ Camera mainCamera;
    /* 0x0520 */ Camera subCameras[3];
    /* 0x0A54 */ Camera* cameraPtrs[4];
    /* 0x0A64 */ s16 activeCamera;
    char unk0A66[0x0032];
//    /* 0x0A66 */ char unk_A66[0x0032];
    /* 0x0A98 */ CollisionContext colCtx;
    char unk208C[0x2BA5];
    /* 0x4C31 */ char unk_4C31[0x0FCF];
    char unk5C00[0x0314];
} GlobalContext; // size = 0x5F14 TODO
_Static_assert(sizeof(GlobalContext) == 0x5F14, "Global Context size");

#define gSaveContext (*(SaveContext*)0x00587958)
#define real_hid_addr 0x10002000
#define real_hid (*(hid_mem_t*)real_hid_addr)

#define Z3D_TOP_SCREEN_LEFT_1 0x14313890
#define Z3D_TOP_SCREEN_LEFT_2 0x14359DA0
#define Z3D_TOP_SCREEN_RIGHT_1 0x14410AD0
#define Z3D_TOP_SCREEN_RIGHT_2 0x14456FE0
#define Z3D_BOTTOM_SCREEN_1 0x143A02B0
#define Z3D_BOTTOM_SCREEN_2 0x143D86C0

#ifdef Version_JP
    #define ADDR(locUSA) (\
        ((locUSA) < 0x2B6D4C) ? (locUSA) : \
        ((locUSA) < 0x2B7234) ? (locUSA) + 0xC0B5C : \
        ((locUSA) < 0x377D90) ? (locUSA) - 0x4E8 : \
        ((locUSA) < 0x41A144) ? (locUSA) : \
        ((locUSA) < 0x4A5B00) ? (locUSA) - 0x28 : (locUSA))
#elifdef Version_EUR
    #define ADDR(locUSA) (\
        ((locUSA) < 0x41A144) ? (locUSA) : \
        ((locUSA) < 0x436690) ? (locUSA) + 0x24 : \
        ((locUSA) < 0x4A5B00) ? (locUSA) + 20 : (locUSA))
#else
    #define ADDR(locUSA) (locUSA)
#endif

typedef s32 (*BossChallenge_IsActive_proc)(void);
#define BossChallenge_IsActive ((BossChallenge_IsActive_proc)ADDR(0x35B164))

typedef s32 (*Camera_CheckWater_proc)(Camera* camera);
#define Camera_CheckWater ((Camera_CheckWater_proc)ADDR(0x2D06A0))

typedef void (*Camera_UpdateInterface_proc)(u32 flags);
#define Camera_UpdateInterface ((Camera_UpdateInterface_proc)ADDR(0x330D84))

typedef f32 (*Camera_BGCheckInfo_proc)(Camera* camera, Vec3f* from, CamColChk* to);
#define Camera_BGCheckInfo ((Camera_BGCheckInfo_proc)ADDR(0x3553FC))

typedef s32 (*Quake_Update_proc)(Camera* camera, ShakeInfo* camShake);
#define Quake_Update ((Quake_Update_proc)ADDR(0x4787C8))

typedef s16 (*Camera_GetCamDataId_proc)(CollisionContext* colCtx, CollisionPoly* poly, s32 bgId);
#define Camera_GetCamDataId ((Camera_GetCamDataId_proc)ADDR(0x47BFD8))

#endif //_Z3D_H_
