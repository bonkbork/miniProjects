#include <string>
#include <iostream>
#include <fstream>

using namespace std;
/**
* To hold the original and sorted version of each word.
**/
struct WordPair {
string original, sorted;
};
const int MAXWORDS = 200000; // maximum number of words

int getMatches(WordPair words[], int numWords, string originalWord, int& first);

void printMatches(WordPair words[], int numWords, string target)
{
    int firstIndex, numberFound;
    numberFound = getMatches(words, numWords, target, firstIndex);
    cout << numberFound << " matches were found.";
    if(numberFound > 0)
    for(int i = firstIndex; i < firstIndex + numberFound; i++)
    {
        cout << " " << words[i].original;
    }

    cout << endl;


}

void getStats(WordPair words[], int numWords)
{
    int count[25] = {0}, numMatches, firstIndex, maxMatches = 0, indexOfMax = 0;
    for(int i = 0; i < numWords; i++)
    {
        numMatches = getMatches(words, numWords, words[i].sorted, firstIndex);
        count[numMatches] ++;
        if(numMatches > maxMatches)
        {
        maxMatches = numMatches;
        indexOfMax = i;
        }
    }
    for(int i = 1; i <= maxMatches; i++)
    {
        cout << "Found " << count[i] << " words with " << i << " angramatic form." << endl;
    }

    cout << "The string " << words[indexOfMax].sorted << " has " << maxMatches << " anagrams." << endl;

}

int binarySearch(WordPair words[], int numWords, string target)
{
    int low = 0;
    while(low < numWords)
    {
        int mid = low + (numWords-low)/2;
        if(words[mid].sorted == target)
        return mid;
        else if(words[mid].sorted < target)
        low = mid + 1;
        else
        numWords = mid - 1;
    }
    return -1;
}

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

bool readWords(WordPair words[], int& numWords, string fileName)
{
    int counter = 0;
    ifstream infile(fileName);
    if(!infile)
    return false;
    else
    {
        while(infile)
        {
            string currentWord;
            infile >> currentWord;
            words[counter].original = currentWord;
            infile >> currentWord;
            words[counter].sorted = currentWord;
            counter++;
        }
    }
    numWords = counter;
    return true;
}

int getMatches(WordPair words[], int numWords, string originalWord, int& first)
{
    first = binarySearch(words, numWords, sortWord(originalWord));
    int numMatches = 1;
    if(first == -1)
    {
      return 0;
    }
    else
    {
        if(first > 0 && words[first].sorted == words[first - numMatches].sorted)
        {
            while(words[first].sorted == words[first - numMatches].sorted)
                {
                    numMatches++;
                }
                first = first - numMatches;
        }
        else if(first < numWords &&words[first].sorted == words[first + numMatches].sorted)
        {
            while(words[first].sorted == words[first + numMatches].sorted)
                {
                    numMatches++;
                }
        }
    }

    return numMatches;
}
int main()
{
static WordPair words[MAXWORDS]; // To hold the words.
int numWords; // To store the number of words pairs read in.
// Get the input file name from the user.
string inputFileName;
cout << "What is the input file name? ";
cin >> inputFileName;
// Call readWords to populate the array words.
// If readWords returns false print message "Unable to open input file."
// Otherwise proceed as follows:
// Print the message "Opened file successfully".
if(!readWords(words, numWords, inputFileName))
cout << "Unable to open input file." << endl;
else
{
    string userInput = "l";
    cout << "Opened file successfully." << endl;
    getStats(words, numWords);
    do
    {
        cout << "Please enter a scrambled word or q to quit: ";
        cin >> userInput;
        if(userInput != "q")
        {
            int firstIndex;
            int matches = getMatches(words, numWords, userInput, firstIndex);
            cout << matches << " matches were found:";
            for(int i = firstIndex; i < firstIndex + matches; i++)
            {
                cout << " " << words[i].original;
            }
            cout << endl;
        }
    }while(userInput != "q");
}
// Next call getStats to print the counts.
// Finally unscramble words until the user decides to quit.
// See the sample output in the instructions as a guide.
cout << "Bye." << endl;
}
