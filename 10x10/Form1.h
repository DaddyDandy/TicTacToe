#include "BigGame.h"
#include "StdAfx.h"
#include <windows.h>
#pragma once


namespace BigXO
{
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	Game G;//создание объекта класса

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}	
	private: 
		array <Button^, 2>^ myField;//создание масива кнопок
		int line; 
		int row;


	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  gameToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  какИгратьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  рестартToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  выходToolStripMenuItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;			
			 System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
			 
			 void InitializeComponent(void)
			 {
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->gameToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->какИгратьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->рестартToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->menuStrip1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->gameToolStripMenuItem, 
					 this->рестартToolStripMenuItem, this->выходToolStripMenuItem});
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(525, 24);
				 this->menuStrip1->TabIndex = 0;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // gameToolStripMenuItem
				 // 
				 this->gameToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->какИгратьToolStripMenuItem});
				 this->gameToolStripMenuItem->Name = L"gameToolStripMenuItem";
				 this->gameToolStripMenuItem->Size = System::Drawing::Size(46, 20);
				 this->gameToolStripMenuItem->Text = L"Игра";
				 // 
				 // какИгратьToolStripMenuItem
				 // 
				 this->какИгратьToolStripMenuItem->Name = L"какИгратьToolStripMenuItem";
				 this->какИгратьToolStripMenuItem->Size = System::Drawing::Size(137, 22);
				 this->какИгратьToolStripMenuItem->Text = L"Как играть\?";
				 this->какИгратьToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::какИгратьToolStripMenuItem_Click);
				 // 
				 // рестартToolStripMenuItem
				 // 
				 this->рестартToolStripMenuItem->Name = L"рестартToolStripMenuItem";
				 this->рестартToolStripMenuItem->Size = System::Drawing::Size(61, 20);
				 this->рестартToolStripMenuItem->Text = L"Рестарт";
				 this->рестартToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::рестартToolStripMenuItem_Click);
				 // 
				 // выходToolStripMenuItem
				 // 
				 this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
				 this->выходToolStripMenuItem->Size = System::Drawing::Size(53, 20);
				 this->выходToolStripMenuItem->Text = L"Выход";
				 this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::выходToolStripMenuItem_Click);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(204)));
				 this->label1->Location = System::Drawing::Point(60, 580);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(406, 20);
				 this->label1->TabIndex = 1;
				 this->label1->Text = L"Если вам что-то не понятно, зайдите в меню игры :)";
				 this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(204)));
				 this->label2->Location = System::Drawing::Point(167, 24);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(150, 25);
				 this->label2->TabIndex = 2;
				 this->label2->Text = L"Сейчас ходит :";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
					 static_cast<System::Byte>(204)));
				 this->label3->ForeColor = System::Drawing::Color::Red;
				 this->label3->Location = System::Drawing::Point(323, 24);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(31, 25);
				 this->label3->TabIndex = 3;
				 this->label3->Text = L"ф";
				 this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
				 // 
				 // Form1
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->AutoSize = true;
				 this->ClientSize = System::Drawing::Size(525, 627);
				 this->ControlBox = false;
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->menuStrip1);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
				 this->MainMenuStrip = this->menuStrip1;
				 this->MaximumSize = System::Drawing::Size(545, 670);
				 this->MinimumSize = System::Drawing::Size(545, 670);
				 this->Name = L"Form1";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Tic-Tac-Toe";
				 this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion


	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
			 {

			 }
			 //Buttons' creation
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
				 myField = gcnew array<Button^, 2>(10, 10);
				 int x = 10, y = 70 , spaceForBut = 51, padding = 10;
				 for(int i = 0; i < 10; i++)
				 {
					 for(int j = 0; j < 10; j++)
					 {
						 this->myField[i,j] = (gcnew System::Windows::Forms::Button());
						 this->myField[i,j]->Size = Drawing::Size(50,50);
						 this->myField[i,j]->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204));
						 this->myField[i,j]->Text = "X";
						 this->myField[i,j]->Name = i.ToString()+j.ToString();
						 this->myField[i,j]->Location = System::Drawing::Point(x, y);
						 this->myField[i,j]->Click += gcnew System::EventHandler(this, &Form1::MyGame);
						 Controls->Add(myField[i,j]);
						 x += spaceForBut;
					 }
					 y += spaceForBut;
					 x = padding; 
				 }
				 clearButton();
			 }

			 //Game
	private: System::Void MyGame(System::Object^  sender, System::EventArgs^  e)
			 {
				 dynamic_cast<Button^>(sender);
				 int indexOfBotton = Convert::ToInt32( dynamic_cast<Button^>(sender)->Name);
				 line = indexOfBotton/10;
				 row = indexOfBotton%10;

				 if(G.getGameField(line,row) == 0)
				 {
					 G.Gaming(line,row);
					 if(G.getGameField(line, row) == 1)
					 {
						 myField[line,row]->Text = "X";
						 myField[line,row]->ForeColor = System::Drawing::Color::Red;
						 label3->Text = "O";
					 }
					 else if(G.getGameField(line , row) == 2)
					 {
						 myField[line,row]->Text = "O";
						 myField[line,row]->ForeColor = System::Drawing::Color::Blue;
						 label3->Text = "X";
					 }
					 switch(G.WhoWin())
					 {
						case 1: MessageBox::Show("X ПОБЕДИЛ !!!");clearButton();break;
						case 2: MessageBox::Show("O ПОБЕДИЛ !!!");clearButton();break;
						case 3: MessageBox::Show("НИЧЬЯ :)");clearButton();break;
					 }
				 }
			 }

			 //Field cleaning
			 void clearButton()
			 {
				 for(int i = 0; i < 10; ++i)
					 for( int j = 0; j < 10; ++j)
					 {
						 myField[i,j]->Text = " ";
					 }
					 label3->Text = "X";
					 G.ClearField();
			 }

	private: System::Void рестартToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 clearButton();
			 }
	private: System::Void выходToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
				 Form1::Close();
			 }
	private: System::Void какИгратьToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 MessageBox::Show("Игра - правила игры и описание кнопок \nРестарт - очистить поле игры \nВыход - покинуть игру\n====================================================\nИгра начинается сразу при запуске программы. Игру начинает Х(крестик). Игроки ходят по очереди, побеждает от, кто первым выстроит поледовательность из 5(своих) знаков по горизонтали/вертикали/диагонали.\nПриятной игры!");
			 }
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	};

}