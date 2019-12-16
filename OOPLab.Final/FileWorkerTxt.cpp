#include"pch.h"
#include"FileWorkerTxt.h"

string FileWorkerTxt::read_note_from_file(string fileName) {
	string contentFromFile, tmp;
	ifstream fin;
	fin.open(_dataBaseFolder + "\\" + fileName);
	if (fin) {
		while (!fin.eof()) {
			getline(fin, tmp, '\n');
			if (tmp == "\0")
				break;
			contentFromFile += tmp;
			contentFromFile += '\r';
		}
	}
	fin.close();
	return contentFromFile;
}

int FileWorkerTxt::read_number_of_note_from_file(string fileName) {
	int totalNote;
	ifstream fin;
	fin.open(_dataBaseFolder + "\\" + fileName);
	if (fin) {
		fin >> totalNote;
	}
	fin.close();
	return totalNote;
}

int FileWorkerTxt::read_number_of_tag_from_file(string fileName) {
	int totalTag;
	ifstream fin;
	fin.open(_dataBaseFolder + "\\" + fileName);
	if (fin) {
		fin >> totalTag;
	}
	fin.close();
	return totalTag;
}

vector<string> FileWorkerTxt::read_list_tag_from_file(string fileName, int totalTag) {
	vector<string> listTag;
	ifstream fin;
	string tag;
	fin.open(_dataBaseFolder + "\\" + fileName);
	if (fin) {
		for (int i = 0; i < totalTag; ++i) {
			getline(fin, tag, '\n');
			listTag.push_back(tag);
			tag.clear();
		}
	}
	fin.close();
	return listTag;
}

Tags FileWorkerTxt::read_list_note_with_tag_from_file(string fileNameWithoutTxt) {
	ifstream fin;
	Tags newTag = TagFactory::tag_generator(fileNameWithoutTxt);
	fin.open(_dataBaseFolder + "\\" + fileNameWithoutTxt + ".txt");
	if (fin) {
		int noteId;
		int numOfNoteWithTag;
		fin >> numOfNoteWithTag;
		for (int i = 0; i < numOfNoteWithTag; ++i) {
			fin >> noteId;
			newTag.add_note(noteId);
		}
	}
	fin.close();
	return newTag;
}

void FileWorkerTxt::write_number_of_tag_to_file(string filename, int numTotalTag) {
	ofstream fout;
	fout.open(_dataBaseFolder + "\\" + filename);
	if (fout) {
		fout << numTotalTag;
	}
	fout.close();
}

void FileWorkerTxt::write_tag_to_file(string filename, vector<Tags> listTag, int numOfTotalTag) {
	ofstream fout1, fout2;
	fout1.open(_dataBaseFolder + "\\" + filename);
	if (fout1) {
		for (int i = 0; i < numOfTotalTag; ++i) {
			fout1 << listTag[i].get_text() << endl;
			fout2.open(_dataBaseFolder + "\\" + listTag[i].get_text() + ".txt");
			if (fout2) {
				vector<int> listNote = listTag[i].get_list_note();
				int listNoteSize = listNote.size();
				fout2 << listNoteSize << endl;
				for (int j = 0; j < listNoteSize; ++j) {
					fout2 << listNote[j] << endl;
				}
			}
			fout2.close();
		}
	}
	fout1.close();
}

void FileWorkerTxt::write_note_to_file(int numOfTotalNote, string filename, vector<Note> listNote) {
	ofstream fout1, fout2;
	fout1.open(_dataBaseFolder + "\\" + filename);
	if (fout1) {
		fout1 << numOfTotalNote;
	}
	fout1.close();
	for (int i = 0; i < numOfTotalNote; ++i) {
		stringstream ss;
		ss << listNote[i].get_id();
		fout2.open(_dataBaseFolder + "\\" + ss.str() + ".txt");
		if (fout2) {
			string noteContent = listNote[i].get_text();
			fout2 << noteContent;
		}
		fout2.close();
	}
}