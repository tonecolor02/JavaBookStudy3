#ifndef __TABLE2_H__
#define __TABLE2_H__

#include "Slot2.h"
#include "DLinkedList.h"

#define MAX_TBL     100

typedef int HashFunc(Key k);

typedef struct _table
{
    // 배열 형태의 테이블을 리스트 형태로 바꿈
    //    Slot tbl[MAX_TBL];
    List tbl[MAX_TBL];
    HashFunc * hf;
} Table;

void TBLInit(Table * pt, HashFunc * f);
void TBLInsert(Table * pt, Key k, Value v);
Value TBLDelete(Table * pt, Key k);
Value TBLSearch(Table * pt, Key k);

#endif
