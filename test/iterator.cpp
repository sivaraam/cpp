#include <list>
#include <iostream>

int main() {
	std::list<int> myList;
	std::list<int>::iterator myIter = myList.begin();    // any issues?
	myList.push_back( 123 );
	std::cout<<*myIter<<'\n';
	myIter++;
	std::cout<<*myIter<<'\n';
}
