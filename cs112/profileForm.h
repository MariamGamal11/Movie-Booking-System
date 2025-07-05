#pragma once
#include "ExcelManger.h"
#include "users.h"
#include "loginForm.h"
#include "Marvel.h"

namespace cs112 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for profileForm
	/// </summary>
	public ref class profileForm : public System::Windows::Forms::Form
	{
	
	private: System::Windows::Forms::PictureBox^ back;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	private: System::Windows::Forms::Label^ logout;
	private:
		String^ currentUsername;
		User^ user;
		Form^ homeForm;
		loginForm^ loginFomInstance;
	public:
		profileForm(User^ user, Form^ home,loginForm^ login)
		{
			InitializeComponent();
			homeForm = home;
			loginFomInstance = login;
			this->currentUsername = user->username; 
			this->user = user; 
			usern->Text = this->currentUsername;
			usrlabel->Text = "Welcome " + this->currentUsername;
			loadBookings(); 

			this->FormClosing += gcnew FormClosingEventHandler(this, &profileForm::profileForm_FormClosing);
			this->past_bookings->MouseEnter += gcnew System::EventHandler(this, &profileForm::Label_MouseEnter);
			this->past_bookings->MouseLeave += gcnew System::EventHandler(this, &profileForm::Label_MouseLeave);
			this->past_bookings->Click += gcnew System::EventHandler(this, &profileForm::Label_Click);

			this->upcoming_bookings->MouseEnter += gcnew System::EventHandler(this, &profileForm::Label_MouseEnter);
			this->upcoming_bookings->MouseLeave += gcnew System::EventHandler(this, &profileForm::Label_MouseLeave);
			this->upcoming_bookings->Click += gcnew System::EventHandler(this, &profileForm::Label_Click);


			this->logout->MouseEnter += gcnew System::EventHandler(this, &profileForm::Label_MouseEnter);
			this->logout->MouseLeave += gcnew System::EventHandler(this, &profileForm::Label_MouseLeave);

			this->back->MouseEnter += gcnew System::EventHandler(this, &profileForm::Pic_MouseEnter);
			this->back->MouseLeave += gcnew System::EventHandler(this, &profileForm::Pic_MouseLeave);


			this->upcoming_listview->View = System::Windows::Forms::View::Details;
			this->upcoming_listview->Columns->Add("Movie", 200);
			this->upcoming_listview->Columns->Add("Date", 150);
			this->upcoming_listview->Columns->Add("Seats", 100);
			this->upcoming_listview->Columns->Add("Ticket Price", 120);

			this->past_listview->View = System::Windows::Forms::View::Details;
			this->past_listview->Columns->Add("Movie", 200);
			this->past_listview->Columns->Add("Date", 150);
			this->past_listview->Columns->Add("Seats", 100);
			this->past_listview->Columns->Add("Ticket Price", 120);

		}
	private:
		System::Void profileForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			e->Cancel = true; // Prevent closing
			this->Hide(); // Hide instead of closing
			if (homeForm != nullptr) {
				homeForm->Show();
				homeForm->BringToFront();
			}
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~profileForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ menu_icon;
	private: System::Windows::Forms::Panel^ side_barPanel;


	private: System::Windows::Forms::Label^ usern;

	private: System::Windows::Forms::PictureBox^ pictureBox6;

	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ upcoming_bookings;


	private: System::Windows::Forms::Label^ past_bookings;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ sideBar_2Panel;
	private: System::Windows::Forms::ListView^ past_listview;


	private: System::Windows::Forms::ListView^ upcoming_listview;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
	private: System::Windows::Forms::Label^ usrlabel;




		   System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(profileForm::typeid));
			   this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			   this->menu_icon = (gcnew System::Windows::Forms::PictureBox());
			   this->side_barPanel = (gcnew System::Windows::Forms::Panel());
			   this->logout = (gcnew System::Windows::Forms::Label());
			   this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			   this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			   this->upcoming_bookings = (gcnew System::Windows::Forms::Label());
			   this->past_bookings = (gcnew System::Windows::Forms::Label());
			   this->usern = (gcnew System::Windows::Forms::Label());
			   this->sideBar_2Panel = (gcnew System::Windows::Forms::PictureBox());
			   this->past_listview = (gcnew System::Windows::Forms::ListView());
			   this->upcoming_listview = (gcnew System::Windows::Forms::ListView());
			   this->usrlabel = (gcnew System::Windows::Forms::Label());
			   this->back = (gcnew System::Windows::Forms::PictureBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->menu_icon))->BeginInit();
			   this->side_barPanel->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sideBar_2Panel))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // pictureBox1
			   // 
			   this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			   this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pictureBox1->Location = System::Drawing::Point(-2, 0);
			   this->pictureBox1->Name = L"pictureBox1";
			   this->pictureBox1->Size = System::Drawing::Size(120, 120);
			   this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox1->TabIndex = 1;
			   this->pictureBox1->TabStop = false;
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->BackColor = System::Drawing::Color::Transparent;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Viner Hand ITC", 25.8F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(231)), static_cast<System::Int32>(static_cast<System::Byte>(203)),
				   static_cast<System::Int32>(static_cast<System::Byte>(251)));
			   this->label2->Location = System::Drawing::Point(116, 33);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(227, 69);
			   this->label2->TabIndex = 2;
			   this->label2->Text = L"CineVerse";
			   this->label2->Click += gcnew System::EventHandler(this, &profileForm::label2_Click);
			   // 
			   // pictureBox2
			   // 
			   this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			   this->pictureBox2->Location = System::Drawing::Point(21, 15);
			   this->pictureBox2->Name = L"pictureBox2";
			   this->pictureBox2->Size = System::Drawing::Size(53, 50);
			   this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox2->TabIndex = 3;
			   this->pictureBox2->TabStop = false;
			   // 
			   // menu_icon
			   // 
			   this->menu_icon->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->menu_icon->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(63)),
				   static_cast<System::Int32>(static_cast<System::Byte>(105)));
			   this->menu_icon->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"menu_icon.BackgroundImage")));
			   this->menu_icon->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->menu_icon->Cursor = System::Windows::Forms::Cursors::Hand;
			   this->menu_icon->Location = System::Drawing::Point(1011, 0);
			   this->menu_icon->Name = L"menu_icon";
			   this->menu_icon->Size = System::Drawing::Size(77, 86);
			   this->menu_icon->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->menu_icon->TabIndex = 5;
			   this->menu_icon->TabStop = false;
			   this->menu_icon->Click += gcnew System::EventHandler(this, &profileForm::menu_icon_Click);
			   // 
			   // side_barPanel
			   // 
			   this->side_barPanel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->side_barPanel->BackColor = System::Drawing::Color::Transparent;
			   this->side_barPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"side_barPanel.BackgroundImage")));
			   this->side_barPanel->Controls->Add(this->logout);
			   this->side_barPanel->Controls->Add(this->pictureBox9);
			   this->side_barPanel->Controls->Add(this->label1);
			   this->side_barPanel->Controls->Add(this->pictureBox6);
			   this->side_barPanel->Controls->Add(this->pictureBox4);
			   this->side_barPanel->Controls->Add(this->upcoming_bookings);
			   this->side_barPanel->Controls->Add(this->past_bookings);
			   this->side_barPanel->Controls->Add(this->usern);
			   this->side_barPanel->Controls->Add(this->pictureBox2);
			   this->side_barPanel->Location = System::Drawing::Point(812, 108);
			   this->side_barPanel->Name = L"side_barPanel";
			   this->side_barPanel->Size = System::Drawing::Size(267, 648);
			   this->side_barPanel->TabIndex = 6;
			   this->side_barPanel->Visible = false;
			   // 
			   // logout
			   // 
			   this->logout->AutoSize = true;
			   this->logout->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold));
			   this->logout->ForeColor = System::Drawing::Color::LightCyan;
			   this->logout->Location = System::Drawing::Point(55, 359);
			   this->logout->Name = L"logout";
			   this->logout->Size = System::Drawing::Size(71, 22);
			   this->logout->TabIndex = 18;
			   this->logout->Text = L"Logout";
			   this->logout->Click += gcnew System::EventHandler(this, &profileForm::logout_Click);
			   // 
			   // pictureBox9
			   // 
			   this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			   this->pictureBox9->Location = System::Drawing::Point(18, 356);
			   this->pictureBox9->Name = L"pictureBox9";
			   this->pictureBox9->Size = System::Drawing::Size(31, 30);
			   this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox9->TabIndex = 14;
			   this->pictureBox9->TabStop = false;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->BackColor = System::Drawing::Color::Transparent;
			   this->label1->ForeColor = System::Drawing::Color::White;
			   this->label1->Location = System::Drawing::Point(40, 104);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(168, 16);
			   this->label1->TabIndex = 9;
			   this->label1->Text = L"_______________________";
			   // 
			   // pictureBox6
			   // 
			   this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.BackgroundImage")));
			   this->pictureBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pictureBox6->Location = System::Drawing::Point(9, 266);
			   this->pictureBox6->Name = L"pictureBox6";
			   this->pictureBox6->Size = System::Drawing::Size(40, 40);
			   this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox6->TabIndex = 13;
			   this->pictureBox6->TabStop = false;
			   // 
			   // pictureBox4
			   // 
			   this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
			   this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			   this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->pictureBox4->Location = System::Drawing::Point(11, 182);
			   this->pictureBox4->Name = L"pictureBox4";
			   this->pictureBox4->Size = System::Drawing::Size(40, 40);
			   this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->pictureBox4->TabIndex = 11;
			   this->pictureBox4->TabStop = false;
			   // 
			   // upcoming_bookings
			   // 
			   this->upcoming_bookings->AutoSize = true;
			   this->upcoming_bookings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->upcoming_bookings->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			   this->upcoming_bookings->Location = System::Drawing::Point(50, 275);
			   this->upcoming_bookings->Name = L"upcoming_bookings";
			   this->upcoming_bookings->Size = System::Drawing::Size(186, 22);
			   this->upcoming_bookings->TabIndex = 9;
			   this->upcoming_bookings->Text = L"Upcoming Bookings";
			   // 
			   // past_bookings
			   // 
			   this->past_bookings->AutoSize = true;
			   this->past_bookings->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->past_bookings->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			   this->past_bookings->Location = System::Drawing::Point(49, 191);
			   this->past_bookings->Name = L"past_bookings";
			   this->past_bookings->Size = System::Drawing::Size(138, 22);
			   this->past_bookings->TabIndex = 8;
			   this->past_bookings->Text = L"Past Bookings";
			   // 
			   // usern
			   // 
			   this->usern->AutoSize = true;
			   this->usern->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->usern->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			   this->usern->Location = System::Drawing::Point(30, 76);
			   this->usern->Name = L"usern";
			   this->usern->Size = System::Drawing::Size(49, 22);
			   this->usern->TabIndex = 7;
			   this->usern->Text = L"user";
			   // 
			   // sideBar_2Panel
			   // 
			   this->sideBar_2Panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->sideBar_2Panel->BackColor = System::Drawing::Color::Transparent;
			   this->sideBar_2Panel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sideBar_2Panel.BackgroundImage")));
			   this->sideBar_2Panel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->sideBar_2Panel->Location = System::Drawing::Point(812, 1);
			   this->sideBar_2Panel->Name = L"sideBar_2Panel";
			   this->sideBar_2Panel->Size = System::Drawing::Size(267, 163);
			   this->sideBar_2Panel->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->sideBar_2Panel->TabIndex = 14;
			   this->sideBar_2Panel->TabStop = false;
			   this->sideBar_2Panel->Visible = false;
			   // 
			   // past_listview
			   // 
			   this->past_listview->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->past_listview->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				   static_cast<System::Int32>(static_cast<System::Byte>(216)));
			   this->past_listview->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->past_listview->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->past_listview->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				   static_cast<System::Int32>(static_cast<System::Byte>(93)));
			   this->past_listview->FullRowSelect = true;
			   this->past_listview->HideSelection = false;
			   this->past_listview->Location = System::Drawing::Point(127, 268);
			   this->past_listview->Name = L"past_listview";
			   this->past_listview->Size = System::Drawing::Size(590, 247);
			   this->past_listview->TabIndex = 0;
			   this->past_listview->UseCompatibleStateImageBehavior = false;
			   this->past_listview->View = System::Windows::Forms::View::Details;
			   this->past_listview->Visible = false;
			   // 
			   // upcoming_listview
			   // 
			   this->upcoming_listview->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(173)),
				   static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(216)));
			   this->upcoming_listview->BorderStyle = System::Windows::Forms::BorderStyle::None;
			   this->upcoming_listview->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Bold));
			   this->upcoming_listview->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(76)),
				   static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(93)));
			   this->upcoming_listview->FullRowSelect = true;
			   this->upcoming_listview->HideSelection = false;
			   this->upcoming_listview->Location = System::Drawing::Point(127, 268);
			   this->upcoming_listview->Name = L"upcoming_listview";
			   this->upcoming_listview->Size = System::Drawing::Size(590, 247);
			   this->upcoming_listview->TabIndex = 15;
			   this->upcoming_listview->UseCompatibleStateImageBehavior = false;
			   this->upcoming_listview->View = System::Windows::Forms::View::Details;
			   this->upcoming_listview->Visible = false;
			   // 
			   // usrlabel
			   // 
			   this->usrlabel->AutoSize = true;
			   this->usrlabel->BackColor = System::Drawing::Color::Transparent;
			   this->usrlabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->usrlabel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(219)), static_cast<System::Int32>(static_cast<System::Byte>(177)),
				   static_cast<System::Int32>(static_cast<System::Byte>(250)));
			   this->usrlabel->Location = System::Drawing::Point(423, 32);
			   this->usrlabel->Name = L"usrlabel";
			   this->usrlabel->Size = System::Drawing::Size(279, 54);
			   this->usrlabel->TabIndex = 16;
			   this->usrlabel->Text = L"User Profile";
			   // 
			   // back
			   // 
			   this->back->BackColor = System::Drawing::Color::Transparent;
			   this->back->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back.Image")));
			   this->back->Location = System::Drawing::Point(12, 696);
			   this->back->Name = L"back";
			   this->back->Size = System::Drawing::Size(42, 42);
			   this->back->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			   this->back->TabIndex = 17;
			   this->back->TabStop = false;
			   this->back->Click += gcnew System::EventHandler(this, &profileForm::back_Click);
			   // 
			   // profileForm
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			   this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			   this->ClientSize = System::Drawing::Size(1080, 750);
			   this->Controls->Add(this->back);
			   this->Controls->Add(this->usrlabel);
			   this->Controls->Add(this->upcoming_listview);
			   this->Controls->Add(this->past_listview);
			   this->Controls->Add(this->pictureBox1);
			   this->Controls->Add(this->menu_icon);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->side_barPanel);
			   this->Controls->Add(this->sideBar_2Panel);
			   this->DoubleBuffered = true;
			   this->Name = L"profileForm";
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"Your Profile";
			   this->Load += gcnew System::EventHandler(this, &profileForm::profile_Load);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->menu_icon))->EndInit();
			   this->side_barPanel->ResumeLayout(false);
			   this->side_barPanel->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sideBar_2Panel))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }

