#include <iostream>
#include <vector> 
#include <ctime>
#include <math.h>
#include "quicksort.hpp"
#include "matrices.hpp"
#include "matrices_strassen.hpp"
#include "opciones.hpp"
#include "funciones.hpp"
#include "strassen.hpp"

using namespace std;


void opcion_Quicksort()
{
	Clock time;
	string respuesta="No";

	double tamano=0;
	double n, n_min, n_max, n_incremento, n_rep,suma=0;
	double media=0.0, a0=0.0, a1=0.0;

	vector <int> v; //vector a ordenar
	vector<double> n_elementos; //vector que almacena los valores estudiados
	vector <double> tiempos_reales;
	vector <double> tiempos_estimados;


	cout<<"Introduzca los siguientes datos:\nNumero minimo de elementos del vector:\n >";
	cin>>n_min;
	cout<<"\nNumero maximo de elementos del vector:\n >";
	cin>>n_max;
	cout<<"\nIncremento del numero de elementos del vector:\n >";
	cin>>n_incremento;
	cout<<"\nNumero de repeticiones para cada operacion:\n >";
	cin>>n_rep;


	n=n_min;

	while(n <= n_max){
		suma=0;
		cout << "n: " << n << endl;
		for (int i = 0; i < n_rep; i++)
		{

			v.resize(n);
			rellenarVector(v);
			time.start();
			quicksort(v,0,n-1);

			if (time.isStarted())
			{
				time.stop();
				suma=suma+time.elapsed();
				//std::cout << "Han pasado " << time.elapsed() << "microsegundos \n";
			}

			estaOrdenado(v);
			//imprime(v);
		}

		media=suma/n_rep;
		tiempos_reales.push_back(media);
		n_elementos.push_back(n);
		n+=n_incremento;

		v.clear();		
	}
	/*
		Funcion mostrar_tabla meramente auxiliar. Permite ver los tiempos reales obtenidos
	*/
	//mostrar_tabla(n_elementos,tiempos_reales);
	escribeFichero(n_elementos,tiempos_reales,"Tabla.txt");
	
	ajusteNlogN(n_elementos,tiempos_reales,a0,a1);
	calcularTiemposEstimadosNlogN(n_elementos,tiempos_reales,a0,a1,tiempos_estimados);
	cout<<"\nLa ecuación de las curva ajustadas por mínimos cuadrados es: "<<a0<<"+"<<a1<<"*n*log(n)"<<endl;
	cout<<"El coeficiente de determinacion es: "<<calcularCoeficienteDeterminacion(tiempos_reales,tiempos_estimados)<<endl;
	/*
		Comprobación de la petición del usuario
	*/
	cout<<"\n¿Desea hacer una estimación de tiempos para un determinado valor del tamaño del ejemplar?\n >";
	cin>>respuesta;
	if (respuesta=="Si" or respuesta=="SI" or respuesta=="si")
	{
		do{

			cout<<"\nIntroduzca el tamano de la muestra:\n >";
			cin>>tamano;

			if (tamano!=0 and tamano>0)
			{				
				cout<<"\nTardaría en calcularse "<<calcularTiempoEstimadoNlogN(tamano,a0,a1)<<" dias."<<endl;			
				cout << "\nIntroduzca tamano 0 si desea finalizar. Gracias" << endl;
			}


		}while(tamano!=0);
	}
}



