//rotate the linked list by k left or right

#include<iostream>
#include<vector>

using namespace std;

class node{
    public:
     int data;
     node* next;

     node(int data){
        this->data = data;
        this->next = nullptr;
     }

};
node* insertInLL(node* where, int value){
    if(where == nullptr){
        return new node(value);
    }
    else
     where->next = new node(value);

     return where;
}
void printLL(node* head){
    node* temp = head;
    while (temp != nullptr)
    {
        cout<<temp->data<<", ";
        temp = temp->next;
    }
    
}

int main(){
    vector<int>arr = {1,2,3,4,5,6,7};

    node* head = new node(NULL);
    node* temp = head;

    for(int i=0; i<arr.size(); i++){
        temp = insertInLL(temp, arr[i]);
    }
    cout<<endl;
    printLL(head);
    cout<<endl;

    return 0;
}