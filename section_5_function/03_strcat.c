//
//  03_strcat.c
//  cprogramming
//
//  Created by josephliao on 2021/3/24.
//

#include <stdio.h>
#define SIZE 100
void istrcat(char *s, const char *t);

void istrcat_call(void){
    char s[SIZE] = "hello\0others";
    char t[SIZE] = "@world@\0others";
    istrcat(s, t);
    printf("after cat: %s\n", s);
}

void istrcat(char *s, const char *t){
    if(s == NULL || t == NULL) return;
    while(*s++)
        ;
    s--;
    while (*s++ = *t++)
        ;
    return;
}
