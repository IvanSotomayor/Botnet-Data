#Main.cpp
```c++
#include "bitacora.hpp"
#include <vector>
#include <fstream> 

int main(){

    Bitacora* prueba; 

    //Se lee el archivo txt y los registros se meten a un vector de objetos
    ifstream datos;
    datos.open("bitacoraPrincipal.txt");
    string mes, dia,hora,ipp,falla;
    vector<Bitacora *> log;
    while(datos.good()){        //Complejidad o(n)
        getline(datos,mes,' ');
        getline(datos,dia,' ');
        getline(datos,hora,' ');
        getline(datos,ipp,' ');
        getline(datos,falla);
        log.push_back(new Bitacora(mes,dia,hora,ipp,falla));
    }

    datos.close();

    //Se ordena el arreglo de objetos  complejidad o(n*log(n))
    prueba->mergeSort(log,0,log.size()-1);

    //Se recorre todo arreglo ordenado y se imprime en un txt Complejidad o(n)
    ofstream myFile("BitacoraOrdenada.txt"); 
    for(Bitacora * entry:log){
        myFile << entry->getMes() << " ";
        myFile << entry->getDia() << " ";
        myFile << entry->getHora() << " ";
        myFile << entry->getIpp() << " ";
        myFile << entry->getFalla() <<endl;
    }
    myFile.close();


    //Archivo de registros de la bitacora ordenados por intervalos de fechas
    //Dia y Mes
    ofstream myFile2("OrdenadaPorFechas.txt");
    string mes1;
    string mes2;
    string dia1;
    string dia2;
    cout << "Ingrese su primer dia: ";
    cin >> dia1;
    cout << "Ingrese su primer mes: ";
    cin >> mes1;
    cout << "Ingrese su segundo dia ";
    cin >> dia2;
    cout << "Ingrese su segundo mes: ";
    cin >> mes2;
    Bitacora fecha_uno(mes1,dia1);
    Bitacora fecha_dos(mes2,dia2);

    fecha_uno.asignarClave();
    fecha_dos.asignarClave();

    for(Bitacora* entry:log){  //Complejidad o(n)
        if(entry->getClave() >= fecha_uno.getClave() && entry->getClave() <= fecha_dos.getClave()){
            myFile2 << entry->getMes() << " ";
            myFile2 << entry->getDia() << " ";
            myFile2 << entry->getHora() << " ";
            myFile2 << entry->getIpp() << " ";
            myFile2 << entry->getFalla() <<endl;
        }
        //IF para que el for no recorra todo el vector 
        if(entry->getClave() > fecha_dos.getClave()){
            break;
        }
    }

    myFile2.close();

    return 0;
}
```
