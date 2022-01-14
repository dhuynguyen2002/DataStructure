//Simply put, when you want to use algorithms that requires random access, forget linked list.
//When you want to use algorithms that requires heavy insertionand removal, forget arrays.
#include <cmath>
#include<iostream>
template <typename T>
struct Node
{
	T data;
	Node* next = NULL;
	Node* prev = NULL;
};

template <typename T>
bool cmp(T const& t1, T const& t2)
{
	return t1 > t2;
}

template <typename T>
class DLList
{
private:
	bool isSort = false;
	int len;
public:
	Node<T>* head;
	Node<T>* tail;
	DLList<T> (T data)
	{

		len = 1;
		head = new Node<T>;
		head->data = data;
		head->next = NULL;
		head->prev = NULL;

		tail = head;
	}

	int push_front(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->next = head;

		head->prev = newNode;

		head = newNode;
		++len;
		return 1;
	}

	int append(T data)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;
		newNode->prev = tail;

		tail->next = newNode;

		tail = newNode;
		++len;
		return 1;
	}

	int insert(T data, Node<T>*& frNode)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = data;

		newNode->next = frNode;
		
		newNode->prev = frNode->prev;
		
		frNode->prev->next = newNode;
		frNode->prev = newNode;

		++len;
		return 1;
	}

	int insert_at(T data, int pos)
	{
		if (pos > len + 1|| pos <= 0)
		{
			std::cout << "Error Insert" << std::endl;
			return 0;
		}
		if (pos == 1) { push_front(data); return 1; }
		if (pos == len + 1) { append(data); return 1; }
		Node<T>* temp = head;
		for (int i = 1; i < pos; i++)
			temp = temp->next;

		insert(data, temp);
		return 1;
	}

	int insert_Order(T data)
	{
		Node<T>* temp = head;

		while (temp != NULL)
		{
			
			if (cmp(temp->data, data))
			{
				if (temp == head){ push_front(data); return 1; }	
				insert(data, temp);
				return 1;
			}
			if (temp == tail)
			{
				append(data);
				return 1;
			}
			temp = temp->next;
		}

		return 0;
	}
	
	int getLen() { return len; }

};

template <typename T>
inline void PrintDLL(DLList<T>& list)
{
	Node<T>* temp = list.head;
	while (temp != NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}
