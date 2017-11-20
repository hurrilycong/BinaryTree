/*
* 二叉树的实现，包括二叉搜索树，二叉平衡树，红黑树
*/

#include "AvlTree.h"
#include "BiTNodeDef.h"
#include <iostream>
#include <queue>

AvlTree::AvlTree()
{
    m_root = NULL;
}

AvlTree::AvlTree(const AvlTreeNode bt)
{
    m_root = bt;
}

void AvlTree::_delete_pointer(AvlTNode *&node)
{
    if(NULL == node)
    {
        return ;
    }
    _delete_pointer(node->lchild);
    _delete_pointer(node->rchild);
    delete node;
}

AvlTree::~AvlTree()
{
    if(NULL != m_root)
    {
        _delete_pointer(m_root);
    }
}

void AvlTree::_preOrderTraverse(AvlTreeNode node)
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

int AvlTree::preOrderTraverse()
{
    if(NULL == m_root)
    {
        return -1;
    }
    _preOrderTraverse(m_root);

    return 0;
}

void AvlTree::_inOrderTraverse(AvlTreeNode node)
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

int AvlTree::inOrderTraverse()
{
    if (NULL == m_root)
    {
        return -1;
    }
    _inOrderTraverse(m_root);

    return 0;
}

void AvlTree::_postOrderTraverse(AvlTreeNode node)
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

int AvlTree::postOrderTraverse()
{
    if (NULL == m_root)
    {
        return -1;
    }
    _postOrderTraverse(m_root);

    return 0;
}
/*
* @return   0 not found
            1 found
*/
int AvlTree::findNode(AvlTreeNode tree, int data, AvlTreeNode parent, AvlTNode *&self)
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

int AvlTree::getHeight(AvlTreeNode self)
{
    if(!self)
    {
        return 0;
    }
    else
    {
        return self->height;
    }
}

int AvlTree::getMax(int a, int b)
{
    return (a > b) ? a : b;
}

void AvlTree::_LL_rotate(AvlTreeNode &node)
{
    AvlTreeNode temp = node->lchild;
    node->lchild = temp->rchild;
    temp->lchild = node;

    node->height = getMax(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    temp->height = getMax(getHeight(temp->lchild), getHeight(temp->rchild)) + 1;

    node = temp;
}

void AvlTree::_RR_rotate(AvlTreeNode &node)
{
    AvlTreeNode temp = node->rchild;
    node->rchild = temp->lchild;
    temp->lchild = node;

    node->height = getMax(getHeight(node->lchild), getHeight(node->rchild)) + 1;
    temp->height = getMax(getHeight(temp->lchild), getHeight(node->rchild)) + 1;

    node = temp;
}

void AvlTree::_LR_rotate(AvlTreeNode &node)
{
    _LL_rotate(node);
    _RR_rotate(node);
}

void AvlTree::_RL_rotate(AvlTreeNode &node)
{
    _RR_rotate(node);
    _LL_rotate(node);
}

/*
* @return   0 insert successful
            -1 not insert
*/
int AvlTree::_insert_node(AvlNode *&node, int key)
{
    AvlTreeNode self;
    if(!node)
    {
        AvlTreeNode node = new AvlTNode();
        node->lchild = NULL;
        node->rchild = NULL;
        node->data = key;
        node->height = 1;
        m_root = node;
        return 0;
    }
    else if(findNode(node, key, NULL, self))
    {
        return -1;
    }
    else if(key < node->data)
    {
        if(_insert_node(node->lchild, key))
        {
            return -1;
        }
        else
        {
            node->height = getMax(getHeight(node->rchild), getHeight(node->lchild)) + 1;
            if(2 == (getHeight(node->lchild) - getHeight(node->rchild)))
            {
                if(getHeight(node->lchild->lchild) > getHeight(node->lchild->rchild))
                {
                    _LL_rotate(node);
                }
                else
                {
                    _LR_rotate(node);
                }
            }
        }
        return 0;
    }
    else
    {
        if(_insert_node(node->rchild, key))
        {
            return -1;
        }
        else
        {
            node->height = getMax(getHeight(node->rchild), getHeight(node->lchild)) + 1;
            if(2 == (getHeight(node->rchild) - getHeight(node->lchild)))
            {
                if(getHeight(node->rchild->lchild) > getHeight(node->rchild->rchild))
                {
                    _RL_rotate(node);
                }
                else
                {
                    _RR_rotate(node);
                }
            }
        }
        return 0;
    }
}

int AvlTree::insert_node(int key)
{
    if(_insert_node(m_root, key))
    {
        std::cout << "insert node to AvlTree failed for key " << key <<std::endl;
        return -1;
    }
    //getMinHeight();
    return 0;
    // AvlTNode *self;
    // if(!findNode(m_root, key, NULL, self))
    // {
    //     AvlTreeNode node = new AvlTNode();
    //     node->lchild = NULL;
    //     node->rchild = NULL;
    //     node->data = key;
    //     node->height = getHeight(AvlTreeNode self) + 1;
    //     if(NULL == self)
    //     {
    //         m_root = node;
    //     }
    //     else if(self->data > key)
    //     {
    //         self->lchild = node;
    //     }
    //     else
    //     {
    //         self->rchild = node;
    //     }
    //     return 0;
    // }
    // return -1;
}

/*
* @return 获得二叉树的根
*/
AvlTreeNode AvlTree::getRoot()
{
    return m_root;
}

int AvlTree::delete_node(int key)
{
    AvlTreeNode self = NULL;
    AvlTreeNode p = NULL;
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
            AvlTreeNode q;
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

int AvlTree::findMaxValue(int &data)
{
    AvlTreeNode p = m_root;
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

int AvlTree::findMinValue(int &data)
{
    AvlTreeNode p = m_root;
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

void AvlTree::_levelTraverse(AvlTreeNode node)
{
    if(NULL == node)
    {
        return ;
    }
    else
    {
        std::queue<AvlTreeNode> que;
        que.push(node);
        while(!que.empty())
        {
            AvlTreeNode p = que.front();
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
}

int AvlTree::levelTraverse()
{
    if(NULL == m_root)
    {
        return 0;
    }
    else
    {
        _levelTraverse(m_root);
        return 0;
    }
}