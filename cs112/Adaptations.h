#pragma once
#include "marveldata.h"
#include "MovieDetailForm.h"
#include "users.h"

namespace cs112 {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Collections::Generic;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Data::OleDb;
    using namespace System::IO;
    using namespace System::Drawing::Imaging;

    public ref class Adaptations : public System::Windows::Forms::Form
    {
        User^ user; // Declare user variable
        Form^ homeForm;
    public:
        Adaptations(User^ user, Form^ Home)
        {
            InitializeComponent();
              this->user = user; // Store the user
            this->homeForm = Home;
            LoadMoviesFromExcel();
            CreateDynamicPanels();
        }

        ~Adaptations()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        List<Movie^>^ movies;

    private: System::Windows::Forms::PictureBox^ logo;
    private: System::Windows::Forms::PictureBox^ home;
    private: User^ currentUser;


           System::ComponentModel::Container^ components;

           void LoadMoviesFromExcel()
           {
               movies = gcnew List<Movie^>();
               String^ excelFilePath = "..\\data\\Movies.xlsx";

               if (!File::Exists(excelFilePath))
               {
                   MessageBox::Show("Excel file not found at: " + Path::GetFullPath(excelFilePath));
                   return;
               }

               String^ connString = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + excelFilePath +
                   ";Extended Properties=\"Excel 12.0 Xml;HDR=YES;IMEX=1\";";

               try
               {
                   OleDbConnection^ conn = gcnew OleDbConnection(connString);
                   conn->Open();

                   DataTable^ schemaTable = conn->GetOleDbSchemaTable(OleDbSchemaGuid::Tables, nullptr);

                   OleDbCommand^ cmd = gcnew OleDbCommand("SELECT * FROM [booksM$]", conn);
                   OleDbDataReader^ reader = cmd->ExecuteReader();

                   // Check if "showtimes" column exists
                   DataTable^ schema = reader->GetSchemaTable();
                   bool hasShowtimes = false;
                   for each (DataRow ^ row in schema->Rows)
                   {
                       String^ colName = row["ColumnName"]->ToString()->ToLower();
                       if (colName == "showtimes") hasShowtimes = true;
                   }

                   if (!hasShowtimes)
                   {
                       MessageBox::Show("Column 'showtimes' not found in the Excel sheet.");
                       conn->Close();
                       return;
                   }

                   while (reader->Read())
                   {
                       try
                       {
                           Movie^ movie = gcnew Movie();

                           // Read other fields
                           movie->name = reader->IsDBNull(reader->GetOrdinal("name")) ?
                               "Untitled" : reader["name"]->ToString();

                           movie->description = reader->IsDBNull(reader->GetOrdinal("description")) ?
                               "No description" : reader["description"]->ToString();

                           movie->rate = reader->IsDBNull(reader->GetOrdinal("rate")) ?
                               "Unrated" : reader["rate"]->ToString();


                           movie->imagePath = reader->IsDBNull(reader->GetOrdinal("imagePath")) ?
                               String::Empty : reader["imagePath"]->ToString();
                           movie->imagePath2 = reader->IsDBNull(reader->GetOrdinal("imagePath2")) ?
                               String::Empty : reader["imagePath2"]->ToString();
                           movie->imagePath3 = reader->IsDBNull(reader->GetOrdinal("imagePath3")) ?
                               String::Empty : reader["imagePath3"]->ToString();
                           movie->imagePath4 = reader->IsDBNull(reader->GetOrdinal("imagePath4")) ?
                               String::Empty : reader["imagePath4"]->ToString();
                           movie->imagePath5 = reader->IsDBNull(reader->GetOrdinal("imagePath5")) ?
                               String::Empty : reader["imagePath5"]->ToString();

                           movie->price = reader->IsDBNull(reader->GetOrdinal("price")) ?
                               0.0 : Convert::ToDouble(reader["price"]);

                           // Parse showtimes
                           movie->showtimes = gcnew List<String^>();
                           int showtimesColIndex = reader->GetOrdinal("showtimes");
                           if (!reader->IsDBNull(showtimesColIndex))
                           {
                               String^ rawShowtimes = reader->GetString(showtimesColIndex)->Trim();
                               if (!String::IsNullOrEmpty(rawShowtimes))
                               {
                                   array<String^>^ splitTimes = rawShowtimes->Split(
                                       gcnew array<wchar_t>{','},
                                       StringSplitOptions::RemoveEmptyEntries
                                   );

                                   for each (String ^ time in splitTimes)
                                   {
                                       String^ cleaned = time->Trim();
                                       movie->showtimes->Add(cleaned);
                                   }
                               }
                           }



                           movies->Add(movie);
                       }
                       catch (Exception^ ex)
                       {
                           MessageBox::Show("Error processing row: " + ex->Message);
                       }
                   }

                   conn->Close();
               }
               catch (Exception^ ex)
               {
                   MessageBox::Show("Excel Error: " + ex->Message +
                       "\nVerify:\n1. Columns: name, rate, description, imagePath, showtimes, price exist\n" +
                       "2. The Excel file is not open in another program.");
               }
           }

           void CreateDynamicPanels()
           {
               int panelWidth = 220;
               int panelHeight = 350;
               int spacing = 30;
               int panelsPerRow = 4;
               int startY = panel13->Bottom + spacing;
               int x = spacing, y = startY;

               for (int i = 0; i < movies->Count; i++)
               {
                   Panel^ panel = gcnew Panel();
                   panel->BackColor = Color::FromArgb(45, 48, 66);
                   panel->Size = System::Drawing::Size(panelWidth, panelHeight);
                   panel->Location = System::Drawing::Point(x, y);
                   panel->Padding = System::Windows::Forms::Padding(5);
                   panel->Tag = movies[i];  // Store movie reference
                   panel->Cursor = Cursors::Hand;

                   // Add click handler to the entire panel
                   panel->Click += gcnew System::EventHandler(this, &Adaptations::MoviePanel_Click);

                   PictureBox^ pictureBox = gcnew PictureBox();
                   pictureBox->Size = System::Drawing::Size(panelWidth - 5, (int)(panelHeight * 0.8));
                   pictureBox->Location = System::Drawing::Point(5, 5);
                   pictureBox->SizeMode = PictureBoxSizeMode::Zoom;
                   pictureBox->BackColor = Color::Transparent;
                   pictureBox->Cursor = Cursors::Hand;
                   pictureBox->Click += gcnew System::EventHandler(this, &Adaptations::MoviePanel_Click);

                   if (!String::IsNullOrEmpty(movies[i]->imagePath) && File::Exists(movies[i]->imagePath))
                   {
                       try {
                           pictureBox->Image = Image::FromFile(movies[i]->imagePath);
                       }
                       catch (...) {
                           pictureBox->Image = SystemIcons::Warning->ToBitmap();
                       }
                   }
                   else
                   {
                       pictureBox->Image = SystemIcons::Information->ToBitmap();
                   }

                   Panel^ labelPanel = gcnew Panel();
                   labelPanel->Dock = DockStyle::Bottom;
                   labelPanel->Height = static_cast<int>(panelHeight * 0.2);
                   labelPanel->BackColor = Color::FromArgb(60, 63, 81);
                   labelPanel->Cursor = Cursors::Hand;
                   labelPanel->Click += gcnew System::EventHandler(this, &Adaptations::MoviePanel_Click);

                   Label^ label = gcnew Label();
                   label->Dock = DockStyle::Fill;
                   label->ForeColor = Color::White;
                   label->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);
                   label->TextAlign = ContentAlignment::MiddleCenter;
                   label->AutoSize = false;
                   label->MaximumSize = System::Drawing::Size(panelWidth - 20, 0);
                   label->Text = movies[i]->name;
                   label->Cursor = Cursors::Hand;
                   label->Click += gcnew System::EventHandler(this, &Adaptations::MoviePanel_Click);
                   label->MouseEnter += gcnew System::EventHandler(this, &Adaptations::MovieLabel_MouseEnter);
                   label->MouseLeave += gcnew System::EventHandler(this, &Adaptations::MovieLabel_MouseLeave);

                   labelPanel->Controls->Add(label);
                   panel->Controls->Add(pictureBox);
                   panel->Controls->Add(labelPanel);
                   this->Controls->Add(panel);

                   x += panelWidth + spacing;
                   if ((i + 1) % panelsPerRow == 0)
                   {
                       x = spacing;
                       y += panelHeight + spacing;
                   }
               }
           }

