/* Ivan Ortega Sotomayor | A01383282
Bruno Cruz Mendoza | A01367102
Carlos Javier Leal Beltrán | A01741355 */

#include "bitacora.hpp"
#include "doublyLikedList.hpp"
#include "ListaCDL.hpp"
#include "Falla.hpp"
#include <vector>
#include <fstream> 

int main(){
    
    /*Se lee el archivo txt, cada uno de los
    registros se meten a una lista doblemente enlazada de objetos Bitacora*/
    //Complejidad O(n)
    ifstream datos;
    datos.open("bitacoraPrincipal.txt");
    string mes, dia,hora,minutos_segundos,ipp,falla;
    ListaDL <Bitacora*> registros;
    while(datos.good()){        //Complejidad o(n)
        getline(datos,mes,' ');
        getline(datos,dia,' ');
        getline(datos,hora,':');
        getline(datos,minutos_segundos,' ');
        getline(datos,ipp,' ');
        getline(datos,falla);
        registros.agregaFinal(new Bitacora(mes,dia,hora,minutos_segundos,ipp,falla));
    }
    datos.close();

    //Meter por falla a la lista circular
    ListaCDL <Falla*> lista_fallas;
    NodoDL<Bitacora*> * apuntadorDL = registros.getHead();
    
    //Complejidad o(n)
    while(apuntadorDL){
        string mes = apuntadorDL->getValor()->mesANumero();
        Falla * nuevo = new Falla(apuntadorDL->getValor()->getFalla(),1,mes,apuntadorDL->getValor()->getTipo());
        if(lista_fallas.buscarNodo(nuevo)){
            lista_fallas.buscarNodo(nuevo)->getValor()->sumarOcurrencia();
            lista_fallas.buscarNodo(nuevo)->getValor()->sumarMes(mes);
        }else{
            lista_fallas.agregarFinal(nuevo);
        }
        apuntadorDL = apuntadorDL->getSiguiente();
    }

    //Funcion para imprimir todas las fallas en un txt
    cout << "Se han impreso todas las fallas en el doc Fallas.txt"<<endl;
    lista_fallas.imprimirFallas();

    //Buscar por falla
    string tipo_usuario;
    cout << "Ingresa el nombre de la falla a buscar"<<endl;
    cout << "Las opciones las puedes encontrar en el archivo Fallas.txt"<<endl;
    cout << "Falla a buscar: "; getline(cin,tipo_usuario);
    tipo_usuario = tipo_usuario + "\r";
    Falla * user = new Falla(tipo_usuario,1,"1",1);
    lista_fallas.porFalla(user);

    //Filtrar los registros por hora
    string hora_filtrar;
    cout << "Ingresa la hora a filtrar: "; cin >> hora_filtrar;
    registros.filtrarPorHora(hora_filtrar);
    cout << "La hora que filtraste esta en el archivo FiltradoHora.txt"<<endl;

    return 0;
}