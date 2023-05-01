#include "MyLibrary.cpp"

int main()
{
	setlocale(LC_ALL, "Russian");

	//обьявление используемых в программе переменных
	My_List<int> list;
	int choice = 0, value, index;

	//цикл, обеспечивающий возвращение в главное меню после каждой операции
	while (choice != 10)
	{
		cout << "\nВыберите операцию с листом:\n1 - добавить эл-т\n2 - удалить эл-т";
		cout << "\n3 - вывести эл-т на экран\n4 - вывести список на экран\n5 - очистить список";
		cout << "\n6 - поиск эл-та по значению\n7 - сложение элементов массива";
		cout << "\n8 - вычитание элементов массива\n9 - вырезать часть массива";
		cout << "\n10 - выход из программы\nВаш выбор: "; cin >> choice;

		if (choice == 1)
		{
			cout << "\nВведите значение эл-та = "; cin >> value;
			list.Insert(value);
		}

		if (choice == 2)
		{
			try
			{
				if (list.GetSize() == 0)
				{
					throw exception("Список пуст!\n");
				}

				cout << "\nВведите индекс эл-та = "; cin >> index;

				list.RemoveAt(index);

				cout << "Эл-т удален!\n";
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
		}

		if (choice == 3)
		{
			try
			{
				if (list.GetSize() == 0)
				{
					throw exception("Список пуст!\n");
				}

				cout << "\nВведите индекс эл-та = "; cin >> index;

				list.PrintElement(index);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
		}

		if (choice == 4)
		{
			try
			{
				list.PrintList();
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
		}

		if (choice == 5)
		{
			try
			{
				if (list.GetSize() == 0)
				{
					throw exception("Список пуст!\n");
				}

				list.Clear();

				cout << "Список очищен!\n";
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
		}

		if (choice == 6)
		{
			if (list.GetSize() == 0)
			{
				cout << "Список пуст!\n";

				continue;
			}

			cout << "\nВведите значение эл-та = "; cin >> value;

			try
			{
				index = list.Find(value);

				cout << "Индекс первого найденного эл-та = " << index << endl;
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
		}

		if (choice == 7)
		{
			try
			{
				Sum(list);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
		}

		if (choice == 8)
		{
			try
			{
				Subtract(list);
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
		}

		if (choice == 9)
		{
			try
			{
				list.PrintList();

				int a = 0, b = 0;

				cout << "Вырежем часть массива, а именно эл-ты list[a]...list[b],";
				cout << "где индекс a - левая граница вырезаемой части, b - правая\n";
				cout << "a = "; cin >> a; cout << "b = "; cin >> b;

				if ((a < 0) || (b < 0) || (b < a) || (b >= list.GetSize()) || (a >= list.GetSize()))
				{
					throw exception("Неверный ввод индексов!\n");
				}

				for (int i = 0; i <= b - a; i++)
				{
					list.RemoveAt(a);
				}

				cout << "Часть массива вырезана!\n";
			}
			catch (const std::exception& ex)
			{
				cout << ex.what();
			}
		}

		if (choice == 10)
		{
			break;
		}

		if (choice < 1 || choice > 10)
		{
			cout << "Неправильный ввод!";
		}
	}

	return 0;
}