#include <iostream>
using namespace std;

const int N = 10;
const int VIVO = 0;
const int QUEMANDOSE = 1;
const int QUEMADO = 2;

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1,  0,  1,-1, 1,-1, 0, 1};

// Mostrar la matriz
void mostrarBosque(int bosque[N][N], string mensaje) {
    cout << "\n" << mensaje << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << bosque[i][j] << " ";
        }
        cout << endl;
    }
}

// Verifica si una celda tiene vecino que se está quemando
bool tieneVecinoQuemando(int bosque[N][N], int fila, int col) {
    for (int k = 0; k < 8; k++) {
        int nf = fila + dx[k];
        int nc = col + dy[k];
        if (nf >= 0 && nf < N && nc >= 0 && nc < N) {
            if (bosque[nf][nc] == QUEMANDOSE)
                return true;
        }
    }
    return false;
}

// Verifica si queda algún árbol quemándose
bool hayFuego(int bosque[N][N]) {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (bosque[i][j] == QUEMANDOSE)
                return true;
    return false;
}

int main() {
    int bosque[N][N];

    // Llenamos el bosque con árboles vivos (0)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            bosque[i][j] = VIVO;

    mostrarBosque(bosque, "Bosque inicial");

    int fila, columna;
    cout << "\nElige donde comienza el fuego." << endl;
    do {
        cout << "Fila (0 al 9): ";
        cin >> fila;
    } while (fila < 0 || fila >= N);

    do {
        cout << "Columna (0 al 9): ";
        cin >> columna;
    } while (columna < 0 || columna >= N);

    bosque[fila][columna] = QUEMANDOSE;

    mostrarBosque(bosque, "Despues de encender fuego");

    int iteracion = 1;

    while (hayFuego(bosque)) {
        int siguiente[N][N];

        // Actualizamos cada celda
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (bosque[i][j] == VIVO && tieneVecinoQuemando(bosque, i, j)) {
                    siguiente[i][j] = QUEMANDOSE;
                } else if (bosque[i][j] == QUEMANDOSE) {
                    siguiente[i][j] = QUEMADO;
                } else {
                    siguiente[i][j] = bosque[i][j];
                }
            }
        }

        // Copiar el bosque actualizado
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                bosque[i][j] = siguiente[i][j];

        cout << "\nIteracion " << iteracion++ << ":";
        mostrarBosque(bosque, "Estado del bosque");
    }

    cout << "\n?? El fuego se ha propagado por completo. Fin de la simulación.\n";

    return 0;
}


