#include <stdio.h>
#include "Binarytree.h"

int main(void)
{
    
    // 트리노드를 생성함
    // 새로 만들어진 트리노드가 가르키는 left,right 방향은 null 로 초기화
    BTreeNode * bt1 = MakeBTreeNode();
    BTreeNode * bt2 = MakeBTreeNode();
    BTreeNode * bt3 = MakeBTreeNode();
    BTreeNode * bt4 = MakeBTreeNode();
    
    // 첫번째 만든 트리노드에 데이터 1,2,3,4 집어 넣는다
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);
    
    // 1번트리 왼쪽아래에 2번 트리 연결
    MakeLeftSubTree(bt1, bt2);
    
    // 1번트리 오른쪽 아래에 3번트리 연결
    MakeRightSubTree(bt1, bt3);
    
    // 2번트리 왼쪽에 4번트리 연결
    MakeLeftSubTree(bt2, bt4);
    
    // 1번트리의 왼쪽아래 연결된 트리의 데이터를 가져옴 2
    printf("%d \n",
           GetData(GetLeftSubTree(bt1)));
    
    // 2번트리 왼쪽아래의 데이터를 가져온후 가져온 2번트리의 데이터에 왼쪽 아래 4번트리데어티를 가져옴
    printf("%d \n",
           GetData(GetLeftSubTree(GetLeftSubTree(bt1))));
    return 0;
}



