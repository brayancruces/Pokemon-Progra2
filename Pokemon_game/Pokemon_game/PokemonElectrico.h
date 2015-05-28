#pragma once
#include "Pokemon.h"

class PokemonElectrico : public Pokemon
{
public:
	 PokemonElectrico(void);
	~PokemonElectrico(void);
};

PokemonElectrico::PokemonElectrico() : Pokemon()
{
	Tipo = 1;
}

PokemonElectrico::~PokemonElectrico(void){}

//Pokemones Tipo Electrico
class Pikachu : public PokemonElectrico
{
public:
	 Pikachu(void);
	~Pikachu(void);
};

Pikachu::Pikachu(void): PokemonElectrico()
{
	setVida(60);
	setAncho(80);
	setAlto(80);
	setPokemonCapturado(true);

	setDirImagenFront("Resources\\img\\sprites\\pokemon\\battle\\pikachu_back.png");
	setDirImagenBack("Resources\\img\\sprites\\pokemon\\battle\\pikachu_back.png");
	setNombre("Pikachu");

	setAtaque1("Impactrueno");
	setAtaque2("QueRikachu");
	setAtaque3("Dedo");
	setAtaque4("AtaqueRapido");

	setDanio1(10);
	setDanio2(15);
	setDanio3(20);
	setDanio4(30);	
}

Pikachu::~Pikachu(void){}