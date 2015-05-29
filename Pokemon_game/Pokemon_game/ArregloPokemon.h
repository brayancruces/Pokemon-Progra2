#pragma once
#include"Pokemon.h"
#include "PokemonElectrico.h"
#include "PokemonPlanta.h"

class ArregloPokemon{
protected:
	Pokemon** ArregloDePokemones;
	int* TamanioDelArreglo;

public:

	 ArregloPokemon(void);
	~ArregloPokemon(void);

	Pokemon** CrearArregloPokemon();
	Pokemon* RetornaPokemon(int Indice);
	int getTamanioDelArreglo();
	void AgregarPokemon(Pokemon* NuevoPokemon);
	void EliminarPokemon(int Indice);
};

ArregloPokemon::ArregloPokemon(void)
{
	ArregloDePokemones = NULL;
	TamanioDelArreglo = new int;
	*TamanioDelArreglo = 0;
}

ArregloPokemon::~ArregloPokemon(void)
{
	for (int i = 0; i < *TamanioDelArreglo; i++)
		delete ArregloDePokemones[i];
	delete ArregloDePokemones;
}

Pokemon** ArregloPokemon::CrearArregloPokemon()
{
	return new Pokemon*[*TamanioDelArreglo + 1];
}

int ArregloPokemon::getTamanioDelArreglo(){
	return *TamanioDelArreglo;
}

Pokemon* ArregloPokemon::RetornaPokemon(int Indice){
	return ArregloDePokemones[Indice];
}

void ArregloPokemon::AgregarPokemon(Pokemon* NuevoPokemon)
{
	Pokemon** ArregloPokemonAuxiliar = CrearArregloPokemon();
	if (ArregloPokemonAuxiliar != NULL){
		for (int i = 0; i<*TamanioDelArreglo; i++)
			ArregloPokemonAuxiliar[i] = ArregloDePokemones[i];

		ArregloPokemonAuxiliar[*TamanioDelArreglo] = NuevoPokemon;
		*TamanioDelArreglo = *TamanioDelArreglo + 1;

		if (ArregloDePokemones != NULL)
			delete ArregloDePokemones;
		ArregloDePokemones = ArregloPokemonAuxiliar;
	}
}

void ArregloPokemon::EliminarPokemon(int Indice){
	Pokemon** ArregloDePokemonesAuxiliar = new Pokemon*[*TamanioDelArreglo - 1];
	if (ArregloDePokemonesAuxiliar != NULL)
	{
		//sobre la izquierda del indice a eliminar;
		for (int i = 0; i <= Indice - 1; i++)
			ArregloDePokemonesAuxiliar[i] = ArregloDePokemones[i];
		//sobre la derecha del indice a eliminar;
		for (int i = Indice + 1; i<*TamanioDelArreglo; i++)
			ArregloDePokemonesAuxiliar[i - 1] = ArregloDePokemones[i];

		*TamanioDelArreglo = *TamanioDelArreglo - 1;
		if (ArregloDePokemonesAuxiliar != NULL)
			delete ArregloDePokemonesAuxiliar;

		ArregloDePokemones = ArregloDePokemonesAuxiliar;
	}
}

	