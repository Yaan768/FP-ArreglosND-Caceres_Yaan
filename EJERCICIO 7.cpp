#include <iostream>
using namespace std;

const int N = 4;

int main() {
    int matriz[N][N];
    int rotada[N][N];

    // Ingreso de la matriz
    cout << "Ingrese los valores de la matriz 4x4:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Rotar 90 grados en sentido horario
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            rotada[j][N - 1 - i] = matriz[i][j];
        }
    }

    // Mostrar la matriz original
    cout << "\nMatriz original:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Mostrar la matriz rotada
    cout << "\nMatriz rotada 90 grados en sentido horario:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << rotada[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

