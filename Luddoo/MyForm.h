#include <cstdlib>
#include <ctime>
#include <msclr\marshal_cppstd.h>
using namespace msclr::interop;
#pragma once

namespace Luddoo {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	
	/*har aik color k 4 pieces hein.*/
	int Yellow[4];/*Yellow ka 'i'th piece is waqt block array me kon si jaga (index) per he?
				    yellow range is from block[47 to 45], and then finishing.*/
	int Red[4];/*block[8 to 6], and then finishing.*/
	int Green[4];/*block[34 to 32], and then finishing.*/
	int Blue[4];/*block[21 to 19], and then finishing.*/

	int currentMove;/*jo pice currently move krna chahta he, us piece ki info hogi, k wo piece kitna aage move kare ga (1/2/3/4/5/6 ?)*/
	char PlayerTurn;/*tells that abi kon se player ki turn he?*/

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();/*its own function.*/
			//
			//TODO: Add the constructor code here
			//
			for (int i = 0; i < 4; i++)
			{
				Yellow[i] = -1;/*shuru me sare pieces home me hi pare hun ge.*/
				Red[i] = -1;
				Green[i] = -1;
				Blue[i] = -1;
			}
			currentMove = 0;
			initializeButtonArray();
			setNextPlayerTurn();
			refreshBoard();
			disableAllPieces();
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
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:

private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Label^  label9;
private: System::Windows::Forms::Button^  U00;
private: System::Windows::Forms::Button^  U52;
private: System::Windows::Forms::Button^  U42;
private: System::Windows::Forms::Button^  U32;
private: System::Windows::Forms::Button^  U22;
private: System::Windows::Forms::Button^  U02;
private: System::Windows::Forms::Button^  U51;
private: System::Windows::Forms::Button^  U41;
private: System::Windows::Forms::Button^  U31;
private: System::Windows::Forms::Button^  U21;
private: System::Windows::Forms::Button^  U01;
private: System::Windows::Forms::Button^  L20;
private: System::Windows::Forms::Button^  L10;
private: System::Windows::Forms::Button^  L00;
private: System::Windows::Forms::Button^  U50;
private: System::Windows::Forms::Button^  U40;
private: System::Windows::Forms::Button^  U30;
private: System::Windows::Forms::Button^  U20;
private: System::Windows::Forms::Button^  U10;
private: System::Windows::Forms::Button^  L25;
private: System::Windows::Forms::Button^  L24;
private: System::Windows::Forms::Button^  L23;
private: System::Windows::Forms::Button^  L22;
private: System::Windows::Forms::Button^  L21;
private: System::Windows::Forms::Button^  L15;
private: System::Windows::Forms::Button^  L14;
private: System::Windows::Forms::Button^  L13;
private: System::Windows::Forms::Button^  L12;
private: System::Windows::Forms::Button^  L11;
private: System::Windows::Forms::Button^  L05;
private: System::Windows::Forms::Button^  L04;
private: System::Windows::Forms::Button^  L03;
private: System::Windows::Forms::Button^  L02;
private: System::Windows::Forms::Button^  L01;
private: System::Windows::Forms::Button^  U12;
private: System::Windows::Forms::Button^  U11;
private: System::Windows::Forms::Button^  D52;
private: System::Windows::Forms::Button^  D42;
private: System::Windows::Forms::Button^  D32;
private: System::Windows::Forms::Button^  D12;
private: System::Windows::Forms::Button^  D11;
private: System::Windows::Forms::Button^  D22;
private: System::Windows::Forms::Button^  D02;
private: System::Windows::Forms::Button^  D51;
private: System::Windows::Forms::Button^  D41;
private: System::Windows::Forms::Button^  D31;
private: System::Windows::Forms::Button^  D21;
private: System::Windows::Forms::Button^  D01;
private: System::Windows::Forms::Button^  D50;
private: System::Windows::Forms::Button^  D40;
private: System::Windows::Forms::Button^  D30;
private: System::Windows::Forms::Button^  D20;
private: System::Windows::Forms::Button^  D10;
private: System::Windows::Forms::Button^  D00;
private: System::Windows::Forms::Button^  R25;
private: System::Windows::Forms::Button^  R24;
private: System::Windows::Forms::Button^  R23;
private: System::Windows::Forms::Button^  R22;
private: System::Windows::Forms::Button^  R21;
private: System::Windows::Forms::Button^  R20;
private: System::Windows::Forms::Button^  R15;
private: System::Windows::Forms::Button^  R14;
private: System::Windows::Forms::Button^  R13;
private: System::Windows::Forms::Button^  R12;
private: System::Windows::Forms::Button^  R11;
private: System::Windows::Forms::Button^  R10;
private: System::Windows::Forms::Button^  R05;
private: System::Windows::Forms::Button^  R04;
private: System::Windows::Forms::Button^  R03;
private: System::Windows::Forms::Button^  R02;
private: System::Windows::Forms::Button^  R01;
private: System::Windows::Forms::Button^  R00;
private: System::Windows::Forms::Button^  destin;
private: System::Windows::Forms::Button^  R;
private: System::Windows::Forms::Button^  Y;
private: System::Windows::Forms::Button^  B;
private: System::Windows::Forms::Button^  G;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Y = (gcnew System::Windows::Forms::Button());
			this->G = (gcnew System::Windows::Forms::Button());
			this->B = (gcnew System::Windows::Forms::Button());
			this->R = (gcnew System::Windows::Forms::Button());
			this->destin = (gcnew System::Windows::Forms::Button());
			this->D52 = (gcnew System::Windows::Forms::Button());
			this->D42 = (gcnew System::Windows::Forms::Button());
			this->D32 = (gcnew System::Windows::Forms::Button());
			this->D12 = (gcnew System::Windows::Forms::Button());
			this->D11 = (gcnew System::Windows::Forms::Button());
			this->D22 = (gcnew System::Windows::Forms::Button());
			this->D02 = (gcnew System::Windows::Forms::Button());
			this->D51 = (gcnew System::Windows::Forms::Button());
			this->D41 = (gcnew System::Windows::Forms::Button());
			this->D31 = (gcnew System::Windows::Forms::Button());
			this->D21 = (gcnew System::Windows::Forms::Button());
			this->D01 = (gcnew System::Windows::Forms::Button());
			this->D50 = (gcnew System::Windows::Forms::Button());
			this->D40 = (gcnew System::Windows::Forms::Button());
			this->D30 = (gcnew System::Windows::Forms::Button());
			this->D20 = (gcnew System::Windows::Forms::Button());
			this->D10 = (gcnew System::Windows::Forms::Button());
			this->D00 = (gcnew System::Windows::Forms::Button());
			this->U52 = (gcnew System::Windows::Forms::Button());
			this->U42 = (gcnew System::Windows::Forms::Button());
			this->U32 = (gcnew System::Windows::Forms::Button());
			this->U12 = (gcnew System::Windows::Forms::Button());
			this->U11 = (gcnew System::Windows::Forms::Button());
			this->U22 = (gcnew System::Windows::Forms::Button());
			this->U02 = (gcnew System::Windows::Forms::Button());
			this->U51 = (gcnew System::Windows::Forms::Button());
			this->U41 = (gcnew System::Windows::Forms::Button());
			this->U31 = (gcnew System::Windows::Forms::Button());
			this->U21 = (gcnew System::Windows::Forms::Button());
			this->U01 = (gcnew System::Windows::Forms::Button());
			this->R25 = (gcnew System::Windows::Forms::Button());
			this->L25 = (gcnew System::Windows::Forms::Button());
			this->R24 = (gcnew System::Windows::Forms::Button());
			this->L24 = (gcnew System::Windows::Forms::Button());
			this->R23 = (gcnew System::Windows::Forms::Button());
			this->L23 = (gcnew System::Windows::Forms::Button());
			this->R22 = (gcnew System::Windows::Forms::Button());
			this->L22 = (gcnew System::Windows::Forms::Button());
			this->R21 = (gcnew System::Windows::Forms::Button());
			this->L21 = (gcnew System::Windows::Forms::Button());
			this->R20 = (gcnew System::Windows::Forms::Button());
			this->L20 = (gcnew System::Windows::Forms::Button());
			this->R15 = (gcnew System::Windows::Forms::Button());
			this->L15 = (gcnew System::Windows::Forms::Button());
			this->R14 = (gcnew System::Windows::Forms::Button());
			this->L14 = (gcnew System::Windows::Forms::Button());
			this->R13 = (gcnew System::Windows::Forms::Button());
			this->L13 = (gcnew System::Windows::Forms::Button());
			this->R12 = (gcnew System::Windows::Forms::Button());
			this->L12 = (gcnew System::Windows::Forms::Button());
			this->R11 = (gcnew System::Windows::Forms::Button());
			this->L11 = (gcnew System::Windows::Forms::Button());
			this->R10 = (gcnew System::Windows::Forms::Button());
			this->L10 = (gcnew System::Windows::Forms::Button());
			this->R05 = (gcnew System::Windows::Forms::Button());
			this->L05 = (gcnew System::Windows::Forms::Button());
			this->R04 = (gcnew System::Windows::Forms::Button());
			this->L04 = (gcnew System::Windows::Forms::Button());
			this->R03 = (gcnew System::Windows::Forms::Button());
			this->L03 = (gcnew System::Windows::Forms::Button());
			this->R02 = (gcnew System::Windows::Forms::Button());
			this->L02 = (gcnew System::Windows::Forms::Button());
			this->R01 = (gcnew System::Windows::Forms::Button());
			this->L01 = (gcnew System::Windows::Forms::Button());
			this->R00 = (gcnew System::Windows::Forms::Button());
			this->L00 = (gcnew System::Windows::Forms::Button());
			this->U50 = (gcnew System::Windows::Forms::Button());
			this->U40 = (gcnew System::Windows::Forms::Button());
			this->U30 = (gcnew System::Windows::Forms::Button());
			this->U20 = (gcnew System::Windows::Forms::Button());
			this->U10 = (gcnew System::Windows::Forms::Button());
			this->U00 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->Y);
			this->panel1->Controls->Add(this->G);
			this->panel1->Controls->Add(this->B);
			this->panel1->Controls->Add(this->R);
			this->panel1->Controls->Add(this->destin);
			this->panel1->Controls->Add(this->D52);
			this->panel1->Controls->Add(this->D42);
			this->panel1->Controls->Add(this->D32);
			this->panel1->Controls->Add(this->D12);
			this->panel1->Controls->Add(this->D11);
			this->panel1->Controls->Add(this->D22);
			this->panel1->Controls->Add(this->D02);
			this->panel1->Controls->Add(this->D51);
			this->panel1->Controls->Add(this->D41);
			this->panel1->Controls->Add(this->D31);
			this->panel1->Controls->Add(this->D21);
			this->panel1->Controls->Add(this->D01);
			this->panel1->Controls->Add(this->D50);
			this->panel1->Controls->Add(this->D40);
			this->panel1->Controls->Add(this->D30);
			this->panel1->Controls->Add(this->D20);
			this->panel1->Controls->Add(this->D10);
			this->panel1->Controls->Add(this->D00);
			this->panel1->Controls->Add(this->U52);
			this->panel1->Controls->Add(this->U42);
			this->panel1->Controls->Add(this->U32);
			this->panel1->Controls->Add(this->U12);
			this->panel1->Controls->Add(this->U11);
			this->panel1->Controls->Add(this->U22);
			this->panel1->Controls->Add(this->U02);
			this->panel1->Controls->Add(this->U51);
			this->panel1->Controls->Add(this->U41);
			this->panel1->Controls->Add(this->U31);
			this->panel1->Controls->Add(this->U21);
			this->panel1->Controls->Add(this->U01);
			this->panel1->Controls->Add(this->R25);
			this->panel1->Controls->Add(this->L25);
			this->panel1->Controls->Add(this->R24);
			this->panel1->Controls->Add(this->L24);
			this->panel1->Controls->Add(this->R23);
			this->panel1->Controls->Add(this->L23);
			this->panel1->Controls->Add(this->R22);
			this->panel1->Controls->Add(this->L22);
			this->panel1->Controls->Add(this->R21);
			this->panel1->Controls->Add(this->L21);
			this->panel1->Controls->Add(this->R20);
			this->panel1->Controls->Add(this->L20);
			this->panel1->Controls->Add(this->R15);
			this->panel1->Controls->Add(this->L15);
			this->panel1->Controls->Add(this->R14);
			this->panel1->Controls->Add(this->L14);
			this->panel1->Controls->Add(this->R13);
			this->panel1->Controls->Add(this->L13);
			this->panel1->Controls->Add(this->R12);
			this->panel1->Controls->Add(this->L12);
			this->panel1->Controls->Add(this->R11);
			this->panel1->Controls->Add(this->L11);
			this->panel1->Controls->Add(this->R10);
			this->panel1->Controls->Add(this->L10);
			this->panel1->Controls->Add(this->R05);
			this->panel1->Controls->Add(this->L05);
			this->panel1->Controls->Add(this->R04);
			this->panel1->Controls->Add(this->L04);
			this->panel1->Controls->Add(this->R03);
			this->panel1->Controls->Add(this->L03);
			this->panel1->Controls->Add(this->R02);
			this->panel1->Controls->Add(this->L02);
			this->panel1->Controls->Add(this->R01);
			this->panel1->Controls->Add(this->L01);
			this->panel1->Controls->Add(this->R00);
			this->panel1->Controls->Add(this->L00);
			this->panel1->Controls->Add(this->U50);
			this->panel1->Controls->Add(this->U40);
			this->panel1->Controls->Add(this->U30);
			this->panel1->Controls->Add(this->U20);
			this->panel1->Controls->Add(this->U10);
			this->panel1->Controls->Add(this->U00);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(554, 534);
			this->panel1->TabIndex = 0;
			// 
			// Y
			// 
			this->Y->BackColor = System::Drawing::Color::Gold;
			this->Y->Location = System::Drawing::Point(3, 3);
			this->Y->Name = L"Y";
			this->Y->Size = System::Drawing::Size(213, 207);
			this->Y->TabIndex = 24;
			this->Y->Text = L"Y";
			this->Y->UseVisualStyleBackColor = false;
			this->Y->Click += gcnew System::EventHandler(this, &MyForm::Y_Click);
			// 
			// G
			// 
			this->G->BackColor = System::Drawing::Color::LimeGreen;
			this->G->Location = System::Drawing::Point(4, 321);
			this->G->Name = L"G";
			this->G->Size = System::Drawing::Size(213, 207);
			this->G->TabIndex = 24;
			this->G->Text = L"G";
			this->G->UseVisualStyleBackColor = false;
			this->G->Click += gcnew System::EventHandler(this, &MyForm::G_Click);
			// 
			// B
			// 
			this->B->BackColor = System::Drawing::Color::DeepSkyBlue;
			this->B->Location = System::Drawing::Point(335, 321);
			this->B->Name = L"B";
			this->B->Size = System::Drawing::Size(213, 207);
			this->B->TabIndex = 24;
			this->B->Text = L"B";
			this->B->UseVisualStyleBackColor = false;
			this->B->Click += gcnew System::EventHandler(this, &MyForm::B_Click);
			// 
			// R
			// 
			this->R->BackColor = System::Drawing::Color::Red;
			this->R->Location = System::Drawing::Point(335, 3);
			this->R->Name = L"R";
			this->R->Size = System::Drawing::Size(213, 207);
			this->R->TabIndex = 24;
			this->R->Text = L"R";
			this->R->UseVisualStyleBackColor = false;
			this->R->Click += gcnew System::EventHandler(this, &MyForm::R_Click);
			// 
			// destin
			// 
			this->destin->Location = System::Drawing::Point(222, 214);
			this->destin->Name = L"destin";
			this->destin->Size = System::Drawing::Size(107, 104);
			this->destin->TabIndex = 23;
			this->destin->UseVisualStyleBackColor = true;
			// 
			// D52
			// 
			this->D52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D52->Location = System::Drawing::Point(295, 494);
			this->D52->Name = L"D52";
			this->D52->Size = System::Drawing::Size(38, 34);
			this->D52->TabIndex = 5;
			this->D52->Text = L"D52";
			this->D52->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D52->UseVisualStyleBackColor = true;
			this->D52->Click += gcnew System::EventHandler(this, &MyForm::D52_Click);
			// 
			// D42
			// 
			this->D42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D42->Location = System::Drawing::Point(295, 460);
			this->D42->Name = L"D42";
			this->D42->Size = System::Drawing::Size(38, 34);
			this->D42->TabIndex = 20;
			this->D42->Text = L"D42";
			this->D42->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D42->UseVisualStyleBackColor = true;
			this->D42->Click += gcnew System::EventHandler(this, &MyForm::D42_Click);
			// 
			// D32
			// 
			this->D32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D32->Location = System::Drawing::Point(295, 426);
			this->D32->Name = L"D32";
			this->D32->Size = System::Drawing::Size(38, 34);
			this->D32->TabIndex = 19;
			this->D32->Text = L"D32";
			this->D32->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D32->UseVisualStyleBackColor = true;
			this->D32->Click += gcnew System::EventHandler(this, &MyForm::D32_Click);
			// 
			// D12
			// 
			this->D12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D12->Location = System::Drawing::Point(295, 358);
			this->D12->Name = L"D12";
			this->D12->Size = System::Drawing::Size(38, 34);
			this->D12->TabIndex = 18;
			this->D12->Text = L"D12";
			this->D12->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D12->UseVisualStyleBackColor = true;
			this->D12->Click += gcnew System::EventHandler(this, &MyForm::D12_Click);
			// 
			// D11
			// 
			this->D11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D11->Location = System::Drawing::Point(257, 358);
			this->D11->Name = L"D11";
			this->D11->Size = System::Drawing::Size(38, 34);
			this->D11->TabIndex = 17;
			this->D11->Text = L"D11";
			this->D11->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D11->UseVisualStyleBackColor = true;
			this->D11->Click += gcnew System::EventHandler(this, &MyForm::D11_Click);
			// 
			// D22
			// 
			this->D22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D22->Location = System::Drawing::Point(295, 392);
			this->D22->Name = L"D22";
			this->D22->Size = System::Drawing::Size(38, 34);
			this->D22->TabIndex = 16;
			this->D22->Text = L"D22";
			this->D22->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D22->UseVisualStyleBackColor = true;
			this->D22->Click += gcnew System::EventHandler(this, &MyForm::D22_Click);
			// 
			// D02
			// 
			this->D02->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D02->Location = System::Drawing::Point(295, 324);
			this->D02->Name = L"D02";
			this->D02->Size = System::Drawing::Size(38, 34);
			this->D02->TabIndex = 15;
			this->D02->Text = L"D02";
			this->D02->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D02->UseVisualStyleBackColor = true;
			this->D02->Click += gcnew System::EventHandler(this, &MyForm::D02_Click);
			// 
			// D51
			// 
			this->D51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D51->Location = System::Drawing::Point(257, 494);
			this->D51->Name = L"D51";
			this->D51->Size = System::Drawing::Size(38, 34);
			this->D51->TabIndex = 14;
			this->D51->Text = L"D51";
			this->D51->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D51->UseVisualStyleBackColor = true;
			this->D51->Click += gcnew System::EventHandler(this, &MyForm::D51_Click);
			// 
			// D41
			// 
			this->D41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D41->Location = System::Drawing::Point(257, 460);
			this->D41->Name = L"D41";
			this->D41->Size = System::Drawing::Size(38, 34);
			this->D41->TabIndex = 13;
			this->D41->Text = L"D41";
			this->D41->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D41->UseVisualStyleBackColor = true;
			this->D41->Click += gcnew System::EventHandler(this, &MyForm::D41_Click);
			// 
			// D31
			// 
			this->D31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D31->Location = System::Drawing::Point(257, 426);
			this->D31->Name = L"D31";
			this->D31->Size = System::Drawing::Size(38, 34);
			this->D31->TabIndex = 12;
			this->D31->Text = L"D31";
			this->D31->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D31->UseVisualStyleBackColor = true;
			this->D31->Click += gcnew System::EventHandler(this, &MyForm::D31_Click);
			// 
			// D21
			// 
			this->D21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D21->Location = System::Drawing::Point(257, 392);
			this->D21->Name = L"D21";
			this->D21->Size = System::Drawing::Size(38, 34);
			this->D21->TabIndex = 11;
			this->D21->Text = L"D21";
			this->D21->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D21->UseVisualStyleBackColor = true;
			this->D21->Click += gcnew System::EventHandler(this, &MyForm::D21_Click);
			// 
			// D01
			// 
			this->D01->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D01->Location = System::Drawing::Point(257, 324);
			this->D01->Name = L"D01";
			this->D01->Size = System::Drawing::Size(38, 34);
			this->D01->TabIndex = 10;
			this->D01->Text = L"D01";
			this->D01->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D01->UseVisualStyleBackColor = true;
			this->D01->Click += gcnew System::EventHandler(this, &MyForm::D01_Click);
			// 
			// D50
			// 
			this->D50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D50->Location = System::Drawing::Point(219, 494);
			this->D50->Name = L"D50";
			this->D50->Size = System::Drawing::Size(38, 34);
			this->D50->TabIndex = 9;
			this->D50->Text = L"D50";
			this->D50->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D50->UseVisualStyleBackColor = true;
			this->D50->Click += gcnew System::EventHandler(this, &MyForm::D50_Click);
			// 
			// D40
			// 
			this->D40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D40->Location = System::Drawing::Point(219, 460);
			this->D40->Name = L"D40";
			this->D40->Size = System::Drawing::Size(38, 34);
			this->D40->TabIndex = 8;
			this->D40->Text = L"D40";
			this->D40->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D40->UseVisualStyleBackColor = true;
			this->D40->Click += gcnew System::EventHandler(this, &MyForm::D40_Click);
			// 
			// D30
			// 
			this->D30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D30->Location = System::Drawing::Point(219, 426);
			this->D30->Name = L"D30";
			this->D30->Size = System::Drawing::Size(38, 34);
			this->D30->TabIndex = 7;
			this->D30->Text = L"D30";
			this->D30->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D30->UseVisualStyleBackColor = true;
			this->D30->Click += gcnew System::EventHandler(this, &MyForm::D30_Click);
			// 
			// D20
			// 
			this->D20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D20->Location = System::Drawing::Point(219, 392);
			this->D20->Name = L"D20";
			this->D20->Size = System::Drawing::Size(38, 34);
			this->D20->TabIndex = 6;
			this->D20->Text = L"D20";
			this->D20->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D20->UseVisualStyleBackColor = true;
			this->D20->Click += gcnew System::EventHandler(this, &MyForm::D20_Click);
			// 
			// D10
			// 
			this->D10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D10->Location = System::Drawing::Point(219, 358);
			this->D10->Name = L"D10";
			this->D10->Size = System::Drawing::Size(38, 34);
			this->D10->TabIndex = 21;
			this->D10->Text = L"D10";
			this->D10->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D10->UseVisualStyleBackColor = true;
			this->D10->Click += gcnew System::EventHandler(this, &MyForm::D10_Click);
			// 
			// D00
			// 
			this->D00->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->D00->Location = System::Drawing::Point(219, 324);
			this->D00->Name = L"D00";
			this->D00->Size = System::Drawing::Size(38, 34);
			this->D00->TabIndex = 22;
			this->D00->Text = L"D00";
			this->D00->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->D00->UseVisualStyleBackColor = true;
			this->D00->Click += gcnew System::EventHandler(this, &MyForm::D00_Click);
			// 
			// U52
			// 
			this->U52->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U52->Location = System::Drawing::Point(295, 173);
			this->U52->Name = L"U52";
			this->U52->Size = System::Drawing::Size(38, 34);
			this->U52->TabIndex = 1;
			this->U52->Text = L"U52";
			this->U52->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U52->UseVisualStyleBackColor = true;
			this->U52->Click += gcnew System::EventHandler(this, &MyForm::U52_Click);
			// 
			// U42
			// 
			this->U42->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U42->Location = System::Drawing::Point(295, 139);
			this->U42->Name = L"U42";
			this->U42->Size = System::Drawing::Size(38, 34);
			this->U42->TabIndex = 1;
			this->U42->Text = L"U42";
			this->U42->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U42->UseVisualStyleBackColor = true;
			this->U42->Click += gcnew System::EventHandler(this, &MyForm::U42_Click);
			// 
			// U32
			// 
			this->U32->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U32->Location = System::Drawing::Point(295, 105);
			this->U32->Name = L"U32";
			this->U32->Size = System::Drawing::Size(38, 34);
			this->U32->TabIndex = 1;
			this->U32->Text = L"U32";
			this->U32->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U32->UseVisualStyleBackColor = true;
			this->U32->Click += gcnew System::EventHandler(this, &MyForm::U32_Click);
			// 
			// U12
			// 
			this->U12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U12->Location = System::Drawing::Point(295, 37);
			this->U12->Name = L"U12";
			this->U12->Size = System::Drawing::Size(38, 34);
			this->U12->TabIndex = 1;
			this->U12->Text = L"U12";
			this->U12->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U12->UseVisualStyleBackColor = true;
			this->U12->Click += gcnew System::EventHandler(this, &MyForm::U12_Click);
			// 
			// U11
			// 
			this->U11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U11->Location = System::Drawing::Point(257, 37);
			this->U11->Name = L"U11";
			this->U11->Size = System::Drawing::Size(38, 34);
			this->U11->TabIndex = 1;
			this->U11->Text = L"U11";
			this->U11->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U11->UseVisualStyleBackColor = true;
			this->U11->Click += gcnew System::EventHandler(this, &MyForm::U11_Click);
			// 
			// U22
			// 
			this->U22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U22->Location = System::Drawing::Point(295, 71);
			this->U22->Name = L"U22";
			this->U22->Size = System::Drawing::Size(38, 34);
			this->U22->TabIndex = 1;
			this->U22->Text = L"U22";
			this->U22->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U22->UseVisualStyleBackColor = true;
			this->U22->Click += gcnew System::EventHandler(this, &MyForm::U22_Click);
			// 
			// U02
			// 
			this->U02->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U02->Location = System::Drawing::Point(295, 3);
			this->U02->Name = L"U02";
			this->U02->Size = System::Drawing::Size(38, 34);
			this->U02->TabIndex = 1;
			this->U02->Text = L"U02";
			this->U02->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U02->UseVisualStyleBackColor = true;
			this->U02->Click += gcnew System::EventHandler(this, &MyForm::U02_Click);
			// 
			// U51
			// 
			this->U51->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U51->Location = System::Drawing::Point(257, 173);
			this->U51->Name = L"U51";
			this->U51->Size = System::Drawing::Size(38, 34);
			this->U51->TabIndex = 1;
			this->U51->Text = L"U51";
			this->U51->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U51->UseVisualStyleBackColor = true;
			this->U51->Click += gcnew System::EventHandler(this, &MyForm::U51_Click);
			// 
			// U41
			// 
			this->U41->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U41->Location = System::Drawing::Point(257, 139);
			this->U41->Name = L"U41";
			this->U41->Size = System::Drawing::Size(38, 34);
			this->U41->TabIndex = 1;
			this->U41->Text = L"U41";
			this->U41->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U41->UseVisualStyleBackColor = true;
			this->U41->Click += gcnew System::EventHandler(this, &MyForm::U41_Click);
			// 
			// U31
			// 
			this->U31->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U31->Location = System::Drawing::Point(257, 105);
			this->U31->Name = L"U31";
			this->U31->Size = System::Drawing::Size(38, 34);
			this->U31->TabIndex = 1;
			this->U31->Text = L"U31";
			this->U31->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U31->UseVisualStyleBackColor = true;
			this->U31->Click += gcnew System::EventHandler(this, &MyForm::U31_Click);
			// 
			// U21
			// 
			this->U21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U21->Location = System::Drawing::Point(257, 71);
			this->U21->Name = L"U21";
			this->U21->Size = System::Drawing::Size(38, 34);
			this->U21->TabIndex = 1;
			this->U21->Text = L"U21";
			this->U21->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U21->UseVisualStyleBackColor = true;
			this->U21->Click += gcnew System::EventHandler(this, &MyForm::U21_Click);
			// 
			// U01
			// 
			this->U01->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U01->Location = System::Drawing::Point(257, 3);
			this->U01->Name = L"U01";
			this->U01->Size = System::Drawing::Size(38, 34);
			this->U01->TabIndex = 1;
			this->U01->Text = L"U01";
			this->U01->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U01->UseVisualStyleBackColor = true;
			this->U01->Click += gcnew System::EventHandler(this, &MyForm::U01_Click);
			// 
			// R25
			// 
			this->R25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R25->Location = System::Drawing::Point(511, 284);
			this->R25->Name = L"R25";
			this->R25->Size = System::Drawing::Size(36, 34);
			this->R25->TabIndex = 1;
			this->R25->Text = L"R25";
			this->R25->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R25->UseVisualStyleBackColor = true;
			this->R25->Click += gcnew System::EventHandler(this, &MyForm::R25_Click);
			// 
			// L25
			// 
			this->L25->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L25->Location = System::Drawing::Point(180, 284);
			this->L25->Name = L"L25";
			this->L25->Size = System::Drawing::Size(36, 34);
			this->L25->TabIndex = 1;
			this->L25->Text = L"L25";
			this->L25->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L25->UseVisualStyleBackColor = true;
			this->L25->Click += gcnew System::EventHandler(this, &MyForm::L25_Click);
			// 
			// R24
			// 
			this->R24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R24->Location = System::Drawing::Point(475, 284);
			this->R24->Name = L"R24";
			this->R24->Size = System::Drawing::Size(36, 34);
			this->R24->TabIndex = 1;
			this->R24->Text = L"R24";
			this->R24->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R24->UseVisualStyleBackColor = true;
			this->R24->Click += gcnew System::EventHandler(this, &MyForm::R24_Click);
			// 
			// L24
			// 
			this->L24->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L24->Location = System::Drawing::Point(144, 284);
			this->L24->Name = L"L24";
			this->L24->Size = System::Drawing::Size(36, 34);
			this->L24->TabIndex = 1;
			this->L24->Text = L"L24";
			this->L24->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L24->UseVisualStyleBackColor = true;
			this->L24->Click += gcnew System::EventHandler(this, &MyForm::L24_Click);
			// 
			// R23
			// 
			this->R23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R23->Location = System::Drawing::Point(440, 284);
			this->R23->Name = L"R23";
			this->R23->Size = System::Drawing::Size(36, 34);
			this->R23->TabIndex = 1;
			this->R23->Text = L"R23";
			this->R23->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R23->UseVisualStyleBackColor = true;
			this->R23->Click += gcnew System::EventHandler(this, &MyForm::R23_Click);
			// 
			// L23
			// 
			this->L23->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L23->Location = System::Drawing::Point(109, 284);
			this->L23->Name = L"L23";
			this->L23->Size = System::Drawing::Size(36, 34);
			this->L23->TabIndex = 1;
			this->L23->Text = L"L23";
			this->L23->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L23->UseVisualStyleBackColor = true;
			this->L23->Click += gcnew System::EventHandler(this, &MyForm::L23_Click);
			// 
			// R22
			// 
			this->R22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R22->Location = System::Drawing::Point(405, 284);
			this->R22->Name = L"R22";
			this->R22->Size = System::Drawing::Size(36, 34);
			this->R22->TabIndex = 1;
			this->R22->Text = L"R22";
			this->R22->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R22->UseVisualStyleBackColor = true;
			this->R22->Click += gcnew System::EventHandler(this, &MyForm::R22_Click);
			// 
			// L22
			// 
			this->L22->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L22->Location = System::Drawing::Point(74, 284);
			this->L22->Name = L"L22";
			this->L22->Size = System::Drawing::Size(36, 34);
			this->L22->TabIndex = 1;
			this->L22->Text = L"L22";
			this->L22->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L22->UseVisualStyleBackColor = true;
			this->L22->Click += gcnew System::EventHandler(this, &MyForm::L22_Click);
			// 
			// R21
			// 
			this->R21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R21->Location = System::Drawing::Point(370, 284);
			this->R21->Name = L"R21";
			this->R21->Size = System::Drawing::Size(36, 34);
			this->R21->TabIndex = 1;
			this->R21->Text = L"R21";
			this->R21->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R21->UseVisualStyleBackColor = true;
			this->R21->Click += gcnew System::EventHandler(this, &MyForm::R21_Click);
			// 
			// L21
			// 
			this->L21->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L21->Location = System::Drawing::Point(39, 284);
			this->L21->Name = L"L21";
			this->L21->Size = System::Drawing::Size(36, 34);
			this->L21->TabIndex = 1;
			this->L21->Text = L"L21";
			this->L21->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L21->UseVisualStyleBackColor = true;
			this->L21->Click += gcnew System::EventHandler(this, &MyForm::L21_Click);
			// 
			// R20
			// 
			this->R20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R20->Location = System::Drawing::Point(335, 284);
			this->R20->Name = L"R20";
			this->R20->Size = System::Drawing::Size(36, 34);
			this->R20->TabIndex = 1;
			this->R20->Text = L"R20";
			this->R20->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R20->UseVisualStyleBackColor = true;
			this->R20->Click += gcnew System::EventHandler(this, &MyForm::R20_Click);
			// 
			// L20
			// 
			this->L20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L20->Location = System::Drawing::Point(4, 284);
			this->L20->Name = L"L20";
			this->L20->Size = System::Drawing::Size(36, 34);
			this->L20->TabIndex = 1;
			this->L20->Text = L"L20";
			this->L20->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L20->UseVisualStyleBackColor = true;
			this->L20->Click += gcnew System::EventHandler(this, &MyForm::L20_Click);
			// 
			// R15
			// 
			this->R15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R15->Location = System::Drawing::Point(511, 250);
			this->R15->Name = L"R15";
			this->R15->Size = System::Drawing::Size(36, 33);
			this->R15->TabIndex = 1;
			this->R15->Text = L"R15";
			this->R15->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R15->UseVisualStyleBackColor = true;
			this->R15->Click += gcnew System::EventHandler(this, &MyForm::R15_Click);
			// 
			// L15
			// 
			this->L15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L15->Location = System::Drawing::Point(180, 249);
			this->L15->Name = L"L15";
			this->L15->Size = System::Drawing::Size(36, 34);
			this->L15->TabIndex = 1;
			this->L15->Text = L"L15";
			this->L15->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L15->UseVisualStyleBackColor = true;
			this->L15->Click += gcnew System::EventHandler(this, &MyForm::L15_Click);
			// 
			// R14
			// 
			this->R14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R14->Location = System::Drawing::Point(475, 250);
			this->R14->Name = L"R14";
			this->R14->Size = System::Drawing::Size(36, 33);
			this->R14->TabIndex = 1;
			this->R14->Text = L"R14";
			this->R14->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R14->UseVisualStyleBackColor = true;
			this->R14->Click += gcnew System::EventHandler(this, &MyForm::R14_Click);
			// 
			// L14
			// 
			this->L14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L14->Location = System::Drawing::Point(144, 249);
			this->L14->Name = L"L14";
			this->L14->Size = System::Drawing::Size(36, 34);
			this->L14->TabIndex = 1;
			this->L14->Text = L"L14";
			this->L14->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L14->UseVisualStyleBackColor = true;
			this->L14->Click += gcnew System::EventHandler(this, &MyForm::L14_Click);
			// 
			// R13
			// 
			this->R13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R13->Location = System::Drawing::Point(440, 250);
			this->R13->Name = L"R13";
			this->R13->Size = System::Drawing::Size(36, 33);
			this->R13->TabIndex = 1;
			this->R13->Text = L"R13";
			this->R13->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R13->UseVisualStyleBackColor = true;
			this->R13->Click += gcnew System::EventHandler(this, &MyForm::R13_Click);
			// 
			// L13
			// 
			this->L13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L13->Location = System::Drawing::Point(109, 249);
			this->L13->Name = L"L13";
			this->L13->Size = System::Drawing::Size(36, 34);
			this->L13->TabIndex = 1;
			this->L13->Text = L"L13";
			this->L13->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L13->UseVisualStyleBackColor = true;
			this->L13->Click += gcnew System::EventHandler(this, &MyForm::L13_Click);
			// 
			// R12
			// 
			this->R12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R12->Location = System::Drawing::Point(405, 250);
			this->R12->Name = L"R12";
			this->R12->Size = System::Drawing::Size(36, 33);
			this->R12->TabIndex = 1;
			this->R12->Text = L"R12";
			this->R12->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R12->UseVisualStyleBackColor = true;
			this->R12->Click += gcnew System::EventHandler(this, &MyForm::R12_Click);
			// 
			// L12
			// 
			this->L12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L12->Location = System::Drawing::Point(74, 249);
			this->L12->Name = L"L12";
			this->L12->Size = System::Drawing::Size(36, 34);
			this->L12->TabIndex = 1;
			this->L12->Text = L"L12";
			this->L12->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L12->UseVisualStyleBackColor = true;
			this->L12->Click += gcnew System::EventHandler(this, &MyForm::L12_Click);
			// 
			// R11
			// 
			this->R11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R11->Location = System::Drawing::Point(370, 250);
			this->R11->Name = L"R11";
			this->R11->Size = System::Drawing::Size(36, 33);
			this->R11->TabIndex = 1;
			this->R11->Text = L"R11";
			this->R11->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R11->UseVisualStyleBackColor = true;
			this->R11->Click += gcnew System::EventHandler(this, &MyForm::R11_Click);
			// 
			// L11
			// 
			this->L11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L11->Location = System::Drawing::Point(39, 249);
			this->L11->Name = L"L11";
			this->L11->Size = System::Drawing::Size(36, 34);
			this->L11->TabIndex = 1;
			this->L11->Text = L"L11";
			this->L11->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L11->UseVisualStyleBackColor = true;
			this->L11->Click += gcnew System::EventHandler(this, &MyForm::L11_Click);
			// 
			// R10
			// 
			this->R10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R10->Location = System::Drawing::Point(335, 250);
			this->R10->Name = L"R10";
			this->R10->Size = System::Drawing::Size(36, 33);
			this->R10->TabIndex = 1;
			this->R10->Text = L"R10";
			this->R10->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R10->UseVisualStyleBackColor = true;
			this->R10->Click += gcnew System::EventHandler(this, &MyForm::R10_Click);
			// 
			// L10
			// 
			this->L10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L10->Location = System::Drawing::Point(4, 249);
			this->L10->Name = L"L10";
			this->L10->Size = System::Drawing::Size(36, 34);
			this->L10->TabIndex = 1;
			this->L10->Text = L"L10";
			this->L10->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L10->UseVisualStyleBackColor = true;
			this->L10->Click += gcnew System::EventHandler(this, &MyForm::L10_Click);
			// 
			// R05
			// 
			this->R05->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R05->Location = System::Drawing::Point(511, 214);
			this->R05->Name = L"R05";
			this->R05->Size = System::Drawing::Size(36, 34);
			this->R05->TabIndex = 1;
			this->R05->Text = L"R05";
			this->R05->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R05->UseVisualStyleBackColor = true;
			this->R05->Click += gcnew System::EventHandler(this, &MyForm::R05_Click);
			// 
			// L05
			// 
			this->L05->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L05->Location = System::Drawing::Point(180, 214);
			this->L05->Name = L"L05";
			this->L05->Size = System::Drawing::Size(36, 34);
			this->L05->TabIndex = 1;
			this->L05->Text = L"L05";
			this->L05->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L05->UseVisualStyleBackColor = true;
			this->L05->Click += gcnew System::EventHandler(this, &MyForm::L05_Click);
			// 
			// R04
			// 
			this->R04->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R04->Location = System::Drawing::Point(475, 214);
			this->R04->Name = L"R04";
			this->R04->Size = System::Drawing::Size(36, 34);
			this->R04->TabIndex = 1;
			this->R04->Text = L"R04";
			this->R04->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R04->UseVisualStyleBackColor = true;
			this->R04->Click += gcnew System::EventHandler(this, &MyForm::R04_Click);
			// 
			// L04
			// 
			this->L04->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L04->Location = System::Drawing::Point(144, 214);
			this->L04->Name = L"L04";
			this->L04->Size = System::Drawing::Size(36, 34);
			this->L04->TabIndex = 1;
			this->L04->Text = L"L04";
			this->L04->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L04->UseVisualStyleBackColor = true;
			this->L04->Click += gcnew System::EventHandler(this, &MyForm::L04_Click);
			// 
			// R03
			// 
			this->R03->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R03->Location = System::Drawing::Point(440, 214);
			this->R03->Name = L"R03";
			this->R03->Size = System::Drawing::Size(36, 34);
			this->R03->TabIndex = 1;
			this->R03->Text = L"R03";
			this->R03->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R03->UseVisualStyleBackColor = true;
			this->R03->Click += gcnew System::EventHandler(this, &MyForm::R03_Click);
			// 
			// L03
			// 
			this->L03->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L03->Location = System::Drawing::Point(109, 214);
			this->L03->Name = L"L03";
			this->L03->Size = System::Drawing::Size(36, 34);
			this->L03->TabIndex = 1;
			this->L03->Text = L"L03";
			this->L03->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L03->UseVisualStyleBackColor = true;
			this->L03->Click += gcnew System::EventHandler(this, &MyForm::L03_Click);
			// 
			// R02
			// 
			this->R02->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R02->Location = System::Drawing::Point(405, 214);
			this->R02->Name = L"R02";
			this->R02->Size = System::Drawing::Size(36, 34);
			this->R02->TabIndex = 1;
			this->R02->Text = L"R02";
			this->R02->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R02->UseVisualStyleBackColor = true;
			this->R02->Click += gcnew System::EventHandler(this, &MyForm::R02_Click);
			// 
			// L02
			// 
			this->L02->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L02->Location = System::Drawing::Point(74, 214);
			this->L02->Name = L"L02";
			this->L02->Size = System::Drawing::Size(36, 34);
			this->L02->TabIndex = 1;
			this->L02->Text = L"L02";
			this->L02->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L02->UseVisualStyleBackColor = true;
			this->L02->Click += gcnew System::EventHandler(this, &MyForm::L02_Click);
			// 
			// R01
			// 
			this->R01->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R01->Location = System::Drawing::Point(370, 214);
			this->R01->Name = L"R01";
			this->R01->Size = System::Drawing::Size(36, 34);
			this->R01->TabIndex = 1;
			this->R01->Text = L"R01";
			this->R01->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R01->UseVisualStyleBackColor = true;
			this->R01->Click += gcnew System::EventHandler(this, &MyForm::R01_Click);
			// 
			// L01
			// 
			this->L01->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L01->Location = System::Drawing::Point(39, 214);
			this->L01->Name = L"L01";
			this->L01->Size = System::Drawing::Size(36, 34);
			this->L01->TabIndex = 1;
			this->L01->Text = L"L01";
			this->L01->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L01->UseVisualStyleBackColor = true;
			this->L01->Click += gcnew System::EventHandler(this, &MyForm::L01_Click);
			// 
			// R00
			// 
			this->R00->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->R00->Location = System::Drawing::Point(335, 214);
			this->R00->Name = L"R00";
			this->R00->Size = System::Drawing::Size(36, 34);
			this->R00->TabIndex = 1;
			this->R00->Text = L"R00";
			this->R00->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->R00->UseVisualStyleBackColor = true;
			this->R00->Click += gcnew System::EventHandler(this, &MyForm::R00_Click);
			// 
			// L00
			// 
			this->L00->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->L00->Location = System::Drawing::Point(4, 214);
			this->L00->Name = L"L00";
			this->L00->Size = System::Drawing::Size(36, 34);
			this->L00->TabIndex = 1;
			this->L00->Text = L"L00";
			this->L00->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->L00->UseVisualStyleBackColor = true;
			this->L00->Click += gcnew System::EventHandler(this, &MyForm::L00_Click);
			// 
			// U50
			// 
			this->U50->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U50->Location = System::Drawing::Point(219, 173);
			this->U50->Name = L"U50";
			this->U50->Size = System::Drawing::Size(38, 34);
			this->U50->TabIndex = 1;
			this->U50->Text = L"U50";
			this->U50->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U50->UseVisualStyleBackColor = true;
			this->U50->Click += gcnew System::EventHandler(this, &MyForm::U50_Click);
			// 
			// U40
			// 
			this->U40->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U40->Location = System::Drawing::Point(219, 139);
			this->U40->Name = L"U40";
			this->U40->Size = System::Drawing::Size(38, 34);
			this->U40->TabIndex = 1;
			this->U40->Text = L"U40";
			this->U40->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U40->UseVisualStyleBackColor = true;
			this->U40->Click += gcnew System::EventHandler(this, &MyForm::U40_Click);
			// 
			// U30
			// 
			this->U30->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U30->Location = System::Drawing::Point(219, 105);
			this->U30->Name = L"U30";
			this->U30->Size = System::Drawing::Size(38, 34);
			this->U30->TabIndex = 1;
			this->U30->Text = L"U30";
			this->U30->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U30->UseVisualStyleBackColor = true;
			this->U30->Click += gcnew System::EventHandler(this, &MyForm::U30_Click);
			// 
			// U20
			// 
			this->U20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U20->Location = System::Drawing::Point(218, 71);
			this->U20->Name = L"U20";
			this->U20->Size = System::Drawing::Size(38, 34);
			this->U20->TabIndex = 1;
			this->U20->Text = L"U20";
			this->U20->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U20->UseVisualStyleBackColor = true;
			this->U20->Click += gcnew System::EventHandler(this, &MyForm::U20_Click);
			// 
			// U10
			// 
			this->U10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U10->Location = System::Drawing::Point(218, 37);
			this->U10->Name = L"U10";
			this->U10->Size = System::Drawing::Size(38, 34);
			this->U10->TabIndex = 1;
			this->U10->Text = L"U10";
			this->U10->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U10->UseVisualStyleBackColor = true;
			this->U10->Click += gcnew System::EventHandler(this, &MyForm::U10_Click);
			// 
			// U00
			// 
			this->U00->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 6.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->U00->Location = System::Drawing::Point(218, 3);
			this->U00->Name = L"U00";
			this->U00->Size = System::Drawing::Size(38, 34);
			this->U00->TabIndex = 1;
			this->U00->Text = L"U00";
			this->U00->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->U00->UseVisualStyleBackColor = true;
			this->U00->Click += gcnew System::EventHandler(this, &MyForm::U00_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(476, 540);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(63, 40);
			this->button1->TabIndex = 3;
			this->button1->Text = L"RollDice";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(327, 542);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(35, 13);
			this->label9->TabIndex = 5;
			this->label9->Text = L"label9";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(554, 590);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Ludo";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			 /*throughing dice, and then disable to through dice until the player make plays his piece.*/
			 srand(time(0));
			 currentMove = (rand() % 6 + 1);
			 
			 bool IsSomePieceWillMove = false;
			 if (label9->Text == "Yellow turn")
				 IsSomePieceWillMove = enablePlayerValidPieces(Yellow, Y);/*ham yellow valid pieces k buttons ko enable krne ja raha hein, taake yellow player us
																		    button per click kar k aage move kar jae.*/
			 else if (label9->Text == "Red turn")
				 IsSomePieceWillMove = enablePlayerValidPieces(Red, R);/*ham red valid pieces k buttons ko enable kar rahe hein.*/
			 else if (label9->Text == "Green turn")
				 IsSomePieceWillMove = enablePlayerValidPieces(Green, G);/*ham green valid pieces k buttons ko enable kar rahe hein.*/
			 else
				 IsSomePieceWillMove = enablePlayerValidPieces(Blue, B);/*ham blue valid pieces k buttons ko enable kar rahe hein.*/
			 
			 button1->Text = Convert::ToString(currentMove);
			 if (IsSomePieceWillMove == true)
				 button1->Enabled = false;
			 else
			 {
				 setNextPlayerTurn();
				 button1->Enabled = true;
			 }

}

