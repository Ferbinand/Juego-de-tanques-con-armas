#ifndef LOGICATANK_H_INCLUDED
#define LOGICATANK_H_INCLUDED


void CargarCadena(char *pal, int tam);
void MenuPrincipal(); ///Imprime menu
void Gotoxy(int x, int y); //Imprime en det lugar
void OcultarCursor();

void CargarCadena(char *pal, int tam){
  int i;
  fflush(stdin);
  for(i=0;i<tam;i++){
      pal[i]=cin.get();
	  if(pal[i]=='\n') break;
	  }
  pal[i]='\0';
  fflush(stdin);
}

void MenuPrincipal(){
    system("cls");
    cout << "********** MENU  **********" << endl;
    cout << "***************************" << endl;
    cout << "1. JUGAR" << endl;
    //if(Played){
    cout << "2." << endl;
    cout << "3." << endl;
    cout << "4." << endl;
    //}
    cout << "0. SALIR " << endl;
    cout << "***************************" << endl;
    cout << "Ingrese una opcion " << endl;
}

void Gotoxy(int x, int y){
    HANDLE hCon; //nombre de la pantalla a controlar
    hCon = GetStdHandle(STD_OUTPUT_HANDLE); //trae el tipo de parametro de la salida de la consola
    COORD dwPos; //es un tipo de estructura de dato que devuelve x e y
    dwPos.X = x; //enters
    dwPos.Y = y; //espacios

    SetConsoleCursorPosition(hCon, dwPos); //le paso la coordenada
}

void OcultarCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci; // Estructura de datos que guarda info del cursor y parametros
    cci.dwSize = 1;  //tamaño del cursor
    cci.bVisible = FALSE; //visible?

    SetConsoleCursorInfo(hCon, &cci); //se pasa por ref para no modificarlo
}

#endif // LOGICATANK_H_INCLUDED
