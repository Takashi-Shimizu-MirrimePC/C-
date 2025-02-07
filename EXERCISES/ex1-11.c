/*演習１−１１単語カウントプログラムのテストはどのようにするか
            もしバグがあるとしたらそれを暴き出すにはどんな入力をするのがよいか

先に説明されていたプログラムに欠陥はありませんし、テストをする方法としては、出力をより分かりやすくする。

printf("%d %d %d\n", nl, nw, nc);の部分を

printf("改行数:%d 単語数:%d 文字総数:%d\n", nl, nw, nc);と表記することを思いつきました。

もしバグがあった場合、それを見つけるためにはどんな入力をすれば効果的かという部分は

入力内容に対してより正確に把握できるようにすることを思いつきました。

空白のカウントも増やして、文字に含まれる!や,や.のカウントを別にしたり、

エラーメッセージを出力できるようにしたり、

入力文字の上限を決めたり、マルチバイト文字に対応させたり、というのが解答として適しているでしょうか？

どう思いますか？


>>>>>>>1. 出力をより分かりやすくする
            printf("改行数:%d 単語数:%d 文字総数:%d\n", nl, nw, nc);
            これにより、プログラムが何を出力しているのかが直感的に理解できやすくなります。
            この修正は実際にテストをする際にも役立つ


もしバグがあるとしたらそれを暴き出すにはどんな入力をするのがよいか
    プログラムの動作を正確にテストするためには、いくつかのテストケースを用意することが重要です。
    考えられるケースを網羅的にテストすることで、どんな入力にも対応できるプログラムが作成できます。
>>>>>>>2. テスト方法
        テストケースの例
        空の入力：何も入力せずに EOF を送る。出力が 0 0 0 となることを確認。
        単語を含む通常の文：例えば、Hello world! という入力をした場合、単語数や文字数が正しくカウントされるか確認。
        連続した空白：Hello world! というように空白が複数ある場合に正しく単語数をカウントできるか。
        複数行入力：改行や複数行が入力された場合に、行数や単語数、文字数が正しくカウントされるか確認。
        タブ文字や特殊文字を含む入力：Hello\tworld! というようにタブ文字を入力した場合や、Hello, world! などの句読点が含まれる場合に問題なく処理できるか。
>>>>>>>3. バグを見つけるための入力
        バグを見つけるためには、エッジケースを意識した入力をすることが効果的です。例えば：
        空白が連続する場合：複数の空白が連続する場合、単語のカウントが正しく行われるか確認します。
        改行と空白が多い場合：改行や空白が多すぎる場合、単語数が一度にカウントされるかどうか。
        特殊文字や記号：!, ,, ., ? などの記号が単語カウントに影響しないかをチェック
            Hello    world!   This is a test.   
            Hello → 単語1
            world! → 単語2
            This → 単語3
            is → 単語4
            a → 単語5
            test. → 単語6
            こんな入力でも問題なく正しい結果が出力されるか確認します。
>>>>>>>4. エラーメッセージとデバッグ
        バグを見つけるために、次のような工夫も有効です：    
        エラーメッセージを追加して、予期しない入力や処理に対して警告を出す。
        たとえば、空白や改行以外の文字が入力されたときに、その文字を出力するなどしてデバッグを容易にします。
            if (c == ' ' || c == '\n' || c == '\t') {
                state = OUT;
            } else {
                printf("Unexpected character: %c\n", c);
            }
>>>>>>>5. 入力文字の上限やマルチバイト文字への対応
        入力文字数の上限：getchar() で1文字ずつ処理しているので、バッファオーバーフローを防ぐために
                        入力の上限を設定することも検討できます。例えば、最大で MAX_INPUT_LENGTH の制限
                        を設け、その範囲内で入力を処理するようにします。
        マルチバイト文字の対応：日本語や他のマルチバイト文字が含まれる入力に対応するためには、
                        getchar() の代わりに、マルチバイト文字を処理できる関数を使う必要があります。
                        例えば、fgetwc() を使ってワイド文字を処理する方法などが考えられます。
>>>>>>>6. 最も適当な解答
        演習問題の解答として最も適当な方法は、次の点をカバーするものです：

        多様な入力ケースを使ってテストし、プログラムの正確さを確認。
        エラーメッセージの表示やデバッグ用のログを追加して、問題が発生した場合に追跡できるようにする。
        改行、空白、タブなどの文字区切りを正しく処理し、文字数や単語数のカウントが正しいことを確認。
        文字数のカウントに空白や改行、タブなどを正しく反映させる。
        できれば、バッファオーバーフローを避けるために、入力の制限を設ける。
        テストをしっかり行い、エラーメッセージやログでデバッグしやすくすることが重要です。
#include <stdio.h>
#define IN 1
#define OUT 0

int main ()
{
    int c, nl, nw, nc, state;
    state = OUT; 
    nl = nw = nc = 0;
    while (( c = getchar()) != EOF ) {
        ++nc;
        if ( c == '\n' )
            ++nl;
        if ( c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if ( state == OUT ) {
            state = IN;
            ++nw;
        }   
    }
    printf("%d %d %d\n", nl, nw, nc);
    return 0;
}*/
/*
#include <stdio.h>
#define IN  1
#define OUT 0

int main(){
  int wordcounter, nowstatus;
  int c;
  nowstatus = OUT;
  wordcounter = 0;
  while((c = getchar()) != EOF){
    if(c == '\t' || c == ' ' || c == '\n'){
      nowstatus = OUT;
    }else if(nowstatus == OUT){
      nowstatus = IN;
      ++wordcounter;
    }
  }
  printf("%d\n", wordcounter);
}
#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
    int c, nl, nw, nc, state;
    state = OUT; // 状態は最初はOUT
    nl = nw = nc = 0; // 行数、単語数、文字数を初期化

    while ((c = getchar()) != EOF) {
        ++nc; // 文字数をカウント

        if (c == '\n') // 改行が来たら行数を増やす
            ++nl;

        if (c == ' ' || c == '\n' || c == '\t') // 空白、改行、タブが来たら
            state = OUT; // OUTにする（単語の境界）
        else if (state == OUT) { // OUTからINに移行するタイミングで
            state = IN; // 単語が始まったのでIN
            ++nw; // 新しい単語をカウント
        }
    }

    printf("%d %d %d\n", nl, nw, nc); // 行数、単語数、文字数を表示
    return 0;
}
*/
    #include <stdio.h>

    #define IN 1
    #define OUT 0
    int main()
    {
        int c, nl, nw, nc, state;
        state = OUT;
        nl = nw = nc = 0;
        while (( c = getchar()) != EOF ) {
            ++nc;
            if ( c == '\n' )
                ++nl;
            if ( c == ' ' || c == '\n' || c == '\t')
                state = OUT;
            else if ( state == OUT ) {
                state = IN;
                ++nw;
            }   
        }
        printf("%d %d %d\n", nl, nw, nc);
        return 0;
    }
/*難しく考えすぎかも*/

