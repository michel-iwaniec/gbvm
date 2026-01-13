.module scene_1_init

.include "vm.i"
.include "data/game_globals.i"

.globl _fade_frames_per_step, b_wait_frames, _wait_frames

.area _CODE_255

.LOCAL_ACTOR = -4
.LOCAL_TMP4_WAIT_ARGS = -4
.LOCAL_TMP1_WAIT_ARGS = -5
.LOCAL_TMP2_WAIT_ARGS = -5
.LOCAL_TMP3_WAIT_ARGS = -5

___bank_scene_1_init = 255
.globl ___bank_scene_1_init

_scene_1_init::
        VM_LOCK

        VM_RESERVE              5

        ; Set Sprite Mode: 8x16
        VM_SET_SPRITE_MODE      .MODE_8X16

GBVM$scene_1_init$autofade$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$autofade$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Wait 1 Frames
        VM_IDLE

        ; Fade In
        VM_SET_CONST_INT8       _fade_frames_per_step, 1
        VM_FADE_IN              1

GBVM$scene_1_init$50e901b3_a3d8_4269_bf59_388f458184d7$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$50e901b3_a3d8_4269_bf59_388f458184d7$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
GBVM$scene_1_init$67b6fa94_98f3_4b00_ac1a_a4fa0e40f02e$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$67b6fa94_98f3_4b00_ac1a_a4fa0e40f02e$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Text Dialogue
        VM_OVERLAY_CLEAR        0, 0, 20, 5, .UI_COLOR_WHITE, .UI_DRAW_FRAME
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_SPEED_INSTANT
        VM_OVERLAY_MOVE_TO      0, 13, .OVERLAY_IN_SPEED
        VM_OVERLAY_SET_SCROLL   1, 1, 18, 5, .UI_COLOR_WHITE
        VM_LOAD_TEXT            0
        .asciz "scene projectile\012dir: right\012strong: false"
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

GBVM$scene_1_init$61f73b71_5251_46c8_9ae9_077adbd035c1$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$61f73b71_5251_46c8_9ae9_077adbd035c1$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Launch Projectile In Direction
        VM_ACTOR_GET_POS        .LOCAL_ACTOR
        VM_RPN
            .R_REF      ^/(.LOCAL_ACTOR + 1)/
            .R_REF      ^/(.LOCAL_ACTOR + 2)/
            .R_INT16    64
            .R_STOP
        VM_PROJECTILE_LAUNCH    0, .ARG2
        VM_POP                  3

GBVM$scene_1_init$c7767b1c_1d44_4742_99a8_e3936e54d5e0$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$c7767b1c_1d44_4742_99a8_e3936e54d5e0$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Wait 30 frames
        VM_SET_CONST            .LOCAL_TMP1_WAIT_ARGS, 30
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP1_WAIT_ARGS

GBVM_END$scene_1_init$50e901b3_a3d8_4269_bf59_388f458184d7 = .
.globl GBVM_END$scene_1_init$50e901b3_a3d8_4269_bf59_388f458184d7
GBVM$scene_1_init$d96c6681_c985_4a7e_9599_275c952533ad$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$d96c6681_c985_4a7e_9599_275c952533ad$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
GBVM$scene_1_init$6e21d864_eccb_4e4e_8f65_76be8b02f2d2$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$6e21d864_eccb_4e4e_8f65_76be8b02f2d2$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Text Dialogue
        VM_OVERLAY_CLEAR        0, 0, 20, 5, .UI_COLOR_WHITE, .UI_DRAW_FRAME
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_SPEED_INSTANT
        VM_OVERLAY_MOVE_TO      0, 13, .OVERLAY_IN_SPEED
        VM_OVERLAY_SET_SCROLL   1, 1, 18, 5, .UI_COLOR_WHITE
        VM_LOAD_TEXT            0
        .asciz "scene projectile\012dir: up\012strong: true"
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

GBVM$scene_1_init$f1a10c37_9bc6_492d_9ec7_da827130826b$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$f1a10c37_9bc6_492d_9ec7_da827130826b$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Launch Projectile In Direction
        VM_ACTOR_GET_POS        .LOCAL_ACTOR
        VM_RPN
            .R_REF      ^/(.LOCAL_ACTOR + 1)/
            .R_REF      ^/(.LOCAL_ACTOR + 2)/
            .R_INT16    0
            .R_STOP
        VM_PROJECTILE_LAUNCH    1, .ARG2
        VM_POP                  3

GBVM$scene_1_init$c781c485_41c2_473e_90a3_4e0c67fcee7e$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$c781c485_41c2_473e_90a3_4e0c67fcee7e$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Wait 30 frames
        VM_SET_CONST            .LOCAL_TMP2_WAIT_ARGS, 30
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP2_WAIT_ARGS

GBVM_END$scene_1_init$d96c6681_c985_4a7e_9599_275c952533ad = .
.globl GBVM_END$scene_1_init$d96c6681_c985_4a7e_9599_275c952533ad
GBVM$scene_1_init$aa5c621e_d049_4c8c_ad22_1f42ad1dcb24$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$aa5c621e_d049_4c8c_ad22_1f42ad1dcb24$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
GBVM$scene_1_init$8d43327c_7203_4cd8_a63d_5a0fb5de2653$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$8d43327c_7203_4cd8_a63d_5a0fb5de2653$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Load Projectile Into Slot
        VM_PROJECTILE_LOAD_TYPE 2, 0, ___bank_global_projectiles_0, _global_projectiles_0

