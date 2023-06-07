.arm
.text

.global hook_before_GlobalContext_Update
hook_before_GlobalContext_Update:
    push {r0-r12, lr}
    bl before_GlobalContext_Update
    pop {r0-r12, lr}
    cpy r7,r0
    bx lr

.section .loader
.global hook_into_loader
hook_into_loader:
    push {r0-r12, lr}
    bl loader_main
    pop {r0-r12, lr}
    bl 0x100028
    b  0x100004

.global hook_CameraUpdate
hook_CameraUpdate:
    push {r0-r12, lr}
    cpy r0,r1
    bl Camera_FreeCamEnabled
    cmp r0,#0x0
    pop {r0-r12, lr}
    cpyeq r6,r0
    bxeq lr
    bl Camera_FreeCamUpdate
    ldmia sp!,{r4-r11,pc}
