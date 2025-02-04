//演習１－６　getchar() != EOF という式の値が０か１かであることを確認せよ
#include <stdio.h>

int main ()
{
    int c;
    c = getchar() != EOF;
    printf("%d",c);
}
//1