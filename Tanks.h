#ifndef TANKS_H_INCLUDED
#define TANKS_H_INCLUDED

/*TAREAS:
poner FileTanks nombre del archivo



*/
class Tanks{
private:
    int tankID; //no repite
   // char tankName[30]; //no pude inicializar constructor
    int tankColor; // 1 a 5
    int tankWeapon; //Tipo de arma que lleva ID de arma relacionado
    int tankAttack; //entre 1 y 10
    int tankVelocity; // 1 a 10
    int tankDefense; // 1 a 10
    bool tankState;

    ///atributos de mov
    int x, y;


public:
    ///CONSTRUCTOR
    Tanks(int id, int color, int weapon, int atk, int vel, int def, bool estad, int _x, int _y): tankID(id), tankColor(color), tankWeapon(weapon), tankAttack(atk), tankVelocity(vel), tankDefense(def), tankState(estad), x(_x), y(_y){}
    ///SETS
//------------------------------------------------------------
    void setTankID(int id){tankID=id;}                                ///IDTank
   // void setTankName(const char *n){strcpy(tankName, n);}             ///NombreTank
    void setTankColor(int num){tankColor=num;}                        ///Color
    void setTankWeapon(int num){if(num>=1&&num<=10)tankWeapon=num;}   ///Arma  (unico con validacion por ahora)
    void setTankAttack(int num){tankAttack=num;}                      ///Ataque
    void setTankVelocity(int num){tankVelocity=num;}                  ///Velocidad
    void setTankDefense(int num){tankDefense=num;}                    ///Defensa
    void setTankState(bool s){tankState=s;}                           ///Estado


    ///GETS
//------------------------------------------------------------
    int getTankID(){return tankID;}                             ///IDTank
  //  char *getTankName(){return tankName;}                       ///NombreTank
    int getTankColor(){return tankColor;}                       ///Color
    int getTankWeapon(){return tankWeapon;}                     ///Arma
    int getTankAttack(){return tankAttack;}                     ///Ataque
    int getTankVelocity(){return tankVelocity;}                 ///Velicidad
    int getTankDefense(){return tankDefense;}                   ///Defensa
    bool getTankState(){return tankState;}                      ///Estado


    ///OTROS
//------------------------------------------------------------
    //Funciones ABM  , Carga y Datos.
    bool leerDisco(int pos);
    bool grabarDisco();
    bool modificarDisco(int pos);
    void bajaLogica();
    int buscarIDTank(int i);
    Tanks cargarTank();

    //Funciones de movimiento y logica
    void drawTankUp();
    void drawTankDown();
    void drawTankLeft();
    void drawTankRight();
    void cleanTank();
    void moveTank();

    //Otros botones
    void shoot(int weapon);


};
/*

///ABM ARCHIVO DE TANQUES
//------------------------------------------------------------

bool Tanks::leerDisco(int pos){
        FILE *p;
        p=fopen("Tank.dat", "rb");
        if(p==NULL&&pos>0){
            cout << "No pudo abrir el archivo"<<endl;
            return false;
        }
        fseek (p, pos*sizeof(Tanks),0);
        bool leyo=fread(this,sizeof(Tanks),1,p);
        fclose(p);
        return leyo;
}

bool Tanks::grabarDisco(){
    FILE *p;
    p=fopen("Tanks.dat", "ab");
    if(p==NULL){
        cout << "No pudo abrir el archivo"<<endl;
        return false;
    }
    bool escribio=fwrite(this,sizeof(Tanks),1,p);
    fclose(p);
    return escribio;
}

bool Tanks::modificarDisco(int pos){
    FILE *p;
    p=fopen("Tanks.dat", "rb+");
    if(p==NULL){
        cout << "No pudo abrir el archivo"<<endl;
        return false;
    }
    fseek (p, pos*sizeof(Tanks),0);
    bool modifico=fwrite(this,sizeof(Tanks),1,p);
    fclose(p);
    return modifico;
}

int Tanks::buscarIDTank(int i){
    FILE *p;
    int c=0;
    Tanks obj;
    p=fopen("Tanks.dat","rb");
    while(fread(&obj, sizeof obj, 1,p)==1){
       if(obj.getTankID()==i){
        fclose(p);
        return c;
       }
       c++;
    }
    fclose(p);
    return -1;
}

void Tanks::bajaLogica(){
    int id,pos;
    cout<<"ID DEL TANQUE A ELIMINAR: ";
    cin>>id;
    cout<<endl;
    pos=buscarIDTank(id);
    if(pos>-1){
    leerDisco(pos);
    setTankState(false);
    if(modificarDisco(pos)==true){
     cout<<"EL TANQUE FUE ELIMINADO EXITOSAMENTE"<<endl;
    }else{
        cout<<"EL TANQUE NO PUDO SER ELIMINADO"<<endl;
        }
    }
    else{
    cout<<"ESE ID NO ESTA EN EL ARCHIVO";
    }
}

///FIN ABM ARCHIVO DE TANQUES
//------------------------------------------------------------

*/

