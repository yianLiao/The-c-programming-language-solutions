//
//  04_strend.c
//  cprogramming
//
//  Created by josephliao on 2021/3/24.
//

#include <stdio.h>
int strend(const char *s, const char *t);

void strend_call(void){
    char *s = "hello@world!\0aaa";
    char *t = "o@world!\0bbb";
    printf("whether\" %s\" occurs at the end of \"%s\":\n%s\n", t, s, strend(s, t) ? "yes" : "no");
}

int strend(const char *s, const char *t){
    if(s == NULL && t == NULL) return -1;
    const char *savet = t;
    while(*s)
        s++;
    while(*t)
        t++;
    while((t >= savet) && (*s == *t)){
        s--;
        t--;
    }
    if(t < savet)
        return 1;
    else
        return 0;
}
