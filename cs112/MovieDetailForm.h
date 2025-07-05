
#pragma once

#include "marveldata.h"
#include "users.h"

namespace cs112 {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::IO;
    using namespace System::Data::OleDb;

    public ref class MovieDetailForm : public Form {
        User^ user;
    public:
        MovieDetailForm(Movie^ movie, User^ user) {
            InitializeComponent();
            this->user = user;
            LoadMovieData(movie);
        }

    private:
        PictureBox^ pictureBox;   // Main movie image (imagePath2)
        PictureBox^ pictureBox1;  // Second movie image (imagePath)
        PictureBox^ pictureBox2; // Third movie image (imagePath3)
        PictureBox^ pictureBox3; // Fourth movie image (imagePath4)
        PictureBox^ pictureBox4; // Fifth movie image (imagePath5)
        PictureBox^ logo;         // Logo (pictureBox2 in movieBooking)
        PictureBox^ pictureBoxIMDb; // IMDb icon
        Label^ lblTitle;          // Movie name (labelMovieName)
        Label^ lblRating;         // Rating (labelStars)
        Label^ label2;            // CinVerse label
        Label^ txtDescription;    // Description label (matches label8)
        Button^ btnBook;          // Book Seat button
        Button^ btnCancel;        // Cancel button
        Label^ lblPrice;          // Price label
        Panel^ seatPanel;         // Seats panel
        Label^ lblDescription;    // Description label
        Label^ lblShowtimes;      // Showtimes label
        Label^ lblSeats;          // Seats label
        array<Button^, 2>^ seatButtons; // Seat buttons (3x5 grid)
        String^ selectedShowtime;
        String^ selectedMovieName;
        RadioButton^ radioButton1; // Showtime 1
        RadioButton^ radioButton2; // Showtime 2
        RadioButton^ radioButton3; // Showtime 3
        RadioButton^ radioButton4; // Showtime 4

        // Mouse Enter event for buttons
        System::Void Button_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
            Button^ btn = safe_cast<Button^>(sender);
            btn->Cursor = Cursors::Hand;
        }

