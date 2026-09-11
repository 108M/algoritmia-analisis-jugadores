# Algoritmia: análisis de jugadores en C

Programa en **C puro** que implementa desde cero varios algoritmos clásicos
de análisis de datos para clasificar jugadores (dataset de estilo Inazuma
Eleven, en CSV) según su posición a partir de sus estadísticas.

## Qué hace

- **Clasificación por K-vecinos más cercanos (KNN)**: dado un jugador nuevo,
  busca los K jugadores más parecidos del dataset (por distancia entre sus
  estadísticas) y predice su posición por mayoría de votos.
- **Búsqueda de la K óptima**: prueba distintos valores de K y calcula el
  porcentaje de acierto de cada uno para encontrar el mejor.
- **Edición de Wilson**: variante que primero "limpia" el dataset de
  entrenamiento eliminando los ejemplos mal clasificados, para mejorar la
  precisión del KNN posterior.
- **Normalización de estadísticas**: para que ningún atributo (p. ej. la
  velocidad) pese más que otro solo por tener una escala mayor.
- **Cola de enteros implementada a mano**, usada como estructura de apoyo
  en el procesado de datos.

Todo el flujo se maneja desde un menú interactivo por terminal.

## Lenguaje y stack

C (sin dependencias externas más allá de la librería estándar y `libm`).

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
