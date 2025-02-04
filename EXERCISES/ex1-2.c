/*演習１－２　xが上にあげなかったある文字であるとして、
printfの引数に\xを含めるとどうなるかを調べる実験をおこなえ？(文言が古すぎ)

    //この課題は、printf関数の引数に\xを含めることで何が起こるかを調べるという実験です。
        解説
        \xは、C言語で「16進数」を示すエスケープシーケンスです。例えば、
        \x41は16進数で「A」に相当する文字を表示します。
        \xの後に続けて16進数で指定したい文字のコードを記述します。
        この演習の目的は、\xをprintfの引数に含めたときに、どのように動作するのかを確認することです。
        \xは16進数の値を文字に変換するために使われ、後ろに続く数値でその変換を制御します。

*/
#include <stdio.h>

int main ()
{
    printf("\x41,\x42,\x43");
}
//A,B,C