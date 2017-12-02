#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person * Value;

// 데이터 저장되 있지 않다, 데이터가 저장되었다 현재는 지워진상태, 현재 데이터가 저장되어 있음
enum SlotStatus {EMPTY, DELETED, INUSE};

typedef struct _slot
{
    Key key;
    Value val;
    enum SlotStatus status;
}Slot;

// Slot과 관련해서는 별도의 함수를 정의하지 않는다.
#endif
