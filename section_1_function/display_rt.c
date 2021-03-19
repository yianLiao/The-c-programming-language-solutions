//
//  display_rt.c
//  cprogramming
//
//  Created by josephliao on 2021/1/24.
//
#include <stdio.h>
#include <stdlib.h>

int display_rt(void){
    int c;
    //system("/bin/stty raw");
    while((c = getchar()) != EOF){
        putchar(c);
    }
    //system("/bin/stty cooked");
    return EXIT_SUCCESS;
}
