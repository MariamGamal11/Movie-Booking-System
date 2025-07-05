#pragma once

#include "users.h"
namespace cs112 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::OleDb;

	/// <summary>
	/// Summary for signinForm
	/// </summary>
	public ref class signinForm : public System::Windows::Forms::Form
	{
	public:
		signinForm(void)
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
		~signinForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;



	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ tbpass;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ tbuser;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::TextBox^ tbconpass;

	private: System::Windows::Forms::Label^ label3;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(signinForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tbpass = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tbuser = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->tbconpass = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(24, 35);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(150, 150);
			this->pictureBox1->TabIndex = 21;
			this->pictureBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Viner Hand ITC", 36));
			this->label4->ForeColor = System::Drawing::Color::Thistle;
			this->label4->Location = System::Drawing::Point(176, 83);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(308, 97);
			this->label4->TabIndex = 20;
			this->label4->Text = L"CineVerse";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(108)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(154)));
			this->button1->Location = System::Drawing::Point(236, 627);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(110, 50);
			this->button1->TabIndex = 19;
			this->button1->Text = L"Sign up";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &signinForm::button2_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(108)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
				static_cast<System::Int32>(static_cast<System::Byte>(154)));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::Black;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::Color::Indigo;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(64, 627);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(128, 50);
			this->button2->TabIndex = 18;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &signinForm::button1_Click);
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(100, 417);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(330, 5);
			this->panel2->TabIndex = 17;
			// 
			// tbpass
			// 
			this->tbpass->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(54)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(88)));
			this->tbpass->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbpass->Font = (gcnew System::Drawing::Font(L"High Tower Text", 18));
			this->tbpass->ForeColor = System::Drawing::Color::Lavender;
			this->tbpass->Location = System::Drawing::Point(99, 384);
			this->tbpass->Name = L"tbpass";
			this->tbpass->Size = System::Drawing::Size(330, 35);
			this->tbpass->TabIndex = 16;
			this->tbpass->UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(38, 328);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(163, 46);
			this->label2->TabIndex = 15;
			this->label2->Text = L"password";
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(100, 299);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(330, 5);
			this->panel1->TabIndex = 14;
			// 
			// tbuser
			// 
			this->tbuser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->tbuser->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbuser->Font = (gcnew System::Drawing::Font(L"High Tower Text", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tbuser->ForeColor = System::Drawing::Color::Lavender;
			this->tbuser->Location = System::Drawing::Point(99, 266);
			this->tbuser->Name = L"tbuser";
			this->tbuser->Size = System::Drawing::Size(330, 35);
			this->tbuser->TabIndex = 13;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(38, 210);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 46);
			this->label1->TabIndex = 12;
			this->label1->Text = L"username";
			// 
			// panel3
			// 
			this->panel3->Location = System::Drawing::Point(100, 563);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(330, 5);
			this->panel3->TabIndex = 24;
			// 
			// tbconpass
			// 
			this->tbconpass->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->tbconpass->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->tbconpass->Font = (gcnew System::Drawing::Font(L"High Tower Text", 18));
			this->tbconpass->ForeColor = System::Drawing::Color::Lavender;
			this->tbconpass->Location = System::Drawing::Point(99, 530);
			this->tbconpass->Name = L"tbconpass";
			this->tbconpass->Size = System::Drawing::Size(330, 35);
			this->tbconpass->TabIndex = 23;
			this->tbconpass->UseSystemPasswordChar = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(38, 474);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(290, 46);
			this->label3->TabIndex = 22;
			this->label3->Text = L"confirm password";
			// 
			// signinForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1080, 750);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->tbconpass);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->tbpass);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->tbuser);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"signinForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"signinForm";
			this->Load += gcnew System::EventHandler(this, &signinForm::signinForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &signinForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &signinForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &signinForm::MyForm_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}

public: User^ user = nullptr;
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ usrnm = tbuser->Text;
	String^ pss = tbpass->Text;
	String^ copss = tbconpass->Text;

	if (usrnm->Length == 0 || pss->Length == 0 || copss->Length == 0) {
		MessageBox::Show("Fill all fields", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	if (String::Compare(pss, copss) != 0) {
		MessageBox::Show("Passwords do not match", "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;
	}

	String^ excelFilePath = "..\\data\\cinema_data.xlsx";
	String^ connString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + excelFilePath + ";Extended Properties=\"Excel 12.0 Xml;HDR=YES\";";

	OleDbConnection^ conn = gcnew OleDbConnection(connString);

	try {
		conn->Open();

		// Get the next ID
		String^ maxIdQuery = "SELECT MAX(id) FROM [Users$];";
		OleDbCommand^ cmdMaxId = gcnew OleDbCommand(maxIdQuery, conn);
		Object^ result = cmdMaxId->ExecuteScalar();
		int newId = (result != nullptr && !Convert::IsDBNull(result)) ? Convert::ToInt32(result) + 1 : 1;

		// Corrected SQL query (note [password])
		String^ sqlQuery = "INSERT INTO [Users$] (id, username, [password]) VALUES (?, ?, ?);";
		OleDbCommand^ command = gcnew OleDbCommand(sqlQuery, conn);

		// Add parameters IN ORDER: id, username, password
		command->Parameters->AddWithValue("", newId);
		command->Parameters->AddWithValue("", usrnm);
		command->Parameters->AddWithValue("", pss);

		command->ExecuteNonQuery();

		MessageBox::Show("Registration successful!", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Hide();
	}
	catch (Exception^ ex) {
		MessageBox::Show(ex->Message, "Excel Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	finally {
		if (conn->State == ConnectionState::Open) {
			conn->Close();
		}
	}
}
private: System::Void signinForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
	   bool drag;
	   Point offset;

	   private:
		   System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			   drag = true;
			   offset = e->Location;
		   }

private:
	System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (drag) {
			Point currentScreenPos = PointToScreen(e->Location);
			this->Location = Point(currentScreenPos.X - offset.X, currentScreenPos.Y - offset.Y);
		}
	}

private:
	System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		drag = false;
	}



};
}
