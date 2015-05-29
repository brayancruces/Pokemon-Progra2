#pragma once;
#include"Entrenador.h";

class Lider : public Entrenador
{
protected:
	char* Especialidad;
public:
	Lider(void);
	~Lider(void);
	char* getEspecialidad();
	void MostrarEnBatalla(Graphics^ Graphic);
	void MostrarMiniatura(Graphics^ Graphic);
};

Lider::Lider(void) : Entrenador()
{
	Especialidad = new char[20];
}
Lider::~Lider(void){}

void Lider::MostrarEnBatalla(Graphics^ Graphic){}
void Lider::MostrarMiniatura(Graphics^ Graphic){}

class PrimerLider : public Lider
{
protected:
	int IDLider;
public:
	PrimerLider(void);
	~PrimerLider(void);
};
PrimerLider::PrimerLider(void) : Lider()
{
	AnchoBatalla = 80;
	AltoBatalla = 80;
	IDLider = 1;
	EquipoPokemon->AgregarPokemon(new Bulbasaur());
	strcpy(Nombre, "Mandingo");
	strcpy(Especialidad, "Tierra");
	strcpy(DirImagenBatalla, "Resources\\img\\sprites\\pokemon\\battle\\rattata_front.png");
}
PrimerLider::~PrimerLider(void){}
