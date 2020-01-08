#pragma once

#include"Note.h"
#include"TagFactory.h"
#include"FileWorker.h"
#include"Tag.h"

using namespace Windows::UI::Popups;

class FileWorkerTxt : public FileWorker {
public:
	int read_number_of_note_from_file(string fileName);
	int read_number_of_tag_from_file(string fileName);
	string read_note_from_file(string fileName);
	vector<string> read_list_tag_from_file(string fileName, int totalTag);
	Tags read_list_note_with_tag_from_file(string fileNameWithoutTxt);
	void write_note_to_file(int numOfTotalNote, string filename, vector<Note> listNote);
	void write_number_of_tag_to_file(string filename, int numTotalTag);
	void write_tag_to_file(string filename, vector<Tags> listTag, int numOfTotalTag);
};
