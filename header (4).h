#pragma once
#include <iostream>

class List {
protected:
	struct ListItem {
		int info;
		ListItem* next;

		ListItem() : next(nullptr), info(0) {}
		ListItem(const int a) : info(a) , next(nullptr) {}
	};
	ListItem* First;
public:
	List() {}
	List(const List&);
	~List();
	const List& operator =(const List&);
	void InsertFirst(const int&);
	bool DeleteFirst();
	const int Top() const;
	void ListPrint() const;
	void ForEach(void(int)) const;
	void ForEach(void(int&));
	void Erase();
	void insert(const int elem) {
		ListItem* elemItem = new ListItem(elem);
		if (First == nullptr || First->info > elem) { //если пустой
			this->InsertFirst(elem);
		}
		else {
		ListItem* moveItem = First;//вспомогательная структура для передвижения по списку
		while (moveItem != nullptr) {//проверка на конец списка
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
protected:
	void Clone(const List&);
};