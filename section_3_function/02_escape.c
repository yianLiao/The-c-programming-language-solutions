//
//  02_escape.c
//  cprogramming
//
//  Created by josephliao on 2021/3/6.
//

#include <stdio.h>
#define TRUE 1 //don't aad ';' to the ending!!
#define FALSE 0
#define MAXLEN 100

char* escape(char s[], const char t[]);
char* unescape(char s[], const char t[]);

void escape_call(void){
    char s[MAXLEN];
    const char *t1, *t2;
    t1 = "abcdef\tgh\nijk\\";
    t2= "abcdef\\tgh\\nijk\\\\";
    printf("original t1 is:\n %s\n", t1);
    printf("t1 after escape visualization is:\n %s\n", escape(s, t1));
    printf("original t2 is:\n %s\n", t2);
    printf("t2 after unescape is:\n %s\n", unescape(s, t2));
    
}

char* escape(char s[], const char t[]){
    int i,j;
    for(i=0,j=0; t[i] != '\0'; ++i){
        switch (t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
    return s;
}

char* unescape(char s[], const char t[]){
    int i,j;
    int slash  = FALSE;
    for(i=0,j=0; t[i] != '\0'; ++i){
        switch (t[i]) {
            case '\\':
                if(slash){
                    slash = FALSE;
                    s[j++] = '\\';
                    break;
                }else{
                    slash = TRUE;
                    break;
                }
            case 't':
                if(slash){
                    slash = FALSE;
                    s[j++] = '\t';
                    break;
                }
            case 'n':
                if(slash){
                    slash = FALSE;
                    s[j++] = '\n';
                    break;
                }
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
    return s;
}

