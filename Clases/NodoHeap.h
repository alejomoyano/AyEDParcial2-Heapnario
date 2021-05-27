#ifndef ALGORITMOS_TP2_NODO_H
#define ALGORITMOS_TP2_NODO_H

#include <iostream>
#include <vector>
#include <list>

using namespace std;

template<class T>
class NodoHeap {
private:
    int contador=1;
    T dato;
    NodoHeap<T> *padre;
    list<NodoHeap<T>> hijos;

public:
    NodoHeap(){
        padre= nullptr;
    };

    NodoHeap(T dato) : dato(dato){padre= nullptr;}

    T getDato() const {
        return dato;
    }

    void setPadre(NodoHeap<T> *padre){
        NodoHeap::padre=padre;
    }

    void setDato(T dato) {
        NodoHeap::dato = dato;
    }

    NodoHeap<T> *getPadre() const {
        return padre;
    }

//    vector<NodoHeap<T>>* getHijos() const {
//        vector<NodoHeap<T>>* childs=&hijos;
//        return childs;
//    }
//
//
    void setHijos(NodoHeap<T> child) {
        hijos.push_back(child);
    }

    void sumar_contador(){
        contador++;
    }


};

#endif //ALGORITMOS_TP2_NODO_H