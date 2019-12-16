#pragma once

#include"Tag.h"
#include"FileWorkerTxt.h"

class TagSaver {
protected:
	FileWorkerTxt _fileWorker;
public:
	void save_tag_to_file(vector<Tags> listTag, int numTotalTag);
};