#include <iostream>
#include <typeinfo>
#include <vector>
#include <algorithm>
#include <conio.h>
#include <fstream>
#include <sstream>

using namespace std;

void mayusculas(string &palabra){
    for(int i = 0; i < palabra.size(); i++){
        palabra[i] = toupper(palabra[i]);
    }
}

void tabla(string nombre, vector<pair<string,string> >cam){
    ofstream table("D:\\Trabajos 5to semestre\\Base de Datos II\\SGBD\\BD\\"+nombre+".txt");
    table.close();
    ofstream meta("D:\\Trabajos 5to semestre\\Base de Datos II\\SGBD\\BD\\METADATA.txt", ios::app);
    meta << nombre;
    for(int i = 0; i < cam.size(); i++){
        meta << " " << cam[i].first << " " << cam[i].second;
    }
    meta << endl;
    meta.close();
}

void create_table(){
    system ("cls");
    cout << "INGRESE EL CAMPO Y SU TIPO DE DATO SEPARADOS POR UN ESPACIO" << endl;
    cout << "PRESIONE ENTER PARA SEGUIR LLENANDO LOS CAMPOS Y CUALQUIER OTRA TECLA PARA SALIR" << endl;
    cout << endl;
    vector<pair<string,string> > campos;
    string nombre, camp, tipo;
    bool val = 1;
    cout << "INGRESE EL NOMBRE DE LA TABLA: ";
    cin >> nombre;
    mayusculas(nombre);
    ifstream meta("D:\\Trabajos 5to semestre\\Base de Datos II\\SGBD\\BD\\METADATA.txt");
    string temp;
    while(getline(meta, temp)){
        stringstream str(temp);
        string valor;
        getline(str, valor, ' ');
        if(nombre == valor){
            cout << "TABLA YA EXISTENTE" << endl;
            meta.close();
            system("pause");
            return;
        }
    }
    int contador = 1;
    while(val){
        cout << "ATRIBUTO " << contador << " : ";
        cin >> camp;
        cin >> tipo;
        mayusculas(camp);
        mayusculas(tipo);
        if(tipo == "INTEGER"){
            campos.push_back(make_pair(camp,tipo));
            contador++;
        } else if(tipo == "STRING"){
            campos.push_back(make_pair(camp,tipo));
            contador++;
        } else if(tipo == "DATE"){
            campos.push_back(make_pair(camp,tipo));
            contador++;
        }
        else{
            cout << "TIPO DE DATO NO VALIDO" << endl;
        }
        cout << "Desea continuar?: " << endl;
        if(getch() == 13) continue;
        else val = 0;
    }
    tabla(nombre,campos);
    system("pause");
}

int main()
{
    int opcion;
    do{
    system ("cls");
    cout<<"1. CREATE TABLE\n";
    cout<<"2. INSERTO INTO\n";
    cout<<"3. DELETE FROM\n";
    cout<<"4. DROP TABLE\n";
    cout<<"0. SALIR DEL PROGRAMA\n";
    cin>>opcion;
    if(opcion >= 0 && opcion < 5){
        switch(opcion){
            case 1:{
                create_table();
                break;
                }//case 1 switch1
            case 2:{
                break;
                }//case 2 switch1
            case 3:{
                break;
                }//case 3 switch1
            case 4:{
                break;
                }//case 4 switch1
            case 5:{
                break;
                }//case5 switch1
        }//fin de switch
     }
    }while(opcion!=0);
    return 0;
}
