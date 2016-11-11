#pragma once
#include <list>
#include <fstream>
#include <vcclr.h>
#include <Windows.h>
//#define LOG
#ifdef LOG
std::ofstream log1(".\\log.txt");
#endif

namespace FXChords {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
			array<TextBox^> ^textBoxs;
			array<Label^> ^tercje;
			array<Label^> ^septymy;
			array<System::String ^, 2> ^dzwieki_skala;
			array<System::String ^> ^dzwieki2;
			array<System::String ^, 2> ^melodia;
			static const array<System::String ^> ^dzwieki = {"A","A#","B","C","C#","D","D#","E","F","F#","G","G#"}; 
			static const array<System::String ^> ^akordy = {"m7","maj7","7","mb57"};
			static int ilosc=1,x=65,y=27,txbi=1;

	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  tercje1;
	private: System::Windows::Forms::Label^  septymy1;
	private: System::Windows::Forms::Label^  melodia2;
	private: System::Windows::Forms::Label^  melodia1;
	private: System::Windows::Forms::Button^  guide_tones;
	private: System::Windows::Forms::Button^  reset;
	private: System::Windows::Forms::Label^  line2;
	private: System::Windows::Forms::Label^  line1;
	private: System::Windows::Forms::Button^  button1;



	private: System::Windows::Forms::Label^  label13;

			//zawijanie dzwiekow
			int element(int indx)
				 {
					 return indx%12;
				 }

			//obliczanie odleglosci 2 dzwiekow
			int odleglosc(System::String^ a, System::String^ b)
			{			
				int c,d,e;
				for (int i=0; i<12; i++)
				{
					if (a==Convert::ToString(dzwieki[i]))
					{
						c=i;
					}
					if (b==Convert::ToString(dzwieki[i]))
					{
						d=i;
					}
				}								

				e=abs(c-d);

				if (e>6) e=12-e;
				return e;
			}
			
			//rysowanie textboxow
			void textboxy()
			{						
						//dodawanie
						if (ilosc<this->ilosc_akordow->Value)
							{
								txbi++;
								x+=30;								
								textBoxs[txbi] = gcnew System::Windows::Forms::TextBox();  	
								textBoxs[txbi] ->Location = System::Drawing::Point(x,y);
								textBoxs[txbi] ->Size = System::Drawing::Size(25, 20);
								textBoxs[txbi] ->Name = "textBox" + Convert::ToString(txbi);	
								textBoxs[txbi] ->MaxLength = 2;
								textBoxs[txbi] ->CharacterCasing = CharacterCasing::Upper;
								textBoxs[txbi] ->TextAlign = HorizontalAlignment::Center;
								textBoxs[txbi] ->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
								this->tabPage2->Controls->Add(textBoxs[txbi]);						


								tercje[txbi] = gcnew System::Windows::Forms::Label();
								tercje[txbi]->Location = System::Drawing::Point(x+2,y+26);
								tercje[txbi]->Size = System::Drawing::Size(25, 16);
								tercje[txbi]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
								tercje[txbi]->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 9.75F,System::Drawing::FontStyle::Regular,System::Drawing::GraphicsUnit::Point, ((Byte) 0));
								tercje[txbi]->Name = "tercje" + Convert::ToString(txbi);		
								this->tabPage2->Controls->Add(tercje[txbi]);
								
								septymy[txbi] = gcnew System::Windows::Forms::Label();
								septymy[txbi]->Location = System::Drawing::Point(x+2,y+26+26);
								septymy[txbi]->Size = System::Drawing::Size(25, 16);
								septymy[txbi]->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
								septymy[txbi]->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 9.75F,System::Drawing::FontStyle::Regular,System::Drawing::GraphicsUnit::Point, ((Byte) 0));
								septymy[txbi]->Name = "septymy" + Convert::ToString(txbi);	
								this->tabPage2->Controls->Add(septymy[txbi]);
								
