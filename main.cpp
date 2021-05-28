#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include "Clases/ArbolHeapNario.h"


using namespace std;

int main() {
    int n; //n de n-ario
    cout << "Cantidad de nodos: ";
    cin >> n;
    cout << endl;

    ArbolHeapNario<string> arbol(n);

    string str;
    string line;    //donde se va a guardar una linea del texto
    ifstream myFile("File.txt");    //Archivo con el texto

    regex reg("([^\\W]+(?:['-][^\\W_]+)*)");    // expresion regular que filtra palabras, numeros...

    //mientras haya una linea sigue
    while (getline(myFile, line)) {
        for(sregex_iterator palabra = sregex_iterator(line.begin(),line.end(),reg);palabra != sregex_iterator();++palabra){
            smatch match = *palabra;
            str = match.str();

            arbol.put(str);

        }
    }

}