#pragma once

#include"Tag.h"

class TagFactory {
public:
	static Tags tag_generator(string& text) {
		return Tags(text);
	}
};
