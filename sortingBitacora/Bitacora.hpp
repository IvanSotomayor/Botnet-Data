# Bitacora.hpp

```cpp
#include <string>
#include <iostream>
#include <sstream> //Lectura de flujos de strings
#include <vector>

using namespace std;

class Bitacora{
    //Atributos
    private:
        string mes;
        string dia;
        string hora;
        string ipp;
        string falla;
        int clave;
    //Métodos
    public:
        Bitacora(string mes, string dia, string hora, string ipp, string falla);
        Bitacora(string mes,string dia);
        string getMes(){return this->mes;}
        void setMes(string mes){this->mes=mes;}
        string getDia(){return this->dia;}
        void setDia(string dia){this->dia=dia;}
        string getHora(){return this->hora;}
        void setHora(string hora){this->hora=hora;}
        string getIpp(){return this->ipp;}
        void setIpp(string ipp){this->ipp=ipp;}
        string getFalla(){return this->falla;}
        void setFalla(string falla){this->falla=falla;}
        int getClave(){return this->clave;}
        void setClave(int clave){this->clave=clave;}
        string mesANumero();
        void asignarClave();
        void imprimirRegistro();
        void merge(vector<Bitacora*>&array, int inicio,int mitad, int fin);
        void mergeSort(vector<Bitacora*>&array, int inicio, int fin);
};

  
```
