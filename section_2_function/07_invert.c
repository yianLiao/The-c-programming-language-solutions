//
//  07_invert.c
//  cprogramming
//
//  Created by josephliao on 2021/3/5.
//

#include <stdio.h>
#include "section_2.h"
unsigned invertTail(unsigned x, int n);
unsigned invert(unsigned x, int p, int n);
unsigned invert_simple(unsigned x, int p , int n);
void invert_call(void){
    unsigned x;
    int p,n;
    unsigned result;
    printf("input 01 sequence as binary form of x: \n");
    x = bitsToUsgn();
    printf("input position p:\n");
    scanf("%d", &p);
    getchar();//drop newline char
    printf("input n:\n");
    scanf("%d", &n);
    //result = invert(x, p, n);
    result = invert_simple(x, p, n);
    unsgnToBits(x);
    unsgnToBits(result);

}

unsigned invert(unsigned x, int p, int n){
    return invertTail(invertTail(x, p+1), p+1-n);
}

unsigned invertTail(unsigned x, int n){
    unsigned tailMask;
    tailMask = ~(~0 << n);
    return (~(x & tailMask)) & (x | tailMask);
}

/*another simple solution*/
unsigned invert_simple(unsigned x, int p , int n){
    unsigned mask;
    mask =(~(~0 << n)) << (p+1-n);
    //a^1 is invert a, a^0 is a
    return x ^ mask;
}
