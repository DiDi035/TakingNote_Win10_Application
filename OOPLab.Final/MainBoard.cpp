#include"pch.h"
#include"MainBoard.h"

vector<Note> MainBoard::get_listNote() {
	return _listNote;
}

vector<Tags> MainBoard::get_listTag() {
	return _listTag;
}

void MainBoard::set_listNote(vector<Note> listNote) {
	_listNote = listNote;
}

void MainBoard::set_listTag(vector<Tags> listTag) {
	_listTag = listTag;
}