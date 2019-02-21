/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* Copyright(C),2019-2020,Hemy08
* File Name : bubble sort
* Author : hemy08
* Version : 1.0
* Date : 2019/2/19
* Description : 冒泡排序算法
* Others :
* History ：Created by Hemy08 on 2019/2/19.
* Function List :
*
*
*
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/*
 *     冒泡排序是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果它们的顺序错误就把它们交换过来。走访数列的工作是重复地进
 * 行直到没有再需要交换，也就是说该数列已经排序完成。这个算法的名字由来是因为越小的元素会经由交换慢慢“浮”到数列的顶端。
 *
 * 算法描述 :
 *          1 比较相邻的元素。如果第一个比第二个大，就交换它们两个；
 *          2 对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对，这样在最后的元素应该会是最大的数；
 *          3 针对所有的元素重复以上的步骤，除了最后一个；
 *          4 重复步骤1~3，直到排序完成。
 */
#include "sort_api.h"

/*
 * 升序排序
 */
void SORT_BubbleSortUp(unsigned int arr[], unsigned int len)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int tmpval = 0;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] >= arr[j+1]) {        // 相邻元素两两对比
                tmpval = arr[j+1];        // 元素交换
                arr[j+1] = arr[j];
                arr[j] = tmpval;
            }
        }
    }
    return;
}

/*
 * 降序排序
 */
void SORT_BubbleSortDown(unsigned int arr[], unsigned int len)
{
    unsigned int i = 0;
    unsigned int j = 0;
    unsigned int tmpval = 0;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] <= arr[j+1]) {        // 相邻元素两两对比
                tmpval = arr[j+1];        // 元素交换
                arr[j+1] = arr[j];
                arr[j] = tmpval;
            }
        }
    }
    return;
}