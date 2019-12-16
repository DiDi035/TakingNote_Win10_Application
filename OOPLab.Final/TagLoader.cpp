#include"pch.h"
#include"TagLoader.h"

vector<Tags> TagLoader::load_tag() {
	int totalTag = _fileWorker->read_number_of_tag_from_file("TotalTag.txt");
	_totalTag = totalTag;
	vector<string> listTagName = _fileWorker->read_list_tag_from_file("ListTag.txt", _totalTag);
	vector<Tags> listTag;
	for (int i = 0; i < listTagName.size(); ++i) {
		listTag.push_back(_fileWorker->read_list_note_with_tag_from_file(listTagName[i]));
	}
	return listTag;
}

int TagLoader::get_nom_total_tag() {
	return _totalTag;
}