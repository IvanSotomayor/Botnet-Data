#include <iostream>
using namespace std;

template <typename T>
class Nodo{
    //Atributos
    T valor;
    Nodo * siguiente;
    public:
    //Metodos
    T getValor(){return this->valor;}
    void setValor(T valor){this->valor=valor;}
    Nodo<T> * getSiguiente(){return this->siguiente;}
    void setSiguiente(Nodo<T> * siguiente){this->siguiente=siguiente;}
    //Constructores
    Nodo(T valor,Nodo<T> * siguiente){
        this->valor=valor;
        this->siguiente=siguiente;
    }
};

template <typename T>
class ListaCircular{
    Nodo<T> * last;
    int tam;
public:
    int getTam(){return this->tam;}
    void setTam(int tam){this->tam=tam;}
    Nodo<T> * getLast(){return this->last;}
    void setHead(Nodo<T> * last){this->last=last;}

    ListaCircular(){
        this->last=nullptr;
        this->tam=0;
    }

    void agregarInicio(T valor){
        //Lista con nodos
        if(this->last){
                //this->last->getSiguiente()  es el head (primer nodo)
                Nodo<T> * nuevo= new Nodo<T>(valor,this->last->getSiguiente());
                //ACtualizamos el apuntador del último nodo ahora conectado con el nuevo nodo
                this->last->setSiguiente(nuevo);
        }else{ //Lista sin nodos (vacia)
            Nodo<T> * nuevo=new Nodo<T>(valor,nullptr); //Crear nodo
            nuevo->setSiguiente(nuevo); //Como solo hay un nodo el apuntador siguiente es asi mismo
            this->last=nuevo;
        }
        this->tam++;
    }

    //Agregar al final O(1)
    void agregarFinal(T valor){
        if(this->last){ //Lista con elementos
            //Creamos el nuevo nodo apuntado al que era el nodo inicial
            Nodo<T> * nuevo=new Nodo<T>(valor,this->last->getSiguiente());
            //Actualizamos el siguiente del último nodo con el nuevo nodo
            this->last->setSiguiente(nuevo);
            //Actualizamos el apuntador del último al nuevo nodo
            this->last=nuevo;
        }else{ //Lista Vacía
            Nodo<T> * nuevo=new Nodo<T>(valor,nullptr); // Creando el nuevo nodo
            nuevo->setSiguiente(nuevo); // Como solo hay un nodo el apuntador siguiente será asi mismo
            this->last=nuevo; // El nuevo nodo será el último y el primero al mismo tiempo
        }            
        this->tam++; //Actualizamos el tamaño
    }

    void imprimirLista(){
        if(this->last){
            Nodo<T> * actual=this->last->getSiguiente();
            do{
                cout<<actual->getValor()<<" "; //Imprimir el valor contenido en el nodo
                actual=actual->getSiguiente(); //Recorrer el apuntador actual al siguiente nodo
            }while (actual!=this->last->getSiguiente()); 
            cout<<endl;                            
        }else{
            cout<<"Lista Circular vacía"<<endl;
        }
    }

    void imprimirLista2(){
        if(this->last){
            Nodo<T> * actual=this->last->getSiguiente();
            do{
                cout<<*actual->getValor()<<" "; //Imprimir el valor contenido en el nodo
                actual=actual->getSiguiente(); //Recorrer el apuntador actual al siguiente nodo
            }while (actual!=this->last->getSiguiente()); 
            cout<<endl;                            
        }else{
            cout<<"Lista Circular vacía"<<endl;
        }
    }

    Nodo<T> * eliminarInicio(){
        if(this->last){
            Nodo<T> * actual=this->last->getSiguiente();
            if(this->tam==1)
                this->last=nullptr;
            else
                this->last->setSiguiente(actual->getSiguiente());
            this->tam--;
            return actual;
        }
        return nullptr;

    }
        
};

template <typename T>
class Queue{
    ListaCircular<T> * queue;
public:
    Queue(){
        this->queue=new ListaCircular<T>();
    }
    void push(T valor){
        this->queue->agregarFinal(valor);
    }
    Nodo<T> * pop(){
        return this->queue->eliminarInicio();
    }

    Nodo<T> * front(){
        if(this->queue->getLast())
            return this->queue->getLast()->getSiguiente();
        return nullptr;
    }

    void imprimirQueueHeap(){
        this->queue->imprimirLista2();                         
    }

    void imprimirQueueStack(){
        this->queue->imprimirLista();
    }

    bool isEmpty(){
        if(this->queue->getTam() == 0){
            return true;
        }else{
            return false;
        }
    }
    
    int getSize(){
        return this->queue->getTam();
    }
};