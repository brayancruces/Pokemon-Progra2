#pragma once
#include"Entrenador.h";

class Marco : public Entrenador
{
protected:
	bool Medalla1;
	bool Medalla2;
	bool Medalla3;
	bool Medalla4;
	bool Medalla5;
	bool Medalla6;
public:
	 Marco(void);
	~Marco(void);
	bool getMedalla1();
	bool getMedalla2();
	bool getMedalla3();
	bool getMedalla4();
	bool getMedalla5();
	bool getMedalla6();
	void setMedalla1(bool Nuevo);
	void setMedalla2(bool Nuevo);
	void setMedalla3(bool Nuevo);
	void setMedalla4(bool Nuevo);
	void setMedalla5(bool Nuevo);
	void setMedalla6(bool Nuevo);
	void MostrarEnBatalla(Graphics^ Graphic);
	void MostrarMiniatura(Graphics^ Graphic);
};

Marco::Marco(void) : Entrenador()
{
	Medalla1 = false;
	Medalla2 = false;
	Medalla3 = false;
	Medalla4 = false;
	Medalla5 = false;
	Medalla6 = false;
	AnchoBatalla = 80;
	AltoBatalla = 80;
	AnchoMiniatura = 102;
	AltoMiniatura = 200;
	EquipoPokemon->AgregarPokemon(new Pikachu());
	strcpy(Nombre,"Cachimbo");
	strcpy(DirImagenBatalla, "Resources\\img\\sprites\\pokemon\\battle\\squirtle_back.png");
	strcpy(DirSpritesMiniatura, "Resources\\img\\sprites\\pokemon\\personaje\\marco.png");
}
Marco::~Marco(void){}

bool Marco::getMedalla1(){ return Medalla1; }
bool Marco::getMedalla2(){ return Medalla2; }
bool Marco::getMedalla3(){ return Medalla3; }
bool Marco::getMedalla4(){ return Medalla4; }
bool Marco::getMedalla5(){ return Medalla5; }
bool Marco::getMedalla6(){ return Medalla6; }
void Marco::setMedalla1(bool Nuevo){ Medalla1 = Nuevo; }
void Marco::setMedalla2(bool Nuevo){ Medalla2 = Nuevo; }
void Marco::setMedalla3(bool Nuevo){ Medalla3 = Nuevo; }
void Marco::setMedalla4(bool Nuevo){ Medalla4 = Nuevo; }
void Marco::setMedalla5(bool Nuevo){ Medalla5 = Nuevo; }
void Marco::setMedalla6(bool Nuevo){ Medalla6 = Nuevo; }

void Marco::MostrarEnBatalla(Graphics^ Graphic){}
void Marco::MostrarMiniatura(Graphics^ Graphic){}