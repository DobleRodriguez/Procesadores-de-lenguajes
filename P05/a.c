#include <stdio.h>

int main(int argc, int argp, char const *argv[])
{
    int a = 0 + 'b';
    char* x;
    printf("%d\n", a*4-3);
    printf("%d\n", a*4-3<10000);
    if (a*4-3<10000) {
        printf("XD");
    }
    return ++a;
}

