//演習1－3　表の上に見出しを印字するように温度換算プログラムを変更せよ
#include <stdio.h>
int main()
{
    printf("***温度変換プログラム***\n");
    float fahr,celsius;
    //int fahr,celsius;
    int lower,upper,step;
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr<=upper){
        celsius = (5.0/9.0)*(fahr-32.0);
        printf("%3.0f %6.1f\n", fahr ,celsius);
        /*celsius = 5 * (fahr-32) / 9;
        printf("%d\t%d\n",fahr,celsius);*/
        fahr = fahr + step ;
    }
}
/* printf("%d\t%d\n",fahr,celsius);
***温度変換プログラム***
0       -17
20      -6
40      4
60      15
80      26
100     37
120     48
140     60
160     71
180     82
200     93
220     104
240     115
260     126
280     137
300     148
*/

/* printf("%3d%6d\n",fahr,celsius);
***温度変換プログラム***
  0   -17
 20    -6
 40     4
 60    15
 80    26
100    37
120    48
140    60
160    71
180    82
200    93
220   104
240   115
260   126
280   137
300   148

*/

/*float fahr,celsius; celsius = (5.0/9.0)*(fahr-32.0); printf("%3.0f %6.1f\n", fahr ,celsius);
***温度変換プログラム***
  0  -17.8
 20   -6.7
 40    4.4
 60   15.6
 80   26.7
100   37.8
120   48.9
140   60.0
160   71.1
180   82.2
200   93.3
220  104.4
240  115.6
260  126.7
280  137.8
300  148.9

*/
