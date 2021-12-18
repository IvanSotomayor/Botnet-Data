#include <iostream>
#include <sstream> //Lectura de flujos de strings
#include <string>
#include <vector>
using namespace std;

class Falla{
private:
    string falla ;
    int ocurrencia;
    int meses[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int tipo;
public:
    Falla(string falla, int ocurrencia, string mes, int tipo);
    string getFalla();
    void setFalla(string falla);
    int getOcurrencia();
    void setOcurrencia(int ocurrencias);
    void sumarOcurrencia();
    void sumarMes(string mes);
    void desplegarFallas();
    int getTipo();
    void setTipo(int tipo);

    friend ostream& operator<<(ostream& salida, const Falla& objeto){
        salida<<objeto.falla<<endl;
        salida<<"Numero de ocurrencias totales de este tipo "<<objeto.ocurrencia<<endl;
        vector <string> meses = 
        {
         "enero","febrero","marzo","abril","mayo","junio",
         "julio","agosto","septiembre ","octubre","noviembre",
         "diciembre",
        };
        for(int i = 0; i < 12; i++){
            salida<<meses[i] <<" ---> "<<objeto.meses[i]<<" "<<endl;
        }
        return salida;
    }

};