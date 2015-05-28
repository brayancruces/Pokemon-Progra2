#pragma once
#include <stdlib.h>
#include <string.h>
using namespace System;
using namespace System::Drawing;

class Pokemon
{
protected:
	//Atributos
	int XImagen;
	int YImagen;
	int Ancho;
	int Alto;
	int Tipo;
	int Vida;
	int Vitalidad;
	int Experiencia;
	int Nivel;
	int Danio1;
	int Danio2;
	int Danio3;
	int Danio4;
	bool PokemonCapturado;
	char* Nombre;
	char* Ataque1;
	char* Ataque2;
	char* Ataque3;
	char* Ataque4;
	char* DirImagenFront;
	char* DirImagenBack;

public:
		 Pokemon(void);//Constructor
		~Pokemon(void);//Destructor

	//METODOS DE ACCESO
		// GET
		int getXImagen();
		int getYImagen();
		int getAncho();
		int getAlto();
		int getTipo();
		int getVida();
		int getVitalidad();
		int getExperiencia();
		int getNivel();
		int getDanio1();
		int getDanio2();
		int getDanio3();
		int getDanio4();
		bool getPokemonCapturado();
		char* getNombre();
		char* getAtaque1();
		char* getAtaque2();
		char* getAtaque3();
		char* getAtaque4();
		char* getDirImagen();
		
		//SET
		void setXImagen(int NuevoXImagen);
		void setYImagen(int NuevaYImagen);
		void setAncho(int NuevoAncho);
		void setAlto(int NuevoAlto);
		void setTipo(int NuevoTipo);
		void setVida(int NuevaVida);
		void setVitalidad(int NuevaVitalidad);
		void setExperiencia(int NuevaExperiencia);
		void setNivel(int NuevoNivel);
		void setDanio1(int NuevoDanio1);
		void setDanio2(int NuevoDanio2);
		void setDanio3(int NuevoDanio3);
		void setDanio4(int NuevoDanio4);
		void setPokemonCapturado(bool NuevoPokemonCapturado);
		void setNombre(char* NuevoNombre);
		void setDirImagenFront(char* NuevaDirImagenFront);
		void setDirImagenBack(char* NuevaDirImagenFront);
		void setAtaque1(char* NuevoAtaque1);
		void setAtaque2(char* NuevoAtaque2);
		void setAtaque3(char* NuevoAtaque3);
		void setAtaque4(char* NuevoAtaque4);

		//OTROS METODOS
		void DibujarPokemon(Graphics^ Graphic, int EsquinaX, int EsquinaY, int NuevoAncho, int NuevoAlto);
};

//Constructor
Pokemon::Pokemon(void)
{
	Experiencia = 0;
	Nivel = 1;
	Nombre = new char[15];
	Ataque1 = new char[20];
	Ataque2 = new char[20];
	Ataque3 = new char[20];
	Ataque4 = new char[20];
	DirImagenFront = new char[100];
	DirImagenBack = new char[100];
}

//Destructor
Pokemon::~Pokemon()
{
	delete[] Nombre;
	delete[] Ataque1;
	delete[] Ataque2;
	delete[] Ataque3;
	delete[] Ataque4;
	delete[] DirImagenFront;
	delete[] DirImagenBack;
}


// Metodos GET
int Pokemon::getXImagen(){ return XImagen; }
int Pokemon::getYImagen(){ return YImagen; }
int Pokemon::getTipo(){ return Tipo; }
int Pokemon::getVida(){ return Vida; }
int Pokemon::getExperiencia(){ return Experiencia; }
int Pokemon::getNivel(){ return Nivel; }
int Pokemon::getAncho(){ return Ancho; }
int Pokemon::getAlto(){ return Alto; }
int Pokemon::getDanio1(){ return Danio1; }
int Pokemon::getDanio2(){ return Danio2; }
int Pokemon::getDanio3(){ return Danio3; }
int Pokemon::getDanio4(){ return Danio4; }
char* Pokemon::getNombre(){ return Nombre; }
char* Pokemon::getAtaque1(){ return Ataque1; }
char* Pokemon::getAtaque2(){ return Ataque2; }
char* Pokemon::getAtaque3(){ return Ataque3; }
char* Pokemon::getAtaque4(){ return Ataque4; }
char* Pokemon::getDirImagen()
{
	if (PokemonCapturado)
		return DirImagenBack;
	else
		return DirImagenFront;
}

//Metodos SET
void Pokemon::setXImagen(int NuevoXImagen){ XImagen = NuevoXImagen; }
void Pokemon::setYImagen(int NuevaYImagen){ YImagen = NuevaYImagen; }
void Pokemon::setDanio1(int NuevoDanio1){ Danio1 = NuevoDanio1; }
void Pokemon::setDanio2(int NuevoDanio2){ Danio2 = NuevoDanio2; }
void Pokemon::setDanio3(int NuevoDanio3){ Danio3 = NuevoDanio3; }
void Pokemon::setDanio4(int NuevoDanio4){ Danio4 = NuevoDanio4; }
void Pokemon::setAncho(int NuevoAncho){ Ancho = NuevoAncho; }
void Pokemon::setAlto(int NuevoAlto){ Alto = NuevoAlto; }
void Pokemon::setTipo(int NuevoTipo){ Tipo = NuevoTipo; }
void Pokemon::setVida(int NuevaVida){ Vida = NuevaVida; }
void Pokemon::setExperiencia(int NuevaExperiencia){ Experiencia = NuevaExperiencia; }
void Pokemon::setNivel(int NuevoNivel){ Nivel = NuevoNivel; }
void Pokemon::setPokemonCapturado(bool NuevoPokemonCapturado){ PokemonCapturado = NuevoPokemonCapturado; }
void Pokemon::setNombre(char* NuevoNombre){ strcpy(Nombre, NuevoNombre); }
void Pokemon::setAtaque1(char* NuevoAtaque1){ strcpy(Ataque1, NuevoAtaque1); }
void Pokemon::setAtaque2(char* NuevoAtaque2){ strcpy(Ataque2, NuevoAtaque2); }
void Pokemon::setAtaque3(char* NuevoAtaque3){ strcpy(Ataque3, NuevoAtaque3); }
void Pokemon::setAtaque4(char* NuevoAtaque4){ strcpy(Ataque4, NuevoAtaque4); }
void Pokemon::setDirImagenFront(char* NuevaDirImagenFront){ strcpy(DirImagenFront, NuevaDirImagenFront); }
void Pokemon::setDirImagenBack(char* NuevaDirImagenBack){ strcpy(DirImagenBack, NuevaDirImagenBack); }

void Pokemon::DibujarPokemon(Graphics^ Graphic,int EsquinaX, int EsquinaY, int NuevoAncho, int NuevoAlto)
{
	//Dibujando al pokemon Retador
	Graphic->DrawImage(
		gcnew Bitmap(gcnew String(getDirImagen())),//--------->Imagen del Pokemon
		Rectangle(EsquinaX, EsquinaY, NuevoAncho, NuevoAlto),//Destino y Tamaño de la Imagen
		Rectangle(0, 0, Ancho, Alto),//----------------------->Porcion de la Imagen
		GraphicsUnit::Pixel//--------------------------------->Unidad de Medicion
		);
}



