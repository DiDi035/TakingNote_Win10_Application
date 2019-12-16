#include"pch.h"
#include"stringToStringConverter.h"

String^ stringToStringConverter::convert_from_string_to_String(string data) {
	wstring w_str = wstring(data.begin(), data.end());
	const wchar_t* w_chars = w_str.c_str();
	String^ output = ref new String(w_chars);
	return output;
}