void opcion_Producto_Matriz()
{
	Clock time;
	string respuesta="No";

	double n, n_min, n_max,n_incremento;
	double tamano=0;

	vector<double> n_elementos; //vector que almacena los valores estudiados
	vector <double> tiempos_reales;
	vector <double> tiempos_estimados;
	vector <double> constantes; //vector que contrandrá los coeficientes obtenidos en el sistema de ecuaciones

	//Comprobamos que introduzca un orden de matriz válido.
	do{
		cout<<"Introduzca el orden minimo de las matrices cuadradas:\n >";
		cin>>n_min;
	}while(n_min<1);

	/*
		Creación de las matrices a multiplicar y la matriz resultante.
		Además, se rellenan con numeros aleatorios utilizando la funcion rellenarMatriz.
	*/
	vector<vector <double> > v (n_min, vector<double> (n_min));
	vector<vector <double> > v2 (n_min, vector<double> (n_min));
	vector<vector <double> > v3 (n_min, vector<double> (n_min));
	rellenarMatriz(v);
	rellenarMatriz(v2);

	cout<<"\nIntroduzca el orden maximo de las matrices cuadradas:\n >";
	cin>>n_max;
	cout<<"\nIncremento del orden de las matrices:\n >";
	cin>>n_incremento;

	n=n_min;

	while(n <= n_max){
		cout << "n: " << n << endl;
		/*
			Redimensionamos las matrices con el nuevo tamaño
		*/
		v.resize(n, vector<double> (n));
		v2.resize(n, vector<double> (n));
		v3.resize(n, vector<double> (n));
		rellenarMatriz(v);
		rellenarMatriz(v2);

		time.start();
		multiplicacion(v,v2,v3,n);

		if (time.isStarted())
		{
			time.stop();
		}	

		tiempos_reales.push_back(time.elapsed());
		n_elementos.push_back(n);
		n+=n_incremento;

		v.clear();	
		v2.clear();
		v3.clear();	

	}
	/*
		Funcion mostrar_tabla meramente auxiliar. Permite ver los tiempos reales obtenidos
	*/
	//mostrar_tabla(n_elementos,tiempos_reales);
	escribeFichero(n_elementos,tiempos_reales,"Tabla_matriz.txt");
	
	ajustePolinomico(n_elementos, tiempos_reales, constantes);
	calcularTiemposEstimadosPolinomico(n_elementos,tiempos_reales,constantes,tiempos_estimados);
	cout<<"\nEl coeficiente de determinacion es: "<<calcularCoeficienteDeterminacion(tiempos_reales,tiempos_estimados)<<endl;
	
	cout<<"¿Desea hacer una estimación de tiempos para un determinado valor del tamaño del ejemplar?\n >";
	cin>>respuesta;

	if (respuesta=="Si" or respuesta=="SI" or respuesta=="si")
	{
		do{

			cout<<"\nIntroduzca el tamano de la muestra:\n >";
			cin>>tamano;

			if (tamano!=0 and tamano>0)
			{				
				cout<<"\nTardaría en calcularse "<<calcularTiempoEstimadoPolinomico(tamano,constantes)<<" dias."<<endl;			
				cout << "\nIntroduzca tamano 0 si desea finalizar. Gracias" << endl;
			}


		}while(tamano!=0);
	}
}


void opcion_Strassen()
{
	Clock time;
	string respuesta="No";

	double tamano=0;
	double n, n_min, n_max;

	vector<double> n_elementos; //vector que almacena los valores estudiados
	vector <double> tiempos_reales;
	vector <double> tiempos_estimados;
	vector <double> constantes; //vector que contrandrá los coeficientes obtenidos en el sistema de ecuaciones
	
	do{
		cout<<"Introduzca el orden minimo de las matrices cuadradas:\n >";
		cin>>n_min;
	}while(n_min<1);

	vector<vector <double> > v (n_min, vector<double> (n_min));
	vector<vector <double> > v2 (n_min, vector<double> (n_min));
	vector<vector <double> > v3 (n_min, vector<double> (n_min)); //resultado
	rellenarMatriz(v);
	rellenarMatriz(v2);

	cout<<"\nIntroduzca el orden maximo de las matrices cuadradas:\n >";
	cin>>n_max;

	n=n_min;

	for (unsigned int i = n; i <= n_max; i=2*i)
	{
		cout << "i: " << i << endl;
		v.resize(i, vector <double> (i));
		v2.resize(i, vector <double> (i));
		v3.resize(i, vector <double> (i));
		rellenarMatriz(v);
		rellenarMatriz(v2);

		time.start();		
		strassen(v,v2,v3,i);

		
		if (time.isStarted())
		{
			time.stop();
		}	
		
		tiempos_reales.push_back(time.elapsed());
		n_elementos.push_back(i);

		v.clear();	
		v2.clear();
		v3.clear();	
	}
	/*
		Funcion mostrar_tabla meramente auxiliar. Permite ver los tiempos reales obtenidos
	*/
	//mostrar_tabla(n_elementos,tiempos_reales);
	escribeFichero(n_elementos,tiempos_reales,"Tabla_matriz_strassen.txt");
	
	ajustePolinomicoStrassen(n_elementos, tiempos_reales, constantes);
	calcularTiemposEstimadosPolinomicoStrassen(n_elementos,tiempos_reales,constantes,tiempos_estimados);
	cout<<"\nEl coeficiente de determinacion es: "<<calcularCoeficienteDeterminacion(tiempos_reales,tiempos_estimados)<<endl;
	

	cout<<"¿Desea hacer una estimación de tiempos para un determinado valor del tamaño del ejemplar?\n >";
	cin>>respuesta;
	if (respuesta=="Si" or respuesta=="SI" or respuesta=="si")
	{
		do{

			cout<<"\nIntroduzca el tamano de la muestra:\n >";
			cin>>tamano;

			if (tamano!=0 and tamano>0)
			{				
				cout<<"\nTardaría en calcularse "<<calcularTiempoEstimadoPolinomicoStrassen(tamano,constantes)<<" dias."<<endl;			
				cout << "\nIntroduzca tamano 0 si desea finalizar. Gracias" << endl;
			}


		}while(tamano!=0);
	}
}