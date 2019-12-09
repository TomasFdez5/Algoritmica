#include "algorithm.hpp"
#include "suppressioncollinearpointsmethod.hpp"
#include "opciones.hpp"
#include "greedymethod.hpp"

using namespace std;

void opcion_uno()
{
	Algorithm *a;
	char fileNameDC[100], fileNamePA[100];
	int n;

	cout << "Digital curve to obtain polygonal approximation: ";
	cin >> fileNameDC;

	a = new CollinearSuppressionMethod(fileNameDC);

	a->apply();

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
	a = new GreedyMethod(fileNameDC, n_puntos);
	//Lo aplicamos
	a->apply();
	cout << "El valor de ISE resultante es " << a->getISE() << endl;

	DigitalCurve aP = a->getPolygonalApproximation();

	cout << "Introduzca el nombre del fichero para guardar la aproximacion: ";
	cin >> fileNamePA;

	aP.saveDigitalCurve(fileNamePA);

}