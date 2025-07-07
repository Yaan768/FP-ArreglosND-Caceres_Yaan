#include <iostream>
using namespace std;

const int FILAS = 6;
const int COLUMNAS = 6;

int main() {
    int matriz[FILAS][COLUMNAS];

    // Ingreso de matriz
    cout << "Ingresa los valores de la matriz 6x6:\n";
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Reflejo horizontal: intercambiar elementos de cada fila
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS / 2; j++) {
            int temp = matriz[i][j];
            matriz[i][j] = matriz[i][COLUMNAS - 1 - j];
            matriz[i][COLUMNAS - 1 - j] = temp;
        }
    }

    // Mostrar matriz reflejada
    cout << "\nMatriz reflejada horizontalmente:\n";
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

