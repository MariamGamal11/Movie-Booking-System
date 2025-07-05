#pragma once

#include "Booking.h"
#include <vector>

using namespace System;

ref class ExcelManager
{
public:
    static std::vector<Booking> GetBookingsForUser(System::String^ username);

private:
    static std::string MarshalString(System::String^ str);
};