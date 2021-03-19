//
//  01_strrindex.c
//  cprogramming
//
//  Created by josephliao on 2021/3/8.
//

#include <stdio.h>
#include <string.h>
#define MAXLEN 1000
int strrindex(const char s[], const char t[]);

void strrindex_call(void){
    char *s, *t;
    int position;
    s = "abc4efa4ceg4baa4abiab";
    t = "ab";
    position = strrindex(s, t);
    printf("index is: %d\n", position);
    
}

int strrindex(const char s[], const char t[]){
    int i,j;
    int match;
    int slen = strlen(s);
    int tlen = strlen(t);
    if(!slen || !tlen)
        return -1;
    /*check s from backward to find the first match*/
    for(i=slen-1, match=0; i>=tlen-1 && !match; --i){
        /*check if substring in s ended with position i matches string t*/
        for(j=0; j<=tlen-1 && t[tlen-1-j] == s[i-j]; ++j){
            ;
        }
        if(j > tlen-1){
            match = 1;
        }
    }
    if(match){
        ++i;//resume i
        return i + 1 - tlen;//from this position to i is of length tlen;
    }else{
        return -1;
    }
}
