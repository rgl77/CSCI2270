// Orgil Sugar
// Instructor:  Rhonda Hoenigman
// TA : Aayush

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

// Declaring global variables
int arraySize = 100;
int num = 0;
int index = 0;

// Word struct
struct Word
{
	string singleWord;
	int wordCount;
};


// Array 1 and 2
Word *Array, *Array2;

//adding word count to non Common words count
int nonCommonWords()
{
	int totalNonCommonWords = 0;
	for (int i = 0; i < index; i++)
	{
		if(!isCommon(Array.singleWord[i]))
		totalNonCommonWords = totalNonCommonWords + Array[i].wordCount;
	}
	return totalNonCommonWords;
}

// sorting non common words with sort
void sortNonCommon(int length)
{
	Word swap;
	int countSwap = 0;
	for (int x = 0; x < arraySize - 1; x++)
	{
		for (int o = 0; o < arraySize - x - 1; o++)
		{
			if (Array[o + 1].wordCount > Array[o].wordCount)
			{
				swap = Array[o];
				Array[o] = Array[o + 1];
				Array[o + 1] = swap;
				countSwap++;
			}
		}
	}

}

// including the 50 common words given
bool isCommon(string str)
{
	bool h = false;
	string commonWords[50] = {"the", "be", "to", "of", "and", "a", "in", "that", "have", "i", "it", "for", "not", "on", "with", "he", "as", "you", "do", "at", "this", "but", "his", "by", "from", "they", "we", "say", "her", "she", "or", "an", "will", "my", "one", "all", "would", "there", "their", "what", "so", "up", "out", "if", "about", "who", "get", "which", "go", "me"};
	for (int x = 0; x < 50; x++)
	{
		if (str == commonWords[x])
			{
			    h = true;
			}
	}
	return h;
}


// doubling the array and copying the past one into new one
void doubleArray()
{
	arraySize = arraySize * 2;
	Array2 = new Word[arraySize];
	for (int j = 0; j < arraySize/2; j++)
	{
		Array[j] = Array2[j];

	}
	delete []Array;
	Array = Array2;
	num++;
}

// Adding the element into the array
void addElement(string str2)
{

	if (isCommon(str2)==false){
    bool isfound=true;
	for (int i = 0; i < index; i++)
	{
		if (str2 == Array[i].singleWord)
		{
			Array[i].wordCount++;
			isfound=true;
			break;
		}
	}
	if(isfound==false){
		Array[index].singleWord = str2;
		Array[index].wordCount = 1;
		index++;
	}
	if (index == arraySize)
	{
		doubleArray();
	}
}
}

// getting the file
void getFile(string user)
{
	ifstream ifs;
	string str;
	int i = 0;
	string word1;
	ifs.open(user);
	while(ifs >> str)
	{
		addElement(str);
	}
}

// main function
int main (int argc, char* argv[])
{
    string filename = argv[1];
	int topNwords = atoi(argv[2]);
	Array = new Word[arraySize];
	getFile(filename);
	sortNonCommon(index);
	for (int i = 0; i < topNwords; i++)
	{
		cout << Array[i].wordCount << " - " << Array[i].singleWord << endl;
	}
	cout << "#" << endl;
	cout << "Array doubled: " << num << endl;
	cout << "#" << endl;
	cout << "Unique non-common words: " << index << endl;
	cout << "#" << endl;
	cout << "Total non-common words: " << nonCommonWords() << endl;
	return 0;

}



