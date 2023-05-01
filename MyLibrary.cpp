#include "MyLibrary.h"

using namespace MyNamespace;

//конструктор класса
template<typename T>
My_List<T>::My_List()
{
	SIZE = 0;
	head = nullptr;
}

//деструктор класса
template<typename T>
My_List<T>::~My_List()
{
	Clear();
}

//перегрузка оператора квадратных скобок
template<typename T>
T& My_List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;

	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}

		current = current->pNext;
		counter++;
	}
}

//метод удаляет эл-т в начале списка
template<typename T>
void My_List<T>::Pop_Front()
{
	Node<T>* temp = head;
	head = head->pNext;

	delete temp;

	SIZE--;
}

//метод очищает список
template<typename T>
void My_List<T>::Clear()
{
	while (SIZE)
	{
		Pop_Front();
	}
}

//метод добавляет эл-т списка с определенным индексом
template<typename T>
void My_List<T>::Insert(T value)
{
	Node<T>* current = head;
	Node<T>* prev = nullptr;
	Node<T>* newNode = new Node<T>(value);

	// найдем место для вставки нового элемента в отсортированном списке
	while (current != nullptr && value > current->data)
	{
		prev = current;
		current = current->pNext;
	}

	// если новый элемент добавляется в начало списка
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

//метод удаляет эл-т списка с определенным индексом
template<typename T>
void My_List<T>::RemoveAt(int index)
{
	if ((index >= SIZE) || index < 0)
	{
		throw exception("Нет эл-та с таким индексом!\n");
	}

	if (index == 0)
	{
		Pop_Front();
	}
	else
	{
		Node<T>* previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;

		SIZE--;
	}
}

//метод удаляет эл-т в конце списка
template<typename T>
void My_List<T>::Pop_Back()
{
	RemoveAt(SIZE - 1);
}

//метод выводит эл-т списка с определенным индексом
template<typename T>
void My_List<T>::PrintElement(int index)
{
	if (SIZE == 0)
	{
		throw exception("Список пуст!\n");
	}

	if ((index >= SIZE) || index < 0)
	{
		throw exception("Такого эл-та в списке нет!\n");
	}

	Node<T>* current = head;

	for (int i = 0; i < index; i++)
	{
		current = current->pNext;
	}

	cout << current->data << endl;
}

//метод выводит весь список на экран
template<typename T>
void My_List<T>::PrintList()
{
	if (SIZE == 0)
	{
		throw exception("Список пуст!\n");
	}

	cout << "Список эл-тов:\n";

	Node<T>* current = head;

	while (current != nullptr)
	{
		cout << current->data << " ";
		current = current->pNext;
	}

	cout << endl;
}

//метод возвращает индекс первого найденного эл-та с переданным значением
template<typename T>
int My_List<T>::Find(T value)
{
	if (SIZE == 0)
	{
		throw exception("Список пуст!\n");
	}

	int index = 0;
	Node<T>* current = head;

	while (current != nullptr)
	{
		if (current->data == value)
		{
			return index;
		}

		current = current->pNext;
		index++;
	}

	throw exception("Такого эл-та нет!\n");
}