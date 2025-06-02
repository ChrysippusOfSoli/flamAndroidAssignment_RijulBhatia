// assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <unordered_map>
#include <iostream>

class LRUCache {
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;

        Node(int k = 0, int v = 0) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    std::unordered_map<int, Node*> cache; // key to node ptr
    Node* head; // most receantly used
    Node* tail; // least receantly used

    void addNode(Node* node) {
        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(Node* node) {
        removeNode(node);
        addNode(node);
    }

    Node* removeTail() {
        Node* lastNode = tail->prev;
        removeNode(lastNode);
        return lastNode;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }

    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()) {
            return -1;
        }

        Node* node = it->second;
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()) {
            Node* node = it->second;
            node->value = value;
            moveToHead(node);
        }
        else {
            Node* newNode = new Node(key, value);
            if (cache.size() >= capacity) {
                Node* tail_node = removeTail();
                cache.erase(tail_node->key);
                delete tail_node;
            }

            addNode(newNode);
            cache[key] = newNode;
        }
    }
};

//int main()
//{
//    
//}

