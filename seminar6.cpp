#include <iostream>
#include <string>

using namespace std;

enum finantare
{
	TAXA = 1,
	BUGET = 2,
	BUGET_BURSA = 3
};

class Carte
{

private:
	char* titlu;
	string autor;
	int nrPagini;
	double pret;
	bool electronica;
	int* nrCuvPerPag;
public:
	void set_nrCuvPerPag(int* nrCuvPerPag, int nrPagini)
	{
		this->nrPagini = nrPagini;
		//this->note = _note;

		this->nrCuvPerPag = new int[nrPagini];
		for (int index = 0; index < nrPagini; index++)
		{
			this->nrCuvPerPag[index] = nrCuvPerPag[index];
		}
	}

	Carte(char* titlu, string autor, int nrPagini, double pret, bool electronica, int* nrCuvPerPag) : autor(autor), nrPagini(nrPagini), pret(pret), electronica(electronica) {

		this->titlu = new char[strlen(titlu) + 1];
		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
		this->nrCuvPerPag = new int[nrPagini];
		for (int index = 0; index < nrPagini; index++)
		{
			this->nrCuvPerPag[index] = nrCuvPerPag[index];
		}
	}

	Carte(const Carte& carte)
	{
		this->titlu = new char[strlen(carte.titlu) + 1];
		strcpy_s(this->titlu, strlen(carte.titlu) + 1, titlu);
		this->autor = carte.autor;
		this->nrPagini = carte.nrPagini;
		this->pret = carte.pret;
		this->electronica = carte.electronica;
		this->nrCuvPerPag = new int[carte.nrPagini];
		for (int index = 0; index < carte.nrPagini; index++)
		{
			this->nrCuvPerPag[index] = carte.nrCuvPerPag[index];
		}
	}

	~Carte()
	{
		delete[] this->titlu;
		delete[] this->nrCuvPerPag;
	}

	char* getTitlu(char* titlu)
	{
		return titlu;
	}
	string getAutor(string autor)
	{
		return autor;
	}
	int getPagini(int nrPagini)
	{
		return nrPagini;
	}
	double getPret(double pret)
	{
		return pret;
	}
};


class Student
{
public:
	string nume;
	char* adresa;
	int varsta;
	int an_studii;

	//constructori
	Student()
	{

	}

	Student(string _nume, char* _adresa, int _varsta, int _an_studii, int* _note, int _numar_materii, string _numar_matricol, finantare _finantare) :
		nume(_nume), varsta(_varsta), an_studii(_an_studii), numar_matricol(_numar_matricol), finantare(_finantare), numar_materii(_numar_materii)
	{
		//care este diferenta?
		// 
		//this->adresa = _adresa;

		this->adresa = new char[strlen(_adresa) + 1];
		strcpy_s(this->adresa, strlen(_adresa) + 1, _adresa);

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	// Implementarea constructorului de copiere va rezolva problema care genereaza exceptiile lansate la executia destructorului - incercarea de a 
				//dezaloca a doua oara aceeasi zona de memorie care a fost anterior dezalocata
	// Aceasta implementare apeleaza constructorul cu parametri. In cadrul constructorului cu parametri alocarea memoriei este facuta corect pentru cele doua variabile membre de tip pointer

	/*
	Student(const Student& student):
		Student(student.nume, student.adresa, student.varsta, student.an_studii, student.note, student.numar_materii, student.numar_matricol, student.finantare)
	{

	}*/
	

	//Sa se implementeze constructorul de copiere fara a apela constructorul cu parametri astfel incat:
   //				- copierea valorilor (in noul obiect) sa se realizeze corect  
   //              - dezalocarea memoriei sa se realizeze fara a genera exceptii
   
   
   Student(const Student& student) 
   {
	   this->nume = student.nume;
	   this->adresa = new char[strlen(student.adresa) + 1];
	   strcpy_s(this->adresa, strlen(student.adresa) + 1, student.adresa);
	   this->an_studii = student.an_studii;
	   this->finantare = student.finantare;
	   this->note = new int[student.numar_materii];
	   this->numar_materii = student.numar_materii;
	   this->note = new int[student.numar_materii];
	   for (int index = 0; index < numar_materii; index++)
	   {
		   this->note[index] = note[index];
	   }
	   this->varsta = student.varsta;

   }
   

   //setters
	void set_note(int* _note, int _numar_materii)
	{
		this->numar_materii = _numar_materii;
		//this->note = _note;

		this->note = new int[_numar_materii];
		for (int index = 0; index < _numar_materii; index++)
		{
			this->note[index] = _note[index];
		}
	}

	void set_numar_matricol(string _nr_matricol)
	{
		this->numar_matricol = _nr_matricol;
	}

	void set_finantare(finantare _finantare)
	{
		this->finantare = _finantare;
	}


	//getters
	int* get_note() { return this->note; }
	string get_numar_matricol() { return this->numar_matricol; }
	finantare get_finantare() { return this->finantare; }
	int get_numar_materii() { return this->numar_materii; }


	//destructor
	~Student()
	{
		delete this->adresa;
		delete this->note;
	}
private:
	int* note;
	string numar_matricol;
	finantare finantare;
	int numar_materii;


};


//exemple vizibilitate - constructori/destructori/metode/atribute
//exemplu constructor de copiere

int main()
{
	Student s0;

	s0.nume = "Anghel Mihai";

	s0.adresa = new char[20];
	strcpy_s(s0.adresa, 20, "Bucuresti, Sector 1");

	s0.varsta = 21;
	s0.an_studii = 2;

	//de ce este generata eroarea?
	//s0.note = new int[20];

	s0.set_numar_matricol("A689867");
	s0.set_finantare(finantare::BUGET_BURSA);

	// discutie eroare invalid heap pointer
	int note[10] = { 9,10,10,10,8,9,7,10,5,10 };
	s0.set_note(note, 10);
	int nrCuvPerPag[4] = { 50,30,30 };
	Carte carte = Carte((char*)"Book", "Autor",50,68.2,0,(int*)nrCuvPerPag);
	carte.set_nrCuvPerPag(nrCuvPerPag, 3);
	Student s1 = Student("Popescu I", (char*)"Bucuresti, Sector 1", 21, 2, note, 10, "A689867", finantare::BUGET_BURSA);

	Student s2 = s1;
	s2.nume = "Ionescu C";
}
