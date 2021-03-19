//
//  23_rmcomments.c
//  cprogramming
//
//  Created by josephliao on 2021/2/4.
//

#include <stdio.h>
#include <stdlib.h>
#define CODE 0
#define ESCAPE 1
#define QUOTE 2
#define SLASH 3
#define LCOMMENT 4 //single line comments
#define MCOMMENT 5 //comments with stars
#define MCOMMENT_RSTAR 6

int rmcomments(void){
    int c;
    int state = CODE;
    while((c = getchar()) != EOF){
        if(state == CODE){
            if( c == '\\'){
                state = ESCAPE;
                putchar(c);
            }else if(c == '\'' || c == '"'){
                state = QUOTE;
                putchar(c);
            }else if (c == '/'){
                state = SLASH;
            }else{
                putchar(c);
            }
        }else if(state == ESCAPE){
            putchar(c);
        }else if(state == QUOTE){
            if(c != '\'' && c != '\"'){
                putchar(c);
            }else{
                //quotes do not nest, or else wrong handle
                putchar(c);
                state = CODE;
            }
        }else if(state == SLASH){
            if(c == '/'){
                state = LCOMMENT;
            }else if(c == '*'){
                state = MCOMMENT;
            }else{
                state = CODE;
                putchar('/');
            }
        }else if(state == LCOMMENT){
            if(c == '\n')
                state = CODE;
        }else if(state == MCOMMENT){
            if(c == '*')
                state = MCOMMENT_RSTAR;
        }else if(state == MCOMMENT_RSTAR){
            if(c == '/')
                state = CODE;
            else
                state = MCOMMENT;
        }else{
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}
