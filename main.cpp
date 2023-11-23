#include <iostream>
using namespace std;

class MyString
{
public:
	MyString()//default constructor
	{
		str = nullptr;
		length = 0;
	}

	MyString(const char *str)//(MyString str("123") or MyString str = "123")
	{
		length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; ++i)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}

	MyString(const MyString& other)// copy constructor(MyString str2(str1))
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		length = other.length;

		this->str = new char[length + 1];

		for (int i = 0; i < length; ++i)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}

	MyString(MyString&& other) // move constructor
	{
		this->length = other.length;
		this->str = other.str;

		other.str = nullptr;
	}

	~MyString()// destructor
	{
		delete[] str;
	}

	MyString& operator = (const char * str) // overloaded operator =  (str1 = "123");)
	{
		length = strlen(str);

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

	MyString& operator =(const MyString& other)// overloaded operator =  (str1 = str2);
	{
		this->length = strlen(other.str);

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

	MyString operator + (const MyString& str2) //overloaded operator + 
	{
		MyString newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(str2.str);

		newStr.length = thisLength + otherLength;

		newStr.str = new char[thisLength + otherLength + 1];
		
		int i = 0;
		for (; i < thisLength; ++i)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; ++j, ++i)
		{
			newStr.str[i] = str2.str[j];
		}

		newStr.str[newStr.length] = '\0';
		return newStr;
	}

	bool operator == (const MyString& other) //overloaded operator ==
	{
		if (this->length != other.length)
		{
			return false;
		}

		for (int i = 0; i < this->length; ++i)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}

		return true;
	}

	bool operator != (const MyString& other)//overloaded operator !=
	{
		return !this->operator ==(other);
	}

	char& operator [](int index) //overloaded operator []
	{
		return this->str[index];
	}

private://all arrays of char are stored in this variable
	char* str;
	int length;

public:
	void print()
	{
		cout << str << endl;
	}

	int Length()
	{
		return length;
	}

	void replace(char who, char what)
	{
		bool isReplace = false;
		for (int i = 0; i < this->length; ++i)
		{
			if (this->str[i] == who)
			{
				this->str[i] = what;
				isReplace = true;
				cout << "symbol replaced" << endl;
			}
		}
		if (isReplace == false)
		{
			cout << "there is no such symbol." << endl;
		}
	}
};

int main()
{
	MyString str1("123"); //copy
	MyString str2 = "133"; //copy

	MyString str3 = str1 + str2; // + and copy

	str1.replace('1', '2');//replaces '1' with '2'
	str1.print();//print string

	str1[0] = 'Q';// overloaded operator [] returns char and replace str[0] with 'Q'
	cout << str1[0] << endl;//demonstration of the overloaded operator []
	return 0;
}