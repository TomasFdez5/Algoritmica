#include <vector>    // necesario para el contenedor vector
#include "algorithm.hpp"
#include "greedymethod.hpp"
#include "digitalcurve.hpp"
//#include "heapvectorMasood.hpp"
//#include "nodoMasood.hpp"



using namespace std;

/* Functions for Collinear suppression method */

//Constructor.

GreedyMethod::GreedyMethod(char *fileName, int numberPointsPolygonalApproximation)
{
	//A digital curve is created to load the digital curve in file
	DigitalCurve dc(fileName);

	//Digital curve as saved as original curve
	setOriginalCurve(dc);

	//Set the number of points of the polygonal approximation
	setNumberPointsPolygonalApproximation(numberPointsPolygonalApproximation);
}

//Destructor
GreedyMethod::~GreedyMethod()
{
}

void GreedyMethod::muestra_dominantes()
{
	for (int i = 0; i < getDominantPointsPosition().size(); i++)
	{
		cout << "Dominante["<<i<<"] = " << getDominantPointsPosition()[i] << endl; 
	}
}

void GreedyMethod::apply()
{
	int incremento=0; 
	vector <int> new_dominant_Point_Position; //vector auxiliar para coger los puntos dominantes que me interesen en cada caso
	long double error=0.0; 		//variables auxiliares para comprobar el error que se producen en la modificación de los puntos dominantes
	long double error_aux=0.0;
	long double ISEanterior; //contendra el valor anterior para getISE() y nos servirá para comprobar cuando deja de variar

	calculateSummations();
	collinearPointsElimination();

	/*
		Descomentar para ver los puntos dominantes resultantes de coger aquellos que sean múltiplo de 'incremento'
	*/
	//muestra_dominantes();

	cout << "\nTotal de dominantes: " << getDominantPointsPosition().size() << endl;

	incremento = getDominantPointsPosition().size()/(getNumberPointsPolygonalApproximation()-1);
	cout << "El incremento es de :" << incremento << endl;

	for (unsigned int i = 0; i < getNumberPointsPolygonalApproximation()-1; i++)
	{
		if (i*incremento<getDominantPointsPosition().size())
		{
			new_dominant_Point_Position.push_back(getDominantPointsPosition()[i*incremento]);
		}
	}
	
	//Cogemos el último dominante como se indica en el guión.
	new_dominant_Point_Position.push_back(getDominantPointsPosition()[getDominantPointsPosition().size()-1]);


	setDominantPointsPosition(new_dominant_Point_Position);

	/*
		Descomentar para ver los puntos dominantes resultantes de coger aquellos que sean múltiplo de 'incremento'
	*/
	//muestra_dominantes();

	cout << "El valor anterior de ISE es " << getISE() << endl;


	do{

		ISEanterior = getISE();
		for (int i = 1; i < new_dominant_Point_Position.size(); i++)
		{
			error = calculateISEValue(new_dominant_Point_Position[i-1],new_dominant_Point_Position[i]) + calculateISEValue(new_dominant_Point_Position[i],new_dominant_Point_Position[(i+1)%new_dominant_Point_Position.size()]);
			/*cout << "dominante i - 1: " << new_dominant_Point_Position[i-1] << " dominante i + 1%: " << new_dominant_Point_Position[(i+1)%new_dominant_Point_Position.size()] << endl;*/
			for (int z = new_dominant_Point_Position[i-1]; z < new_dominant_Point_Position[i+1] ; z++)
			{
				error_aux = calculateISEValue(new_dominant_Point_Position[i-1],z) + calculateISEValue(z,new_dominant_Point_Position[(i+1)%new_dominant_Point_Position.size()]);
				if (error_aux<error){error = error_aux; new_dominant_Point_Position[i]=z;}
			}		
		}
		setDominantPointsPosition(new_dominant_Point_Position);
		cout << "getISE() = " << getISE() << " ISEanterior = " << ISEanterior << endl;

	}while(getISE()!=ISEanterior);

	/*
		Descomentar para ver los puntos dominantes resultantes de modificar su posición para encontrar aquella que tenga menos error
	*/
	//muestra_dominantes();

	calculatePolygonalApproximation();

	setNumberPointsPolygonalApproximation(getPolygonalApproximation().getNumberPointsDigitalCurve());
}


