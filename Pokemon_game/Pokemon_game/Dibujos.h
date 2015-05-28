#include "ArregloPokemon.h"

void DibujarCuadroPokemon(Graphics^miGraphic, Pokemon* miPokemon, int Cordx, int Cordy){

	int Ancho, Alto;
	int XVariable, YVariable;
	String^ CuadroPokemon;

	if (miPokemon->getPokemonCapturado())
	{	
		Ancho = 281; Alto = 101;
		XVariable = Cordx + 25;
		YVariable = Cordy + 12;
		CuadroPokemon = gcnew String("Resources\\img\\escenarios\\CuadroDeStatsMio.png");
	}
	else
	{
		Ancho = 254; Alto = 77;
		XVariable = Cordx + 8;
		YVariable = Cordy + 3;
		CuadroPokemon = gcnew String("Resources\\img\\escenarios\\CuadroDeStatsRetador.png");
	}

	miGraphic->DrawImage(
		gcnew Bitmap(CuadroPokemon),//-------->Imagen del Pokemon
		Rectangle(Cordx, Cordy, Ancho, Alto),//Destino y Tamaño de la Imagen
		Rectangle(0, 0, Ancho, Alto),//------->Porcion de la Imagen
		GraphicsUnit::Pixel//----------------->Unidad de Medicion
		);

	miGraphic->DrawString(
		gcnew String(miPokemon->getNombre()),//------------>El Nombre del Pokemon
		gcnew Font("Lucida Console", 15, FontStyle::Bold),//La Fuente
		Brushes::Black,//---------------------------------->El Color
		XVariable + 5,//--------------------------------------->La Coordenada X
		YVariable + 10//---------------------------------------->La Coordenada Y
		);

	miGraphic->DrawString(
		miPokemon->getVida().ToString(),//------------------->La Vida del Pokemon
		gcnew Font("Lucida Console", 14, FontStyle::Bold),//->La Fuente
		gcnew SolidBrush(Color::FromArgb(110, 218, 163)),//-->El Color
		XVariable + 5,//----------------------------------------->La Coordenada X
		YVariable + 30//----------------------------------------->La Coordenada Y
		);
}

void DibujarAtaquesPokemon(Graphics^miGrapfic, Pokemon* miPokemon, int Cordx, int Cordy){

	Font^Fuente = gcnew Font("Lucida Console", 14);

	//capturar ataques
	String ^Ataque1 = gcnew String(miPokemon->getAtaque1());
	String ^Ataque2 = gcnew String(miPokemon->getAtaque2());
	String ^Ataque3 = gcnew String(miPokemon->getAtaque3());
	String ^Ataque4 = gcnew String(miPokemon->getAtaque4());

	miGrapfic->DrawString(Ataque1, Fuente, Brushes::WhiteSmoke, Cordx + 5, Cordy + 5);
	miGrapfic->DrawString(Ataque2, Fuente, Brushes::WhiteSmoke, Cordx + 5, Cordy + 25);
	miGrapfic->DrawString(Ataque3, Fuente, Brushes::WhiteSmoke, Cordx + 5, Cordy + 45);
	miGrapfic->DrawString(Ataque4, Fuente, Brushes::WhiteSmoke, Cordx + 5, Cordy + 65);

}

