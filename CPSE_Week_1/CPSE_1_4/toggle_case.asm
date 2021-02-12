.cpu cortex-m0
.text
.align 2
.global toggle_case

toggle_case:
    PUSH { R4, LR }
    MOV R4, R0
compare_a:
    CMP R0, #65
    BGE compare_z
    bl done
compare_z:
    CMP R0, #90
    BLE toggle_Upper
    BGE compare_A
compare_A:
    CMP R0, #97
    BGE compare_Z
    BL done
compare_Z:
    CMP R0, #122
    BLE toggle_Lower
    BL done

toggle_Upper:
    ADD R0, #32
    BL done
toggle_Lower:
    SUB R0, #32
    BL done

done: 
    POP { R4, PC }
