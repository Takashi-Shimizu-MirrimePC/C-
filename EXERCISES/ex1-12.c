/*演習１－１２　入力した単語を1行に1文字ずつ印字するプログラムをかけ
入力した単語を印字する

while((c = getchar()) != EOF){
if(cが改行なら)改行をカウントアップする
if(cが空白なら)空白をカウントアップする
if(cがタブなら)タブをカウントアップする
If(cが単語なら)単語を出力する

cが単語であることの条件
getchar()は一文字ずつ入力を受け取る
単語の条件、
文字と文字が繋がっていること
前後に文字以外がないこと

int c,last_c
If(c != c )
putcher(c);



#include <stdio.h>

int main ()
{
    int c;
    while((c = getchar()) != EOF)
    if(c != '\n' && '\t' && ' '){
       putchar(c);
       printf("\n");
    }
    
}
*/  
#include <stdio.h>

int main() {
    int c;
    int last_c = ' '; // 最後に入力された文字を記録。空白で初期化しておく。

    while ((c = getchar()) != EOF) {
        // 改行、空白、タブのいずれでもない場合、単語の一部として扱う
        if (c != '\n' && c != '\t' && c != ' ') {
            putchar(c); // 文字を印字
        } else if (last_c != ' ' && last_c != '\n' && last_c != '\t') {
            // 直前の文字が単語だった場合、改行する
            printf("\n");
        }
        
        last_c = c; // 現在の文字をlast_cに記録
    }

    return 0;
}
/*
Hello, World! c Langage is Difficurt
Hello,
World!
c
Langage
is
Difficurt

分からなかったところ
単語を定義するところ
単語を定義する条件は、cが連続していること　ｃの前後に　ｃ以外がないこと
その表現方法が分からんかった

ChatGPTに聞いてみた✋

演習1-12で求められているのは、入力した単語を1行に1文字ずつ印字するプログラムです。
あなたが書いたコードは、`getchar()` で1文字ずつ入力を受け取り、
その中で改行、空白、タブ以外の文字を印字するというものです。
ただし、いくつか改善すべき点がありますので、詳細に解説します。

### 修正点
1. **`if(c != '\n' && '\t' && ' ')` の条件式の誤り**
   - 現在の条件式では、`c` が改行でもタブでも空白でもないことを確認したい意図だと思いますが、
   この式は正しく動作しません。`'\n' && '\t' && ' '` は常に真（`true`）になり、
   意図した動作にはなりません。
   - 正しくは、`c != '\n' && c != '\t' && c != ' '` 
   という条件式で、`c` が改行、タブ、空白でないことをチェックします。

2. **単語の処理について**
   - 単語を「1行に1文字ずつ印字する」だけでなく、
   空白や改行がある場合に、単語の境界を考慮して処理する必要があります。
   単語が連続しているときはそのまま印字し、単語の終わり（空白、改行、タブ）で
   改行するという処理が求められます。

3. **改行の処理**
   - 改行をカウントしていない点について、`'\n'` の処理を追加して、
   改行が入力された場合に改行を印字するようにします。

### 改善したコード例

以下は、入力された単語を1行に1文字ずつ印字するプログラムの改善案です。
単語の区切り（空白、改行、タブ）で行を分けます。

```c
#include <stdio.h>

int main() {
    int c;
    int last_c = ' '; // 最後に入力された文字を記録。空白で初期化しておく。

    while ((c = getchar()) != EOF) {
        // 改行、空白、タブのいずれでもない場合、単語の一部として扱う
        if (c != '\n' && c != '\t' && c != ' ') {
            putchar(c); // 文字を印字
        } else if (last_c != ' ' && last_c != '\n' && last_c != '\t') {
            // 直前の文字が単語だった場合、改行する
            printf("\n");
        }
        
        last_c = c; // 現在の文字をlast_cに記録
    }

    return 0;
}
```

### 解説

1. **`last_c` の役割**
   - `last_c` は直前の文字を記録するための変数です。これを使って、
   空白や改行が入力されたときに、直前の文字が単語だった場合に改行を入れる処理をしています。
   これにより、単語が終わった後に改行を挿入できます。

2. **単語の判定**
   - 単語の一部として扱うのは、改行、空白、タブ以外の文字です。
   空白や改行などが来た場合、直前が単語だった場合に改行を入れる処理をしています。

3. **`putchar(c)` の使い方**
   - `putchar(c)` で入力された文字をそのまま出力します。これで1文字ずつ印字できます。

### 実行例

入力：
```
Hello world! This is a test.
```

出力：
```
Hello
world!
This
is
a
test.
```

このように、入力された単語ごとに1行ずつ印字されます。

### まとめ
この修正により、単語が終わるたびに改行され、1行に1文字ずつ印字されるプログラムになります。
バグを防ぐために、入力の前後で単語の境界をしっかりと確認することが重要です。

*/
