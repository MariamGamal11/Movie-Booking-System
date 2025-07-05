#include "loginForm.h"
#include "homeForm.h"
#include "signinForm.h"
#include "profileForm.h"
#include "ExcelManger.h"
#include "Marvel.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    cs112::loginForm^ login = gcnew cs112::loginForm(); // Persistent loginForm instance
    User^ user = nullptr;

    while (true) {
        login->switchTORegister = false; // Reset flag
        login->Reset(); // Clear loginForm state before showing
        login->ShowDialog(); // Show loginForm as a modal dialog

        if (login->switchTORegister) {
            cs112::signinForm^ signIn = gcnew cs112::signinForm();
            signIn->ShowDialog();
            // After signup, loop back to login (handled by the loop)
        }
        else {
            user = login->user; // User from loginForm
            if (user != nullptr) {
                cs112::homeForm^ home = gcnew cs112::homeForm(user, login);
                login->Hide(); // Ensure loginForm is hidden while home is active
                Application::Run(home); // Run homeForm's message loop

                // After homeForm closes, loop will show loginForm again via ShowDialog
                user = nullptr;
            }
            else {
                if (MessageBox::Show("Authentication cancelled. Exit application?", "Program.cpp",
                    MessageBoxButtons::YesNo) == System::Windows::Forms::DialogResult::Yes) {
                    break; // Exit if user confirms
                }
                // Continue loop to show loginForm again
            }
        }
    }
}


