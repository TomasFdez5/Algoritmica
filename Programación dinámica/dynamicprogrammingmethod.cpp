#include "dynamicprogrammingmethod.hpp"

#include <vector>    // necesario para el contenedor vector
#include "algorithm.hpp"
#include "digitalcurve.hpp"

#define INFINITO 99999999999



using namespace std;


DynamicProgrammingMethod::DynamicProgrammingMethod(char *fileName, int numberPointsPolygonalApproximation)
{
	//A digital curve is created to load the digital curve in file
	DigitalCurve dc(fileName);

	//Digital curve as saved as original curve
	setOriginalCurve(dc);

	//Set the number of points of the polygonal approximation
	setNumberPointsPolygonalApproximation(numberPointsPolygonalApproximation);
}

//Destructor
DynamicProgrammingMethod::~DynamicProgrammingMethod()
{
}



void DynamicProgrammingMethod::apply()
{
	long double minimo = INFINITO;
	int padre = 0;

	vector <int> new_dominant_Point_Position;
	int father[getOriginalCurve().getNumberPointsDigitalCurve()][getNumberPointsPolygonalApproximation()];
	long double E[getOriginalCurve().getNumberPointsDigitalCurve()][getNumberPointsPolygonalApproximation()];
	//	Siendo 
	//	N: numero de puntos de una curva 					-->  getOriginalCurve().getNumberPointsDigitalCurve()
	//	M: numero de puntos de la aproximacion poligonal 	-->  getNumberPointsPolygonalApproximation()

	calculateSummations();

//	Relleno la matriz E con ceros inicialmente

	for (int i = 0; i < getOriginalCurve().getNumberPointsDigitalCurve(); i++)
	{
		for (int z = 0; z < getNumberPointsPolygonalApproximation(); z++)
		{
			E[i][z]=0;
		}
	}
//	Introduzco los casos base

	for (int j = 1; j < getOriginalCurve().getNumberPointsDigitalCurve(); j++)
	{
		E[j][0]=INFINITO;
	}

//	Fin rellenar matriz E

//	Inicio método	

	for (int i = 1; i < getNumberPointsPolygonalApproximation(); i++)	//	Recorre la m
	{
		for (int j = i; j < getOriginalCurve().getNumberPointsDigitalCurve(); j++)		//	Recorre la n
		{
			minimo=INFINITO;
			for (int p = i-1; p < j; p++)		//	Recorre las posibilidades para el min
			{
				if (minimo > (E[p][i-1] + calculateISEValue(p,j)))
				{
					minimo = E[p][i-1] + calculateISEValue(p,j);
					padre = p;
				}
			}
			E[j][i] = minimo;
			father[j][i] = padre;
		}
	}
//	Fin método

	//	El último padre óptimo encontrado será nuestro primer dominante
	int nuevo = padre;
	new_dominant_Point_Position.push_back(nuevo);


//	Bajamos por la matriz E encontrando los dominantes

	for (int i = getNumberPointsPolygonalApproximation()-1; i > 0; i--)
	{
		new_dominant_Point_Position.push_back(father[nuevo-1][i]);
		nuevo=father[nuevo-1][i];
	}

//	Fin recorrido


	//	Invierto mis dominantes ya que los he rellenado en orden inverso
	reverse(new_dominant_Point_Position.begin(),new_dominant_Point_Position.end());

	//	Muestro los dominantes obtenidos
	for (int i = 0; i < new_dominant_Point_Position.size(); i++)
	{
		cout << "Dominante["<<i<<"] = " << new_dominant_Point_Position[i] << endl; 
	}

	cout << "Error obtenido por la matriz E= " << E[getOriginalCurve().getNumberPointsDigitalCurve()-1][getNumberPointsPolygonalApproximation()-1] << endl; // DUDA  ¿?¿?¿?¿?¿?¿?

	//	Establezco los dominantes obtenidos
	setDominantPointsPosition(new_dominant_Point_Position);

	calculatePolygonalApproximation();

	setNumberPointsPolygonalApproximation(getPolygonalApproximation().getNumberPointsDigitalCurve());
}


