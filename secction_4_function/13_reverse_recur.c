//
//  reverse_recur.c
//  cprogramming
//
//  Created by josephliao on 2021/3/20.
//

#include <stdio.h>
#include <string.h>
#define MAX_LEN 1000 //maximum length of a line
void reverse_recur(char s[], int start, int end);

void reverse_recur_call(void){
    char line[MAX_LEN];
    strcpy(line, "12345 67890!");
    reverse_recur(line, 0, strlen(line) - 1);
    printf("%s\n", line);
}

void reverse_recur(char s[], int start, int end){
    int tmp;
    if(start >= end) return;
    
    tmp = s[start];
    s[start] = s[end];
    s[end] = tmp;
    
    reverse_recur(s, start+1, end-1);
}
