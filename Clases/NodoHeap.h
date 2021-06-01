#ifndef ALGORITMOS_TP2_NODO_H
#define ALGORITMOS_TP2_NODO_H

#include <iostream>
#include <vector>

using namespace std;

/**
 * Clase que implementa un tipo de Nodo específico, que puede
 * almacenar cualquier tipo de dato T.
 * @tparam T
 */
template<class T>
class NodoHeap {
private:
    T dato;

    int repeticiones = 1; // Cada palabra correspondiente al nodo comienza con 1 repetición.

    NodoHeap<T> *padre;

    vector<NodoHeap<T>*> hijos;

    bool nopila = false; // Flag para determinar, en el ordenamiento final, si ya está en su posición final

    int comp = 0; // Contador auxiliar de comparaciones que sufre un nodo en el ordenamiento final

    int swap = 0; // Contador auxiliar de swaps que sufre un nodo en el ordenamiento final

public:
    NodoHeap(T d);
    NodoHeap(const NodoHeap<T> &nh);

    // Métodos correspondientes al dato del Nodo
    T getDato(){return dato;};
    void setDato(T nuevo);
    int getRepeticion();
    void sumarRepeticion();
    void setRepeticiones(int nuevo);
    NodoHeap<T>* buscarDato(T c);
    NodoHeap<T>* buscarDatoEnHijos(T t);

    // Métodos correspondientes al Nodo Padre
    void setPadre(NodoHeap<T> *nodo) {padre = nodo;};
    NodoHeap<T>* getPadre() {return padre;};

    // Métodos correspondientes al vector de Nodos Hijos
    void putHijo(NodoHeap<T> *nodo);
    vector<NodoHeap<T>*> getHijos();
    int getCantidadHijos();

    // Métodos correspondientes al flag de Ordenamiento Final
    bool desapilado();
    void setNoPila();

    // Métodos de comparación entre Nodos
    void comparar(NodoHeap<T>* nodob, int* c, int* s);
    NodoHeap<T>* comparar_sort(vector<NodoHeap<T>*> children);
    void swap_dato(NodoHeap<T>* nodob);
    void swap_repeticion(NodoHeap<T>* nodob);

    // Métodos correspondientes a las variables comp y swap

    int get_comp() {return comp;}
    int get_swap() {return swap;}
    void sum_comp() {comp++;}
    void sum_swap() {swap++;}
    void set_comp(int new_comp) {comp = new_comp; }
    void set_swap(int new_swap) {swap = new_swap;}
    void reset_comp() {comp = 0;}
    void reset_swap() {swap = 0;}

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
 * Constructor por copia
 * @tparam T
 * @param puntero constante del cuál quiero extraer información
 */
template<class T>
NodoHeap<T>::NodoHeap(const NodoHeap<T> &nh) {
    repeticiones = nh.repeticiones;
    dato = nh.dato;
    padre = nh.padre;
    hijos = nh.hijos;
}


/**
 * Inserta un nuevo Nodo Hijo al vector
 * @tparam T
 * @param puntero al nodo que se quiere insertar
 */
template<class T>
void NodoHeap<T>::putHijo(NodoHeap<T> *nodo) {
    hijos.push_back(nodo);
}


/**
 * Devuelve el tamaño actual del vector Hijos
 * @tparam T
 * @return
 */
template<class T>
int NodoHeap<T>::getCantidadHijos() {
    return hijos.size();
}

/**
 * Suma en 1 la cantidad actual de repeticiones del dato
 * @tparam T
 */
template<class T>
void NodoHeap<T>::sumarRepeticion() {
    repeticiones++;
}

/**
 * Busca en un nodo dado el dato c, y si no lo encuentra
 * busca en su vector Hijos
 * @tparam T
 * @param dato a buscar
 * @return
 */
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
    }
    return nullptr;
}

/**
 * Devuelve el valor actual de repeticiones de una palabra
 * @tparam T
 * @return cantidad
 */
template<class T>
int NodoHeap<T>::getRepeticion() {
    return repeticiones;
}

/**
 * Reemplaza el dato de un nodo con otro valor nuevo
 * @tparam T
 * @param dato nuevo
 */
template<class T>
void NodoHeap<T>::setDato(T nuevo) {
    dato = nuevo;
}

/**
 * Devuelve el vector que contiene a los Nodods Hijos
 * @tparam T
 * @return vector
 */
template<class T>
vector<NodoHeap<T> *> NodoHeap<T>::getHijos() {
    return hijos;
}

/**
 * Método para swap de Nodos - modifica el valor de la variable "repeticiones"
 * @tparam T
 * @param dato nuevo
 */
template<class T>
void NodoHeap<T>::setRepeticiones(int nuevo) {
    repeticiones = nuevo;
}

/**
 * Método para cambiar entre dos Nodos su variable "swap"
 * @tparam T
 * @param puntero a nodo con el que se quiere intercambiar
 */
template<class T>
void NodoHeap<T>::swap_dato(NodoHeap<T> *nodob) {
    T aux = this->getDato();
    this->setDato(nodob->getDato());
    nodob->setDato(aux);

}

