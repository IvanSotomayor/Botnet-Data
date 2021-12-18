#include "Accesos.hpp"

Accesos::Accesos(int numeroAccesos, string ip){
    this->numeroAccesos = numeroAccesos;
    this->ip = ip;
    this->lista_ips->agregarFinal(ip);
}

string Accesos::getIp(){
    return this->ip;
}

void Accesos::setIp(string ip){
    this->ip = ip;
}

int Accesos::getAccesos(){
    return this->numeroAccesos;
}

void Accesos::setAccesos(int numero){
    this->numeroAccesos = numero;
}

void Accesos::agregarIp(string ip_string){
    this->lista_ips->agregarFinal(ip_string);
}

void Accesos::imprimirIps(){
    if(this->lista_ips->getHead()){
        this->lista_ips->imprimirLista();
    }else{
        cout << "No hay registros disponibles" <<endl;
    }
}