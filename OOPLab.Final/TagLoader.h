#pragma once

#include"TagFactory.h"
#include"FileWorkerTxt.h"

using namespace std;

class TagLoader {
	int _totalTag;
	FileWorkerTxt* _fileWorker;
public:
	TagLoader() {
		_totalTag = 0;
		_fileWorker = new FileWorkerTxt;
	}
	~TagLoader() {
		delete _fileWorker;
	}
	int get_nom_total_tag();
	vector<Tags> load_tag();
};