private: System::Void Y_Click(System::Object^  sender, System::EventArgs^  e) {
			 for (int i = 0; i < 4; i++)
			 {
				 /*koi bi yellow goti agar nikalne wali he, tu usay nikaal dia jae.
				 home se nikal k medan-r-jang wali array (block) k 8th index me ye wala yellow piece aa jae ga.*/
				 if (Yellow[i] == -1)
				 {
					 Yellow[i] = 47;/*this is the stand of yellow where the yellow piece will started.*/
					 break;/*aik waqt me aik hi ywllow piece bahir nikle ga.*/
				 }
			 }
			 refreshBoard();
			 disableAllPieces();
			 setNextPlayerTurn();
			 button1->Enabled = true;
}
private: System::Void R_Click(System::Object^  sender, System::EventArgs^  e) {
			 for (int i = 0; i < 4; i++)
			 {
				 if (Red[i] == -1)
				 {
					 Red[i] = 8;
					 break;
				 }
			 }
			 refreshBoard();
			 disableAllPieces();
			 setNextPlayerTurn();
			 button1->Enabled = true;
}

private: System::Void G_Click(System::Object^  sender, System::EventArgs^  e) {
			 for (int i = 0; i < 4; i++)
			 {
				 if (Green[i] == -1)
				 {
					 Green[i] = 34;
					 break;
				 }
			 }
			 refreshBoard();
			 disableAllPieces();
			 setNextPlayerTurn();
			 button1->Enabled = true;
}
		 
