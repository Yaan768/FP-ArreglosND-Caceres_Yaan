#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 10;
const int MINA = 1;
const int VACIO = 0;

// Direcciones de las 8 celdas vecinas
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1,  0,  1,-1, 1,-1, 0, 1};

// Función para contar las minas alrededor de una celda
int contarMinas(int tablero[N][N], int fila, int columna) {
    int contador = 0;
    for (int i = 0; i < 8; i++) {
        int nuevaFila = fila + dx[i];
        int nuevaCol = columna + dy[i];
        if (nuevaFila >= 0 && nuevaFila < N && nuevaCol >= 0 && nuevaCol < N) {
            if (tablero[nuevaFila][nuevaCol] == MINA) {
                contador++;
            }
        }
    }
    return contador;
}

int main() {
    srand(time(0));

    int tablero[N][N];
    int tableroNumerico[N][N];

    // a) Generar aleatoriamente el tablero con minas (1) o vacío (0)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // 20% de probabilidad de que sea una mina
            tablero[i][j] = (rand() % 5 == 0) ? MINA : VACIO;
        }
    }

    // b) Calcular las minas vecinas para cada celda
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] == MINA) {
                tableroNumerico[i][j] = -1; // -1 representa una mina
            } else {
                tableroNumerico[i][j] = contarMinas(tablero, i, j);
            }
        }
    }

    // c) Mostrar tablero de minas y tablero de números juntos
    cout << "\nTABLERO DE MINAS\t\tTABLERO DE NUMEROS\n";
    for (int i = 0; i < N; i++) {
        // Mostrar tablero con minas (1 = mina, 0 = vacío)
        for (int j = 0; j < N; j++) {
            cout << tablero[i][j] << " ";
        }

        cout << "\t\t";

        // Mostrar tablero numérico (cuántas minas hay alrededor)
        for (int j = 0; j < N; j++) {
            if (tableroNumerico[i][j] == -1)
                cout << "1 "; // Mostramos 1 en lugar de asterisco para minas
            else
                cout << tableroNumerico[i][j] << " ";
        }

        cout << endl;
    }

    return 0;
}