/*
///Funciones de datos y Stats
void Tanks::loadTank(){

    setTankID(autoNumTank()); //si no funciona asignar primero a una variable int y luego a set tank ID
    cout<<"ID CANCION: "<<getIDcancion()<<endl;
    cout<<"INGRESE NOMBRE DE LA CANCION: ";
    CargarCadena(nombre,29);
    cout<<"INGRESE NOMBRE DEL AUTOR/COMPOSITOR: ";
    CargarCadena(nombreAut,29);

    }while(pos==-1);
    cout<<"INGRESE FECHA DE ESTRENO: ";
    fechadeEstreno.Cargar();
    do{
    cout<<"INGRESE DURACION DE LA CANCION: ";
    cin>>d;
    }while(d<0);
    setDuracion(d);
    do{
    cout<<"INGRESE GENERO MUSICAL (1 A 10): ";
    cin>>g;
    }while(g<0||g>10);
    setGenero(g);
    tankState=true;
    cout<<endl;
}

void Tanks::showTanks(){
    int pos=0;
    Tanks obj;
    while(obj.leerDisco(pos)){
       obj.mostrar();
       cout<<endl;
       pos++;
    }
}

void Tanks::mostrar(){
    if(tankState==true){
    cout<<"ID TANQUE: "<<tankID<<endl;
    cout<<"NOMBRE DEL TANQUE: "<<tankName<<endl;
    cout<<"COLOR: "<<tankColor<<endl;
    cout<<"ARMA: "<<tankWeapon<<endl;
    cout<<"ATAQUE: "<<tankAttack<<endl;
    cout<<"VELOCIDAD: "<<tankVelocity<<endl;
    cout<<"DEFENSA: "<<tankDefense<<endl;
    }
}

int autoNumTank(){
 int pos=0;
 Tanks obj;
 while(obj.leerDisco(pos)){
    pos++;
    }
    return pos+1;
}

Tanks cargarTank(){
    Tanks obj;
    obj.cargar();
    return obj;
}
/// FIN FUNCIONES DATOS Y STATS
//---------------------------------------------------
*/

/// FUNC MOVIMIENTO / PINTAR / BORRAR FISICAS

void Tanks::drawTankUp(){
    Gotoxy(x,y); printf(" %c ", 186);
    Gotoxy(x,y+1); printf("%c%c%c", 201,219,187);
    Gotoxy(x,y+2); printf("%c%c%c", 200,205,188);
}
void Tanks::drawTankDown(){
    Gotoxy(x,y); printf("%c%c%c", 201,205,187);
    Gotoxy(x,y+1); printf("%c%c%c", 200,219,188);
    Gotoxy(x,y+2); printf(" %c ", 186);
}
void Tanks::drawTankLeft(){
    Gotoxy(x,y); printf("  %c%c", 95, 95);
    Gotoxy(x,y+1); printf("%c%c%c", 205, 219, 186);
    Gotoxy(x,y+2); printf("  %c%c",238,238);
}
void Tanks::drawTankRight(){
    Gotoxy(x,y); printf("%c%c  ", 95, 95);
    Gotoxy(x,y+1); printf("%c%c%c", 186, 219, 205);
    Gotoxy(x,y+2); printf("%c%c  ",238,238);
}
void Tanks::cleanTank(){
    Gotoxy(x,y); cout << "      ";
    Gotoxy(x,y+1); cout << "      ";
    Gotoxy(x,y+2); cout << "      ";
}

void Tanks::moveTank(){
    if(kbhit()){
        char tecla=getch();
        cleanTank();
        if(tecla=='a') { //izquierda
            x--;
            drawTankLeft();
        }
        if(tecla=='d') { //derecha
            x++;
            drawTankRight();
        }
        if(tecla=='w') { //arriba
            y--;
            drawTankUp();
        }
        if(tecla=='s') {//abajo
            y++;
            drawTankDown();
        }

    }
}


/// FIN FUNCIONES FISICAS / PINTAR / BORRAR
//---------------------------------------------------
/*
OTRAS FUNCIONES O VALIDACIONES UTILES
 Checkea si existe ese ID y sino no se puede asignar nada porque no existe
do{
    cout<<"INGRESE ID DEL INTERPRETE: ";
    cin>>ii;
    pos=obj.buscarIDinterprete(ii);
    if(pos>-1){
    setIDinterprete(ii);
    }else{
    cout<<"EL ID NO EXISTE EN EL ARCHIVO DE INTERPRETES"<<endl;
    cout<<endl;
    }


*/


#endif // TANKS_H_INCLUDED
