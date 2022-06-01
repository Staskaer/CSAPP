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
    data acc = IDENT;
    data *d = vec_get_da(v);

    for (i = 0; i < length; i++)
    {
        acc = *dest OP d[i];
    }
    *dest = acc;
}

/*
与combine3相比，这段明显没有了写回内存那一步，这减少了巨大的开销
但是同样可以发现，combine4也需要每次读写一次内存，和开了O2优化的combine3性能类似了
.L5:
	cmpl	%esi, %edx
	jge	.L4
	movslq	%edx, %rcx
	movl	(%rax,%rcx,4), %ecx
	imull	(%rbx), %ecx
	addl	$1, %edx
	jmp	.L5
*/