#include "DubleConnList.h"
#include <typeinfo>
using namespace std;
template <typename T>
void DubleConnList<T>::Void()
{
	cout << endl << endl << endl;
}
int main()
{
	system("chcp 1251");
	DubleConnList<int> list;
	cout << "Fist list\n";
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(6);
	list.show();
	list.Void();
	cout << "Reverse list\n";
	list.reverse();
	list.show();
	list.Void();
	cout << "Expanded list 3rd - g\n";
	list.insert('g',3);
	list.show();
	list.Void();
	cout << "3rd element has been removed\n";
	list.remove(3);
	list.show();
	DubleConnList<char> list2;
	cout << "Second list\n";
	list2.add('z');
	list2.add('g');
	list2.add('t');
	list2.add('h');
	list2.add('j');
	list2.add('l');
	list2.show();
	//list2 = list; 
	//cout << "clear list\n";
	//list.clear();
	//list.show();
	//cout << "show list2\n";
	//list2.show();
	DubleConnList<char> list3(list2);
	cout << "Third list\n";
	cout << "show list3\n";
	list3.show();
	//cout << "Fist list again\n";
	//list.add('a');
	//list.add('b');
	//list.add('c');
	//list.add('d');
	//list.add('e');
	//list.add('f');
	//list.show();
	//DubleConnList<char> list4;
	//cout << "list4\n";
	//list4.add('a');
	//list4.add('b');
	//list4.show();
	//list4=(move(list));
	//cout << "list4 after move\n";
	//list4.show();
	//list.show();
	//DubleConnList<char> list5(move(list4));
	//cout << "list5\n";
	//list5.show();
	//cout << "list4\n";
	//list4.show();
	return 0;
}


