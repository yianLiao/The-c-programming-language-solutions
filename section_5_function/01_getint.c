//
//  01_getint.c
//  cprogramming
//
//  Created by josephliao on 2021/3/23.
//

#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int igetch(void);
int iungetch(int);
int getint(int *pn);
int ungets(char *s);
static int n, array[SIZE];

void getint_call(void){
    int ret;
    int i;
    char *s = "@+@+123-23@-@-3";
    printf("input %s\n", s);
    ungets(s);
    for(n = 0; n < SIZE && (ret = getint(&array[n])) != EOF; n++){
        if(ret == 0){//next input not number
            n--;//not moving n
            printf("remove an invalid character: %c\n", igetch());
        }
    }
    printf("end of file, output array:\n");
    for(i = 0; i <= n-1; i++){
        printf("%d->%d\t", i, array[i]);
    }
        
}


/*getint: get next integer into *pn
 return EOF for the end of file, zero if next input not a number, positive if valid number
 */
int getint(int *pn){
    int c, sign, sc;
    while(isspace(c = igetch()))/*skip spaces*/
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        iungetch(c);//not a number
        return 0;
    }
    
        
    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-'){
        sc = c;
        c = igetch();
        if(!isdigit(c)){//+ - not sign but random char
            iungetch(c);
            iungetch(sc);
            return 0;
        }
    }
    
    for(*pn = 0; isdigit(c); c = igetch()){/*get the whole number*/
        *pn = *pn * 10 + (c - '0');
    }
    iungetch(c);
    *pn *= sign;
    return 1;
}
