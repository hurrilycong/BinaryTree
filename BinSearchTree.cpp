/*
* 二叉树的实现，包括二叉搜索树，二叉平衡树，红黑树
*/

#include "BinSearchTree.h"
#include "BiTNodeDef.h"
#include <iostream>
#include <queue>

BinSearchTree::BinSearchTree()
{
    m_root = NULL;
}

BinSearchTree::BinSearchTree(const BiTree bt)
{
    m_root = bt;
}

void BinSearchTree::_delete_pointer(BiNode *&node)
{
    if(NULL == node)
    {
        return ;
    }
    _delete_pointer(node->lchild);
    _delete_pointer(node->rchild);
    delete node;
}

BinSearchTree::~BinSearchTree()
{
    if(NULL != m_root)
    {
        _delete_pointer(m_root);
    }
}

void BinSearchTree::_preOrderTraverse(BiTree node)
{
    std::cout << node->data << " ";
    if(node->lchild != NULL)
    {
        _preOrderTraverse(node->lchild);
    }
    if(node->rchild != NULL)
    {
        _preOrderTraverse(node->rchild);
    }
}

int BinSearchTree::preOrderTraverse()
{
    if(NULL == m_root)
    {
        return -1;
    }
    _preOrderTraverse(m_root);

    return 0;
}

void BinSearchTree::_inOrderTraverse(BiTree node)
{
    if (node->lchild != NULL)
    {
        _inOrderTraverse(node->lchild);
    }
    std::cout << node->data << " ";
    if (node->rchild != NULL)
    {
        _inOrderTraverse(node->rchild);
    }
}

int BinSearchTree::inOrderTraverse()
{
    if (NULL == m_root)
    {
        return -1;
    }
    _inOrderTraverse(m_root);

    return 0;
}

void BinSearchTree::_postOrderTraverse(BiTree node)
{
    if (node->lchild != NULL)
    {
        _postOrderTraverse(node->lchild);
    }
    if (node->rchild != NULL)
    {
        _postOrderTraverse(node->rchild);
    }
    std::cout << node->data << " ";
}

int BinSearchTree::postOrderTraverse()
{
    if (NULL == m_root)
    {
        return -1;
    }
    _postOrderTraverse(m_root);

    return 0;
}

int BinSearchTree::findNode(BiTree tree, int data, BiTree parent, BiTNode *&self)
{
    if(NULL == tree)
    {
        self = parent;
        return 0;
    }
    else if(tree->data == data)
    {
        self = tree;
        return 1;
    }
    else if(tree->data > data)
    {
        return findNode(tree->lchild, data, tree, self);
    }
    else
    {
        return findNode(tree->rchild, data, tree, self);
    }
}

int BinSearchTree::insert_node(int key)
{
    BiTNode *self;
    if(!findNode(m_root, key, NULL, self))
    {
        BiTree node = new BiNode();
        node->lchild = NULL;
        node->rchild = NULL;
        node->data = key;
        if(NULL == self)
        {
            m_root = node;
        }
        else if(self->data > key)
        {
            self->lchild = node;
        }
        else
        {
            self->rchild = node;
        }
        return 0;
    }
    return -1;
}

/*
* @return 获得二叉树的根
*/
BiTree BinSearchTree::getRoot()
{
    return m_root;
}

int BinSearchTree::delete_node(int key)
{
    BiTree self = NULL;
    BiTree p = NULL;
    if(findNode(m_root, key, NULL, self))
    {
        if(NULL == self)
        {
            return 0;
        }
        if(NULL == self->rchild)
        {
            p = self;
            self = self->lchild;
            delete p;
        }
        else if(NULL == self->lchild)
        {
            p = self;
            self = self->rchild;
            delete p;
        }
        else
        {
            BiTree q;
            p = self->lchild;
            while(p->rchild)
            {
                q = p;
                p = p->rchild;
            }
            self->data = p->data;
            if(p != q)
            {
                q->lchild = p->rchild;
            }
            else
            {
                q->rchild = p->lchild;
            }
            delete p;
        }
    }
}

int BinSearchTree::findMaxValue(int &data)
{
    BiTree p = m_root;
    if(NULL == p)
    {
        return -1;
    }
    while(p->rchild)
    {
        p = p->rchild;
    }
    data = p->data;

    return 0;
}

int BinSearchTree::findMinValue(int &data)
{
    BiTree p = m_root;
    if (NULL == p)
    {
        return -1;
    }
    while (p->lchild)
    {
        p = p->lchild;
    }
    data = p->data;

    return 0;
}

int BinSearchTree::_get_deepth(BiTree node)
{
    if(NULL == node)
    {
        return 0;
    }
    else
    {
        int l = _get_deepth(node->lchild);
        int r = _get_deepth(node->rchild);
        return (l > r) ? (l+1) : (r+1);
    }
}

int BinSearchTree::get_max_deepth()
{
    if(NULL != m_root)
    {
        int deep = 1;
        return _get_deepth(m_root);
    }
    else
    {
        return 0;
    }
}

int BinSearchTree::_get_node_num(BiTree node)
{
    if(NULL != node)
    {
        int l = _get_node_num(node->lchild);
        int r = _get_node_num(node->rchild);
        return l+r+1;
    }
    else
    {
        return 0;
    }
}

int BinSearchTree::get_node_num()
{
    if(NULL == m_root)
    {
        return 0;
    }
    else
    {
        return _get_node_num(m_root);
    }
}

int BinSearchTree::_level_traverse(BiTree node)
{
    if(NULL == node)
    {
        return 0;
    }
    else
    {
        std::queue<BiTree> que;
        que.push(node);
        while(!que.empty())
        {
            BiTree p = que.front();
            std::cout<<p->data<<" ";
            que.pop();
            if(p->lchild)
            {
                que.push(p->lchild);
            }
            if(p->rchild)
            {
                que.push(p->rchild);
            }
        }
    }
    return 1;
}

int BinSearchTree::levelTraverse()
{
    if(NULL == m_root)
    {
        return 0;
    }
    else
    {
        _level_traverse(m_root);
        return 0;
    }
}