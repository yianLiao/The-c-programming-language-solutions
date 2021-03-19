//
//  18_remove_space.c
//  cprogramming
//
//  Created by josephliao on 2021/2/1.
// remove trailing blanks and tabs from each line of input, and to delete entirely blank lines
//

#include <stdio.h>
#define MAX_GAP 10 /* maximum number of successive blanks and tabs*/
#define IN 1 /* inside  successive blanks and tabs */
#define OUT 0 /* outside successive blanks and tabs */
void remove_space(void){
    int c;
    char gap[MAX_GAP + 1]; // save  successive blanks and tabs
    int i = 0; //next index for gap to put blank or tab
    int state = OUT;
    
    while((c = getchar()) != EOF){
        if(c != ' ' && c != '\t' && c != '\n'){
            if(state == IN){
                gap[i] = '\0';
                printf("%s", gap);
                i = 0;
            }
            putchar(c);
            state = OUT;
        }else{
            if( c == '\n'){
                i = 0;
                putchar(c);
            }else{
                gap[i++] = ' ';
                state = IN;
            }
        }
    }
}

