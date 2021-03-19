//
//  wordcount.c
//  cprogramming
//
//  Created by josephliao on 2021/1/30.
//

#include <stdio.h>
//#include <stdlib.h>

#define OUT 0    //currently outside a word
#define IN  1    //currently inside word

void wordcount(void){

    int state = OUT;
    int c, nw, nl;
    double nc;
    nw = nl = nc = 0;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            ++nc;
            if(c == '\n'){
                ++nl;
            }
            if(state == IN){
                ++nw;
            }
            state = OUT;
        }
        else{
            ++nc;
            state = IN;
        }
    }
    
    printf("characters count: %.0f, words count: %d, lines count: %d \n", nc, nw, nl);
}
