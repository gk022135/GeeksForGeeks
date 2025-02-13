// inverting bianry tree its like make mirror of binary tree

/*
Approach 01:- O(n) time and O(h) space ---> recursion post order Traversal
Approach 02:- O(n) time and O(n) space ---> recursion
*/

/*
Pre-Order --->  cout left right
Inorder   --->  left cout right
Post-order ---> left right cout
*/

#include <iostream>
#include <vector>
#include <queue>

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

// mirror of binary tree function

void mirrorBST(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    mirrorBST(root->left);
    mirrorBST(root->right);

    swap(root->left, root->right); // i do not swap value because when i swap value the tree remain same but value are change
}

void LevelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        cout << "N";
        return;
    }

    queue<Node *> q;
    q.push(root);


    while (!q.empty())
    {
        Node* tempRoot = q.front();
        q.pop();

        if(tempRoot == nullptr){
            cout<<"N ";
            continue;
        }
        cout<<tempRoot->data<<" ";

        q.push(tempRoot -> left);
        q.push(tempRoot -> right);
    }
}


int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    mirrorBST(root);
    LevelOrderTraversal(root);

    return 0;
}