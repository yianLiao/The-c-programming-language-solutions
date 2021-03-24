//
//  qsort.c
//  cprogramming
//
//  Created by josephliao on 2021/3/24.
//

#include <stdio.h>
#include <string.h>
#include "sort_lines.h"
void swap(char *v[], int i, int j);
int partition(CHARP v[], int left, int right);


/*qsort: sort v[left] ... v[right] into increasing order*/
void mqsort(CHARP v[], int left, int right){
    if(left < right){
        int pivot = partition(v, left, right);
        mqsort(v, left, pivot-1);
        mqsort(v, pivot+1, right);
    }
}

/*swap: interchange v[i] and v[j]*/
void swap(CHARP v[], int i, int j){
    CHARP temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/*partition: create a partition of v, return pivot,
 where v[left..pivot-1] < v[pivot], and v[pivot+1..right] >= v[pivot]
 */
int partition(CHARP v[], int left, int right){
    /*use middle element as pivot element, and swap it with left element*/
    swap(v, left, (left + right) / 2);
    /*now save the pivot element to create an empty position on left*/
    CHARP pivot = v[left];
    
    while(left < right){
        while(left < right && strcmp(v[right], pivot) >= 0) --right;
        v[left] = v[right]; //move the smaller element to empty left, create an empty right
        while(left < right && strcmp(v[left], pivot) <= 0) ++left;
        v[right] = v[left];//move the bigger element to empty right, create an empty left
    }

    v[left] = pivot;//put back pivot element
    return left;
}
