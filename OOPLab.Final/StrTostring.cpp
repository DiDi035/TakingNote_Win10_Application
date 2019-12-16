#include"pch.h"
#include"StrTostringConverter.h"

string StrTostring::convert_from_String_to_string(String^ data) {
	std::wstring convertStep1(data->Begin());
	std::string convertStep2(convertStep1.begin(), convertStep1.end());
	return convertStep2;
}

