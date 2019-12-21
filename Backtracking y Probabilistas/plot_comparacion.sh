#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "ComparacionBvsLV.eps"
set key right bottom
set xlabel "Numero de reinas"
set ylabel "Tiempo empleado"
plot 'Datos_comparacion.txt' using 1:2 t "Backtracking" w l, 'Datos_comparacion.txt' using 1:3 t "Probabilista, Las Vegas" w l
_end_
