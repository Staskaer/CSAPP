### 测试静态链接库

---

1. 首先，线编写`addvec.c`和`multvec.c`两个源代码和头文件`vector.h`

2. 然后使用`gcc -c addvec.c multvec.c`生成`.o`文件

3. 随后，使用`ar`工具 `ar rcs libvector.lib addvec.o multvec.o`生成库文件

4. 使用库函数进行编写，先编译出`main.c`的`.o`文件`main.o`

5. 最后，将其链接起来 `gcc -static -o prog.exe main.o -L. -llibvector`

6. 可以使用`objdump -D .o文件 > 重定向的文件`来查看各个节的内容