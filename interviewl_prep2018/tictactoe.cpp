#include <iostream>
#include <vector>

using namespace std;

class Board {
public:
    enum Player {
        X,
        O
    };

    Board() {
        board = vector<vector<char>>(3, vector<char>(3, '-'));
    }

    void printBoard() {
        for(auto row : board) {
            for(int i = 0; i < row.size(); i++) {
                cout << row[i] << ((i != row.size() - 1) ? "|" : "");
            }
            cout << endl;
        }
    }

    bool placeToken(unsigned int x, unsigned int y, Player p) {
        if(x >= 3 || y >= 3 || board[x][y] != '-') {
            return false;
        }

        board[x][y] = p == X ? 'X' : 'O';
        return true;
    }

    bool boardFull() {
       for(auto& row : board) {
            for(int i = 0; i < row.size(); i++) {
                if(row[i] == '-') {
                    return false;
                }
            }
        } 

        return true;
    }

    bool moveAi() {
       for(int i = 0; < board.size(); i++) {
            for(int i = 0; i < row.size(); i++) {
                if(row[i] == '-') {
                    placeToken()
                    return true;
                }
            }
        } 
        return false;
    }

private:
    vector<vector<char>> board;
};

int main() {
    Board board;
    board.printBoard();
    board.placeToken(0, 1, Board::Player::X);
    board.printBoard();

    return 0;
}