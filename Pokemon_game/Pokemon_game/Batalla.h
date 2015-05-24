#pragma once

#include "ArregloPokemon.h"
#include "Dibujos.h"

using namespace System;
using namespace System::Drawing;


class Batalla
{
	ArregloPokemon* Entrenador1;
	ArregloPokemon* Entrenador2;
	Pokemon* Pokemon1;
	Pokemon* Pokemon2;

	int Indice;
	bool GanoEntrenador1;
	int Timer;
	bool TurnoEntrenador1;
	bool Final;



public:
	Batalla();
	~Batalla();
	void Dibujar(Graphics^ Graphic);
	void Batallar(char* TipoDeAtaque);
};


//Constructor
Batalla::Batalla()
{
	Entrenador1 = NULL;
	Entrenador2 = NULL;
	Pokemon1 = new Pokemon(5, 5, 5, 5);
	Pokemon2 = new Pokemon(5, 5, 5, 5);
	Timer = 0;
	TurnoEntrenador1 = true;
	Final = false;
	Indice = 0;

}

// Destructor
Batalla::~Batalla()
{
	delete Entrenador1;
	delete Entrenador2;

}

void Batalla::Dibujar(Graphics^ Graphic){

	if (!Final){

		System::Drawing::Rectangle rctPokemon = System::Drawing::Rectangle(0, 0, 80, 80);
		Graphic->DrawImage("template_BatallaPokemon.png", rctDestinoPokemon2, rctPokemon, System::Drawing::GraphicsUnit::Pixel);


		//Dibujando al pokemon Retador
		System::Drawing::Bitmap ^ bmpPokemon1 = gcnew System::Drawing::Bitmap("pikachu1.png");
		System::Drawing::Rectangle rctDestinoPokemon1 = System::Drawing::Rectangle(400, 50, 80, 80);
		Graphic->DrawImage(bmpPokemon1, rctDestinoPokemon1, rctPokemon, System::Drawing::GraphicsUnit::Pixel);

		//Dibujando a mi Pokemon
		System::Drawing::Bitmap ^ bmpPokemon2 = gcnew System::Drawing::Bitmap("pikachu2.png");
		System::Drawing::Rectangle rctDestinoPokemon2 = System::Drawing::Rectangle(200, 250, 80, 80);
		Graphic->DrawImage(bmpPokemon2, rctDestinoPokemon2, rctPokemon, System::Drawing::GraphicsUnit::Pixel);


		Graphic->FillRectangle(Brushes::Gray, 0, 350, 600, 150);
		Graphic->FillRectangle(Brushes::LightGray, 10, 360, 580, 130);
			

		if (turnoataque == true){

			infopokemon(gr, pokemon1, 50, 50);
			infopokemon(gr, pokemon2, 300, 300);
		}
		else
		{
			timer++;
		}

		if (timer > 5){
			timer = 0;
			turnoataque = true;
		}

		if (pokemon1->getvida() <= 0) fin = true;
		if (pokemon2->getvida() <= 0) fin = true;

	}
	else
	{
		gr->FillRectangle(Brushes::Gray, 50, 350, 500, 400);

	}

}
void Batalla::emularbatalla(ATTACK TURNO){

	switch (TURNO)
	{
	case ATAQUE1:

		pokemon2->setvida(pokemon2->getvida() - pokemon1->getdanio1());
		break;
	case ATAQUE2:

		pokemon2->setvida(pokemon2->getvida() - pokemon1->getdanio2());
		break;
	case ATAQUE3:
		pokemon2->setvida(pokemon2->getvida() - pokemon1->getdanio3());
		break;
	case ATAQUE4:
		pokemon2->setvida(pokemon2->getvida() - pokemon1->getdanio4());

		break;
	default:
		break;
	}

	int bot = rand() & 3;

	switch (bot)
	{
	case 0:
		pokemon1->setvida(pokemon1->getvida() - pokemon2->getdanio1());
		break;
	case 1:
		pokemon1->setvida(pokemon1->getvida() - pokemon2->getdanio2());
		break;
	case 2:
		pokemon1->setvida(pokemon1->getvida() - pokemon2->getdanio3());
		break;
	case 3:
		pokemon1->setvida(pokemon1->getvida() - pokemon2->getdanio4());
		break;
	default:
		pokemon1->setvida(pokemon1->getvida() - pokemon2->getdanio1());
		break;
	}

	turnoataque = false;

}
