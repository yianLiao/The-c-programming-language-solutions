//
//  04_itoa.c
//  cprogramming
//
//  Created by josephliao on 2021/3/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAXLEN 1000

void reverse(char s[]);
void pad_itoa(int n, char s[], int len);
void pad_itoa_call(void){
    int n;
    int w;
    char s[MAXLEN];
    printf("input an int n and the min field width, seperate by space: \n");
    scanf("%d %d", &n, &w);
    pad_itoa(n, s, w);
    printf("n convert to padding string is%s\n",s);
//    base_itoa(INT_MIN, s, 2);
//    printf("MIN int convert to string is %s\n",s);
}
/*another solution*/
void pad_itoa(int n, char s[], int width)
{
    int i, sign;
    sign = n;
    i = 0;
    do {        /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';     /* get next digit */
    } while (n /= 10);                  /* delete it */
    if (sign < 0)
        s[i++] = '-';
    while(i < width){
        s[i++] = '*';//use * instead of space to visualize
    }
    s[i] = '\0';
    reverse(s);
}

