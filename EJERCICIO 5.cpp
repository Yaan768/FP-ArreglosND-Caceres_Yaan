#include <iostream>
using namespace std;

const int TAM = 4;

int main() {
    int matriz[TAM][TAM];

    // Ingreso de la matriz
    cout << "Ingrese los valores de la matriz 4x4:\n";
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Inicialización de variables para máximo y mínimo
    int max = matriz[0][0], min = matriz[0][0];
    int filaMax = 0, colMax = 0, filaMin = 0, colMin = 0;

    // Búsqueda de máximo y mínimo
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
                filaMax = i;
                colMax = j;
            }
            if (matriz[i][j] < min) {
                min = matriz[i][j];
                filaMin = i;
                colMin = j;
            }
        }
    }

    // Mostrar resultados
    cout << "\nEl valor mAximo es: " << max << " en posiciOn [" << filaMax << "][" << colMax << "]\n";
    cout << "El valor mInimo es: " << min << " en posiciOn [" << filaMin << "][" << colMin << "]\n";

    return 0;
}

