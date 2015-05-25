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
	void BatallarConMi(char* TipoDeAtaque);
};


//Constructor
Batalla::Batalla()
{
	Entrenador1 = NULL;
	Entrenador2 = NULL;
	Pokemon1 = new Bulbasaur(5, 5, 5, 5);
	Pokemon2 = new Pikachu(5, 5, 5, 5);
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

		//Dibujado el template de la batalla
		System::Drawing::Bitmap ^ bmpTemplateBatalla = gcnew System::Drawing::Bitmap("Resources\\img\\escenarios\\battle.png");
		System::Drawing::Rectangle rctDestinoBatalla= System::Drawing::Rectangle(0, 0, 600, 500);
		Graphic->DrawImage(bmpTemplateBatalla, rctDestinoBatalla, Rectangle(0, 0, 600, 500), GraphicsUnit::Pixel);
		
		//Dibujando al pokemon Retador
		System::Drawing::Bitmap ^ bmpPokemon1 = gcnew System::Drawing::Bitmap("Resources\\img\\sprites\\pokemon\\battle\\bulbasaur_front.png");
		System::Drawing::Rectangle rctDestinoPokemon1 = System::Drawing::Rectangle(400, 50, 80, 80);
		Graphic->DrawImage(bmpPokemon1, rctDestinoPokemon1, rctPokemon, System::Drawing::GraphicsUnit::Pixel);

		//Dibujando a mi Pokemon
		System::Drawing::Bitmap ^ bmpPokemon2 = gcnew System::Drawing::Bitmap("Resources\\img\\sprites\\pokemon\\battle\\pikachu_back.png");
		System::Drawing::Rectangle rctDestinoPokemon2 = System::Drawing::Rectangle(200, 250, 80, 80);
		Graphic->DrawImage(bmpPokemon2, rctDestinoPokemon2, rctPokemon, System::Drawing::GraphicsUnit::Pixel);


		//Graphic->FillRectangle(Brushes::Gray, 0, 350, 600, 150);
		//Graphic->FillRectangle(Brushes::LightGray, 10, 360, 580, 130);
			

		if (TurnoEntrenador1){

			DibujarStatsPokemon(Graphic, Pokemon1, 50, 50);
			DibujarStatsPokemon(Graphic, Pokemon2, 300, 300);
		}
		else
		{
			Timer++;
		}

		if (Timer > 5){
			Timer = 0;
			TurnoEntrenador1 = true;
		}

		if (Pokemon1->getVida() <= 0) Final = true;
		if (Pokemon2->getVida() <= 0) Final = true;

	}
	else
	{
		Graphic->FillRectangle(Brushes::Gray, 50, 350, 500, 400);

	}

}
void Batalla::BatallarConMi(char* TipoDeAtaque){

	// Ataques de mi pokemon
	if (strcmp(TipoDeAtaque,"Primera") == 0)
		Pokemon2->setVida(Pokemon2->getVida() - Pokemon1->getDanio1());
		
	else if (strcmp(TipoDeAtaque,"Segunda") == 0)
		Pokemon2->setVida(Pokemon2->getVida() - Pokemon1->getDanio2());

	else if (strcmp(TipoDeAtaque,"Tercera") == 0)
		Pokemon2->setVida(Pokemon2->getVida() - Pokemon1->getDanio3());

	else if (strcmp(TipoDeAtaque,"Ultimate") == 0)
		Pokemon2->setVida(Pokemon2->getVida() - Pokemon1->getDanio4());
	
	// Ataques del del Bot 
	int AtaqueRandom = rand() & 3;

	switch (AtaqueRandom)
	{
	case 0:
		Pokemon1->setVida(Pokemon1->getVida() - Pokemon2->getDanio1());
		break;
	case 1:
		Pokemon1->setVida(Pokemon1->getVida() - Pokemon2->getDanio2());
		break;
	case 2:
		Pokemon1->setVida(Pokemon1->getVida() - Pokemon2->getDanio3());
		break;
	case 3:
		Pokemon1->setVida(Pokemon1->getVida() - Pokemon2->getDanio4());
		break;
	}

	TurnoEntrenador1 = false;

}
