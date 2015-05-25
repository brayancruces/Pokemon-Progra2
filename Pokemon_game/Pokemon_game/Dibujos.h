#include "ArregloPokemon.h"
//#include <stdlib.h>

using namespace System::Drawing;


void DibujarStatsPokemon(Graphics^miGrafic, char* NombrePokemon, int VidaPokemon, int Cordx, int Cordy){

	Font^Fuente = gcnew Font("Lucida Console", 14);


	miGrafic->DrawString(NombrePokemon, Fuente, Brushes::Red, Cordx + 5, Cordy + 5);
	miGrafic->DrawString(VidaPokemon, Fuente, Brushes::Red, Cordx + 5, Cordy + 25);
	//gr->FillRectangle(Brushes::Red, x + 20, y + 20, dato->getvida()*4, 30);
}