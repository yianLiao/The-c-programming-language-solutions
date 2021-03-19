//
//  len_and_print.c
//  cprogramming
//
//  Created by josephliao on 2021/1/31.
//

#include <stdio.h>
#include "section_1.h"
#define MAX_LEN 5 /* maximum input line size*/
#define IN 1 /* current Line read not yet finished, still inside the Line */
#define OUT 0 /* current Line read finished */

void copy(char to[], char from[]);
void arbit_longest_print(void){
    int tempLen = 0; /* length of current read */
    int curLen = 0; /* length of current Line */
    int maxLen = 0; /* max length of lines seen so far */
    int state = OUT;
    
    char curLine[MAX_LEN]; /* current line */
    char maxLine[MAX_LEN]; /* longest line sofar */
    char tempLine[MAX_LEN]; /* current read in */
    
    while((tempLen = get_line(tempLine, MAX_LEN)) > 0){
        curLen += tempLen;
        if(state == OUT)
            copy(curLine, tempLine);
        if(tempLen == MAX_LEN - 1 && tempLine[tempLen - 1] != '\n'){
            state = IN;
        }else{
            if(curLen > maxLen){
                maxLen = curLen;
                copy(maxLine, curLine);
            }
            curLen = 0;
            state = OUT;
        }
    }
    if(maxLen > 0){
        printf("longest length : %d\n", maxLen);
        printf("longest sentence: %s", maxLine);
        if(maxLine[maxLen -1] != '\n')
            putchar('\n');
    }
}

int get_line(char s[], int lim){
    /* get a line into s, return the actual length of this line */
    int c;
    int i;
    for(i = 0; i <= lim - 2 && (c = getchar()) != EOF && c != '\n'; ++i){
        //mind the order, check overflow first!
        s[i] = c;
    }
    if( c == '\n'){
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[]){
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