								ilosc++;
							}

						//usuwanie
						if (ilosc>this->ilosc_akordow->Value)
							{
								tabPage2->Controls->Remove(textBoxs[txbi]); 
								tabPage2->Controls->Remove(tercje[txbi]);
								tabPage2->Controls->Remove(septymy[txbi]);
								txbi--;
								x-=30;								
								ilosc--;
							}
			}

	
	public:
		Form1(void)
		{
			InitializeComponent();
			textBoxs = gcnew array<TextBox^>(51);
			tercje	= gcnew array<Label^>(51);
			septymy = gcnew array<Label^>(51);
			dzwieki_skala = gcnew array<System::String ^, 2>(4,7);
			dzwieki2 = gcnew array<System::String ^>(8);
			melodia = gcnew array<System::String ^, 2>(2,51);
			textBoxs[1] = this->textBox1;
			tercje[1] = this->tercje1;
			septymy[1] = this->septymy1;			
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
#ifdef LOG
			log1.close();
#endif
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  tonacja;
	private: System::Windows::Forms::TabControl^  tabControl1;

	private: 

	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::ComboBox^  skala;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::NumericUpDown^  ilosc_akordow;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;


	private: System::Windows::Forms::Label^  trojdzwiek1;
	private: System::Windows::Forms::Label^  trojdzwiek2;
	private: System::Windows::Forms::Label^  trojdzwiek3;
	private: System::Windows::Forms::Label^  trojdzwiek4;
	private: System::Windows::Forms::Label^  trojdzwiek5;
	private: System::Windows::Forms::Label^  trojdzwiek6;
	private: System::Windows::Forms::Label^  trojdzwiek7;
	private: System::Windows::Forms::Label^  czterodzwiek1;
	private: System::Windows::Forms::Label^  czterodzwiek2;
	private: System::Windows::Forms::Label^  czterodzwiek3;
	private: System::Windows::Forms::Label^  czterodzwiek4;
	private: System::Windows::Forms::Label^  czterodzwiek5;
	private: System::Windows::Forms::Label^  czterodzwiek6;
	private: System::Windows::Forms::Label^  czterodzwiek7;







	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;




	private: System::ComponentModel::IContainer^  components;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tonacja = (gcnew System::Windows::Forms::ComboBox());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->trojdzwiek1 = (gcnew System::Windows::Forms::Label());
			this->trojdzwiek2 = (gcnew System::Windows::Forms::Label());
			this->trojdzwiek3 = (gcnew System::Windows::Forms::Label());
			this->trojdzwiek4 = (gcnew System::Windows::Forms::Label());
			this->trojdzwiek5 = (gcnew System::Windows::Forms::Label());
			this->trojdzwiek6 = (gcnew System::Windows::Forms::Label());
			this->trojdzwiek7 = (gcnew System::Windows::Forms::Label());
			this->czterodzwiek1 = (gcnew System::Windows::Forms::Label());
			this->czterodzwiek2 = (gcnew System::Windows::Forms::Label());
			this->czterodzwiek3 = (gcnew System::Windows::Forms::Label());
			this->czterodzwiek4 = (gcnew System::Windows::Forms::Label());
			this->czterodzwiek5 = (gcnew System::Windows::Forms::Label());
			this->czterodzwiek6 = (gcnew System::Windows::Forms::Label());
			this->czterodzwiek7 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->line2 = (gcnew System::Windows::Forms::Label());
			this->line1 = (gcnew System::Windows::Forms::Label());
			this->reset = (gcnew System::Windows::Forms::Button());
			this->guide_tones = (gcnew System::Windows::Forms::Button());
			this->melodia2 = (gcnew System::Windows::Forms::Label());
			this->melodia1 = (gcnew System::Windows::Forms::Label());
			this->septymy1 = (gcnew System::Windows::Forms::Label());
			this->tercje1 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->ilosc_akordow = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->skala = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ilosc_akordow))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(13, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(38, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Key:";
			this->label1->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// tonacja
			// 
			this->tonacja->FormattingEnabled = true;
			this->tonacja->Items->AddRange(gcnew cli::array< System::Object^  >(12) {L"A", L"A#", L"B", L"C", L"C#", L"D", L"D#", L"E", 
				L"F", L"F#", L"G", L"G#"});
			this->tonacja->Location = System::Drawing::Point(57, 11);
			this->tonacja->MaxDropDownItems = 13;
			this->tonacja->Name = L"tonacja";
			this->tonacja->Size = System::Drawing::Size(38, 21);
			this->tonacja->Sorted = true;
			this->tonacja->TabIndex = 1;
			this->tonacja->Text = L"A";
			this->tonacja->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::tonacja_SelectedIndexChanged);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 38);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(746, 204);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label11);
			this->tabPage1->Controls->Add(this->label10);
			this->tabPage1->Controls->Add(this->tableLayoutPanel1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(738, 178);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Chords";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label11->Location = System::Drawing::Point(6, 121);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(61, 16);
			this->label11->TabIndex = 2;
			this->label11->Text = L"Chords:";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label10->Location = System::Drawing::Point(10, 67);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(57, 16);
			this->label10->TabIndex = 1;
			this->label10->Text = L"Triads:";
			this->label10->Click += gcnew System::EventHandler(this, &Form1::label10_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->tableLayoutPanel1->ColumnCount = 7;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				92)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				92)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				92)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				92)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				92)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				92)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute, 
				92)));
			this->tableLayoutPanel1->Controls->Add(this->label4, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->label5, 2, 0);
			this->tableLayoutPanel1->Controls->Add(this->label6, 3, 0);
			this->tableLayoutPanel1->Controls->Add(this->label7, 4, 0);
			this->tableLayoutPanel1->Controls->Add(this->label8, 5, 0);
			this->tableLayoutPanel1->Controls->Add(this->label9, 6, 0);
			this->tableLayoutPanel1->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->trojdzwiek1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->trojdzwiek2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->trojdzwiek3, 2, 1);
			this->tableLayoutPanel1->Controls->Add(this->trojdzwiek4, 3, 1);
			this->tableLayoutPanel1->Controls->Add(this->trojdzwiek5, 4, 1);
			this->tableLayoutPanel1->Controls->Add(this->trojdzwiek6, 5, 1);
			this->tableLayoutPanel1->Controls->Add(this->trojdzwiek7, 6, 1);
			this->tableLayoutPanel1->Controls->Add(this->czterodzwiek1, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->czterodzwiek2, 1, 2);
			this->tableLayoutPanel1->Controls->Add(this->czterodzwiek3, 2, 2);
			this->tableLayoutPanel1->Controls->Add(this->czterodzwiek4, 3, 2);
			this->tableLayoutPanel1->Controls->Add(this->czterodzwiek5, 4, 2);
			this->tableLayoutPanel1->Controls->Add(this->czterodzwiek6, 5, 2);
			this->tableLayoutPanel1->Controls->Add(this->czterodzwiek7, 6, 2);
			this->tableLayoutPanel1->GrowStyle = System::Windows::Forms::TableLayoutPanelGrowStyle::FixedSize;
			this->tableLayoutPanel1->Location = System::Drawing::Point(73, 21);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 3;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 20)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 40)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 40)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(644, 136);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::tableLayoutPanel1_Paint);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label4->Location = System::Drawing::Point(129, 4);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(21, 20);
			this->label4->TabIndex = 1;
			this->label4->Text = L"II";
			this->label4->Click += gcnew System::EventHandler(this, &Form1::label4_Click);
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label5->Location = System::Drawing::Point(219, 4);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(27, 20);
			this->label5->TabIndex = 2;
			this->label5->Text = L"III";
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label6->Location = System::Drawing::Point(312, 4);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(27, 20);
			this->label6->TabIndex = 3;
			this->label6->Text = L"IV";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label7->Location = System::Drawing::Point(408, 4);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(21, 20);
			this->label7->TabIndex = 4;
			this->label7->Text = L"V";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label8->Location = System::Drawing::Point(498, 4);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(27, 20);
			this->label8->TabIndex = 5;
			this->label8->Text = L"VI";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label9->Location = System::Drawing::Point(588, 4);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(33, 20);
			this->label9->TabIndex = 6;
			this->label9->Text = L"VII";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label3->Location = System::Drawing::Point(39, 4);
			this->label3->Name = L"label3";
			this->label3->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label3->Size = System::Drawing::Size(15, 20);
			this->label3->TabIndex = 0;
			this->label3->Text = L"I";
			this->label3->Click += gcnew System::EventHandler(this, &Form1::label3_Click);
			// 
			// trojdzwiek1
			// 
			this->trojdzwiek1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->trojdzwiek1->AutoSize = true;
			this->trojdzwiek1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->trojdzwiek1->Location = System::Drawing::Point(39, 46);
			this->trojdzwiek1->Name = L"trojdzwiek1";
			this->trojdzwiek1->Size = System::Drawing::Size(16, 16);
			this->trojdzwiek1->TabIndex = 9;
			this->trojdzwiek1->Text = L"a";
			this->trojdzwiek1->Click += gcnew System::EventHandler(this, &Form1::label12_Click);
			// 
			// trojdzwiek2
			// 
			this->trojdzwiek2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->trojdzwiek2->AutoSize = true;
			this->trojdzwiek2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->trojdzwiek2->Location = System::Drawing::Point(128, 46);
			this->trojdzwiek2->Name = L"trojdzwiek2";
			this->trojdzwiek2->Size = System::Drawing::Size(23, 16);
			this->trojdzwiek2->TabIndex = 10;
			this->trojdzwiek2->Text = L"b0";
			this->trojdzwiek2->Click += gcnew System::EventHandler(this, &Form1::trojdzwiek2_Click);
			// 
			// trojdzwiek3
			// 
			this->trojdzwiek3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->trojdzwiek3->AutoSize = true;
			this->trojdzwiek3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->trojdzwiek3->Location = System::Drawing::Point(224, 46);
			this->trojdzwiek3->Name = L"trojdzwiek3";
			this->trojdzwiek3->Size = System::Drawing::Size(17, 16);
			this->trojdzwiek3->TabIndex = 11;
			this->trojdzwiek3->Text = L"C";
			// 
			// trojdzwiek4
			// 
			this->trojdzwiek4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->trojdzwiek4->AutoSize = true;
			this->trojdzwiek4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->trojdzwiek4->Location = System::Drawing::Point(318, 46);
			this->trojdzwiek4->Name = L"trojdzwiek4";
			this->trojdzwiek4->Size = System::Drawing::Size(16, 16);
			this->trojdzwiek4->TabIndex = 12;
			this->trojdzwiek4->Text = L"d";
			// 
			// trojdzwiek5
			// 
			this->trojdzwiek5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->trojdzwiek5->AutoSize = true;
			this->trojdzwiek5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->trojdzwiek5->Location = System::Drawing::Point(404, 46);
			this->trojdzwiek5->Name = L"trojdzwiek5";
			this->trojdzwiek5->Size = System::Drawing::Size(29, 16);
			this->trojdzwiek5->TabIndex = 13;
			this->trojdzwiek5->Text = L"e/E";
			this->trojdzwiek5->Click += gcnew System::EventHandler(this, &Form1::trojdzwiek5_Click);
			// 
			// trojdzwiek6
			// 
			this->trojdzwiek6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->trojdzwiek6->AutoSize = true;
			this->trojdzwiek6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->trojdzwiek6->Location = System::Drawing::Point(504, 46);
			this->trojdzwiek6->Name = L"trojdzwiek6";
			this->trojdzwiek6->Size = System::Drawing::Size(16, 16);
			this->trojdzwiek6->TabIndex = 14;
			this->trojdzwiek6->Text = L"F";
			// 
			// trojdzwiek7
			// 
			this->trojdzwiek7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->trojdzwiek7->AutoSize = true;
			this->trojdzwiek7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->trojdzwiek7->Location = System::Drawing::Point(596, 46);
			this->trojdzwiek7->Name = L"trojdzwiek7";
			this->trojdzwiek7->Size = System::Drawing::Size(18, 16);
			this->trojdzwiek7->TabIndex = 15;
			this->trojdzwiek7->Text = L"G";
			// 
			// czterodzwiek1
			// 
			this->czterodzwiek1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->czterodzwiek1->AutoSize = true;
			this->czterodzwiek1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->czterodzwiek1->Location = System::Drawing::Point(29, 100);
			this->czterodzwiek1->Name = L"czterodzwiek1";
			this->czterodzwiek1->Size = System::Drawing::Size(35, 16);
			this->czterodzwiek1->TabIndex = 16;
			this->czterodzwiek1->Text = L"Am7";
			// 
			// czterodzwiek2
			// 
			this->czterodzwiek2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->czterodzwiek2->AutoSize = true;
			this->czterodzwiek2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->czterodzwiek2->Location = System::Drawing::Point(115, 100);
			this->czterodzwiek2->Name = L"czterodzwiek2";
			this->czterodzwiek2->Size = System::Drawing::Size(50, 16);
			this->czterodzwiek2->TabIndex = 17;
			this->czterodzwiek2->Text = L"Bmb57";
			// 
			// czterodzwiek3
			// 
			this->czterodzwiek3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->czterodzwiek3->AutoSize = true;
			this->czterodzwiek3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->czterodzwiek3->Location = System::Drawing::Point(210, 100);
			this->czterodzwiek3->Name = L"czterodzwiek3";
			this->czterodzwiek3->Size = System::Drawing::Size(46, 16);
			this->czterodzwiek3->TabIndex = 18;
			this->czterodzwiek3->Text = L"Cmaj7";
			// 
			// czterodzwiek4
			// 
			this->czterodzwiek4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->czterodzwiek4->AutoSize = true;
			this->czterodzwiek4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->czterodzwiek4->Location = System::Drawing::Point(308, 100);
			this->czterodzwiek4->Name = L"czterodzwiek4";
			this->czterodzwiek4->Size = System::Drawing::Size(36, 16);
			this->czterodzwiek4->TabIndex = 19;
			this->czterodzwiek4->Text = L"Dm7";
			// 
			// czterodzwiek5
			// 
			this->czterodzwiek5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->czterodzwiek5->AutoSize = true;
			this->czterodzwiek5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->czterodzwiek5->Location = System::Drawing::Point(391, 100);
			this->czterodzwiek5->Name = L"czterodzwiek5";
			this->czterodzwiek5->Size = System::Drawing::Size(55, 16);
			this->czterodzwiek5->TabIndex = 20;
			this->czterodzwiek5->Text = L"Em7/E7";
			// 
			// czterodzwiek6
			// 
			this->czterodzwiek6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->czterodzwiek6->AutoSize = true;
			this->czterodzwiek6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->czterodzwiek6->Location = System::Drawing::Point(489, 100);
			this->czterodzwiek6->Name = L"czterodzwiek6";
			this->czterodzwiek6->Size = System::Drawing::Size(45, 16);
			this->czterodzwiek6->TabIndex = 21;
			this->czterodzwiek6->Text = L"Fmaj7";
			// 
			// czterodzwiek7
			// 
			this->czterodzwiek7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->czterodzwiek7->AutoSize = true;
			this->czterodzwiek7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->czterodzwiek7->Location = System::Drawing::Point(592, 100);
			this->czterodzwiek7->Name = L"czterodzwiek7";
			this->czterodzwiek7->Size = System::Drawing::Size(25, 16);
			this->czterodzwiek7->TabIndex = 22;
			this->czterodzwiek7->Text = L"G7";
			// 
			// tabPage2
			// 
			this->tabPage2->AutoScroll = true;
			this->tabPage2->AutoScrollMargin = System::Drawing::Size(3, 0);
			this->tabPage2->Controls->Add(this->line2);
			this->tabPage2->Controls->Add(this->line1);
			this->tabPage2->Controls->Add(this->reset);
			this->tabPage2->Controls->Add(this->guide_tones);
			this->tabPage2->Controls->Add(this->melodia2);
			this->tabPage2->Controls->Add(this->melodia1);
			this->tabPage2->Controls->Add(this->septymy1);
			this->tabPage2->Controls->Add(this->tercje1);
			this->tabPage2->Controls->Add(this->label14);
			this->tabPage2->Controls->Add(this->label13);
			this->tabPage2->Controls->Add(this->label12);
			this->tabPage2->Controls->Add(this->textBox1);
			this->tabPage2->Controls->Add(this->ilosc_akordow);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(738, 178);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Guide Tones";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Click += gcnew System::EventHandler(this, &Form1::tabPage2_Click);
			// 
			// line2
			// 
			this->line2->AutoSize = true;
			this->line2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->line2->Location = System::Drawing::Point(0, 138);
			this->line2->Name = L"line2";
			this->line2->Size = System::Drawing::Size(63, 13);
			this->line2->TabIndex = 13;
			this->line2->Text = L"GT line 2:";
			// 
			// line1
			// 
			this->line1->AutoSize = true;
			this->line1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->line1->Location = System::Drawing::Point(0, 112);
			this->line1->Name = L"line1";
			this->line1->Size = System::Drawing::Size(63, 13);
			this->line1->TabIndex = 12;
			this->line1->Text = L"GT line 1:";
			// 
			// reset
			// 
			this->reset->Location = System::Drawing::Point(174, 3);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(75, 20);
			this->reset->TabIndex = 11;
			this->reset->TabStop = false;
			this->reset->Text = L"Reset";
			this->reset->UseVisualStyleBackColor = true;
			this->reset->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// guide_tones
			// 
			this->guide_tones->Location = System::Drawing::Point(255, 3);
			this->guide_tones->Name = L"guide_tones";
			this->guide_tones->Size = System::Drawing::Size(80, 20);
			this->guide_tones->TabIndex = 10;
			this->guide_tones->TabStop = false;
			this->guide_tones->Text = L"Guide Tones";
			this->guide_tones->UseVisualStyleBackColor = true;
			this->guide_tones->Visible = false;
			this->guide_tones->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// melodia2
			// 
			this->melodia2->AutoSize = true;
			this->melodia2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->melodia2->ForeColor = System::Drawing::Color::RoyalBlue;
			this->melodia2->Location = System::Drawing::Point(69, 136);
			this->melodia2->Name = L"melodia2";
			this->melodia2->Size = System::Drawing::Size(0, 16);
			this->melodia2->TabIndex = 9;
			this->melodia2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// melodia1
			// 
			this->melodia1->AutoSize = true;
			this->melodia1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->melodia1->ForeColor = System::Drawing::Color::Green;
			this->melodia1->Location = System::Drawing::Point(69, 110);
			this->melodia1->Name = L"melodia1";
			this->melodia1->Size = System::Drawing::Size(0, 16);
			this->melodia1->TabIndex = 8;
			this->melodia1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// septymy1
			// 
			this->septymy1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->septymy1->Location = System::Drawing::Point(65, 79);
			this->septymy1->Name = L"septymy1";
			this->septymy1->Size = System::Drawing::Size(25, 16);
			this->septymy1->TabIndex = 7;
			this->septymy1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tercje1
			// 
			this->tercje1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->tercje1->Location = System::Drawing::Point(65, 53);
			this->tercje1->Margin = System::Windows::Forms::Padding(3);
			this->tercje1->Name = L"tercje1";
			this->tercje1->Size = System::Drawing::Size(25, 16);
			this->tercje1->TabIndex = 6;
			this->tercje1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->tercje1->Click += gcnew System::EventHandler(this, &Form1::label15_Click);
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label14->Location = System::Drawing::Point(28, 79);
			this->label14->Margin = System::Windows::Forms::Padding(0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(28, 16);
			this->label14->TabIndex = 5;
			this->label14->Text = L"7th";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label13->Location = System::Drawing::Point(26, 53);
			this->label13->Margin = System::Windows::Forms::Padding(0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(30, 16);
			this->label13->TabIndex = 4;
			this->label13->Text = L"3rd";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label12->Location = System::Drawing::Point(6, 28);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(53, 16);
			this->label12->TabIndex = 3;
			this->label12->Text = L"Chord:";
			this->label12->Click += gcnew System::EventHandler(this, &Form1::label12_Click_1);
			// 
			// textBox1
			// 
			this->textBox1->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->textBox1->Location = System::Drawing::Point(65, 27);
			this->textBox1->MaxLength = 2;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(25, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// ilosc_akordow
			// 
			this->ilosc_akordow->Location = System::Drawing::Point(126, 3);
			this->ilosc_akordow->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) {50, 0, 0, 0});
			this->ilosc_akordow->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->ilosc_akordow->Name = L"ilosc_akordow";
			this->ilosc_akordow->Size = System::Drawing::Size(42, 20);
			this->ilosc_akordow->TabIndex = 1;
			this->ilosc_akordow->TabStop = false;
			this->ilosc_akordow->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->ilosc_akordow->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) {1, 0, 0, 0});
			this->ilosc_akordow->ValueChanged += gcnew System::EventHandler(this, &Form1::ilosc_akordow_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->label2->Location = System::Drawing::Point(3, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(117, 16);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Number of chords:";
			// 
			// skala
			// 
			this->skala->FormattingEnabled = true;
			this->skala->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"aeolian", L"locrian", L"ionian", L"dorian", L"phrygian", 
				L"lydian", L"miksolydian"});
			this->skala->Location = System::Drawing::Point(101, 11);
			this->skala->Name = L"skala";
			this->skala->Size = System::Drawing::Size(85, 21);
			this->skala->TabIndex = 3;
			this->skala->Tag = L"";
			this->skala->Text = L"aeolian";
			this->skala->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::tonacja_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->AutoSize = true;
			this->button1->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(238)));
			this->button1->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->Location = System::Drawing::Point(674, 11);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 23);
			this->button1->TabIndex = 14;
			this->button1->Text = L"by FX-Team";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(770, 254);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->skala);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->tonacja);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"FX Chords";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->ilosc_akordow))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
			 {
				 tonacja_SelectedIndexChanged(sender,e);				
			 }
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void tonacja_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				this->ilosc_akordow->Value = 1;
				textBoxs[1] -> Text = "";
				tercje[1] -> Text = "";
				septymy[1] -> Text = "";
				this->melodia1->Text = "";
				this->melodia2->Text = "";
				//this->line1->Text = "";
				//this->line2->Text = "";
				
				int centrum = this->tonacja->SelectedIndex;
				 
				if (this->skala->Text=="aeolian")
				{
					//dzwieki skali
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum))),0,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2))),0,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3))),0,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5))),0,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7))),0,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+8))),0,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10))),0,6);
				
					//typy akordow skali
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,0);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(3)),3,1);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,2);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,3);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,4);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,5);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,6);

					//trojdzwieki
					this->trojdzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+"m";
					this->trojdzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+"dim";
					this->trojdzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+"maj";
					this->trojdzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+"m";
					this->trojdzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+"m"+"/"+Convert::ToString(dzwieki_skala->GetValue(0,4));
					this->trojdzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+"maj";
					this->trojdzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+"maj";
					
					//czterodzwieki
					this->czterodzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+Convert::ToString(dzwieki_skala->GetValue(3,0));
					this->czterodzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+Convert::ToString(dzwieki_skala->GetValue(3,1));
					this->czterodzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+Convert::ToString(dzwieki_skala->GetValue(3,2));
					this->czterodzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+Convert::ToString(dzwieki_skala->GetValue(3,3));
					this->czterodzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+Convert::ToString(dzwieki_skala->GetValue(3,0))+"/"+dzwieki[element(centrum+7)]+Convert::ToString(dzwieki_skala->GetValue(3,4));
					this->czterodzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+Convert::ToString(dzwieki_skala->GetValue(3,5));
					this->czterodzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+Convert::ToString(dzwieki_skala->GetValue(3,6));										

					//tercje
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3))),1,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2+3))),1,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3+4))),1,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+3))),1,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+4))),1,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+8+4))),1,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10+4))),1,6);
					
					//septymy
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10))),2,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2+10))),2,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3+11))),2,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+10))),2,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+10))),2,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+8+11))),2,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10+10))),2,6);					
				}

				if (this->skala->Text=="locrian")
				{
					//dzwieki skali
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum))),0,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+1))),0,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3))),0,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5))),0,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+6))),0,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+8))),0,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10))),0,6);

					//typy akordow skali
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(3)),3,0);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,1);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,2);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,3);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,4);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,5);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,6);

					//trojdzwieki
					this->trojdzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+"dim";
					this->trojdzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+"maj";
					this->trojdzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+"m";
					this->trojdzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+"m";
					this->trojdzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+"maj"+"/"+dzwieki[element(centrum+7)]+"maj";
					this->trojdzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+"maj";
					this->trojdzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+"m";

					//czterodzwieki
					this->czterodzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+dzwieki_skala->GetValue(3,0);
					this->czterodzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+dzwieki_skala->GetValue(3,1);
					this->czterodzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+dzwieki_skala->GetValue(3,2);
					this->czterodzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+dzwieki_skala->GetValue(3,3);
					this->czterodzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+dzwieki_skala->GetValue(3,1)+"/"+dzwieki[element(centrum+7)]+dzwieki_skala->GetValue(3,4);
					this->czterodzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+dzwieki_skala->GetValue(3,5);
					this->czterodzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+dzwieki_skala->GetValue(3,6);
					
					//tercje
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3))),1,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+1+4))),1,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3+3))),1,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+3))),1,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+6+4))),1,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+8+4))),1,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10+3))),1,6);
					
					//septymy
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10))),2,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+1+11))),2,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3+10))),2,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+10))),2,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+6+10))),2,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+8+10))),2,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10+10))),2,6);
				}	

				if (this->skala->Text=="ionian")
				{
					//dzwieki skali
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum))),0,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2))),0,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4))),0,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5))),0,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7))),0,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9))),0,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+11))),0,6);

					//typy akordow skali
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,0);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,1);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,2);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,3);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,4);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,5);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(3)),3,6);

					//trojdzwieki
					int centrum = this->tonacja->SelectedIndex;
					this->trojdzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+"maj";
					this->trojdzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+"m";
					this->trojdzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+"m";
					this->trojdzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+"maj";
					this->trojdzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+"maj";
					this->trojdzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+"m";
					this->trojdzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+"dim";

					//czterodzwieki
					this->czterodzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+dzwieki_skala->GetValue(3,0);
					this->czterodzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+dzwieki_skala->GetValue(3,1);
					this->czterodzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+dzwieki_skala->GetValue(3,2);
					this->czterodzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+dzwieki_skala->GetValue(3,3);
					this->czterodzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+dzwieki_skala->GetValue(3,4);
					this->czterodzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+dzwieki_skala->GetValue(3,5);
					this->czterodzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+dzwieki_skala->GetValue(3,6);					

					//tercje
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4))),1,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2+3))),1,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4+3))),1,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+4))),1,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+4))),1,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9+3))),1,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+11+3))),1,6);
					
					//septymy
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+11))),2,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2+10))),2,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4+10))),2,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+11))),2,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+10))),2,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9+10))),2,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+11+10))),2,6);					
				}

				if (this->skala->Text=="dorian")
				{
					//dzwieki skali
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum))),0,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2))),0,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3))),0,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5))),0,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7))),0,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9))),0,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10))),0,6);

					//typy akordow skali
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,0);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,1);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,2);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,3);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,4);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(3)),3,5);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,6);

					//trojdzwieki
					this->trojdzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+"m";
					this->trojdzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+"m";
					this->trojdzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+"maj";
					this->trojdzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+"maj";
					this->trojdzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+"m"+"/"+Convert::ToString(dzwieki_skala->GetValue(0,4))+"maj";
					this->trojdzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+"dim";
					this->trojdzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+"maj";
					
					//czterodzwieki
					this->czterodzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+dzwieki_skala->GetValue(3,0);
					this->czterodzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+dzwieki_skala->GetValue(3,1);
					this->czterodzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+dzwieki_skala->GetValue(3,2);
					this->czterodzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+dzwieki_skala->GetValue(3,3);
					this->czterodzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+dzwieki_skala->GetValue(3,0)+"/"+Convert::ToString(dzwieki_skala->GetValue(0,4))+dzwieki_skala->GetValue(3,4);
					this->czterodzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+dzwieki_skala->GetValue(3,5);
					this->czterodzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+dzwieki_skala->GetValue(3,6);					

					//tercje
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3))),1,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2+3))),1,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3+4))),1,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+4))),1,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+4))),1,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9+3))),1,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10+4))),1,6);
					
					//septymy
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10))),2,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2+10))),2,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3+11))),2,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+10))),2,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+10))),2,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9+10))),2,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10+11))),2,6);
				}

				if (this->skala->Text=="phrygian")
				{
					//dzwieki skali
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum))),0,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+1))),0,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3))),0,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5))),0,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7))),0,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+8))),0,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10))),0,6);

					//typy akordow skali
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,0);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,1);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,2);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,3);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,4);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,5);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,6);

					//trojdzwieki
					this->trojdzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+"m";
					this->trojdzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+"maj";
					this->trojdzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+"maj";
					this->trojdzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+"m";
					this->trojdzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+"dim/"+Convert::ToString(dzwieki_skala->GetValue(0,4))+"maj";
					this->trojdzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+"maj";
					this->trojdzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+"m";
					
					//czterodzwieki
					this->czterodzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+dzwieki_skala->GetValue(3,0);
					this->czterodzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+dzwieki_skala->GetValue(3,1);
					this->czterodzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+dzwieki_skala->GetValue(3,2);
					this->czterodzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+dzwieki_skala->GetValue(3,3);
					this->czterodzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+akordy[3]+"/"+Convert::ToString(dzwieki_skala->GetValue(0,4))+dzwieki_skala->GetValue(3,4);
					this->czterodzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+dzwieki_skala->GetValue(3,5);
					this->czterodzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+dzwieki_skala->GetValue(3,6);					

					//tercje
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3))),1,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+1+4))),1,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3+4))),1,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+3))),1,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+4))),1,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+8+4))),1,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10+3))),1,6);
					
					//septymy
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10))),2,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+1+11))),2,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+3+10))),2,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+10))),2,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+10))),2,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+8+11))),2,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10+10))),2,6);
				}

				if (this->skala->Text=="lydian")
				{					
					//dzwieki skali
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum))),0,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2))),0,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4))),0,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+6))),0,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7))),0,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9))),0,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+11))),0,6);

					//typy akordow skali
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,0);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,1);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,2);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(3)),3,3);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,4);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,5);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,6);
					
					//trojdzwieki
					this->trojdzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+"maj";
					this->trojdzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+"maj";
					this->trojdzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+"m";
					this->trojdzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+"dim";
					this->trojdzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+"maj";
					this->trojdzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+"m";
					this->trojdzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+"m";

					//czterodzwieki
					this->czterodzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+dzwieki_skala->GetValue(3,0);
					this->czterodzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+dzwieki_skala->GetValue(3,1);
					this->czterodzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+dzwieki_skala->GetValue(3,2);
					this->czterodzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+dzwieki_skala->GetValue(3,3);
					this->czterodzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+dzwieki_skala->GetValue(3,0)+"/"+Convert::ToString(dzwieki_skala->GetValue(0,4))+dzwieki_skala->GetValue(3,4);
					this->czterodzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+dzwieki_skala->GetValue(3,5);
					this->czterodzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+dzwieki_skala->GetValue(3,6);

					//tercje
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4))),1,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2+4))),1,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4+3))),1,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+6+3))),1,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+4))),1,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9+3))),1,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+11+3))),1,6);
					
					//septymy
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+11))),2,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2+10))),2,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4+10))),2,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+6+10))),2,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+10))),2,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9+10))),2,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+11+10))),2,6);
				}

				if (this->skala->Text=="miksolydian")
				{
					//dzwieki skali
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum))),0,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2))),0,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4))),0,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5))),0,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7))),0,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9))),0,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10))),0,6);

					//typy akordow skali
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,0);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,1);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(3)),3,2);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,3);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(2)),3,4);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(0)),3,5);
					dzwieki_skala->SetValue(Convert::ToString(akordy->GetValue(1)),3,6);
					
					//trojdzwieki
					this->trojdzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+"maj";
					this->trojdzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+"m";
					this->trojdzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+"dim";
					this->trojdzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+"maj";
					this->trojdzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+"m"+"/"+Convert::ToString(dzwieki_skala->GetValue(0,4))+"maj";
					this->trojdzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+"m";
					this->trojdzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+"maj";
					
					//czterodzwieki
					this->czterodzwiek1->Text = Convert::ToString(dzwieki_skala->GetValue(0,0))+dzwieki_skala->GetValue(3,0);
					this->czterodzwiek2->Text = Convert::ToString(dzwieki_skala->GetValue(0,1))+dzwieki_skala->GetValue(3,1);
					this->czterodzwiek3->Text = Convert::ToString(dzwieki_skala->GetValue(0,2))+dzwieki_skala->GetValue(3,2);
					this->czterodzwiek4->Text = Convert::ToString(dzwieki_skala->GetValue(0,3))+dzwieki_skala->GetValue(3,3);
					this->czterodzwiek5->Text = Convert::ToString(dzwieki_skala->GetValue(0,4))+dzwieki_skala->GetValue(3,1)+"/"+Convert::ToString(dzwieki_skala->GetValue(0,4))+dzwieki_skala->GetValue(3,4);
					this->czterodzwiek6->Text = Convert::ToString(dzwieki_skala->GetValue(0,5))+dzwieki_skala->GetValue(3,5);
					this->czterodzwiek7->Text = Convert::ToString(dzwieki_skala->GetValue(0,6))+dzwieki_skala->GetValue(3,6);							

					//tercje
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4))),1,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2+3))),1,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4+3))),1,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+4))),1,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+4))),1,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9+3))),1,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10+4))),1,6);
					
					//septymy
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10))),2,0);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+2+10))),2,1);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+4+10))),2,2);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+5+11))),2,3);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+7+10))),2,4);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+9+10))),2,5);
					dzwieki_skala->SetValue(Convert::ToString(dzwieki->GetValue(element(centrum+10+11))),2,6);
				}	
				
}
private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 }

