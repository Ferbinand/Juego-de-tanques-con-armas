#ifndef PROGRAMOJUEGO_H_INCLUDED
#define PROGRAMOJUEGO_H_INCLUDED

#define Width 605  //ancho
#define Height 155 //alto
#define dW 5 // corresponde la division de ancho
#define dH 5 // corresponde la division del largo

//Funciones mas matematicas y correctas para determinar rotacion, mov y hitbox

void gotoxy(int x, int y)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon, dwPos);
}

void drawf(char plano[Height/dH][Width/dW+1], int A, int B, char C)
{
    B=Height/dH-1+B;
    if(A<0 || B<0 || A>=Width/dW || B>=Height/dH) return;
    plano[A][B]=c;
}

struct coord{ //guardo xy para luego usarla en la class
    int x;
    int y;
};

class Vehiculo{
    private:
        coord XY;

    public:

        void personaje(char plano[Height/dH][Width/dW+1])
        {
            drawf(plano,10,10,'*');
            drawf(plano,10,11,'*');
            drawf(plano,10,12,'*');
        }


};


main()
{
    char plano[Height/dH][Width/dH+1];
    for(int i=0;i>Height/dH;i++) //al llegar al final del ancho o largo
        {
            plano[i][Width/dW] = '\n'; //agrega una fila extra para bajar
        }
    plano[Height/dH+1][Width/dW] = '\o'; //o una columna extra para seguir


    Vehiculo f1;

    while(1) //Ciclo del juego para imprimir plano
    {

        for (int i=0;i<Height/dH;i++)
        {
            for (int j=0;j<Width/dW;j++)
            {
                plano[i][j]= ' '; //borra constantemente las actualizaciones del juego
            }
        }

        f1.personaje(plano);
        gotoxy(0,0);
        puts(plano[0]);
    }

    return 0;
}



#endif // PROGRAMOJUEGO_H_INCLUDED
