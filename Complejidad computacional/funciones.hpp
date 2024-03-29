#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <cstring> //Para usar memset
#include <iostream>
#include <stdint.h> // Para usar uint64_t
#include <vector> //para manejar la clase vector de la STL>
#include <cassert>

using namespace std;

	void mostrar_tabla(const vector <double> &n_elementos,const vector <double> &tiempos);
	
	void escribeFichero(const vector <double> &n_elementos,const vector <double> &tiempos,string nombre);
	
	void escribeFichero(const vector <double> &n_elementos,const vector <double> &tiempos_reales,const vector <double> &tiempos_estimados,string nombre);
	
	double sumatorio(const vector <double> v,double grado,const vector <double> v1,double grado1);

	double calcularCoeficienteDeterminacion(const vector <double> &tiempos_reales, const vector <double> &tiempos_estimados);

	void imprimirMatriz(vector<vector <double> > &v);

	void rellenarMatriz(vector<vector <double> > &v);

	/*
		Clase tiempo
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


#endif