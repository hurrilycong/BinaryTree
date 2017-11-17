#ifndef _BI_T_NODE_H_
#define _BI_T_NODE_H_

#include <iostream>

//binary search tree
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

//avl tree
typedef struct AvlNode
{
    int data;
    int height;
    AvlNode *lchild;
    AvlNode *rchild;
    AvlNode(AvlNode *r, AvlNode *l, int key, int h)
    {
        lchild = l;
        rchild = r;
        data = key;
        height = h;
    }
    AvlNode()
    {
        lchild = NULL;
        rchild = NULL;
        data = 0;
        height = 1;
    }
}AvlTNode, *AvlTreeNode;

#endif