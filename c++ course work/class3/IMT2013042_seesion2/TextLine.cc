//textline.cc

#include<iostream>
#include<string>

#include "TextLine.h"

TextLine::TextLine(std::string input_line)
{
	text_line = input_line;
}

int TextLine::getTermCount( std::string search_string)
{
	int count = 0;
	std::size_t found = text_line.find(search_string);
	if(found != std::string::npos)
		count++;
	while(found != std::string::npos){
		std:: size_t holder = text_line.find(search_string, found + 1);
		found = holder;
		if(found == std::string::npos)
			break;
		count++;
	}
	//std::cout << count << std::endl;
	return count;
}	

void TextLine::showline()
{
	std::cout << text_line << std::endl;
}
