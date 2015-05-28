#pragma once
#include "Pokemon.h"

class PokemonPlanta : public Pokemon
{
public:
	 PokemonPlanta(void);
	~PokemonPlanta(void);
};

PokemonPlanta::PokemonPlanta(void) : Pokemon()
{
	Tipo == 2;
}

PokemonPlanta::~PokemonPlanta(void){}

//Pokemones Tipo Planta
class Bulbasaur : public PokemonPlanta
{
public:
	 Bulbasaur(void);
	~Bulbasaur(void);
};

Bulbasaur::Bulbasaur(void) : PokemonPlanta()
{
	setVida(80);
	setAncho(80);
	setAlto(80);
	setPokemonCapturado(false);
	
	setDirImagenFront("Resources\\img\\sprites\\pokemon\\battle\\bulbasaur_front.png");
	setDirImagenBack("Resources\\img\\sprites\\pokemon\\battle\\bulbasaur_back.png");
	setNombre("Bulbasaur"); 

	setAtaque1("Latigo Sepa");
	setAtaque2("Maliciosos");
	setAtaque3("Somnifero");
	setAtaque4("BitchSlap!");

	setDanio1(10);
	setDanio2(15);
	setDanio3(20);
	setDanio4(30);
}
Bulbasaur::~Bulbasaur(void){}