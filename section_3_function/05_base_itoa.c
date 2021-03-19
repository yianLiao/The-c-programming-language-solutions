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
void base_itoa(int n, char s[], int b);
void base_itoa_call(void){
    int n;
    int b;
    char s[MAXLEN];
    printf("input an int n and the base b, seperate by space: \n");
    scanf("%d %d", &n, &b);
    base_itoa(n, s, b);
    printf("n convert to %d-base string is %s\n",b, s);
//    base_itoa(INT_MIN, s, 2);
//    printf("MIN int convert to string is %s\n",s);
}
/*another solution*/
void base_itoa(int n, char s[], int b)
{
    int i, sign;
    char symbols[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (2 > b || b > strlen(symbols) )
            return;     /* not a valid base */
    sign = n;
    i = 0;
    do {        /* generate digits in reverse order */
        s[i++] = symbols[abs(n % b)];     /* get next digit */
    } while (n /= b);                  /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

