#pragma once
#include "Batalla.h"
#include "Juego.h"
#include <time.h>


namespace Pokemon_game {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			PokemonUPC = new Juego();
			Nagayoshi = new PrimerLider();
			Yo = new Marco();
			miBatalla = new Batalla(Yo, Nagayoshi);
			miTiempo = time(NULL);
			miGraphic = this->CreateGraphics();
			EspacioParaBuffer = BufferedGraphicsManager::Current;
			miBuffer = EspacioParaBuffer->Allocate(miGraphic, this->ClientRectangle);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>

		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			delete PokemonUPC;
			delete miBatalla;
			delete miGraphic;
			delete EspacioParaBuffer;
			delete miBuffer;

		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Juego* PokemonUPC;
		Batalla* miBatalla;
		time_t miTiempo;
		Entrenador* Yo;
		Entrenador* Nagayoshi;
		Graphics^ miGraphic;
		BufferedGraphicsContext^ EspacioParaBuffer;
		BufferedGraphics^ miBuffer;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(600, 500);
			this->Name = L"MyForm";
			this->Text = L"Pokemon UPC";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
	
		time_t TiempoEnFuncion;
		TiempoEnFuncion = time(NULL);

		//if (Controlador->MenuDeInicio){}
		//else if (Controlador->Introduccion){}
		//else if(Controlador->SeleccionDePokemon){}
		
		if (PokemonUPC->getEscena() == 0){
			if (miBatalla->getContadorDeTurnos() == -1)
			{
				miBatalla->DibujarEscenario(miBuffer->Graphics);
				miBuffer->Render(miGraphic);
			}
			else if (miBatalla->getContadorDeTurnos() == 1 || miBatalla->getContadorDeTurnos() == 2)
			{
				miBatalla->ActualizarEscenario(miBuffer->Graphics);
				miBuffer->Render(miGraphic);
			}
			else if (miBatalla->getContadorDeTurnos() == 5)
				PokemonUPC->setEscena(1);

		}
		else if (PokemonUPC->getEscena() == 1)
			PokemonUPC->FinBatalla1(miGraphic,miBatalla);


	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		
			 if (e->KeyCode == Keys::A) miBatalla->BatallarConMi(miGraphic,"Primera");
		else if (e->KeyCode == Keys::S) miBatalla->BatallarConMi(miGraphic,"Segunda");
		else if (e->KeyCode == Keys::Z) miBatalla->BatallarConMi(miGraphic,"Tercera");
		else if (e->KeyCode == Keys::X) miBatalla->BatallarConMi(miGraphic,"Especial");

	}
	
};
}

