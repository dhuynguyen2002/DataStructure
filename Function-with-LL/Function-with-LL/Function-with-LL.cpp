#include "LinkedList.cpp"

using namespace std;

bool cmp(int data1, int data2)
{
	return data1 > data2;
}

struct abc {
	int a;
	string b;
};

void cr(DLList<int> &m, int pos) {
	if(!m.remove_at(pos)) { return; };
	cout << "After remove at " << pos << " :";
	PrintDLL(m);
	cout << endl;
}

void cr(DLList<int> &m, Node<int> *node) {
	if(!m.remove_node(node)) { return; }
	cout << "After remove Node: ";
	PrintDLL(m);
	cout << endl;
}

void test_delete(DLList<int> &m) {
	cout << "Before remove:";
	PrintDLL(m);
	cout << endl;
	Node<int> *temp = m.head; 
	cr(m, temp->next->next);
	temp = m.head;
	cr(m, temp);
	cr(m, 4);
	cr(m, 0);
	cr(m, m.getLen()-1);
	cr(m, 1);
	cr(m, 3);
	cr(m, -1);
	cr(m,m.tail);
	cr(m,m.head);
	cr(m,1);
}

int main()
{
	// I'm here
	// Something change
	DLList<int> m(4);
	m.push_front(2);
	m.push_front(1);
	m.append(7);
	m.append(10);
	m.insert_Order(14);
	m.insert_at(3,7);
	test_delete(m);
	cout << endl << m.getLen();
}

