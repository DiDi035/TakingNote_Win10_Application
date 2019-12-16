#pragma once

#include"Note.h"

class NoteFactory {
public:
	static Note note_generator(int& id, string& text) {
		return Note(id, text);
	}
};
