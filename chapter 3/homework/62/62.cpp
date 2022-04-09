typedef enum
{
    MODE_A,
    MODE_B,
    MODE_C,
    MODE_D,
    MODE_E
} mode_t;

/*
p1 在%rdi， p2在%dsi， action在%edx

.L8:    #mode_e
    movl    $27,    %rax
    ret

.L3:    #mode_a
    movq    (%rsi), %rax
    movq    (%rdi), %rdx
    movq    %rdx,   (%rsi)
    ret

.L5:    #mode_b
    movq    (%rdi), %rax
    addq    (%rsi), %rax
    movq    %rax,   (%rdi)
    ret

.L6:    #mode_c
    movq    (%rsi), %rax
    movq    %rax,   (%rdi)
    movl    $27     %eax
    ret

.L9     #default
    movl    $12,    %eax
    ret


*/

long switch3(long *p1, long *p2, mode_t action)
{
    long result = 0;
    switch (action)
    {
    case MODE_A:
        result = *p2;
        *p2 = *p1;
        break;
    case MODE_B:
        *p1 += *p2;
        result = *p1;
        break;
    case MODE_C:
        *p1 = 59;
        result = *p2;
        break;
    case MODE_D:
        *p1 = *p2;
        result = 27;
    case MODE_E:
        return 27;
    default:
        return 12;
    }
    return result;
}

//gcc -Og -S 62.cpp生成的汇编差距有点大，但感觉应该没什么问题，这个逻辑还算比较容易的