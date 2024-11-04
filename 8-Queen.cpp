#include <iostream>
#include <vector>
using namespace std;

const int N = 8;

// Function to print the board
void printBoard(vector<vector<int>> &board)
{
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      if (board[i][j] == 1)
        cout << "Q ";
      else
        cout << "- ";
    }
    cout << endl;
  }
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(vector<vector<int>> &board, int row, int col)
{
  // Check this column on the upper side
  for (int i = 0; i < row; i++)
    if (board[i][col] == 1)
      return false;

  // Check the upper left diagonal
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j] == 1)
      return false;

  // Check the upper right diagonal
  for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    if (board[i][j] == 1)
      return false;

  return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueens(vector<vector<int>> &board, int row)
{
  // If all queens are placed, return true
  if (row >= N)
    return true;

  // Consider each column in the current row
  for (int col = 0; col < N; col++)
  {
    // Check if it's safe to place the queen at board[row][col]
    if (isSafe(board, row, col))
    {
      // Place the queen
      board[row][col] = 1;

      // Recursively place the next queen
      if (solveNQueens(board, row + 1))
        return true;

      // If placing queen at board[row][col] doesn't lead to a solution,
      // backtrack by removing the queen from board[row][col]
      board[row][col] = 0;
    }
  }

  // If the queen cannot be placed in any column in this row, return false
  return false;
}

int main()
{
  // Initialize an 8x8 chessboard with all 0's
  vector<vector<int>> board(N, vector<int>(N, 0));

  // Place the first queen at (0, 0)
  board[0][0] = 1;

  // Call the backtracking function to place the remaining queens
  if (solveNQueens(board, 1))
  { // Start from row 1, since the first queen is placed at row 0
    cout << "Solution for 8-Queens problem:" << endl;
    printBoard(board);
  }
  else
  {
    cout << "No solution exists." << endl;
  }

  return 0;
}
