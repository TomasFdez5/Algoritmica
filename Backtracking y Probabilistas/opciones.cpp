#include "opciones.hpp"
#include "funciones_backtracking.hpp"
#include "funciones_probabilista.hpp"
#include "funciones_estadisticas.hpp"
#include "funciones_general.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector> //	Necesario para ir almanenando las soluciones proporcionadas por Backtracking

using namespace std;

void opcion_backtracking()
{
	vector<vector<int> > soluciones_reina; //	Matriz de posibles soluciones
	int n_reinas;
	
	cout << "Introduzca el valor de N para las N-Reinas: ";
	cin >> n_reinas;

	Backtracking_NReinas(n_reinas, soluciones_reina);

	cout << "Existen " << soluciones_reina.size() << " soluciones para el problema de las " << n_reinas << " reinas." << endl;

	//	Una vez obtenidas las soluciones, damos la posibilidad de mostrarlas
	string respuesta;
	cout << "\n¿Desea ver las soluciones obtenidas?\n\t| Si\n\t| No\n" << endl;
	cout << "Respuesta: ";
	cin >> respuesta; cout << endl;

	if (comprueba_cadena(respuesta)==true)
	{
		mostrar_soluciones(soluciones_reina);
	}
}

void opcion_probabilista()
{
	srand(time(NULL));
	int n_reinas;
	bool existe_solucion = false;
	int contador_pruebas=0;

	cout << "Introduzca el valor de N para las N-Reinas: ";
	cin >> n_reinas;
	cout << endl;

	vector<int> solucion_reina(n_reinas+1);

	//	Iteramos hasta que se encuentre la primera solucion posible.
	while(existe_solucion == false)
	{

		Probabilista_NReinas(n_reinas, solucion_reina, existe_solucion);
		if (existe_solucion)
		{
			cout << "\n      PRIMERA SOLUCION OBTENIDA\n" << endl;			
			muestra_tablero(solucion_reina);
			cout << "__________________________________________________________\n"<<endl;
		}
		contador_pruebas++;
	}
	cout << "Se han realizado " << contador_pruebas << " pruebas hasta encontrar la primera solucion." << endl;
}

void opcion_ajuste_backtracking()
{
	Clock time;
	vector<vector<int> > soluciones_reina; 	//	Matriz de posibles soluciones

	
	//	Valores introducidos por el usuario
	int n_reinas_minimo,n_reinas_maximo,n_incremento=0;


	//	Variables necesarias para el calculo del ajuste
	double a0=0.0, a1=0.0;
	vector <double> n_elementos; 
	vector <double> tiempos_reales;
	vector <double> tiempos_estimados;

	introducir_datos(n_reinas_minimo,n_reinas_maximo,n_incremento);

	int iteracion = n_reinas_minimo;

	while(iteracion <= n_reinas_maximo)
	{
		cout << "Calculando " << iteracion << "-Reinas..." << endl;
		time.start();

		Backtracking_NReinas(iteracion, soluciones_reina);

		if (time.isStarted()){time.stop();}

		tiempos_reales.push_back(time.elapsed());	//Añado el tiempo obtenido
		n_elementos.push_back(iteracion);			//Añado el nº de reinas estudiado
		iteracion+=n_incremento;					//Incremento el numero de reinas
		soluciones_reina.clear();					//Vacio la matriz de soluciones
	}

	ajusteFactorial_NReinas(n_elementos,tiempos_reales,a0,a1);
	calcularTiemposEstimados_Factorial_NReinas(n_elementos,tiempos_reales,a0,a1,tiempos_estimados);
	escribirFichero(n_elementos,tiempos_reales,tiempos_estimados,"Datos_ajuste.txt");

	cout<<"\nLa ecuación de las curva ajustada es: "<<a0<<"+"<<a1<<"*n!"<<endl;
	cout<<"El coeficiente de determinacion es: "<<calcularCoeficienteDeterminacion(tiempos_reales,tiempos_estimados)<<endl;
	
	bool terminar_estimacion=false; // 	Me indica si el usuario quiere dejar de hacer estimaciones
	string respuesta;
	cout << "\n¿Desea hacer una estimación de tiempos para un determinado valor del tamaño del ejemplar?\n\t| Si\n\t| No\n" << endl;
	cout << "Respuesta: ";
	cin >> respuesta;	cout << endl;
	if (comprueba_cadena(respuesta)==true)
	{
		do{
			terminar_estimacion = realizar_estimacion(a0,a1);
		}while(terminar_estimacion!=true);
	}

}

void opcion_comparar_primera_solucion()
{
	Clock time;
	vector<vector<int> > soluciones_reina;
	//	Variables necesarias para el calculo del ajuste
	int n_reinas_minimo,n_reinas_maximo,n_incremento=0;
	bool existe_solucion=false;
	
	vector <double> n_elementos;
	vector <double> tiempos_primera_backtracking;	//Vector de tiempos obtenidos por backtracking
	vector <double> tiempos_primera_LasVegas;		//Vector de tiempos obtenidos por Las Vegas
	
	introducir_datos(n_reinas_minimo,n_reinas_maximo,n_incremento);

	int iteracion = n_reinas_minimo;
	vector<int> solucion_reina(iteracion+1); // Creamos el vector solucion con su tamano correspondiente para Probabilista.
	
	while(iteracion <= n_reinas_maximo)
	{

		cout << "Calculando " << iteracion << "-Reinas..." << endl;
	//	Calculo tiempos Backtracking
		time.start();

		Backtracking_NReinas(iteracion, soluciones_reina,true);

		if (time.isStarted()){time.stop();}
		tiempos_primera_backtracking.push_back(time.elapsed());
	//	Fin tiempos Backtracking
	//	Calculo tiempos Las Vegas
		time.start();

		while(existe_solucion == false)
		{
			Probabilista_NReinas(iteracion, solucion_reina,existe_solucion);
			if (existe_solucion)	//	Pararemos solo en caso de que encontremos solucion
			{
				if (time.isStarted()){time.stop();}
				tiempos_primera_LasVegas.push_back(time.elapsed());				
			}
		}		
	//	Fin tiempos Las vegas

		n_elementos.push_back(iteracion);
		iteracion+=n_incremento;			//	Incremento el numero de reinas
		soluciones_reina.clear();			//	Vacio la matriz y vector de soluciones
		solucion_reina.clear();
		solucion_reina.resize(iteracion+1);	//	Redimensiono el vector de solucion (Las Vegas)
		existe_solucion=false;				//	Reestablezco la bandera a false (Las Vegas)
	}

	comparacion_primera_iteracion(n_elementos,tiempos_primera_backtracking,tiempos_primera_LasVegas);
	
}