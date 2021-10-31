#include<iostream>
#include <bits/stdc++.h>
using namespace std;
const int MOD=1000000007;//10e8+7
#define MAX 5


// Function returns true if the
// move taken is valid else
// it will return false.
bool isSafe(int row, int col, int m[][MAX],
                 int n, bool visited[][MAX])
{
    if (row == -1 || row == n || col == -1 ||
                  col == n || visited[row][col]
                           || m[row][col] == 0)
        return false;
 
    return true;
}

// Function to print all the possible
// paths from (0, 0) to (n-1, n-1).
void printPathUtil(int row, int col, int m[][MAX],
              int n, string& path, vector<string>&
               possiblePaths, bool visited[][MAX]){
    
    // This will check the initial point
    // (i.e. (0, 0)) to start the paths.
    if (row == -1 || row == n || col == -1
               || col == n || visited[row][col]
                           || m[row][col] == 0)
        return;
    
    // If reach the last cell (n-1, n-1)
    // then store the path and return
    if(row==n-1 && col==n-1){
        possiblePaths.push_back(path)
        return;
    }
    
    // Mark the cell as visited
    visited[row][col] = true;
    
    // Try for all the 4 directions (down, left,
    // right, up) in the given order to get the
    // paths in lexicographical order
 
    // Check if downward move is valid
    if (isSafe(row + 1, col, m, n, visited))
    {
        path.push_back('D');
        printPathUtil(row + 1, col, m, n,
                 path, possiblePaths, visited);
        path.pop_back();
    }
 
    // Check if the left move is valid
    if (isSafe(row, col - 1, m, n, visited))
    {
        path.push_back('L');
        printPathUtil(row, col - 1, m, n,
                   path, possiblePaths, visited);
        path.pop_back();
    }
 
    // Check if the right move is valid
    if (isSafe(row, col + 1, m, n, visited))
    {
        path.push_back('R');
        printPathUtil(row, col + 1, m, n,
                   path, possiblePaths, visited);
        path.pop_back();
    }
 
     // Check if the upper move is valid
    if (isSafe(row - 1, col, m, n, visited))
    {
        path.push_back('U');
        printPathUtil(row - 1, col, m, n,
               path, possiblePaths, visited);
        path.pop_back();
    }
 
    // Mark the cell as unvisited for
    // other possible paths
    visited[row][col] = false;
}

// Function to store and print
// all the valid paths
void printPath(int m[MAX][MAX], int n){
    bool visited[n][MAX];
    vector<string> allPossiblePaths;
    string path;
    memset(visited, false, sizeof(visited));
    
    // Call the utility function to
    // find the valid paths
    printPathUtil(0, 0, m, n, path,
                      allPossiblePaths, visited);
 
    // Print all possible paths
    for (int i = 0; i < allPossiblePaths.size(); i++)
        cout << allPossiblePaths[i] << " ";
    
}

int main(){
    int m[MAX][MAX] = { { 1, 0, 0, 0, 0 },
                        { 1, 1, 1, 1, 1 },
                        { 1, 1, 1, 0, 1 },
                        { 0, 0, 0, 0, 1 },
                        { 0, 0, 0, 0, 1 } };
    int n = sizeof(m) / sizeof(m[0]);
    printPath(m, n);
 
    return 0;
}

/*
Complexity Analysis: 

Time Complexity: O(3^(n^2)). 
As there are N^2 cells from each cell there are 3 unvisited neighbouring cells. So the time complexity O(3^(N^2).
Auxiliary Space: O(3^(n^2)). 
As there can be atmost 3^(n^2) cells in the answer so the space complexity is O(3^(n^2)).

Output: 
DDRRURRDDD DDRURRRDDD DRDRURRDDD DRRRRDDD
*/

/*

/* C++ program to solve Rat in
a Maze problem using backtracking */
#include <stdio.h>
 
// Maze size
#define N 4
 
bool solveMazeUtil(
    int maze[N][N], int x,
    int y, int sol[N][N]);
 
/* A utility function to print
solution matrix sol[N][N] */
void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}
 
/* A utility function to check if x,
y is valid index for N*N maze */
bool isSafe(int maze[N][N], int x, int y)
{
    // if (x, y outside maze) return false
    if (
        x >= 0 && x < N && y >= 0
        && y < N && maze[x][y] == 1)
        return true;
 
    return false;
}
 
/* This function solves the Maze problem
using Backtracking. It mainly uses
solveMazeUtil() to solve the problem.
It returns false if no path is possible,
otherwise return true and prints the path
in the form of 1s. Please note that there
may be more than one solutions, this
function prints one of the feasible
solutions.*/
bool solveMaze(int maze[N][N])
{
    int sol[N][N] = { { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 0, 0, 0 } };
 
    if (solveMazeUtil(
            maze, 0, 0, sol)
        == false) {
        printf("Solution doesn't exist");
        return false;
    }
 
    printSolution(sol);
    return true;
}
 

    
    /*
    Output: 
The 1 values show the path for rat 

 1  0  0  0 
 1  1  0  0 
 0  1  0  0 
 0  1  1  1
Complexity Analysis: 

Time Complexity: O(2^(n^2)). 
The recursion can run upper-bound 2^(n^2) times.
Space Complexity: O(n^2). 
Output matrix is required so an extra space of size n*n is needed.
    */





 









