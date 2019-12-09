#!/bin/bash

cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico_matriz.eps"
set key right bottom
set xlabel "Etiqueta eje X"
set ylabel "Etiqueta Eje Y"
plot 'Datos_matriz.txt' using 1:2 t "Tiempos reales", 'Datos_matriz.txt' using 1:3 t "Tiempos estimados" w l
_end_
