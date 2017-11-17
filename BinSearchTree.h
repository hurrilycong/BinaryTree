#ifndef _BIN_SEARCH_TREE_H_
#define _BIN_SEARCH_TREE_H_

#include "BiTNodeDef.h"

class BinSearchTree
{
    public:
      BinSearchTree();
      BinSearchTree(const BiTree bt);
      ~BinSearchTree();
      int preOrderTraverse();
      int inOrderTraverse();
      int postOrderTraverse();
      int levelTraverse();
      int insert_node(int data);
      int delete_node(int data);
      int findMaxValue(int &data);
      int findMinValue(int &data);
      int get_max_deepth();
      int get_node_num();
      int findNode(BiTree tree, int key, BiTree parent, BiTNode *&self);
      BiTree getRoot();
    private:
      BiTree m_root;
      void _preOrderTraverse(BiTree node);
      void _inOrderTraverse(BiTree node);
      void _postOrderTraverse(BiTree node);
      void _delete_pointer(BiNode *&node);
      int _get_deepth(BiTree node);
      int _get_node_num(BiTree node);
      int _level_traverse(BiTree node);
};

#endif