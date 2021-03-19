//
//  21_entab.c
//  cprogramming
//
//  Created by josephliao on 2021/2/1.
//when either a tab or a single blank would suffice to reach a tab stop, if this space is between two words,
//do not replace it with tab.(special case)

#include <stdio.h>
#include "section_1.h"

void entab(void){
    //deal with replacement every tab stops
    int c;
    int prespace = 0; //number of spaces before current getchar
    int count = 0;//next position to getchar within a tabwidth, range from 0 to TABWIDTH-1
    while( (c = getchar()) != EOF){
        count = (count+1) % TABWIDTH;
        
        if(count == 1 || c == '\n'){
            //time to deal with replacement for the previous tabwidth
            if(prespace != 0){
                //has trailing spaces,replace with tab
                if(prespace == 1 && c != ' ' && c != '\n'){
                    //special case that do not replace this single space with tab
                    putchar('*');
                    prespace = 0;
                }else{
                    putchar('\t');
                    prespace = 0;
                }
            }
        }
        if(c == '\n'){
           // not counting the newline
            count = 0;
        }
        //handle current char
        if(c == ' '){
            //maybe trailing space, save it
            ++prespace;
        }else{//not trailing spaces, just put back saved spaces and current char
            while (prespace != 0) {
                putchar('*');
                --prespace;
            }
            putchar(c);
        }

    }
}


void entab_v2(void){
    //based on input
    int c;
    int i;
    int prespace = 0; //number of successive spaces before non-space char
    int col = 0;//next position to getchar in a line
    int tabn = 0;// number of replacements should be taken
    while ((c = getchar()) != EOF) {
        if(c == ' '){
            ++prespace;
            ++col;
        }else{
            //replacement if necessary
            if(prespace == 1){
                if(c != '\n'){
                    //special case
                    putchar(' ');
                }else{
                    putchar('\t');
                }
            }else if(prespace > 1){
                //if col-prespace <= i*TABWIDTH-1 <= col-1 for some i, then replace with a tab
                //reduced to: i <= col/TABWIDTH and i >= (col-prespace+1-1)/TABWIDTH + 1
                //that is : (col-prespace)/TABWIDTH + 1 <= i <= col/TABWIDTH
                tabn = col/TABWIDTH - (col-prespace)/TABWIDTH;
                for (i = 0; i < tabn; ++i)
                    putchar('\t');
                if(tabn >= 1){
                    //at least one replacement
                    prespace = col % TABWIDTH;
                }
                for(i = 0; i <= prespace - 1; ++i)
                    putchar(' ');
            }
            prespace = 0;
            putchar(c);
            ++col;
            if(c == '\n')
                col = 0;
        }
    }
    
}
