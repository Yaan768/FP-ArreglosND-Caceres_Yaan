#include <iostream>
using namespace std;

const int N = 3;

void ingresarMatriz(int matriz[N][N]) {
    cout << "Ingrese los valores de la matriz " << N << "x" << N << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Matriz[" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }
}

void buscarValor(int matriz[N][N], int valor) {
    bool encontrado = false;
    cout << "\nEl valor " << valor << " se encuentra en:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (matriz[i][j] == valor) {
                cout << "Fila " << i << ", Columna " << j << endl;
                encontrado = true;
            }
        }
    }

    if (!encontrado) {
        cout << "El valor no se encuentra en la matriz.\n";
    }
}

int main() {
    int matriz[N][N];
    int valor;

    ingresarMatriz(matriz);

    cout << "\nIngrese el valor a buscar: ";
    cin >> valor;

    buscarValor(matriz, valor);

    return 0;
}