           void MoviePanel_Click(System::Object^ sender, System::EventArgs^ e)
           {
               Control^ clickedControl = dynamic_cast<Control^>(sender);
               Movie^ selectedMovie = nullptr;

               if (clickedControl->GetType() == Panel::typeid)
               {
                   selectedMovie = dynamic_cast<Movie^>(clickedControl->Tag);
               }
               else
               {
                   Control^ parent = clickedControl->Parent;
                   while (parent != nullptr && parent->GetType() != Panel::typeid)
                   {
                       parent = parent->Parent;
                   }
                   if (parent != nullptr)
                   {
                       selectedMovie = dynamic_cast<Movie^>(parent->Tag);
                   }
               }

               if (selectedMovie != nullptr)
               {
                   // Create and show detail form
                   MovieDetailForm^ detailForm = gcnew MovieDetailForm(selectedMovie,this->user);
                   detailForm->Show();
               }
           }

           void MovieLabel_MouseEnter(System::Object^ sender, System::EventArgs^ e)
           {
               Label^ label = dynamic_cast<Label^>(sender);
               if (label != nullptr)
                   label->ForeColor = Color::LightBlue;
           }

           void MovieLabel_MouseLeave(System::Object^ sender, System::EventArgs^ e)
           {
               Label^ label = dynamic_cast<Label^>(sender);
               if (label != nullptr)
                   label->ForeColor = Color::White;
           }

#pragma region Windows Form Designer generated code
           void InitializeComponent(void)
           {
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Adaptations::typeid));
               this->panel13 = (gcnew System::Windows::Forms::Panel());
               this->home = (gcnew System::Windows::Forms::PictureBox());
               this->logo = (gcnew System::Windows::Forms::PictureBox());
               this->label1 = (gcnew System::Windows::Forms::Label());
               this->panel13->SuspendLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->home))->BeginInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->BeginInit();
               this->SuspendLayout();
               // 
               // panel13
               // 
               this->panel13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(48)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                   static_cast<System::Int32>(static_cast<System::Byte>(74)));
               this->panel13->Controls->Add(this->home);
               this->panel13->Controls->Add(this->logo);
               this->panel13->Controls->Add(this->label1);
               this->panel13->Location = System::Drawing::Point(0, -3);
               this->panel13->Name = L"panel13";
               this->panel13->Size = System::Drawing::Size(1067, 106);
               this->panel13->TabIndex = 0;
               // 
               // home
               // 
               this->home->Cursor = System::Windows::Forms::Cursors::Hand;
               this->home->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"home.Image")));
               this->home->Location = System::Drawing::Point(968, 15);
               this->home->Name = L"home";
               this->home->Size = System::Drawing::Size(80, 80);
               this->home->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
               this->home->TabIndex = 3;
               this->home->TabStop = false;
               this->home->Click += gcnew System::EventHandler(this, &Adaptations::home_Click);
               // 
               // logo
               // 
               this->logo->BackColor = System::Drawing::Color::Transparent;
               this->logo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.BackgroundImage")));
               this->logo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->logo->Location = System::Drawing::Point(0, 1);
               this->logo->Name = L"logo";
               this->logo->Size = System::Drawing::Size(106, 102);
               this->logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
               this->logo->TabIndex = 2;
               this->logo->TabStop = false;
               // 
               // label1
               // 
               this->label1->AutoSize = true;
               this->label1->Font = (gcnew System::Drawing::Font(L"Viner Hand ITC", 28.2F));
               this->label1->ForeColor = System::Drawing::Color::Thistle;
               this->label1->Location = System::Drawing::Point(112, 30);
               this->label1->Name = L"label1";
               this->label1->Size = System::Drawing::Size(240, 76);
               this->label1->TabIndex = 1;
               this->label1->Text = L"CineVerse";
               // 
               // Adaptations
               // 
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
               this->AutoScroll = true;
               this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(37)),
                   static_cast<System::Int32>(static_cast<System::Byte>(56)));
               this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
               this->ClientSize = System::Drawing::Size(1062, 850);
               this->Controls->Add(this->panel13);
               this->Name = L"Adaptations";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
               this->Text = L"Mainform";
               this->panel13->ResumeLayout(false);
               this->panel13->PerformLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->home))->EndInit();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->EndInit();
               this->ResumeLayout(false);

           }
#pragma endregion

    private:
        System::Windows::Forms::Panel^ panel13;
        System::Windows::Forms::Label^ label1;
    private: System::Void home_Click(System::Object^ sender, System::EventArgs^ e) {
        this->Hide();
        homeForm->Show();
    }
};
}