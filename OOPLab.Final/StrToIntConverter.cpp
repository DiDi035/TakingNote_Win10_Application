#include"pch.h"
#include"StrToIntConverter.h"

int StrToIntConverter::convert_from_String_to_int(String^ data) {
	string stringStore = strToString.convert_from_String_to_string(data);
	int intStore = stoi(stringStore);
	return intStore;
}

String^ StrToIntConverter::convert_from_int_to_String(int data) {
	stringstream ss;
	ss << data;
	String^ StringStore = stringToStr.convert_from_string_to_String(ss.str());
	return StringStore;
}