    #include <stdio.h>
    int main () 
    {
            int c,i,nwhite,nother; //宣言　全部int
            int ndigit[10];        //int ndigit[10]配列型宣言 
            nwhite = nother = 0;   //初期化
            for(i = 0; i < 10; ++i)//配列を回す iを0で初期化;iが10になるまで;iをカウントアップ
                ndigit[i] = 0;     //ndigit[i]に0を代入して初期化
            
            while((c = getchar()) != EOF)       //cがEOFでない限り真　EOFになるまで繰り返す下記の内容を繰り返す
                if ( c >= '0' && c  <= '9' )   //もし、cが0以上ANDcが9以下であれば
                    ++ndigit[c - '0'];          //ndigitに1増加[c　- '0'] (入力されたcから0を引く)
                else if ( c == ' ' || c == '\n' || c == '\t')       //ifが偽だったんだ…じゃあもし、cが' 'OR '\n' OR '\t'のどれかだったら
                    ++nwhite;                                       //nwhiteを1増加
                else            //上の2つ全部偽だったんだ…その場合は
                    ++nother;    //notherを1増加
            
            printf ("digits =");            //printf関数呼び出して"digits ="を引数に出力
            for (i = 0; i < 10; ++i)        //iを0で初期化;iが10になるまで;iを1増加させる
                printf(" %d",ndigit[i]);    //printf関数呼び出し,ndigit[i]のiを引数に出力
            printf (", white space = %d, other = %d\n",     //printf関数呼び出し,
                    nwhite,nother);                         //nwhite,notherを引数で渡して出力

    return 0;        
    }

/*
adam 24 gef sd fda 
^Z
digits = 0 0 1 0 1 0 0 0 0 0, white space = 6, other = 12

2 4 6 8 a d c d e       f       g
^Z
digits = 0 0 1 0 1 0 1 0 1 0, white space = 11, other = 7

数字の０から９までの数字が何回出現しているかカウントをおこなう。
数字以外の文字、空白、改行、タブなら、nwhiteをカウントアップ。
数字以外の文字、空白、改行、タブ以外なら、notherをカウントアップ
そういうプログラム。*/