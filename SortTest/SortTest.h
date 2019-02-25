//
// Created by Hemy08 on 2019/2/22.
//

#ifndef __SORTALGORITHM_SORTTEST_H__
#define __SORTALGORITHM_SORTTEST_H__

typedef struct Test_stArrStudent{
    unsigned int index;
    char name[20];
    unsigned int age;
}test_student;

/*
 * 打印 int 数组
 */
void TEST_SortPrintArray(unsigned int arr[], unsigned int  len);
/*
 * 测试 int 数组的冒泡法 排序
 */
void TEST_BubbleSortTestArr();
/*
 * 测试 结构体数据 的冒泡法 排序，按照其中一个int字段的值进行排序
 */
void TEST_BubbleSortTestStruct();

#endif //__SORTALGORITHM_SORTTEST_H__
