# Movie-Booking-System
CineVerse is a Windows Forms-based desktop application built in C++/CLI as part of the CSCI 112 course. Designed to provide a smooth and interactive movie booking experience, it allows users to explore categorized movies, view detailed information, and book seats based on real-time availability.

🚀 Features:

🔐 User Authentication

 - Secure sign-in and registration system.

 - Personalized experience based on user login.

🎞️ Movie Browsing by Category

- Dedicated window for browsing five curated movie categories: Anime, Marvel, Book Adaptations, DC, Disney.
  
- Scrollable user-friendly layout with movie posters and titles.

📄 Movie Details & Showtimes

- Upon selection, a detailed page displays:

Movie description

Ratings

Available showtimes

- Showtimes and seat data are dynamically loaded from Excel files.

🎟️ Interactive Seat Selection & Booking

- Select seats from a visual layout.

- Already booked seats are disabled to prevent double-booking.

- Users can also cancel existing bookings.

✅ Booking Confirmation

- Booking confirmation saved to Excel.

- Each booking includes:

    Movie name, Time and date, Selected seat(s)

👤 Profile Page

- Displays: Watched movies, Upcoming bookings

- All data is pulled in real-time from the Excel backend.

📁 Excel-Based Backend Integration

- Uses .xlsx files and OLEDB to handle:

User accounts, Movies, Categories, Showtimes, Bookings, Seat availability

🛠 Technologies Used

- C++/CLI

- Windows Forms (WinForms)

- .NET Framework

- Microsoft Access Database Engine (OLEDB)

- Excel (.xlsx) as data storage
