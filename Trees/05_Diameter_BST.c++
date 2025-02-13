/*
Diameter Of BST :-he diameter/width of a tree is defined as the number of edges on the longest path between any two nodes.

*/

/*
Approach -01:- Using Top Down Recursion - O(n^2) Time and O(h) Space
Approach -02:- Using Bottom Up Recursive - O(n) Time and O(h) Space

*/

/*
Approach 01:-
The idea is to recursively traverse the tree. For each node, find the height of left subtree and right subtree and compare the diameter (sum of height of left subtree + height of right subtree) with the maximum diameter.
*/

/*
Approach -02:-
The idea is to optimize the above approach by calculating the height in the same recursive function rather than calculating it separately.
*/

#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Approach -02
int DiameterOfBst(Node *root, int &res)
{
    if (root == nullptr)
    {
        return 0;
    }

    int LeftHeigth = DiameterOfBst(root->left, res);
    int RightHeigth = DiameterOfBst(root->right, res);

    res = max(res, LeftHeigth + RightHeigth);

    return 1 + max(LeftHeigth, RightHeigth);
}

int diameter(Node *root)
{
    int res = 0;
    DiameterOfBst(root, res);
    return res;
}

int main()
{

    Node *root = new Node(5);
    root->left = new Node(8);
    root->right = new Node(6);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(9);

    cout<<"diameter of BST: "<<diameter(root)<<endl;
    return 0;
}