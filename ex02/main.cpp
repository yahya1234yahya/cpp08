#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	std::cout << "=== Testing MutantStack ===" << std::endl;
	
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Top element: " << mstack.top() << std::endl;

	mstack.pop();

	std::cout << "Size after pop: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(11);
	mstack.push(42);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "Iterating through MutantStack:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	// Test that MutantStack can be used as a regular stack
	std::stack<int> s(mstack);
	std::cout << "Regular stack size (copied from MutantStack): " << s.size() << std::endl;

	std::cout << std::endl;
	std::cout << "=== Comparing with std::list ===" << std::endl;
	
	// Same test with std::list for comparison
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << "Back element: " << lst.back() << std::endl;

	lst.pop_back();

	std::cout << "Size after pop: " << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(11);
	lst.push_back(42);
	lst.push_back(0);

	std::list<int>::iterator lit = lst.begin();
	std::list<int>::iterator lite = lst.end();

	++lit;
	--lit;

	std::cout << "Iterating through std::list:" << std::endl;
	while (lit != lite)
	{
		std::cout << *lit << std::endl;
		++lit;
	}

	std::cout << std::endl;
	std::cout << "=== Additional MutantStack tests ===" << std::endl;

	// Test reverse iterators
	std::cout << "Reverse iteration:" << std::endl;
	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();
	while (rit != rite)
	{
		std::cout << *rit << " ";
		++rit;
	}
	std::cout << std::endl;

	// Test copy constructor and assignment
	MutantStack<int> mstack2(mstack);
	MutantStack<int> mstack3;
	mstack3 = mstack;

	std::cout << "Copy constructor test - size: " << mstack2.size() << std::endl;
	std::cout << "Assignment operator test - size: " << mstack3.size() << std::endl;

	// Test with different type
	std::cout << std::endl;
	std::cout << "=== Testing with strings ===" << std::endl;
	MutantStack<std::string> strStack;
	strStack.push("Hello");
	strStack.push("World");
	strStack.push("42");

	MutantStack<std::string>::iterator strIt = strStack.begin();
	MutantStack<std::string>::iterator strIte = strStack.end();

	std::cout << "String stack contents:" << std::endl;
	while (strIt != strIte)
	{
		std::cout << *strIt << std::endl;
		++strIt;
	}

	return 0;
}
