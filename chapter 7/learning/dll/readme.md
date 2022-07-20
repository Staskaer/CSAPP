### 测试动态链接库

---

1. 首先，线编写`addvec.c`和`multvec.c`两个源代码和头文件`vector.h`

2. 使用`gcc -shared -fpic -o libvector.so addvec.c mult.c`编译动态链接库

3. 使用`gcc -o prog2.exe main.c ./libvector.so`来进行动态链接