private: System::Void B_Click(System::Object^  sender, System::EventArgs^  e) {
			 for (int i = 0; i < 4; i++)
			 {
				 if (Blue[i] == -1)
				 {
					 Blue[i] = 21;
					 break;
				 }
			 }
			 refreshBoard();
			 disableAllPieces();
			 setNextPlayerTurn();
			 button1->Enabled = true; 
}
		 
		 array<Button^>^ block = gcnew array<Button^>(72);/*total 52 (0-51) normal blocks hein jis per pieces sequence me
														  move karein ge, tu ham in blocks k ander buttons ka reference
														  bi usi sequence me rakhein ge, taake sare pieces bi isi hisab
														  se game me sequence me move karein.
														  aur 52-56 left wale finishing blocks hein.
														  aur 57-61 up wale finishing blocks hein.
														  aur 62-66 right wale finishing blocks hein.
														  aur 67-71 down wale finishing blocks hein.*/



		 void initializeButtonArray()
		 {
			 block[0] = U50;
			 block[1] = U40;
			 block[2] = U30;
			 block[3] = U20;
			 block[4] = U10;
			 block[5] = U00;
			 block[6] = U01;
			 block[7] = U02;
			 block[8] = U12;
			 block[9] = U22;
			 block[10] = U32;
			 block[11] = U42;
			 block[12] = U52;

			 block[13] = R00;
			 block[14] = R01;
			 block[15] = R02;
			 block[16] = R03;
			 block[17] = R04;
			 block[18] = R05;
			 block[19] = R15;
			 block[20] = R25;
			 block[21] = R24;
			 block[22] = R23;
			 block[23] = R22;
			 block[24] = R21;
			 block[25] = R20;

			 block[26] = D02;
			 block[27] = D12;
			 block[28] = D22;
			 block[29] = D32;
			 block[30] = D42;
			 block[31] = D52;
			 block[32] = D51;
			 block[33] = D50;
			 block[34] = D40;
			 block[35] = D30;
			 block[36] = D20;
			 block[37] = D10;
			 block[38] = D00;

			 block[39] = L25;
			 block[40] = L24;
			 block[41] = L23;
			 block[42] = L22;
			 block[43] = L21;
			 block[44] = L20;
			 block[45] = L10;
			 block[46] = L00;
			 block[47] = L01;
			 block[48] = L02;
			 block[49] = L03;
			 block[50] = L04;
			 block[51] = L05;

			 block[52] = L11;
			 block[53] = L12;
			 block[54] = L13;
			 block[55] = L14;
			 block[56] = L15;

			 block[57] = U11;
			 block[58] = U21;
			 block[59] = U31;
			 block[60] = U41;
			 block[61] = U51;

			 block[62] = R14;
			 block[63] = R13;
			 block[64] = R12;
			 block[65] = R11;
			 block[66] = R10;

			 block[67] = D41;
			 block[68] = D31;
			 block[69] = D21;
			 block[70] = D11;
			 block[71] = D01;

			 /*for (int i = 0; i < 72; i++)
			 block[i]->Text = Convert::ToString(i);*/
		 }

		 void setNextPlayerTurn()
		 {
			 if (label9->Text == "Yellow turn")
			 {
				 label9->Text = "Red turn";
				 label9->BackColor = Color::Red;
				 PlayerTurn = 'R';
			 }
			 else if (label9->Text == "Red turn")
			 {
				 label9->Text = "Green turn";
				 label9->BackColor = Color::LimeGreen;
				 PlayerTurn = 'G';
			 }
			 else if (label9->Text == "Green turn")
			 {
				 label9->Text = "Blue turn";
				 label9->BackColor = Color::DeepSkyBlue;
				 PlayerTurn = 'B';
			 }
			 else
			 {
				 label9->Text = "Yellow turn";
				 label9->BackColor = Color::Gold;
				 PlayerTurn = 'Y';
			 }
		 }

		 void disableAllPieces()
		 {
			 Y->Enabled = false;
			 R->Enabled = false;
			 G->Enabled = false;
			 B->Enabled = false;
			 destin->Enabled = false;
			 
			 for (int i = 0; i < 72; i++)
				 block[i]->Enabled = false;
		 }

		 bool enablePlayerValidPieces(int piece[4], Button^ PButton)
		 {
			 /*ham sirf wohi pieces enable karein ge, jo is player (1/2/3/4) k valid hun ge, taake
			 user un pieces per click kar k foran us piece ko aage 'currentMove' times move kar le ga.
			 jis bi piece ko move krwana he, us hisab se is function me parameters paas kiay jain ge.*/
			 disableAllPieces();
			 bool IsSomePieceWillMove = false;
			 for (int i = 0; i < 4; i++)
			 {
				 if (piece[i] == 72)
					 continue;/*ye piece finished ho gya he, tu is ko chor do.*/
				 if (piece[i] == -1)
				 {
					 if (currentMove == 6)/*ye player[i] abi ghar betha he, aur 6 aa gaya he, tu ab ye bahir nikal sakte he.*/
					 {
						 PButton->Enabled = true;
						 IsSomePieceWillMove = true;
					 }
					 else { /*ye piece ghar se bahir nai nikal sakta, so IsSomePieceWillMove remained false;*/ }
				 }
				 else /*player[i] ==(0 to 71)*/
				 {
					 block[piece[i]]->Enabled = true;/*ye wala piece[i] piece ab medan-e-jang me kahi na kahi move kar sakta he.*/
					 block[piece[i]]->BackColor = Color::LightPink;
					 IsSomePieceWillMove = true;
				 }
			 }
			 return IsSomePieceWillMove;
		 }

		 bool IsThisPosAStand(int Pos)
		 {
			 /*this function tells k kya ye Pos stand he, aur agar tu stand he, tu is position per koi bi
			 enemy ka piece bi nai mare ga, wrna ham enemy ka piece maar dein ge is function k jawab ki
			 base per.*/
			 if (Pos == 8 || Pos == 21 || Pos == 34 || Pos == 47)/*bahir wale stands*/
				 return true;
			 for (int i = 52; i <= 56; i++){/*yellow k finishing stands*/
				 if (Pos == i)
					 return true;
			 }
			 for (int i = 57; i <= 61; i++){/*red k finishing stands.*/
				 if (Pos == i)
					 return true;
			 }
			 for (int i = 62; i <= 66; i++){/*blue k finishing stands*/
				 if (Pos == i)
					 return true;
			 }
			 for (int i = 67; i <= 71; i++){/*green k finishing stands*/
				 if (Pos == i)
					 return true;
			 }
			 return false;
		 }

		 void killEnemyPieces(int Pos, char myPiece)
		 {
			 /*is 'Pos' ki jaga per agar ye mere piece 'myPiece' k elawa jitne bi koi aur piece (enemy) hun, tu
			 un enemies ko kill kar k un k apne apne gharo me pohncha do.*/
			 if (IsThisPosAStand(Pos) == true)
				 return;/*lekin agar 'Pos' aik stand ho, tu phir stand se koi bi enemy kill nai hogi, balke stand per wese hi pieces
						aik dosare k ooper place hote jain ge.*/
			 for (int i = 0; i < 4; i++)
			 {
				 if (myPiece == 'Y')/*agar me yellow hun, tu mere enemies red,green,blue hein.*/
				 {
					 /*agar mere enemies me se koi bi isi Pos per para hua ho, tu us ko kill kar dena he.*/
					 if (Red[i] == Pos)
					 {
						 /*agar mera koi red enemy isi jaga 'Pos' per he, tu us ko kill kar k us k ghar me move karwa do. */
						 Red[i] = -1;
					 }
					 if (Green[i] == Pos)
						 Green[i] = -1;
					 if (Blue[i] == Pos)
						 Blue[i] = -1;
				 }
				 else if (myPiece == 'R')/*agar me red hun, tu mere enemies yellow,green,blue hein.*/
				 {
					 if (Yellow[i] == Pos)
						 Yellow[i] = -1;
					 if (Green[i] == Pos)
						 Green[i] = -1;
					 if (Blue[i] == Pos)
						 Blue[i] = -1;
				 }
				 else if (myPiece == 'G')/*agar me green hun, tu mere enemies yellow,red,blue hein.*/
				 {
					 if (Yellow[i] == Pos)
						 Yellow[i] = -1;
					 if (Red[i] == Pos)
						 Red[i] = -1;
					 if (Blue[i] == Pos)
						 Blue[i] = -1;
				 }
				 else if (myPiece == 'B')/*agar me blue hun, tu mere enemies yellow,red,green hein.*/
				 {
					 if (Yellow[i] == Pos)
						 Yellow[i] = -1;
					 if (Red[i] == Pos)
						 Red[i] = -1;
					 if (Green[i] == Pos)
						 Green[i] = -1;
				 }
				 else {}
			 }

		 }

		 void updatePieceinArray(int sourcePos, char piece)
		 {
			 /*piece => Y/R/G/B wale piece ko move krna he.
			 aur piece ko is 'sourcePos' (0 - 71) wali jaga se block array me aage move krna he.*/
			 for (int i = 0; i < 4; i++)
			 {
				 if (piece == 'Y' && Yellow[i] == sourcePos)
				 {
					 /*moving yellow[i] piece from this Pos 'sourcePos' to forward in the block array.*/
					 if (Yellow[i] >= 52 && Yellow[i] <= 56)
					 {
						 /*it means that Yellow[i] is now finishing, and want to move forward.*/
						 Yellow[i] += currentMove;
						 if (Yellow[i] == 57)
						 {
							 /*it means that ye yellow[i] ab exactly finish ho gya he, tu usay finishing state per kar dein ge,
							 taake jab board refresh ho, tu yellow[i] destin me print ho.*/
							 Yellow[i] = 72;
							 break;/*ye yellow[i] destination per pohnch gya he, tu ab kuch nai krna.*/
						 }
						 else if (Yellow[i] > 57){
							 Yellow[i] -= currentMove;/*ham yellow[i] ko aage le kar gae, lekin wo apne finish se ziada bahir chala gya, tu us ko move hi
													  nai karein ge, yani k waha per hi piche le aain ge.*/
						 }
						 else /*yellow[i] <=56*/{
							 /*Yellow[i] abi bi finishing stands per hi he, lekin aage move kar gya he.*/
						 }
					 }
					 else if (Yellow[i] >= 47 && Yellow[i] <= 51)
					 {
						 /*this yellow[i] is in initial stage.*/
						 Yellow[i] += currentMove;
						 if (Yellow[i] >= 52)
						 {
							 /*initial stage se aage 0 position k aage safar kare ga.*/
							 Yellow[i] -= 52;/*ham ab block ki array me start me jain ge.*/
						 }
					 }
					 else if (Yellow[i] >= 39 && Yellow[i] <= 45)
					 {
						 /*ye yellow[i] finishing wali stage per aane wala he.*/
						 Yellow[i] += currentMove;
						 if (Yellow[i] > 45)
							 Yellow[i] += 6;/*move yellow[i] to finishing stand (52-56)*/
						 if (Yellow[i] == 57)
						 {
							 Yellow[i] = 72;
							 break;
						 }
					 }
					 else/*if yellow[i] ==(0 to 38)*/
					 {
						 /*yellow[i] normal path me safar kar raha he.*/
						 Yellow[i] += currentMove;
					 }
					 /*mera ab ye yellow[i] piece ab move kar gaya he new position per jo k yellow[i] k ander hi save he, tu ab
					 us new position per agar koi mere dushman ka koi piece para hua he, tu us ko kill kar dia jae.*/
					 killEnemyPieces(Yellow[i], 'Y');
					 break;/*aik waqt me aik hi ye 'piece' move kare ga isi liay break kia he, wrna is for loop me agli baar agar is
						   position per koi aur ye 'piece' para hota, tu wo bi aage move kar jata.*/
				 }
				 else if (piece == 'R' && Red[i] == sourcePos)
				 {
					 if (Red[i] >= 57 && Red[i] <= 61)
					 {
						 Red[i] += currentMove;
						 if (Red[i] == 62)
						 {
							 Red[i] = 72;
							 break;
						 }
						 else if (Red[i] > 62)
							 Red[i] -= currentMove;
						 else {}
					 }
					 else if (Red[i] >= 45 && Red[i] <= 51)
					 {
						 Red[i] += currentMove;
						 if (Red[i] >= 52)
							 Red[i] -= 52;/*ham ab block ki array me start me jain ge.*/
					 }
					 else if (Red[i] >= 0 && Red[i] <= 6)
					 {
						 /*ye red[i] finishing wali stage per aa rahe he.*/
						 Red[i] += currentMove;
						 if (Red[i] > 6)
							 Red[i] += 50;/*move Red[i] to finishing stand (57-61)*/
						 if (Red[i] == 62)
						 {
							 Red[i] = 72;
							 break;
						 }
					 }
					 else/*if Red[i] ==(8 to 44)*/
						 Red[i] += currentMove;/*normal flow of Red[i]*/
					 killEnemyPieces(Red[i], 'R');
					 break;
				 }
				 else if (piece == 'G' && Green[i] == sourcePos)
				 {
					 if (Green[i] >= 67 && Green[i] <= 71)
					 {
						 Green[i] += currentMove;
						 if (Green[i] == 72)
						 {
							 Green[i] = 72;/*green bi finish kae gya he.*/
							 break;
						 }
						 else if (Green[i] > 72)
							 Green[i] -= currentMove;
						 else {}
					 }
					 else if (Green[i] >= 45 && Green[i] <= 51)
					 {
						 Green[i] += currentMove;
						 if (Green[i] >= 52)
							 Green[i] -= 52;/*ham ab block ki array me start me jain ge.*/
					 }
					 else if (Green[i] >= 26 && Green[i] <= 32)
					 {
						 /*ye green[i] finishing wali stage per aa rahe he.*/
						 Green[i] += currentMove;
						 if (Green[i] > 32)
							 Green[i] += 34;/*move Green[i] to finishing stand (67-71)*/
						 if (Green[i] == 72)
						 {
							 Green[i] = 72;
							 break;
						 }
					 }
					 else/*if Green[i] ==(34 to 44, 0 to 25)*/
						 Green[i] += currentMove;/*normal flow of green[i]*/
					 killEnemyPieces(Green[i], 'G');
					 break;
				 }
				 else if (piece == 'B' && Blue[i] == sourcePos)
				 {
					 if (Blue[i] >= 62 && Blue[i] <= 66)
					 {
						 Blue[i] += currentMove;
						 if (Blue[i] == 67)
						 {
							 Blue[i] = 72;
							 break;
						 }
						 else if (Blue[i] > 67)
							 Blue[i] -= currentMove;
						 else {}
					 }
					 else if (Blue[i] >= 45 && Blue[i] <= 51)
					 {
						 Blue[i] += currentMove;
						 if (Blue[i] >= 52)
							 Blue[i] -= 52;/*ham ab block ki array me start me jain ge.*/
					 }
					 else if (Blue[i] >= 13 && Blue[i] <= 19)
					 {
						 /*ye blue[i] finishing wali stage per aa rahe he.*/
						 Blue[i] += currentMove;
						 if (Blue[i] > 19)
							 Blue[i] += 42;/*move blue[i] to finishing stand (62-66)*/
						 if (Blue[i] == 67)
						 {
							 Blue[i] = 72;
							 break;
						 }
					 }
					 else/*if blue[i] ==(21 to 44, 0 to 12)*/
						 Blue[i] += currentMove;/*normal flow of blue[i]*/
					 killEnemyPieces(Blue[i], 'B');
					 break;
				 }
				 else {}
			 }
		 }

		 void refreshBoard()
		 {
			 /*jo bi backend per changes hui hun gi, asal me yehi function us changes
			 ko board per refresh kare ga.
			 pehle board ko clear kia jae ga, yani k pehle board me se sare pieces ko
			 apni purani jaga se remove kia jae ga, aur phir dubara pieces ko un ki destin
			 place per rakha jae ga, yani k agar koi piece aik jaga se move ho k dosari jaga
			 aaya he, tu us purani jaga se us piece ko remove krna mushkil ho jae ga, k us
			 button k text me se sirf isi piece ko nikala jae, tu isi liay ham ye kaam krte
			 hein, k pichle sare board ko clear kar dein, aur phir jon jon si pieces ki new
			 jaga he, waha per aa kar pieces ko place kar dein.
			 so firstly clearing board.*/
			 {
				 /*jab clear hoga, tu home me se bi sab kuch clear ho jae ga.*/
				 Y->Text = "";
				 R->Text = "";
				 G->Text = "";
				 B->Text = "";
				 destin->Text = "";

				 for (int i = 0; i < 72; i++)
				 {
					 block[i]->Text = "";
					 block[i]->BackColor = Color::Transparent;
				 }

				 block[47]->BackColor = Color::Gold;
				 for (int i = 52; i <= 56; i++)
					 block[i]->BackColor = Color::Gold;

				 block[8]->BackColor = Color::Red;
				 for (int i = 57; i <= 61; i++)
					 block[i]->BackColor = Color::Red;

				 block[21]->BackColor = Color::DeepSkyBlue;
				 for (int i = 62; i <= 66; i++)
					 block[i]->BackColor = Color::DeepSkyBlue;

				 block[34]->BackColor = Color::LimeGreen;
				 for (int i = 67; i <= 71; i++)
					 block[i]->BackColor = Color::LimeGreen;
			 }

			 /*now placing all pieces on their new place. pieceName will be Y/ R/ G/ B*/
			 for (int i = 0; i < 4; i++)
			 {
				 if (Yellow[i] == -1)/*At home*/
				 {
					 /*Yellow[i] se ham ne yellow k 'i'th piece ki place get ki he, k wo kaha per
					 para hua he?*/
					 Y->Text += "Y";
				 }
				 else if (Yellow[i] == 72)
					 destin->Text += "Y";/*ye yellow[i] finish ho gya he.*/
				 else /*if (Yellow[i] >=0 && Yellow[i] < 72)*/
					 block[Yellow[i]]->Text += "Y";/*At somewhere in the blocks.*/

				 if (Red[i] == -1)
					 R->Text += "R";
				 else if (Red[i] == 72)
					 destin->Text += "R";
				 else
					 block[Red[i]]->Text += "R";

				 if (Green[i] == -1)
					 G->Text += "G";
				 else if (Green[i] == 72)
					 destin->Text += "G";
				 else
					 block[Green[i]]->Text += "G";

				 if (Blue[i] == -1)
					 B->Text += "B";
				 else if (Blue[i] == 72)
					 destin->Text += "B";
				 else
					 block[Blue[i]]->Text += "B";

			 }
		 }

		 void movePiece(int sourcePos)
		 {
			 /*this function moves the piece firstly in the backend array, and then refresh the board,
			   taake updated pieces board per bi update ho jain.*/
			 updatePieceinArray(sourcePos, PlayerTurn);/*ye function check kare ga, k current position (sourcePos)
													     per koi current playerTurn ka koi piece para hua he?
														 agar para he, tu us ko 'currentMove' times aage move karwa de.
														 aur baqi sare pieces waha hi pare rahein.
														 ye function asal me array me changes kare ga.*/

			 refreshBoard();
			 disableAllPieces();
			 setNextPlayerTurn();
			 button1->Enabled = true;
		 }