GBVM$scene_1_init$6a2dae75_7a1d_4b3e_a94f_a5e5d7623156$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$6a2dae75_7a1d_4b3e_a94f_a5e5d7623156$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Load Projectile Into Slot
        VM_PROJECTILE_LOAD_TYPE 3, 1, ___bank_global_projectiles_0, _global_projectiles_0

GBVM_END$scene_1_init$aa5c621e_d049_4c8c_ad22_1f42ad1dcb24 = .
.globl GBVM_END$scene_1_init$aa5c621e_d049_4c8c_ad22_1f42ad1dcb24
GBVM$scene_1_init$96962aa8_a927_4a02_b3b7_b5f95e7e708c$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$96962aa8_a927_4a02_b3b7_b5f95e7e708c$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
GBVM$scene_1_init$ff84df4f_ed3d_48a5_9c67_41b46be2e72d$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$ff84df4f_ed3d_48a5_9c67_41b46be2e72d$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Text Dialogue
        VM_OVERLAY_CLEAR        0, 0, 20, 5, .UI_COLOR_WHITE, .UI_DRAW_FRAME
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_SPEED_INSTANT
        VM_OVERLAY_MOVE_TO      0, 13, .OVERLAY_IN_SPEED
        VM_OVERLAY_SET_SCROLL   1, 1, 18, 5, .UI_COLOR_WHITE
        VM_LOAD_TEXT            0
        .asciz "slot projectile\012dir: left\012strong: false"
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

GBVM$scene_1_init$d8e819bf_e86d_4fdd_a68b_30b0b7b8de6b$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$d8e819bf_e86d_4fdd_a68b_30b0b7b8de6b$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Launch Projectile In Direction
        VM_ACTOR_GET_POS        .LOCAL_ACTOR
        VM_RPN
            .R_REF      ^/(.LOCAL_ACTOR + 1)/
            .R_REF      ^/(.LOCAL_ACTOR + 2)/
            .R_INT16    192
            .R_STOP
        VM_PROJECTILE_LAUNCH    2, .ARG2
        VM_POP                  3

GBVM$scene_1_init$d2f1968b_cdf4_4df1_9174_de315bef6d6f$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$d2f1968b_cdf4_4df1_9174_de315bef6d6f$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Wait 30 frames
        VM_SET_CONST            .LOCAL_TMP3_WAIT_ARGS, 30
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP3_WAIT_ARGS

GBVM_END$scene_1_init$96962aa8_a927_4a02_b3b7_b5f95e7e708c = .
.globl GBVM_END$scene_1_init$96962aa8_a927_4a02_b3b7_b5f95e7e708c
GBVM$scene_1_init$6b018cba_4f34_41b3_a931_8aa77f560d59$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$6b018cba_4f34_41b3_a931_8aa77f560d59$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
GBVM$scene_1_init$8f020371_b6b9_4ffe_84e8_0f0daa301fe6$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$8f020371_b6b9_4ffe_84e8_0f0daa301fe6$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Text Dialogue
        VM_OVERLAY_CLEAR        0, 0, 20, 5, .UI_COLOR_WHITE, .UI_DRAW_FRAME
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_SPEED_INSTANT
        VM_OVERLAY_MOVE_TO      0, 13, .OVERLAY_IN_SPEED
        VM_OVERLAY_SET_SCROLL   1, 1, 18, 5, .UI_COLOR_WHITE
        VM_LOAD_TEXT            0
        .asciz "scene projectile\012dir: right\012strong: true"
        VM_DISPLAY_TEXT
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT | .UI_WAIT_BTN_A)/
        VM_OVERLAY_MOVE_TO      0, 18, .OVERLAY_OUT_SPEED
        VM_OVERLAY_WAIT         .UI_MODAL, ^/(.UI_WAIT_WINDOW | .UI_WAIT_TEXT)/

GBVM$scene_1_init$f6a703cd_eb38_406a_96c3_5826922fcf87$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$f6a703cd_eb38_406a_96c3_5826922fcf87$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Actor Set Active
        VM_SET_CONST            .LOCAL_ACTOR, 0

        ; Launch Projectile In Direction
        VM_ACTOR_GET_POS        .LOCAL_ACTOR
        VM_RPN
            .R_REF      ^/(.LOCAL_ACTOR + 1)/
            .R_REF      ^/(.LOCAL_ACTOR + 2)/
            .R_INT16    128
            .R_STOP
        VM_PROJECTILE_LAUNCH    3, .ARG2
        VM_POP                  3

GBVM$scene_1_init$21f9f830_8664_4128_a3b8_4773906593ea$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script = .
.globl GBVM$scene_1_init$21f9f830_8664_4128_a3b8_4773906593ea$31c1306c_bbcd_45f4_acb8_c9825ba781ac$scene$31c1306c_bbcd_45f4_acb8_c9825ba781ac$script
        ; Wait 30 frames
        VM_SET_CONST            .LOCAL_TMP4_WAIT_ARGS, 30
        VM_INVOKE               b_wait_frames, _wait_frames, 0, .LOCAL_TMP4_WAIT_ARGS

GBVM_END$scene_1_init$6b018cba_4f34_41b3_a931_8aa77f560d59 = .
.globl GBVM_END$scene_1_init$6b018cba_4f34_41b3_a931_8aa77f560d59
        ; Stop Script
        VM_STOP
