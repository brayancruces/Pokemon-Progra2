#pragma once
#include "ArregloPokemon.h"
#include "Dibujos.h"

class Batalla
{
	Pokemon* PokemonRetador;
	Pokemon* PokemonMio;

	int Timer;
	bool TurnoMio;
	bool Final;
	
public:
	 Batalla(void);
	~Batalla(void);
	void Dibujar(Graphics^ Graphic);
	void BatallarConMi(char* TipoDeAtaque);
};

//Constructor
Batalla::Batalla(void)
{
	Timer = 0;
	Final = false;
	TurnoMio = true;
	PokemonRetador = new Bulbasaur();
	PokemonMio = new Pikachu();
}

// Destructor
Batalla::~Batalla(void)
{
	delete PokemonRetador;
	delete PokemonMio;
}

void Batalla::Dibujar(Graphics^ Graphic){

	if (!Final){

		//Dibujado el campo de batalla
		Graphic->DrawImage(
			gcnew Bitmap("Resources\\img\\escenarios\\battle.png"),//Imagen del Pokemon
			Rectangle(0, 0, 600, 500),//---------------------------->Destino de la Imagen
			Rectangle(0, 0, 600, 500),//---------------------------->Porcion de la Imagen
			GraphicsUnit::Pixel//----------------------------------->Unidad de Medicion
			);
			
		PokemonRetador->DibujarPokemon(Graphic, 300, 0, 320, 320);
		PokemonMio->DibujarPokemon(Graphic, 80, 200, 160, 160);
		
		DibujarNombrePokemon(Graphic, PokemonRetador, 50, 45);
		DibujarNombrePokemon(Graphic, PokemonMio, 340, 245);
		DibujarAtaquesPokemon(Graphic, PokemonMio, 200, 380);

		if (TurnoMio){

			DibujarStatsPokemon(Graphic, PokemonRetador, 50, 50);
			DibujarStatsPokemon(Graphic, PokemonMio, 350, 255);
		}
		else
		{
			Timer++;
		}

		if (Timer > 5){
			Timer = 0;
			TurnoMio = true;
		}

		if (PokemonRetador->getVida() <= 0) Final = true;
		if (PokemonMio->getVida() <= 0) Final = true;

	}
	else
	{
		Graphic->FillRectangle(Brushes::White, 50, 120, 490, 200);
		Font^Fuente = gcnew Font("Lucida Console", 18);
		Fuente = gcnew System::Drawing::Font(Fuente, FontStyle::Bold);

		// Jugador ganó
		if (PokemonRetador->getVida() <= 0)
		{
			Graphic->DrawString("YOU WIN", Fuente, Brushes::Black, 240, 120);

		}

		//Bot ganó
		else{
			Graphic->DrawString("YOU LOOSE", Fuente, Brushes::Black, 240, 120);
		}


	}

}
void Batalla::BatallarConMi(char* TipoDeAtaque){

	if (strcmp(TipoDeAtaque,"Primera") == 0)
		PokemonRetador->setVida(PokemonRetador->getVida() - PokemonMio->getDanio1());
		
	else if (strcmp(TipoDeAtaque,"Segunda") == 0)
		PokemonRetador->setVida(PokemonRetador->getVida() - PokemonMio->getDanio2());

	else if (strcmp(TipoDeAtaque,"Tercera") == 0)
		PokemonRetador->setVida(PokemonRetador->getVida() - PokemonMio->getDanio3());

	else if (strcmp(TipoDeAtaque,"Especial") == 0)
		PokemonRetador->setVida(PokemonRetador->getVida() - PokemonMio->getDanio4());
	
	// Ataques del del Bot 
	int AtaqueRandom = rand() & 3;

	switch (AtaqueRandom)
	{
	case 0:
		PokemonMio->setVida(PokemonMio->getVida() - PokemonRetador->getDanio1());
		break;
	case 1:
		PokemonMio->setVida(PokemonMio->getVida() - PokemonRetador->getDanio2());
		break;
	case 2:
		PokemonMio->setVida(PokemonMio->getVida() - PokemonRetador->getDanio3());
		break;
	case 3:
		PokemonMio->setVida(PokemonMio->getVida() - PokemonRetador->getDanio4());
		break;
	}

	TurnoMio = false;

}
