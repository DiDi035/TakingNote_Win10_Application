#pragma once

#include"FileWorker.h"
#include"Note.h"
#include"Tag.h"

class DataLoader {
public:
	virtual vector<Note> load_note() = 0;
	virtual vector<Tags> load_tag() = 0;
};
