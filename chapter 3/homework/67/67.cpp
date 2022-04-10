typedef struct
{
    long a[2];
    long *p;
} strA;

typedef struct
{
    long u[2];
    long q;

} strB;

strB process(strA s)
{
    strB r;
    r.u[0] = s.a[1];
    r.u[1] = s.a[0];
    r.q = *s.p;
    return r;
}

long eval(long x, long y, long z)
{
    strA s;
    s.a[0] = x;
    s.a[1] = y;
    s.p = &z;
    strB r = process(s);
    return r.u[0] + r.u[1] + r.q;
}

/*
# strB process(strA s)
# s in %rdi
process:
    movq %rdi, %rax         #把栈顶的位置放入%rax
    movq 24(%rsp), %rdx     #rdx = &z（栈帧上,因为多出一个返回地址，所以都要加8的偏移）
    movq (%rdx), %rdx       #是rdx = *p的操作
    movq 16(%rsp), %rcx     #rcx = y
    movq %rcx, (%rdi)       #(是rsp+64) 在栈帧的上方存入y
    movq 8(%rsp), %rcx      #实际上结构体是用之前的函数的栈帧的上部分来存储的
                            #没有为这个函数单独分配新的栈帧
    movq %rcx, 8(%rdi)      #和上面类似，存入x
    movq %rdx, 16(%rdi)
    ret
    #要注意rsp是整个栈的指针，+8是因为存入了返回地址这个偏移量
    #rdi是要存放的结构体的位置
    #通过rsp+bias的方式访问s中元素
    #用rdi+bias的方式保存strB中的元素

# long eval(long x, long y, long z)
# x in %rdi, y in %rsi, z in %rdx
eval:
    subq $104, %rsp         #分配栈空间
    movq %rdx, 24(%rsp)     #在rsp+24的位置放入z
    leaq 24(%rsp), %rax     #把z的地址放入%rax中
    movq %rdi, (%rsp)       #rsp的位置放入x
    movq %rsi, 8(%rsp)      #rsp+8的位置放入y
    movq %rax, 16(%rsp)     #rsp+16的位置放入z的地址（%rax）
    leaq 64(%rsp), %rdi     #向process函数传入rsp+64
    call process            #调用process函数,会分配八字节栈空间，存入返回地址，即下一行代码地址
    movq 72(%rsp), %rax     #计算加法
    addq 64(%rsp), %rax
    addq 80(%rsp), %rax
    addq $104, %rsp         #回收栈帧
    ret

//很明显编译器进行了优化，因为传递的都是地址。
//另外，process没有自己的栈帧
//以及，process传入的第一个参数%rdi实际上是用于保存strB的数据的
//process访问strA的数据则使用%rsp来实现的
//汇编中传入的参数和c语言中传入的参数感觉没有一一对应关系

*/