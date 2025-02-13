//finding height of BST 
/*
1. using recursion  TC O(n) and SC O(h)
2. Level order Traversal using null Delimiter TC O(n) and SC O(n)
3. Level order Traversal without using null Delimete T O(n) and SC O(n);
*/


//aproach 01
/*
The idea is to recursively calculate the height of the left and the right subtrees of a node and then find height to the node as max of the heights of two children plus 1.
*/

// Approach 02
/*
If we take a closer look at the breadth first traversal, we can notice that after we process the last node of the current level, the queue contains all the nodes of next level. We use this property and insert a special NULL into the queue to indicate end of a level.
*/

#include<iostream>
#include<vector>
#include<math.h>
#include<queue>

using namespace std;


class Node{
    public:
      int data;
      Node* left;
      Node* right;

      Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int heightRecursion(Node* root){
    if(root == nullptr){
        return -1;
    }
    int leftHeight = heightRecursion(root->left);
    int RightHeight = heightRecursion(root -> right);

    return max(leftHeight,RightHeight) + 1;
}


int HeightLevelOrder(Node* root){
    if(root == nullptr) return 0;

    int depth = 0;
    queue<Node* >q;

    q.push(root);
    q.push(nullptr);

    while(!q.empty()){
        Node* tempRoot = q.front();
        q.pop();


        if(tempRoot == nullptr){
            depth++;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            if(tempRoot->left != nullptr){
                q.push(tempRoot->left);
            }
            if(tempRoot->right != nullptr){
                q.push(tempRoot->right);
            }
        }
    }
    return depth - 1;

}
int main(){
    Node* root = new Node(12);
    Node* temp = root;
    root->left = new Node(8);
    root->right = new Node(18);
    root->left-> left = new Node(5);
    root->left -> right = new Node(11);

    cout<<"height of tree with recursion "<<HeightLevelOrder(root)<<endl;
    root = temp;
    
    cout<<"height of tree with Level Order Traversal "<<HeightLevelOrder(root);
    cout<<endl;

    return 0;

}