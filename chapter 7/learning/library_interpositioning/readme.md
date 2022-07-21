#### 测试库打桩机制


> ##### 编译时打桩
> 
> 1. 先编写好`mymalloc.c`,`malloc.h`,`main.c` 这几个文件和内容
> 
> 2. `gcc -DCOMPILETIME -C mymalloc.c`先编译出目标文件
> 
> 3. `gcc -I. -o prog.exe main.c mymalloc.o`其中`-I.`是说明在搜索系统路径之前，先查找当前目录下的`malloc.h`文件
> 
> 4. 然后执行这个文件就能看到库函数已经被调换
>

> ##### 链接时打桩
> 
> 1. 链接时打桩主要是使用了`--wrap f`标志进行打桩，所有调用`f()`的位置被解析成`__wrap_f()`，而所有被调用`__real_f()`的位置被解析成`f()`
> 
> 2. 使用`gcc -DLINKTIME -C mymalloc.c`生成目标文件
> 
> 3. 使用`gcc -c main.c`生成目标文件
> 
> 4. 使用`gcc -Wl,--wrap,malloc -Wl,--wrap,free -o prog2.exe main.o mymalloc.o`来进行链接时打桩

