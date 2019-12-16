#include "pch.h"
#include"Note.h"

Note::Note(int id, string text) {
	_id = id;
	_text = text;
}
//setter
void Note::set_id(int data) {
	_id = data;
}
void Note::set_text(string data) {
	_text = data;
}
void Note::add_tag(string data) {
	_listTag.push_back(data);
}
//getter
int Note::get_id() {
	return _id;
}
string Note::get_text() {
	return _text;
}
vector<string> Note::get_list_tags() {
	return _listTag;
}
bool Note::delete_tag(string tagDelete) {
	for (int i = 0; i < _listTag.size(); ++i)
	{
		if (_listTag[i] == tagDelete)
		{
			_listTag.erase(_listTag.begin() + i);
			return true;
		}
	}
	return false;
}