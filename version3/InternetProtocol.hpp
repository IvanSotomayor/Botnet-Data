#include <iostream>
using namespace std;

class InternetProtocol{
    string ip;
    int num_accesos;
public:
    InternetProtocol(string ip, int num_accesos);
    string getIp();
    void setIp(string ip);
    int getNumAccesos();
    void setNumAccesos(int accesos);
};