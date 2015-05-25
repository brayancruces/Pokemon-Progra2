#pragma once
#include "Pokemon.h"
class PokemonPlanta : protected Pokemon
{
public:

	PokemonPlanta(int Cordx, int Cordy, int anchoSprite, int alturaSprite);
	~PokemonPlanta();

};

PokemonPlanta::PokemonPlanta(int Cordx, int Cordy, int anchoSprite, int alturaSprite)
	: Pokemon(Cordx, Cordy, anchoSprite, alturaSprite)
{

}

PokemonPlanta::~PokemonPlanta()
{

}

//Pokemones Tipo Planta
class Bulbasaur : PokemonPlanta
{
public:
	Bulbasaur(int Cordx, int Cordy, int anchoSprite, int alturaSprite);
	~Bulbasaur();

};

Bulbasaur::Bulbasaur(int Cordx, int Cordy, int anchoSprite, int alturaSprite)
	: PokemonPlanta(Cordx, Cordy, anchoSprite, alturaSprite)
{
	


	setdirImagen("Resources\\img\\sprites\\pokemon\\battle\\bulbasaur_front.png");
	setNombre("Bulbasaur");

	setAtaque1("Latigo Sepa");
	setAtaque1("Maliciosos");
	setAtaque1("Somnifero");
	setAtaque1("BitchSlap!");

	setDanio1(20);
	setDanio1(0);
	setDanio1(10);
	setDanio1(50);
}
Bulbasaur::~Bulbasaur()
{

}