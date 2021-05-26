#include <iostream>
#include <fstream>
#include <string>
#include <regex>

#include "Clases/Cola.h"
#include "Clases/Pila.h"
#include "Clases/NodoHeap.h"
#include "Clases/Nodo.h"

using namespace std;

int main() {
    Cola<Nodo<string>> colaDeNodos;
    Pila<Nodo<string>> pilaDeNodos;
    Nodo<string> padre;
    string aux[100];
    int i=0;
    int n=0; //n de n-ario
    cout<<"Cantidad de nodos:";
    cin>>n;

    string str=" ",straux=" ";
    int j=0;
    string line;//donde se va a guardar una linea del texto
    ifstream myFile("File.txt");//Archivo con el texto

    regex reg("([^\\W]+(?:['-][^\\W_]+)*)");

//mientras haya una linea sigue
    while (getline(myFile, line)) {

        for(sregex_iterator i = sregex_iterator(line.begin(),line.end(),reg);i != sregex_iterator();++i){
            smatch match = *i;
            str = match.str();
            aux[j]=str;
            cout<<str<<endl;
            j++;
            //--------en otra funcion--------
            //no hay raiz(cola vacia), entonces no tiene padre ese nodo. Esto se ejecuta solo al inicio del programa
//            if(colaDeNodos.esVacia()){
//                auto nodo = Nodo<string>(str,nullptr);
//                colaDeNodos.encolar(nodo);
//                pilaDeNodos.push(nodo);
//            }
//            else {
//                padre= colaDeNodos.verFrente();
//                auto nodo = Nodo<string>(str, &padre);
//                colaDeNodos.encolar(nodo);
//                pilaDeNodos.push(nodo);
//            }
//            if (padre.getHijos()->size() == n){ //si con el nodo que le metimos se completo, lo desencolamos
//                cout<<"---------\n"<<colaDeNodos.desencolar().getDato()<<endl;
//            }
        }
    }
}



