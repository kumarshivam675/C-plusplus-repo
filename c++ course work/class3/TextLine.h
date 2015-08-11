//textline.h

#include<string>

class TextLine{
	std::string text_line;
	int no_textlines;
public:
	TextLine(std::string input_line);
	int getTermCount(std::string search_string);
	void showline(); //For printing the line
}; 	
