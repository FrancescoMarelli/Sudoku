#include <iostream>
#include <vector>

const short N = 9;
const short kSubgrid = 3;

class Sudoku  {
 private:
    std::vector <std::vector<short>> m_;
 public:
    Sudoku(std::vector <std::vector<short>> m) : m_(m) {}
    ~Sudoku() {}

    std::vector <std::vector<short>> get_m(void) const {
        return m_;
    }


    bool find_empty_cell(short& row, short& col) {
        for (row = 0; row < N; ++row) {
            for (col = 0; col < N; ++col) {
                if (m_[row][col] == 0) {
                    return true;
                }
            }
        }
        return false;
    }

    bool check_row( short row,  short num) {
        for (short col = 0; col < N; ++col) {
            if (m_[row][col] == num) {
                return false;
            }
        }
        return true;
    }

    bool check_col( short col,  short num) {
        for (short row = 0; row < N; ++row) {
            if (m_[row][col] == num) {
                return false;
            }
        }
        return true;
    }

    bool check_box( short startRow,  short startCol,  short num) {
        for (short row = 0; row < kSubgrid; ++row) {
            for (short col = 0; col < kSubgrid; ++col) {
                if (m_[startRow + row][startCol + col] == num)
                    return false;
            }
        }
        return true;
    }

    bool check_all( short row,  short col,  short num) {
        return check_row(row, num) && check_col(col, num) && check_box(row - row % kSubgrid, col - col % kSubgrid, num);
    }


    bool solve(void) {
        short row, col;
        if (!find_empty_cell(row, col)) {
            return true;
        }

        for (short num = 1; num <= N; ++num) {
            if (check_all(row, col, num)) {
                m_[row][col] = num;
                if (solve())
                    return true;
                m_[row][col] = 0;
            }
        }
        return false;
    }

    friend std::ostream& operator<<(std::ostream &os, const Sudoku &s);


};

std::ostream& operator<<(std::ostream &os, const Sudoku &s) {
    for (short row = 0; row < N; ++row) {
        for (short col = 0; col < N; ++col) {
            os << s.m_[row][col] << " ";
        }
        os << std::endl;
    }
    return os;
}

