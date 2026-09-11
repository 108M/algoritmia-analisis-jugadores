# Algoritmia: análisis de jugadores en C

Proyecto de la asignatura de Algoritmia (grado en Ingeniería Informática). Un
programa en C que lee una base de jugadores en CSV (`IE1.csv`, con
estadísticas al estilo Inazuma Eleven) y clasifica jugadores por posición
usando **k-vecinos más cercanos (KNN)**, con una variante que aplica la
**edición de Wilson** para depurar el conjunto de entrenamiento.

Incluye además, como estructuras propias:

- **Normalización** de estadísticas (`normalizar.c`).
- **Búsqueda de máximos y mínimos** (`maxMin.c`).
- **Cola de enteros** hecha a mano (`colaEnteros.c`).

## Compilar y ejecutar

```bash
cd src
gcc jugador.c -c
gcc main.c -c
gcc normalizar.c -c -lm
gcc maxMin.c -c
gcc colaEnteros.c -c
gcc jugador.o maxMin.o normalizar.o colaEnteros.o main.o menu.c -o menu -lm
./menu
```

(o usa el `makefile` incluido con `make menu` si tienes `make` instalado).

El menú deja elegir entre predecir la clase de un jugador con KNN normal o
con Wilson, para una K fija o buscando la K óptima.

## Estado

Funciona: compilado y probado (todas las opciones del menú cargan
`IE1.csv` y responden correctamente). Es trabajo académico, no mantenido
activamente — quedan bugs conocidos sin resolver por el propio autor
original de la práctica.
