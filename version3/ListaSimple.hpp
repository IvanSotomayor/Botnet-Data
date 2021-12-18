#include <iostream>
using namespace std;

template <typename T>
class NodoSmp{
    T valor;
    NodoSmp * siguiente;
public:
    T getValor(){return this->valor;}
    void setValor(T valor){this->valor=valor;}
    NodoSmp * getSiguiente(){return this->siguiente;}
    void setSiguiente(NodoSmp * siguiente){this->siguiente=siguiente;}
    NodoSmp(T valor, NodoSmp * siguiente){
        this->valor=valor;
        this->siguiente=siguiente;
    }
};

template <typename T>
class ListaSimple{
    NodoSmp<T> * head;
    int tam;
public:
    int getTam(){return this->tam;}
    void setTam(int tam){this->tam=tam;}
    NodoSmp<T> * getHead(){return this->head;}
    void setHead(NodoSmp<T> * head){this->head=head;}

    ListaSimple(){
        this->head=nullptr;
        this->tam=0;
    }

    //Agregar nodo al inicio
    void agregarInicio(T valor){
        NodoSmp<T> * nuevo=new NodoSmp<T>(valor,this->head);  //Crear el nuevo nodo
        this->head=nuevo; //Actualizando el head de la lista al nuevo nodo
        //this->head=new Nodo(valor,this->head);
        this->tam++; //Actualizando el tamaño
    }

    //Agregar nodo al final
    void agregarFinal(T valor){
        NodoSmp<T> * nuevo=new NodoSmp<T>(valor,nullptr);  //Crear el nuevo nodo
        if(this->head){//Lista tiene nodos
            NodoSmp<T> * nodo=this->head;
            //Encontrar el último nodo
            while(nodo->getSiguiente())
                nodo=nodo->getSiguiente();
            nodo->setSiguiente(nuevo); //Actualizar el ultimo siguiente con el nuevo
        }else{ //Lista vacia
            this->head=nuevo;
        }
        this->tam++;
    }

    //Complejidad O(n)
    void imprimirLista(){
        cout << endl;
        NodoSmp<T> * nodo=this->head;
        cout << "IP's con ese numero de accesos: "<<endl;
        cout <<"---------------------------------"<<endl;
        while(nodo){
            cout << nodo->getValor()<<endl;
            nodo=nodo->getSiguiente();
        }
        cout<<endl;
    }

    //Complejidad O(n)
    NodoSmp<T> * buscarNodo(T valor){
        NodoSmp<T> * nodo=this->head;
        while(nodo){
            if(nodo->getValor()==valor)
                return nodo;
            nodo=nodo->getSiguiente();
        }
        return nullptr; //No encontre el elemento a buscar
    }      
};