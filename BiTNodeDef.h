#ifndef _BI_T_NODE_H_
#define _BI_T_NODE_H_

#include <iostream>

typedef struct BiNode
{
    int data;
    BiNode *rchild;
    BiNode *lchild;
    BiNode(BiNode *r, BiNode *l, int key)
    {
        rchild = r;
        lchild = l;
        data = key;
    }
    BiNode()
    {
        rchild = NULL;
        lchild = NULL;
        data = 0;
    }
}BiTNode, *BiTree;

#endif