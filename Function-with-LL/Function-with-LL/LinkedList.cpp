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
	
	int pop_front() {
		if(len==0) {
			std::cout << "List is empty" << std::endl;
			return 0;
		}
		if(head == tail ) {
			delete head;
			head = tail = NULL;
			len--;
			return 1;
		}
		Node<T>* temp = head;
		head = head->next;
		head -> prev = NULL;
		delete temp;
		
		len--;
		return 1;
	}
	
	int pop_back() {
		if(len==0) {
			std::cout << "List is empty" << std::endl;
			return 0;
		}
		if(head == tail ) {
			delete head;
			head = tail = NULL;
			len--;
			return 1;
		}
		Node<T>* temp = tail;
		tail = tail->prev;
		tail -> next = NULL;
		delete temp;
		
		len--;
		
		return 1;
	}
	
	int remove_node(Node<T>* node) {
		if(node == NULL) { 
			std::cout << "Node does not exist" << std::endl;
			return 0; 
		}
		if(node == head) { pop_front(); return 1; };
		if(node == tail) { pop_back(); return 1; };

		
		node->prev->next = node ->next;
		node->next->prev = node ->prev;
		
		delete node;
				
		len--;
		return 1;
		
	}
	
	int remove_at(int pos) {
		if(len==0) {
			std::cout << "List is empty" << std::endl;
			return 0;
		}
		if(pos<0 || pos >=len) {
			std::cout << "Out of range" << std::endl;
			return 0;
		}
		if(pos==0) { pop_front(); return 1; }
		if(pos==len-1) { pop_back(); return 1; }
		Node<T>* temp;
		if(pos<=len/2) {
			temp = head;
			for(int i=1; i<=pos; ++i) {
				temp=temp->next;
			}
		} else {
			temp = tail;
			for(int i=len-1; i>pos; --i) {
				temp=temp->prev;
			}
		}	
		len--;
		if (remove_node(temp)==1) {return 1;}
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
