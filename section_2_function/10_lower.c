//
//  09_bitcount.c
//  cprogramming
//
//  Created by josephliao on 2021/3/5.
//

#include <stdio.h>
#include "section_2.h"

int lower(int c);

void lower_call(void){
    int c;
    printf("input character: \n");
    c = getchar();
    printf("lower case is %c\n", lower(c));
    return;
}

int lower(int c){
    return ('A' <= c && c <= 'Z') ? (c - 'A' + 'a') : c;
}