#pragma endregion
		   //This function loads bookings into the ListViews
		   void profileForm::loadBookings()
		   {
			   auto bookings = ExcelManager::GetBookingsForUser(currentUsername); // calls bookings associated with the current user
			   DateTime today = DateTime::Now; // retrieves current date and time

			   this->past_listview->Items->Clear();
			   this->upcoming_listview->Items->Clear();

			   for each(Booking b in bookings) {
				   String^ movie = gcnew String(b.movieName.c_str());
				   String^ date = gcnew String(b.date.c_str());
				   String^ seats = gcnew String(b.seats.c_str());
				   String^ price = gcnew String(b.price.c_str());
				   array<String^>^ row = gcnew array<String^>{ movie, date, seats,price}; // creates an array of managed strings that represents a row in the ListView.
				   DateTime movieDate;
				   if (!DateTime::TryParse(date, movieDate)) continue;

				   if (movieDate < today)
					   past_listview->Items->Add(gcnew ListViewItem(row));
				   else
					   upcoming_listview->Items->Add(gcnew ListViewItem(row));
			   }
		   }

		   void profileForm::profile_Load(System::Object^ sender, System::EventArgs^ e)
		   {
			   loadBookings();
		   }
		   System::Void profileForm::Label_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			   Label^ lbl = safe_cast<Label^>(sender);
			   lbl->BackColor = Color::FromArgb(50, 50, 70); // Hover background
			   lbl->ForeColor = Color::White;               // change text color
			   lbl->Cursor = Cursors::Hand;
		   }

		   System::Void profileForm::Label_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			   Label^ lbl = safe_cast<Label^>(sender);
			   lbl->BackColor = Color::Transparent;          // Reset background
			   lbl->ForeColor = SystemColors::ActiveCaption; // Reset text color
			   lbl->Cursor = Cursors::Default;
		   }

		   System::Void profileForm::Pic_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
			   PictureBox^ pic = safe_cast<PictureBox^>(sender);
			   pic->Cursor = Cursors::Hand;
		   }

		   System::Void profileForm::Pic_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
			   PictureBox^ pic = safe_cast<PictureBox^>(sender);
			   pic->Cursor = Cursors::Default;
		   }

		   System::Void profileForm::Label_Click(System::Object^ sender, System::EventArgs^ e) {
			   Label^ clickedLabel = safe_cast<Label^>(sender);

			   // Reset both labels first
			   past_bookings->ForeColor = Color::LightBlue;
			   upcoming_bookings->ForeColor = Color::LightBlue;

			   // Highlight clicked one
			   clickedLabel->ForeColor = Color::DeepSkyBlue;

			   // TODO: Show the relevant ListView (watched or upcoming)
			   if (clickedLabel == past_bookings) {
				   past_listview->Visible = !past_listview->Visible;
				   upcoming_listview->Visible = false;
			   }
			   else {
				   upcoming_listview->Visible = !upcoming_listview->Visible;
				   past_listview->Visible = false;
			   }
		   }

	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void menu_icon_Click(System::Object^ sender, System::EventArgs^ e) {
		// Toggle the visibility of the profile panel when the menu icon is clicked
		side_barPanel->Visible = !side_barPanel->Visible;
		sideBar_2Panel->Visible = !sideBar_2Panel->Visible;

	}
	private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();      
		homeForm->Show();
	}
private: System::Void logout_Click(System::Object^ sender, System::EventArgs^ e) {
	// Show the existing login form
	if (loginFomInstance != nullptr) {
		loginFomInstance->Show();
		loginFomInstance->BringToFront();
		loginFomInstance->Reset(); // Clear previous login data
	}
	this->Hide();
	if (homeForm != nullptr) {
		homeForm->Hide();
	}
	// Reset the user object
	this->user = nullptr;
}
};
}