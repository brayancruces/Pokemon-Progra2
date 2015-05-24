#pragma once
#include"Pokemon.h"

class ArregloPokemon{
protected:
	Pokemon** ArregloDePokemones;
	int* N;

public:

	ArregloPokemon();
	~ArregloPokemon();

	void AgregarPokemon(Pokemon* NuevoPokemon);
};

ArregloPokemon::ArregloPokemon()
{
	ArregloDePokemones = NULL;
	*N = 0;
}
ArregloPokemon::~ArregloPokemon()
{
	for (int i = 0; i < *N; i++)
		delete ArregloDePokemones[i];
	delete ArregloDePokemones;
}

void ArregloPokemon::AgregarPokemon(Pokemon* NuevoPokemon)
{

}