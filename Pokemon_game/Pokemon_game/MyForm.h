#pragma once
#include "Batalla.h"

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
			miBatalla = new Batalla();
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
			delete miBatalla;
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Batalla* miBatalla;


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
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {


		System::Drawing::Graphics^ miGraphic = this->CreateGraphics();
		System::Drawing::BufferedGraphicsContext^ miBufferBase = BufferedGraphicsManager::Current;
		System::Drawing::BufferedGraphics^ miBuffer = miBufferBase->Allocate(miGraphic, this->ClientRectangle);

		miBatalla->Dibujar(miBuffer->Graphics);

		miBuffer->Render(miGraphic);
		delete miBuffer;
		delete miBufferBase;
		delete miGraphic;

	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

		if (e->KeyCode == Keys::A) miBatalla->BatallarConMi("Primera");
		if (e->KeyCode == Keys::S) miBatalla->BatallarConMi("Segunda");
		if (e->KeyCode == Keys::Z) miBatalla->BatallarConMi("Tercera");
		if (e->KeyCode == Keys::X) miBatalla->BatallarConMi("Ultimate");

	}
	};
}

