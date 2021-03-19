//
//  08_rightrot.c
//  cprogramming
//
//  Created by josephliao on 2021/3/5.
//

#include <stdio.h>
#include "section_2.h"
unsigned rightrot(unsigned x, int n);
unsigned rightrot_indep(unsigned ix, int n);
void rightrot_call(void){
    unsigned x;
    int n;
    unsigned result;
    printf("input 01 sequence as binary form of x: \n");
    x = bitsToUsgn();
    printf("input n:\n");
    scanf("%d", &n);
    result = rightrot(x, n);
    unsgnToBits(x);
    unsgnToBits(result);
    unsgnToBits(rightrot_indep(x, n));
}

/*this version is not word length independent, but faster O(1)*/
unsigned rightrot(unsigned x, int n){
    int len = sizeof(x) * 8;
    int nr = n % len;
    unsigned rmask;
    rmask  = ~(~0 << nr);
    return (x >> nr) ^ ((x & rmask) << (len - nr));
}

/*this version is independent of word length, of time O(n)*/
unsigned rightrot_indep(unsigned ix, int n){
    unsigned x = ix;
    while(n > 0){
        if(x & 1){
            x = (x >> 1) | (~(~0U >> 1));
        }else{
            x = x >> 1;
        }
        --n;
    }
    return x;
}
