#include <iostream>

#define QUEEN '*'
#define EMPTY '.'
#define DIM 15

using namespace std;

class Solver {
public:

    Solver(){
        for(auto & i : mat){
            for (char & j : i) {
                j='.';
            }
        }
    }

    int getSolutions(){
        return solutions;
    }

    void printmat(){
        string str = "\n";
        for (auto & i: mat) {
            for (char j : i) {
                str+= j;
                str+= " ";
            }
            str+="\n";
        }
        cout << str;
    }

    bool solve(int i){
        if(placed == DIM) {
            solutions++;
            return false;
        }

        for (int j = 0; j < DIM; ++j) {

            if (check(i, j)) {
                mat[i][j] = QUEEN;
                placed++;
                if (solve(i + 1)) return true;
                mat[i][j] = EMPTY;
                placed--;
            }
        }
        return false;
    }

private:

    bool check(int i, int j){
        for(int row = 0; row < DIM; ++row){
            for(int col = 0; col < DIM; ++col){
                if(row+col == i+j || row-col ==i-j || row == i || col == j) {
                    if (mat[row][col] == QUEEN) {
                        return false;
                    }
                }
            }
        }
        return true;
    }

    char mat[DIM][DIM];
    int placed = 0;
    int solutions = 0;
};

int main() {

    char tablero[DIM][DIM];

    for(auto & i : tablero){
        for (char & j : i) {
            j=EMPTY;
        }
    }

    Solver solver;
    solver.solve(0);
    cout << "Number of solutions: " << solver.getSolutions() << endl << endl;
}
