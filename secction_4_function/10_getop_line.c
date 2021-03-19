//
//  getop_line.c
//  cprogramming
//
//  Created by josephliao on 2021/3/18.
//

#include <stdio.h>
#include <ctype.h>
#include "calc.h"
#include "section_1.h" //get_line
#define MAXLINE 1000
char line[MAXLINE];
int li = 0;

int getop_line(char s[]){
    int i, c, nc;

    if(line[li] == '\0'){// need to get a new line
        if(get_line(line, MAXLINE) == 0)
            return  EOF;
        else
            li = 0;
    }
    
    while((s[0] = c = line[li++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    
    //handle a word input
    if(isalpha(c)){
        i = 0;
        while (isalpha(s[++i] = c = line[li++]))
            ;
        --li;
        s[i] = '\0';
        return LIBFUNC;
    }
            
    if(c == '-' || c == '+'){
        nc = line[li++];
        if(!isdigit(nc) && nc != '.'){
            //c is not sign but operator, and put back nc
            li--;
            return c;
        }else{
            //c is sign, just put back digit part to continue
            li--;
        }
    }else{
        if(!isdigit(c) && c != '.')
            return c; /* not a number */
    }
    
    i = 0;
    s[++i] = c = line[li++];//s[0] is sign, s[1] is first digit or .
    
    if(isdigit(c))//integer part
        while (isdigit(s[++i] = c = line[li++]))
            ;
    if(c == '.')//fraction part
        while (isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    if(c != EOF)
        li--;
    return NUMBER;
}
