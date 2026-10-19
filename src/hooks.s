.arm
.text

.global hook_before_GlobalContext_Update
hook_before_GlobalContext_Update:
    push {r0-r12, lr}
    bl before_GlobalContext_Update
    pop {r0-r12, lr}
.if _TW_==1
    add r1,r0,#0x14
.else
    cpy r7,r0
.endif
    bx lr

.global hook_after_GlobalContext_Update
hook_after_GlobalContext_Update:
    push {r0-r12, lr}
    bl after_GlobalContext_Update
    pop {r0-r12, lr}
.if _TW_==1
    b 0x2FC1A0
.elseif _JP_==1
    b 0x2E2108
.else
# both USA and EUR
    b 0x2E25F0
.endif

.section .loader
.global hook_into_loader
hook_into_loader:
    push {r0-r12, lr}
    bl loader_main
    pop {r0-r12, lr}
.if _TW_==1
    bl 0x100024
.else
    bl 0x100028
.endif
    b  0x100004

.global hook_CameraUpdate
hook_CameraUpdate:
    push {r0-r12, lr}
    cpy r0,r1
    bl Camera_FreeCamEnabled
    cmp r0,#0x0
    pop {r0-r12, lr}
.if _TW_==1
    cpyeq r4,r1
    bxeq lr
    bl Camera_FreeCamUpdate
    pop {r0,r1,r4-r11,pc}
.else
    cpyeq r6,r0
    bxeq lr
    bl Camera_FreeCamUpdate
    ldmia sp!,{r4-r11,pc}
.endif
