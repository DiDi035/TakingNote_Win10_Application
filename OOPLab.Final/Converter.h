#pragma once

using namespace Platform;
using namespace std;

#include<string>

class Converter {
public:
	virtual String^ convert_from_string_to_String(string data) = 0;
	virtual string convert_from_String_to_string(String^ data) = 0;
};
