#include <iostream>
#include <fstream>
using namespace std;

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
    void imprimirFallas(){
        ofstream myFile("Fallas.txt");
        if(this->head){
            NodoDL<T> * elemento=this->head;
            do{
                myFile<<* elemento->getValor()<<endl;
                elemento=elemento->getSiguiente();
            }while(elemento != this->head);
            myFile<<endl;
        }else{
            myFile<<"Lista vacía"<<endl;
        }   
        myFile.close();
    }

    //Complejidad O(n)
    NodoDL<T> * buscarNodo(T valor){
        if(this->head){
            NodoDL<T> * current = this->head;
            bool encontrado = false;
            do{
                if (current->getValor()->getFalla() == valor->getFalla()){
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
    void porFalla(T user_election){
        ofstream myFile("PorFalla.txt");
        NodoDL<T> * elemento=this->head;
        do{
            if(buscarNodo(user_election)){
                cout << "El elemento que buscabas se encontro esta en el archivo PorFalla.txt"<<endl;
                myFile << *buscarNodo(user_election)->getValor() << endl;
                break;
            }else{
                cout << "El elemento no se encuentra en esta lista:"<<endl;
            }
            elemento=elemento->getSiguiente();
        }while(elemento != this->head);
        myFile.close();
    }
};
