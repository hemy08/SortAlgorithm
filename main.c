//
// Created by Hemy08 on 2019/2/19.
//

#include <stdio.h>
#include <string.h>
#include "./src/sort_api.h"

void SortPrintArray(unsigned int arr[], unsigned int  len)
{
    unsigned int i = 0;
    for (i = 0; i <len ; ++i) {
        printf("arr[%d] = %d \n",i,arr[i]);
    }
}

void main()
{
    unsigned int arr[10] = {5,421,23,24,16,9,2,7,4,50};

    SORT_BubbleSortDown(arr,10);
    SortPrintArray(arr,10);
    SORT_BubbleSortUp(arr,10);
    SortPrintArray(arr,10);
}