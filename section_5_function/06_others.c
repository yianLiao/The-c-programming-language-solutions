//
//  06_others.c
//  cprogramming
//
//  Created by josephliao on 2021/3/24.
//

#include <stdio.h>
#include <string.h>


void reverse2(unsigned char *str){
    int i;
    int j;
    unsigned char a;
    unsigned len = strlen((const char *)str);
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        a = *(str+i);
        *(str+i)= *(str+j);
        *(str+j) = a;
    }
}
