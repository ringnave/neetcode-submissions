class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            vector<char> row = board[i];
            sort(row.begin(), row.end());
            for (int j = 1; j < 9; ++j) {
                if (row[j] != '.' && row[j - 1] != '.' && row[j] == row[j - 1]) {
                    cout << 'a' << endl;
                    return false;
                }
            }
        }

        for (int i = 0; i < 9; ++i) {
            vector<char> col(9);
            for (int j = 0; j < 9; ++j) {
                col[j] = board[j][i];
                cout << col[j] << ' ' << board[j][i] << '\n';
            }
            cout << "-----" << '\n';
            cout << col[0] << '\n';
            cout << col[1] << '\n';
            cout << col[2] << '\n';
            cout << col[3] << '\n';
            cout << col[4] << '\n';
            cout << col[5] << '\n';
            cout << col[6] << '\n';
            cout << col[7] << '\n';
            cout << col[8] << '\n';
            cout << "-----" << '\n';
            sort(col.begin(), col.end());

            cout << col[0] << '\n';
            cout << col[1] << '\n';
            cout << col[2] << '\n';
            cout << col[3] << '\n';
            cout << col[4] << '\n';
            cout << col[5] << '\n';
            cout << col[6] << '\n';
            cout << col[7] << '\n';
            cout << col[8] << '\n';
            for (int j = 1; j < 9; ++j) {
                if (col[j] != '.' && col[j - 1] != '.' && col[j] == col[j - 1]) {
                    return false;
                }
            }
        }

        int i{0}, j{0};
        while (i < 9) {
            int i1{i}, i2{i + 1}, i3{i + 2};

            while (j < 9) {
                int j1{j}, j2{j + 1}, j3{j + 2};
                vector<char> line(9);
                line[0] = board[i1][j1];
                line[1] = board[i1][j2];
                line[2] = board[i1][j3];
                line[3] = board[i2][j1];
                line[4] = board[i2][j2];
                line[5] = board[i2][j3];
                line[6] = board[i3][j1];
                line[7] = board[i3][j2];
                line[8] = board[i3][j3];

                sort(line.begin(), line.end());
                for (int k = 1; k < 9; ++k) {
                    if (line[k] != '.' && line[k - 1] != '.' && line[k] == line[k - 1]) {
                        cout << 'c' << endl;
                        return false;
                    }
                }

                j += 3;
            }

            i += 3;
        }

        return true;
    }
};
