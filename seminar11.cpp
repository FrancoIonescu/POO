#include <iostream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;

public:

	Date(): day(0), month(0), year(0) {}
	Date(int d,int m, int y) : day(d), month(m), year(y){}

};

class Person
{
	string name;
	string pin;
	Date birthday;
	string* addresses;
	int addressesCount;

public:
	Person()
	{
		this->name = "";
		this->pin = "";
		Date d;
		this->birthday = d;
		this->addresses = nullptr;
		this->addressesCount = 0;
	}

		Person(string name, string pin, Date birthday, string* adresses, int addressesCount) : birthday(birthday),addressesCount(addressesCount)
		{
			this->name = name;
			this->pin = pin;
			this->birthday = birthday;
			this->addresses = new string[addressesCount];
			for (int i = 0; i < addressesCount; i++)
			{
				this->addresses[i] = adresses[i];
			}
		}
		Person(const Person& p)
		{
			this->name = p.name;
			this->pin = p.pin;
			this->addressesCount = p.addressesCount;
			this->birthday = p.birthday;
			this->addresses = new string[p.addressesCount];
			for (int i = 0; i < p.addressesCount; i++)
			{
				this->addresses[i] = p.addresses[i];
			}
		}
		Person& operator=(const Person& p)
		{

			if (this == &p)
			{
				return *this;
			}

			this->name = p.name;
			this->pin = p.pin;
			this->addressesCount = p.addressesCount;
			this->birthday = p.birthday;
			this->addresses = new string[p.addressesCount];
			for (int i = 0; i < p.addressesCount; i++)
			{
				this->addresses[i] = p.addresses[i];
			}
			return *this;
		}
};

class Student: Person
{
	int regNo;
	float* grades;
	int gradesCount;
	bool scholarship;

public:

	Student(): Person()
	{
		this->regNo = 0;
		this->grades = nullptr;
		this->gradesCount = 0;
		this->scholarship = 0;
	}

	Student(string name, string pin, Date birthday, string* adresses, int addressesCount, int regNo,float* grades,int gradesCount, bool scholarship):
		Person(name, pin,  birthday,  adresses, addressesCount), regNo(regNo),gradesCount(gradesCount),scholarship(scholarship)
	{
		this->grades = new float[gradesCount];
		for (int i = 0; i < gradesCount; i++)
		{
			this->grades[i] = grades[i];
		}
	}

};

class University
{
	string name = "";
	string address = "";
	Student* students = nullptr;
	int studentsCount = 0;

public:
	University(string name, string address, Student* students, int studentsCount)
	{
		this->name = name;
		this->address = address;
		this->studentsCount = studentsCount;
		this->students = new Student[studentsCount];
		for (int i = 0; i < studentsCount; i++)
		{
			this->students[i] = students[i];
		}
	}
};


int main()
{

	Date d1;
	Date d2(6, 12, 2023);
	Person p1;
	string* addresses = new string[3];
	addresses[0] = "Bucuresti";
	addresses[1] = "Cluj";
	addresses[2] = "Oradea";

	Person p2("Popescu Andrei", "190029334",d2, addresses,3 );

	Student s1;
	float* grades = new float[5];
	grades[0] = 6;
	grades[1] = 5;
	grades[2] =7;
	grades[3] = 8;
	grades[4] = 10;
	Student s2("Popescu Andrei", "190029334", d2, addresses, 3, 123, grades,5, 1);
	Student s3("George Andrei", "190029334", d2, addresses, 3, 123, grades,5, 1);

	Student* students = new Student[3];
	students[0] = s1;
	students[1] = s2;
	students[2] = s3;
	University u1("ASE", "Bucuresti", students, 3);

	return 0;
}
