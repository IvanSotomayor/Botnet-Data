#include <iostream>
#include "ListaSimple.hpp"
using namespace std;

class Accesos{
    int numeroAccesos;
    string ip;
    ListaSimple<string> * lista_ips = new ListaSimple<string>();
public:
    Accesos(int numeroAccesos, string ip);
    string getIp();
    void setIp(string ip);
    int getAccesos();
    void setAccesos(int numero);
    void agregarIp(string ip_string);
    void imprimirIps();
};