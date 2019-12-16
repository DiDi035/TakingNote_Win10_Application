#pragma once

#include<iostream>
#include<vector>

using namespace std;

class Note {
	int _id;
	string _text;
	vector<string> _listTag;

public:

	Note(int id, string text);
	//setter
	void set_id(int data);
	void set_text(string data);
	void add_tag(string data);
	//getter
	int get_id();
	string get_text();
	vector<string> get_list_tags();
	bool delete_tag(string tagDelete);
};
