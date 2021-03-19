//
//  cprogramming
//
//  Created by josephliao on 2021/1/24.
//
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

void trimspace(void){
    /*
    int c, d;
    while((c = getchar()) != EOF){
        if(c == ' '){
            putchar(c);
            while((d = getchar()) != EOF && d == ' ');
            if(d == EOF) return;
            putchar(d);
        }else{
            putchar(c);
        }
    }
    */
    
    /* 程序虽然简单，但是状态的变化需要细心维护，分析出哪些情况会引起状态标志的改变。
        prevspace = true/false 代表自动机两种状态，初始状态为false
        可以换出状态转移图，其中有两个节点代表状态，每个节点会发出两条边，代表对于不同的输入产生的状态转移。
        在每条边上可以标注 （输入/输出), 那么每两个节点与连接这两个节点的边及标注就代表了一个转移函数，即在某状态下对于某种
        输入会产生某种输出和某种状态转移。
     */
    int c;
    int prevspace = FALSE;
    while((c = getchar()) != EOF){
        if(c == ' '){
            if(prevspace == FALSE){
                putchar(' ');
                prevspace = TRUE;
            }
        }else{
            putchar(c);
            prevspace = FALSE;
        }
    }
    
}
