#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include "record.h"

// function prototypes
int defragment(Record[],int* count);
void display_stats(Record[]);
void sort(Record[],int* count);
void swap(Record* a,Record* b);
void searchBacknum(Record[], int*);
void searchTotalPay(Record[], int*);

#endif
