/*演習１－１３　入力した単語の長さをヒストグラム(度数分布図)にしてプリントするプログラムをかけ。
ヒストグラムは横に書くほうが簡単だが縦書きに挑戦してみるのもよい。・・・

単語の入力
ヒストグラムの出力
単語の入力：int c;
int　last_c = ' ';
int c を　getcharで一文字ずつ受け取る
int c が　単語である事を判断する
int c が単語でなければなんの処理もおこなわない
単語であれば単語番号と、単語の文字数を取得し配列に代入する

要素数をヒストグラムとして出力する：ヒストグラムの表現は■を用いる
入力された単語の配列にアクセスし単語の文字数を取得する
取得した文字数を■で表現する。
表示のために取得した配列の単語番号に０から入力された数まで整数値を割り振り、
割り振った数値の上に取得した単語の文字数の文だけ縦方向に■を出力する



#include <stdio.h>
int main () {

    int c,c_count;
    int last_c = ' ';
    c_count = 0;
    //単語の取得
    while (( c = getchar()) != EOF){//cがEOF(^Z)になるまで下記の{}内をループ
        if ( c != ' ' && c != '\n' && c != '\t'){
                putchar(c);
                printf("\n");
                ++c_count;   
                printf("%d",c_count);            
        }else if ( last_c == '\n' || last_c == '\t' || last_c == ' '){
                
                printf("\n");
                
        }else{
            ;
        
    }
   
   
}
 return 0;
}

// 分からんくてChatGPTに聞いた。

#include <stdio.h>

#define MAX_WORD_LENGTH 50  // 単語の最大長を定義（必要に応じて調整）

int main() {
    int c;
    int word_lengths[MAX_WORD_LENGTH] = {0};  // 単語の長さを記録する配列
    int current_length = 0;  // 現在の単語の長さ
    int word_count = 0;  // 単語の数

    // 単語の取得
    while ((c = getchar()) != EOF) {
        // 単語の途中である文字か判定
        if (c != ' ' && c != '\n' && c != '\t') {
            // 単語が続いているので長さを増やす
            current_length++;
        } else if (current_length > 0) {
            // 空白、改行、タブで単語が終了したとき
            word_lengths[current_length]++;
            word_count++;  // 単語のカウントを増やす
            current_length = 0;  // 単語の長さをリセット
        }
    }

    // 最後の単語が EOF で終了した場合の処理
    if (current_length > 0) {
        word_lengths[current_length]++;
        word_count++;
    }

    // ヒストグラムを縦方向に表示
    printf("\nヒストグラム（単語の長さ）:\n");
    for (int i = MAX_WORD_LENGTH - 1; i > 0; i--) {  // 長さが長い順に表示
        if (word_lengths[i] > 0) {
            printf("%2d: ", i);
            for (int j = 0; j < word_lengths[i]; j++) {
                printf("■");
            }
            printf("\n");
        }
    }

    // 単語の長さが1からMAX_WORD_LENGTHまでの範囲に収まるようにして出力
    return 0;
}
/*
thia is my dream
^Z

ヒストグラム（単語の長さ）:
 5: ■
 4: ■
 2: ■■


 ///////
K&R 解答集　WEBサイト　引用
https://tomcha.hatenablog.jp/entry/2015/02/23/195219
 ///////
1－13－1
#include <stdio.h>

#define IN  0
#define OUT 1
int main(){
  int wordsize[10];
  int c;
  int i,j,k,l;
  int wordstatus;
  wordstatus = OUT;
  i = 0;
  for(j = 0; j < 10; j++){
    wordsize[j] = 0;
  }
  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\t' || c == '\n'){
      if(wordstatus == IN){
        if(i <= 9){
          wordsize[i] += 1;
        }else{
          wordsize[9] += 1;
        }
        wordstatus = OUT;
        i = 0;
      }
    }else{
      wordstatus = IN;
      i += 1;
    }
  }
  for(k = 0; k < 10; k++){
    l = 0;
    if(wordsize[k] != 0){
      printf("%2d:%d",k ,wordsize[k]);
      while( l < wordsize[k]){
        printf("*");
        l += 1;
      }
      printf("\n");
    }
  }
}

asd asd asd asd afaafa a as asda a a a a a a a asa aasda asda 
^Z
 1:8********
 2:1*
 3:5*****
 4:2**
 5:1*
 6:1*
*/
//1－13－2
#include <stdio.h>

#define IN  0
#define OUT 1
int main(){
  int wordsize[10];
  int c;
  int i,j,k,l,m;
  int wordstatus;
  wordstatus = OUT;
  i = 0;
  for(j = 0; j < 10; j++){
    wordsize[j] = 0;
  }

  while((c = getchar()) != EOF){
    if(c == ' ' || c == '\t' || c == '\n'){
      if(wordstatus == IN){
        if(i <= 9){
          wordsize[i] += 1;
        }else{
          wordsize[9] += 1;
        }
        wordstatus = OUT;
        i = 0;
      }
    }else{
      wordstatus = IN;
      i += 1;
    }
  }

  int output[50];
  for(k = 0; k < 50; k++){
    output[k] = 0;
  }

  for(l = 0; l < 10; l++){
    if(wordsize[l] >= 5){
      output[l] = 1;
    }
    if(wordsize[l] >= 4){
      output[10 + l] = 1;
    }
    if(wordsize[l] >= 3){
      output[20 + l] = 1;
    }
    if(wordsize[l] >= 2){
      output[30 + l] = 1;
    }
    if(wordsize[l] >= 1){
      output[40 + l] = 1;
    }
  }

  for(m = 0; m < 50; m++){
    if(output[m] == 1){
      printf("*");
    }else{
      printf(" ");
    }
    if((m % 10) == 9){
      printf("\n");
    }
  }
  printf("0123456789\n");
}
/*
this is my programming study log.
^Z



  * *
  * **   *
0123456789
//////////////////////////////////////////
my mother is very kind for me.
^Z



  ***
  *** *
0123456789
//////////////////////////////////////////
*/