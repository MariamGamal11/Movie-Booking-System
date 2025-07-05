#pragma once
#include <string>

using namespace System;
using namespace System::Collections::Generic;

public ref class Movie
{
public:
    String^ name;
    String^ description;
    String^ rate;
    String^ imagePath;
    String^ imagePath2;
    String^ imagePath3;
    String^ imagePath4;
    String^ imagePath5;
    List<String^>^ showtimes;

    double price;

};
