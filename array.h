#ifndef ARRAY_H_
#define ARRAY_H_
#include <iostream>

template<typename T>
class My_List
{
public:
	My_List();
	~My_List();

	T& operator[](const int index);

	const int GetSize() { return SIZE; }
	void Pop_Front();
	void Pop_Back();
	void Clear();
	void PrintElement(int index);
	void PrintList();
	void Insert(T value);
	void RemoveAt(int index);
	int Find(T value);

private:
	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};

	Node<T>* head;
	static int SIZE;
};

template<typename T>
int My_List<T>::SIZE = 0;

template<typename T>
My_List<T>::My_List()
{
	SIZE = 0;
	head = nullptr;
}

template<typename T>
My_List<T>::~My_List()
{
	Clear();
}

template<typename T>
T& My_List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
			return current->data;

		current = current->pNext;
		counter++;
	}
}

template<typename T>
void My_List<T>::Pop_Front()
{
	Node<T>* temp = head;
	head = head->pNext;

	delete temp;
	SIZE--;
}

template<typename T>
void My_List<T>::Clear()
{
	while (SIZE)
		Pop_Front();
}

template<typename T>
void My_List<T>::Insert(T value)
{
	Node<T>* current = head;
	Node<T>* prev = nullptr;
	Node<T>* newNode = new Node<T>(value);

	while (current != nullptr && value > current->data)
	{
		prev = current;
		current = current->pNext;
	}

	if (prev == nullptr)
	{
		newNode->pNext = head;
		head = newNode;
	}
	else
	{
		prev->pNext = newNode;
		newNode->pNext = current;
	}

	SIZE++;
}

template<typename T>
void My_List<T>::RemoveAt(int index)
{
	if ((index >= SIZE) || index < 0)
		throw std::exception("Нет эл-та с таким индексом!\n");

	if (index == 0)
	{
		Pop_Front();
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
			previous = previous->pNext;

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;
		SIZE--;
	}
}

template<typename T>
void My_List<T>::Pop_Back()
{
	RemoveAt(SIZE - 1);
}

template<typename T>
void My_List<T>::PrintElement(int index)
{
	if (SIZE == 0)
		throw std::exception("Список пуст!\n");

	if ((index >= SIZE) || index < 0)
		throw std::exception("Такого эл-та в списке нет!\n");

	Node<T>* current = head;

	for (int i = 0; i < index; i++)
		current = current->pNext;

	std::cout << current->data << std::endl;
}

template<typename T>
void My_List<T>::PrintList()
{
	if (SIZE == 0)
		throw std::exception("Список пуст!\n");

	std::cout << "Список эл-тов:\n";

	Node<T>* current = head;

	while (current != nullptr)
	{
		std::cout << current->data << " ";
		current = current->pNext;
	}

	std::cout << std::endl;
}

template<typename T>
int My_List<T>::Find(T value)
{
	if (SIZE == 0)
		throw std::exception("Список пуст!\n");

	int index = 0;
	Node<T>* current = head;

	while (current != nullptr)
	{
		if (current->data == value)
			return index;

		current = current->pNext;
		index++;
	}

	throw std::exception("Такого эл-та нет!\n");
}

#endif // ARRAY_H_