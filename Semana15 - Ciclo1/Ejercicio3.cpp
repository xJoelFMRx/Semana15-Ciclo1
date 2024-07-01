#include "pch.h"
#include "iostream"
const int N = 30;
const int columnas = 3;

using namespace System;
using namespace std;

int RandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}


void GenerarDatos(int* CodigoVend, int Matriz[][columnas])
{
    for (int i = 0; i < N; i++)
    {
        CodigoVend[i] = 201 + i;
        Matriz[i][0] = RandInt(1, 60);
        Matriz[i][1] = RandInt(1, 90);
        Matriz[i][2] = RandInt(1, 70);
    }
}

void MostrarMatrizyArregloCod(int* CodigoVend, int Matriz[][columnas])
{
    Console::SetCursorPosition(0, 0);
    cout << " Codigo" << endl;
    Console::SetCursorPosition(0, 1);
    cout << "Vendedor" << endl;
    Console::SetCursorPosition(12, 0);
    cout << "Min llamadas" << endl;
    Console::SetCursorPosition(12, 1);
    cout << "  A fijo" << endl;
    Console::SetCursorPosition(28, 0);
    cout << "Min llamadas" << endl;
    Console::SetCursorPosition(28, 1);
    cout << " A celular" << endl;
    Console::SetCursorPosition(44, 0);
    cout << "Mensajes de" << endl;
    Console::SetCursorPosition(44, 1);
    cout << "   Texto" << endl;
    for (int i = 0; i < N; i++)
    {
        cout << ' ' << ' ' << CodigoVend[i];
        for (int j = 0; j < columnas; j++)
        {
            cout << "\t\t" << Matriz[i][j];
        }
        cout << endl;
    }
}

void CodigoVendedoresMayorCantidadMinLlamadasCelu(int* CodigoVend, int Matriz[][columnas])
{
    int max = Matriz[0][1];
    for (int i = 0; i < N; i++)
    {
        if (max < Matriz[i][1])
        {
            max = Matriz[i][1];
        }
    }
    cout << endl << "Codigo(s) de vendedor(es) con mayor cantidad de minutos de llamadas a celulares: ";
    for (int i = 0; i < N; i++)
    {
        if (max == Matriz[i][1])
        {
            cout << CodigoVend[i] << ' ';
        }
    }
    cout << endl;
}

void MontoTotalAPagarExcesoConsumo(int* CodigoVend, int Matriz[][columnas])
{
    double MontoTotalAlPagarExcesoConsumo;
    Console::SetCursorPosition(0, 35);
    cout << " Codigo" << endl;
    Console::SetCursorPosition(0, 36);
    cout << "Vendedor" << endl;
    Console::SetCursorPosition(12, 35);
    cout << "Min llamadas" << endl;
    Console::SetCursorPosition(12, 36);
    cout << "  A fijo" << endl;
    Console::SetCursorPosition(28, 35);
    cout << "Min llamadas" << endl;
    Console::SetCursorPosition(28, 36);
    cout << " A celular" << endl;
    Console::SetCursorPosition(44, 35);
    cout << "Mensajes de" << endl;
    Console::SetCursorPosition(44, 36);
    cout << "   Texto" << endl;
    Console::SetCursorPosition(60, 35);
    cout << " Monto Pagar" << endl;
    Console::SetCursorPosition(60, 36);
    cout << "Exceso Consumo" << endl;
    for (int i = 0; i < N; i++)
    {
        MontoTotalAlPagarExcesoConsumo = 0;
        if (Matriz[i][0] > 20)
        {
            MontoTotalAlPagarExcesoConsumo += (Matriz[i][0] - 20) * 0.35;
        }
        if (Matriz[i][1] > 40)
        {
            MontoTotalAlPagarExcesoConsumo += (Matriz[i][1] - 40) * 0.45;
        }
        if (Matriz[i][2] > 20)
        {
            MontoTotalAlPagarExcesoConsumo += (Matriz[i][2] - 20) * 0.20;
        }
        cout << ' ' << ' ' << CodigoVend[i];
        for (int j = 0; j < columnas; j++)
        {
            cout << "\t\t" << Matriz[i][j] << ' ';
        }
        cout << "\t\t" << MontoTotalAlPagarExcesoConsumo;
        cout << endl;
    }
}

void TiempoPromLlamadasYMensajes(int Matriz[][columnas])
{
    int SumaMinLlamadasFijo = 0;
    int SumaMinLlamadasCel = 0;
    int SumaMensajesEnviados = 0;
    double PromedioFijo = 0;
    double PromedioCel = 0;
    double PromedioMensajes = 0;
    for (int i = 0; i < N; i++)
    {
        SumaMinLlamadasFijo += Matriz[i][0];
        SumaMinLlamadasCel += Matriz[i][1];
        SumaMensajesEnviados += Matriz[i][2];
    }
    if (N > 0)
    {
        PromedioFijo = (SumaMinLlamadasFijo * 1.0) / N;
        PromedioCel = (SumaMinLlamadasCel * 1.0) / N;
        PromedioMensajes = (SumaMensajesEnviados * 1.0) / N;
    }
    cout << endl << "Tiempo promedio de llamadas a fijo: " << PromedioFijo << endl;
    cout << "Tiempo promedio de llamadas a celular: " << PromedioCel << endl;
    cout << "Promedio de mensajes enviados: " << PromedioMensajes;
}

int main()
{
    srand(time(nullptr));
    int* CodigoVend = new int[N];
    int Matriz[N][columnas];

    GenerarDatos(CodigoVend, Matriz);
    MostrarMatrizyArregloCod(CodigoVend, Matriz);
    CodigoVendedoresMayorCantidadMinLlamadasCelu(CodigoVend, Matriz);
    MontoTotalAPagarExcesoConsumo(CodigoVend, Matriz);
    TiempoPromLlamadasYMensajes(Matriz);
    
    delete[] CodigoVend;

    system("pause>0");
    return 0;
}