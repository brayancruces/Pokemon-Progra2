#pragma once
#include "Pokemon.h"
class PokemonElectrico : public Pokemon
{
public:
	PokemonElectrico(int Cordx, int Cordy, int anchoSprite, int alturaSprite);
	~PokemonElectrico();
};


PokemonElectrico::PokemonElectrico(int Cordx, int Cordy, int anchoSprite, int alturaSprite) 
	: Pokemon(Cordx, Cordy, anchoSprite, alturaSprite)
{
	
}


PokemonElectrico::~PokemonElectrico()
{

}

//Pokemones Tipo Electrico
class Pikachu : PokemonElectrico
{
public:
	Pikachu(int Cordx, int Cordy, int anchoSprite, int alturaSprite);
	~Pikachu();

};

Pikachu::Pikachu(int Cordx, int Cordy, int anchoSprite, int alturaSprite)
	: PokemonElectrico(Cordx, Cordy, anchoSprite, alturaSprite)
{


	setdirImagen("Resources\\img\\sprites\\pokemon\\battle\\pikachu_back.png");
	setNombre("Pikachu");

	setAtaque1("Impactrueno");
	setAtaque1("QueRikachu");
	setAtaque1("Dedo");
	setAtaque1("AtaqueRapido");

	setDanio1(40);
	setDanio1(0);
	setDanio1(100);
	setDanio1(5);

	
}
Pikachu::~Pikachu()
{

}