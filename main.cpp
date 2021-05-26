#include <iostream>
#include <fstream>
#include <regex>

#include "Clases/Cola.h"
#include "Clases/Pila.h"
#include "Clases/NodoHeap.h"
#include "Clases/Nodo.h"

using namespace std;

int main() {
    Cola<NodoHeap<string>> colaDeNodos;
    Pila<NodoHeap<string>> pilaDeNodos;
    Nodo<NodoHeap<string>> *padre;
    string palabras[1000];
    int i=0;
    int n=0; //n de n-ario
//    cout<<"Cantidad de nodos:";
//    cin>>n;

    string str=" ";
    int j=0;
    string line;//donde se va a guardar una linea del texto
    ifstream myFile("File.txt");//Archivo con el texto

    regex reg("([^\\W]+(?:['-][^\\W_]+)*)");// expresion regular que filtra palabras, numeros...

//mientras haya una linea sigue
    while (getline(myFile, line)) {

        for(sregex_iterator i = sregex_iterator(line.begin(),line.end(),reg);i != sregex_iterator();++i){
            smatch match = *i;
            str = match.str();
//            palabras[j]=str;
//            cout<<str<<endl;
//            j++;
            //--------en otra funcion--------
//            no hay raiz(cola vacia), entonces no tiene padre ese nodo. Esto se ejecuta solo al inicio del programa
            if(colaDeNodos.esVacia()){
                NodoHeap<string> nodoHeap = NodoHeap<string>(str, nullptr);
                colaDeNodos.encolar(nodoHeap);
                pilaDeNodos.push(nodoHeap);
            }
            else {
                NodoHeap<string> aux = colaDeNodos.verFrente();
                NodoHeap<string>* padre = & aux;
                NodoHeap<string> nodoHeap = NodoHeap<string>(str, padre);
                colaDeNodos.encolar(nodoHeap);
                pilaDeNodos.push(nodoHeap);
            }

//            if (padre.getHijos()->size() == n){ //si con el nodo que le metimos se completo, lo desencolamos
//                cout<<"---------\n"<<colaDeNodos.desencolar().getDato()<<endl;
//            }
        }
        cout<<"--------Cola-------\n";
        while(!colaDeNodos.esVacia()){
            cout<<colaDeNodos.desencolar().getDato()<<endl;
        }
        cout<<"--------Pila-------\n";
        while(!pilaDeNodos.esVacia()){
            cout<<pilaDeNodos.pop().getDato()<<endl;
        }
    }
}



