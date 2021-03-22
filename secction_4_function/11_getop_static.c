//
//  getop_static.c
//  cprogramming
//
//  Created by josephliao on 2021/3/18.
//

#include <stdio.h>
#include <ctype.h>
#include "calc.h"

int getop_static(char s[]){
    int i, c, nc;
    static int pbk = '\0';//to save a putback char
    
    if(pbk == '\0'){
        c = igetch();
    }else{
        c = pbk;
        pbk = '\0';
    }
    
    while((s[0] = c) == ' ' || c == '\t')
        c = igetch();
    s[1] = '\0';
    
    //handle a word input
    if(isalpha(c)){
        i = 0;
        while (isalpha(s[++i] = c = igetch()))
            ;
        pbk = c;
        s[i] = '\0';
        return LIBFUNC;
    }
    
    //handle ambiguous - +
    if(c == '-' || c == '+'){
        if(pbk == '\0'){
            nc = igetch();
        }else{
            nc = pbk;
            pbk = '\0';
        }
        if(!isdigit(nc) && nc != '.'){
            //c is not sign but operator, and put back nc
            pbk = nc;
            return c;
        }else{
            //c is sign, just put back digit part to continue
            pbk = nc;
        }
    }else{
        if(!isdigit(c) && c != '.')
            return c; /* not a number */
    }
    
    //handle numeric part
    i = 0;
    if(pbk == '\0'){
        c = igetch();
    }else{
        c = pbk;
        pbk = '\0';
    }
    s[++i] = c;//s[0] is sign, s[1] is first digit or .
    if(isdigit(c))//integer part
        while (isdigit(s[++i] = c = igetch()))
            ;
    if(c == '.')//fraction part
        while (isdigit(s[++i] = c = igetch()))
            ;
    s[i] = '\0';
    if(c != EOF)
        pbk = c;
    
    return NUMBER;
}
