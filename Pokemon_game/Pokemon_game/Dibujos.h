#include "ArregloPokemon.h"
//#include <stdlib.h>

using namespace System::Drawing;


void DibujarStatsPokemon(Graphics^miGrafic, Pokemon* miPokemon, int Cordx, int Cordy){

	Font^Fuente = gcnew Font("Lucida Console", 14);

	miGrafic->DrawRectangle(Pens::Red, Cordx, Cordy, 150, 50);
	miGrafic->DrawString("Pompinchu", Fuente, Brushes::Red, Cordx + 5, Cordy + 5);
	miGrafic->DrawString(miPokemon->getVida().ToString(), Fuente, Brushes::Red, Cordx + 5, Cordy + 25);
	//gr->FillRectangle(Brushes::Red, x + 20, y + 20, dato->getvida()*4, 30);
}