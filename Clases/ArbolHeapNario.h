#ifndef PARCIAL2_ARBOLYHEAPNARIO_ARBOLHEAPNARIO_H
#define PARCIAL2_ARBOLYHEAPNARIO_ARBOLHEAPNARIO_H

#include "NodoHeap.h"
#include "Cola.h"
#include "Pila.h"
#include <iostream>

using namespace std;

template<class T> class ArbolHeapNario {
    private:
        int n;
        NodoHeap<T> *raiz;
        Cola<NodoHeap<T>*> cola;
        Pila<NodoHeap<T>*> pila;
    public:
        ArbolHeapNario(int orden);
        void put(T dato);
        bool palabraRepetida(T dato, NodoHeap<T>* aux);
};

template<class T>
ArbolHeapNario<T>::ArbolHeapNario(int orden) {
    n = orden;
    raiz = nullptr;
}

template<class T> bool ArbolHeapNario<T>::palabraRepetida(T dato, NodoHeap<T>* aux) {
    vector<NodoHeap<T>*> child = aux->getHijos();
    int size = aux->getCantidadHijos();

    if (aux == nullptr){
        return false;
    } else {
        if(aux->getDato() == dato){
            aux->sumarCont();
            return true;
        }else {
            for (int i = 0; i < size; i++){
                //con el return elimina la primer repetición pero no recorre el array más alla del hijo[0]
                return palabraRepetida(dato, child[i]); //sin el return, recorre bien pero no devuelve nada entonces nunca se hace true la condicion de repetida, y se agrega igual
            }
        }
    }
    return false;
}



template<class T> void ArbolHeapNario<T>::put(T dato) {
    if (raiz == nullptr) {
        raiz = new NodoHeap<T>(dato);
        cola.encolar(raiz);
        pila.push(raiz);
        cout << dato <<endl; //para ver raíz
        cout << endl <<endl;
    }
    else {
        if (!(palabraRepetida(dato,raiz))) {
        NodoHeap<T> *aux = cola.verFrente();
        NodoHeap<T> *nodoNuevo = new NodoHeap<T>(dato);
        aux->putHijo(nodoNuevo);
        cola.encolar(nodoNuevo);
        pila.push(nodoNuevo);
        cout << dato << endl;
            if (aux->getCantidadHijos() == n) {
                cola.desencolar();
                cout << endl << endl; //para probar cuando desencola
            }
        }
    }
}




#endif //PARCIAL2_ARBOLYHEAPNARIO_ARBOLHEAPNARIO_H
