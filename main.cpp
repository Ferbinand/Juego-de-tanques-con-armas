/*UTN
JUEGO DE TANQUES
Autor: Mariano Alejandro Visgarra


Descripcion: Juego con vista isometrica de tanques

Ingreso por teclado: Direccion de los tanques y disparado

Ideas:  * 4 jugadores / 2 jugadores
        * Varias armas (objeto dentro del tanque)
        * Varios tipos de bala (dentro de cada arma)
*/

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <windows.h> //permite dar posicion al cursor
#include <conio.h>


using namespace std;

#include "LogicaTank.h"
#include "Tanks.h"

int main () {
    int option;
    Tanks tank1(1, 1, 1, 1, 1, 1, 1, 1, 1);
    tank1.drawTankUp();
	while(true){
        MenuPrincipal();
        cin >> option;
        OcultarCursor();

        switch (option){
            case 1:{
                bool gameOver=false;

                system("cls");
                int x=5, y=4;
                Gotoxy(x,y);

                while(!gameOver){
                    tank1.moveTank();
                    Sleep(30);
                }
                Gotoxy(0,0);
                cout << "Game Over" << endl;
                system("pause");}
                break;
            case 0:
                return 0;
            default:
                cout << "Ingrese una opcion correcta..." << endl;
                system("pause");
                break;
        }
    }


	cout << "Hello World" << endl;
	system("pause");
	return 0;
}
