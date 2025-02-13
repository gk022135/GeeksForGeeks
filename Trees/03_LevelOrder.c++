//level order traversal of treee using queue

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Node{
    public:
      int data;
      Node* right;
      Node* left;

      Node(int data){
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
      }
       
};

vector<vector<int>> BfsQueueTraversal(Node* root){
    // base if root became null return an empty vector

    if(root == nullptr){
        return {};
    }

    queue<Node*>q;

    q.push(root);
    int currentLevel = 0;

    vector<vector<int>>result;

    while(!q.empty()){
        int len = q.size();

        for(int i =0; i<len; i++){
            Node* tempRoot = q.front();
            q.pop();

            result[currentLevel].push_back(tempRoot->data);

            if(tempRoot ->left != nullptr){
                q.push(tempRoot->left);
            }
            if(tempRoot ->right != nullptr){
                q.push(tempRoot -> right);
            }
        }
        currentLevel++;
    }
    return result;

}

int main(){
    Node* root = new Node(1);
    
    root->left = new Node(3);
    root->right = new Node(2);

    root ->right->left = new Node(4);
    root->right->right = new Node(5);

    root->right->right->right = new Node(6);

    vector<vector<int>> resultQueue = BfsQueueTraversal(root);
   
    cout<<"[";
    for(auto i: resultQueue){
        cout<<"[";
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<"],";
    }
    cout<<"]\n";

    return 0;
}