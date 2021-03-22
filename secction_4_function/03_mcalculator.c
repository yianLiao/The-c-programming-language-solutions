//
//  03_mcalculator.c
//  cprogramming
//
//  Created by josephliao on 2021/3/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100 /* max size of operand or operator*/


int mcalculator(void);
void mcalculator_call(void){
    char *s = "1.0 2.0 + -.5 -.5 + * 3 + sin 6 5 % - \n";//sin((1+2)*(-0.5-0.5) + 3)-(6 % 5) = -1
    printf("auto input string: %s\n", s);
    iungets(s);
    //ungets(s); //exercise 4-10
    mcalculator();
}


int mcalculator(void){
    int type;
    double op2;
    char s[MAXOP];
    
    while((type = getop(s)) != EOF){
        //exercise 4-10 use getop_line(s) instead and change iungets to ungets
        //exercise 4-11 use getop_static(s) instead
        switch (type) {
            case LIBFUNC:
                dofunc(s);
                break;
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if(fabs(op2) > DOUBLE_EPS)//op2 not 0
                    push(pop() / op2);
                else{
                    printf("error: zero divisor\n");
                    return -1;
                }
                break;
            case '%':
                op2 = pop();
                if (fabs(op2) > DOUBLE_EPS)
                    push(fmod(pop(), op2));
                else
                    printf("error: zero devisor\n");
                break;
            case '\n':
                printf("output result : %.8g\n", pop());
                printf("waiting for next input...\n");
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
