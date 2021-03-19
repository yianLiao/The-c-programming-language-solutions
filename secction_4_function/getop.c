//
//  getop.c
//  cprogramming
//
//  Created by josephliao on 2021/3/18.
//

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop(char s[]){
    int i, c, nc;
    while((s[0] = c = igetch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    //handle a word input
    if(isalpha(c)){
        i = 0;
        while (isalpha(s[++i] = c = igetch()))
            ;
        iungetch(c);
        s[i] = '\0';
        return LIBFUNC;
    }
            
    if(c == '-' || c == '+'){
        nc = igetch();
        if(!isdigit(nc) && nc != '.'){
            //c is not sign but operator, and put back nc
            iungetch(nc);
            return c;
        }else{
            //c is sign, just put back digit part to continue
            iungetch(nc);
        }
    }else{
        if(!isdigit(c) && c != '.')
            return c; /* not a number */
    }
    
    i = 0;
    s[++i] = c = igetch();//s[0] is sign, s[1] is first digit or .
    
    if(isdigit(c))//integer part
        while (isdigit(s[++i] = c = igetch()))
            ;
    if(c == '.')//fraction part
        while (isdigit(s[++i] = c = igetch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        iungetch(c);
    return NUMBER;
}
