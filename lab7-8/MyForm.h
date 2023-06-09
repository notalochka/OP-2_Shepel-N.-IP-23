#pragma once

namespace labaratorna7 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonAdd;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBoxName;
	private: System::Windows::Forms::TextBox^ textBoxGroup;
	private: System::Windows::Forms::TextBox^ textBoxDay;
	private: System::Windows::Forms::TextBox^ textBoxMonth;
	private: System::Windows::Forms::TextBox^ textBoxYear;





	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ textBoxFilename1;
	private: System::Windows::Forms::TextBox^ textBoxFilename2;
	private: System::Windows::Forms::Button^ buttonCreateFile1;
	private: System::Windows::Forms::Button^ buttonReadFile1;




	private: System::Windows::Forms::Button^ buttonCreateFile2;
	private: System::Windows::Forms::Button^ buttonReadFile2;
	private: System::Windows::Forms::Button^ buttonRewriteFile2;



	private: System::Windows::Forms::RichTextBox^ richTextBoxFile1;
	private: System::Windows::Forms::RichTextBox^ richTextFile2;


	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonAdd = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBoxName = (gcnew System::Windows::Forms::TextBox());
			this->textBoxGroup = (gcnew System::Windows::Forms::TextBox());
			this->textBoxDay = (gcnew System::Windows::Forms::TextBox());
			this->textBoxMonth = (gcnew System::Windows::Forms::TextBox());
			this->textBoxYear = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBoxFilename1 = (gcnew System::Windows::Forms::TextBox());
			this->textBoxFilename2 = (gcnew System::Windows::Forms::TextBox());
			this->buttonCreateFile1 = (gcnew System::Windows::Forms::Button());
			this->buttonReadFile1 = (gcnew System::Windows::Forms::Button());
			this->buttonCreateFile2 = (gcnew System::Windows::Forms::Button());
			this->buttonReadFile2 = (gcnew System::Windows::Forms::Button());
			this->buttonRewriteFile2 = (gcnew System::Windows::Forms::Button());
			this->richTextBoxFile1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextFile2 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// buttonAdd
			// 
			this->buttonAdd->Location = System::Drawing::Point(808, 55);
			this->buttonAdd->Name = L"buttonAdd";
			this->buttonAdd->Size = System::Drawing::Size(187, 75);
			this->buttonAdd->TabIndex = 0;
			this->buttonAdd->Text = L"Додати у вхідний файл";
			this->buttonAdd->UseVisualStyleBackColor = true;
			this->buttonAdd->Click += gcnew System::EventHandler(this, &MyForm::buttonAdd_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(77, 39);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 29);
			this->label1->TabIndex = 1;
			this->label1->Text = L"ПІБ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(78, 110);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 29);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Група";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(82, 183);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(233, 29);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Дата народження";
			// 
			// textBoxName
			// 
			this->textBoxName->Location = System::Drawing::Point(172, 36);
			this->textBoxName->Name = L"textBoxName";
			this->textBoxName->Size = System::Drawing::Size(210, 34);
			this->textBoxName->TabIndex = 4;
			// 
			// textBoxGroup
			// 
			this->textBoxGroup->Location = System::Drawing::Point(172, 105);
			this->textBoxGroup->Name = L"textBoxGroup";
			this->textBoxGroup->Size = System::Drawing::Size(133, 34);
			this->textBoxGroup->TabIndex = 5;
			// 
			// textBoxDay
			// 
			this->textBoxDay->Location = System::Drawing::Point(349, 180);
			this->textBoxDay->Name = L"textBoxDay";
			this->textBoxDay->Size = System::Drawing::Size(82, 34);
			this->textBoxDay->TabIndex = 6;
			// 
			// textBoxMonth
			// 
			this->textBoxMonth->Location = System::Drawing::Point(459, 181);
			this->textBoxMonth->Name = L"textBoxMonth";
			this->textBoxMonth->Size = System::Drawing::Size(75, 34);
			this->textBoxMonth->TabIndex = 7;
			// 
			// textBoxYear
			// 
			this->textBoxYear->Location = System::Drawing::Point(569, 181);
			this->textBoxYear->Name = L"textBoxYear";
			this->textBoxYear->Size = System::Drawing::Size(141, 34);
			this->textBoxYear->TabIndex = 8;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(353, 140);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 29);
			this->label4->TabIndex = 9;
			this->label4->Text = L"день";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(451, 139);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(95, 29);
			this->label5->TabIndex = 10;
			this->label5->Text = L"місяць";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(615, 140);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 29);
			this->label6->TabIndex = 11;
			this->label6->Text = L"рік";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(150, 252);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(217, 29);
			this->label7->TabIndex = 12;
			this->label7->Text = L"ВХІДНИЙ ФАЙЛ";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(705, 252);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(236, 29);
			this->label8->TabIndex = 13;
			this->label8->Text = L"ВИХІДНИЙ ФАЙЛ";
			// 
			// textBoxFilename1
			// 
			this->textBoxFilename1->Location = System::Drawing::Point(166, 299);
			this->textBoxFilename1->Name = L"textBoxFilename1";
			this->textBoxFilename1->Size = System::Drawing::Size(180, 34);
			this->textBoxFilename1->TabIndex = 14;
			// 
			// textBoxFilename2
			// 
			this->textBoxFilename2->Location = System::Drawing::Point(732, 299);
			this->textBoxFilename2->Name = L"textBoxFilename2";
			this->textBoxFilename2->Size = System::Drawing::Size(180, 34);
			this->textBoxFilename2->TabIndex = 15;
			// 
			// buttonCreateFile1
			// 
			this->buttonCreateFile1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCreateFile1->Location = System::Drawing::Point(125, 339);
			this->buttonCreateFile1->Name = L"buttonCreateFile1";
			this->buttonCreateFile1->Size = System::Drawing::Size(107, 44);
			this->buttonCreateFile1->TabIndex = 16;
			this->buttonCreateFile1->Text = L"створити";
			this->buttonCreateFile1->UseVisualStyleBackColor = true;
			this->buttonCreateFile1->Click += gcnew System::EventHandler(this, &MyForm::buttonCreateFile1_Click);
			// 
			// buttonReadFile1
			// 
			this->buttonReadFile1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonReadFile1->Location = System::Drawing::Point(277, 339);
			this->buttonReadFile1->Name = L"buttonReadFile1";
			this->buttonReadFile1->Size = System::Drawing::Size(117, 44);
			this->buttonReadFile1->TabIndex = 17;
			this->buttonReadFile1->Text = L"прочитати";
			this->buttonReadFile1->UseVisualStyleBackColor = true;
			this->buttonReadFile1->Click += gcnew System::EventHandler(this, &MyForm::buttonReadFile1_Click);
			// 
			// buttonCreateFile2
			// 
			this->buttonCreateFile2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonCreateFile2->Location = System::Drawing::Point(692, 339);
			this->buttonCreateFile2->Name = L"buttonCreateFile2";
			this->buttonCreateFile2->Size = System::Drawing::Size(107, 44);
			this->buttonCreateFile2->TabIndex = 18;
			this->buttonCreateFile2->Text = L"створити";
			this->buttonCreateFile2->UseVisualStyleBackColor = true;
			this->buttonCreateFile2->Click += gcnew System::EventHandler(this, &MyForm::buttonCreateFile2_Click);
			// 
			// buttonReadFile2
			// 
			this->buttonReadFile2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonReadFile2->Location = System::Drawing::Point(851, 339);
			this->buttonReadFile2->Name = L"buttonReadFile2";
			this->buttonReadFile2->Size = System::Drawing::Size(117, 44);
			this->buttonReadFile2->TabIndex = 19;
			this->buttonReadFile2->Text = L"прочитати";
			this->buttonReadFile2->UseVisualStyleBackColor = true;
			this->buttonReadFile2->Click += gcnew System::EventHandler(this, &MyForm::buttonReadFile2_Click);
			// 
			// buttonRewriteFile2
			// 
			this->buttonRewriteFile2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonRewriteFile2->Location = System::Drawing::Point(459, 284);
			this->buttonRewriteFile2->Name = L"buttonRewriteFile2";
			this->buttonRewriteFile2->Size = System::Drawing::Size(167, 90);
			this->buttonRewriteFile2->TabIndex = 20;
			this->buttonRewriteFile2->Text = L"Перезаписати у файл неповнолітніх";
			this->buttonRewriteFile2->UseVisualStyleBackColor = true;
			this->buttonRewriteFile2->Click += gcnew System::EventHandler(this, &MyForm::buttonRewriteFile2_Click);
			// 
			// richTextBoxFile1
			// 
			this->richTextBoxFile1->Location = System::Drawing::Point(48, 405);
			this->richTextBoxFile1->Name = L"richTextBoxFile1";
			this->richTextBoxFile1->Size = System::Drawing::Size(470, 207);
			this->richTextBoxFile1->TabIndex = 21;
			this->richTextBoxFile1->Text = L"";
			// 
			// richTextFile2
			// 
			this->richTextFile2->Location = System::Drawing::Point(590, 405);
			this->richTextFile2->Name = L"richTextFile2";
			this->richTextFile2->Size = System::Drawing::Size(470, 207);
			this->richTextFile2->TabIndex = 22;
			this->richTextFile2->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(15, 29);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(1112, 636);
			this->Controls->Add(this->richTextFile2);
			this->Controls->Add(this->richTextBoxFile1);
			this->Controls->Add(this->buttonRewriteFile2);
			this->Controls->Add(this->buttonReadFile2);
			this->Controls->Add(this->buttonCreateFile2);
			this->Controls->Add(this->buttonReadFile1);
			this->Controls->Add(this->buttonCreateFile1);
			this->Controls->Add(this->textBoxFilename2);
			this->Controls->Add(this->textBoxFilename1);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBoxYear);
			this->Controls->Add(this->textBoxMonth);
			this->Controls->Add(this->textBoxDay);
			this->Controls->Add(this->textBoxGroup);
			this->Controls->Add(this->textBoxName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonAdd);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(6, 5, 6, 5);
			this->Name = L"MyForm";
			this->Text = L"labaratorna 7-8";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void buttonCreateFile1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonReadFile1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonAdd_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonRewriteFile2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonCreateFile2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonReadFile2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
