#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct WordPair 
{
string original, sorted;
};

const int MAXWORDS = 200000;

string sortWord(string w) 
{
  int length = w.length();
  string wArray[length], sortedW;

  for (int i = 0; i < length; i++) {
    wArray[i] = w.substr(i, 1);
  }

  for (int i = 0; i < length; i++) {
    int minIndex = i;
    for (int k = i + 1; k < length; k++) {
      if (wArray[minIndex] > wArray[k]) {
        minIndex = k;
      }
    }
    swap(wArray[i],wArray[minIndex]);
  }

  for (int i = 0; i < length; i++) {
    sortedW += wArray[i];
  }
  return sortedW;
}

bool readOriginalWords(const string &fileName, WordPair words[],int &numWords) {
  int counter = 0;
  ifstream infile(fileName);
  if (!infile)
    return false;
  else {
    string currentWord;
    while (infile >> currentWord) 
    {      
      words[counter].original = currentWord;
      words[counter].sorted = sortWord(currentWord);
      counter++;
    }
  }

  numWords = counter;

  infile.close();

  return true;
}

void sortWordsArray(WordPair words[], int numWords)
{
    for(int i = 0; i < numWords; i++)
    {
        int minIndex = i;
        for(int k = i + 1; k < numWords; k++)
        {
            if(words[minIndex].sorted > words[k].sorted )
            {
                minIndex = k;
            }
        }
        swap(words[i],words[minIndex]);
        if(i % 5 == 0)
        {
            cout << 100*i/numWords << "% sorted." << endl;
        }
    }
  cout << "Finished sorting array" << endl;
}
/**
* Output the contents of the words array to a file with the given fileName.
* Each line of output should contain the original and sorted fields of the
* corresponding array element. Close the file after all the words are output.
**/
void writeWordsToFile(const string& fileName, WordPair words[], int numWords);
int main()
{
static WordPair words[MAXWORDS]; // To store the words. (Keyword static needed due to the large array size.)
int numberOfWords; // To store the number of words read in.
string inputFileName, outputFileName; // To store the file names.
// get file names from the user.
// Call helper function readOriginalWords. If the return value is false,
// output message "Unable to open input file."
if (!readOriginalWords(inputFileName, words, numberOfWords)) {
cout << "Unable to open input file." << endl;
}
// If the return value from readOriginalWords is true, tell the user
// how many words were read in, then call sortWords.
// Upon return from sortWords, output the message "Finished sorting array."
// Next call writeWordsToFile with the given outputFileName.
// Upon return from writeWordsToFile outpu a message of the form
// "Finished writing file ________ ."
// (where the blank should be filled with the outputFileName).
cout << "Bye." << endl;
return 0;
}
