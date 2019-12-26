#include"pch.h"
#include"Tag.h"

Tags::Tags(string text) {
	_text = text;
}
//setter
void Tags::set_text(string data) {
	_text = data;
}
//getter
string Tags::get_text() {
	return _text;
}

vector<int> Tags::get_list_note() {
	return _idNote;
}

void Tags::add_note(int id) {
	_idNote.push_back(id);
}

bool Tags::delete_note(int id) {
	for (int i = 0; i < _idNote.size(); ++i) {
		if (_idNote[i] = id) {
			_idNote.erase(_idNote.begin() + i);
			return true;
		}
	}
	return false;
}

void Tags::set_new_list_note(vector<int> newListNote) {
	_idNote.clear();
	_idNote = newListNote;
}