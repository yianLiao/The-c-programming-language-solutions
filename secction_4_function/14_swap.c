//
//  14_swap.c
//  cprogramming
//
//  Created by josephliao on 2021/3/20.
//

#include <stdio.h>
#define swap(t,x,y) {   t temp;\
                        temp=(x);\
                        (x)=(y);\
                        (y)=temp;\
                    }
void swap_call(void){
    int a = 1;
    int b = 2;
    swap(int, a, b);
    printf("swap to %d,%d\n", a, b);
}
