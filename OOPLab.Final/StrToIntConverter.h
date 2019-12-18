#pragma once

using namespace Platform;
using namespace std;

#include<string>
#include<sstream>
#include"StrTostringConverter.h"
#include"stringToStringConverter.h"

class StrToIntConverter {
	StrTostring strToString;
	stringToStringConverter stringToStr;
public:
	int convert_from_String_to_int(String^ data); 
	String^ convert_from_int_to_String(int data);
};
