union ele
{
    struct
    {
        long *p;
        long y;
    } e1;
    struct
    {
        long x;
        union ele *next;
    } e2;
};
/*
偏移值：(以long为8字节)
e1.p        0
e1.y        8
e2.x        0
e2.next     8
*/
/*
总共需要16个字节
*/

void proc(union ele *up)
{
    up->e2.x = *(up->e2.next->e1.p) - up->e2.next->e1.y;
}
/*
up in rdi

proc:
    movq    8(%rdi),   %rax     #rax = next
    movq    (%rax),    %rdx     #rdx = *next
    movq    (%rdx),    %rdx     #rdx = *p
    subq    8(%rax),   %rdx     #rdx = *p - y
    movq    %rdx,      (%rdi)   #*up = rdx
    ret
*/