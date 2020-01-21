#include <iostream>
#include <array>
#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include "WordAnalysis.h"
using namespace std;

WordAnalysis::WordAnalysis(int a)
{
	timesDoubled = 0;
	index = 0;
	words = new word[a];
	wordCount = a;
}

bool WordAnalysis::readDataFile(char* fileName)
{
	ifstream dataFile;
	string word1;
	int i = 0;
	dataFile.open(fileName);
	if (dataFile.is_open())
	{	
		while (dataFile >> word1)
		{
			if (checkIfCommonWord(word1) == false)
			{
				doubleArrayAndAdd(word1);
			}
		}
		dataFile.close();
		return true;
	}
	else
	{
		cout << "error" << endl;
		return false;
	}
}

bool WordAnalysis:: checkIfCommonWord(string str)
{
	string commonWords[50] = {"the", "you", "one", "be", "do", "all", "to", "at", "would", "of", "this", "there", "and", "but", "their", "a", "his", "what", "in", "by", "so", "that", "from", "up", "have", "they", "out", "i", "we", "if", "it", "say", "about", "for", "her", "who", "not", "she", "get", "on", "or", "which", "with", "an", "go", "he", "will", "me", "as", "my"};
	for (int x = 0; x < 50; x++)
	{
		if (str == commonWords[x])
			return true;
	}
	return false;

}

int WordAnalysis:: getWordCount()
{
	int totalWords = 0;
	for (int i = 0; i < wordCount; i++)
	{
		totalWords = totalWords + words[i].count;
	}
	return totalWords;
}


void WordAnalysis:: sortData()
{
	word swap;
	int countSwap = 0;
	for (int k = 0; k < index - 1; k++)
	{
		for (int l = 0; l < index - k ; l++)
		{
			if (words[l + 1].count > words[l].count)
			{
				swap = words[l];
				words[l] = words[l + 1];
				words[l + 1] = swap;
				countSwap++;
			}
		}
	}

}

void WordAnalysis:: doubleArrayAndAdd(string str2)
{
	
		if (checkIfCommonWord(str2)==false)
		{
			if (index == wordCount)
			{
				wordCount = wordCount * 2;
				word *words2 = new word[wordCount];
				for (int j = 0; j < wordCount/2; j++)
				{
					words2[j] = words[j];
					
				}
				delete []words;
				words = words2;
				timesDoubled++;
			}
			if (index == 0)
			{
				words[0].w = str2;
				words[0].count = 1;
				index = 1;

				return;
			}

			bool isfound = false;

			for (int i = 0; i < index; i++)
			{
				if (str2 == words[i].w)
				{
					words[i].count++;
					isfound = true;
					//cout << words[i].count << endl;
					break;
				}
			}

			if(isfound == false)
			{
				words[index].w = str2;
				words[index].count = 1;
				index++;
			
			}

		}
	

}

int WordAnalysis::getArrayDoubling()
{
	return timesDoubled;
}

void WordAnalysis::printCommonWords(int topN)
{	
	sortData();

	for (int i = 0; i < topN; i++)
	{

		cout << words[i].count << " - " << words[i].w << endl;
	}
}

int WordAnalysis:: getUniqueWordCount()
{
	return index;
}
