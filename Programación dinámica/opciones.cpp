#include "algorithm.hpp"
#include "opciones.hpp"
#include "suppressioncollinearpointsmethod.hpp"
#include "dynamicprogrammingmethod.hpp"

using namespace std;

void opcion_uno()
{
	//It creates a pointer to algorithm class to use overload in execution
   	Algorithm *a;

	char fileNameDC[100], fileNamePA[100];
	int n;
	cout << "Digital curve to obtain polygonal approximation: ";
	cin >> fileNameDC;

	//Creates a new class for method and the pointer points to the new class
	a = new CollinearSuppressionMethod(fileNameDC);

	//Execute the method
	a->apply();

	cout << "Number of points of the polygonal approxmation: " << a->getNumberPointsPolygonalApproximation() << endl;
	cout << "The value of ISE is " << a->getISE() << endl;

	DigitalCurve aP = a->getPolygonalApproximation();

	cout << "Name of file to save the polygonal approximation: ";
	cin >> fileNamePA;

	aP.saveDigitalCurve(fileNamePA);
}

void opcion_dos()
{
	Algorithm *a;
	char fileNameDC[100], fileNamePA[100];
	int n_puntos;

	cout << "\nCurva digital para obtener la approximacion poligonal: ";
	cin >> fileNameDC;
	cout << "\nNumero de puntos para la aproximacion poligonal: ";
	cin >> n_puntos;


	//Creamos la instancia de nuestro método.
	a = new DynamicProgrammingMethod(fileNameDC, n_puntos);
	//Lo aplicamos
	a->apply();
	cout << "El valor de ISE obtenido por la funcion getISE()= " << a->getISE() << endl;

	DigitalCurve aP = a->getPolygonalApproximation();

	cout << "Introduzca el nombre del fichero para guardar la aproximacion: ";
	cin >> fileNamePA;

	aP.saveDigitalCurve(fileNamePA);
}