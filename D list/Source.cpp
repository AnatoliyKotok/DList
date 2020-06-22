#include<iostream>
#include"D_list.h"
using namespace std;

int main() {
	
	D_list<int>list;
	list.addhead(123);
	list.addhead(13);
	list.addhead(45);
	/*list.insertAfter(123,1);
	list.insertBefor(123, 12);*/
	list.redact(123, 55);
	list.addTeil(15);
	list.printL();
	list.addTeil(18);
	list.printL();
	/*for (auto i = list.rbegin(); i != list.rend(); ++i) {
		cout << *i << "\t";
	}*/
	for (auto i = list.begin(); i != list.end(); ++i)
	{
		cout << *i << "\t";
	}
}