#include "list.h"

using namespace myspace1;

template<typename Object>
List<Object>::List(){
    init();
}

template<typename Object>
List<Object>::List(const List & rhs)
{
	init();
	for (auto &x : rhs)
		push_back(x);
}


template<typename Object>
List<Object>::~List()
{
	clear();
	delete head;
	delete tail;
}

template<typename Object>
List<Object> & List<Object>::operator=(const List & rhs)
{
	List copy = rhs;
	std::swap(*this, copy);
	return *this;
}


template<typename Object>
List<Object>::List(List && rhs) :theSize(rhs.theSize), head(rhs.head), tail(rhs.tail)
{
	rhs.theSize = 0;
	rhs.head = nullptr;
	rhs.taill = nullptr;
}

template<typename Object>
List<Object> & List<Object>::operator = (List && rhs)
{
	std::swap(theSize, rhs.theSize);
	std::swap(head, rhs.head);
	std::swap(tail, rhs.tail);
}

int main(){
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    // std::cout << a << std::endl;
}