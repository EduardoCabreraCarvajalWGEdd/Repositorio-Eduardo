#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para generar una nueva pregunta
void generarPregunta(int &num1, int &num2) {
    num1 = rand() % 10 + 1; // Genera un número entre 1 y 10
    num2 = rand() % 10 + 1; // Genera un número entre 1 y 10
}

// Función para verificar la respuesta del estudiante
bool verificarRespuesta(int respuesta, int correcta) {
    return respuesta == correcta;
}

// Función para retroalimentación correcta
void retroalimentacionCorrecta() {
    string mensajesCorrectos[] = {"¡Muy bien!", "¡Excelente!", "¡Buen trabajo!", "¡Bravo, eres un campeón!"};
    int index = rand() % 4;
    cout << mensajesCorrectos[index] << endl;
}

// Función para retroalimentación incorrecta
void retroalimentacionIncorrecta() {
    string mensajesIncorrectos[] = {"¡Uf! No es correcta, por favor intenta de nuevo.", "Incorrecto. Intenta una vez más.", "¡No te rindas! Trata de nuevo.", "Tú puedes, sigue intentando."};
    int index = rand() % 4;
    cout << mensajesIncorrectos[index] << endl;
}

int main() {
    srand(time(0)); // Inicializa el generador de números aleatorios con el tiempo actual

    int numPreguntas = 15;
    int correctas = 0, incorrectas = 0;

    for (int i = 0; i < numPreguntas; ++i) {
        int num1, num2, respuesta, correcta, intentos = 3;
        bool esCorrecta = false;

        generarPregunta(num1, num2);
        correcta = num1 * num2;

        while (intentos > 0 && !esCorrecta) {
            cout << "¿Cuánto es " << num1 << " por " << num2 << "?" << endl;
            cin >> respuesta;

            if (verificarRespuesta(respuesta, correcta)) {
                retroalimentacionCorrecta();
                correctas++;
                esCorrecta = true;
            } else {
                retroalimentacionIncorrecta();
                intentos--;
                if (intentos == 0) {
                    cout << "La respuesta correcta es: " << correcta << endl;
                    incorrectas++;
                }
            }
        }
    }

    cout << "Resultados: " << endl;
    cout << "Correctas: " << correctas << endl;
    cout << "Incorrectas: " << incorrectas << endl;

    float rendimiento = (correctas / (float)numPreguntas) * 100;
    cout << "Rendimiento: " << rendimiento << "%" << endl;

    if (rendimiento <= 70) {
        cout << "Debes repetir el ejercicio." << endl;
    } else {
        cout << "¡Felicitaciones! Continúa con el siguiente nivel." << endl;
    }

    return 0;
}
