#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
    return k % 100;    // 키를 부분적으로만 사용한 별로 좋지 않은 해쉬의 예!!!
}

// 충돌이 발생하는것은 마찬가지
int main(void)
{
    Table myTbl;
    Person * np;
    Person * sp;
    Person * rp;
    
    // 해당 테이블의 전체 슬롯을 empty로 변경해준다
    TBLInit(&myTbl, MyHashFunc);
    
    // 데이터 입력
    np = MakePersonData(20120003, "Lee", "Seoul");
    
    // 해당 테이블 경로, 주민등록번호, 데이터 입력
    // 값 셋팅해주고 해당슬롯에 데이터가 들어있다고 변경해줌
    TBLInsert(&myTbl, GetSSN(np), np);
    
    np = MakePersonData(20130012, "KIM", "Jeju");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    np = MakePersonData(20170049, "HAN", "Kangwon");
    TBLInsert(&myTbl, GetSSN(np), np);
    
    // 데이터 검색
    sp = TBLSearch(&myTbl, 20120003);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    sp = TBLSearch(&myTbl, 20130012);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    sp = TBLSearch(&myTbl, 20170049);
    if(sp != NULL)
        ShowPerInfo(sp);
    
    // 데이터 삭제
    rp = TBLDelete(&myTbl, 20120003);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTbl, 20130012);
    if(rp != NULL)
        free(rp);
    
    rp = TBLDelete(&myTbl, 20170049);
    if(rp != NULL)
        free(rp);
    
    return 0;
}
