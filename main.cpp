#include <iostream>
#include <fstream>
#include <string>
#include "Clases/Nodo.h"
#include "Clases/Cola.h"
#include "Clases/Pila.h"

using namespace std;

int main() {
    string str=" ";
    int i=0;
    string line;//donde se va a guardar una linea del texto
    ifstream myFile("File.txt");//Archivo con el texto

//mientras haya una linea sigue
    while (getline(myFile, line)) {
        while(line.length()) {
            if(line.at(i)==' ' || line.at(i)=='.' || line.at(i)==',') { //si el char es un blank, coma o punto (separador de palabra)
                str = line.substr(0,i+1); // hace un substring con la palabra desde 0 hasta la pos del "separdor"
                line = line.erase(0,i+1); // elimina del string la palabra
//                cout << str << endl;
                str.clear(); // limpiamos el string
                i=0;//limpiamos el contador
            }
            i++;//contador de la pos del "separador"
        }
    }
}
