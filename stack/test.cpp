#include<iostream>
#include "ArrayStack1.h"

using namespace std;
int main() {

	zhlib::ArrayStack<int> a;
	a.push(1);
	a.push(2);
	a.push(5);
	a.push(6);
	a.push(7);

	
	cout << "Size:" << a.size() << endl;
	cout << "Top:" << a.top() <<endl;
	cout << "Empty?:" << a.empty() <<endl;

	a.print();


}