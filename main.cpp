#include <iostream>
using namespace std;

class MyString
{
public:
	MyString()//конструктор по умолчанию
	{
		str = nullptr;
	}

	MyString(const char *str)//конструктор для инициализации типа MyString str("123")
	{
		int length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; ++i)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}

	MyString(const MyString& other)// конструктор копирования 
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		int length = strlen(other.str);

		this->str = new char[length + 1];

		for (int i = 0; i < length; ++i)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}

	~MyString()// десктруктор
	{
		delete[] str;
	}

	MyString& operator = (const char * str) // перегруженный оператор = для такой конструкции MyString str1 = "123";
	{
		int length = strlen(str);

		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		this->str = new char[length+1];
		for (int i = 0; i < length; ++i)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
		return *this;
	}

	MyString& operator =(const MyString& other)// перегрузка оператора = для использования в виде str1 = str2;
	{
		int length = strlen(other.str);

		if (this->str != nullptr)
		{
		    delete[] this->str;
		}

		this->str = nullptr;

		this->str = new char[length + 1];

		for (int i = 0; i < length; ++i)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
		return *this;
	}

	MyString operator + (const MyString& str2) //перегрузка оператора + для сложения массивов строк
	{
		MyString newStr;
		int length = strlen(this->str) + strlen(str2.str);
		newStr.str = new char[length + 1];
		int i = 0;
		for (; i < strlen(this->str); i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < strlen(str2.str); ++j, ++i)
		{
			newStr.str[i] = str2.str[j];
		}

		newStr.str[length] = '\0';
		return newStr;
	}

private://здесь хранятся все массивы char
	char* str;

public:
	void print()
	{
		cout << str << endl;
	}
};

int main()
{
	MyString str1("123");
	str1.print();
	MyString str2("456");
	str2.print();

	/*cout << "_____________________________" << endl;
	
	str1 = "hello";

	str1.print();
	str2.print();*/

	MyString str3 = str1 + str2;
	str3.print();
	return 0;
}