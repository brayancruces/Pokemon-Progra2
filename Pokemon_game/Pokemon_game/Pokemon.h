#pragma once
#include <stdlib.h>
#include <string.h>

class Pokemon
{
private:
	//Atributos
	int X, Y, Ancho, Altura;
	char* Nombre;
	int Tipo;
	bool Retador; // verificamos condicion de pokemon salvaje
	int Vida;
	int Experiencia;
	int Nivel;
	char* Ataque1;
	char* Ataque2;
	char* Ataque3;
	char* Ataque4;
	int Danio1, Danio2, Danio3, Danio4;

public:
	//METODOS
		//Constructor
		Pokemon();
		Pokemon(int Cordx, int Cordy, int anchoSprite, int alturaSprite);
		//Destructor
		~Pokemon();

	//METODOS DE ACCESO
		// GET
		int getX();
		int getY();
		int getAncho();
		int getAltura();
		char* getNombre();
		int getTipo();
		bool getRetador();
		int getVida();
		int getExperiencia();
		int getNivel();
		char* getAtaque1();
		char* getAtaque2();
		char* getAtaque3();
		char* getAtaque4();
		int getDanio1();
		int getDanio2();
		int getDanio3();
		int getDanio4();

		//SET
		void setX(int nuevo);
		void setY(int nuevo);
		void setAncho(int nuevo);
		void setAltura(int nuevo);
		void setNombre(char* nuevo);
		void setTipo(char* nuevo);
		void setRetador(bool nuevo);
		void setVida(int nuevo);
		void setExperiencia(int nuevo);
		void setNivel(int nuevo);
		void setDanio1(int nuevo);
		void setDanio2(int nuevo);
		void setDanio3(int nuevo);
		void setDanio4(int nuevo);

};

//Constructor
Pokemon::Pokemon(){}
Pokemon::Pokemon(int Cordx, int Cordy, int anchoSprite, int alturaSprite){
	X = Cordx;
	Y = Cordy;
	Ancho = anchoSprite;
	Altura = alturaSprite;

	Nombre = new char[100];
	Tipo = 0;
    Ataque1 = new char[100];
	Ataque2 = new char[100];
	Ataque3 = new char[100];
	Ataque4 = new char[100];

	Vida = 30 + rand() % 30;
	Experiencia = rand() % 800;
	Nivel = 1 + Experiencia / 200;
	Retador = true;
	Danio1 = Nivel + rand() % 4;
	Danio2 = Nivel + rand() % 4;
	Danio3 = Nivel * 2 + rand() % 4;
	Danio4 = Nivel * 2 + rand() % 4;

}

//Destructor
Pokemon::~Pokemon(){}
//METODOS DE ACCESO


// GET
int Pokemon::getX(){ return X; }
int Pokemon::getY(){ return Y; }
int Pokemon::getAncho(){ return Ancho; }
int Pokemon::getAltura(){ return Altura; }
char* Pokemon::getNombre(){ return Nombre; }
int Pokemon::getTipo(){ return Tipo; }
bool Pokemon::getRetador(){ return Retador; }
int Pokemon::getVida(){ return Vida; }
int Pokemon::getExperiencia(){ return Experiencia; }
int Pokemon::getNivel(){ return Nivel; }
char* Pokemon::getAtaque1(){ return Ataque1; }
char* Pokemon::getAtaque2(){ return Ataque2; }
char* Pokemon::getAtaque3(){ return Ataque3; }
char* Pokemon::getAtaque4(){ return Ataque4; }
int Pokemon::getDanio1(){ return Danio1; }
int Pokemon::getDanio2(){ return Danio2; }
int Pokemon::getDanio3(){ return Danio3; }
int Pokemon::getDanio4(){ return Danio4; }

//SET
void Pokemon::setX(int nuevo){ X = nuevo; }
void Pokemon::setY(int nuevo){ Y = nuevo; }
void Pokemon::setAncho(int nuevo){ Ancho = nuevo; }
void Pokemon::setAltura(int nuevo){ Altura = nuevo; }
void Pokemon::setNombre(char* nuevo){ strcpy(Nombre, nuevo); }
void Pokemon::setTipo(char* nuevo){ strcpy(Nombre, nuevo); }
void Pokemon::setRetador(bool nuevo){ Retador = nuevo; }
void Pokemon::setVida(int nuevo){ Vida = nuevo; }
void Pokemon::setExperiencia(int nuevo){ Experiencia = nuevo; }
void Pokemon::setNivel(int nuevo){ Experiencia = nuevo; }
void Pokemon::setDanio1(int nuevo){ Danio1 = nuevo; }
void Pokemon::setDanio2(int nuevo){ Danio2 = nuevo; }
void Pokemon::setDanio3(int nuevo){ Danio3 = nuevo; }
void Pokemon::setDanio4(int nuevo){ Danio4 = nuevo; }


