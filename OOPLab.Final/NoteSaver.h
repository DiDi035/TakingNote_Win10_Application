#pragma once

#include"Note.h"
#include"FileWorkerTxt.h"

class NoteSaver {
	FileWorkerTxt _fileWorker;
public:
	void save_note_to_file(vector<Note> listNote, int numTotalNote);
};
