# Movie-Booking-System
CineVerse is a Windows Forms-based desktop application built in C++/CLI as part of the CSCI 112 course. Designed to provide a smooth and interactive movie booking experience, it allows users to explore categorized movies, view detailed information, and book seats based on real-time availability.

## Features:

🔐 User Authentication

 - Secure sign-in and registration system.

 - Personalized experience based on user login.

🎞️ Movie Browsing by Category

- Dedicated window for browsing five curated movie categories: Anime, Marvel, Book Adaptations, DC, Disney.
  
- Scrollable user-friendly layout with movie posters and titles.

📄 Movie Details & Showtimes

- Upon selection, a detailed page displays: Movie description, Ratings, Available showtimes.

- Showtimes and seat data are dynamically loaded from Excel files.

🎟️ Interactive Seat Selection & Booking

- Select seats from a visual layout.

- Already booked seats are disabled to prevent double-booking.

- Users can also cancel existing bookings.

✅ Booking Confirmation

- Booking confirmation saved to Excel.

- Each booking includes: Movie name, Time and date, Selected seat(s).

👤 Profile Page

- Displays: Watched movies, Upcoming bookings

- All data is pulled in real-time from the Excel backend.

📁 Excel-Based Backend Integration

- Uses .xlsx files and OLEDB to handle: User accounts, Movies, Categories, Showtimes, Bookings, Seat availability

## Technologies Used

- C++/CLI

- Windows Forms (WinForms)

- .NET Framework

- Microsoft Access Database Engine (OLEDB)

- Excel (.xlsx) as data storage

## How to Run
- Download or clone this repository to your local machine (make sure that cs112, data, pics folders remain in the same directory as cs112.sln, as they are required for the application to function properly).
- Install Microsoft Visual Studio with C++/CLI support (2019 or later, with .NET Framework 4.7.2 or later).
- Install Microsoft Access Database Engine 2010 Redistributable (64-bit or 32-bit, matching your system) for OLEDB connectivity.
- Configure the project in Visual Studio by running cs112.sln file.

## Team Members
* Dareen Hassan:
  
  - Built the home, sign-up (signinForm.h), and login (loginForm.h) windows.
  
  - Managed user data storage in cinema_data.xlsx.
  
  - Designed a dynamic panel for movie details.
  
  - Handled the extraction of pictures from the excel files.
  
* Iren Nabil:
  
  - Created the category window for selecting movie categories.
  
  - Implemented a system to display category-specific movies.
  
* Fatma Eldahahn:
  
  - Developed the movies window with a dynamic panel.
  
  - Displayed movie names and posters from Movies.xlsx.
  
* Mariam Elbadry:
  
  - Designed and implemented the movie booking window (MovieDetailForm.h).
  
  - Enabled showtime and seat selection with a 3x5 grid and ticket booking.
  
  - Extracted movie details from Movies.xlsx.
  
  - Saved the movie booking infromation into Booking.xlsx
  
* Mariam Gamal:
  
  - Developed the user profile window (profileForm.h).
  
  - Displayed past and upcoming bookings from Booking.xlsx.
  
  - Created a cancellation system for bookings.
  
  - Added Features hover effects and custom cursors in UI.
