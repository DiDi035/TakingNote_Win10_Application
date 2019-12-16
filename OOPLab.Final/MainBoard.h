#pragma once

#include"Note.h"
#include"Tag.h"
#include<vector>

using namespace std;

class MainBoard {
	vector<Note> _listNote;
	vector<Tags> _listTag;
public:
	vector<Note> get_listNote();
	vector<Tags> get_listTag();
	void set_listNote(vector<Note> listNote);
	void set_listTag(vector<Tags> listTag);
};
