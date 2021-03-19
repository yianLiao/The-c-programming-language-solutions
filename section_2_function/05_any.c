//
//  04_squeeze.c
//  cprogramming
//
//  Created by josephliao on 2021/3/5.
//

#include <stdio.h>
#define MAXLEN 50
int any(char s1[], char s2[]);
void any_call(void){
    char s1[MAXLEN];
    char s2[MAXLEN];
    printf("input s1:\n");
    scanf("%s", s1);
    printf("input s2:\n");
    scanf("%s", s2);
    printf("the return value is :%d\n", any(s1, s2));
}

int any(char s1[], char s2[]){
    int i,k;
    for(i=0; s1[i] != '\0'; i++){
        for(k=0; s2[k] != '\0'; k++){
            if(s1[i] == s2[k])
                return i;
        }
    }
    return -1;
}
