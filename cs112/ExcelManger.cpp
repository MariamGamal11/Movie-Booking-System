#include "ExcelManger.h"

using namespace System;
using namespace System::Data;
using namespace System::Data::OleDb;
using namespace System::Runtime::InteropServices;
using namespace System::Windows::Forms;

// convert from managed string (.NET Framework) to unmanaged (standard c++ string)
std::string ExcelManager::MarshalString(System::String^ str)
{
    IntPtr ptr = Marshal::StringToHGlobalAnsi(str);
    std::string result = static_cast<char*>(ptr.ToPointer());
    Marshal::FreeHGlobal(ptr);
    return result;
}

std::vector<Booking> ExcelManager::GetBookingsForUser(System::String^ username)
{
    std::vector<Booking> bookings;

    String^ filePath = "..\\data\\Booking.xlsx";

    // Connection string for .xlsx files
    String^ connStr = "Provider=Microsoft.ACE.OLEDB.12.0;Data Source=" + filePath +
        ";Extended Properties='Excel 12.0 Xml;HDR=YES';";


    try {
        OleDbConnection^ conn = gcnew OleDbConnection(connStr);
        conn->Open();

        // Query all data from Sheet1
        String^ query = "SELECT * FROM [Sheet1$] WHERE [Username] = '" + username + "' AND [Status] = 'Booked'";
        OleDbCommand^ cmd = gcnew OleDbCommand(query, conn);

        OleDbDataReader^ reader = cmd->ExecuteReader();

        while (reader->Read())
        {
            // Read columns by name or index
            System::String^ user = reader->IsDBNull(4) ? nullptr : reader->GetString(4);
            System::String^ movie = reader->IsDBNull(2) ? nullptr : reader->GetString(2);
            System::String^ seats = reader->IsDBNull(1) ? nullptr : reader->GetString(1);
            System::String^ price = reader->IsDBNull(3) ? nullptr : reader->GetString(3);


            System::String^ date = nullptr;
            if (!reader->IsDBNull(0))
                date = reader->GetValue(0)->ToString();


            if (user == nullptr || movie == nullptr || date == nullptr)
                continue;

            if (user->Trim()->ToLower() == username->Trim()->ToLower())
            {

                Booking b;
                b.username = MarshalString(user);
                b.movieName = MarshalString(movie);
                b.price = MarshalString(price);
                b.date = MarshalString(date);
                b.seats = seats == nullptr ? "" : MarshalString(seats);
                bookings.push_back(b);
            }
        }

        reader->Close();
        conn->Close();
    }
    catch (Exception^ ex)
    {
        // Handle exceptions (file not found, no driver installed, etc.)
        System::Windows::Forms::MessageBox::Show("Error reading Excel file:\n" + ex->Message);
    }

    return bookings;
}