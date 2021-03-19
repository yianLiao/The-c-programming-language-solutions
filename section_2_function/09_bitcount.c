//
//  09_bitcount.c
//  cprogramming
//
//  Created by josephliao on 2021/3/5.
//

#include <stdio.h>
#include "section_2.h"

int bitcount(unsigned x);

void bitcount_call(void){
    unsigned x;
    printf("input 01 sequence as binary form of x: \n");
    x = bitsToUsgn();
    printf("number of 1 in x is %d\n", bitcount(x));
    return;
}

int bitcount(unsigned x){
    unsigned y = x;
    int n = 0;
    while(y != 0){
        ++n;
        y &= (y-1);
    }
    return n;
}
