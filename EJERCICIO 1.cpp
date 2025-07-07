#include <iostream>
using namespace std;

const int N = 3;

void ingresarMatriz(int matriz[N][N], char nombre) {
    cout << "Ingrese los valores de la Matriz " << nombre << " (" << N << "x" << N << "):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << nombre << "[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void mostrarMatrizHorizontal(int A[N][N], int B[N][N], int R[N][N]) {
    cout << "\nMatriz A\tMatriz B\tResultado:\n";
    for (int i = 0; i < N; i++) {
        // Mostrar fila de A
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << "\t";
        }
        cout << "\t";
        // Mostrar fila de B
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << "\t";
        }
        cout << "\t";
        // Mostrar fila de R
        for (int j = 0; j < N; j++) {
            cout << R[i][j] << "\t";
        }
        cout << endl;
    }
}

void multiplicarMatrices(int A[N][N], int B[N][N], int R[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            R[i][j] = 0;
            for (int k = 0; k < N; k++) {
                R[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int A[N][N], B[N][N], R[N][N];

    ingresarMatriz(A, 'A');
    ingresarMatriz(B, 'B');

    multiplicarMatrices(A, B, R);

    mostrarMatrizHorizontal(A, B, R);

    return 0;
}

