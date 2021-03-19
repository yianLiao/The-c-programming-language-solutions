//wordprint
//  cprogramming
//
//  Created by josephliao on 2021/1/30.
//

#include <stdio.h>
//#include <stdlib.h>

#define OUT 0    //currently outside a word
#define IN  1    //currently inside word

void wordprint(void){
    int state = OUT;
    int c;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            if(state == IN){
                putchar('\n');
            }
            state = OUT;
        }
        else{
            putchar(c);
            state = IN;
        }
    }
}