        // Mouse Leave event for buttons
        System::Void Button_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
            Button^ btn = safe_cast<Button^>(sender);
            btn->Cursor = Cursors::Default;
        }

        // Mouse Enter event for radio buttons
        System::Void RadioButton_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
            RadioButton^ rb = safe_cast<RadioButton^>(sender);
            rb->Cursor = Cursors::Hand;
        }

        // Mouse Leave event for radio buttons
        System::Void RadioButton_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
            RadioButton^ rb = safe_cast<RadioButton^>(sender);
            rb->Cursor = Cursors::Default;
        }

        void InitializeComponent() {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MovieDetailForm::typeid));
            this->SuspendLayout();

            // Form setup (matching movieBooking)
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoScroll = true;
            this->BackColor = System::Drawing::Color::FromArgb(19, 35, 77);
            //this->ClientSize = System::Drawing::Size(1920, 1200);
            this->Name = L"MovieDetailForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Movie Details";
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;

            // logo (pictureBox2)
            logo = gcnew PictureBox();
            logo->BackColor = System::Drawing::Color::FromArgb(19, 35, 77);
            LoadImageToPictureBox(logo, L"../pics/logo.png");
            logo->Location = System::Drawing::Point(17, 12);
            logo->Name = L"logo";
            logo->Size = System::Drawing::Size(115, 89);
            logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            logo->TabIndex = 1;
            logo->TabStop = false;

            // label2 (CinVerse)
            label2 = gcnew Label();
            label2->Font = gcnew System::Drawing::Font(L"Viner Hand ITC", 25.8F);
            label2->ForeColor = System::Drawing::Color::Thistle;
            label2->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
            label2->Location = System::Drawing::Point(138, 31);
            label2->Name = L"label2";
            label2->Size = System::Drawing::Size(250, 100);
            label2->TabIndex = 4;
            label2->Text = L"CineVerse";
            label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;

            // lblTitle (labelMovieName)
            lblTitle = gcnew Label();
            lblTitle->Font = gcnew System::Drawing::Font(L"Georgia", 32, System::Drawing::FontStyle::Bold);
            lblTitle->ForeColor = System::Drawing::Color::FromArgb(175, 228, 252);
            lblTitle->Location = System::Drawing::Point(1, 564);
            lblTitle->Name = L"lblTitle";
            lblTitle->Size = System::Drawing::Size(1085, 110);
            lblTitle->TabIndex = 5;
            lblTitle->Text = L"Movie Title";
            lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

            // lblRating (labelStars)
            lblRating = gcnew Label();
            lblRating->Font = gcnew System::Drawing::Font(L"Segoe UI Emoji", 31.8F);
            lblRating->ForeColor = System::Drawing::Color::Gold;
            lblRating->Location = System::Drawing::Point(378, 649);
            lblRating->Name = L"lblRating";
            lblRating->Size = System::Drawing::Size(268, 64);
            lblRating->TabIndex = 8;
            lblRating->Text = L"★★★★☆";
            lblRating->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;

            // pictureBox (matches pictureBox1)
            pictureBox = gcnew PictureBox();
            pictureBox->BackColor = System::Drawing::SystemColors::ActiveCaption;
            pictureBox->Location = System::Drawing::Point(439, 147);
            pictureBox->Name = L"pictureBox";
            pictureBox->Size = System::Drawing::Size(183, 286);
            pictureBox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            pictureBox->TabIndex = 7;
            pictureBox->TabStop = false;

            // pictureBox1 (matches pictureBox6)
            pictureBox1 = gcnew PictureBox();
            pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
            pictureBox1->Location = System::Drawing::Point(61, 134);
            pictureBox1->Name = L"pictureBox1";
            pictureBox1->Size = System::Drawing::Size(183, 286);
            pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            pictureBox1->TabIndex = 12;
            pictureBox1->TabStop = false;

            // pictureBox2 (matches pictureBox3)
            pictureBox2 = gcnew PictureBox();
            pictureBox2->BackColor = System::Drawing::SystemColors::ActiveCaption;
            pictureBox2->Location = System::Drawing::Point(250, 279);
            pictureBox2->Name = L"pictureBox2";
            pictureBox2->Size = System::Drawing::Size(183, 282);
            pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            pictureBox2->TabIndex = 9;
            pictureBox2->TabStop = false;

            // pictureBox3 (matches pictureBox5)
            pictureBox3 = gcnew PictureBox();
            pictureBox3->BackColor = System::Drawing::SystemColors::ActiveCaption;
            pictureBox3->Location = System::Drawing::Point(628, 279);
            pictureBox3->Name = L"pictureBox3";
            pictureBox3->Size = System::Drawing::Size(183, 282);
            pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            pictureBox3->TabIndex = 11;
            pictureBox3->TabStop = false;

            // pictureBox4 (matches pictureBox4)
            pictureBox4 = gcnew PictureBox();
            pictureBox4->BackColor = System::Drawing::SystemColors::ActiveCaption;
            pictureBox4->Location = System::Drawing::Point(817, 134);
            pictureBox4->Name = L"pictureBox4";
            pictureBox4->Size = System::Drawing::Size(183, 286);
            pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            pictureBox4->TabIndex = 10;
            pictureBox4->TabStop = false;

            // pictureBoxIMDb (matches pictureBox7)
            pictureBoxIMDb = gcnew PictureBox();
            LoadImageToPictureBox(pictureBoxIMDb, L"../pics/imdb.png");
            pictureBoxIMDb->Location = System::Drawing::Point(620, 671);
            pictureBoxIMDb->Name = L"pictureBoxIMDb";
            pictureBoxIMDb->Size = System::Drawing::Size(113, 45);
            pictureBoxIMDb->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            pictureBoxIMDb->TabIndex = 13;
            pictureBoxIMDb->TabStop = false;

            // lblDescription (matches label1)
            lblDescription = gcnew Label();
            lblDescription->AutoSize = true;
            lblDescription->Font = gcnew System::Drawing::Font(L"Georgia", 28.2F, System::Drawing::FontStyle::Bold);
            lblDescription->ForeColor = System::Drawing::Color::FromArgb(175, 228, 252);
            lblDescription->Location = System::Drawing::Point(1338, 111);
            lblDescription->Name = L"lblDescription";
            lblDescription->Size = System::Drawing::Size(308, 54);
            lblDescription->TabIndex = 14;
            lblDescription->Text = L"Description";
            lblDescription->UseMnemonic = false;

            // txtDescription (matches label8)
            txtDescription = gcnew Label();
            txtDescription->Font = gcnew System::Drawing::Font(L"Georgia", 13.8F, System::Drawing::FontStyle::Bold);
            txtDescription->ForeColor = System::Drawing::Color::White;
            txtDescription->Location = System::Drawing::Point(1141, 174);
            txtDescription->Name = L"txtDescription";
            txtDescription->Size = System::Drawing::Size(764, 162);
            txtDescription->TabIndex = 29;
            txtDescription->Text = L"Description text goes here";

            // lblShowtimes (matches label4)
            lblShowtimes = gcnew Label();
            lblShowtimes->AutoSize = true;
            lblShowtimes->Font = gcnew System::Drawing::Font(L"Georgia", 28.2F, System::Drawing::FontStyle::Bold);
            lblShowtimes->ForeColor = System::Drawing::Color::FromArgb(175, 228, 252);
            lblShowtimes->Location = System::Drawing::Point(1340, 400);
            lblShowtimes->Name = L"lblShowtimes";
            lblShowtimes->Size = System::Drawing::Size(292, 54);
            lblShowtimes->TabIndex = 16;
            lblShowtimes->Text = L"Showtimes";
            lblShowtimes->UseMnemonic = false;

            // radioButton1 (matches radioButton1)
            radioButton1 = gcnew RadioButton();
            radioButton1->AutoSize = true;
            radioButton1->Font = gcnew System::Drawing::Font(L"Times New Roman", 16.2F);
            radioButton1->ForeColor = System::Drawing::Color::White;
            radioButton1->Location = System::Drawing::Point(1147, 480);
            radioButton1->Name = L"radioButton1";
            radioButton1->Size = System::Drawing::Size(247, 37);
            radioButton1->TabIndex = 18;
            radioButton1->Text = L"Showtime 1";
            radioButton1->UseVisualStyleBackColor = true;
            radioButton1->CheckedChanged += gcnew System::EventHandler(this, &MovieDetailForm::ShowtimeRadioButton_CheckedChanged);
            radioButton1->MouseEnter += gcnew System::EventHandler(this, &MovieDetailForm::RadioButton_MouseEnter);
            radioButton1->MouseLeave += gcnew System::EventHandler(this, &MovieDetailForm::RadioButton_MouseLeave);

            // radioButton2 (matches radioButton2)
            radioButton2 = gcnew RadioButton();
            radioButton2->AutoSize = true;
            radioButton2->Font = gcnew System::Drawing::Font(L"Times New Roman", 16.2F);
            radioButton2->ForeColor = System::Drawing::Color::White;
            radioButton2->Location = System::Drawing::Point(1589, 480);
            radioButton2->Name = L"radioButton2";
            radioButton2->Size = System::Drawing::Size(264, 37);
            radioButton2->TabIndex = 19;
            radioButton2->Text = L"Showtime 2";
            radioButton2->UseVisualStyleBackColor = true;
            radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MovieDetailForm::ShowtimeRadioButton_CheckedChanged);
            radioButton2->MouseEnter += gcnew System::EventHandler(this, &MovieDetailForm::RadioButton_MouseEnter);
            radioButton2->MouseLeave += gcnew System::EventHandler(this, &MovieDetailForm::RadioButton_MouseLeave);

            // radioButton3 (matches radioButton3)
            radioButton3 = gcnew RadioButton();
            radioButton3->AutoSize = true;
            radioButton3->Font = gcnew System::Drawing::Font(L"Times New Roman", 16.2F);
            radioButton3->ForeColor = System::Drawing::Color::White;
            radioButton3->Location = System::Drawing::Point(1146, 527);
            radioButton3->Name = L"radioButton3";
            radioButton3->Size = System::Drawing::Size(295, 37);
            radioButton3->TabIndex = 20;
            radioButton3->Text = L"Showtime 3";
            radioButton3->UseVisualStyleBackColor = true;
            radioButton3->CheckedChanged += gcnew System::EventHandler(this, &MovieDetailForm::ShowtimeRadioButton_CheckedChanged);
            radioButton3->MouseEnter += gcnew System::EventHandler(this, &MovieDetailForm::RadioButton_MouseEnter);
            radioButton3->MouseLeave += gcnew System::EventHandler(this, &MovieDetailForm::RadioButton_MouseLeave);

            // radioButton4 (matches radioButton4)
            radioButton4 = gcnew RadioButton();
            radioButton4->AutoSize = true;
            radioButton4->Font = gcnew System::Drawing::Font(L"Times New Roman", 16.2F);
            radioButton4->ForeColor = System::Drawing::Color::White;
            radioButton4->Location = System::Drawing::Point(1589, 527);
            radioButton4->Name = L"radioButton4";
            radioButton4->Size = System::Drawing::Size(321, 37);
            radioButton4->TabIndex = 21;
            radioButton4->Text = L"Showtime 4";
            radioButton4->UseVisualStyleBackColor = true;
            radioButton4->CheckedChanged += gcnew System::EventHandler(this, &MovieDetailForm::ShowtimeRadioButton_CheckedChanged);
            radioButton4->MouseEnter += gcnew System::EventHandler(this, &MovieDetailForm::RadioButton_MouseEnter);
            radioButton4->MouseLeave += gcnew System::EventHandler(this, &MovieDetailForm::RadioButton_MouseLeave);

            // lblSeats (matches label5)
            lblSeats = gcnew Label();
            lblSeats->AutoSize = true;
            lblSeats->Font = gcnew System::Drawing::Font(L"Georgia", 28.2F, System::Drawing::FontStyle::Bold);
            lblSeats->ForeColor = System::Drawing::Color::FromArgb(175, 228, 252);
            lblSeats->Location = System::Drawing::Point(1340, 621);
            lblSeats->Name = L"lblSeats";
            lblSeats->Size = System::Drawing::Size(302, 54);
            lblSeats->TabIndex = 22;
            lblSeats->Text = L"Your Seats!";
            lblSeats->UseMnemonic = false;

            // seatPanel (matches panelSeats)
            seatPanel = gcnew Panel();
            seatPanel->BackColor = System::Drawing::Color::Transparent;
            seatPanel->Location = System::Drawing::Point(1342, 679);
            seatPanel->Name = L"seatPanel";
            seatPanel->Size = System::Drawing::Size(420, 296);
            seatPanel->TabIndex = 27;

            // btnBook (matches buttonBook)
            btnBook = gcnew Button();
            btnBook->BackColor = System::Drawing::Color::FromArgb(109, 18, 36);
            btnBook->Font = gcnew System::Drawing::Font(L"Georgia", 25.8F, System::Drawing::FontStyle::Bold);
            btnBook->ForeColor = System::Drawing::Color::White;
            btnBook->Location = System::Drawing::Point(342, 739);
            btnBook->Name = L"btnBook";
            btnBook->Size = System::Drawing::Size(428, 80); // Height reduced from 105 to 80
            btnBook->TabIndex = 28;
            btnBook->Text = L"Book Seat";
            btnBook->UseVisualStyleBackColor = false;
            btnBook->Click += gcnew EventHandler(this, &MovieDetailForm::buttonBook_Click);
            btnBook->MouseEnter += gcnew System::EventHandler(this, &MovieDetailForm::Button_MouseEnter);
            btnBook->MouseLeave += gcnew System::EventHandler(this, &MovieDetailForm::Button_MouseLeave);

            // btnCancel
            btnCancel = gcnew Button();
            btnCancel->BackColor = System::Drawing::Color::FromArgb(109, 18, 36);
            btnCancel->Font = gcnew System::Drawing::Font(L"Georgia", 25.8F, System::Drawing::FontStyle::Bold);
            btnCancel->ForeColor = System::Drawing::Color::White;
            btnCancel->Location = System::Drawing::Point(342, 827); // Below btnBook (739 + 80 + 8)
            btnCancel->Name = L"btnCancel";
            btnCancel->Size = System::Drawing::Size(428, 80); // Height reduced from 105 to 80
            btnCancel->TabIndex = 29;
            btnCancel->Text = L"Cancel";
            btnCancel->UseVisualStyleBackColor = false;
            btnCancel->Click += gcnew EventHandler(this, &MovieDetailForm::buttonCancel_Click);
            btnCancel->MouseEnter += gcnew System::EventHandler(this, &MovieDetailForm::Button_MouseEnter);
            btnCancel->MouseLeave += gcnew System::EventHandler(this, &MovieDetailForm::Button_MouseLeave);

            // lblPrice (matches Price, positioned below btnCancel)
            lblPrice = gcnew Label();
            lblPrice->AutoSize = true;
            lblPrice->Font = gcnew System::Drawing::Font(L"Georgia", 22.2F, System::Drawing::FontStyle::Bold);
            lblPrice->ForeColor = System::Drawing::Color::White;
            lblPrice->Location = System::Drawing::Point(450, 915); // Below btnCancel (827 + 80 + 8)
            lblPrice->Name = L"lblPrice";
            lblPrice->Size = System::Drawing::Size(142, 43);
            lblPrice->TabIndex = 30;
            lblPrice->Text = L"Price: N/A";

            // Initialize seat buttons
            InitializeSeatButtons();

            // Add controls to form
            this->Controls->Add(lblPrice);
            this->Controls->Add(btnCancel);
            this->Controls->Add(btnBook);
            this->Controls->Add(seatPanel);
            this->Controls->Add(lblSeats);
            this->Controls->Add(radioButton4);
            this->Controls->Add(radioButton3);
            this->Controls->Add(radioButton2);
            this->Controls->Add(radioButton1);
            this->Controls->Add(lblShowtimes);
            this->Controls->Add(txtDescription);
            this->Controls->Add(lblDescription);
            this->Controls->Add(pictureBoxIMDb);
            this->Controls->Add(pictureBox4);
            this->Controls->Add(pictureBox3);
            this->Controls->Add(pictureBox2);
            this->Controls->Add(pictureBox1);
            this->Controls->Add(pictureBox);
            this->Controls->Add(lblRating);
            this->Controls->Add(lblTitle);
            this->Controls->Add(logo);
            this->Controls->Add(label2);

            this->ResumeLayout(false);
            this->PerformLayout();
        }

        void InitializeSeatButtons() {
            seatButtons = gcnew array<Button^, 2>(3, 5);
            int seatNumber = 1;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 5; j++) {
                    Button^ seat = gcnew Button();
                    seat->Size = Drawing::Size(60, 60); // Increased from 50, 50
                    seat->Location = Drawing::Point(j * 70, i * 70); // Increased spacing from 60
                    seat->BackColor = Color::FromArgb(45, 119, 57);
                    seat->ForeColor = Color::White;
                    seat->Font = gcnew Drawing::Font(L"Arial", 15, FontStyle::Bold);
                    seat->Text = seatNumber.ToString();
                    seat->FlatStyle = FlatStyle::Flat;
                    seat->FlatAppearance->BorderSize = 2;
                    seat->FlatAppearance->BorderColor = Color::White;
                    seat->Click += gcnew EventHandler(this, &MovieDetailForm::seatButton_Click);
                    seat->MouseEnter += gcnew System::EventHandler(this, &MovieDetailForm::Button_MouseEnter);
                    seat->MouseLeave += gcnew System::EventHandler(this, &MovieDetailForm::Button_MouseLeave);
                    seatPanel->Controls->Add(seat);
                    seatButtons[i, j] = seat;
                    seatNumber++;
                }
            }
        }

        void LoadMovieData(Movie^ movie) {
            if (movie == nullptr) return;
            this->Text = movie->name;
            lblTitle->Text = movie->name;
            lblRating->Text = String::Format(movie->rate);
            txtDescription->Text = movie->description;
            lblPrice->Text = String::Format(L"Price: {0}", movie->price);
            selectedMovieName = movie->name;

            // Load images from Excel-extracted paths
            LoadImageToPictureBox(pictureBox, movie->imagePath2);
            LoadImageToPictureBox(pictureBox1, movie->imagePath);
            LoadImageToPictureBox(pictureBox2, movie->imagePath3);
            LoadImageToPictureBox(pictureBox3, movie->imagePath4);
            LoadImageToPictureBox(pictureBox4, movie->imagePath5);

            // Populate showtimes
            array<String^>^ showtimes = movie->showtimes->ToArray(); // Convert List<String^> to array<String^>
            int maxShowtimes = Math::Min(showtimes->Length, 4);
            array<RadioButton^>^ radioButtons = { radioButton1, radioButton2, radioButton3, radioButton4 };
            for (int i = 0; i < 4; i++) {
                if (i < maxShowtimes) {
                    radioButtons[i]->Text = showtimes[i];
                    radioButtons[i]->Visible = true;
                }
                else {
                    radioButtons[i]->Text = L"";
                    radioButtons[i]->Visible = false;
                }
            }
        }

        void ShowtimeRadioButton_CheckedChanged(Object^ sender, EventArgs^ e) {
            RadioButton^ rb = safe_cast<RadioButton^>(sender);
            if (rb->Checked) {
                selectedShowtime = rb->Text;
                rb->BackColor = Color::FromArgb(19, 35, 77);
                rb->FlatAppearance->BorderColor = Color::Gold;
                array<RadioButton^>^ radioButtons = { radioButton1, radioButton2, radioButton3, radioButton4 };
                for each (RadioButton ^ otherRb in radioButtons) {
                    if (otherRb != rb) {
                        otherRb->BackColor = Color::FromArgb(19, 35, 77);
                        otherRb->FlatAppearance->BorderColor = Color::FromArgb(19, 35, 77);
                    }
                }
                LoadBookedSeatsFromExcel();
            }
        }

        void LoadImageToPictureBox(PictureBox^ pictureBox, String^ imagePath) {
            try {
                if (!String::IsNullOrEmpty(imagePath) && File::Exists(imagePath)) {
                    pictureBox->Image = Image::FromFile(imagePath);
                    pictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
                }
                else {
                    MessageBox::Show(String::Format(L"File not found: {0}", imagePath), L"Image Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                    pictureBox->Image = nullptr;
                }
            }
            catch (Exception^ ex) {
                MessageBox::Show(String::Format(L"Error loading image: {0}\nPath: {1}", ex->Message, imagePath), L"Image Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                pictureBox->Image = SystemIcons::Error->ToBitmap();
            }
        }

        void seatButton_Click(Object^ sender, EventArgs^ e) {
            Button^ clickedButton = dynamic_cast<Button^>(sender);
            if (clickedButton->BackColor == Color::FromArgb(45, 119, 57)) {
                clickedButton->BackColor = Color::FromArgb(165, 50, 69);
                clickedButton->FlatAppearance->BorderColor = Color::Gold;
            }
            else if (clickedButton->BackColor == Color::FromArgb(165, 50, 69)) {
                clickedButton->BackColor = Color::FromArgb(45, 119, 57);
                clickedButton->FlatAppearance->BorderColor = Color::White;
            }
            else if (clickedButton->BackColor == Color::FromArgb(50, 50, 50) && clickedButton->Tag->ToString() == L"CurrentUser   ") {
                clickedButton->BackColor = Color::FromArgb(165, 50, 69);
                clickedButton->FlatAppearance->BorderColor = Color::Gold;
            }
            else if (clickedButton->BackColor == Color::FromArgb(50, 50, 50)) {
                MessageBox::Show(L"This seat is already booked by another user.", L"Info", MessageBoxButtons::OK, MessageBoxIcon::Information);
            }
        }

        void buttonBook_Click(Object^ sender, EventArgs^ e) {
            if (String::IsNullOrEmpty(selectedShowtime)) {
                MessageBox::Show(L"Please select a showtime.", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            bool anySeatSelected = false;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 5; j++) {
                    if (seatButtons[i, j]->BackColor == Color::FromArgb(165, 50, 69)) {
                        anySeatSelected = true;
                        if (seatButtons[i, j]->Tag != nullptr && seatButtons[i, j]->Tag->ToString() == L"CurrentUser   ") {
                            MessageBox::Show(L"Seat " + seatButtons[i, j]->Text + L" is already booked by you.", L"Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                            seatButtons[i, j]->BackColor = Color::FromArgb(50, 50, 50);
                            seatButtons[i, j]->FlatAppearance->BorderColor = Color::Gray;
                            return;
                        }
                    }
                }
            }
            if (!anySeatSelected) {
                MessageBox::Show(L"Please select at least one seat.", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            SaveBookingToExcel();
        }

        void buttonCancel_Click(Object^ sender, EventArgs^ e) {
            if (String::IsNullOrEmpty(selectedShowtime) || String::IsNullOrEmpty(selectedMovieName)) {
                MessageBox::Show(L"Please select a showtime and movie.", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            Button^ selectedSeat = nullptr;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 5; j++) {
                    if (seatButtons[i, j]->BackColor == Color::FromArgb(165, 50, 69)) {
                        selectedSeat = seatButtons[i, j];
                        break;
                    }
                }
                if (selectedSeat != nullptr) break;
            }
            if (selectedSeat == nullptr) {
                MessageBox::Show(L"Please select a booked seat to cancel.", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            if (MessageBox::Show(L"Are you sure you want to cancel this booking?", L"Confirm Cancellation", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
                CancelBooking(selectedSeat->Text);
            }
        }

        void SaveBookingToExcel() {
            String^ excelFilePath = L"..\\data\\Booking.xlsx";
            String^ connectionString = L"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + excelFilePath + L";Extended Properties='Excel 12.0 Xml;HDR=YES;'";

            try {
                OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
                connection->Open();

                String^ priceText = lblPrice->Text->Replace(L"Price: ", L"");
                double seatPrice = Convert::ToDouble(priceText);
                int bookedSeats = 0;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 5; j++) {
                        if (seatButtons[i, j]->BackColor == Color::FromArgb(165, 50, 69)) {
                            if (seatButtons[i, j]->Tag != nullptr && seatButtons[i, j]->Tag->ToString() == L"CurrentUser   ") {
                                continue;
                            }
                            String^ seat = seatButtons[i, j]->Text;
                            String^ query = String::Format(
                                L"INSERT INTO [Sheet1$] (Showtime, Seat, [Movie Name], Price, [username], Status) VALUES ('{0}', '{1}', '{2}', '{3}', '{4}', 'Booked')",
                                selectedShowtime->Replace(L"'", L"''"),
                                seat->Replace(L"'", L"''"),
                                selectedMovieName->Replace(L"'", L"''"),
                                priceText->Replace(L"'", L"''"),
                                user->username->Replace(L"'", L"''"));

                            OleDbCommand^ command = gcnew OleDbCommand(query, connection);
                            command->ExecuteNonQuery();
                            bookedSeats++;
                        }
                    }
                }

                connection->Close();

                double totalPrice = bookedSeats * seatPrice;
                String^ message = String::Format(L"Booking successful!\nSeats booked: {0}\nTotal price: ${1:F2}", bookedSeats, totalPrice);
                MessageBox::Show(message, L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

                LoadBookedSeatsFromExcel();
            }
            catch (Exception^ ex) {
                MessageBox::Show(L"Error saving booking: " + ex->Message, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }


        void CancelBooking(String^ seatNumber) {
            String^ excelFilePath = L"..\\data\\Booking.xlsx";
            String^ connectionString = L"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + excelFilePath + L";Extended Properties='Excel 12.0 Xml;HDR=YES;'";
            try {
                OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
                connection->Open();
                String^ query = String::Format(
                    L"UPDATE [Sheet1$] SET Status = 'Cancelled' WHERE Showtime = '{0}' AND [Movie Name] = '{1}' AND Seat = '{2}' AND [username] = '{3}' AND Status = 'Booked'",
                    selectedShowtime->Replace(L"'", L"''"),
                    selectedMovieName->Replace(L"'", L"''"),
                    seatNumber->Replace(L"'", L"''"),
                    user->username->Replace(L"'", L"''"));
                OleDbCommand^ command = gcnew OleDbCommand(query, connection);
                int rowsAffected = command->ExecuteNonQuery();
                if (rowsAffected > 0) {
                    MessageBox::Show(L"Booking cancelled successfully!", L"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
                    LoadBookedSeatsFromExcel();
                }
                else {
                    MessageBox::Show(L"No matching booking found or already cancelled.", L"Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                }
                connection->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show(L"Error cancelling booking: " + ex->Message, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }

        void LoadBookedSeatsFromExcel() {
            if (String::IsNullOrEmpty(selectedShowtime) || String::IsNullOrEmpty(selectedMovieName)) return;
            String^ excelFilePath = L"..\\data\\Booking.xlsx";
            String^ connectionString = L"Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + excelFilePath + L";Extended Properties='Excel 12.0 Xml;HDR=YES;'";
            try {
                OleDbConnection^ connection = gcnew OleDbConnection(connectionString);
                connection->Open();
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 5; j++) {
                        seatButtons[i, j]->BackColor = Color::FromArgb(45, 119, 57);
                        seatButtons[i, j]->Enabled = true;
                        seatButtons[i, j]->FlatAppearance->BorderColor = Color::White;
                        seatButtons[i, j]->Tag = nullptr;
                    }
                }
                String^ query = String::Format(
                    L"SELECT Seat, [username] FROM [Sheet1$] WHERE Showtime = '{0}' AND [Movie Name] = '{1}' AND Status = 'Booked'",
                    selectedShowtime->Replace(L"'", L"''"),
                    selectedMovieName->Replace(L"'", L"''"));
                OleDbCommand^ command = gcnew OleDbCommand(query, connection);
                OleDbDataReader^ reader = command->ExecuteReader();
                while (reader->Read()) {
                    String^ seat = reader[L"Seat"]->ToString();
                    String^ bookedBy = reader[L"username"]->ToString();
                    for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 5; j++) {
                            if (seatButtons[i, j]->Text == seat) {
                                seatButtons[i, j]->BackColor = Color::FromArgb(50, 50, 50);
                                seatButtons[i, j]->FlatAppearance->BorderColor = Color::Gray;
                                seatButtons[i, j]->Enabled = true;
                                seatButtons[i, j]->Tag = (bookedBy == user->username) ? L"CurrentUser   " : L"OtherUser   ";
                            }
                        }
                    }
                }
                reader->Close();
                connection->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show(L"Error loading booked seats: " + ex->Message, L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    };
}
