#pragma once

#include<string>

using namespace std;
//KMP algorithms to search string-matching
class KMP {
public:
	static bool search_pattern_in_string(string pattern, string bigString) {
		int patternSize = pattern.length();
		int bigStringSize = bigString.length();
		int* storeArr = new int[patternSize]; //array to store matching characters
		storeArr[0] = 0; //always intialize 1st element as 0
		int i = 0, j = 1;
		while (j < patternSize) {
			if (pattern[i] != pattern[j]) {
				if (i > 0)
					i = storeArr[i - 1];
				else {
					storeArr[j] = 0;
					++j;
				}
			}
			else {
				storeArr[j] = i + 1;
				++j;
				++i;
			}
		}
		i = 0;
		j = 0;
		while (j < bigStringSize && i < patternSize) {
			if (pattern[i] == bigString[j]) {
				++i;
				++j;
			}
			else {
				if (i > 0)
					i = bigString[i - 1];
				else
					j++;
			}
		}
		delete[] storeArr;
		if (i == patternSize) return true;
		return false;
	}
};