#include "opciones.hpp"
#include <iostream>


using namespace std;

int main(int argc, char *argv[])
{
   int opcion=0;
   do{
      cout << "\n\t\tMENU:" << endl;
      cout << "\n\t1. N Reinas por Backtracking." << endl;
      cout << "\t2. N Reinas por algormitmo probabilista." << endl;
      cout << "\t3. Ajustar los tiempos obtenidos para las N-Reinas." << endl;
      cout << "\t4. Comparar el tiempo obtenido ambos algormitmos para obtener la primera solucion." << endl;
      cout << "\t5. Salir." << endl;

      cout << "\nSu opcion: ";
      cin >> opcion;cout << endl;

      switch(opcion){
         case 1:
            opcion_backtracking();
         break;
         case 2:
            opcion_probabilista();
         break;
         case 3:
            opcion_ajuste_backtracking();
         break;
         case 4:
            opcion_comparar_primera_solucion();
         break;
         case 5:
            cout << "\nFin del programa." << endl;
         break;
         default:
            cout << "\nOpcion no valida." << endl;
         break;
      };

   }while(opcion!=5);
   return 0;
}
