#ifndef PARCIAL2_ARBOLYHEAPNARIO_ARBOLHEAPNARIO_H
#define PARCIAL2_ARBOLYHEAPNARIO_ARBOLHEAPNARIO_H

#include "NodoHeap.h"
#include "Cola.h"
#include "Pila.h"
#include <iostream>
using namespace std;
/**
*En el arbol se guarda la raiz y se hacen las funciones para agregar y ordenar los nodos
* y el ordenamiento final
*/
template<class T>
class ArbolHeapNario {
private:
    int n;
    NodoHeap<T> *raiz;
    Cola<NodoHeap<T>*> cola;
    Pila<NodoHeap<T>*> pila;
    NodoHeap<T> *primer_pila; //primer elemento que se agrega a la pila
public:
    ArbolHeapNario(int orden);

    void put(T dato);

    void heapsort();

    void print_arbol();

    void print_alfabetico(NodoHeap<T>* root);
};


template<class T>
ArbolHeapNario<T>::ArbolHeapNario(int orden) {
    n = orden;
    raiz = nullptr;
}
/**
 *Agregamos los datos al arbol, si es el primero lo ponemos como raiz, desp usamos la
 * cola para agregar los hijos formando un arbol completo
*/
template<class T>
void ArbolHeapNario<T>::put(T dato) {
    if (raiz == nullptr) {
        raiz = new NodoHeap<T>(dato);
        cola.encolar(raiz);
        pila.push(raiz);
        primer_pila = raiz; //ya queda guardada la dirección del nodo que ingresa primero a la pila

        //cout<<endl<<endl;
    }
    else {
        NodoHeap<T>* a = raiz->buscarDato(dato);
        if (a!= nullptr){
            a->sumarRepeticion();
            //cout<<"No se agrego "<<a->getDato()<<" y esta repetido "<<a->getRepeticion()<<endl;
        }
        else{
            NodoHeap<T> *aux = cola.verFrente();
            NodoHeap<T> *nodoNuevo = new NodoHeap<T>(dato);

            //aca se arma el heap inicial
            nodoNuevo->comparar(aux);
            aux->putHijo(nodoNuevo);
            nodoNuevo->setPadre(aux);
            cola.encolar(nodoNuevo);
            pila.push(nodoNuevo);

            if(aux->getCantidadHijos() == n)
                cola.desencolar();

        }
    }
}

template<class T>
void ArbolHeapNario<T>::heapsort() {
    while(!(pila.size()==1)) {
        //tengo que usar así porque no funciona el constructor por copia
        NodoHeap<T>* first = pila.first();
        NodoHeap<T>* last = pila.peek();
        last->swap_dato(first);
        last->swap_repeticion(first);

        last->setNoPila();
        pila.desapilar();

        first->comparar_sort();
    }
    pila.first()->setNoPila();
    pila.desapilar();
    cout << "El arbol esta ordenado alfabeticamente." <<endl;
}



template<class T>
void ArbolHeapNario<T>::print_arbol() {
    print_alfabetico(raiz);
}

template<class T>
void ArbolHeapNario<T>::print_alfabetico(NodoHeap<T> *root) {
    Cola<NodoHeap<T>*> aux;
    aux.encolar(root);

    while (!(aux.esVacia())){
        int size = aux.size();

        while(size>0){
            NodoHeap<T>* i_raiz = aux.desencolar();
            i_raiz->print_nodo();
            vector<NodoHeap<T>*> children = i_raiz->getHijos();
            if(!(children.empty())){
                for(int i = 0; i < children.size(); i++){
                    aux.encolar(children.at(i));
                }
                size--;
            } else{
                size--;
            }
        }
        cout<<endl;
    }

}


#endif //PARCIAL2_ARBOLYHEAPNARIO_ARBOLHEAPNARIO_H