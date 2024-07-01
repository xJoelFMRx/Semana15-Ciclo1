#include "pch.h"
#include "iostream"

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int ValidarN()
{
    int N;
    do
    {
        cout << "Ingrese dimension de la matriz: "; cin >> N;
    } while (N < 3 || N > 30);
    cout << endl;
    return N;
}

int** GenerarMatriz(int N)
{
    int** Matriz = new int* [N];
    for (int i = 0; i < N; i++)
    {
        Matriz[i] = new int[N];
    }
    return Matriz;
}

void DatosMatriz(int** Matriz, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Matriz[i][j] = RandInt(0, 9);
        }
    }
}

void MostrarMatriz(int** Matriz, int N)
{
    cout << "Matriz Generada" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << Matriz[i][j] << ' ';
        }
        cout << endl;
    }
}

int ValidarPatron()
{
    int Patron;
    do
    {
        cout << endl << "Ingrese Patron numerico: "; cin >> Patron;
    } while (Patron < 100 || Patron > 999);
    return Patron;
}

void MostrarMatrizResaltada(int** Matriz, int N, int Patron)
{
    int p1 = Patron / 100;
    int p2 = (Patron / 10) % 10;
    int p3 = Patron % 10;

    cout << endl << "Matriz Resaltada" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j <= N - 3 && Matriz[i][j] == p1 && Matriz[i][j + 1] == p2 && Matriz[i][j + 2] == p3)
            {
                Console::BackgroundColor = ConsoleColor::Yellow;
                Console::ForegroundColor = ConsoleColor::Black;
                cout << Matriz[i][j] << ' ';
                cout << Matriz[i][j + 1] << ' ';
                cout << Matriz[i][j + 2] << ' ';
                j += 2;
                Console::ResetColor();
            }
            else
            {
                cout << Matriz[i][j] << ' ';
            }
        }
        cout << endl;
    }
}

void ContarPatron(int** Matriz, int N, int Patron)
{
    int cont = 0;
    int p1 = Patron / 100;
    int p2 = (Patron / 10) % 10;
    int p3 = Patron % 10;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N - 3; j++)
        {
            if (Matriz[i][j] == p1 && Matriz[i][j + 1] == p2 && Matriz[i][j + 2] == p3)
            {
                cont++;
            }
        }
    }
    cout << endl << "El numero de veces que se repite el patron es: " << cont;
}

void LiberarMatriz(int** Matriz, int N)
{
    for (int i = 0; i < N; i++)
    {
        delete[] Matriz[i];
    }
    delete[] Matriz;
}

int main()
{
    srand(time(nullptr));
    int N = ValidarN();
    int** Matriz;
    Matriz = GenerarMatriz(N);

    DatosMatriz(Matriz, N);
    MostrarMatriz(Matriz, N);
    int Patron = ValidarPatron();
    MostrarMatrizResaltada(Matriz, N, Patron);
    ContarPatron(Matriz, N, Patron);

    LiberarMatriz(Matriz, N);

    system("pause>0");
    return 0;
}