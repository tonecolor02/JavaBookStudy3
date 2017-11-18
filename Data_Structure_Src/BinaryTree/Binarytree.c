#include <stdio.h>
#include <stdlib.h>
#include "Binarytree.h"

BTreeNode * MakeBTreeNode(void)
{
    BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

BTData GetData(BTreeNode * bt)
{
    return bt->data;
}

void SetData(BTreeNode * bt, BTData data)
{
    bt->data = data;
}

BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
    return bt->left;
}

BTreeNode * GetRightSubTree(BTreeNode * bt)
{
    return bt->right;
}

// 연결할 트리 두개를 가져온후 해당 방향에 연결한다
// 왼쪽 또는 오른쪽 방향에 데이터가 존재한다면 삭제한후에 트리노드를 연결한다
// 한번의 free함수 호출이 전부이기 때문에 삭제할 서브트리가 하나의 노드로 이뤄져 있다면 문제되지 않지만, 그렇지 않다면 메모리의 누수로 이어짐
// 즉 모든노드를 방문하여 free 함수를 호출해야 하는데 모든 노드를 방문하는 것을 순회라고 한다
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->left != NULL)
        free(main->left);
    
    main->left = sub;
}

void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->right != NULL)
        free(main->right);
    
    main->right = sub;
}
