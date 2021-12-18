#include <iostream>
#include <fstream>
#include "InternetProtocol.hpp" 
#include "ListaCDL.hpp"
#include "bst.hpp"
using namespace std;

int main(){

    //Creando la lista circular doblemente ligada de Ips
    ListaCDL<InternetProtocol*> listaIps;
    cout << "Leyendo..." <<endl;
    listaIps.leerBitacora("bitacoraCompleta.txt");
    cout << "Archivo leido correctamente " <<endl;
    cout <<"-----------------------------"<<endl;
    //Imprimiendo lista de ips en documento ipsAccesos.txt
    listaIps.imprimirLista();

    //Crear el arbol binario de busquedas con objetos Accesos
    BST<Accesos*> arbolDeAccesos;
    arbolDeAccesos.createTree(listaIps);

    //Impresion Level by level del arbol
    //cout << "Impresion nivel por nivel del arbol: "<<endl;
    //arbolDeAccesos.imprimirLevelByLevel();

    //Impresion en preorden del arbol
    //cout << "Impresion en preorden del arbol: "<<endl;
    //arbolDeAccesos.imprimirPreorden();

    //Buscar por numero de accesos
    int accesos_usuario;
    cout << "Ingresa la cantidad de accesos de Ip, que quieres consultar: ";
    cin >> accesos_usuario;

    //Se desplega las ips que tengan el numero de accesos que eliga el usuario
    arbolDeAccesos.deplegarIps(accesos_usuario);

}