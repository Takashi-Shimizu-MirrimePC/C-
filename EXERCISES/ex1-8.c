//演習１ー８　空白、タブ、改行を数えるプログラムをかけ

#include <stdio.h>

int main ()
{
    int c,space,tab,newLine;
    space = tab = newLine = 0; //1行で初期化できる✋
    while(( c = getchar()) != EOF){
        if( c == ' ')
            ++space;
        if( c == '\t')
            ++tab;
        if( c == '\n')
            ++newLine;
    }
    printf("****counts****\n  space:%3d\n    tab:%3d\nnewline:%3d",space,tab,newLine);
    return 0;
}
/*
asdasd                                                  





^Z
****counts****
  space:  6
    tab:  6
newline:  6

間違えたところ
c　=　getcharのかっこが足りなかった。
space = tab = newLine = 0 ; でも初期化になるよね？？　なった✋

*/