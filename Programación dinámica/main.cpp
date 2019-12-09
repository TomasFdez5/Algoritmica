#include "algorithm.hpp"
#include "opciones.hpp"
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{


   int opcion=0;
   do{
      cout << "\n\t\tMENU:" << endl;
      cout << "\n\t1. Supresion de puntos colineales." << endl;
      cout << "\t2. Aproximacion poligonal por programación dinámica." << endl;
      cout << "\t3. Salir." << endl;

      cout << "\nSu opcion:\n> ";
      cin >> opcion;

      switch(opcion){
         case 1:
            opcion_uno();
         break;
         case 2:
            opcion_dos();
         break;
         case 3:
            cout << "\nFin del programa." << endl;
         break;
         default:
            cout << "\nOpcion no valida." << endl;
         break;
      };

   }while(opcion!=3);
   return 0;
}
