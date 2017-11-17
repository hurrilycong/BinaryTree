#include <iostream>
#include "BinSearchTree.h"

int main()
{
    BinSearchTree tree;

    int a;
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
    std::cout<<"Max value of this tree is "<<a<<std::endl;

    return 0;
}