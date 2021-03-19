//
//  17_print_eighty.c
//  cprogramming
//
//  Created by josephliao on 2021/2/1.
//

#include <stdio.h>
#include "section_1.h"
#define MAX_LEN 1000 /* maximum input line size*/
#define LEN_PRINT 80 /* print sentence longer than len_print*/

void print_eighty(void){
    int tempLen = 0; //length of current read in
    int curLen = 0; // length of current line
    char tempLine[MAX_LEN]; // content of current read in
    
    while ((tempLen = get_line(tempLine, MAX_LEN)) > 0) {
        curLen += tempLen;
        if(curLen > LEN_PRINT)
            printf("%s", tempLine);
        if(tempLen != MAX_LEN - 1 || tempLine[tempLen -1] == '\n')
            curLen = 0;
    }
}
