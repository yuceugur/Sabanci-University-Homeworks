#include <iostream>
#include <string>
// uguryuce 27981 the3
using namespace std;

bool isEmpty(string sentence) // it works
{
	if (sentence.at(0) == '@')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isNum(string word) // it works
{	
	int x = 0; int len; int k = 0; char c;
	len = word.length();
	for (x; x < len; x += 1)
	{
		c = word.at(x);
		if (( 65 <= c && c <= 90) || ( 97 <= c && c <= 122))     // non-alphabetical
		{
			k += 1;
		}
	}
	if ( k == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool isSentence(string sentence) //it works
{
	if (sentence.find(".") == string::npos)    // non-sentence
	{
		return true;
	}
	else
	{
		return false;
	}

}


int main()
{
	string input;
	string sentence = "";

	cout << "Please enter the input sentences: ";
	do
	
	}while (input != "@" );
	
	cout << sentence;

	return 0;
}