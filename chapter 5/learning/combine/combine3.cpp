#define OP *
#define IDENT 1

typedef struct
{
    int length;
    int *data;
} vec_rec, *vec_ptr;
typedef int data;

data *vec_get_da(vec_ptr v)
{
    return v->data;
}
long vec_get_len(vec_ptr v)
{
    return v->length;
}

void combine3(vec_ptr v, data *dest)
{
    long i;
    long length = vec_get_len(v);
    *dest = IDENT;
    data *d = vec_get_da(v);

    for (i = 0; i < length; i++)
    {
        *dest = *dest OP d[i];
    }
}

/*
这段程序就是反汇编后循环体的部分，可以发现，它先从内存中
读出数据，然后乘法，然后再写回到内存中
.L5:
	cmpl	%esi, %edx
	jge	.L3
	movslq	%edx, %rcx
	movl	(%rax,%rcx,4), %ecx
	imull	(%rbx), %ecx
	movl	%ecx, (%rbx) //写回内存
	addl	$1, %edx
	jmp	.L5
*/

/**
 * 这是开了O1优化后的代码，计数的过程，同时，直接操作一个指针%rax来读取数据
 * 这个和Og的区别不是特别大
 * .L5:
	movl	(%rdx), %ecx
	imull	(%rax), %ecx
	movl	%ecx, (%rdx)
	addq	$4, %rax
	cmpq	%r8, %rax
	jne	.L5
*/

/**
 * 这是开了O2的优化后的代码，此时ecx的作用不再是临时变量，
 * 而是同时参与到当前次的循环作为存入dest的数据，和下一次循环中从内存中读出的dest
 * 从而每次循环结构内减少了整整一次内存读写操作，与combine4的性能变得接近了
 * .L7:
	imull	(%rax), %ecx
	addq	$4, %rax
	cmpq	%rax, %r8
	movl	%ecx, (%rdx)
	jne	.L7
*/