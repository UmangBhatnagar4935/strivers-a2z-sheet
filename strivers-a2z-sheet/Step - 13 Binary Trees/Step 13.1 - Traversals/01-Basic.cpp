
/* gfg article

A tree is a popular data structure that is non-linear in nature.
 Unlike other data structures like an array, stack, queue, and 
 linked list which are linear in nature, a tree represents a hierarchical structure.
  The ordering information of a tree is not important. A tree contains nodes and 2 pointers.
   These two pointers are the left child and the right child of the parent node. Let us understand
    the terms of tree in detail.

Root: The root of a tree is the topmost node of the tree that has no parent node. There is only one root node in every tree.
Parent Node:  The node which is a predecessor of a node is called the parent node of that node.
Child Node: The node which is the immediate successor of a node is called the child node of that node.
Sibling: Children of the same parent node are called siblings.
Edge: Edge acts as a link between the parent node and the child node.
Leaf: A node that has no child is known as the leaf node. It is the last node of the tree. There can be multiple leaf nodes in a tree.
Subtree: The subtree of a node is the tree considering that particular node as the root node.
Depth: The depth of the node is the distance from the root node to that particular node.
Height: The height of the node is the distance from that node to the deepest node of that subtree.
Height of tree: The Height of the tree is the maximum height of any node. This is the same as the height of the root node.
Level: A level is the number of parent nodes corresponding to a given node of the tree.
Degree of node:  The degree of a node is the number of its children.
NULL: The number of NULL nodes in a binary tree is (N+1), where N is the number of nodes in a binary tree.

*/

#include <bits/stdc++.h>
using namespace std;

/*
1 - Read the problem statements
2 - think about which data strucute and algorithm,we can use
3 - apply algorithm/dsa
4-  dry run
5 - code variatioin
6- complexity both of


Approaches -
they want maximum number of nodes on level if of binary tree

case : 1
input : 5
output 16

case : 2
input : 1
output : 1


according to text cases,we can clearly understand
if n = 1 then we have only 1 node
if m > 1 then we have 2 power n-1 node

*/

class Solution
{
public:
    int countNodes(int i)
    {
        // start code
        if (i == 1)
        {
            return 1;
        }
        return pow(2, i - 1);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i;
        cin >> i;
        Solution ob;
        int res = ob.countNodes(i);

        cout << res;
        cout << "\n";
    }
}
