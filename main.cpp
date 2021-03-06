#include <iostream>
//#include "BinSearchTree.h"
#include "AvlTree.h"

int main()
{
    //BinSearchTree tree;

    int a;
    //check if its throws format exception
    AvlTree tree;
    while(std::cin>>a)
    {
        if(-1 == a)
        {
            break;
        }
        tree.insert_node(a);
    }
    tree.inOrderTraverse();
    std::cout<<std::endl;
    tree.preOrderTraverse();
    std::cout<<std::endl;
    tree.findMaxValue(a);
    std::cout<<std::endl;
    tree.levelTraverse();
    std::cout << "Max value of this tree is "<<a<<std::endl;
    std::cout << "input a number you want delete:" <<std::endl;
    std::cin >> a;
    tree.delete_node(a);
    tree.inOrderTraverse();
    //std::cout<<"the deepth of this tree is "<<tree.get_max_deepth()<<std::endl;
    //std::cout<<"the node num of this tree is "<<tree.get_node_num()<<std::endl;
    return 0;
}