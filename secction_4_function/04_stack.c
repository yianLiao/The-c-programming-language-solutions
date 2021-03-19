//
//  04_stack.c
//  cprogramming
//
//  Created by josephliao on 2021/3/18.
//

#include <stdio.h>

#define MAXVAL 100
int sp = 0; /* next free stack position */
double val[MAXVAL];
void push(double);
double pop(void);

void push(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void){
    if(sp <= 0){
        printf("error: stack empty, can't pop\n");
        return 0.0;
    }
    else
        return val[--sp];
}

void print_top(void){
    if(sp <= 0){
        printf("error: stack empty!\n");
    }else{
        printf("top element is \t%g\n", val[sp-1]);
    }
}

void duplicate_top(void){
    int top;
    if(sp >= MAXVAL){
        printf("error: stack is full, can't duplicate top!\n");
    }else{
        top = val[sp-1];
        val[sp++] = top;
    }
}

void swap_top_two(void){
    int temp;
    if(sp >= 2){//there are at least two elements
        temp = val[sp-1];
        val[sp-1] = val[sp-2];
        val[sp-2] = temp;
    }
}

void clear_stack(void){
    sp = 0;
}
