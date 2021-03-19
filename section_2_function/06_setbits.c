//
//  06_setbits.c
//  cprogramming
//
//  Created by josephliao on 2021/3/5.
//

#include <stdio.h>
#include "section_2.h"
#define MAXLEN 100
unsigned setbits(unsigned x, int p, int n, unsigned y);

void setbits_call(void){
    unsigned x;
    int p,n;
    unsigned y;
    unsigned result;
    printf("input 01 sequence as binary form of x: \n");
    x = bitsToUsgn();
    printf("input position p:\n");
    scanf("%d", &p);
    getchar();//drop newline char
    printf("input 01 sequence as binary form of y: \n");
    y = bitsToUsgn();
    printf("input n:\n");
    scanf("%d", &n);
    result = setbits(x, p, n, y);
    unsgnToBits(result);
}



unsigned setbits(unsigned x, int p, int n, unsigned y){
    unsigned midMask;
    unsigned rgtMask;
    rgtMask = ~(~0 << n);
    midMask = rgtMask << (p+1-n);
    return (x | midMask) & (((y & rgtMask) << (p+1-n)) | ~midMask);
}

unsigned bitsToUsgn(void){
    unsigned c;
    unsigned i = 0;
    
    while((c = getchar()) == '1' || c == '0'){
        i = i * 2 + c - '0';
    }
    return i;
}

void unsgnToBits(unsigned n){
    int i;
    int a[MAXLEN];
    if(n == 0){
        printf("\nBinary of Given Number is=0\n");
        return;
    }

    for(i=0;n>0;i++)
    {
        a[i]=n%2;
        n=n/2;
    }
    printf("Binary of Given Number is=");
    for(i=i-1;i>=0;i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}
