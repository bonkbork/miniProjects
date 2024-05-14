/**
* Read a text file of strings corresponding to English words.
* Output to a text file the original words along with a sorted version
* of each word. Use an array of WordPair to store the data, where WordPair is
* struct type with two members: original and sorted, both of type string.
* The original field will hold each words from the file in its
* original form. The sorted field will hold a sorted version of the
* same word e.g. if original is "hello" then sorted will be "ehllo".
* Record the number of words read in from the file.

* Next sort the array of WordPairs using selection sort. In comparing
* elements use the sorted field to decide which element is bigger.
* Finally, output the array contents to a file, starting with element 0.
* Each line of the output file will contain the original and sorted
* fields of the corresponding array element, in that order.
* A template is provided below with prototypes for functions that
* perform the various tasks.
* Since sorting a large array is time consuming be prepared to wait
* several minutes for the sorting process to complete.
**/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
* Struct type WordPair holds an original word e.g."hello"
* along with a sorted version of the same word e.g. "ehllo"
**/
struct WordPair 
{
string original, sorted;
};
/**
* The maximum number of words that can be stored.
**/
const int MAXWORDS = 200000;
/**
* Sort w alphabetically by letter using selection sort.
* For example, if w is initially "hello" then after being sorted
* w will be "ehllo". Return w.
*
* How to code it:
* First save w.length() to a local variable e.g. length.
* Then use conventional selectionsort where w is viewed
* as an array of characters with the given length. In selection sort
* the first pass locates a smallest character starting from
* index 0 and swaps with w[0]. The next pass locates a smallest
* character starting from index 1 and swaps with w[1]. The process
* continue until all the characters of w are in ascending
* aphabetical order. A difference with the usual
* array-based selection sort is that sortWord has return type
* string rather than void. That means we convey the result
* by returning w (Alternatively we could have passed w by reference,
* but that would be less convenient since when we call sortWord
* we want to retain a copy of the original string.)
**/
string sortWord(string w)
{
    int length = w.length;
    char smallChar;
    string sortedWord;
    char wArray[w.length]; // dude just use an array its much easier (bryant)
    for(int i = 0; i < w.length;i++)
    {
        smallChar = (int)w.substr(i,1);
        for(int k = i; k < w.length;k++)
        {
        if((int)smallChar > <int>w.substr(k,1))
        {
            smallChar = w.substr(k,1);
        }
        }
        sortedWord += smallChar;
    }
}
/**
* Open the file with the given fileName for input.
* If opening the file failed, return false. Otherwise do the following:
* Read words from the file into the array parameter words and set
* int parameter numWords to the number of words read in.
* After each string is read, the current element of words will be initialized as follows:
* Set the original field to the input string in its original form and set
* the sorted field to a sorted version of the word obtained by calling sortWord.
* Finally, close the file and return true.
**/
bool readOriginalWords(const string& fileName, WordPair words[], int& numWords);
/*
* Use selection sort to sort the array words in ascending order.
* To compare elements, use the sorted field of each element:
* If words[i].sorted > words[j].sorted evaluates to true
* then words[i] and words[j] are out of order. Since the function
* may take several minutes, your code should also output the messages
* "5% sorted." "10% sorted." etc. every time i is an exact multiple of 10000,
* where i is the outer loop variable.
* (Use 100*i/numWords to get the percent.)
*/
void sortWordsArray(WordPair words[], int numWords);
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