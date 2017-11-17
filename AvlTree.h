#ifndef _AVL_TREE_H_
#define _AVL_TREE_H_

#include "BiTNodeDef.h"

class AvlTree
{
    public:
        AvlTree();
        AvlTree(const AvlTNode bt);
        ~AvlTree();
        int preOrderTraverse();
        int inOrderTraverse();
        int postOrderTraverse();
        int insert_node(int data);
        int delete_node(int data);
        int findMaxValue(int &data);
        int findMinValue(int &data);
        int findNode(AvlTreeNode tree, int key, AvlTreeNode parent, AvlTNode *&self);
        AvlTreeNode getRoot();
    private:
        AvlTNode *m_root;
        void _preOrderTraverse(AvlTreeNode node);
        void _inOrderTraverse(AvlTreeNode node);
        void _postOrderTraverse(AvlTreeNode node);
        void _insert_node(AvlTNode *&node, int key, int &taller);
        void _delete_node(AvlTNode *&node, int key, int &taller);
        void _delete_pointer(AvlTNode *&node);
        void _r_rotate(AvlTNode *&node);
        void _l_rotate(AvlTNode *&node);
}

#endif