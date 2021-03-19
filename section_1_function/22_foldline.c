//
//  22_foldline.c
//  cprogramming
//  fold long line by outputting word by word, try not to break a word if there exists some blank character within a line. when it is long line without any blank character, use '-' to break a word.
//  Created by josephliao on 2021/2/4.
//

#include <stdio.h>
#define LINELENGTH 10
#define TABWIDTH 4

void foldline_v2(void){
    int i;
    int c, linelen, wordlen, wslen;
    char wordbuf[LINELENGTH];
    
    linelen = wordlen = wslen = 0;
    while((c = getchar()) != EOF){
        if(c == ' ' || c == '\t'){//end of a word
            wordbuf[wordlen] = '\0';
            wslen = ( c == '\t' ? TABWIDTH : 1);
            if(linelen + wordlen > LINELENGTH){
                //try not to break a word,output to the next line instead
                putchar('\n');
                printf("%s", wordbuf);
                linelen = wordlen;
                wordlen = 0;
            }else{
                linelen = linelen + wordlen;
                printf("%s", wordbuf);
                wordlen = 0;
            }
            //output that blank character c, check if linelength reached
            if(linelen + wslen > LINELENGTH){
                putchar('\n');
                linelen = wslen;
                putchar(c);
            }else{
                linelen = linelen + wslen;
                putchar(c);
            }
        }else if (c == '\n'){
            wordbuf[wordlen] = '\0';
            if(linelen + wordlen > LINELENGTH){
                //try not to break a word,output to the next line instead
                putchar('\n');
            }
            printf("%s", wordbuf);
            putchar(c);
            linelen = 0;
            wordlen = 0;
        }else{
            if(wordlen == LINELENGTH){
                //very long line without any blank character need to break
                for(i = 0; i < LINELENGTH-1; i++)
                    putchar(wordbuf[i]);
                putchar('-');
                putchar('\n');
                wordbuf[0] = wordbuf[LINELENGTH-1];
                wordlen = 1;
                linelen = 0;
            }
            wordbuf[wordlen] = c;
            wordlen++;
        }
    }
}
