//
//  word_len_hist_ver.c
//  cprogramming
//
//  Created by josephliao on 2021/1/30.
//

#include <stdio.h>
#include <stdlib.h>
#define  IN 1 //inside a word
#define OUT 0 //outside a word
#define MAX_LEN 20 //word maximum length is 20
int word_len_hist_ver(void){
    int wordlens[MAX_LEN + 1]; //lengths of words,the last element for length bigger than MAX_LEN
    int len = 0; //length of current word
    int state = OUT;
    int c;
    int i, j;
    
    int maxcount = 0; //the max count of all lengths
    
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
    
    for(maxcount = 0, i=0; i<= MAX_LEN; ++i){
        if(wordlens[i] > maxcount)
            maxcount = wordlens[i];
    }
    
    printf("\n vertical histogram of the lengths of words\n");
    /*print the bar*/
    for(j = maxcount; j >= 1; --j){
        for(i = 0; i <= MAX_LEN; ++i){
            if(wordlens[i] >= j){
                printf("   #");
            }else{
                printf("    ");
            }
        }
        printf("\n");
    }
    
    /*print the last line with title*/
    for(i = 0; i < MAX_LEN; ++i){
        printf("%4d", i + 1);
    }
    printf(" >%d", MAX_LEN);
    printf("\n");
    
    return EXIT_SUCCESS;
}