private: System::Void U50_Click(System::Object^  sender, System::EventArgs^  e) {
			 movePiece(0);/*jis player ki turn he, us player k piece ko is button wali position (block[0]) se us piece k diceNumber times aage 
									  move karwa lia jae.*/
}
private: System::Void U40_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(1); }
private: System::Void U30_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(2); }
private: System::Void U20_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(3); }
private: System::Void U10_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(4); }
private: System::Void U00_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(5); }
private: System::Void U01_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(6); }
private: System::Void U02_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(7); }
private: System::Void U12_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(8); }/*stand*/
private: System::Void U22_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(9); }
private: System::Void U32_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(10); }
private: System::Void U42_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(11); }
private: System::Void U52_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(12); }
private: System::Void R00_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(13); }
private: System::Void R01_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(14); }
private: System::Void R02_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(15); }
private: System::Void R03_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(16); }
private: System::Void R04_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(17); }
private: System::Void R05_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(18); }
private: System::Void R15_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(19); }
private: System::Void R25_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(20); }
private: System::Void R24_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(21); }/*stand*/
private: System::Void R23_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(22); }
private: System::Void R22_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(23); }
private: System::Void R21_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(24); }
private: System::Void R20_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(25); }
private: System::Void D02_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(26); }
private: System::Void D12_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(27); }
private: System::Void D22_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(28); }
private: System::Void D32_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(29); }
private: System::Void D42_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(30); }
private: System::Void D52_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(31); }
private: System::Void D51_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(32); }
private: System::Void D50_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(33); }
private: System::Void D40_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(34); }/*stand*/
private: System::Void D30_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(35); }
private: System::Void D20_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(36); }
private: System::Void D10_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(37); }
private: System::Void D00_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(38); }
private: System::Void L25_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(39); }
private: System::Void L24_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(40); }
private: System::Void L23_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(41); }
private: System::Void L22_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(42); }
private: System::Void L21_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(43); }
private: System::Void L20_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(44); }
private: System::Void L10_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(45); }
private: System::Void L00_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(46); }
private: System::Void L01_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(47); }/*stand*/
private: System::Void L02_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(48); }
private: System::Void L03_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(49); }
private: System::Void L04_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(50); }
private: System::Void L05_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(51); }

		 /*yellow k finishing stand wale buttons.*/
private: System::Void L11_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(52); }
private: System::Void L12_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(53); }
private: System::Void L13_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(54); }
private: System::Void L14_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(55); }
private: System::Void L15_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(56); }

		 /*red k finishing stand wale buttons.*/
private: System::Void U11_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(57); }
private: System::Void U21_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(58); }
private: System::Void U31_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(59); }
private: System::Void U41_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(60); }
private: System::Void U51_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(61); }

		 /*blue k finishing stand wale buttons.*/
private: System::Void R14_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(62); }
private: System::Void R13_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(63); }
private: System::Void R12_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(64); }
private: System::Void R11_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(65); }
private: System::Void R10_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(66); }

		 /*green k finishing stand wale buttons.*/
private: System::Void D41_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(67); }
private: System::Void D31_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(68); }
private: System::Void D21_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(69); }
private: System::Void D11_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(70); }
private: System::Void D01_Click(System::Object^  sender, System::EventArgs^  e) { movePiece(71); }

};
}
