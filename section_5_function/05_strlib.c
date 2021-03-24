//
//  05_strlib.c
//  cprogramming
//
//  Created by josephliao on 2021/3/24.
//

#include <stdio.h>
#include <string.h>
#define SIZE 100
void istrncpy(char *s, const char *t, int n);
void istrncat(char *s, const char *t, int n);

void strlib_call(void){
    char s[SIZE] = "123456";
    char t[SIZE] = "abcde";
    istrncat(s, t, 2);
    printf("after operation: %s\n", s);
}


void istrncpy(char *s, const char *t, int n){
    while(*t && (n-- > 0))
        *s++ = *t++;
    *s = '\0';
}

void istrncat(char *s, const char *t, int n){
    while(*s)
        s++;
    istrncpy(s, t, n);
}
/*istrncmp from gcc source code*/
int istrncmp(const char *s, const char *t, int n){
    register unsigned char u1, u2;
    while (n-- > 0){
      u1 = (unsigned char) *s++;
      u2 = (unsigned char) *t++;
      if (u1 != u2)
        return u1 - u2;
      if (u1 == '\0')
        return 0;
    }
    return 0;
}
