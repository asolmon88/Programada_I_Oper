# README DEL PROYECTO
## _Descripción del Programa_


El programa se encarga de contabilizar y corregir errores en archivos; estos errores son de tipo **typo**. El programa recibe los nombres de _N_ archivos, crea _N_ procesos, y cada proceso se encarga de un archivo. Se imprime en consola los errores por archivo, cantidad de errores en general, y se generan archivos nuevos con las correciones ya implementadas.

El proyecto consta de las siguientes partes:

_`files:`_ directorio donde se almacenan los archivos **a procesar**.

_`results:`_ directorio donde se almacenan los archivos **ya procesados**.

_`src:`_ código fuente del programa.

## _Limitaciones & Restricciones_


Los archivos a procesar deben seguir el siguiente formato: `fileN.txt`, el nombre del archivo **NO** debe exceder los **5** caracteres.

# _Manual de usuario_
## ¿Cómo construir el proyecto?
Ingrese el comando: 

    make
## ¿Cómo correr el programa?
El programa se puede correr de dos formas:

**1.  Ingreso de archivos por terminal:** 

    ./main file1.txt file2.txt

Los archivos a procesar se deben encontrar en el directorio general. Los resultados se almacenan en `results`.

**1.  Ingreso de archivos por directorio:**

    ./main

Los archivos a procesar se deben encontrar en el directorio `files`, en este proyecto ya se brindan algunos casos de prueba. Los resultados se almacenan en `results`.
## ¿Cómo remover archivos generados por el programa?

    make clean

## _Créditos_

**Autores**: 

Josué Retana Rodríguez C06440

Ariel Solís Monge B97664

