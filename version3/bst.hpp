#include <iostream>
#include "queue.hpp"
#include "Accesos.hpp"
using namespace std;

template <typename T>
class NodoArbolBinario{
    T valor;
    NodoArbolBinario<T> * izq;
    NodoArbolBinario<T> * der;
    NodoArbolBinario<T> * padre;
public:
    
    T getValor(){return this->valor;}
    NodoArbolBinario<T> * getIzq(){return this->izq;}
    NodoArbolBinario<T> * getDer(){return this->der;}
    NodoArbolBinario<T> * getPadre(){return this->padre;}
    
    void setValor(T valor){this->valor=valor;}
    void setIzq(NodoArbolBinario<T> * izq){this->izq=izq;}
    void setDer(NodoArbolBinario<T> * der){this->der=der;}
    void setPadre(NodoArbolBinario<T> * padre){this->padre=padre;}

    NodoArbolBinario(NodoArbolBinario<T> * padre, T valor){
        this->valor=valor;
        this->izq=nullptr;
        this->der=nullptr;
        this->padre=padre;
    }

    ~NodoArbolBinario(){
        //delete this->valor;
        cout<<"Ejecute el destructor"<<endl;
    } 

    //complejiad o(1)
    static void PreOrder(NodoArbolBinario<T> * actual){
        if(!actual)
            return;
        else{
            cout<<actual->getValor()->getAccesos()<<endl;
            PreOrder(actual->izq);
            PreOrder(actual->der);
        }
    }
    
    //complejiad o(1)
    static void levelByLevel(NodoArbolBinario<T> * actual){
        Queue<NodoArbolBinario<T>*> * queue1 = new Queue<NodoArbolBinario<T>*>();
        queue1->push(actual);
        if(actual){
            while(!queue1->isEmpty()){
                actual = queue1->front()->getValor();
                cout << queue1->pop()->getValor()->getValor()->getAccesos() <<endl;
                if(actual->izq != nullptr){
                    queue1->push(actual->getIzq());
                }
                if(actual->der != nullptr){
                    queue1->push(actual->getDer());
                }
            }
        }else{
            return;
        }
    }
    
    

      
};

template <typename T>
class BST{
    NodoArbolBinario<T> * root;
public:
    //Métodos get
    NodoArbolBinario<T> * getRoot(){return this->root;}
    //Métodos set
    void setRoot(NodoArbolBinario<T> * root){this->root=root;}
    //Método constructor
    BST(){
        this->root=nullptr;
    }

    ~BST(){

    }
    //complejidad o(n)
    void agregaNodoIterativo(T valor){
        NodoArbolBinario<T> * actual= this->root;
        NodoArbolBinario<T> * padre;
        //Arbol vacío
        if(!this->root){
            this->root= new NodoArbolBinario<T>(nullptr,valor);
            return;
        }
        
        if(!this->buscarNodoIp(valor->getAccesos())){
            //Árbol con valores
            //Encontrar al nodo padre
            while(actual){
                padre=actual;
                if(valor->getAccesos() < actual->getValor()->getAccesos()) //Determina la relación de orden
                    actual=actual->getIzq();
                else
                    actual=actual->getDer();
            }
            if(valor->getAccesos() < padre->getValor()->getAccesos())//El elemento es menor que el padre 
                padre->setIzq(new NodoArbolBinario<T>(padre,valor));
            else
                padre->setDer(new NodoArbolBinario<T>(padre,valor));
        }else
            cout<<"Valor repetido"<<endl;            
    }
    
    //complejidad o(n)
    NodoArbolBinario<T> * buscarNodoIp(int valor){
        NodoArbolBinario<Accesos*> * actual = this->root;
        while(actual){
            int accesos_actual = actual->getValor()->getAccesos();
            if(accesos_actual == valor){
                return actual;
            }else{
                if(valor > accesos_actual){
                    actual = actual->getDer();
                }else{
                    actual = actual->getIzq();
                }
            }
        }
        return nullptr;
    }

    void imprimirPreorden(){
        NodoArbolBinario<T>::PreOrder(this->root);
        cout << endl;
    }

    //complejidad o(n)
    void imprimirLevelByLevel(){
        NodoArbolBinario<T>::levelByLevel(this->root);
        cout << endl;
    }


    //Complejidad O(n)
    void createTree(ListaCDL<InternetProtocol*> listaIps){
        if(listaIps.getHead()){
            NodoDL<InternetProtocol*> * elemento = listaIps.getHead();
            do{
                int accesos_actual = elemento->getValor()->getNumAccesos();
                string ip_actual = elemento->getValor()->getIp();
                if(buscarNodoIp(accesos_actual)){
                    buscarNodoIp(accesos_actual)->getValor()->agregarIp(ip_actual);
                }else{
                    agregaNodoIterativo(new Accesos(accesos_actual,ip_actual));
                }
                elemento=elemento->getSiguiente();
            }while(elemento != listaIps.getHead());
        }else{
            cout<<"Lista vacía!"<<endl;
        }   
    }

    void deplegarIps(int acceso_user){
        if(this->root){
            buscarNodoIp(acceso_user)->getValor()->imprimirIps();
        }else{
            cout << "Arbol vacio " <<endl;
        }
    }
    
}; 