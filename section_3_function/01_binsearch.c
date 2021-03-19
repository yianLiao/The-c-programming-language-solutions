//
//  01_binsearch.c
//  cprogramming
//
//  Created by josephliao on 2021/3/6.
//

#include <stdio.h>
#include <stdlib.h>
#define LEN 1000000
int binsearch(int x, int v[], int n);
int nbinsearch(int x, int v[], int n);
void binsearch_call(void){
    int i;
    int v[LEN];//use an array of 0..LEN-1
    for(i = 0; i <= LEN - 1; i++)
        v[i] = i;
    
    int x = 99999;//search target
    
    printf("index:%d\n", binsearch(x, v, LEN));//may take longer time?
    //printf("newindex:%d\n", nbinsearch(x, v, LEN));
    //system("time ls");
}


int binsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low <= high){
        mid = (low+high) / 2;
        if(x < v[mid])
            high = mid - 1;//must -1 to ensure progress
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int nbinsearch(int x, int v[], int n){
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low < high){
        mid = (low+high) / 2;
        if(x <= v[mid])
            high = mid;
        else
            low = mid + 1;
    }
    return (v[high] == x) ? high : -1;
}

