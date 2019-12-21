#include "funciones_general.hpp"
#include "funciones_estadisticas.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

bool Posicion_correcta_reina(int fila, vector<int> posiciones_reina)
{
	for (int i = 1; i <= fila -1; i++)
	{
		if (posiciones_reina[i] == posiciones_reina[fila] || abs(posiciones_reina[i]-posiciones_reina[fila]) == abs(i-fila))
		{
			return false;
		}
	}
	return true;
}

void mostrar_soluciones(vector<vector<int> > soluciones_reina)
{
	char tecla;
	cin.ignore();
	for (unsigned int i = 0; i < soluciones_reina.size(); i++)
	{
		cout << "\n\tSOLUCION Nº " << i+1 << "\n" << endl;
		muestra_tablero(soluciones_reina[i]);
		cout << "__________________________________________________________"<<endl;
		do
		{
			cout << "Presione ENTER para ver el siguiente camino..." << endl;
			tecla = getchar();
		}while(tecla!=13 and tecla!=10 and tecla!=141);			
	}
}

void muestra_tablero(vector<int> solucion)
{
	string tablero[solucion.size()+1][solucion.size()+1];
	for (int i = 0; i < solucion.size(); i++)
	{
		for (int j = 0; j < solucion.size(); j++)
		{
			tablero[i][j]="   ";
		}
	}
	for (unsigned int i = 1; i < solucion.size(); i++)
	{
		tablero[i][solucion[i]]=" ♕ ";
	}
	for (int i = solucion.size()-1; i > 0; i--)
	{
		cout << "      ";
		for (int j = 1; j <solucion.size(); j++)
		{
			cout << "[" << tablero[i][j] << "]"; 
		}
		cout << endl;
	}
	cout << "\n\n" << endl;
}


bool comprueba_cadena(string cadena)
{
	for (int i = 0; i < cadena.length(); i++) {
	    cadena[i] = toupper(cadena[i]);
	  }
	if (cadena=="SI"){return true;}
	else{return false;}
}


void escribirFichero(const vector <double> &n_elementos,const vector <double> &vector1,const vector <double> &vector2, const string nombre)
{
	ofstream fichero(nombre.c_str());
	for (unsigned int i = 0; i < vector1.size(); i++)
	{
        fichero<<n_elementos[i]<<" "<<vector1[i]<<" "<<vector2[i]<<endl;
	}
	fichero.close();
}


void introducir_datos(int &n_reinas_minimo, int &n_reinas_maximo, int &n_incremento)
{
	do{
		cout << "\nIntroduzca el valor minimo de N para las N-Reinas: ";
		cin >> n_reinas_minimo;
		cout << "\nIntroduzca el valor maximo de N para las N-Reinas: ";
		cin >> n_reinas_maximo;
		cout<<"\nIncremento del numero de reinas: ";
		cin>>n_incremento;		
	}while(n_reinas_minimo<1 || n_reinas_maximo<1 || n_incremento<1);
}


bool realizar_estimacion(const double &a0, const double &a1)
{
	double numero_a_estimar=0.0;
	cout<<"\n> Introduzca el tamano de la muestra: ";
	cin>>numero_a_estimar; cout << endl;

	if (numero_a_estimar!=0 and numero_a_estimar>0)
	{				
		cout<<"\nTardaría en calcularse "<<calcularTiempoEstimado_Factorial_NReinas(numero_a_estimar,a0,a1)<<" dias."<<endl;			
		cout << "\nIntroduzca tamano 0 si desea finalizar. Gracias.";
	}
	else{return true;}

	return false;
}

void comparacion_primera_iteracion(const vector <double> &n_elementos,const vector <double> &tiempos_primera_backtracking,const vector <double> &tiempos_primera_LasVegas)
{
	for (int i = 0; i <n_elementos.size() ; i++)
	{
		cout << "\n\n\tCalculo de las " << n_elementos[i] << "-Reinas..." << endl;
		cout << "Tiempo obtenido por Backtracking: " << tiempos_primera_backtracking[i] <<"\nTiempo obtenido por Probabilista, Las Vegas: " << tiempos_primera_LasVegas[i] << endl;
	}
	escribirFichero(n_elementos,tiempos_primera_backtracking,tiempos_primera_LasVegas,"Datos_comparacion.txt");
}