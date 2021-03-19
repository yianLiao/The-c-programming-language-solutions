//
//  getch.c
//  cprogramming
//
//  Created by josephliao on 2021/3/18.
//

#include <stdio.h>
#include <string.h>
#define BUFSIZE 100
int buf[BUFSIZE];
int bufp = 0; //next free position in buf

int igetch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void iungetch(int c){
    if(bufp >= BUFSIZE)
        printf("iungetch: too many characters!\n");
    else
        buf[bufp++] = c;
}

void iungets(char s[]){
    int len = strlen(s);
    while(len > 0)
        iungetch(s[--len]);
}

void ungets(char s[]){
    int len = strlen(s);
    while(len > 0)
        ungetc(s[--len], stdin);
}
