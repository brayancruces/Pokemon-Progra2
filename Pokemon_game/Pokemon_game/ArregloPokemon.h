#pragma once
#include"Pokemon.h"
#include "PokemonElectrico.h"
#include "PokemonPlanta.h"

class ArregloPokemon{
protected:
	Pokemon** ArregloDePokemones;
	int* N;

public:

	 ArregloPokemon(void);
	~ArregloPokemon(void);

	void AgregarPokemon(Pokemon* NuevoPokemon);
};

ArregloPokemon::ArregloPokemon(void)
{
	ArregloDePokemones = NULL;
	*N = 0;
}

ArregloPokemon::~ArregloPokemon(void)
{
	for (int i = 0; i < *N; i++)
		delete ArregloDePokemones[i];
	delete ArregloDePokemones;
}

void ArregloPokemon::AgregarPokemon(Pokemon* NuevoPokemon){ }