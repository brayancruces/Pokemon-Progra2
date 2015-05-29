#pragma once
#include "Batalla.h";


using namespace System;
using namespace System::Drawing;

class Juego
{
protected:
	int Escena;
public:
	Juego(void);
	~Juego(void);
	bool TerminoLaBatalla(Batalla* LaBatalla);
	void FinBatalla1(Graphics^ Graphic, Batalla* BatallaConLider1);
	int getEscena();
	void setEscena(int NuevaEscena);
};

Juego::Juego(void)
{
	Escena = 0;
}
Juego::~Juego(void){}

void Juego::FinBatalla1(Graphics^ Graphic, Batalla* BatallaConLider1){
	
	Graphic->FillRectangle(Brushes::White, 50, 120, 490, 200);
	Font^Fuente = gcnew Font("Lucida Console", 18);
	Fuente = gcnew System::Drawing::Font(Fuente, FontStyle::Bold);

	if (BatallaConLider1->getPokemonMio()->getVida() <= 0)
		Graphic->DrawString("YOU LOSE", Fuente, Brushes::Black, 240, 120);
	else if (BatallaConLider1->getPokemonRetador()->getVida() <= 0)
		Graphic->DrawString("YOU WIN", Fuente, Brushes::Black, 240, 120);
	Escena = 2;
	
}
int Juego::getEscena(){ return Escena; }
void Juego::setEscena(int NuevaEscena){ Escena = NuevaEscena; }