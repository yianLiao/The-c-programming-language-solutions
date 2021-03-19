//
//  04_squeeze.c
//  cprogramming
//
//  Created by josephliao on 2021/3/5.
//

#include <stdio.h>
#define MAXLEN 50
void squeeze(char s1[], char s2[]);
void squeeze_call(void){
    char s1[MAXLEN];
    char s2[MAXLEN];
    printf("input s1:\n");
    scanf("%s", s1);
    printf("input s2:\n");
    scanf("%s", s2);
    squeeze(s1, s2);
    printf("the result s1 is:\n %s\n", s1);
}

void squeeze(char s1[], char s2[]){
    int i,j,k;
    int match;
    for(i=0,j=0; s1[i] != '\0'; i++){
        for(k=0,match=0; match == 0 && s2[k] != '\0'; k++){
            if(s1[i] == s2[k])
                match = 1;
        }
        if(match == 0)
            s1[j++] = s1[i];
    }
    s1[j] = '\0'; //caution!
}
