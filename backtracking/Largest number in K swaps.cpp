//Naive Solution:
/*
Approach: The idea is to consider every digit and swap it with digits following it one at a time and see if it leads to the maximum number. The process is repeated K times. The code can be further optimized, if the current digit is swapped with a digit less than the following digit.
*/
// C++ program to find maximum
// integer possible by doing
// at-most K swap operations
// on its digits.
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum
// integer possible by
// doing at-most K swap
// operations on its digits
void findMaximumNum(
    string str, int k, string& max)
{
    // Return if no swaps left
    if (k == 0)
        return;

    int n = str.length();

    // Consider every digit
    for (int i = 0; i < n - 1; i++) {

        // Compare it with all digits after it
        for (int j = i + 1; j < n; j++) {
            // if digit at position i
            // is less than digit
            // at position j, swap it
            // and check for maximum
            // number so far and recurse
            // for remaining swaps
            if (str[i] < str[j]) {
                // swap str[i] with str[j]
                swap(str[i], str[j]);

                // If current num is more
                // than maximum so far
                if (str.compare(max) > 0)
                    max = str;

                // recurse of the other k - 1 swaps
                findMaximumNum(str, k - 1, max);

                // Backtrack
                swap(str[i], str[j]);
            }
        }
    }
}

// Driver code
int main()
{
    string str = "129814999";

    int k = 4;

    string max = str;
    findMaximumNum(str, k, max);

    cout << max << endl;

    return 0;
}

/*
Output: 
999984211

 

Complexity Analysis:  


Time Complexity: O((n^2)^k). 
For every recursive call n^2 recursive calls is generated until the value of k is 0. So total recursive calls are O((n^2)^k).
Space Complexity:O(n). 
This is the space required to store the output string.
*/


/*
//Efficient Solution:
/*
Approach: The above approach traverses the whole string at each recursive call which is highly inefficient and unnecessary. Also, pre-computing the maximum digit after the current at a recursive call avoids unnecessary exchanges with each digit. It can be observed that to make the maximum string, the maximum digit is shifted to the front. So, instead of trying all pairs, try only those pairs where one of the elements is the maximum digit which is not yet swapped to the front. 
There is an improvement by 27580 microseconds for each test case.
*/
// C++ program to find maximum
// integer possible by doing
// at-most K swap operations on
// its digits.
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum
// integer possible by
// doing at-most K swap operations
// on its digits
void findMaximumNum(
    string str, int k,
    string& max, int ctr)
{
    // return if no swaps left
    if (k == 0)
        return;

    int n = str.length();

    // Consider every digit after
    // the cur position
    char maxm = str[ctr];
    for (int j = ctr + 1; j < n; j++) {
        // Find maximum digit greater
        // than at ctr among rest
        if (maxm < str[j])
            maxm = str[j];
    }

    // If maxm is not equal to k,
    // decrement k
    if (maxm != str[ctr])
        --k;

    // search this maximum among the rest
    for (int j = ctr; j < n; j++) {
        // If digit equals maxm swap
        // the digit with current
        // digit and recurse for the rest
        if (str[j] == maxm) {
            // swap str[ctr] with str[j]
            swap(str[ctr], str[j]);

            // If current num is more than
            // maximum so far
            if (str.compare(max) > 0)
                max = str;

            // recurse other swaps after cur
            findMaximumNum(str, k, max, ctr + 1);

            // Backtrack
            swap(str[ctr], str[j]);
        }
    }
}

// Driver code
int main()
{
    string str = "129814999";
    int k = 4;

    string max = str;
    findMaximumNum(str, k, max, 0);

    cout << max << endl;

    return 0;
}
/*
Output: 
999984211

 

Complexity Analysis:  


Time Complexity: O(n^k). 
For every recursive call n recursive calls is generated until the value of k is 0. So total recursive calls are O((n)^k).
Space Complexity: O(n). 
The space required to store the output string.
*/
*/