#include"pch.h"
#include"TagSaver.h"

void TagSaver::save_tag_to_file(vector<Tags> listTag, int numTotalTag) {
	_fileWorker.write_number_of_tag_to_file("TotalTag.txt", numTotalTag);
	_fileWorker.write_tag_to_file("ListTag.txt", listTag, numTotalTag);
}