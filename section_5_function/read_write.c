//
//  read_write.c
//  cprogramming
//
//  Created by josephliao on 2021/3/24.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort_lines.h"
#define MAXLEN 1000
int get_line(char s[], int limit);

/*readlines: read input lines, save it and keep pointers in lineptr
 */
int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0) {
        if(nlines >= maxlines || (p = malloc(len)) == NULL)
            return  -1;
        else{
            line[len-1] = '\0';/*replace \n with \0*/
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}

/* My solution to the problem, without using alloc */

int myreadlines(char *lineptr[], int maxlines, char *ls)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    p = ls + strlen(ls); /* initiate to first empty position */
    while ((len = get_line(line, MAXLEN)) > 0)
        /* The line below will check to make sure adding the nextline will not exceed MAXSTORE */
        if (nlines >= maxlines || (strlen(ls) + len) > MAXSTORE)
            return -1;
        else
        {   line[len-1] = '\0';/*replace \n with \0*/
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len; /* point p to next empty position */
        }
    return nlines;
}



/*writelines: write output lines*/
void writelines(char *lineptr[], int nlines){
    while (nlines-- > 0) {
        printf("%s\n", *lineptr++);
    }
}
