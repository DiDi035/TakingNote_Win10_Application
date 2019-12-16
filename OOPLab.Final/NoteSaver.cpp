#include"pch.h"
#include"NoteSaver.h"

void NoteSaver::save_note_to_file(vector<Note> listNote, int numTotalNote) {
	_fileWorker.write_note_to_file(numTotalNote, "TotalNote.txt", listNote);
}