#include"pch.h"
#include"Helper.h"

string Helper::combine_list_tag_to_single_string(vector<string> listTag) {
	string finalString;
	for (int i = 0; i < listTag.size(); ++i) {
		if (i == 0)
			finalString += listTag[i];
		else
			finalString += (", " + listTag[i]);
	}
	return finalString;
}

void Helper::combine_listNote_listTag(vector<Tags> &listTag, vector<Note> &listNote) {
	vector<int> listNoteId;
	for (int i = 0; i < listTag.size(); ++i) {
		listNoteId = listTag[i].get_list_note();
		for (int j = 0; j < listNoteId.size(); ++j) {
			listNote[listNoteId[j] - 1].add_tag(listTag[i].get_text());
		}
		listNoteId.clear();
	}
}