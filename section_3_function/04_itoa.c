//
//  04_itoa.c
//  cprogramming
//
//  Created by josephliao on 2021/3/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXLEN 1000

void reverse(char s[]);
void itoa(int n, char s[]);
void new_itoa(int n, char s[]);
void itoa_call(void){
    int n;
    //int k =  -INT_MIN;
    char s[MAXLEN];
    //printf("input an int n:\n");
    //scanf("%d", &n);
    //itoa(n, s);
    //printf("n convert to string is %s\n",s);
    new_itoa(INT_MIN, s);
    printf("MIN int convert to string is %s\n",s);
    //printf("- min int is %d\n",k);
}

/*itoa: convert n to characters in s*/
void itoa(int n, char s[]){
    int sign;
    int re;
    int ld;//last digit of n
    int i;
    i = 0;
    if((sign = n) < 0){
        n += 1; //substrac negtive n by 1 so that when changed to positive still fits in int
        n *= -1;//change to positive
        ld = (n % 10 + 1) % 10;
        s[i++] = ld + '0';
        if(!ld){//original last digit is 0, need to recover n because of borrowing
            n += 1;
        }
        n /= 10;
    }
    do{
        re = n % 10;
        s[i++] = re + '0';
        n /= 10;
    }while(n > 0);
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


/*another solution*/
void new_itoa(int n, char s[])
{
    int i, sign;

    sign = n;
    i = 0;
    do {        /* generate digits in reverse order */
        s[i++] = abs(n % 10) + '0';     /* get next digit */
    } while (n /= 10);                  /* delete it */
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

