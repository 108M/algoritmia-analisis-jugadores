# Algoritmia: análisis de jugadores en C

Proyecto de la asignatura de Algoritmia (grado en Ingeniería Informática). Un
programa en C que lee una base de datos de jugadores en CSV (`IE1.csv`, con
estadísticas al estilo Inazuma Eleven) y aplica sobre ella varios algoritmos
clásicos:

- **Normalización** de estadísticas (`normalizar.c`).
- **Búsqueda de máximos y mínimos** (`maxMin.c`).
- **Cola de enteros** implementada a mano para procesar los datos (`colaEnteros.c`).
- **Cálculo de distancias entre jugadores** (estilo KNN) para encontrar los más parecidos entre sí.

## Dónde está el código

La versión final y compilable es **[`VERSIONFINALAVERDADERA/`](./VERSIONFINALAVERDADERA)**.
Dentro tiene su propio `makefile`:

```bash
cd VERSIONFINALAVERDADERA/all
make
```

## Sobre el resto de archivos

El repo también conserva los `.tar.gz` / `.zip` / `.rar` sueltos en la raíz
(`wilson.tar.gz`, `inazumaeleven.tar.gz`, `respaldo.tar.gz`, etc.). Son copias
de seguridad manuales que fui haciendo del mismo proyecto mientras lo iba
depurando durante el curso — no son ejercicios distintos, sino distintos
puntos en el tiempo del mismo trabajo (de ahí nombres como
`VERSIONFINALAVERDADERA`). Se mantienen aquí tal cual por fidelidad histórica
al proceso, pero para ver o ejecutar el proyecto usa siempre la carpeta
`VERSIONFINALAVERDADERA/`.

## Contexto

Trabajo académico, no mantenido activamente. Se sube como muestra del
ejercicio de algoritmia (estructuras de datos propias, procesado de datos en
C, complejidad algorítmica) más que como software de producción.
