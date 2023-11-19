#include <iostream>
using namespace std;

class MyString
{
public:
	MyString()
	{
		str = nullptr;
	}

	MyString(const char *str)
	{
		int length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; ++i)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}

	MyString(const MyString& other)
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

	~MyString()
	{
		delete[] str;
	}

	MyString& operator = (const char * str)
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

	MyString& operator =(const MyString& other)
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

	MyString operator + (const MyString& str2)
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

private:
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