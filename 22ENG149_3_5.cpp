#include <iostream>
#include <sstream>
using namespace std;

class Node{ // Node class for the Stack
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
	Stack() { // Constructor to initialize the stack
		top = nullptr;
		size = 0;
	}

	void push(int data) { // Function to add elements to the stack
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

	void pop() { // Function to remove elements from the stack
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

	void print() { // Function to display the elements of the stack
		Node* temp = top;

		cout << "Stack: ";
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}

	void reverse() { // Function to reverse the elements of the stack

		if (top == nullptr) {
			cout << "Stack is empty." << endl;
			return;
		}

		Node* prev = nullptr;
		Node* temp = top;
		Node* next = nullptr;

		while (temp != nullptr) {
			next = temp->next;  
			temp->next = prev; 
			prev = temp;       
			temp = next;
		}
		top = prev;
	}

	void count() const { // Function to display the number of elements in the stack
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

