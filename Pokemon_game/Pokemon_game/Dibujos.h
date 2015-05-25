#include "ArregloPokemon.h"


using namespace System::Drawing;


void DibujarStatsPokemon(Graphics^miGrafic, Pokemon* miPokemon, int Cordx, int Cordy){

	Font^Fuente = gcnew Font("Lucida Console", 14);
	System::String ^NombreDePokemon = gcnew System::String(miPokemon->getNombre());

	miGrafic->DrawString(NombreDePokemon, Fuente, Brushes::Red, Cordx + 5, Cordy + 5);
	miGrafic->DrawString(miPokemon->getVida().ToString(), Fuente, Brushes::Red, Cordx + 5, Cordy + 25);
	//gr->FillRectangle(Brushes::Red, x + 20, y + 20, dato->getvida()*4, 30);
}