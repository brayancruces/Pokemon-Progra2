#include "ArregloPokemon.h"

void DibujarNombrePokemon(Graphics^miGrafic, Pokemon* miPokemon, int Cordx, int Cordy){

	Font^Fuente = gcnew Font("Lucida Console", 15,FontStyle::Bold);
	System::String ^NombreDePokemon = gcnew System::String(miPokemon->getNombre());

	miGrafic->DrawString(
		gcnew String(miPokemon->getNombre()),//------------>El Nombre del Pokemon
		gcnew Font("Lucida Console", 15, FontStyle::Bold),//La Fuente
		Brushes::Black,//---------------------------------->El Color
		Cordx + 5,//--------------------------------------->La Coordenada X
		Cordy + 5//---------------------------------------->La Coordenada Y
		);
}

void DibujarStatsPokemon(Graphics^miGrafic, Pokemon* miPokemon, int Cordx, int Cordy){
	
	miGrafic->DrawString(
		miPokemon->getVida().ToString(),//------------------->La Vida del Pokemon
		gcnew Font("Lucida Console", 14, FontStyle::Bold),//->La Fuente
		gcnew SolidBrush(Color::FromArgb(110, 218, 163)),//-->El Color
		Cordx + 5,//----------------------------------------->La Coordenada X
		Cordy + 25//----------------------------------------->La Coordenada Y
		);
}

void DibujarAtaquesPokemon(Graphics^miGrafic, Pokemon* miPokemon, int Cordx, int Cordy){

	Font^Fuente = gcnew Font("Lucida Console", 14);

	//capturar ataques
	String ^Ataque1 = gcnew String(miPokemon->getAtaque1());
	String ^Ataque2 = gcnew String(miPokemon->getAtaque2());
	String ^Ataque3 = gcnew String(miPokemon->getAtaque3());
	String ^Ataque4 = gcnew String(miPokemon->getAtaque4());

	miGrafic->DrawString(Ataque1, Fuente, Brushes::WhiteSmoke, Cordx + 5, Cordy + 5);
	miGrafic->DrawString(Ataque2, Fuente, Brushes::WhiteSmoke, Cordx + 5, Cordy + 25);
	miGrafic->DrawString(Ataque3, Fuente, Brushes::WhiteSmoke, Cordx + 5, Cordy + 45);
	miGrafic->DrawString(Ataque4, Fuente, Brushes::WhiteSmoke, Cordx + 5, Cordy + 65);

}

