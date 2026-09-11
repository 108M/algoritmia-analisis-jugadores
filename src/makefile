all: maxmin cola normalizar jugador main menu

jug: jugador pjugador

jugador: jugador.c
	gcc jugador.c -c
main: main.c
	gcc main.c -c
pjugador: jugador.o pruebaJugador.c
	gcc jugador.o pruebaJugador.c -o pj
normalizar: normalizar.c 
	gcc normalizar.c -c -lm
maxmin: maxMin.c
	gcc maxMin.c -c
pmm: maxMin.o pruebaMaxMin.c
	gcc maxMin.o pruebaMaxMin.c -o pmm
eMM: maxMin.o encuentraMaxMin.c
	gcc maxMin.o encuentraMaxMin.c -o eMM
cola: colaEnteros.c
	gcc colaEnteros.c -c
xd: jugador.o colaEnteros.o normalizar.o maxMin.o xd.c
	gcc jugador.o maxMin.o normalizar.o colaEnteros.o xd.c -o xd -lm
menu: jugador.o colaEnteros.o normalizar.o maxMin.o main.o menu.c
	gcc jugador.o maxMin.o normalizar.o colaEnteros.o main.o menu.c -o menu -lm
clean:
	rm -rf *.o eMM pmm xd a.out main pj menu
