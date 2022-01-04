

#include "LinkedList.cpp"

using namespace std;

int main()
{
	LinkedList* llist = new LinkedList(4);

	llist->AppendNode(5);
	llist->AppendNode(9);
	llist->PushFrontNode(10);
	llist->PushFrontNode(4);
	
	llist->InsertNode(1, 11);
	llist->AppendNode(4);
	//4 11 10 4 5 9
	//cout << llist->GetLength() << endl;

	PrintNode(llist->head);
	llist->Delete(4, true);
	PrintNode(llist->head);
	cout << llist->NodeAt(2)->data;
}

