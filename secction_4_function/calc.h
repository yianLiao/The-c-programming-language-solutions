//
//  calc.h
//  cprogramming
//
//  Created by josephliao on 2021/3/18.
//

#ifndef calc_h
#define calc_h
#define NUMBER '0' /* signal that a number was found */
#define LIBFUNC '1' /* signal that a library function was found*/
#define DOUBLE_EPS 1E-15

void push(double);
double pop(void);
int getop(char[]);
int getop_line(char[]);
int getop_static(char[]);
int igetch(void);
void iungetch(int c);
void iungets(char s[]);
void ungets(char s[]);
void dofunc(char s[]);
#endif /* calc_h */
