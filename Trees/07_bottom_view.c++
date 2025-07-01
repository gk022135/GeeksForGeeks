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


// Node* newNode(int data){
//     Node* node = (Node*)malloc(sizeof(Node));
//     node->data = data;
//     node->left = node->right = NULL;
//     return (node);
// }

// Node* creating_BinaryTree(vector<int> & array, int start_index, int end){
//     //level order inseration

//     Node* root = nullptr;
//     if(start_index < end){
//         root = newNode(array[start_index]);

//         root->left = creating_BinaryTree(array, 2 * start_index + 1, end);
//         // insert right child
//         root->right = creating_BinaryTree(array, 2 * start_index + 2, end);
//     }
// }

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

            // if(line_value.find(line_no) == line_value.end()){
            //     line_value[line_no] = temp->data;
            // }
            line_value[line_no] = temp->data;  //same code only here change, wihtout if condition

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