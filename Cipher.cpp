#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

char decode(char aChar);
void decodeFile(ifstream& aInFile, ofstream& aOutFile, int aKey);

//functions
void decodeFile(ifstream& aInFile, ofstream& aOutFile, int aKey)
{
	srand(aKey);	//uses key as the seed for random no. generator
	char data;
	while (aInFile.good())
	{
		aInFile.get(data);
		if (!aInFile.eof())	//check for End Of File
		{
			aOutFile << decode(data);
		}
	}
}

char decode(char aChar)
{
	//decoding logic
	int result = 1 + rand() % 127;
	result = aChar - result;
	if (result < 0)
	{
		result = result + 128;	//brings value back to ASCII range
	}
	//char outtt = result;
	//cout << outtt;
	return result;
}

int main(int argc, char* argv[])
{
	if (argc < 4)	//need 3 arguments (key, inFile, outFile), argc is already 1
	{
		cerr << "Arguments missing" << endl;
		cerr << "Usage: euclid infile outfile" << endl;
		return 1; //program failed, not enough inputs
	}
	int aKey = atoi(argv[1]);
	cout << aKey << endl;
	ifstream aInFile;
	ofstream aOutFile;
	aInFile.open(argv[2], ios::binary);
	if (!aInFile.good())	//checks input file can be opened
	{
		aInFile.close();
		cerr << "Input file could not be opened" << endl;
		return 2;
	}
	else
	{
		cout << "Input file successfully opened" << endl;
		aOutFile.open(argv[3], ios::binary);	//open output file
		cout << "Output file " << argv[3] << " created" << endl;
	}
	decodeFile(aInFile, aOutFile, aKey);
	aOutFile << endl << endl << "Prepared by Joshua Wong (101350311)" << endl;
	return 0;
}
