#pragma once
#include "Marco.h"
#include "Lider.h"
#include "Dibujos.h"
//#include "Juego.h";

class Batalla
{
private:
	Pokemon* PokemonRetador;
	Pokemon* PokemonMio;
	bool Gane;
	int ContadorDeTurnos;
	
public:
	 Batalla(void);
	 Batalla(Entrenador* NuestroMarco, Entrenador* LiderDeGimnasio);
	~Batalla(void);
	int getContadorDeTurnos();
	Pokemon* getPokemonRetador();
	Pokemon* getPokemonMio();
	void setContadorDeTurnos(int NuevoContadorDeTurnos);
	void DibujarEscenario(Graphics^ Graphic);
	void ActualizarEscenario(Graphics^ Graphic);
	void BatallarConMi(Graphics^ Graphic, char* TipoDeAtaque);
	void ElRivalBatalla(Graphics^ Graphic);
	void Fin(Graphics^ Graphic);
};

//Constructor
Batalla::Batalla(void){}
Batalla::Batalla(Entrenador* NuestroMarco, Entrenador* LiderDeGimnasio)
{
	ContadorDeTurnos = -1;
	PokemonMio = NuestroMarco->getArregloPokemon()->RetornaPokemon(0);
	PokemonRetador = LiderDeGimnasio->getArregloPokemon()->RetornaPokemon(0);
	
}

// Destructor
Batalla::~Batalla(void)
{
	delete PokemonRetador;
	delete PokemonMio;
}

int Batalla::getContadorDeTurnos(){ return ContadorDeTurnos; }
void Batalla::setContadorDeTurnos(int NuevoContadorDeTurnos){ ContadorDeTurnos = NuevoContadorDeTurnos; }
Pokemon* Batalla::getPokemonRetador(){ return PokemonRetador; }
Pokemon* Batalla::getPokemonMio(){ return PokemonMio; }
void Batalla::DibujarEscenario(Graphics^ Graphic)
{
	Graphic->DrawImage(
		gcnew Bitmap("Resources\\img\\escenarios\\BatallaNormal.png"),//Imagen del Pokemon
		Rectangle(0, 0, 600, 500),//---------------------------->Destino de la Imagen
		Rectangle(0, 0, 600, 500),//---------------------------->Porcion de la Imagen
		GraphicsUnit::Pixel//----------------------------------->Unidad de Medicion
		);
	PokemonRetador->DibujarPokemon(Graphic, 300, 0, 280, 280);
	PokemonMio->DibujarPokemon(Graphic, 80, 200, 160, 160);

	DibujarCuadroPokemon(Graphic, PokemonRetador, 50, 50);
	DibujarCuadroPokemon(Graphic, PokemonMio, 310, 240);

	DibujarAtaquesPokemon(Graphic, PokemonMio, 200, 380);

	ContadorDeTurnos = 0;
}

void Batalla::ActualizarEscenario(Graphics^ Graphic)
{
	DibujarCuadroPokemon(Graphic, PokemonRetador, 50, 50);
	DibujarCuadroPokemon(Graphic, PokemonMio, 310, 240);
}
	

void Batalla::BatallarConMi(Graphics^ Graphic, char* TipoDeAtaque){

	if (strcmp(TipoDeAtaque,"Primera") == 0)
		PokemonRetador->setVida(PokemonRetador->getVida() - PokemonMio->getDanio1());
		
	else if (strcmp(TipoDeAtaque,"Segunda") == 0)
		PokemonRetador->setVida(PokemonRetador->getVida() - PokemonMio->getDanio2());

	else if (strcmp(TipoDeAtaque,"Tercera") == 0)
		PokemonRetador->setVida(PokemonRetador->getVida() - PokemonMio->getDanio3());

	else if (strcmp(TipoDeAtaque,"Especial") == 0)
		PokemonRetador->setVida(PokemonRetador->getVida() - PokemonMio->getDanio4());
	
	ContadorDeTurnos = 1;
	if (ContadorDeTurnos == 2)
		ContadorDeTurnos = 0;
	
	if (PokemonMio->getVida() <= 0 || PokemonRetador->getVida() <= 0)
	{
		ContadorDeTurnos = 5;
	}  

	else
		ElRivalBatalla(Graphic);
}

void Batalla::ElRivalBatalla(Graphics^ Graphic)
{
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

	ContadorDeTurnos = 2;
	if (ContadorDeTurnos == 0)
		ContadorDeTurnos = 0;

	if (PokemonMio->getVida() <= 0 || PokemonRetador->getVida() <= 0)
	{
		ContadorDeTurnos = 5;
	}
		
}

void Batalla::Fin(Graphics^ Graphic)
{
	ContadorDeTurnos = 0;
	Graphic->FillRectangle(Brushes::White, 50, 120, 490, 200);
	Font^Fuente = gcnew Font("Lucida Console", 18);
	Fuente = gcnew System::Drawing::Font(Fuente, FontStyle::Bold);
	
	if (Gane){Graphic->DrawString("YOU WIN", Fuente, Brushes::Black, 240, 120);}
	
	else{Graphic->DrawString("YOU LOSE", Fuente, Brushes::Black, 240, 120);}
}

