//
//  display_rt.c
//  cprogramming
//
//  Created by josephliao on 2021/1/24.
//
#include <stdio.h>
#include <stdlib.h>

void ccount(void){
    double nc;
    for(nc = 0; (getchar() != EOF); ++nc)
        ;
    printf("characters total count to : %.0f\n", nc);
}
