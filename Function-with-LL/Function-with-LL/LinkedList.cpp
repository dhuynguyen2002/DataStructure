#include <iostream>
#include <cmath>

struct Node
{
	int data;
	Node* next = NULL;

	Node(int _data) : data(_data) {};
};

class LinkedList
{
private:
	int len = 0;

public:
	Node* head;
	LinkedList(int data)
	{
		head = new Node(data);
		len++;
	}
	
	int GetLength() { return len; }
	//INSERT
	void AppendNode(int data);
	void PushFrontNode(int data);
	void InsertNode(int pos, int data);

	//DELETE
	void Delete(int key, bool multi);
};
// O(n)
inline void LinkedList::AppendNode(int data) 
{
	Node* newNode = new Node(data);
	Node* tHead = head;
	while (tHead->next != NULL)
		tHead = tHead->next;

	tHead->next = newNode;

	len++;
}

// O(1)
inline void LinkedList::PushFrontNode(int data) 
{
	Node* newNode = new Node(data);
	newNode->next = head;
	head = newNode;

	len++;
}

//O(n)
inline void LinkedList::InsertNode(int index, int data)
{
	if (index > len)
	{
		std::cout << "Current Length: " << len << " Can't insert invalid position" << std::endl;
		return;
	}
	
	if (index == 0)
	{
		PushFrontNode(data); return;
	}
	if (index == len)
	{
		AppendNode(data); return;
	}
	Node* tHead = head;
	for (int i = 1; i < len; i++)
	{
		if (i == index)
		{
			Node* newNode = new Node(data);
			newNode->next = tHead->next;
			tHead->next = newNode;
		}
		else tHead = tHead->next;
	}
}

//O(n)
inline void LinkedList::Delete(int key, bool multi)
{
	Node* cNode = head, * pNode = cNode;
	while (cNode != NULL)
	{
		if (cNode->data == key)
		{
			Node* temp = cNode;
			if (cNode == head)
			{
				head = temp->next;
				cNode = head;
				pNode = cNode;
			}
			else
			{
				pNode->next = temp->next;
				cNode = pNode;

			}
			delete temp;
			if (!multi) return;
		}
		else
		{
			pNode = cNode;
			cNode = cNode->next;
		}	
	}
}


// O(n)
inline void PrintNode(Node* head) 
{
	while (head != NULL)
	{
		std::cout << head->data << " ";
		head = head->next;
	}
	std::cout << std::endl;
}