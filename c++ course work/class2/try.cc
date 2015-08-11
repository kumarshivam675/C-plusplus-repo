#include<iostream>
#include<string>

using namespace std;

main()
{
	string sentence, word;
	getline(cin,sentence);
	cout << sentence << endl;
	getline(cin, word);
	if(sentence.find(word) != string::npos)
		cout<< "found";
}
