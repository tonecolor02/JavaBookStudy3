#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    
    // 추가된 노드의 다음값은 없음
    newNode->next = NULL;
    
    // 추가된 노드의 데이터 저장
    newNode->data = data;
    
    // 데이터가 없을 경우 꼬리와 머리는 새로 추가된 노드를 가르킴
    if(QIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    // 데이터가 있을경우 
    else
    {
        pq->rear->next = newNode;  // 마지막 노드가 새 노드를 가르킴
        pq->rear = newNode;    // 꼬리가 새 노드를 가르킴
    }
}

Data Dequeue(Queue * pq)
{
    Node * delNode;
    Data retData;
    
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    
    // 머리가 가르키는 데이터를 삭제
    delNode = pq->front;
    
    // 반환할 데이터를 임시 저장
    retData = delNode->data;
    
    // 머리는 머리가 가르키던 데이터의 다음 데이터를 가르킴
    pq->front = pq->front->next;
    
    // 데이터 삭제하고 반환
    free(delNode);
    return retData;
}

Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue Memory Error!");
        exit(-1);
    }
    
    return pq->front->data;
}

