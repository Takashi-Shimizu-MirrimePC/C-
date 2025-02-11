//演習１－９　
//二つ以上の空白を1つの空白に置き換えながら入力を出力に複写するプログラムを書け
/*
ちょっと難しそうだな、、、、考えてから書こう
while( (c = getchar() != EOF))}
    if(c == ' '' ')｛
        putchar(' ');
    ｝    
}
putchar(c); かな…


#include <stdio.h>
int main ()
{
int c,space;
space = ' ';
while((c = getchar()) != EOF)
    if(c ==(space >= 1))
        c == (space == 1);
    putchar(c);
    return 0;   
}
二つ以上の空白を1つの空白に置き換える
if
*/

#include <stdio.h>

int main ()

{
    int c, last_char;
    last_char = 0;
    
    while(( c = getchar()) != EOF){
        if(c != ' ' || last_char != ' '){
            last_char = c;
            putchar(c);
        }
        
    } putchar(c);
    return 0;  
}
/*
asd      a        a    
asd a a 
a     a     a  
a a a

分からなかったところ
    空白2つをどう表現するか分からなかった
        空白二つを1つに置換するのは
        if(ｃに空白がいつ以上あったら)
            ｛ひとつにする｝という考え方だった
    でもIf文は（条件）｛真の処理｝だったよねだから
        if(真になる条件){処理}をかかんといけん

    もし（　ｃ　が　' 'じゃない、last_charが' 'じゃない　どっちかが真なら
    if(c != ' ' || last_char != ' ' ){
            以下の処理がおこなわれる。
            last_char(c);
            putchar(c);
    }

☆☆☆
    ||は論理演算子で、論理和（OR）を表します。
    2つの条件のうち少なくとも1つが真（true）であれば、全体の条件が真になります。
    例えば、以下の条件式では、cが空白でないか、
    last_charが空白でない場合に真となります：
        if (c != ' ' || last_char != ' ') {
            // ここに処理を書く
        }

||（論理和）を使用することで、連続する空白文字を
    1つにまとめるロジックを実現しています。
    具体的には、以下のように動作します：

    １：c != ' ':
        現在の文字 c が空白でない場合に真となります。

    ２：last_char != ' ':
        前の文字 last_char が空白でない場合に真となります。
        この2つの条件のどちらかが真であれば、現在の文字 c を出力します。これにより、連続する空白文字が1つにまとめられます。
        
        １：最初の文字が空白でない場合:
            c != ' ' が真となり、文字が出力されます。
        ２：最初の文字が空白で、次の文字も空白の場合:
            c == ' ' かつ last_char == ' ' となり、条件が偽となるため、
            2つ目の空白は出力されません。
        ３：最初の文字が空白で、次の文字が空白でない場合:
            c != ' ' が真となり、次の文字が出力されます。
            このようにして、連続する空白文字を1つにまとめることができます。
　
*/

