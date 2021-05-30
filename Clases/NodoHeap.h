#ifndef ALGORITMOS_TP2_NODO_H
#define ALGORITMOS_TP2_NODO_H

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template<class T>
class NodoHeap {
private:
    int repeticiones = 1; //cuenta cantidad de veces q se repite la palabra en el texto
    T dato;
    NodoHeap<T> *padre;
    vector<NodoHeap<T>*> hijos;
    bool nopila = false;

public:
    NodoHeap(T d);

    NodoHeap(const NodoHeap<T> &nh);

    void setPadre(NodoHeap<T> *nodo);

    void putHijo(NodoHeap<T> *nodo);

    int getCantidadHijos();

    NodoHeap<T>* getPadre();

    T getDato();

    int getRepeticion();

    void sumarRepeticion();

    NodoHeap<T>* buscarDato(T c);

    NodoHeap<T>* buscarDatoEnHijos(T t);

    void setDato(T nuevo);

    void comparar(NodoHeap<T>* nodob);

    vector<NodoHeap<T>*> getHijos();

    void setRepeticiones(int nuevo);

    void swap_dato(NodoHeap<T>* new_nodo);

    void swap_repeticion(NodoHeap<T>* new_nodo);

    void comparar_sort();

    bool desapilado();

    void setNoPila();


};
/**
 * Constructor. Inicializa el puntero a padre en null.
 * @tparam T
 * @param d
 */
template<class T>
NodoHeap<T>::NodoHeap(T d) {
    dato = d;
    padre = nullptr;
}

/**
 *Constructor por copia
*/
template<class T>
NodoHeap<T>::NodoHeap(const NodoHeap<T> &nh) {
    repeticiones = nh.repeticiones;
    dato = nh.dato;
    padre = nh.padre;
    hijos = nh.hijos;
}

template<class T>
void NodoHeap<T>::setPadre(NodoHeap<T> *nodo) {
    padre = nodo;
}

/**
 *Le agrega un hijo al nodo actual
*/
template<class T>
void NodoHeap<T>::putHijo(NodoHeap<T> *nodo) {
    hijos.push_back(nodo);
}

template<class T>
int NodoHeap<T>::getCantidadHijos() {
    return hijos.size();
}

template<class T>
NodoHeap<T> *NodoHeap<T>::getPadre() {
    return padre;
}

template<class T>
T NodoHeap<T>::getDato() {
    return dato;
}

template<class T>
void NodoHeap<T>::sumarRepeticion() {
    repeticiones++;
}

template<class T>
NodoHeap<T> *NodoHeap<T>::buscarDato(T c) {
    if(dato == c){
        return this;
    } else {
        return this->buscarDatoEnHijos(c);
    }
}

/**
 * Funcion recursiva de busqueda
 * @tparam T
 * @param dato
 * @return direccion del Nodo que contiene ese dato (un puntero)
 */
template<class T>
NodoHeap<T>* NodoHeap<T>::buscarDatoEnHijos(T t) {
    NodoHeap<T> *aux;
    for(int i=0; i<getCantidadHijos(); i++){
        NodoHeap<T>* a=hijos.at(i);
        aux = a->buscarDato(t);
        if(aux != nullptr)
            return aux;
//        if(a->getDato()==t){
//            cout<<"-----------------"<<endl;
//            cout<<"soy el dato: "<<t<<" ---- ";
//            cout<<"Estoy mirando a "<<hijos.at(i)->getDato()<<" indice: "<<i<<" padre: "<<this->getDato()<<endl;
//            return a;
//        }
//        else{
//            a->buscarDatoEnHijos(t);
//        }
    }
    return nullptr;
}

template<class T>
int NodoHeap<T>::getRepeticion() {
    return repeticiones;
}


template<class T>
void NodoHeap<T>::setDato(T nuevo) {
    dato = nuevo;
}



//aplico el método sobre el nodo hijo comparando con el nodo padre (nodob) y los hijos que ya pueda tener
template<class T>
void NodoHeap<T>::comparar(NodoHeap<T> *nodob) {
    if(nodob!= nullptr) {
        T dato_h = this->getDato(); //dato del nodo donde estoy llamando la funcion, el posible hijo

        T dato_p = nodob->getDato(); //dato del que sería el padre

        if (dato_p.compare(dato_h) < 0) {

            this->swap_dato(nodob);
            this->swap_repeticion(nodob);
            nodob->comparar(nodob->getPadre());
        }

    }
}

template<class T>
vector<NodoHeap<T> *> NodoHeap<T>::getHijos() {
    return hijos;
}

template<class T>
void NodoHeap<T>::setRepeticiones(int nuevo) {
    repeticiones = nuevo;
}

template<class T>
void NodoHeap<T>::swap_dato(NodoHeap<T> *nodob) {
    T aux = this->getDato();
    this->setDato(nodob->getDato());
    nodob->setDato(aux);

}

template<class T>
void NodoHeap<T>::swap_repeticion(NodoHeap<T> *nodob) {
    int aux = this->getRepeticion();
    this->setRepeticiones(nodob->getRepeticion());
    nodob->setRepeticiones(aux);
}

template<class T>
void NodoHeap<T>::comparar_sort() {

    vector<NodoHeap<T>*>children = this->getHijos();
    if(!(children.empty())){
        for(int i = 0; i<children.size(); i++) {
            if(!(children.at(i)->desapilado())){
                NodoHeap<T>* father = children.at(i)->getPadre();
                if(father!= nullptr) {
                    T dato_h = children.at(i)->getDato(); //dato del nodo donde estoy llamando la funcion, el posible hijo
                    T dato_p = father->getDato(); //dato del que sería el padre
                    if (dato_p.compare(dato_h) < 0) {
                        children.at(i)->swap_dato(father);
                        children.at(i)->swap_repeticion(father);
                    }
                }
            }
        }
        for(int j = 0; j<children.size(); j++){
            if(!(children.at(j)->desapilado())){
            children.at(j)->comparar_sort();
            }
        }

    }
    /*  NodoHeap<T>* a = this;
        NodoHeap<T>* b = nodob;

        T a_dato = a->getDato();
        T b_dato = b->getDato();
        while(a_dato<b_dato){
            NodoHeap<T>* aux = b;
            a = b;
            b = aux->getPadre();
            a_dato = a->getDato();
            b_dato = b->getDato();
        }
        a->comparar(b);
        if(b->getPadre() == nullptr){
            vector<NodoHeap<T>*> child = a->getHijos();
            for(int i = 0; i <child.size(); i++){
                child.at(i)->comparar(a);
            }
        }
    }*/
}

template<class T>
bool NodoHeap<T>::desapilado() {
    return nopila;
}

template<class T>
void NodoHeap<T>::setNoPila() {
    if(!nopila){
        nopila = true;
    }
}

#endif //ALGORITMOS_TP2_NODO_H