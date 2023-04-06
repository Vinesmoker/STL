#include<iostream>
using namespace std;

//#define EXEPTIONS_BASICS
//#define DIVISION_BY_ZERO

void main()
{
	setlocale(LC_ALL, "");
	
#ifdef EXEPTIONS_BASICS
	try
	{
		throw;
		//throw 1.5;
		//throw "Something went wrong!";
		throw std::exception("STD exeption thrown");
	}
	catch (int e)
	{
		std::cerr << "Error № " << e << std::endl;
	}
	catch (double e)
	{
		std::cerr << "Error № " << e << std::endl;
	}
	catch (const char* e)
	{
		std::cerr << "Error: " << e << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Error: Some exeption was thrown..." << std::endl;
	}
	cout << "Final!" << endl;
#endif // EXEPTIONS_BASICS

#ifdef DIVISION_BY_ZERO
	int a, b;
	cout << "Введите 2 чила:"; cin >> a >> b;
	try
	{
		cout << a / b << endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}
	catch (...)
	{
		std::cerr << "Something went wrong!" << endl;
	}
#endif // DIVISION_BY_ZERO

	int n;
	cout << "Введите число: "; cin >> n;
	long long f = 1;
	try
	{
		for (int i = 1; i <= n; i++)
		{
			cout << i << "! = ";
			f *= i;
			cout << f << endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << endl;
	}

}
