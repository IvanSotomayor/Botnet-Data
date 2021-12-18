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
    NodoDL(T valor,NodoDL<T> * siguiente, NodoDL<T> * anterior){
        this->valor=valor;
        this->siguiente = siguiente;
        this->anterior = anterior;
    }
};

template<typename T>
class ListaDL{
    NodoDL<T> * head;
    NodoDL<T> * tail;
    int tam;
public:
    int getTam(){return this->tam;}
    void setTam(int tam){this->tam = tam;}
    NodoDL<T> * getHead(){return this->head;}
    void setHead(NodoDL<T> * head){this->head = head;}

    ListaDL(){
        this->head=nullptr;
        this->tam=0;
    }

    void agregarInicio(T valor){  //Complejidad O(1)
        NodoDL<T> * nuevo = new NodoDL<T>(valor,this->head,nullptr); //Crear nuevo nodo
        if(this->head) //Lista con elementos
            this->head->setAnterior(nuevo);
        this->head=nuevo;//Actualizar el head de listaDL
        this->tam++; //Actualizar el tamaño            
    }

    void agregaFinal(T valor){   //Complejidad O(n)
        NodoDL<T> * nuevo=new NodoDL<T>(valor,nullptr,nullptr);
        if(this->head){
            //Encontrar el ultimo nodo
            NodoDL<T> * nodo=this->head;
            while(nodo->getSiguiente()){
                nodo=nodo->getSiguiente();
            }
            nodo->setSiguiente(nuevo);
            nuevo->setAnterior(nodo);
        }else
            this->head=nuevo;
        this->tam++;                      
    }

    void imprimirLista(){  //Complejidad O(n)
        NodoDL<T> * nodo=this->head;
        while(nodo){
            nodo->getValor()->imprimirRegistro();
            nodo=nodo->getSiguiente();
        }
        cout<<endl;
    }

    //Esta funcion verifica que los elementos se insertaron
    //correctamente en la lista enlazada o(n)
    void prueba_dl(){  
        NodoDL<T> * nodo=this->head;
        ofstream myFile("BitacoraDL.txt"); 
        while(nodo){
            myFile << nodo->getValor()->getMes() << " ";
            myFile << nodo->getValor()->getDia() << " ";
            myFile << nodo->getValor()->getHora() << " ";
            myFile << nodo->getValor()->getIpp() << " ";
            myFile << nodo->getValor()->getFalla() << endl;
            nodo=nodo->getSiguiente();
        }
        myFile.close();
    }

    void imprimirListaReversa(){  //Complejidad O(n)
        if(this->head){
            NodoDL<T> * nodo=this->head;
            //Encontrar el último
            while(nodo->getSiguiente())
                nodo=nodo->getSiguiente();

            while(nodo){
                cout<<nodo->getValor()<<" ";
                nodo=nodo->getAnterior();                
            }
            cout<<endl;
        }else
            cout<<"Lista vacia"<<endl;
    }

    //Complejidad O(n)
    void filtrarPorHora(string hora){
        ofstream myFile("FiltradoHora.txt");
        if(this->head){
            NodoDL<T> * elemento = this->head;
            while(elemento){
                if(elemento->getValor()->getHora() == hora){
                    myFile << elemento->getValor()->getMes() << " ";
                    myFile << elemento->getValor()->getDia() << " ";
                    myFile << elemento->getValor()->getHora() << ":";
                    myFile << elemento->getValor()->getMinutosSegundos() << " ";
                    myFile << elemento->getValor()->getIpp() << " ";
                    myFile << elemento->getValor()->getFalla() << endl;
                }
                elemento = elemento->getSiguiente();
            }
        }else{
            cout<<"Lista vacía"<<endl;
        }   
        myFile.close();
    }
};