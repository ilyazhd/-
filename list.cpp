#include "header.h"

List::List(const List& l) {
	Clone(l);
}

List::~List() {
	Erase();
}

const List& List::operator=(const List& l) {
	if (&l == this) {
		return *this;
	}
	Erase();
	Clone(l);
	return *this;
}

void List::InsertFirst(const int& aInfo) {
	ListItem* p = new ListItem();
	p->info = aInfo;
	p->next = First;
	First = p;
}

bool List::DeleteFirst() {
	if (First == NULL) {
		return false;
	}
	ListItem* p = First;
	First = First->next;
	delete p;
	return true;
}

const int List::Top() const {
	if (First == NULL) {
		throw std::runtime_error("Список пуст.");
	}
	int x = First->info;
	return x;
}

void List::Clone(const List& l) {
	ListItem* p, * q, * r;
	r = NULL;
	p = l.First;
	while (p != NULL) {
		q = new ListItem;
		q->info = p->info;
		q->next = NULL;
		if (r == NULL) {
			First = q;
		}
		else {
			r->next = q;
		}
		r = q;
		p = p->next;
	}
}

void List::Erase() {
	ListItem* p, * q;
	p = First;
	while (p != NULL) {
		q = p->next;
		delete p;
		p = q;
	}
	First = NULL;
}

void List::ListPrint() const {
	ListItem* p = First;
	if (p == NULL) {
		std::cout << "Список пуст.\n";
	}
	if (p != NULL) {
		while (p != NULL) {
			std::cout << p->info << " ";
			p = p->next;
		}
	}
	std::cout << std::endl;
}


void List::ForEach(void Fun(int))const
{
	ListItem* P = First;
	if (P == NULL)
		std::cout << "список пуст" << std::endl;
	if (P != NULL)
	{
		std::cout << "содержимое списка" << std::endl;
		while (P != NULL)
		{
			Fun(P->info);
		}
	}
}

void List::insert(const int elem) {
	ListItem* elemItem = new ListItem(elem);
	if (First == nullptr || First->info > elem) {
		InsertFirst(elem);
	}
	else {
		ListItem* moveItem = First;
		while (moveItem != nullptr) {
			if (moveItem->next == nullptr) {
				moveItem->next = elemItem;
				break;
			}
			else if (moveItem->info <= elem && elem < moveItem->next->info) {
				elemItem->next = moveItem->next;
				moveItem->next = elemItem;
				break;
			}
			moveItem = moveItem->next;
		}
	}
}

void List::ForEach(void(*func)(int&)) {
	ListItem* curr = First;
	while (curr) {
		func(curr->info);
		curr = curr->next;
	}
}