#include "pch.h"
#include "iostream"
const int columnas = 3;
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
        cout << "Ingrese Numero de alumnos: "; cin >> N;
    } while (N < 1 || N > 20);
    return N;
}

struct Estudiantes
{
    char Gripe;
    char Tos;
    int Peso;
};

char RespuestasPosibles[2] = { 'S', 'N' };

void GenerayListaParalelos(Estudiantes* estudiante, int N)
{
    for (int i = 0; i < N; i++)
    {
        estudiante[i].Gripe = RespuestasPosibles[RandInt(0, 1)];
        estudiante[i].Tos = RespuestasPosibles[RandInt(0, 1)];
        estudiante[i].Peso = RandInt(30, 60);
    }
    for (int i = 0; i < N; i++)
    {
        cout << endl << "Alumno " << i + 1 << endl;
        cout << "Gripe: " << estudiante[i].Gripe << endl;
        cout << "Tos: " << estudiante[i].Tos << endl;
        cout << "Peso: " << estudiante[i].Peso << endl;
    }
    cout << endl;
    cout << "Resultados: " << endl;
}

void PorcentajeGripeTos(Estudiantes* estudiante, int N)
{
    int contGripeyTos = 0;
    double porcentajeGripeyTos = 0;
    for (int i = 0; i < N; i++)
    {
        if (estudiante[i].Gripe == 'S' && estudiante[i].Tos == 'S')
        {
            contGripeyTos++;
        }
    }
    if (N > 0)
    {
        porcentajeGripeyTos = (contGripeyTos * 100.0) / N;
    }
    cout << "Porcentaje de Alumnos con Gripe y Tos simultaneamente: " << porcentajeGripeyTos << "%" << endl;
}

void PromedioPesos(Estudiantes* estudiante, int N)
{
    int contTotalEnfermedad = 0;
    int SumaPesosEnfermedad = 0;
    double PromedioPesosEnfermedad = 0;
    for (int i = 0; i < N; i++)
    {
        if (estudiante[i].Gripe == 'S' || estudiante[i].Tos == 'S')
        {
            contTotalEnfermedad++;
            SumaPesosEnfermedad += estudiante[i].Peso;
        }
    }
    if (contTotalEnfermedad > 0)
    {
        PromedioPesosEnfermedad = (SumaPesosEnfermedad * 1.0) / contTotalEnfermedad;
    }
    cout << "Promedio del Peso de los Alumnos con alguna enfermedad: " << PromedioPesosEnfermedad << "kg" << endl;
}

int** GenerarMatriz(int N)
{
    int** Matriz = new int* [N];
    for (int i = 0; i < N; i++)
    {
        Matriz[i] = new int[columnas];
    }
    return Matriz;
}

void ListadoOrdenado(Estudiantes* estudiante, int N, int** Matriz)
{
    cout << "Listado ordenado: " << endl;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (estudiante[i].Peso < estudiante[j].Peso)
            {
                Estudiantes temp = estudiante[i];
                estudiante[i] = estudiante[j];
                estudiante[j] = temp;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        Matriz[i][0] = estudiante[i].Peso;
        Matriz[i][1] = estudiante[i].Gripe;
        Matriz[i][2] = estudiante[i].Tos;
    }
    cout << "\tPeso\tGripe\tTos" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "\t" << Matriz[i][0] << "\t" << (char)Matriz[i][1] << "\t" << (char)Matriz[i][2] << endl;
    }
}

void LiberarMatriz(int N, int** Matriz)
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
    Estudiantes* estudiante = new Estudiantes[N];

    GenerayListaParalelos(estudiante, N);
    PorcentajeGripeTos(estudiante, N);
    PromedioPesos(estudiante, N);

    int** Matriz;
    Matriz = GenerarMatriz(N);
    ListadoOrdenado(estudiante, N, Matriz);
    LiberarMatriz(N, Matriz);

    delete[] estudiante;

    system("pause>0");
    return 0;
}
