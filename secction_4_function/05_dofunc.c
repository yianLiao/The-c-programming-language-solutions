//
//  dofunc.c
//  cprogramming
//
//  Created by josephliao on 2021/3/18.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calc.h"
int isInt(double f);
void dofunc(char s[]){
    double op1, op2;
    if(strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if(strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if(strcmp(s, "pow") == 0){
        op2 = pop();
        op1 = pop();
        if ((op1 == 0 && op2 <= 0) || (op1 < 0 && !isInt(op2)))
             printf("error: domain (%g^%g)\n", op1, op2);
        else
            push(pow(pop(), op2));
    }else{
        printf("error: unknown command %s \n", s);
    }
}

int isInt(double f){
    return fabs(f) - floor(fabs(f)) < DOUBLE_EPS ? 1 : 0;
}
