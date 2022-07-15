
#include <stdio.h>
#include <stdlib.h>
void f();
int y = 15212;
int x = 15213;
int main()
{
    f();
    printf("after call = %d , %d", x, y);
    system("pause");
    return 0;
}