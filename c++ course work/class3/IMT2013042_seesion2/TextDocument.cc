//TextDocument.cc

#include<iostream>
#include<string>

#include "TextDocument.h"

#include "TextLine.h"

TextDocument::TextDocument(std::istream& is)
{
	std::string temp;
	while(getline(is,temp)){
		TextLine *tptr = new TextLine(temp);
		doc_lines.push_back(tptr);
		}
	line_count = doc_lines.size();
}

int TextDocument:: getTermCount(std::string search_string)
{
	int count = 0;
	for(int i = 0; i < doc_lines.size() ; i++){
		count += doc_lines[i]->getTermCount(search_string);
			
	}
	return count;
}

void TextDocument::showDocument()
{
	for(int i = 0;i < doc_lines.size(); i++){
		doc_lines[i]->showline();
	}
}

TextDocument::~TextDocument()
{
	for(int i = 0; i < line_count; i++){
		delete doc_lines[i];
	}
}
