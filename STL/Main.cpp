#include<iostream>
#include<array>
#include<vector>
#include<deque>
#include<list>
#include<iterator>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n--------------------------\n"

//https://legacy.cplusplus.com/reference/stl/

template<typename T>void vector_properties(const std::vector<T>& vec)
{
	cout << "Size:\t\t" << vec.size() << endl;
	cout << "Capacity:\t" << vec.capacity() << endl;
	cout << "Max size:\t" << vec.max_size() << endl;
}

//#define STL_ARRAY
//#define STL_VECTOR
//#define STL_DEQUE
#define STL_LIST

void main()
{
	setlocale(LC_ALL, "");
#ifdef STL_ARRAY
	//array - это контейнер, который хранит данные в виде статического массива.
	const int N = 5;
	std::array<int, N> arr = { 3, 5, 8 };
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr.data()[i] << tab;
	}
	cout << endl;
#endif // STL_ARRAY

#ifdef STL_VECTOR
	//vector - это контейнер, который хранит данные в виде динамического массива.
	//vector позволяет добавлять значения только в конец, и удалять элементы только с конца,
	//это НЕ считая вставки и удаления по индексу.
	std::vector<int> vec = { 0, 55, 1, 1, 2, 3, 5, 8, 13, 21, 34 };
	vec.resize(22);
	for (int i = 0; i < vec.capacity(); i++)
	{
		cout << vec[i] << tab;
		//cout << vec.at(i) << tab;
	}
	cout << endl;
	vec.resize(8);
	try
	{
		for (int i = 0; i < vec.capacity(); i++)
		{
			//cout << vec[i] << tab;
			cout << vec.at(i) << tab;
		}
		cout << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	vector_properties(vec);
	cout << delimiter << endl;
	std::vector<int> vec2(100);
	vector_properties(vec2);
	cout << delimiter << endl;
	vec2.push_back(123);
	vector_properties(vec2);
	//cout << delimiter << endl;
	//vec2.shrink_to_fit();	//убирает всю зарезервированную память, т.е., уменьшает capacity до фактического размера (size)
	//vector_properties(vec2);
	cout << delimiter << endl;
	for (int i = 0; i < 90; i++)vec2.pop_back();
	vector_properties(vec2);
	cout << delimiter << endl;
	vec2.reserve(255);
	vec2.resize(8);
	vector_properties(vec2);

#endif // STL_VECTOR

#ifdef STL_DEQUE
	std::deque<int> deque = { 3, 5, 8, 13, 21 };
	for (int i = 0; i < deque.size(); i++)
	{
		cout << deque[i] << "\t";
	}
	cout << endl;
	deque.push_front(2);
	deque.push_back(34);
	for (int i : deque)cout << i << "\t"; cout << endl;
#endif // STL_DEQUE

#ifdef STL_LIST

	std::list<int> list = { 3, 5, 8, 13, 21 };
	/*for (int i = 0; i < list.size(); i++)cout << list << "\t";
	cout << endl;*/

	for(std::list<int>::iterator it = list.begin(); it != list.end(); ++it)
	{
		cout << *it << "\t";
	}
	cout << endl;
	for(std::list<int>::reverse_iterator rit = list.rbegin(); rit != list.rend(); ++rit)
	{
		cout << *rit << "\t";
	}
	cout << endl;
	int index; int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	std::list<int>::iterator position = list.begin();
	//for (int i = 0; i < index; i++)++position;
	std::advance(position, index);
	list.insert(position, value);
	for (int i : list)cout << i << "\t"; cout << endl;

#endif // STL_LIST

}
