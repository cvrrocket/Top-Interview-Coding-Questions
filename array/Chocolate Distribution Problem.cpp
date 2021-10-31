#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int findMinDiff(int arr[], int n, int m){
    int ans=INT_MAX;
    
    // if there are no chocolates or number
    // of students is 0
    if (m == 0 || n == 0)
        return 0;
 
    // Sort the given packets
    sort(arr, arr + n);
 
    // Number of students cannot be more than
    // number of packets
    if (n < m)
        return -1;
    
    // Find the subarray of size m such that
    // difference between last (maximum in case
    // of sorted) and first (minimum in case of
    // sorted) elements of subarray is minimum.
    for(int i=0;i+m-1<n;i++){
        int diff=arr[i+m-1]-arr[i];
        ans=min(ans,diff);
        //if(ans>diff) ans=diff
    }
    
    return ans;
}

int main(){
   int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << findMinDiff(arr, n, m);
    return 0; 
}


//Java


// JAVA Code For Chocolate Distribution
// Problem
import java.util.*;
 
class GFG {
     
    // arr[0..n-1] represents sizes of
    // packets. m is number of students.
    // Returns minimum difference between
    // maximum and minimum values of
    // distribution.
    static int findMinDiff(int arr[], int n,
                                    int m)
    {
        // if there are no chocolates or
        // number of students is 0
        if (m == 0 || n == 0)
            return 0;
      
        // Sort the given packets
        Arrays.sort(arr);
      
        // Number of students cannot be
        // more than number of packets
        if (n < m)
           return -1;
      
        // Largest number of chocolates
        int min_diff = Integer.MAX_VALUE;
      
        // Find the subarray of size m
        // such that difference between
        // last (maximum in case of
        // sorted) and first (minimum in
        // case of sorted) elements of
        // subarray is minimum.
         
        for (int i = 0; i + m - 1 < n; i++)
        {
            int diff = arr[i+m-1] - arr[i];
            if (diff < min_diff)
                min_diff = diff;
        }
        return min_diff;
    }
     
    /* Driver program to test above function */
    public static void main(String[] args)
    {
        int arr[] = {12, 4, 7, 9, 2, 23,
                    25, 41, 30, 40, 28,
                    42, 30, 44, 48, 43,
                   50};
                    
        int m = 7;  // Number of students
         
        int n = arr.length;
        System.out.println("Minimum difference is "
                + findMinDiff(arr, n, m));
             
    }
}


//Python


# Python3 program to solve
# chocolate distribution
# problem
 
 
# arr[0..n-1] represents sizes of packets
# m is number of students.
# Returns minimum difference between maximum
# and minimum values of distribution.
def findMinDiff(arr, n, m):
 
    # if there are no chocolates or number
    # of students is 0
    if (m==0 or n==0):
        return 0
 
    # Sort the given packets
    arr.sort()
 
    # Number of students cannot be more than
    # number of packets
    if (n < m):
        return -1
 
    # Largest number of chocolates
    min_diff = arr[n-1] - arr[0]
 
    # Find the subarray of size m such that
    # difference between last (maximum in case
    # of sorted) and first (minimum in case of
    # sorted) elements of subarray is minimum.
    for i in range(len(arr) - m + 1):
        min_diff = min(min_diff ,  arr[i + m - 1] - arr[i])
     
         
    return min_diff
 
# Driver Code
if __name__ == "__main__":
    arr = [12, 4, 7, 9, 2, 23, 25, 41,
          30, 40, 28, 42, 30, 44, 48,
          43, 50]
    m = 7 # Number of students
    n = len(arr)
    print("Minimum difference is", findMinDiff(arr, n, m))

