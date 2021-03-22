//
//  20_replace_tab.c
//  cprogramming
//
//  Created by josephliao on 2021/2/1.
//

#include <stdio.h>
#include "section_1.h"
int TABWIDTH = 4; //spaces number of a tab.Only defined here as external var, and declared in section_1.h, then used elsewhere.
void replace_tab(void){
    int c;
    int i;
    int count = 0;//next position to put char
    while( (c = getchar()) != EOF){
        if(c == '\t'){
            for(i = 1; i <= TABWIDTH - count; ++i)
                putchar(' ');
            count = 0;
        }else{
            putchar(c);
            if(c == '\n'){
                count = 0;
            }else{
                count = (count + 1) % TABWIDTH;
            }
        }
    }
}
