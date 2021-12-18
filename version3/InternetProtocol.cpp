#include "InternetProtocol.hpp"

InternetProtocol::InternetProtocol(string ip, int num_accesos){
    this->ip = ip;
    this->num_accesos = num_accesos;
}
string InternetProtocol::getIp(){
    return this->ip;
}
void InternetProtocol::setIp(string ip){
    this->ip = ip;
}
int InternetProtocol::getNumAccesos(){
    return this->num_accesos;
}
void InternetProtocol::setNumAccesos(int accesos){
    this->num_accesos = accesos;
}