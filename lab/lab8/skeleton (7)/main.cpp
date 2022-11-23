#include <iostream>
#include <vector>

#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char const *argv[])
{
    int testcase;
    std::cin >> testcase; // 1 or 2 or 3

    if (testcase != 1 && testcase != 2 && testcase != 3)
    {
        std::cout << "test case should be 1, 2 or 3! " << testcase << " found\n";
        return 0;
    }
    std::cout << "LAB 7: BST\n\n";

    if (testcase == 1)      //Test Task 1
    {
        BinarySearchTree *tree1 = new BinarySearchTree(1);
        int nodes[9] = {5, 3, 4, 10, 9, 7, -2, -5, -3};
        for (int i = 0; i < 9; i++)
            tree1->add(nodes[i]);

        BinarySearchTree *tree2 = new BinarySearchTree(1);
        for (int j = 0; j < 9; j++)
            tree2->add(nodes[j]);
        
        std::cout << "The first BST:" << std::endl;
        tree1->print(0);
        std::cout << "The second BST:" << std::endl;
        tree2->print(0);
        std::cout << "Whether they are the same:" << tree1->isSame(tree2) << std::endl;
        std::cout << "Whether they are the same:" << tree2->isSame(tree1) << std::endl;

        BinarySearchTree *tree3 = new BinarySearchTree(2);
        int nodes2[9] = {5, 3, 4, 10, 9, 7, -2, -3, -5};
        for (int i = 0; i < 9; i++)
            tree3->add(nodes2[i]);

        std::cout << "The first BST:" << std::endl;
        tree1->print(0);
        std::cout << "The second BST:" << std::endl;
        tree3->print(0);
        std::cout << "Whether they are the same:" << tree1->isSame(tree3) << std::endl;

        BinarySearchTree *tree4 = new BinarySearchTree(2);
        int nodes3[8] = {5, 3, 4, 10, 9, 7, -2, -5};
        for (int i = 0; i < 8; i++)
            tree4->add(nodes3[i]);

        std::cout << "The first BST:" << std::endl;
        tree1->print(0);
        std::cout << "The second BST:" << std::endl;
        tree4->print(0);
        std::cout << "Whether they are the same:" << tree1->isSame(tree4) << std::endl;
        delete tree1;
        delete tree2;
        delete tree3;
        delete tree4;
        return 0;
    }

    else if (testcase == 2)     //Test Task 1&2
    {
        BinarySearchTree *tree1 = new BinarySearchTree(1);
        int nodes[9] = {5, 3, 4, 10, 9, 7, -2, -5, -3};
        for (int i = 0; i < 9; i++)
            tree1->add(nodes[i]);

        std::cout << "The existing BST:" << std::endl;
        tree1->print(0);

        BinarySearchTree *tree2 = new BinarySearchTree(0);
        tree1->buildNewBST(tree2, -2);
        std::cout << "Different tree of the first tree with the new root -2:" << std::endl;
        tree2->print(0);

        BinarySearchTree *tree3 = new BinarySearchTree(0);
        tree1->buildNewBST(tree3, 3);
        std::cout << "Different tree of the first tree with the new root 3:" << std::endl;
        tree3->print(0);

        BinarySearchTree *tree4 = new BinarySearchTree(0);
        tree3->buildNewBST(tree4, 4);
        std::cout << "Different tree of the first tree with the new root 4:" << std::endl;
        tree4->print(0);

        delete tree1;
        delete tree2;
        delete tree3;
        delete tree4;
        
        return 0;
    }
}
