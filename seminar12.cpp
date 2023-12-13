#include <iostream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;

public:

	Date() : day(0), month(0), year(0) {}
	Date(int d, int m, int y) : day(d), month(m), year(y) {}

};

class Person
{
protected: 
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

	Person(string name, string pin, Date birthday, string* adresses, int addressesCount) : birthday(birthday), addressesCount(addressesCount)
	{
		this->name = name;
		this->pin = pin;
		this->birthday = birthday;
		if (addresses != nullptr)
		{
			this->addresses = new string[addressesCount];
			for (int i = 0; i < addressesCount; i++)
			{
				this->addresses[i] = addresses[i];
			}
		}
		else
		{
			this->addresses = nullptr;
		}
	}
	Person(const Person& p)
	{
		this->name = p.name;
		this->pin = p.pin;
		this->addressesCount = p.addressesCount;
		this->birthday = p.birthday;
		if (this->addresses != nullptr)
		{
			this->addresses = new string[p.addressesCount];
			for (int i = 0; i < p.addressesCount; i++)
			{
				this->addresses[i] = p.addresses[i];
			}
		}
		else
		{
			this->addresses = nullptr;
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
		if (p.addresses != nullptr)
		{
			this->addresses = new string[p.addressesCount];
			for (int i = 0; i < p.addressesCount; i++)
			{
				this->addresses[i] = p.addresses[i];
			}
		}
		else
		{
			this->addresses = nullptr;
		}
		return *this;
	}

	virtual string displayDetails()
	{
		return "I'm a person";
	}

	~Person()
	{
		delete[] addresses;
	}
};

class Student : public Person
{
	int regNo;
	float* grades;
	int gradesCount;
	bool scholarship;

public:

	Student() : Person()
	{
		this->regNo = 0;
		this->grades = nullptr;
		this->gradesCount = 0;
		this->scholarship = 0;
	}

	Student(string name, string pin, Date birthday, string* adresses, int addressesCount, int regNo, float* grades, int gradesCount, bool scholarship) :
		Person(name, pin, birthday, adresses, addressesCount), regNo(regNo), gradesCount(gradesCount), scholarship(scholarship)
	{
		if (grades != nullptr && gradesCount != 0)
		{
			this->gradesCount = gradesCount;
			this->grades = new float[gradesCount];
			for (int i = 0; i < gradesCount; i++)
			{
				this->grades[i] = grades[i];
			}
		}
		else
		{
			this->grades = nullptr;
			this->gradesCount = 0;
		}
	}

	Student(const Student& s)
	{
		this->regNo = s.regNo;
		this->scholarship = s.scholarship;
		if (s.grades != nullptr && s.gradesCount != 0)
		{
			this->gradesCount = s.gradesCount;
			this->grades = new float[s.gradesCount];
			for (int i = 0; i < s.gradesCount; i++)
			{
				this->grades[i] = s.grades[i];
			}
		}
		else
		{
			this->grades = nullptr;
			this->gradesCount = 0;
		}

	}
	Student& operator=(const Student& s)
	{

		if (this == &s)
		{
			return *this;
		}

		this->regNo = s.regNo;
		this->scholarship = s.scholarship;
		if (s.grades != nullptr && s.gradesCount != 0)
		{
			this->gradesCount = s.gradesCount;
			this->grades = new float[s.gradesCount];
			for (int i = 0; i < s.gradesCount; i++)
			{
				this->grades[i] = s.grades[i];
			}
		}
		else
		{
			this->grades = nullptr;
			this->gradesCount = 0;
		}
		return *this;
	}

	string displayDetails() override
	{
		return "I'm a student";
	}

	~Student()
	{
		delete[] grades;
	}

};

class Professor: public Person
{
	float salary;
public:
	Professor() :Person()
	{
		this->salary = 0;
	}
	Professor(string name, string pin, Date birthday, string* adresses, int addressesCount, float salary) : Person(name, pin, birthday, addresses, addressesCount)
	{
		this->salary = salary;
	}

	string displayDetails() override
	{
		return "I'm a professor";
	}
};

class University
{
	string name = "";
	string address = "";
	Student* students = nullptr;
	int studentsCount = 0;

	Person** all = nullptr;
	int countAll = 0;

public:
	University(string name, string address, Student* students, int studentsCount)
	{
		this->name = name;
		this->address = address;
		this->studentsCount = studentsCount;
		if (students != nullptr)
		{
			this->students = new Student[studentsCount];
			for (int i = 0; i < studentsCount; i++)
			{
				this->students[i] = students[i];
			}
		}
		else
		{
			this->students = nullptr;
		}
	}

	void setAllPersons(Person** allPers, int countP)
	{
		this->countAll = countP;
		this->all = allPers;
		/*this->all = new Person * [countP];
		for (int i = 0; i < countP; i++)
		{
			this->all[i] = allPers[i];
		}*/
	}

	void listAllPersons()
	{
		for (int i = 0; i < this->countAll; i++)
		{
			cout << this->all[i]->displayDetails() << endl;
		}
	}
};

class A
{
	string attrA = "";
public:
	A(string aatrA): attrA(attrA) {}
	virtual string show()
	{
		return "Eu sunt A";
	}

};

class B : public A
{
	string attrB = "";
public:
	B(string attrA, string attrB) :A(attrA), attrB(attrB) {
		/*	
			
		*/
	}
	string show() override
	{
		return "Eu sunt B";
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

	Person p2("Popescu Andrei", "190029334", d2, addresses, 3);

	Student s1;
	float* grades = new float[5];
	grades[0] = 6;
	grades[1] = 5;
	grades[2] = 7;
	grades[3] = 8;
	grades[4] = 10;
	Student s2("Popescu Andrei", "190029334", d2, addresses, 3, 123, grades, 5, 1);
	Student s3("George Andrei", "190029334", d2, addresses, 3, 123, grades, 5, 1);

	Student* students = new Student[3];
	students[0] = s1;
	students[1] = s2;
	students[2] = s3;

	Person** all = new Person* [3];
	Person* person = new Person("Popescu Andrei", "190029334", d2, addresses, 3);
	Person* student = new Student("Andresan Andrei", "190029334", d2, addresses, 3, 123, grades, 5, 1);
	Person* professor = new Professor("Profesor Andrei", "4543", d2, addresses, 3, 4500);

	all[0] = person;
	all[1] = student;
	all[2] = professor;

	University u1("ASE", "Bucuresti", students, 3);
	u1.setAllPersons(all, 3);
	u1.listAllPersons();
	A** vect = new A * [4];
	vect[0] = new A("awd");
	vect[1] = new B("awsw", "awsw");
	vect[2] = new B("wew", "awsw");
	vect[3] = new A("wed");
	cout << vect[0]->show() << endl;
	cout << vect[1]->show() << endl;
	cout << vect[2]->show() << endl;
	cout << vect[3]->show() << endl;
	
	return 0;
}
