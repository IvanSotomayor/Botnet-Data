#include <iostream>
#include <sstream> //Lectura de flujos de strings
#include <string>
#include <vector>
using namespace std;

class Bitacora{
//Atributos
private:
    string mes;
    string dia;
    string hora;
    string minutos_segundos;
    string ipp;
    string falla;
    int clave;
    int tipo;
//Métodos
public:
    Bitacora(string mes, string dia, string hora, string minutos_segundos, string ipp, string falla);
    Bitacora(string mes,string dia);
    string getMes(){return this->mes;}
    void setMes(string mes){this->mes=mes;}
    string getDia(){return this->dia;}
    void setDia(string dia){this->dia=dia;}
    string getHora(){return this->hora;}
    void setHora(string hora){this->hora=hora;}
    string getMinutosSegundos(){return this->minutos_segundos;}
    void setMinutosSegundos(string minutosSegundos){this->minutos_segundos=minutos_segundos;}
    string getIpp(){return this->ipp;}
    void setIpp(string ipp){this->ipp=ipp;}
    string getFalla(){return this->falla;}
    void setFalla(string falla){this->falla=falla;}
    int getClave(){return this->clave;}
    void setClave(int clave){this->clave=clave;}
    string mesANumero();
    void asignarClave();
    void asignarTipo();
    int getTipo(){return this->tipo;}
    void setTipo(int tipo){this->tipo = tipo;}
};