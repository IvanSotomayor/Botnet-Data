#include "bitacora.hpp"

Bitacora::Bitacora(string mes, string dia, string hora, string minutos_segundos,string ipp, string falla){
    this->mes=mes;
    this->dia=dia;
    this->hora=hora;
    this->minutos_segundos = minutos_segundos;
    this->ipp=ipp;
    this->falla=falla;
    this->asignarClave();
    this->asignarTipo();
}

Bitacora::Bitacora(string mes,string dia){
    this->mes = mes;
    this->dia = dia;
}

string Bitacora::mesANumero(){   //Complejidad o(1)
    if(!this->mes.compare("Jun")) 
        return "6";
    else if(!this->mes.compare("May"))
        return "5";
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
    string id = this->mesANumero()+this->dia; 
    stringstream string2int(id);
    string2int>>this->clave;     
}

void Bitacora::asignarTipo(){
    if(this->falla == "Failed password for illegal user guest\r"){
        this->tipo = 1;
    }
    else if(this->falla == "Failed password for admin\r"){
        this->tipo = 2;
    }
    else if(this->falla == "Illegal user\r"){
        this->tipo = 3;
    }
    else if(this->falla == "Failed password for illegal user root\r"){
        this->tipo = 4;
    }else{
        this->tipo = 0;
    }
}


int registro::busquedaBinaria(dateTime k) {
  int low = 0;
  int high = myVect.size() - 1;
  while (low <= high) {
    int m = low + (high - low) / 2;
    if (k == myVect[m].getFechaHora()) 
      return m;
    else if (k < myVect[m].getFechaHora())
      high = m - 1;
    else
      low = m + 1;
  }
  return -1;
}


