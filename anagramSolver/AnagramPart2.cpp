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

void printMatches(WordPair words[], int numWords, string target)
{
    int firstIndex, numberFound;
    numberFound = getMatches(words, numWords, target, firstIndex);
    cout << numberFound << " matches were found.";
    if(numberFound > 0)
    for(int i = firstIndex; i <= firstIndex + numberFound; i++)
    {
        cout << " " << words[i].original;
    }

    cout << endl;


}

/**
* Output the number of anagramatic forms found for each word.
* That means count the number of words that have just one anagrammatic form
* e.g. "hello", two anagrammatic forms e.g. "cat" and "act", three anagrammatic forms
* e.g. "rat", "art" , "tar" and so on. For the file words.txt the output should be...
* Found 164883 words with 1 angramatic form.
* Found 22862 words with 2 angramatic forms.
* Found 6981 words with 3 angramatic forms.
* Found 2720 words with 4 angramatic forms.
* Found 1170 words with 5 angramatic forms.
* Found 534 words with 6 angramatic forms.
* Found 357 words with 7 angramatic forms.
* Found 96 words with 8 angramatic forms.
* Found 72 words with 9 angramatic forms.
* Found 30 words with 10 angramatic forms.
* Found 11 words with 11 angramatic forms.
* Found 24 words with 12 angramatic forms.
* The string aerst has 12 anagrams.
*
* Notice the last line also tells you a certain string of sorted letters
* has the most anagrammatic forms, which happens to be 12.
*
* How to code it:
* Declare an int array counts of size 25, initialized to zeros.
* Declare variables numMatches, firstIndex, maxMatches and indexOfMax,
* all of type int. Initialize maxMatches and indexOfMax to 0.
* Use a for-loop to traverse the words array (either
* going from i = 0 to numWords-1 or from numWords-1 to 0).
* Within the loop body, call getMatches and
* assign the result to numMatches. Increment the element of
* countArray at index numMatches (since we found another word
* with numMatches anagrammatic forms). Also, compare numMatches and
* maxMatches to see which one is bigger. If numMatches is bigger,
* then update maxMatches and update indexOfMatch appropriately,
* to record the fact that a bigger number of matches was found at index i.
* After the for-loop, loop through the counts array and output the
* a line saying how many words were found for the elements of
* counts that are nonzero. (See the sample output above.)
* Also output the fact that words[indexOfMax].sorted has
* maxMatches anagrammatic forms. (See last line of sample output).
**/
void getStats(WordPair words[], int numWords);
int binarySearch(WordPair words[], int numWords, string target)
{
    int low = 0;
    while(low <= numWords)
    {
        int mid = low + (numWords-low)/2;
        if(words[mid].sorted == target)
        return mid;
        else if(words[mid].sorted > target)
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
  int counter = -1;
  ifstream infile(fileName);
  if(!infile)
    return false;
  else
  {
      while(infile)
      {
          counter ++;
          string currentWord;
          infile >> currentWord;
          words[counter].original = currentWord;
          infile >> currentWord;
          words[counter].sorted = currentWord;
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
    return 0;
    else
    {
        if(words[first].sorted == words[first - numMatches].sorted)
        {
            while(words[first].sorted == words[first - numMatches].sorted)
                {
                    numMatches++;
                }
                first = first - numMatches;
        }
        else if(words[first].sorted == words[first + numMatches].sorted)
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
// Call readWords to populate the array words.
// If readWords returns false print message "Unable to open input file."
// Otherwise proceed as follows:
// Print the message "Opened file successfully".
// Next call getStats to print the counts.
// Finally unscramble words until the user decides to quit.
// See the sample output in the instructions as a guide.
cout << "Bye." << endl;
}
