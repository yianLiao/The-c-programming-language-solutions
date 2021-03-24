//
//  02_getfloat.c
//  cprogramming
//
//  Created by josephliao on 2021/3/23.
//

#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define SIZE 100

int igetch(void);
int iungetch(int);
int ungets(char *s);
int getfloat(double *pn);

static int n;
static double array[SIZE];

void getfloat_call(void){
    int ret;
    int i;
    char *s = "@-0.2e3@+.0e-1@-.1e2@-.e-2++e23e-1+2";
    //char *s = "-.e-2+2";
    ungets(s);
    for(n = 0; n < SIZE && (ret = getfloat(&array[n])) != EOF; n++){
        if(ret == 0){//next input not number
            n--;//not moving n
            printf("remove an invalid character: %c\n", igetch());
        }
    }
    printf("input %s\n", s);
    printf("end of file, output array:\n");
    for(i = 0; i <= n-1; i++){
        printf("%d->%g\t", i, array[i]);
    }
}

/* getfloat: get next float into *pn
   return EOF for the end of file, zero if next input not a number, positive if valid number
 */
int getfloat(double *pn){
    int c;
    int sign;//sign is 1 or -1
    int sc;//sc is '+' or '-'
    int sgnValid = 0;//1 if got sign before
    int intValid = 0;//1 if got at least one digit of integer part before

    int power;//power of 10 to divide after getting fraction part
    
    int e;//e is 'e' or 'E'
    int esign;//esign is 1 or -1 for exponent part
    int esc;//esc is '+' or '-' for the exponent part
    int epower;//power of 10 to divide/multiply after getting exponet part
    
    while(isspace(c = igetch()))/*skip spaces*/
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.'){
        iungetch(c);//not a number
        return 0;
    }
    
    if(c == EOF)
        return EOF;

    sign = (c == '-') ? -1 : 1;

    /*get the integer part if any*/
    if(c == '+' || c == '-'){
        sgnValid = 1;
        sc = c;
        c = igetch();
        if(!isdigit(c) && c != '.'){//(+|-)not part of valid float point number, end input
            iungetch(c);
            iungetch(sc);
            return 0;
        }
    }
    if(isdigit(c)){
        intValid = 1;//intValid is not 0 if at least one digit of integer part is valid
        for(*pn = 0; isdigit(c); c = igetch()){
            *pn = *pn * 10 + (c - '0');
        }
    }
    
    /*get the fraction part if any*/
    if(c == '.'){
        c = igetch();
        if(!isdigit(c)){//. not floating point but random char, end input
            iungetch(c);
            iungetch('.');
            if(sgnValid && !intValid)
                iungetch(sc);//got sign but not any integer digit, need to throw back sign
            if(intValid)
                *pn *= sign;
            return intValid;
        }
        for(power = 1; isdigit(c); c = igetch()){
            *pn = *pn * 10 + (c - '0');
            power *= 10;
        }
        *pn /= power;
    }

    /*get the exponent part  if any*/
    if(c == 'e' || c == 'E'){
        e = c;
        c = igetch();
        esign = (c == '-') ? -1 : 1;
        if(!isdigit(c) && c != '+' && c != '-'){//(e|E)not part of valid exponent, end input
            iungetch(c);
            iungetch(e);
            *pn *= sign;
            return 1;//there is a valid input number up to this ponit
        }
        if(c == '+' || c == '-'){
            esc = c;
            c = igetch();
            if(!isdigit(c)){//(e|E)(+|-) not part of valid exponent, end input
                iungetch(c);
                iungetch(esc);
                iungetch(e);
                *pn *= sign;
                return 1;//the float number must be valid up to this ponit
            }
        }
        for(epower = 0; isdigit(c); c = igetch()){
            epower = epower * 10 + (c - '0');
        }
        *pn = *pn * pow(10, epower * esign);
    }
    iungetch(c);
    *pn *= sign;
    return 1;
}