private: System::Void bindingSource1_CurrentChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
		 private: System::Void label12_Click(System::Object^  sender, System::EventArgs^  e) {}
private: System::Void statusStrip1_ItemClicked(System::Object^  sender, System::Windows::Forms::ToolStripItemClickedEventArgs^  e) {
		 }
private: System::Void tonacja2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label4_Click(System::Object^  sender, System::EventArgs^  e) {
		 }					
				 
				  

private: System::Void trojdzwiek5_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void bindingSource1_CurrentChanged_1(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	 button1_Click(sender,e);	
	for (int ii=0; ii<(int)ilosc_akordow->Value; ii++)
	{
		//Tercje i septymy
		if (textBoxs[ii+1]->Text->ToUpper() == Convert::ToString(dzwieki_skala->GetValue(0,0)))
		{			
			tercje[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(1,0));	
			septymy[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(2,0));	
			button1_Click(sender,e);
		}

		else if (textBoxs[ii+1]->Text->ToUpper() == Convert::ToString(dzwieki_skala->GetValue(0,1)))
		{			
			tercje[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(1,1));	
			septymy[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(2,1));	
			button1_Click(sender,e);
		}

		else if (textBoxs[ii+1]->Text->ToUpper() == Convert::ToString(dzwieki_skala->GetValue(0,2)))
		{			
			tercje[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(1,2));	
			septymy[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(2,2));
			button1_Click(sender,e);
		}

		else if (textBoxs[ii+1]->Text->ToUpper() == Convert::ToString(dzwieki_skala->GetValue(0,3)))
		{			
			tercje[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(1,3));	
			septymy[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(2,3));
			button1_Click(sender,e);
		}

		else if (textBoxs[ii+1]->Text->ToUpper() == Convert::ToString(dzwieki_skala->GetValue(0,4)))
		{			
			tercje[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(1,4));
			septymy[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(2,4));
			button1_Click(sender,e);
		}

		else if (textBoxs[ii+1]->Text->ToUpper() == Convert::ToString(dzwieki_skala->GetValue(0,5)))
		{			
			tercje[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(1,5));
			septymy[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(2,5));	
			button1_Click(sender,e);
		}
		else if (textBoxs[ii+1]->Text->ToUpper() == Convert::ToString(dzwieki_skala->GetValue(0,6)))
		{			
			tercje[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(1,6));
			septymy[ii+1]->Text = Convert::ToString(dzwieki_skala->GetValue(2,6));	
			button1_Click(sender,e);
		}
		else 
			{				
				tercje[ii+1]->Text = "";
				septymy[ii+1]->Text = "";
				button1_Click(sender,e);
		}			
	}


}
private: System::Void ilosc_akordow_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			/////////////////
			///TEXTBOX'y
			 int il;
			 if ((int)ilosc_akordow->Value>ilosc)
				 il = (int)ilosc_akordow->Value-ilosc;

			  if ((int)ilosc_akordow->Value<ilosc)
				 il = (int)ilosc_akordow->Value+ilosc;

			for (int i=1;i<=il;i++) textboxy();
		 }
