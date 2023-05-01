#pragma once
#include <iostream>

using namespace std;

namespace MyNamespace
{
	template<typename T>
	class My_List
	{
	public:
		My_List();

		~My_List();

		const int GetSize() { return SIZE; }

		T& operator[](const int index);

		void Pop_Front();

		void Pop_Back();

		void Clear();

		void PrintElement(int index);

		void PrintList();

		void Insert(T value);

		void RemoveAt(int index);

		int Find(T value);

	private:
		//внутренний класс, описывающий эл-т списка
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
	void Sum(My_List<T>& list)
	{
		if (list.GetSize() < 2)
		{
			throw exception("Список пуст или эл-тов в списке < 2!\n");
		}
		else
		{
			int a = 0, b = 0;

			cout << "Сложим элементы массива list[a] + list [b]\n";
			cout << "a = "; cin >> a; cout << "b = "; cin >> b;

			if ((a < 0) || (b < 0) || (b == list.GetSize()) || (a == list.GetSize()))
			{
				throw exception("Неверный ввод индексов!\n");
			}

			cout << "list[" << a << "] + list[" << b << "] = " << list[a] + list[b] << endl;
		}
	}

	template<typename T>
	void Subtract(My_List<T>& list)
	{
		if (list.GetSize() < 2)
		{
			throw exception("Список пуст или эл-тов в списке < 2!\n");
		}
		else
		{
			int a = 0, b = 0;

			cout << "Вычтем элементы массива list[a] - list [b]\n";
			cout << "a = "; cin >> a; cout << "b = "; cin >> b;

			if ((a < 0) || (b < 0) || (b == list.GetSize()) || (a == list.GetSize()))
			{
				throw exception("Неверный ввод индексов!\n");
			}

			cout << "list[" << a << "] - list[" << b << "] = " << list[a] - list[b] << endl;
		}
	}

	template<typename T>
	int My_List<T>::SIZE = 0;
}