// top view of binary tree is done by vertical graph traversal
/*
step:-1 when you draw the vertical line from each nodes form top to bottom you see there there will points lies on the line
step:-2 the last  point at each line will be visible from bottom
step:-3 the points at begining are visible from top side (top view)

step:-4 how can we track the point -----> we mark the line left from  root node by decreasing the value by -1 and right side by +1
step:-5 use queue to with pair to keep track of {node, line};
step:-6 use map to update the points value and the line value (e.g current line = pre_line +- 1 (left or right))

for top view do not update the points  in map because at the begin of line points are visible from top so it can't be update 
*/

#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<map>

using namespace std;

struct Node{
    Node * left;
    Node* right;
    int data;
};


Node* newNode(int data){
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

Node* creating_BinaryTree(vector<int> & array, int start_index, int end){
    //level order inseration

    Node* root = nullptr;
    if(start_index < end){
        root = newNode(array[start_index]);

        root->left = creating_BinaryTree(array, 2 * start_index + 1, end);
        // insert right child
        root->right = creating_BinaryTree(array, 2 * start_index + 2, end);
    }
}

class Solution{
public:
    vector<int> top_view(Node* root){
        vector<int> result;
        map<int, int> line_value;
        queue<pair<Node*, int>> node_line;

        node_line.push({root, 0});

        while(!node_line.empty()){
            Node* temp = node_line.front().first;
            int line_no = node_line.front().second;

            if(line_value.find(line_no) == line_value.end()){
                line_value[line_no] = temp->data;
            }

            if(root->left){
                node_line.push({root->left, line_no -1});
            }
            if(root->right){
                node_line.push({root->right, line_no+1});
            }
        }
        for(auto  i : line_value){
            result.push_back(i.second);
        }
    }
};

int main(){
    vector<int> array;
    //call the function for creating the binary tree;
    cout<<"enter the total nodes in binary tree"<<endl;
    

}