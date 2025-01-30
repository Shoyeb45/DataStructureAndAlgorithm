#include <bits/stdc++.h>
using namespace std;

template<typename t>
std::ostream& operator<<(std::ostream& os, vector<t> &vec) {
    for (auto x : vec) {
        os << x << " ";
    }
    os << "\n";
    return os; 
}

bool valid(vector<vector<int>> &chessboard, int row, int column) {
    for (int i = row - 1; i >= 0; i--) {
        if (chessboard[i][column] == 1) {
            return false;
        }
    }

    for (int i = row - 1, j = column + 1; i >= 0 && j < chessboard.size(); i--, j++) {
        if (chessboard[i][j] == 1) {  
            return false;
        }
    }

    for (int i = row - 1, j = column - 1; i >= 0 && j >= 0; i--, j--) {
        if (chessboard[i][j] == 1) {  
            return false;
        }
    }

    return true;
}

void printChessboard(const vector<vector<int>> &chessboard) {
    for (const auto &row : chessboard) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void printAllCombination(vector<vector<int>> &chessboard, int rowIndex) {
    if (rowIndex >= chessboard.size()) {
        printChessboard(chessboard);
        return;
    }

    for (int i = 0; i < chessboard.size(); i++) {
        if (valid(chessboard, rowIndex, i)) {
            chessboard[rowIndex][i] = 1;
            printAllCombination(chessboard, rowIndex + 1);
            chessboard[rowIndex][i] = 0;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> chessboard(n, vector<int>(n, 0));
    printAllCombination(chessboard, 0);
    return 0;
}
