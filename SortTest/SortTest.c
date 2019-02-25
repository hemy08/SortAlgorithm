/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* Copyright(C),2019-2020,Hemy08
* File Name : bubble sort
* Author : hemy08
* Version : 1.0
* Date : 2019/2/19
* Description : 测试各类排序算法
* Others :
* History ：Created by Hemy08 on 2019/2/19.
* Function List :
*
*
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
#include "SortTest.h"
#include "Debug.h"
#include "../src/sort_api.h"
#include <string.h>
#include <stdio.h>


test_student gstArrStudent[10] = {
        {15,    "Mr.Jack",  19},
        {91,    "Ms.Jack",  21},
        {62,    "Mr.Mark",  14},
        {17,    "Mr.Mary",  30},
        {88,    "Mr.Road",  25},
        {32,    "Mr.Hall",  28},
        {43,    "Mr.Haley", 22},
        {22,    "Mr.Hem",   18},
        {19,    "Mr.Bran",  21},
};


/*
 * 打印 int 数组
 */
void TEST_SortPrintArray(unsigned int arr[], unsigned int  len)
{
    unsigned int i = 0;
    for (i = 0; i <len ; ++i) {
        LOG_RECORD(LOG_LEV_ERROR,"arr[%d] = %d \n",i,arr[i]);
    }
}

/*
 * 测试 int 数组的冒泡法 排序
 */
void TEST_BubbleSortTestArr()
{
    unsigned int arr[10] = {5,421,23,24,16,9,2,7,4,50};
    LOG_RECORD(LOG_LEV_ERROR,"\nTEST_BubbleSortTestArr ======================BEGIN===============================");
    LOG_RECORD(LOG_LEV_ERROR,"\nBefore Sort Down arr = {5,421,23,24,16,9,2,7,4,50}");
    SORT_BubbleSortDown(arr,10);
    LOG_RECORD(LOG_LEV_ERROR,"\nAfter Sort Down arr : ");
    for (int i = 0; i < 10 ; ++i) {
        LOG_RECORD(LOG_LEV_ERROR,"arr[%d] = %d",i,arr[i]);
    }

    LOG_RECORD(LOG_LEV_ERROR,"\nBefore Sort Up arr = {5,421,23,24,16,9,2,7,4,50}");
    SORT_BubbleSortUp(arr,10);
    LOG_RECORD(LOG_LEV_ERROR,"\nAfter Sort Up arr : ");
    for (int i = 0; i < 10 ; ++i) {
        LOG_RECORD(LOG_LEV_ERROR,"arr[%d] = %d",i,arr[i]);
    }

    LOG_RECORD(LOG_LEV_ERROR,"\nTEST_BubbleSortTestArr ========================END===============================");
}

/*
 * 测试 结构体数据 的冒泡法 排序，按照其中一个int字段的值进行排序
 */
void TEST_BubbleSortTestStruct()
{
    unsigned int arr[10] = {0};

    LOG_RECORD(LOG_LEV_ERROR,"\nTEST_BubbleSortTestStruct ======================BEGIN===============================");
    for (int i = 0; i <10 ; i++) {
        arr[i] = gstArrStudent[i].index;
    }

    test_student oldStudent[10] = {0};

    LOG_RECORD(LOG_LEV_ERROR,"\nBefore Sort up arr ：");
    for (int i = 0; i <10 ; i++) {
        LOG_RECORD(LOG_LEV_ERROR,"gstArrStudent[%d] = {index: %d, name: %s, age: %d}",i,gstArrStudent[i].index,gstArrStudent[i].name,gstArrStudent[i].age);
    }

    memcpy_s(oldStudent, sizeof(test_student)*10,gstArrStudent,sizeof(test_student)*10);
    SORT_BubbleSortUp(arr,10);
    for (int i = 0; i <10 ; i++) {
        for (int j = 0; j <10 ; j++) {
            if (arr[i] == oldStudent[j].index)
                memcpy_s(&gstArrStudent[i], sizeof(test_student),&oldStudent[j],sizeof(test_student));
        }
    }

    LOG_RECORD(LOG_LEV_ERROR,"\nAfter Sort up arr ：");
    for (int i = 0; i <10 ; i++) {
        LOG_RECORD(LOG_LEV_ERROR,"gstArrStudent[%d] = {index: %d, name: %s, age: %d}",i,gstArrStudent[i].index,gstArrStudent[i].name,gstArrStudent[i].age);
    }

    LOG_RECORD(LOG_LEV_ERROR,"\nTEST_BubbleSortTestStruct ========================END===============================");
}
