#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack {
private:
    Node* top;
	int size;
public:
    Stack() {
        top = nullptr;
        size = 0;
    }

    void push(int data) {
		Node* newNode = new Node(data);

		if (top == nullptr) {
			top = newNode;
		}
		else {
			newNode->next = top;
			top = newNode;
		}
		size++;
	};

    void pop() {
		if (top == nullptr) {
			cout << "Stack is empty" << endl;
		}
		else {
			Node* temp = top;
			top = top->next;
			delete temp;
			size--;
		}
	};

	void print() {
		Node* temp = top;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void reverse(){


		/*Node* prev = nullptr;
		Node* current = top;
		Node* next = nullptr;

		while (current != nullptr) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		top = prev;*/
	};

	bool isEmpty() {
		return top == nullptr;
	};

	int getSize() {
		return size;
	};

int main()
{
    cout << "Hello World!\n";
}

