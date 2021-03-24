//
//  sort_lines.h
//  cprogramming
//
//  Created by josephliao on 2021/3/24.
//

#ifndef sort_lines_h
#define sort_lines_h
#define CHARP char *
#define MAXSTORE 10000 /* max space allocated for all lines.  Same as ALLOCSIZE on p.91. */
void mqsort(CHARP v[], int left, int right);
int readlines(char *lineptr[], int maxlines);
void writelines(char *lineptr[], int nlines);
int myreadlines(char *lineptr[], int maxlines, char *ls);
#endif /* sort_lines_h */
