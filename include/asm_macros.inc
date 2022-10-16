    .macro function name
    .align 2, 0
    .global \name
    .type \name , function
    .endm

    .macro endfunction name
    .size \name , . - \name
    .endm
