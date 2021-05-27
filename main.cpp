#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

#include "Clases/Cola.h"
#include "Clases/Pila.h"
#include "Clases/NodoHeap.h"
#include "Clases/Nodo.h"
#include "Clases/Lista.h"

using namespace std;

int main() {
    Cola<NodoHeap<string>> cola_nh;
    Pila<NodoHeap<string>> pila_nh;
    NodoHeap<string> *padre;
    Lista<NodoHeap<string>> hijos;
    bool flag=1;

    int n=0; //n de n-ario
    cout<<"Cantidad de nodos:";
    cin>>n;

    string str=" ";
    string line;//donde se va a guardar una linea del texto
    ifstream myFile("File.txt");//Archivo con el texto

    regex reg("([^\\W]+(?:['-][^\\W_]+)*)");// expresion regular que filtra palabras, numeros...

//mientras haya una linea sigue
    while (getline(myFile, line)) {

        for(sregex_iterator palabra = sregex_iterator(line.begin(),line.end(),reg);palabra != sregex_iterator();++palabra){
            smatch match = *palabra;
            str = match.str();

            //--------en otra funcion--------
            //no hay raiz(cola vacia), entonces no tiene padre ese nodo. Esto se ejecuta solo al inicio del programa
            if(cola_nh.esVacia()){
                NodoHeap<string> nodo_h = NodoHeap<string>(str);
                cola_nh.encolar(nodo_h);
                pila_nh.push(nodo_h);
            }
            else {

                NodoHeap<string> nodo_hp = NodoHeap<string>();
                nodo_hp.setDato(str);
                nodo_hp.setPadre(cola_nh.verFrente());
                cola_nh.verFrente()->setHijos(nodo_hp);
//                hijos.insertarUltimo(nodo_hp);
                cola_nh.encolar(nodo_hp);
                pila_nh.push(nodo_hp);
                if (hijos.getTamanio()==n){ //si con el nodo que le metimos se completo, lo desencolamos
                    cout<<"---------Desencolamos porque tiene todos los hijos---------\n";
//                    cola_nh.verFrente()->setHijos(hijos);
                    cola_nh.desencolar();
                    //                    <<cola_nh.desencolar().getDato()<<endl;
                }
            }

        }
//        cout<<"--------Cola-------\n";
//        while(!colaDeNodos.esVacia()){
//            cout<<colaDeNodos.desencolar().getDato()<<endl;
//        }
//        cout<<"--------Pila-------\n";
//        while(!pilaDeNodos.esVacia()){
//            cout<<pilaDeNodos.pop().getDato()<<endl;
//        }
    }
}



