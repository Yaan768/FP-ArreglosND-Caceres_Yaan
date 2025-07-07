#include <iostream>
using namespace std;

const int TAM = 4;

int main() {
    int matriz[TAM][TAM];
    int sumaPrincipal = 0;
    int sumaSecundaria = 0;

    // Ingreso de la matriz
    cout << "Ingrese los valores de la matriz 4x4:\n";
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Calcular suma de diagonales
    for (int i = 0; i < TAM; i++) {
        sumaPrincipal += matriz[i][i];                    // Diagonal principal
        sumaSecundaria += matriz[i][TAM - 1 - i];         // Diagonal secundaria
    }

    // Mostrar matriz
    cout << "\nMatriz ingresada:\n";
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    // Mostrar resultados
    cout << "\nSuma de la diagonal principal: " << sumaPrincipal << endl;
    cout << "Suma de la diagonal secundaria: " << sumaSecundaria << endl;

    return 0;
}

