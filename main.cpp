#include <iostream>
#include <fstream>
#include <regex>
#include <vector>

#include "Clases/Cola.h"
#include "Clases/Pila.h"
#include "Clases/NodoHeap.h"
#include "Clases/Nodo.h"

using namespace std;

int main() {
    Cola<NodoHeap<string>> cola_nh;
    Pila<NodoHeap<string>> pila_nh;
    NodoHeap<string> *padre;
    vector<NodoHeap<string>> hijos;

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
                NodoHeap<string> nodo_h = NodoHeap<string>(str, nullptr);
                cola_nh.encolar(nodo_h);
                pila_nh.push(nodo_h);
            }
            else {
                auto paux = cola_nh.desencolar();
                padre = &paux;
                NodoHeap<string> nodo_h = NodoHeap<string>(str,padre);
//                padre->setHijo(nodo_h);
                hijos.push_back(nodo_h);
                cola_nh.encolar(nodo_h);
                pila_nh.push(nodo_h);
                if (hijos.size()==n){ //si con el nodo que le metimos se completo, lo desencolamos
                    cout<<"---------Desencolamos porque tiene todos los hijos---------\n";
                    padre->setHijos(hijos);
                    hijos.clear();
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



