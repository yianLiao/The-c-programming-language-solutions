//
//  word_len_hist.c
//  cprogramming
//
//  Created by josephliao on 2021/1/30.
//

#include <stdio.h>
#include <stdlib.h>
#define  IN 1 //inside a word
#define OUT 0 //outside a word
#define MAX_LEN 10 //word maximum length is 30
int word_len_hist_hor(void){
    int wordlens[MAX_LEN + 1]; //lengths of words,the last element for length bigger than MAX_LEN
    int len = 0; //length of current word
    int state = OUT;
    int c;
    int i, j;
    
    for(int i = 0; i <= MAX_LEN; i++){
        wordlens[i] = 0;
    }
        
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t' || c == '\n'){
            if(state == IN){
                if(len <= MAX_LEN){
                    ++wordlens[len - 1];
                }else{
                    ++wordlens[MAX_LEN];
                }
                
            }
            state = OUT;
            len = 0;
        }else{
            state = IN;
            ++len;
        }
    }
    printf("\n horizonal histogram of the lengths of words\n");
    for(i = 0; i <= MAX_LEN; ++i){
        if(i != MAX_LEN){
            printf("%3d\t", i+1);
        }else{
            printf(">%2d\t", MAX_LEN);
        }
        
        for(j = 0; j < wordlens[i]; j++ ){
            putchar('#');
        }
        putchar('\n');
    }
    return EXIT_SUCCESS;
}
