#ifndef FUNCIONES_GENERAL_HPP
#define FUNCIONES_GENERAL_HPP
#include <vector>
#include <iostream>
#include <stdint.h>	// necesario para uint64_t
#include <fstream> 	//	Necesario para almacenar los datos en un fichero
#include <cstring>	//	Necesario para usar memset
#include <cassert>	//	Necesario para assert en la clase clock
using namespace std;

	/*
		Clase tiempo necesaria para calcular el tiempo empleado.
	*/
	class Clock
	{
		private:
			timespec _start;
			timespec _stop;
			bool _isStarted;
		public:
			Clock ()
			{
				memset(&_start,0,sizeof(timespec));
				memset(&_stop,0,sizeof(timespec));
				_isStarted=false;
			} 
			/*!\brief Starts the clock.
			* \pre not isStarted()
			* \post isStarted()
			*/
			void start ()
			{      
				assert (!isStarted());
				clock_gettime (CLOCK_REALTIME, &_start);   
				_isStarted=true;
			}
			/*!\brief Re-starts the clock.
			* \post isStarted()
			*/
			void restart ()
			{      
				clock_gettime (CLOCK_REALTIME, &_start);   
				_isStarted=true;
			}

			/*!\brief Stops the clock.
			* \pre isStarted()
			* \post not isStarted()
			*/ 
			void stop ()
			{
				assert (_isStarted);
				clock_gettime (CLOCK_REALTIME, &_stop);   
				_isStarted=false;
			}
			/*!\brief Is the clock started?
			* \return true if the clock is started currently.
			*/
			bool isStarted() const
			{
				return _isStarted;
			}
			/*!\brief Return the elapsed time in mcs.*/
			uint64_t elapsed() const
			{
				assert (!_isStarted);
				uint64_t startT = (uint64_t)_start.tv_sec * 1000000LL + (uint64_t)_start.tv_nsec / 1000LL;
				uint64_t stopT = (uint64_t)_stop.tv_sec * 1000000LL + (uint64_t)_stop.tv_nsec / 1000LL;
				return stopT-startT;
			}
	};

	bool Posicion_correcta_reina(int fila, vector<int> posiciones_reina);

	void mostrar_soluciones(vector<vector<int> > soluciones_reina);

	void muestra_tablero(vector<int> solucion);

	bool comprueba_cadena(string cadena);

	void escribirFichero(const vector <double> &n_elementos,const vector <double> &vector1,const vector <double> &vector2, const string nombre);

	void introducir_datos(int &n_reinas_minimo, int &n_reinas_maximo, int &n_incremento);

	bool realizar_estimacion(const double &a0, const double &a1);

	void comparacion_primera_iteracion(const vector <double> &n_elementos,const vector <double> &tiempos_primera_backtracking,const vector <double> &tiempos_primera_LasVegas);

#endif