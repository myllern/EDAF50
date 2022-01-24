#include <iostream>
#include "list.h"

using std::cin;
using std::cout;
using std::endl;

List::List()
{
	first = nullptr;
}

List::~List()
{
}

bool List::exists(int d) const
{
	Node *temp = first;
	while (temp != nullptr)
	{
		if (temp->value == d)
		{
			return true;
		}

		temp = temp->next;
	}
	delete temp;
	return false;
}

int List::size() const
{
	Node *temp = first;
	int count = 0;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;
	}
	delete temp;
	return count;
}

bool List::empty() const
{
	return !first ? true : false;
}

void List::insertFirst(int d)
{
	Node *node = new Node(d, first);
	first = node;
}

void List::remove(int d, DeleteFlag df)
{
	Node *iter = first;
	Node *prev = nullptr;

	if (first == nullptr)
	{
		cout << "List empty" << endl;
	}

	while (iter != nullptr)
	{
		if ((iter->value == d && df == List::DeleteFlag::EQUAL) || (iter->value < d && df == List::DeleteFlag::LESS) || (iter->value > d && df == List::DeleteFlag::GREATER))
		{

			if (prev == nullptr)
			{
				first = first->next; 
				free(iter); 
				iter = first;
			}
			else
			{
				prev->next = iter->next;
				free(iter);
				iter = iter->next;
			}
		}
		else
		{
			prev = iter;
			iter = iter->next;
		}
	}
	//delete prev;
	//delete iter;
}

void List::print() const
{
	Node *temp = first;
	int element = 0;

	while (temp != nullptr)
	{
		cout << "Element nr: " << temp->value << endl;
		element++;
		temp = temp->next;
	}
	delete temp;
}
