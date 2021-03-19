//
//  03_htoi.c
//  cprogramming
//
//  Created by josephliao on 2021/3/4.
//

#include <stdio.h>

#define HEXPOWER 16
#define MAXLEN 30
int htoi(char s[]);
int htoi_simple(char s[]);
int dhtoi(int d);

void htoi_call(void){
    char s[MAXLEN];
    int sval = 0;
    printf("please input a string of hexadecimal digits, end with \\n:\n");
    scanf("%s", s);
    //sval = htoi_simple(s);
    sval = htoi(s);
    if(sval >= 0)
        printf("the decimal value is:%d\n", sval);
    else
        printf("invalid string!\n");
}

int htoi(char s[]){
    int i = 0;
    int c;
    int n;
    int prefix = 0;
    if(s[i] == '\0')
        return -1;
    else if(s[i] == '0'){
        prefix = 1;
        n = 0;
    }else if( (c = dhtoi(s[i])) < 0){
        return -1;
    }else{
        prefix = 0;
        n = c;
    }
    ++i;
    
    for(;i < MAXLEN && s[i] != '\0'; i++){
        if(prefix == 1){
            if(s[i] == 'x' || s[i] == 'X'){
                c = 0;
            }else{
                c = dhtoi(s[i]);
            }
            prefix = 0;
        }else{
            c = dhtoi(s[i]);
        }
        if(c < 0)
            return -1;
        n = n * HEXPOWER + c;
    }
    return n;
}

int dhtoi(int d){
    if(d >= '0' && d <= '9')
        return d - '0';
    else if(d >= 'a' && d<= 'f')
        return d - 'a' + 10;
    else if(d >= 'A' && d <= 'F')
        return d - 'A' + 10;
    else return -1;
}

/*another simple solution*/
int htoi_simple(char s[]){
    int i;
    int c;
    int n;
    for(i=0, n=0; i < MAXLEN && (c = s[i]) != '\0'; i++){
        n *= HEXPOWER;
        if(i == 0 && c == '0'){
            c = s[++i];
            if(c != 'x' && c != 'X')//skip 0x or 0X at the beginning of s
                --i;
        }else if(c >= '0' && c <= '9')
            n += c - '0';
        else if(c >= 'a' && c <= 'f')
            n += c - 'a' + 10;
        else if(c >= 'A' && c <= 'F')
            n += c - 'A' + 10;
        else return -1;//invalid character
    }
    return n;
}