/**
 * Método para cambiar entre dos Nodos su variable "comp"
 * @tparam T
 * @param puntero a nodo con el que se quiere intercambiar
 */
template<class T>
void NodoHeap<T>::swap_repeticion(NodoHeap<T> *nodob) {
    int aux = this->getRepeticion();
    this->setRepeticiones(nodob->getRepeticion());
    nodob->setRepeticiones(aux);
}

/**
 * Método de comparacion "arriba-abajo" - Compara un nodo Padre y cambia
 * solamente con el Nodo Hijo cuyo dato sea mayor. Repite recursivamente
 * con el Nodo Hijo con el que hizo el swap.
 * @tparam T
 * @param vector de Nodos Hijos
 * @return puntero al Nodo donde no prosigue con las comparaciones
 * para obtener sus comparadores
 */
template<class T>
NodoHeap<T>* NodoHeap<T>::comparar_sort(vector<NodoHeap<T>*> children) {
    NodoHeap<T>* aux = this;
    T posible_raiz; // Retengo el dato del Nodo que es candidato a ser raíz
    int k= -1; // Variable auxiliar para determinar en qué posicion del vector se encuentra el Nodo Hijo a intercambiar

    if(!(children.empty())) {
        // Se compara con los hijos para determinar el que contiene el dato mayor
        for (int i = 0; i < children.size(); i++) {
            if (!(children.at(i)->desapilado())) { // Revisa si no es un nodo que no tiene que ser considerado
                if (aux->getDato() > children.at(i)->getDato()) { // El dato del padre es mayor
                    aux->sum_comp(); // Suma en 1 la variable comp del Nodo a devolver

                } else { // El dato del Hijo es mayor
                    aux->sum_comp(); // Suma en 1 la variable comp del Nodo a devolver
                    if(posible_raiz < children.at(i)->getDato()){ // Compara el dato de este Nodo con la posible raíz
                        posible_raiz = children.at(i)->getDato(); // Si es mayor, guarda su valor para usar como referencia
                        k=i; // Asigno a la variable k la posición del nodo con el que se tiene que hacer el intercambio
                    }
                }
            }
        }
    }

    if(k == -1){ // No hubo intercambios, solamente comparaciones. El dato permaece en su lugar
        return aux;
    } else {

        // Se realiza el intercambio con el Nodo Hijo en la posición determinada por k
        aux->swap_dato(children.at(k));
        aux->swap_repeticion(children.at(k));
        aux->sum_swap(); // Suma en 1 la variable swap del Nodo a devolver

        // Mantengo apartados los valores actuales de las variables comp y swap
        int s_aux = aux->get_swap(); int c_aux = aux->get_comp();

        // Reseteo las variables comp y swap del Nodo para que puedan modificarse en futuras comparaciones
        aux->reset_swap();aux->reset_comp();

        // Seteo las variables comp y swap de la nueva posición a comparar con sus hijos, con el valor
        //acumulado hasta ahora en esta pasada
        children.at(k)->set_swap(s_aux); children.at(k)->set_comp(c_aux);

        // Ahora, el Puntero a Nodo auxiliar apunta al nodo que tiene que compararse con sus hijos
        aux = children.at(k);

        return aux->comparar_sort(aux->getHijos()); // Nueva comparación con el nuevo Nodo Padre y sus Nodos Hijos
    }
}


/**
 * Verifica si el Nodo ya está en posición fija del ordenamiento final
 * o si puede ser utilizado para comparar con el Nodo Padre;
 * @tparam T
 * @return true si ya es Nodo Hoja fijo
 */
template<class T>
bool NodoHeap<T>::desapilado() {
    return nopila;
}

/**
 * Activa la variable "nopila", indicando que el Nodo ya fue ordenado y
 * no tiene que ser comparado en futuras comparaciones
 * @tparam T
 */
template<class T>
void NodoHeap<T>::setNoPila() {
    if(!nopila){
        nopila = true;
    }
}


/**
 * Método de comparacion para armado de Heap - Compara dos Nodos para
 * determinar cuál tiene el dato mayor. Repite recursivamente en el caso de
 * que haya un intercambio, para comparar entre el nuevo dato y el que contiene
 * el Nodo Padre del Nodo que fue reemplazado.
 * @tparam T
 * @param vector a comparar, punteros a variables "comp" y "swap" del Arbol
 */
template<class T>
void NodoHeap<T>::comparar(NodoHeap<T> *nodob, int *c, int*s) {
    if(nodob!= nullptr) { // Si es nulo, significa que hemos llegado a la raíz del Arbol
        T dato_h = this->getDato();
        T dato_p = nodob->getDato();

        *c = *c +1; // Aumento en 1 la variable "comp" del Arbol

        if (dato_p<dato_h) { // Se realiza el intercambio de información entre los Nodos, continua comparando
            this->swap_dato(nodob);
            this->swap_repeticion(nodob);

            *s = *s + 1; // Aumento en 1 la variable "swap" del Arbol
            // Comparo el nuevo Nodo con el Nodo Padre del reemplazado, manteniendo los puntos a comp y swap
            nodob->comparar(nodob->getPadre(), c, s);
        }
    }
}


#endif //ALGORITMOS_TP2_NODO_H