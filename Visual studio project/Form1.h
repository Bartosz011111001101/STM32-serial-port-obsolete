#pragma once
#include <msclr/marshal_cppstd.h>

namespace CppCLRWinFormsProject {




	

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
	private: System::Windows::Forms::Button^ Send_data;

		  
	private: System::Windows::Forms::TextBox^ textBox1;


	private: System::ComponentModel::IContainer^ components;

	protected:

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
			this->Send_data = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// Send_data
			// 
			this->Send_data->Location = System::Drawing::Point(66, 12);
			this->Send_data->Name = L"Send_data";
			this->Send_data->Size = System::Drawing::Size(133, 57);
			this->Send_data->TabIndex = 0;
			this->Send_data->Text = L"Send Data";
			this->Send_data->UseVisualStyleBackColor = true;
			this->Send_data->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 75);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(223, 284);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(255, 376);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->Send_data);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		//System::String^ managedString = "Hello";
		System::String^ managedString = textBox1->Text;
		// Uzupe³nianie stringa do 10 znaków
		while (managedString->Length < 10)
		{
			managedString += " "; // Dodajemy pusty znak na koniec wiadomoœci
		}

		// Konwersja zarz¹dzanego stringa na string niezarz¹dzany
		std::string unmanagedString = msclr::interop::marshal_as<std::string>(managedString);

		// Konwersja stringa na tablicê znaków (char*)
		const char* charArray = unmanagedString.c_str();

		// Ustawienie tekstu w textBox1
		textBox1->Text = managedString;

		// Zak³adam, ¿e Serial to instancja klasy obs³uguj¹cej port szeregowy
		bool is_sent = Serial.WriteSerialPort(charArray);

		// Informacja o wyniku wysy³ania danych
		if (is_sent)
		{
			textBox1->Text = "Have sent: " + managedString;
			//textBox1->Text = managedString;
		}
		else
		{
			textBox1->Text = "Error";
		}
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
};
}
