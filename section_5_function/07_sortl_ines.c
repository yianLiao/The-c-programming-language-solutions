//
//  07_sortlines.c
//  cprogramming
//
//  Created by josephliao on 2021/3/24.
//

#include <stdio.h>
#include "sort_lines.h"
#define MAXLINES 1000

char *lineptr[MAXLINES];
void iungets(char s[]);
void iungetch(int c);
int sort_lines_call(void){
    
    char *lines = "12345\n12346\n1234\n12348\n12347\n123\n124\n234\n";
    iungetch(EOF);
    iungets(lines);
    int nlines;
    char linestore[MAXSTORE]; /* array for storing all lines ,\
                               myreadlines will pass an extra parameter linestore \
                               for storing all the input lines */
    //if((nlines = readlines(lineptr, MAXLINES)) >= 0){
    if((nlines = myreadlines(lineptr, MAXLINES, linestore)) >= 0){
        mqsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("error: input too big to sort\n");
        return 1;
    }
}
