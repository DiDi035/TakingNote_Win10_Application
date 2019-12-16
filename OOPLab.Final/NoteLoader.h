#pragma once

#include"DataLoader.h"
#include"NoteFactory.h"
#include"FileWorkerTxt.h"
#include<sstream>

using namespace std;

class NoteLoader {
protected:
	int _totalNote;
	FileWorkerTxt* _fileWorker;
public:
	NoteLoader() {
		_totalNote = 0;
		_fileWorker = new FileWorkerTxt;
	}
	~NoteLoader() {
		delete _fileWorker;
	}
	int get_num_total_note() { 
		return _totalNote;
	}
	vector<Note> load_note();
};
