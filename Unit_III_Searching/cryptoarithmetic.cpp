#include <iostream>
#include <vector>

using namespace std;

bool isValidSolution(int S, int E, int N, int D, int M, int O, int R, int Y) {
    int send = 1000 * S + 100 * E + 10 * N + D;
    int more = 1000 * M + 100 * O + 10 * R + E;
    int money = 10000 * M + 1000 * O + 100 * N + 10 * E + Y;

    return send + more == money;
}

void solveCrypto() {
    vector<int> digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    for (int S : digits)
        for (int E : digits)
            for (int N : digits)
                for (int D : digits)
                    for (int M : digits)
                        for (int O : digits)
                            for (int R : digits)
                                for (int Y : digits) {
                                    if (S != E && S != N && S != D && S != M && S != O && S != R && S != Y &&
                                        E != N && E != D && E != M && E != O && E != R && E != Y &&
                                        N != D && N != M && N != O && N != R && N != Y &&
                                        D != M && D != O && D != R && D != Y &&
                                        M != O && M != R && M != Y &&
                                        O != R && O != Y && R != Y) {
                                        if (isValidSolution(S, E, N, D, M, O, R, Y)) {
                                            cout << "Solution: SEND + MORE = MONEY" << endl;
                                            cout << S << E << N << D << " + " << M << O << R << E << " = " << M << O << N << E << Y << endl;
                                            return;
                                        }
                                    }
                                }
}

int main() {
    solveCrypto();
    return 0; //labs
}
