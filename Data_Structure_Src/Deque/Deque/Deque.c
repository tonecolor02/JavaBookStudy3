#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// 머리와 꼬리에 값은 null 을 가르킴
void DequeInit(Deque * pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

int DQIsEmpty(Deque * pdeq)
{
    if(pdeq->head == NULL)
        return TRUE;
    else
        return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    // 새로 입력된 데이터는 다음데이터를 덱의 해드가 가르키는 데이터로 선언
    newNode->next = pdeq->head;
    
    // 덱에 값이 없을경우 꼬리는 새로운 데이터를 가르킴
    // 덱에 값이 있을경우 해드의 이전 데이터는 새로운 데이터를 가르킴
    if(DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    else
        pdeq->head->prev = newNode;
    
    // 새로 입력된 데이터의 이전데이터는 없기때문에 null 로 선언
    newNode->prev = NULL;
    
    // 덱의 해드값은 새로운 데이터를 가르킴
    pdeq->head = newNode;
}

void DQAddLast(Deque * pdeq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    // 새로 입력된 데이터는 꼬리를 가르킴
    newNode->prev = pdeq->tail;
    
    // 덱에 아무 데이터가 없으면 해드는 새로 입력된 데이터를 가르킴
    // 덱에 데이터가 있을경우 꼬리가 가르키는 다음데이터는 새로운 데이터를 가르킴
    if(DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;
    
    // 새 데이터의 다음데이터는 없기때문에 null로 선언
    newNode->next = NULL;
    
    // 덱의 꼬리는 새 데이터를 가르킴
    pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque * pdeq)
{
    // 덱의 머리가 가르키는 데이터 위치
    Node * rnode = pdeq->head;
    
    // 덱의 머리가 가르키는 데이터
    Data rdata = pdeq->head->data;
    
    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!");
        exit(-1);
    }
    
    // 덱의 머리는 덱의 머리가 가르키던 이전데이터를 가르키게 한후 기존에 가르키는 데이터 삭제
    pdeq->head = pdeq->head->next;
    free(rnode);
    
    // 해당 덱에 데이터가 없으면 꼬리값 초기화
    // 데이터가 있을경우 해드가 가르키는 이전값은 없음
    if(pdeq->head == NULL)
        pdeq->tail = NULL;
    else
        pdeq->head->prev = NULL;
    
    return rdata;
}

Data DQRemoveLast(Deque * pdeq)
{
    // 꼬리가 가르키는 데이터 위치
    Node * rnode = pdeq->tail;
    
    // 꼬리가 가르키는 데이터
    Data rdata = pdeq->tail->data;
    
    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!");
        exit(-1);
    }
    
    // 꼬리는 꼬리가 가르키는 이전데이터를 가르키고 꼬리가 가르키던 데이터 삭제
    pdeq->tail = pdeq->tail->prev;
    free(rnode);
    
    // 덱에 데이터가 없으면 머리 초기화
    // 데이터가 있을경우 덱의 꼬리가 가르키는 다음데이터는 없음
    if(pdeq->tail == NULL)
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;
    
    return rdata;
}

Data DQGetFirst(Deque * pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!");
        exit(-1);
    }
    
    return pdeq->head->data;
}

Data DQGetLast(Deque * pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("Deque Memory Error!");
        exit(-1);
    }
    
    return pdeq->tail->data;
}

