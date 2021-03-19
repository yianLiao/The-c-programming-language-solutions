//
//  sectin_1.c
//  cprogramming
//
//  Created by josephliao on 2021/1/19.
//


#include <stdio.h>
#include <stdlib.h>
#include "section_1.h"
#include "section_2.h"
#include "section_3.h"
#include "section_4.h"
int TABWIDTH = 4; //spaces number of a tab.Only defined here as external var, and declared in section_1.h, then used elsewhere.
int main(int argc, const char * argv[]) {
    //TEST: call one function from a specific section
    mcalculator_call();
    return EXIT_SUCCESS;
}

