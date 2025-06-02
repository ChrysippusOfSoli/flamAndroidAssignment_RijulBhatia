#include <vector>
#include <iostream>

class MyHashMap {
private:
	struct Node {
		int key;
		int value;
		Node* next;

		Node(int k, int v) : key(k), value(v), next(nullptr){}
	};

	static const int BUCKET_SIZE = 1000;
	std::vector<Node*> buckets;

	// has func is simple modulo with prime number
	int hash(int key) {
		return key % BUCKET_SIZE;
	}

	Node* findNode(int bucketIndex, int key) {
		Node* current = buckets[bucketIndex];
		while (current != nullptr) {
			if (current->key == key) {
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}

public:

	MyHashMap() {
		buckets.resize(BUCKET_SIZE, nullptr);
	}
	~MyHashMap() {
		for (int i = 0; i < BUCKET_SIZE; i++) {
			Node* current = buckets[i];
			while (current != nullptr) {
				Node* temp = current;
				current = current->next;
				delete temp;
			}
		}
	}

	void put(int key, int value) {
		int bucketIndex = hash(key);
		Node* existingNode = findNode(bucketIndex, key);

		if (existingNode != nullptr) {
			existingNode->value = value;
		}
		else {
			Node* newNode = new Node(key, value);
			newNode->next = buckets[bucketIndex];
			buckets[bucketIndex] = newNode;
		}
	}

	int get(int key) {
		int bucketIndex = hash(key);
		Node* node = findNode(bucketIndex, key);

		if (node != nullptr) {
			return node->value;
		}
		return -1;
	}

	void remove(int key) {
		int bucketIndex = hash(key);
		Node* current = buckets[bucketIndex];
		Node* prev = nullptr;

		while (current != nullptr) {
			if (current->key == key) {
				if (prev == nullptr) {
					buckets[bucketIndex] = current->next;
				}
				else {
					prev->next = current->next;
				}
				delete current;
				return;
			}
			prev = current;
			current = current->next;
		}
	}

};

//int main() {
//
//}