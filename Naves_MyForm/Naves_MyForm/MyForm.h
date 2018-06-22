#pragma once
#include "Controlador_Juego.h"
namespace Naves_MyForm {

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
			juego = new Controlador_Juego();
			g = this->CreateGraphics();
			bc = BufferedGraphicsManager::Current;
			bg = bc->Allocate(g, this->ClientRectangle);
			fondo = gcnew Bitmap(gcnew String("Naves\\FondoGalaxia.png"));
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
			delete juego;
			delete g, bc, bg, fondo;
		}
	private: System::Windows::Forms::Timer^  timer1;
	protected:
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Controlador_Juego *juego;
		Graphics^ g;
		BufferedGraphicsContext^ bc;
		BufferedGraphics^ bg;
		Bitmap^ fondo;


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
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1370, 749);
			this->DoubleBuffered = true;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"MyForm";
			this->Text = L"StarCraft";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void MyForm_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		juego->GetHumano()->PosicionarNave(e->X, e->Y, e->Button);
		
	}
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		bg->Graphics->DrawImage(fondo, g->VisibleClipBounds);
		juego->TimerTick(bg->Graphics);
		bg->Render(g);
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		juego->Dibujar_Flota_Enemiga(g->VisibleClipBounds.X,g->VisibleClipBounds.Y,g->VisibleClipBounds.Width, g->VisibleClipBounds.Height);
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		
	}
	};
}
