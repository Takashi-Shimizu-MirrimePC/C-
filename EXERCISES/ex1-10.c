//演習１－１０　各タブを\tに。各バックスペースを\bに。各バックスラッシュを\\に置き換えながら
//入力を出力に複写するプログラムをかけ
//こうすればタブとバックスペースははっきり見えるようになる・・・
/*
#include <stdio.h>

int main ()
{
    int c;
    while((c = getchar()) != EOF)
        if( c == '\t')
            putchar("\t");
        if( c == '\b')
            putchar("\b");
        if( c == '\\')
            putchar("\\");
        
    
    putchar(c);
    return 0;
        
}
#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
    }
    return 0;
}
#include <stdio.h>

int main() {
    int c;
    
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            putchar(' \t ');
        } else if (c == '\b') {
            putchar(' \b ');
        } else if (c == '\\') {
            putchar(' \\ ');
        } else {
            putchar(c);
        }
    }
    
    return 0;
}

#include <stdio.h>
int main ()
{
    int c;
    int last_char = 0;
    while((c = getchar()) != EOF)
        if(c == '\t' || last_char == '\t'){
            putchar('\t');
        } else if (c == '\b' || last_char == '\b'){
            putchar('\b');
        } else if (c == '\\' || last_char == '\\'){
            putchar('\\');
        } else {
            putchar(c);
        }
        
        return 0;
}
#include <stdio.h>

int main() {
    int c;
    int last_char = 0; // 前の文字を追跡する変数

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
        last_char = c; // 現在の文字を前の文字として保存
    }

    return 0;
}#include <stdio.h>

int main() {
    int c;
    int last_char = 0; // 前の文字を追跡する変数

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            printf("\\t");
        } else if (c == '\b') {
            printf("\\b");
        } else if (c == '\\') {
            printf("\\\\");
        } else {
            putchar(c);
        }
        last_char = c; // 現在の文字を前の文字として保存
    }

    return 0;
}
#include <stdio.h>
int main ()
{
    int c;
    int last_char = 0;
    while((c = getchar()) != EOF) {
        if( c == '\t'){ 
            printf("\t");
        }else if( c == '\b'){
            printf("\b");
            fflush(stdout);
        }else if( c == '\\'){
            printf("\\\\");
        }else{
            putchar(last_char);
            putchar(c);
        } 
    }
    return 0;
}

#include <stdio.h>
int main()
{
    int c;
    while((c = getchar()) != EOF){
        if(c == '\b')
            printf("\\b");
            
    }putchar(c);
    return 0;
}
#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF) {
        // タブ文字の場合
        if (c == '\t') {
            printf("\\t");
        }
        // バックスペースの場合
        else if (c == '\b') {
            printf("\\b");
        }
        // バックスラッシュの場合
        else if (c == '\\') {
            printf("\\\\");
        }
        // その他の文字はそのまま出力
        else {
            putchar(c);
        }
    }
    return 0;
}
#include <stdio.h>

int main() {
    char c;
    char prev_char = '\0';  // 直前の文字を保持する変数
    
    while ((c = getchar()) != EOF) {  // 標準入力から1文字ずつ読み取る
        if (c == '\t') {               // タブの場合
            printf("\\t");
        } else if (c == '\b') {        // バックスペースの場合
            if (prev_char != '\0') {   // 直前の文字があれば削除
                printf("\b \b");       // バックスペースで削除する
            }
        } else if (c == '\\') {        // バックスラッシュの場合
            printf("\\\\");
        } else {
            putchar(c);                // その他の文字はそのまま出力
            prev_char = c;             // 出力した文字を保持
        }
    }

    return 0;
}
#include <stdio.h>

int main() {
    char c;
    int last_char_printed = 0;  // 最後に出力された文字数のカウント（バックスペース後の削除を管理）

    while ((c = getchar()) != EOF) {  // 標準入力から1文字ずつ読み取る
        if (c == '\t') {               // タブの場合
            printf("\\t");
            last_char_printed += 4;    // タブは長さ4とみなす
        } else if (c == '\b') {        // バックスペースの場合
            if (last_char_printed > 0) {  // 何か文字が出力されていれば
                printf("\\b");            // バックスペースを出力
                last_char_printed--;      // 出力済み文字数を1減らす
            }
        } else if (c == '\\') {        // バックスラッシュの場合
            printf("\\\\");
            last_char_printed += 2;     // バックスラッシュは長さ2
        } else {
            putchar(c);                // その他の文字はそのまま出力
            last_char_printed++;        // 出力された文字数をカウント
        }
    }

    return 0;
}

#include <stdio.h>

int main() {
    char c;
    int buffer_size = 100;  // 最大の入力サイズ（ここでは100文字）
    char buffer[buffer_size];  // 入力された文字列を保持するバッファ
    int index = 0;  // バッファ内で現在の位置を追跡する

    while ((c = getchar()) != EOF) {  // 標準入力から1文字ずつ読み取る
        if (c == '\t') {               // タブの場合
            printf("\\t");
            buffer[index++] = '\t';    // バッファにもタブを追加
        } else if (c == '\b') {        // バックスペースの場合
            if (index > 0) {           // バッファに文字があれば
                index--;               // 1つ前の文字を削除
                printf("\\b");         // バックスペースを出力
            }
        } else if (c == '\\') {        // バックスラッシュの場合
            printf("\\\\");
            buffer[index++] = '\\';    // バッファにもバックスラッシュを追加
        } else {
            putchar(c);                // その他の文字はそのまま出力
            buffer[index++] = c;       // バッファに文字を追加
        }
    }

    return 0;
}
#include <stdio.h>

int main() {
    char c;
    char buffer[100];  // 最大100文字のバッファ
    int index = 0;  // バッファ内の現在の位置を追跡

    while ((c = getchar()) != EOF) {  // 標準入力から1文字ずつ読み取る
        if (c == '\t') {               // タブの場合
            printf("\\t");
        } else if (c == '\b') {        // バックスペースの場合
            if (index > 0) {           // 文字がある場合のみ
                index--;               // バッファから1文字削除
                printf("\\b");         // バックスペースを出力
            }
        } else if (c == '\\') {        // バックスラッシュの場合
            printf("\\\\");
        } else {
            putchar(c);                // その他の文字はそのまま出力
            buffer[index++] = c;       // バッファに文字を追加
        }
    }

    return 0;
}

#include <stdio.h>

int main() {
    char c;
    char buffer[100];  // 入力された文字列を保持するバッファ
    int index = 0;  // バッファ内で現在の位置を追跡
    int delete_count = 0;  // バックスペースで削除された文字数をカウント

    while ((c = getchar()) != EOF) {  // 標準入力から1文字ずつ読み取る
        if (c == '\t') {               // タブの場合
            printf("\\t");
        } else if (c == '\b') {        // バックスペースの場合
            if (index > 0) {           // バッファに文字があれば
                index--;               // バッファから1文字削除
                delete_count++;        // 削除された文字数を増やす
                printf("\\b");         // バックスペースを出力
            }
        } else if (c == '\\') {        // バックスラッシュの場合
            printf("\\\\");
        } else {
            putchar(c);                // その他の文字はそのまま出力
            buffer[index++] = c;       // バッファに文字を追加
        }
    }

    // 最後に削除された文字数だけ \b を出力
    for (int i = 0; i < delete_count; i++) {
        printf("\\b");
    }

    return 0;
}*/
#include <stdio.h>

int main() {
    char c;
    char buffer[100];  // 入力された文字列を保持するバッファ
    int index = 0;  // バッファ内で現在の位置を追跡

    while ((c = getchar()) != EOF) {  // 標準入力から1文字ずつ読み取る
        if (c == '\t') {               // タブの場合
            printf("\\t");
        } else if (c == '\b') {        // バックスペースの場合
            if (index > 0) {           // バッファに文字があれば
                index--;               // バッファから1文字削除
                printf("\\b");         // バックスペースを出力
            }
        } else if (c == '\\') {        // バックスラッシュの場合
            printf("\\\\");
        } else {
            putchar(c);                // その他の文字はそのまま出力
            buffer[index++] = c;       // バッファに文字を追加
        }
    }

    return 0;
}