private: System::Void trojdzwiek2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label10_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label12_Click_1(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label15_Click(System::Object^  sender, System::EventArgs^  e) {
			
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
			int i=1;
			this->melodia1->Text = "";
			this->melodia2->Text = "";
			/*if (Convert::ToString(textBoxs[1]->Text)!="")
				{
					this->line1->Text = "GT line 1:";
					this->line2->Text = "GT line 2:";
				}*/
			this->tercje1->ForeColor = System::Drawing::Color::Green;
			this->septymy1->ForeColor = System::Drawing::Color::RoyalBlue;
			//pierwsze dzwieki guide tones
			melodia->SetValue(Convert::ToString(tercje[1]->Text),0,1);
			this->melodia1->Text = Convert::ToString(tercje[1]->Text) + " ";
			melodia->SetValue(Convert::ToString(septymy[1]->Text),1,1);
			this->melodia2->Text = Convert::ToString(septymy[1]->Text) + " ";

			if ((int)ilosc_akordow->Value>=2)
				{	
					for (i;i<(int)ilosc_akordow->Value;i++)
						{					
							if (Convert::ToString(textBoxs[i+1]->Text)!="")
								{							
									///algorytm wyznaczania najkrotszej sciezki	
									if (Convert::ToString(melodia->GetValue(0,i)) == Convert::ToString(tercje[i+1]->Text))
										{
											melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),0,i+1);
											melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),1,i+1);
											this->tercje[i+1]->ForeColor = System::Drawing::Color::Green;
											this->septymy[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
										}
									else if (Convert::ToString(melodia->GetValue(0,i)) == Convert::ToString(septymy[i+1]->Text))
										{
											melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),0,i+1);
											melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),1,i+1);
											this->septymy[i+1]->ForeColor = System::Drawing::Color::Green;
											this->tercje[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
										}
									else if (Convert::ToString(melodia->GetValue(1,i)) == Convert::ToString(tercje[i+1]->Text))
										{
											melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),1,i+1);
											melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),0,i+1);
											this->septymy[i+1]->ForeColor = System::Drawing::Color::Green;
											this->tercje[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
										}

									else if (Convert::ToString(melodia->GetValue(1,i)) == Convert::ToString(septymy[i+1]->Text))
										{
											melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),1,i+1);
											melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),0,i+1);
											this->tercje[i+1]->ForeColor = System::Drawing::Color::Green;
											this->septymy[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
										}

									else if (odleglosc(Convert::ToString(melodia->GetValue(0,i)),Convert::ToString(tercje[i+1]->Text)) == odleglosc(Convert::ToString(melodia->GetValue(0,i)),Convert::ToString(septymy[i+1]->Text)))
										{
											if (odleglosc(Convert::ToString(melodia->GetValue(1,i)), Convert::ToString(tercje[i+1]->Text)) > odleglosc(Convert::ToString(melodia->GetValue(1,i)), Convert::ToString(septymy[i+1]->Text)))
												{
													melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),0,i+1);
													melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),1,i+1);
													this->tercje[i+1]->ForeColor = System::Drawing::Color::Green;
													this->septymy[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
												}
											else
												{
													melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),1,i+1);
													melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),0,i+1);
													this->septymy[i+1]->ForeColor = System::Drawing::Color::Green;
													this->tercje[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
												}
										}

									else if (odleglosc(Convert::ToString(melodia->GetValue(1,i)),Convert::ToString(tercje[i+1]->Text)) == odleglosc(Convert::ToString(melodia->GetValue(1,i)),Convert::ToString(septymy[i+1]->Text)))
										{
											if (odleglosc(Convert::ToString(melodia->GetValue(0,i)), Convert::ToString(tercje[i+1]->Text)) > odleglosc(Convert::ToString(melodia->GetValue(0,i)), Convert::ToString(septymy[i+1]->Text)))
												{
													melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),1,i+1);
													melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),0,i+1);
													this->septymy[i+1]->ForeColor = System::Drawing::Color::Green;
													this->tercje[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
												}
											else
												{
													melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),0,i+1);
													melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),1,i+1);
													this->tercje[i+1]->ForeColor = System::Drawing::Color::Green;
													this->septymy[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
												}
										}

									else if (odleglosc(Convert::ToString(melodia->GetValue(0,i)),Convert::ToString(tercje[i+1]->Text)) < odleglosc(Convert::ToString(melodia->GetValue(0,i)),Convert::ToString(septymy[i+1]->Text)))
										{						
											melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),0,i+1);
											melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),1,i+1);
											this->tercje[i+1]->ForeColor = System::Drawing::Color::Green;
											this->septymy[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
										}
									else if (odleglosc(Convert::ToString(melodia->GetValue(1,i)), Convert::ToString(tercje[i+1]->Text)) < odleglosc(Convert::ToString(melodia->GetValue(1,i)), Convert::ToString(septymy[i+1]->Text)))
										{
											melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),1,i+1);
											melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),0,i+1);
											this->septymy[i+1]->ForeColor = System::Drawing::Color::Green;
											this->tercje[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
										}

									else if (odleglosc(Convert::ToString(melodia->GetValue(0,i)),Convert::ToString(tercje[i+1]->Text)) > odleglosc(Convert::ToString(melodia->GetValue(0,i)),Convert::ToString(septymy[i+1]->Text)))
										{						
											melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),1,i+1);
											melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),0,i+1);
											this->septymy[i+1]->ForeColor = System::Drawing::Color::Green;
											this->tercje[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
										}
									else if (odleglosc(Convert::ToString(melodia->GetValue(1,i)), Convert::ToString(tercje[i+1]->Text)) > odleglosc(Convert::ToString(melodia->GetValue(1,i)), Convert::ToString(septymy[i+1]->Text)))
										{
											melodia-> SetValue(Convert::ToString(tercje[i+1]->Text),0,i+1);
											melodia-> SetValue(Convert::ToString(septymy[i+1]->Text),1,i+1);
											this->tercje[i+1]->ForeColor = System::Drawing::Color::Green;
											this->septymy[i+1]->ForeColor = System::Drawing::Color::RoyalBlue;
										}

									this->melodia1->Text = this->melodia1-> Text + Convert::ToString(melodia->GetValue(0,i+1)) + " ";
									this->melodia2->Text = this->melodia2-> Text + Convert::ToString(melodia->GetValue(1,i+1)) + " ";
								}
						}
				}
}
private: System::Void tabPage2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 this->ilosc_akordow->Value = 1;
				textBoxs[1] -> Text = "";
				tercje[1] -> Text = "";
				septymy[1] -> Text = "";
				this->melodia1->Text = "";
				this->melodia2->Text = "";
				//this->line1->Text = "";
				//this->line2->Text = "";
				this->tercje1->ForeColor = System::Drawing::Color::Black;
				this->septymy1->ForeColor = System::Drawing::Color::Black;
		 }
private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) {			
			 MessageBox::Show("FX Chords v1.0 by FX-Team:\n• Michuu^^\n• FX\n www.fx-team.fulara.com", "Info",
                     MessageBoxButtons::OK, MessageBoxIcon::Information);
		 }
};
}

