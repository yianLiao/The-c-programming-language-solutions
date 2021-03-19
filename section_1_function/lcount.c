//
//  cprogramming
//
//  Created by josephliao on 2021/1/24.
//
#include <stdio.h>
#include <stdlib.h>

void lcount(void){
    int c, lc;
    lc = 0;
    while((c = getchar()) != EOF)
          if(c == '\n')
              ++lc;
    printf("lines total count to : %d\n", lc);
}
