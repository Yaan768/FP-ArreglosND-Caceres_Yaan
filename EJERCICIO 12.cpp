#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int N = 10;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1,  0,  1,-1, 1,-1, 0, 1};

// Cuenta vecinos vivos
int contarVivos(int tablero[N][N], int fila, int col) {
    int vivos = 0;
    for (int k = 0; k < 8; k++) {
        int nf = fila + dx[k];
        int nc = col + dy[k];
        if (nf >= 0 && nf < N && nc >= 0 && nc < N) {
            if (tablero[nf][nc] == 1) vivos++;
        }
    }
    return vivos;
}

// Mostrar tablero
void mostrarTablero(int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    cout << "----------------------------\n";
}

// Avanza una generación
void siguienteGeneracion(int actual[N][N], int siguiente[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int vivos = contarVivos(actual, i, j);
            if (actual[i][j] == 1) {
                siguiente[i][j] = (vivos == 2 || vivos == 3) ? 1 : 0;
            } else {
                siguiente[i][j] = (vivos == 3) ? 1 : 0;
            }
        }
    }
}

int main() {
    srand(time(0));

    int tablero[N][N], aux[N][N];
    int generaciones;

    // Generación aleatoria inicial
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            tablero[i][j] = rand() % 2;

    cout << "TABLERO INICIAL:\n";
    mostrarTablero(tablero);

    cout << "¿Cuantas generaciones deseas simular?: ";
    cin >> generaciones;

    for (int gen = 1; gen <= generaciones; gen++) {
        siguienteGeneracion(tablero, aux);

        cout << "Generacion #" << gen << ":\n";
        mostrarTablero(aux);

        // Copiar aux tablero
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                tablero[i][j] = aux[i][j];
    }

    return 0;
}


