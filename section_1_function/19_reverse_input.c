//
//  reverse_input.c
//  cprogramming
//
//  Created by josephliao on 2021/2/1.
//

#include <stdio.h>
#include "section_1.h"
#define MAX_LEN 1000 //maximum length of a line
void reverse(char s[]);

void reverse_iput(void){
    int len;
    char line[MAX_LEN];
    while((len = get_line(line, MAX_LEN)) > 0){
        reverse(line);
        printf("%s", line);
    }
}

void reverse(char s[]){
    int i = 0;//index of end
    int j = 0;//working index
    char c;
    while(s[i] != '\0')
        ++i;
    if(i > 0 && s[i-1] == '\n')
        --i;//skip '\n' at the end
    
    for(j = i-1; (i-1)-j < j && j >= 0; --j){
        //swap s[j] and s[i-1-j]
        c = s[j];
        s[j] = s[i-1-j];
        s[i-1-j] = c;
    }
}
