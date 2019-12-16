#pragma once

#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Tags {
	string _text;
	vector<int> _idNote;

public:

	Tags(string text);
	//setter
	void set_text(string data);
	void add_note(int id);
	//getter
	string get_text();
	vector<int> get_list_note();
	bool delete_note(int id);
};
