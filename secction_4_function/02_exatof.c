//
//  02_exatof.c
//  cprogramming
//
//  Created by josephliao on 2021/3/18.
//

#include <stdio.h>
#include <ctype.h>

double exatof(const char s[]);

void exatof_call(void){
    char *s = ".4235E+3";
    printf("%f\n", exatof(s));
}


double exatof(const char s[]){
    double value, power;
    int i, sign;
    int expo, esign;
    
    //skip space
    for(i=0; isspace(s[i]); ++i);
    
    //get sign if any
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    
    //get integer part
    for(value = 0.0; isdigit(s[i]); i++){
        value = value * 10.0 + (s[i] - '0');
    }
    if(s[i] == '.')
        i++;
    
    //get fraction part while keeping track of extra power
    for(power = 1.0; isdigit(s[i]); i++){
        value = value * 10.0 + (s[i] - '0');
        power *= 10.0;
    }
    
    //get exponent part
    if(s[i] == 'e' || s[i] == 'E'){
        i++;
        esign = (s[i] == '-') ? -1 : 1;
        if(s[i] == '+' || s[i] == '-')
            i++;
        for(expo = 0; isdigit(s[i]); i++){
            expo = expo * 10 + (s[i] - '0');
        }
        
        if(esign < 0){
            //actual power to divided should raise
            for(; expo>0; expo--){
                power *= 10.0;
            }
        }else{
            //actual power to divided should decrease
            for(; expo>0; expo--){
                power /= 10.0;
            }
        }
        
    }
    
    return sign * (value / power);
    
}

