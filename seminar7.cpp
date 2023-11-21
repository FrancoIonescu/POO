#include <iostream>
using namespace std;

class Masina
{
	string marca;
	char* model;
	string nrInmatriculare;
	static int totalMasiniFabricate;

public:

	Masina(string marca, char* model, string nrInmatriculare) : marca(marca), nrInmatriculare(nrInmatriculare)
	{
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
		incrementCar();
	}

	void setMarca(string marca)
	{
		this->marca = marca;
	}
	void setModel(char* model)
	{
		this->model = new char[strlen(model) + 1];
		strcpy_s(this->model, strlen(model) + 1, model);
	}
	void setNrImatriculare(string nrInmatriculare)
	{
		this->nrInmatriculare = nrInmatriculare;
	}

	string getMarca()
	{
		return this->marca;
	}

	char* getModel()
	{
		char* temp = new char[strlen(this->model) + 1];
		strcpy_s(this->model, strlen(this->model) + 1, this->model);
		return temp;
		//return this->model;
	}

	string getNrInmatriculare()
	{
		return this->nrInmatriculare;
	}

	static int getTotalMasini()
	{
		return totalMasiniFabricate;
	}

	static void incrementCar()
	{
		Masina::totalMasiniFabricate++;
	}

	~Masina()
	{
		delete[] this->model;
	}
};

int Masina::totalMasiniFabricate = 0;



int main()
{

	Masina m("Dacia", (char*)"Spring", "B123AAA");
	//Masina::incrementCar();
	Masina m1("Renault", (char*)"Megane", "B123BBB");
	//Masina::incrementCar();


	return 0;
}
