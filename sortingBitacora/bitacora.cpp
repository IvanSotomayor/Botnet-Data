#include "bitacora.hpp"

Bitacora::Bitacora(string mes, string dia, string hora, string ipp, string falla){
    this->mes=mes;
    this->dia=dia;
    this->hora=hora;
    this->ipp=ipp;
    this->falla=falla;
    //Llamar al metodo asignar clave
    this->asignarClave();
}

Bitacora::Bitacora(string mes,string dia){
    this->mes = mes;
    this->dia = dia;
}

string Bitacora::mesANumero(){   //Complejidad o(1)
    if(!this->mes.compare("Jun")) // ! not
        return "6";
    else if(!this->mes.compare("Jul"))
        return "7";
    else if(!this->mes.compare("Aug"))
        return "8";
    else if(!this->mes.compare("Sep"))
        return "9";
    else if(!this->mes.compare("Oct"))
        return "10";
    else if(!this->mes.compare("Nov"))
        return "11";
    else if(!this->mes.compare("Dec"))
        return "12";
    else
        return "0";
}

void Bitacora::asignarClave(){ //Complejidad o(1)
    string id=this->mesANumero()+this->dia; //Concatenar el mes con el dia para crear la clave
    stringstream string2int(id);
    string2int>>this->clave; //Conversion de string a int        
}

void Bitacora::imprimirRegistro(){  //Complejidad o(1)
    cout<<this->mes<<" "<<this->dia<<" "<<this->hora<<" "<<this->ipp<<" "<<this->falla<<"\n";
}

void Bitacora::merge(vector<Bitacora*>&array, int inicio,int mitad, int fin){ 
    int i, j, k;
    int n1 = mitad-inicio+1; //numero de elementos de izq
    int n2 = fin-mitad; //numero de elementos de der
    // Reservar espacio derecha e izquierda
    vector<Bitacora*>Izq(n1);
    vector<Bitacora*> Der(n2);
    // Copiar datos de arreglo en izq y der
    for(i=0;i<n1;i++)
        Izq[i]=array[inicio+i];
    for(j=0;j<n2;j++)
        Der[j]=array[mitad+1+j];
    
    //Realizar merge cuando tenemos dos arreglos
    i=0;
    j=0;
    k=inicio;
    while(i<n1 && j<n2){
        if (Izq[i]->getClave()<=Der[j]->getClave()){
            array[k]=Izq[i];
            i++;
        }else{
            array[k]=Der[j];
            j++;
        }
        k++;
    }
    //Vaciar lo que resta de der
    while(j<n2){
        array[k]=Der[j];
        j++;
        k++;
    }
    //Vaciar lo que resta de izq
    while(i<n1){
        array[k]=Izq[i];
        i++;
        k++;
    }
}

void Bitacora::mergeSort(vector<Bitacora*>&array, int inicio, int fin){ //Complejidad o(n*log(n))
    if(inicio<fin){ //Caso de recursión
        int mitad= inicio +(fin-inicio)/2; 
        mergeSort(array,inicio,mitad); //Parte izq
        mergeSort(array,mitad+1,fin); //Parte der
        merge(array,inicio, mitad,fin); //Integrar nuestro arreglo        
    }
    //Caso base
}