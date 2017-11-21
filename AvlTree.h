#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include "BiTNodeDef.h"

class AvlTree
{
    public:
        AvlTree();
        AvlTree(const AvlTreeNode bt);
        ~AvlTree();
        int preOrderTraverse();
        int inOrderTraverse();
        int postOrderTraverse();
        int levelTraverse();
        int insert_node(int data);
        int delete_node(int data);
        int findMaxValue(int &data);
        AvlTreeNode findMaxNode(AvlTreeNode node);
        int findMinValue(int &data);
        AvlTreeNode findMinNode(AvlTreeNode node);
        int findNode(AvlTreeNode tree, int key, AvlTreeNode parent, AvlTNode *&self);
        int getHeight(AvlTreeNode self);
        AvlTreeNode getRoot();
    private:
        AvlTNode *m_root;
        void _preOrderTraverse(AvlTreeNode node);
        void _inOrderTraverse(AvlTreeNode node);
        void _postOrderTraverse(AvlTreeNode node);
        void _levelTraverse(AvlTreeNode node);
        int _insert_node(AvlTNode *&node, int key);
        int _delete_node(AvlTNode *&node, int key);
        void _delete_pointer(AvlTNode *&node);
        void _LL_rotate(AvlTNode *&node);
        void _LR_rotate(AvlTNode *&node);
        void _RL_rotate(AvlTNode *&node);
        void _RR_rotate(AvlTNode *&node);
        int getMax(int a, int b);
};

#endif