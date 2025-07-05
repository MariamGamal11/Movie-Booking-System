#pragma once

#include "users.h"
#include "profileForm.h"
#include "loginForm.h"
#include "Marvel.h"
#include "Adaptations.h"
#include "Anime.h"
#include "DC.h"
#include "Disney.h"

namespace cs112 {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for Categories
    /// </summary>
    public ref class homeForm : public System::Windows::Forms::Form
    {
    private:
        User^ user;
        loginForm^ loginFormInstance;

    public:
        homeForm(User^ user, loginForm^ login)
        {
            InitializeComponent();
            this->user = user; // Store the user
            prof->Text = user->username;
            this->loginFormInstance = login;

            this->pictureBox1->Click += gcnew System::EventHandler(this, &homeForm::pictureBox1_Click_1);

            this->FormClosing += gcnew FormClosingEventHandler(this, &homeForm::homeForm_FormClosing);
        }

        void homeForm_FormClosing(Object^ sender, FormClosingEventArgs^ e) {
            // Allow the form to close
            if (loginFormInstance != nullptr) {
                loginFormInstance->Show();
                loginFormInstance->BringToFront();
                loginFormInstance->Reset();
            }
        }


    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~homeForm()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::PictureBox^ logo;
    private: System::Windows::Forms::Label^ appName;
    private: System::Windows::Forms::Button^ dcButton;
    private: System::Windows::Forms::Button^ bookButton;
    private: System::Windows::Forms::Button^ animeButton;
    private: System::Windows::Forms::Button^ marvelButton;
    private: System::Windows::Forms::Button^ disneyButton;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Label^ prof;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(homeForm::typeid));
            this->logo = (gcnew System::Windows::Forms::PictureBox());
            this->appName = (gcnew System::Windows::Forms::Label());
            this->dcButton = (gcnew System::Windows::Forms::Button());
            this->bookButton = (gcnew System::Windows::Forms::Button());
            this->animeButton = (gcnew System::Windows::Forms::Button());
            this->marvelButton = (gcnew System::Windows::Forms::Button());
            this->disneyButton = (gcnew System::Windows::Forms::Button());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->prof = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // logo
            // 
            this->logo->BackColor = System::Drawing::Color::Transparent;
            this->logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.Image")));
            this->logo->Location = System::Drawing::Point(0, 1);
            this->logo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->logo->Name = L"logo";
            this->logo->Size = System::Drawing::Size(115, 102);
            this->logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->logo->TabIndex = 0;
            this->logo->TabStop = false;
            this->logo->Click += gcnew System::EventHandler(this, &homeForm::pictureBox1_Click);
            // 
            // appName
            // 
            this->appName->AutoSize = true;
            this->appName->BackColor = System::Drawing::Color::Transparent;
            this->appName->Font = (gcnew System::Drawing::Font(L"Viner Hand ITC", 32, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->appName->ForeColor = System::Drawing::Color::Thistle;
            this->appName->Location = System::Drawing::Point(116, 16);
            this->appName->Name = L"appName";
            this->appName->Size = System::Drawing::Size(275, 87);
            this->appName->TabIndex = 1;
            this->appName->Text = L"CineVerse";
            this->appName->Click += gcnew System::EventHandler(this, &homeForm::label1_Click);
            // 
            // dcButton
            // 
            this->dcButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->dcButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dcButton.BackgroundImage")));
            this->dcButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->dcButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->dcButton->Location = System::Drawing::Point(712, 433);
            this->dcButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->dcButton->Name = L"dcButton";
            this->dcButton->Size = System::Drawing::Size(192, 139);
            this->dcButton->TabIndex = 3;
            this->dcButton->UseVisualStyleBackColor = true;
            this->dcButton->Click += gcnew System::EventHandler(this, &homeForm::dcButton_Click);
            // 
            // bookButton
            // 
            this->bookButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->bookButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bookButton.BackgroundImage")));
            this->bookButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->bookButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->bookButton->Location = System::Drawing::Point(131, 433);
            this->bookButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->bookButton->Name = L"bookButton";
            this->bookButton->Size = System::Drawing::Size(192, 139);
            this->bookButton->TabIndex = 4;
            this->bookButton->UseVisualStyleBackColor = true;
            this->bookButton->Click += gcnew System::EventHandler(this, &homeForm::bookButton_Click);
            // 
            // animeButton
            // 
            this->animeButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->animeButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"animeButton.BackgroundImage")));
            this->animeButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->animeButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->animeButton->Location = System::Drawing::Point(712, 202);
            this->animeButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->animeButton->Name = L"animeButton";
            this->animeButton->Size = System::Drawing::Size(192, 139);
            this->animeButton->TabIndex = 5;
            this->animeButton->UseVisualStyleBackColor = true;
            this->animeButton->Click += gcnew System::EventHandler(this, &homeForm::button4_Click);
            // 
            // marvelButton
            // 
            this->marvelButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->marvelButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"marvelButton.BackgroundImage")));
            this->marvelButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->marvelButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->marvelButton->Location = System::Drawing::Point(426, 308);
            this->marvelButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->marvelButton->Name = L"marvelButton";
            this->marvelButton->Size = System::Drawing::Size(192, 139);
            this->marvelButton->TabIndex = 6;
            this->marvelButton->UseVisualStyleBackColor = true;
            this->marvelButton->Click += gcnew System::EventHandler(this, &homeForm::marvelButton_Click);
            // 
            // disneyButton
            // 
            this->disneyButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->disneyButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"disneyButton.BackgroundImage")));
            this->disneyButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->disneyButton->Cursor = System::Windows::Forms::Cursors::Hand;
            this->disneyButton->Location = System::Drawing::Point(131, 202);
            this->disneyButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->disneyButton->Name = L"disneyButton";
            this->disneyButton->Size = System::Drawing::Size(192, 139);
            this->disneyButton->TabIndex = 8;
            this->disneyButton->UseVisualStyleBackColor = true;
            this->disneyButton->Click += gcnew System::EventHandler(this, &homeForm::disneyButton_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(994, 12);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(62, 66);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 9;
            this->pictureBox1->TabStop = false;
            // 
            // prof
            // 
            this->prof->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->prof->AutoSize = true;
            this->prof->BackColor = System::Drawing::Color::Transparent;
            this->prof->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->prof->ForeColor = System::Drawing::Color::Thistle;
            this->prof->Location = System::Drawing::Point(894, 34);
            this->prof->Name = L"prof";
            this->prof->Size = System::Drawing::Size(103, 32);
            this->prof->TabIndex = 10;
            this->prof->Text = L"Profile";
            this->prof->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            // 
            // homeForm
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ClientSize = System::Drawing::Size(1080, 750);
            this->Controls->Add(this->prof);
            this->Controls->Add(this->pictureBox1);
            this->Controls->Add(this->disneyButton);
            this->Controls->Add(this->marvelButton);
            this->Controls->Add(this->animeButton);
            this->Controls->Add(this->bookButton);
            this->Controls->Add(this->dcButton);
            this->Controls->Add(this->appName);
            this->Controls->Add(this->logo);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->Name = L"homeForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Categories";
            this->TopMost = true;
            this->Load += gcnew System::EventHandler(this, &homeForm::Categories_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void Categories_Load(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
        Anime^ anime = gcnew Anime(this->user, this);
        anime->Show();
        this->Hide();
    }
    private: System::Void pictureBox1_Click_1(System::Object^ sender, System::EventArgs^ e) {
        // Create profileForm and pass the user
        profileForm^ profile = gcnew profileForm(this->user, this, this->loginFormInstance);
        profile->Show();
        this->Hide(); // Hide the current form
    }

    private: System::Void marvelButton_Click(System::Object^ sender, System::EventArgs^ e) {
        Marvel^ marvel = gcnew Marvel(this->user, this); // Pass the user to Marvel
        marvel->Show();
        this->Hide();
    }
    private: System::Void bookButton_Click(System::Object^ sender, System::EventArgs^ e) {
        Adaptations^ adapt = gcnew Adaptations(this->user, this);
        adapt->Show();
        this->Hide();
    }
    private: System::Void dcButton_Click(System::Object^ sender, System::EventArgs^ e) {
        DC^ dc = gcnew DC(this->user, this);
        dc->Show();
        this->Hide();
    }
    private: System::Void disneyButton_Click(System::Object^ sender, System::EventArgs^ e) {
        disney^ cartoon = gcnew disney(this->user, this);
        cartoon->Show();
        this->Hide();
    }
    };
}