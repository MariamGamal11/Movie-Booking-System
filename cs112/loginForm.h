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
	/// Summary for loginForm
	/// </summary>
	public ref class loginForm : public System::Windows::Forms::Form
	{
	public:
		loginForm(void)
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
		~loginForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::LinkLabel^ linklabel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button2;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(loginForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->linklabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(31, 244);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"username";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(84)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"High Tower Text", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Lavender;
			this->textBox1->Location = System::Drawing::Point(101, 297);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(330, 35);
			this->textBox1->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->Location = System::Drawing::Point(102, 328);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(330, 5);
			this->panel1->TabIndex = 2;
			// 
			// panel2
			// 
			this->panel2->Location = System::Drawing::Point(102, 492);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(330, 5);
			this->panel2->TabIndex = 5;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(90)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"High Tower Text", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->ForeColor = System::Drawing::Color::Lavender;
			this->textBox2->Location = System::Drawing::Point(101, 461);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(330, 35);
			this->textBox2->TabIndex = 4;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(31, 408);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(163, 46);
			this->label2->TabIndex = 3;
			this->label2->Text = L"password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Thistle;
			this->label3->Location = System::Drawing::Point(55, 635);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(207, 32);
			this->label3->TabIndex = 6;
			this->label3->Text = L"First time visiting\?";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// linklabel1
			// 
			this->linklabel1->ActiveLinkColor = System::Drawing::Color::White;
			this->linklabel1->AutoSize = true;
			this->linklabel1->BackColor = System::Drawing::Color::Transparent;
			this->linklabel1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->linklabel1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linklabel1->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(181)), static_cast<System::Int32>(static_cast<System::Byte>(161)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->linklabel1->Location = System::Drawing::Point(253, 635);
			this->linklabel1->Name = L"linklabel1";
			this->linklabel1->Size = System::Drawing::Size(170, 32);
			this->linklabel1->TabIndex = 7;
			this->linklabel1->TabStop = true;
			this->linklabel1->Text = L"create account";
			this->linklabel1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->linklabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &loginForm::linkLabel2_LinkClicked);
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
			this->button1->Location = System::Drawing::Point(266, 546);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(126, 47);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Log in";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &loginForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Viner Hand ITC", 36));
			this->label4->ForeColor = System::Drawing::Color::Thistle;
			this->label4->Location = System::Drawing::Point(180, 73);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(308, 97);
			this->label4->TabIndex = 10;
			this->label4->Text = L"CineVerse";
			this->label4->Click += gcnew System::EventHandler(this, &loginForm::label4_Click);
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
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// button2
			// 
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
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(94, 546);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 47);
			this->button2->TabIndex = 12;
			this->button2->Text = L"Exit";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &loginForm::button3_Click);
			// 
			// loginForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1080, 750);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->linklabel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"loginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"loginForm";
			this->Load += gcnew System::EventHandler(this, &loginForm::loginForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &loginForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &loginForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &loginForm::MyForm_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}

public: User^ user = nullptr;

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ username = this->textBox1->Text;
		String^ password = this->textBox2->Text;

		if (username->Length == 0 || password->Length == 0) {
			MessageBox::Show("Enter your username and password", "No input", MessageBoxButtons::RetryCancel, MessageBoxIcon::Exclamation);
			return;
		}

		// Excel file path (update this path)
		String^ excelFilePath = "..\\data\\cinema_data.xlsx";

		// Connection string for Excel (ACE OLEDB)
		String^ connString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + excelFilePath +
			";Extended Properties=\"Excel 12.0 Xml;HDR=YES\";";

		OleDbConnection^ conn = gcnew OleDbConnection(connString);

		try {
			conn->Open();

			// Query to read data from the "Users" sheet
			String^ sqlQuery = "SELECT * FROM [Users$] WHERE username = ? AND password = ?;";
			OleDbCommand^ command = gcnew OleDbCommand(sqlQuery, conn);
			command->Parameters->AddWithValue("username", username);
			command->Parameters->AddWithValue("password", password);

			OleDbDataReader^ reader = command->ExecuteReader();
			if (reader->Read()) {
				user = gcnew User;

				// Check if "id" column is not NULL
				if (!reader->IsDBNull(reader->GetOrdinal("id"))) {
					user->id = Convert::ToInt32(reader["id"]);
				}
				else {
					user->id = 0; // Default value or handle as needed
				}

				user->username = reader["username"]->ToString();
				user->password = reader["password"]->ToString();
				this->Hide();
			}

			else {
				MessageBox::Show("Username or password is incorrect", "Incorrect", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
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

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
		   //dragging the app:
		   bool drag;
		   Point offset;
private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	//enable
	drag = true;
	offset.X = e->X;
	offset.Y = e->Y;
}
private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (drag) {
		Point currentPosition = PointToScreen(Point(e->X, e->Y));
		Location = Point(currentPosition.X - offset.X, currentPosition.Y - offset.Y);
	}
}
private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	drag = false;
}
	   public: bool switchTORegister = false;
private: System::Void linkLabel2_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	this->switchTORegister = true;
	this->Hide();
}

private: System::Void loginForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}

	  public:
		  // Add the Reset method here
		  void Reset() {
			  user = nullptr;
			  textBox1->Text = "";
			  textBox2->Text = "";
			  switchTORegister = false;
		  }
};
}
