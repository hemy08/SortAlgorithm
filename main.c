//
// Created by Hemy08 on 2019/2/19.
//

#include <stdio.h>
#include <string.h>
#include "./src/sort_api.h"
#include "SortTest/SortTest.h"
#include "SortTest/Debug.h"

void main()
{
    LogSetLogFileName("E:\\myCodeHub\\SortAlgorithm\\debug_log.log");
    LogSetRecordMode(LOG_FMT);
    TEST_BubbleSortTestArr();
    TEST_BubbleSortTestStruct();
}