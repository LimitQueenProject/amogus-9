#include <stdio.h>
#include <stdbool.h>

#include "header.h"

char player = 'O', opponent = 'X';
void pilihIndexKomputer(int _flag, int *_baris, int *_kolom, char _papan[7][7])
{

	Move bestMove = findBestMove(_flag, _papan);
	*_baris = bestMove.row;
	*_kolom = bestMove.col;
}

int _max(int v1, int v2)
{
	if (v1 > v2)
	{
		return v1;
	}
	else
		return v2;
}

int _min(int v1, int v2)
{
	if (v1 < v2)
	{
		return v1;
	}
	else
		return v2;
}

Move findBestMove(int _flag, char _papan[7][7])
{
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	// Traverse all cells, evaluate minimax function for
	// all empty cells. And return the cell with optimal
	// value.
	for (int i = 0; i < _flag; i++)
	{
		for (int j = 0; j < _flag; j++)
		{
			// Mengecek apakah kotak masih kosong
			if (_papan[i][j] == ' ')
			{
				// Make the move
				_papan[i][j] = player;

				// compute evaluation function for this
				// move.
				int moveVal = minimax(_flag, _papan, 0, false);

				// Undo the move
				_papan[i][j] = ' ';

				// If the value of the current move is
				// more than the best value, then update
				// best/
				if (moveVal > bestVal)
				{
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
				}
			}
		}
	}

	return bestMove;
}

int minimax(int _flag, char _papan[7][7], int depth, bool isMax)
{
	int score = evaluate(_flag, _papan);

	// If Maximizer has won the game return his/her
	// evaluated score
	if (score == 10)
		return score;

	// If Minimizer has won the game return his/her
	// evaluated score
	if (score == -10)
		return score;

	// If there are no more moves and no winner then
	// it is a tie
	if (isMovesLeft(_papan) == false)
		return 0;

	// If this maximizer's move
	if (isMax)
	{
		int best = -1000;

		// Traverse all cells
		for (int i = 0; i < _flag; i++)
		{
			for (int j = 0; j < _flag; j++)
			{
				// Check if cell is empty
				if (_papan[i][j] == ' ')
				{
					// Make the move
					_papan[i][j] = player;

					// Call minimax recursively and choose
					// the maximum value
					best = max(best,
							   minimax(_flag, _papan, depth + 1, !isMax));

					// Undo the move
					_papan[i][j] = ' ';
				}
			}
		}
		return best;
	}

	// If this minimizer's move
	else
	{
		int best = 1000;

		// Traverse all cells
		for (int i = 0; i < _flag; i++)
		{
			for (int j = 0; j < _flag; j++)
			{
				// Check if cell is empty
				if (_papan[i][j] == ' ')
				{
					// Make the move
					_papan[i][j] = opponent;

					// Call minimax recursively and choose
					// the minimum value
					best = min(best,
							   minimax(_flag, _papan, depth + 1, !isMax));

					// Undo the move
					_papan[i][j] = ' ';
				}
			}
		}
		return best;
	}
}

bool isMovesLeft(char _papan[7][7])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (_papan[i][j] == ' ')
				return true;
	return false;
}

int evaluate(int _flag, char b[7][7])
{
	// Checking for Rows for X or O victory.
	for (int row = 0; row < _flag; row++)
	{
		if (b[row][0] == b[row][1] &&
			b[row][1] == b[row][2])
		{
			if (b[row][0] == player)
				return +10;
			else if (b[row][0] == opponent)
				return -10;
		}
	}

	// Checking for Columns for X or O victory.
	for (int col = 0; col < _flag; col++)
	{
		if (b[0][col] == b[1][col] &&
			b[1][col] == b[2][col])
		{
			if (b[0][col] == player)
				return +10;

			else if (b[0][col] == opponent)
				return -10;
		}
	}

	// Checking for Diagonals for X or O victory.
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2])
	{
		if (b[0][0] == player)
			return +10;
		else if (b[0][0] == opponent)
			return -10;
	}

	if (b[0][2] == b[1][1] && b[1][1] == b[2][0])
	{
		if (b[0][2] == player)
			return +10;
		else if (b[0][2] == opponent)
			return -10;
	}

	// Else if none of them have won then return 0
	return 0;
}