#include"pch.h"
#include"NoteLoader.h"

vector<Note> NoteLoader::load_note() {
	string content;
	int totalNote = _fileWorker->read_number_of_note_from_file("TotalNote.txt");
	_totalNote = totalNote;
	vector<Note> listNote;
	for (int i = 1; i <= totalNote; ++i) {
		stringstream ss;
		ss << i;
		content = _fileWorker->read_note_from_file(ss.str() + ".txt");
		listNote.push_back(NoteFactory::note_generator(i, content));
		content.clear();
	}
	return listNote;
}