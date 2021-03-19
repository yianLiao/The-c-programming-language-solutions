//
//  03_expand.c
//  cprogramming
//
//  Created by josephliao on 2021/3/6.
//

#include <stdio.h>
#define MAXLEN 1000

int validrange(char c1, char c2);
char* expand(const char s1[], char s2[]);
void same_case(char c1, char c2, int* a, int* b);

void expand_call(void){
    char s2[MAXLEN];
    const char *s1;
    s1 = "-a-z 0-9 a-D-f -0-2 some text 1-1 WITH CAPITALS! 0-0 5-3 -";
    printf("original s1 is:\n %s\n", s1);
    printf("s1 after expanded is:\n %s\n", expand(s1, s2));
}

char* expand(const char s1[], char s2[]){
    int i,j;
    int k;
    int head,tail;
    for(i=0,j=0; s1[i] != '\0'; i++){
        if(s1[i] == '-' && i != 0 && s1[i+1] != '\0'){
            same_case(s1[i-1], s1[i+1], &head, &tail);
            if(validrange(head, tail)){
                //need expand from head to tail
                for(k = head+1; k <= tail; k++)
                    s2[j++] = k;
                i++;//skip tail
            }else{
                s2[j++] = s1[i];//non-valid range
            }
        }else{
            s2[j++] = s1[i];//no need expand
        }
    }
    s2[j] = '\0';
    return s2;
}

/*if c1 and c2 are all letters, change them into case of c2, then return in a and b*/
void same_case(char c1, char c2, int* a, int* b){
    if(c1 >= 'a' && c1 <= 'z'){
        if(c2 >= 'A' && c2 <= 'Z'){
            *a = c1-'a'+'A';
            *b = c2;
            return;
        }
    }
    if(c1 >= 'A' && c1 <= 'Z'){
        if(c2 >= 'a' && c2 <= 'z'){
            *a = c1-'A'+'a';
            *b = c2;
            return;
        }
    }
    *a = c1;
    *b = c2;
    return;
}

/* validrange:  returns non-zero if c1-c2 is a valid range. ensure all letters inputed are same case*/
int validrange(char c1, char c2)
{
    if((c1 >= 'a' && c1 <= 'z') && (c2 >= 'a' && c2 <= 'z') && c1 <= c2)
        return 1;
    if((c1 >= 'A' && c1 <= 'Z') && (c2 >= 'A' && c2 <= 'Z') && c1 <= c2)
        return 1;
    if((c1 >= '0' && c1 <= '9') && (c2 >= '0' && c2 <= '9') && c1 <= c2)
        return 1;
    return 0;
}
