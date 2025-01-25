#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class node {
public:
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

node* insertInLL(node* head, int data) {
    if (head == nullptr) {
        return new node(data);
    }
    node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = new node(data);
    return head;
}

node* reverseLL(node* head) {
    node* prev = nullptr;
    node* curr = head;
    node* next = nullptr;

    while (curr != nullptr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    node* head = nullptr;

    for (int i = 0; i < arr.size(); i++) {
        head = insertInLL(head, arr[i]);
    }

    head = reverseLL(head);

    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    return 0;
}
