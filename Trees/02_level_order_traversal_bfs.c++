/*
The main idea of level order traversal is to traverse all the nodes of a lower level before moving to any of the nodes of a higher level. This can be done in any of the following ways: 

Approach
1. using stack (Recursion)
2. using queue (iteration)


*/

/*
<------- Using Stack (recursion) ------>

The idea is to traverse the tree recursively, passing the current node and its level, starting with the root at level 0. For each visited node, its value is added to the result array, by considering the value of current level as an index in the result array
*/

#include<iostream>
#include<vector>

using namespace std;

class node{
    public :
      int data;
      node *left;
      node* right;

      node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void levelOrderRec(node* root, int level, vector<vector<int>> &result){


    //base case if root became null ptr return 
    if(root == nullptr){
        return;
    }
//result is a vector<vector<int>>, where each inner vector stores the values of nodes at a particular level.

//res.size() represents the current number of levels recorded.
    if(result.size() <= level){
        //If level is greater than or equal to res.size(), it means we are visiting this level for the first time.
        result.push_back({});
    }
    result[level].push_back(root->data);

    levelOrderRec(root->left, level+1, result);
    levelOrderRec(root->right, level + 1, result);
}

vector<vector<int>> LevelOrderTraveresal(node * root){
    vector<vector<int>> result;

    levelOrderRec(root, 0, result);

    return result;
}

// main function or driver code 

int main(){
    node* root = new node(1);
    
    root->left = new node(3);
    root->right = new node(2);

    root ->right->left = new node(4);
    root->right->right = new node(5);

    root->right->right->right = new node(6);

    vector<vector<int>> res = LevelOrderTraveresal(root);

    cout<<"[";
    for(auto i: res){
        cout<<"[";
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"],";
    }
    cout<<"]";

    return 0;
}