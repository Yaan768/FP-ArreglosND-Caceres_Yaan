#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Ingrese el orden del cuadrado latino (N): ";
    cin >> n;

    int matriz[n][n];

    // Generar el cuadrado latino
    for (int fila = 0; fila < n; fila++) {
        for (int col = 0; col < n; col++) {
            matriz[fila][col] = (col + fila) % n + 1;
        }
    }

    // Mostrar el cuadrado latino
    cout << "\nCuadrado latino de orden " << n << ":\n";
    for (int fila = 0; fila < n; fila++) {
        for (int col = 0; col < n; col++) {
            cout << matriz[fila][col] << " ";
        }
        cout << endl;
    }

    return 0;
}

