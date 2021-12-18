#include <iostream>
#include <fstream> 
using namespace std;

template<typename T>
class NodoDL{
    T valor;
    NodoDL<T> * siguiente;
    NodoDL<T> * anterior;
public:
    //Metodos
    T getValor(){return this->valor;}
    void setValor(T valor){this->valor = valor;}
    NodoDL<T> * getSiguiente(){return this->siguiente;}
    void setSiguiente(NodoDL<T> * siguiente){this->siguiente = siguiente;}
    NodoDL<T> * getAnterior(){return this->anterior;}
    void setAnterior(NodoDL<T> * anterior){this->anterior = anterior;}
    //Constructores
    NodoDL(T valor, NodoDL<T> * siguiente, NodoDL<T> * anterior){
        this->valor=valor;
        this->siguiente = siguiente;
        this->anterior = anterior;
    }
};

template <typename T>
class ListaCDL{
    NodoDL<T> * head;
    int tam;
public:
    int getTam(){return this->tam;}
    void setTam(int tam){this->tam=tam;}
    NodoDL<T> * getHead(){return this->head;}
    void setHead(NodoDL<T> * head){this->head=head;}

    ListaCDL(){
        this->head=nullptr;
        this->tam=0;
    }

    //Complejidad O(1)
    void agregarVacio(T valor){
        NodoDL<T> * nuevo= new NodoDL<T>(valor,nullptr,nullptr);
        nuevo->setSiguiente(nuevo);
        nuevo->setAnterior(nuevo);
        this->head=nuevo;
    }

    //Complejidad O(1)
    void agregarInicio(T valor){
        if(this->head){ //Lista con nodos
            NodoDL<T> * nuevo=new NodoDL<T>(valor,this->head,this->head->getAnterior());
            this->head->getAnterior()->setSiguiente(nuevo);
            this->head->setAnterior(nuevo);
            this->head=nuevo;                
        }else //Lista sin nodos
            this->agregarVacio(valor);
        this->tam++;
    }

    //Complejidad O(1)
    void agregarFinal(T valor){
        if(this->head){ //Lista con nodos
            NodoDL<T> * nuevo=new NodoDL<T>(valor,this->head,this->head->getAnterior());
            this->head->getAnterior()->setSiguiente(nuevo);
            this->head->setAnterior(nuevo);                             
        }else //Lista sin nodos
            this->agregarVacio(valor);
        this->tam++;
    }

    //Complejidad O(n)
    NodoDL<T> * buscarNodo(T valor){
        if(this->head){
            NodoDL<T> * current = this->head;
            bool encontrado = false;
            do{
                if (current->getValor()->getIp() == valor->getIp()){
                    encontrado = true;
                    return current;
                }
                current = current->getSiguiente();
            }while(current != this->head);
            if (encontrado == false){
                return nullptr;
            }
        }
        return nullptr;
    }

    //Complejidad O(n)
    void leerBitacora(string nombre_bitacora){
        ifstream datos;
        datos.open(nombre_bitacora);
        string mes,dia,hora,ipp,puerto,falla;
        while(datos.good()){        //Complejidad o(n)
            getline(datos,mes,' ');
            getline(datos,dia,' ');
            getline(datos,hora,' ');
            getline(datos,ipp,':');
            getline(datos,puerto,' ');
            getline(datos,falla);
            InternetProtocol * nodo = new InternetProtocol(ipp,1);
            if(buscarNodo(nodo)){
                buscarNodo(nodo)->getValor()->setNumAccesos(buscarNodo(nodo)->getValor()->getNumAccesos()+1);
            }else{
                agregarFinal(nodo);
            }
        }
        datos.close();
    }

    //Complejidad O(n)
    void imprimirLista(){
        ofstream myFile("ipsAccesos.txt");
        if(this->head){
            NodoDL<T> * current = this->head;
            do{
                myFile << "IP:";
                myFile << current->getValor()->getIp() << " | ";
                myFile << "Numero de accesos: ";
                myFile << current->getValor()->getNumAccesos() <<endl;
                current = current->getSiguiente();
            }while(current != this->head);
        }else{
            cout << "lista vacia "<<endl;
        }
        myFile.close();
    }
};
