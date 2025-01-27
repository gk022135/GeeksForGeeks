#include<iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    vector<int> key_val{2, 0};
    Node* left;
    Node* right;

    Node(int key, int value) {
        key_val[0] = key;
        key_val[1] = value;
        left = nullptr;
        right = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> lru_memory;  // Key-Node mapping for O(1) access
    Node* head;  // Dummy head of the doubly linked list
    Node* tail;  // Dummy tail of the doubly linked list

    void moveToFront(Node* node) {
        // Remove the node from its current position
        removeNode(node);
        // Add it to the front of the doubly linked list
        addToFront(node);
    }

    void removeNode(Node* node) {
        Node* prev = node->left;
        Node* next = node->right;

        if (prev) prev->right = next;
        if (next) next->left = prev;
    }

    void addToFront(Node* node) {
        node->right = head->right;
        node->left = head;

        if (head->right) head->right->left = node;
        head->right = node;

        if (tail->left == nullptr) {
            tail->left = node;
        }
    }

    void removeFromTail() {
        // Remove the least recently used node
        if (tail->left) {
            Node* lru = tail->left;
            lru_memory.erase(lru->key_val[0]);
            removeNode(lru);
            delete lru;
        }
    }

public:
    LRUCache(int cap) : capacity(cap) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->right = tail;
        tail->left = head;
    }

    int get(int key) {
        if (lru_memory.find(key) == lru_memory.end()) {
            return -1;  // Key not found
        }

        // Move the accessed node to the front of the doubly linked list
        Node* node = lru_memory[key];
        moveToFront(node);

        return node->key_val[1];
    }

    void put(int key, int value) {
        if (lru_memory.find(key) != lru_memory.end()) {
            // Key already exists; update its value and move it to the front
            Node* node = lru_memory[key];
            node->key_val[1] = value;
            moveToFront(node);
        } else {
            // Key doesn't exist; create a new node
            if (lru_memory.size() == capacity) {
                // If capacity is full, remove the least recently used node
                removeFromTail();
            }

            Node* newNode = new Node(key, value);
            addToFront(newNode);
            lru_memory[key] = newNode;
        }
    }
};


int main() {
    LRUCache cache(2);  // Create an LRU Cache with capacity 2

    cache.put(1, 10);   // Insert (1, 10)
    cache.put(2, 20);   // Insert (2, 20)
    cout << cache.get(1) << "\n"; // Output: 10 (key 1 accessed)
    cache.put(3, 30);   // Insert (3, 30), evict (2, 20) as capacity is 2
    cout << cache.get(2) << "\n"; // Output: -1 (key 2 not found)
    cache.put(4, 40);   // Insert (4, 40), evict (1, 10)
    cout << cache.get(1) << "\n"; // Output: -1 (key 1 not found)
    cout << cache.get(3) << "\n"; // Output: 30
    cout << cache.get(4) << "\n"; // Output: 40

    return 0;
}
