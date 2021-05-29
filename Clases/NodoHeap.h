#ifndef ALGORITMOS_TP2_NODO_H
#define ALGORITMOS_TP2_NODO_H

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

template<class T>
class NodoHeap {
private:
    int repeticiones=1; //cuenta cantidad de veces q se repite la palabra en el texto
    T dato;
    NodoHeap<T> *padre;
    vector<NodoHeap<T>*> hijos;

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

        //compara alfabeticamente dos strings. si a(dato padre) es menor a b(dato hijo), devuelve 1 y hace el swap para
        // que quede el  mayor alfabeticamente como padre. sino, 0
        if (dato_p.compare(dato_h) < 0) {
            T aux = nodob->getDato();
            int aux2 = this->getRepeticion();
            this->setDato(aux);
            this->setRepeticiones(nodob->getRepeticion());

            nodob->setDato(dato_h);
            nodob->setRepeticiones(aux2);


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
/*
template<class T>
void NodoHeap<T>::print_nodo() {
    if(!(this->getHijos().empty())){
        vector<NodoHeap<T>*> child = this->getHijos();
        for(int i=0; i <child.size(); i++){
            cout<<child.at(i)->getDato()<<endl;
        }
        for(int i=0; i <child.size(); i++){
            child.at(i)->print_nodo();
        }
    }


}*/


#endif //ALGORITMOS_TP2_NODO_H