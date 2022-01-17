#include "LinkedList.cpp"

using namespace std;

bool cmp(int data1, int data2)
{
	return data1 > data2;
}


int main()
{
	//19:15
	//vlxx.non
	DLList<int> m(4);
	m.push_front(2);
	m.push_front(8);
	m.push_back(3);
	m.push_back(1);
	m.insert_order(4, cmp);
	m.insert_at(6,7);
	//Node<int>* temp = m.head;
//	MergeSort(temp, 5,cmp);
	//test_delete(m);
	PrintDLL(m);
	m.head = mergeSort(m.head, cmp);
	DLList<int> curr=m.find_all(4);
	cout << "list of find: ";
	PrintDLL(curr);
	Node<int>* node = m.find_node(2);
	cout << node->data;
	cout << endl;
	PrintDLL(m);
}
