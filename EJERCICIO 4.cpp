#include <iostream>
using namespace std;

const int TAM = 4;

int main() {
    int matriz[TAM][TAM];

    // Ingreso de matriz
    cout << "Ingrese los valores de la matriz 4x4:\n";
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // matriz original
    cout << "\nMatriz original:\n";
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    // Pedir las filas a intercambiar
    int fila1, fila2;
    cout << "\nIngrese las dos filas que desea intercambiar (0 a 3):\n";
    cin >> fila1 >> fila2;

    if (fila1 < 0 || fila1 >= TAM || fila2 < 0 || fila2 >= TAM) {
        cout << "Filas inválidas. Deben estar entre 0 y 3.\n";
        return 1;
    }

    // Intercambio de filas
    for (int j = 0; j < TAM; j++) {
        int temp = matriz[fila1][j];
        matriz[fila1][j] = matriz[fila2][j];
        matriz[fila2][j] = temp;
    }

    // Mostrar matriz resultante
    cout << "\nMatriz después del intercambio:\n";
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}

