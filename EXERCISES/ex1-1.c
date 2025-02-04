//演習1－1手元のシステムでプログラムをランさせよ。
//プログラムの一部を省いて、どんなエラーメッセージが出るか試してみよ

#include <stdio.h>

int main ()
{
    printf("hello,world\n");
}
/*PS C:\Users\shimizu_takashi\Documents\Visual Studio Code\programingGengoC> cd "c:\Users\shimizu_takashi\Documents\Visual Studio Code\programingGengoC\EXERCISES\" ; if ($?) { gcc --exec-charset=cp932 ex1-1.c -o ex1-1 } ; if ($?) { chcp 932 | Out-Null } ; if ($?) { .\ex1-1 }
hello,world*/

/*
#include <stdio.h>

int main
{
    printf("hello,world\n");
}

Documents\Visual Studio Code\programingGengoC\EXERCISES\" ; if ($?) { gcc --exec-charset=cp932 ex1-1.c -o ex1-1 } ; if ($?) { chcp 932 | Out-Null } ; if ($?) { .\ex1-1 }
ex1-1.c:7:1: error: expected '=', ',', ';', 'asm' or '__attribute__' before '{' token
    7 | {
      | ^
*/

