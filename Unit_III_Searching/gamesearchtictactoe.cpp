#include <iostream>
#include <vector>
#include <climits>

using namespace std;

char player = 'X', opponent = 'O';

bool isMovesLeft(vector<vector<char>> &board) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == '_')
                return true;
    return false;
}

int evaluate(vector<vector<char>> &board) {
    for (int row = 0; row < 3; row++) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            if (board[row][0] == player)
                return +10;
            else if (board[row][0] == opponent)
                return -10;
        }
    }

    for (int col = 0; col < 3; col++) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            if (board[0][col] == player)
                return +10;
            else if (board[0][col] == opponent)
                return -10;
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == player)
            return +10;
        else if (board[0][0] == opponent)
            return -10;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == player)
            return +10;
        else if (board[0][2] == opponent)
            return -10;
    }

    return 0;
}

int minimax(vector<vector<char>> &board, int depth, bool isMax) {
    int score = evaluate(board);

    if (score == 10)
        return score;

    if (score == -10)
        return score;

    if (!isMovesLeft(board))
        return 0;

    if (isMax) {
        int best = INT_MIN;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = player;

                    best = max(best, minimax(board, depth + 1, !isMax));

                    board[i][j] = '_';
                }
            }
        }
        return best;
    } else {
        int best = INT_MAX;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    board[i][j] = opponent;

                    best = min(best, minimax(board, depth + 1, !isMax));

                    board[i][j] = '_';
                }
            }
        }
        return best;
    }
}

pair<int, int> findBestMove(vector<vector<char>> &board) {
    int bestVal = INT_MIN;
    pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                board[i][j] = player;

                int moveVal = minimax(board, 0, false);

                board[i][j] = '_';

                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

int main() {
    vector<vector<char>> board = {
        {'X', 'O', 'X'},
        {'_', 'O', '_'},
        {'_', '_', '_'}
    };

    pair<int, int> bestMove = findBestMove(board);
    cout << "The best move is: (" << bestMove.first << ", " << bestMove.second << ")" << endl;

    return 0;
}
