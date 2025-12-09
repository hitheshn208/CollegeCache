#include<stdio.h>

typedef enum { ONE = 1, TWO, THREE, FOUR} number_words;

int main()
{
    number_words X;

    X = ONE;
    printf("%d\n", X);
    X = TWO;
    printf("%d\n", X);
    X = THREE;
    printf("%d\n", X);
    X = FOUR;
    printf("%d\n", X);

    return 0;
}