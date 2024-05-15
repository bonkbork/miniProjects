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
/**
* Print words that are anagrams for the target string.
* Here is a sample output where the target string is "tra"
* 3 matches were found. art rat tar.
* Here is a sample output where the target string is "abcde"
* 0 matches were found.
* How to code it:
* Declare local variables firstIndex and numberFound of type int.
* Call getMatches with words, numWords, target and firstIndex as the four arguments
* and assign the result of getMatches to numberFound.
* Output the number of matches that were found, e.g. "3 matches were found."
* Then, use a for-loop to output each match (if numberFound is bigger than 0).
**/
void printMatches(WordPair words[], int numWords, string target);
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
/**
* Sort w alphabetically by letter using selection sort.
* For example, if w is initially "hello" then after being sorted
* w will be "ehllo". Return w. For a full description see
* AnagramPart1.
**/
string sortWord(string w);
/**
* Open the file with the given fileName for input.
* If the file didn't open succesfully, return false.
* Otherwise, read each pair of strings from the file
* into the original and sorted fields of each element of
* the words array. Record the total number of pairs in
* parameter numwords. Return true.
**/
bool readWords(WordPair words[], int& numWords, string fileName);
/**
* Return
* Call binarySearch with sortWord(originalWord) as the target.
* The parameter first is used to store the return value.
* If first is -1 then no matches were found so return 0.
* Otherwise, first represents the index of a matching word
* but perhaps not the index of the first matching word among
* the sequence of words with the same sorted field.
* That means it's necessary to decrement first until we get to the first match.
* For example, if first is initially 5 and words[4] has the same sorted field
* as words[5], then we need decrement first to 4. If words[3] again has the
* same sorted field we need to decrement first again and so on.
* Next count the number of matches found by setting a local variable numMatches
* to 1, then incrementing it as long as words[first + numMatches] has the
* same sorted field. Return numMatches.
**/
int getMatches(WordPair words[], int numWords, string originalWord, int& first);
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
