#include "TextDocument.h"

main(int argc, char* argv[])
{
	std::string search_string = argv[1];
	TextDocument tdoc(std::cin);
//	tdoc.showDocument();
//	std::cout << "hello\n";
	int scount = tdoc.getTermCount(search_string);
	std::cout << "The term "<< search_string << " occurs "<< scount <<" times " << std::endl;
}
