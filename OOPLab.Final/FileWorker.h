#pragma once

#include"pch.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace Windows::Storage;
using namespace std;

class FileWorker
{
protected:
	ifstream fin;
	ofstream fout;
	string _dataBaseFolder;
public:
	~FileWorker() {
		if (fin.is_open()) {
			fin.close();
		}
		if (fout.is_open()) {
			fout.close();
		}
	}
	FileWorker() {
		Platform::String^ localfolder = ApplicationData::Current->LocalFolder->Path;
		wstring folderNameW(localfolder->Begin());
		string folderNameA(folderNameW.begin(), folderNameW.end());
		_dataBaseFolder = folderNameA;
	}
};