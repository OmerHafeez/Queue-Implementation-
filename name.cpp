#include<iostream>
#include<limits>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
	Node(int a)
	{
		data = a;
		next = nullptr;
	}
};

class queue {
public:
	Node* front;
	queue()
	{
		front = nullptr;
	}
	Node* create_Node(int a)
	{
		Node* newNode = new Node(a);
		if (newNode == nullptr)
		{
			cout << "Node not created" << endl;
			return nullptr;
		}
		else
		{
			return newNode;
		}
	}

	bool isEmpty()
	{
		if (front == nullptr)
		{
			return true;
		}
		else
			return false;
	}

	int frontcheck()
	{
		if (front == nullptr)
		{
			cout << "Queue is empty" << endl;
			return front->data;
		}
		else
		{
			return front->data;
		}
	}

	int count_Nodes()
	{
		if (front == nullptr)
			return 0;
		else if (front->next == nullptr)
			return 1;
		else
		{
			int count = 0;

			Node* current = front;
			while (current->next != nullptr)
			{
				count++;
				current = current->next;
			}
			return count + 1;
		}
	}

	void enqueue()
	{
		int a;
		cout << "Enter the value you want to store" << endl;
		cin >> a;
		if (a)
		{
			Node* newNode = create_Node(a);
			if (front == nullptr)
			{
				front = newNode;
			}

			else
			{
				Node* current = front;
				while (current->next != nullptr)
				{
					current = current->next;
				}
				current->next = newNode;
			}
		}
		else {
			cout << "Invalid Input" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}


	void dequeue()
	{
		if (front == nullptr)
			cout << "Linked List is Empty" << endl;
		else if (front->next == nullptr)
		{
			delete front;
			front = nullptr;
		}
		else
		{
			Node* current = front;
			front = front->next;
			delete current;
			current = nullptr;
		}
	}

	void displayqueue() {
		Node* current = front;
		while (current != nullptr) {
			cout << current->data << " -> ";
			current = current->next;
		}
		cout << "nullptr" << endl;
	}

};


//
//int main()
//{
//	queue q1;
//	while (1)
//	{
//
//		string command = "-1"; // Initialize choice to a non-zero value
//
//		while (command != "Q") {
//			cout << "Queue Menu:" << endl;
//			cout << "1. Count Nodes" << endl;
//			cout << "+*. Enqueue" << endl;
//			cout << "-. Dequeue" << endl;
//			cout << "F. frontcheck" << endl;
//			cout << "E. isEmpty" << endl;
//			cout << "Q. Exit" << endl;
//			cout << "Enter your choice: ";
//			cin >> command;
//
//			cout << "Enter command: ";
//			cin >> command;
//			if (command == "+x")
//			{
//				q1.enqueue();
//				q1.displayqueue();
//			}
//			else if (command == "-")
//			{
//				q1.dequeue();
//				q1.displayqueue();
//			}
//			else if (command == "E")
//			{
//				if (q1.isEmpty())
//				{
//					cout << "Queue is empty!" << endl;
//				}
//				else
//					cout << "Queue is not empty!" << endl;
//				q1.displayqueue();
//			}
//			else if (command == "C")
//			{
//				while (!q1.isEmpty())
//				{
//					q1.dequeue();
//				}
//				cout << "Queue cleared!" << endl;
//				q1.displayqueue();
//			}
//			else if (command == "Q")
//				break;
//			else
//				cout << "Invalid command!" << endl;
//		}
//
//	}
//}

int main()
{
	queue q1;
	string commmand;
	while (1)
	{
		cout << "Enter command: ";
		cin >> commmand;
		if (commmand == "+x")
		{
			q1.enqueue();
			q1.displayqueue();
		}
		else if (commmand == "-")
		{
			q1.dequeue();
			q1.displayqueue();
		}
		else if (commmand == "E")
		{
			if (q1.isEmpty())
			{
				cout << "Queue is empty!" << endl;
			}
			else
				cout << "Queue is not empty!" << endl;
			q1.displayqueue();
		}
		else if (commmand == "C")
		{
			while (!q1.isEmpty())
			{
				q1.dequeue();

			}
			cout << "Queue cleared!" << endl;
			q1.displayqueue();
		}
		else if (commmand == "Q")
			break;
		else
			cout << "Invalid command!" << endl;
	}
}