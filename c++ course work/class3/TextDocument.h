//TextDocument.h

#include<iostream>
#include<vector>
//#include "textline.h"
//Class pre declaration
class TextLine;

class TextDocument{
	std::vector<TextLine*> doc_lines;
	int line_count;
public:
	TextDocument(std::istream& is);
	~TextDocument();
	int getTermCount(std::string search_string);
	void showDocument();
};
