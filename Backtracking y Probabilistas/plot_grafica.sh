#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "Backtracking_graf.eps"
set key right bottom
set xlabel "Numero de reinas"
set ylabel "Tiempo empleado"
plot 'Datos_ajuste.txt' using 1:2 t "Tiempos reales" w l, 'Datos_ajuste.txt' using 1:3 t "Tiempos estimados" w l
_end_
