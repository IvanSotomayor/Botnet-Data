#include "Falla.hpp"
#include <iostream>
#include <fstream>
#include <sstream> //Lectura de flujos de strings
#include <string>
#include <vector>
#include <sstream> 

Falla::Falla(string falla, int ocurrencia, string mes, int tipo){
    int mesConvertido;
    this->falla = falla;
    this->ocurrencia = ocurrencia;
    stringstream string2int(mes);
    string2int >> mesConvertido;
    mesConvertido = mesConvertido - 1;
    this->meses[mesConvertido]++;
    this->tipo = tipo;
}

string Falla::getFalla(){
    return this->falla;
}

void Falla::setFalla(string falla){
    this->falla = falla;
}

int Falla::getOcurrencia(){
    return this->ocurrencia;
}

void Falla::setOcurrencia(int ocurrencias){
    this->ocurrencia = ocurrencias;
}

void Falla::sumarOcurrencia(){
    this->ocurrencia++;
}

void Falla::sumarMes(string mes){
    int mesNumero;
    stringstream string2int(mes);
    string2int >> mesNumero;
    mesNumero = mesNumero - 1;
    this->meses[mesNumero]++;
}

int Falla::getTipo(){
    return this->tipo;
}

void Falla::setTipo(int tipo){
    this->tipo = tipo;
}


