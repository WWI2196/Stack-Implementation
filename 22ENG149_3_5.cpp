#include <iostream>
#include <sstream>
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

		cout << "Stack: ";
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void reverse() {

		if (top == nullptr) {
			cout << "Stack is empty." << endl;
			return;
		}

		Node* prev = nullptr;
		Node* temp = top;
		Node* next = nullptr;

		while (temp != nullptr) {
			next = temp->next;  // Save next
			temp->next = prev;  // Reverse current node's pointer
			prev = temp;        // Move pointers one position ahead.
			temp = next;
		}
		top = prev;
	}

	void count() const {
		cout <<"Number of elements in the stack is: " << size << endl;
	}

	void deleteStack() {

		while (top != nullptr) {
			Node* temp = top->next;
			delete top;
			top = temp;
		}
		size = 0;
	}
};

	

int main()
{
	int numberOfElements,value;

	cout << "Enter the number of elements: ";
	cin >> numberOfElements;
	cin.ignore();  // To ignore the newline character after the number of TreeTreeTreeNodes

	Stack stack;

	cout << "Enter the values separated by space: ";

	string input;
	getline(cin, input);  // Read the entire line of input

	stringstream inputStream(input);

	for (int i = 0; i < numberOfElements; i++) {
		inputStream >> value;  // Extract each number from the stringstream
		stack.push(value);
	}

	stack.print();
	stack.reverse();
	stack.print();

	stack.pop();
	stack.count();
	stack.print();

	return  0;
}

