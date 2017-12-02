#ifndef __SLOT2_H__
#define __SLOT2_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

// 슬롯의 상태 정보를 표시하기 위한 enum 선언과 관련 구조체의 멤버가 사라짐

typedef struct _slot
{
    Key key;
    Value val;
} Slot;

#endif
