#include "LinkedList.cpp"

using namespace std;

bool cmp(int data1, int data2)
{
	return data1 > data2;
}

int main()
{
	DLList<int> m(4);
	m.push_front(2);
	m.push_front(1);
	m.append(7);
	m.append(10);

	m.insert_Order(14);
	PrintDLL(m);
	cout << endl;
	m.insert_at(3,7);
	PrintDLL(m);
	cout << endl << m.getLen();
}

