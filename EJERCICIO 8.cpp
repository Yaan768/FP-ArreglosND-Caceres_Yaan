#include <iostream>
using namespace std;

const int N = 5;

int main() {
    int matriz[N][N];

    // Ingreso de datos
    cout << "Ingrese los elementos de la matriz 5x5:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Mostrar la matriz ingresada
    cout << "\nMatriz ingresada:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Recorrido en espiral
    cout << "\nRecorrido en espiral:\n";
    int filaInicio = 0, filaFin = N - 1;
    int colInicio = 0, colFin = N - 1;

    while (filaInicio <= filaFin && colInicio <= colFin) {
        // Recorre la fila superior
        for (int col = colInicio; col <= colFin; col++) {
            cout << matriz[filaInicio][col] << " ";
        }
        filaInicio++;

        // Recorre la columna derecha
        for (int fila = filaInicio; fila <= filaFin; fila++) {
            cout << matriz[fila][colFin] << " ";
        }
        colFin--;

        // Recorre la fila inferior (si queda)
        if (filaInicio <= filaFin) {
            for (int col = colFin; col >= colInicio; col--) {
                cout << matriz[filaFin][col] << " ";
            }
            filaFin--;
        }

        // Recorre la columna izquierda (si queda)
        if (colInicio <= colFin) {
            for (int fila = filaFin; fila >= filaInicio; fila--) {
                cout << matriz[fila][colInicio] << " ";
            }
            colInicio++;
        }
    }

    cout << endl;
    return 0;
}

