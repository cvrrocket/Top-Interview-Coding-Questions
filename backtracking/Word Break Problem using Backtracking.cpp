// A recursive program to print all possible
// partitions of a given string into dictionary
// words
#include <iostream>
using namespace std;
 
/* A utility function to check whether a word
  is present in dictionary or not.  An array of
  strings is used for dictionary.  Using array
  of strings for dictionary is definitely not
  a good idea. We have used for simplicity of
  the program*/
int dictionaryContains(string &word)
{
    string dictionary[] = {"mobile","samsung","sam","sung",
                            "man","mango", "icecream","and",
                            "go","i","love","ice","cream"};
    int n = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < n; i++)
        if (dictionary[i].compare(word) == 0)
            return true;
    return false;
}
 
// Prototype of wordBreakUtil
void wordBreakUtil(string str, int size, string result);
 
// Prints all possible word breaks of given string
void wordBreak(string str)
{
    // Last argument is prefix
    wordBreakUtil(str, str.size(), "");
}
 
// Result store the current prefix with spaces
// between words
void wordBreakUtil(string str, int n, string result)
{
    //Process all prefixes one by one
    for (int i=1; i<=n; i++)
    {
        // Extract substring from 0 to i in prefix
        string prefix = str.substr(0, i);
 
        // If dictionary conatins this prefix, then
        // we check for remaining string. Otherwise
        // we ignore this prefix (there is no else for
        // this if) and try next
        if (dictionaryContains(prefix))
        {
            // If no more elements are there, print it
            if (i == n)
            {
                // Add this element to previous prefix
                result += prefix;
                cout << result << endl;
                return;
            }
            wordBreakUtil(str.substr(i, n-i), n-i,
                                result + prefix + " ");
        }
    }     
}
 
//Driver Code
int main()
{
   
    // Function call
    cout << "First Test:\n";
    wordBreak("iloveicecreamandmango");
 
    cout << "\nSecond Test:\n";
    wordBreak("ilovesamsungmobile");
    return 0;
}
/*
Output
First Test:
i love ice cream and man go
i love ice cream and mango
i love icecream and man go
i love icecream and mango

Second Test:
i love sam sung mobile
i love samsung mobile
Complexities: 

Time Complexity: O(nn). Because there are nn combinations in The Worst Case.
Auxiliary Space: O(n2). Because of the Recursive Stack of wordBreakUtil(…) function in The Worst Case.
*/