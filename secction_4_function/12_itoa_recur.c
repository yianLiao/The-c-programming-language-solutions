//
//  12_itoa_recur.c
//  cprogramming
//
//  Created by josephliao on 2021/3/20.
//

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define MAXLEN 1000
int itoa_recur(int n, char s[]);
void itoa_recur_call(void){
    int n =  -INT_MIN;
    //n = -123;
    char s[MAXLEN] = {'@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@','@'};
    //printf("input an int n:\n");
    //scanf("%d", &n);
    //itoa(n, s);
    itoa_recur(n, s);
    printf("%d int convert to string is %s\n", n, s);
    //printf("- min int is %d\n",k);
}

/*convert integer to string, return ending index of the string*/
int itoa_recur(int n, char s[])
{
    int i = 0;
    int j;
    static int count = 0;
    int shrink;
    int lastd;
    shrink  = abs(n / 10);
    lastd = n % 10;
    if(n < 0){
        s[i++] = '-';
        j = 0;
        /*get last digit, take care of machine dependent % operate*/
        if(lastd > 0)
            lastd = 10 - lastd;
        else
            lastd = -lastd;
    }else{
        j = -1;
    }
    
    if(shrink){
        ++count;
        j = itoa_recur(shrink, s + i);
    }else{
        s[count+1] = '\0';
    }
    
    s[++j + i] = lastd + '0';
    return j;
}

