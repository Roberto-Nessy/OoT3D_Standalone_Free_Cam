#include "input.h"
#include "common.h"
#include "z3D/z3D.h"
#include "3ds/srv.h"
#include "3ds/services/irrst.h"

GlobalContext* gGlobalContext;

void before_GlobalContext_Update(GlobalContext* globalCtx) {
    static u8 init = 0;
    if (!init) {
        srvInit();
        irrstInit();
        gGlobalContext = globalCtx;
        init = 1;
    }
    Input_Update();
}
