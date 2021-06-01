#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include "Clases/ArbolHeapNario.h"


using namespace std;

int main() {
    int n; //n de n-ario
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout<<"Algoritmos y Estructuras de Datos"<<endl;
    cout<<"Proyecto Segundo Parcial – 2021"<<endl;
    cout<<"Implementar Ordenamiento Heap Sort"<<endl;
    cout<<"--------------------------------------------------------------------------------"<<endl;
    cout << "Ingrese el orden del monticulo ('n'): ";
    cin >> n;
    cout << endl;

    ArbolHeapNario<string> arbol(n);

    string str;
    string line;    // Se guarda la linea de texto
    ifstream myFile("File.txt");    // Archivo con el texto fuente

    regex reg("([^\\W]+(?:['-][^\\W_]+)*)");    // Expresion regular que filtra palabras y números

    // Mientras siga habiendo una linea por procesar
    while (getline(myFile, line)) {
        for(sregex_iterator palabra = sregex_iterator(line.begin(),line.end(),reg);palabra != sregex_iterator();++palabra){
            smatch match = *palabra;
            str = match.str();

            arbol.put(str); // Ingresa la palabra al arbol, cumpliendo la condición de Heap N-Ario.

        }
    }

    arbol.heapsort(); // Realiza el ordenamiento final de la Heap
    arbol.print_arbol(); // Genera un archivo .txt y muestra por pantalla el resultado final del odenamiento

    cout<<"Final de la implementacion del ordenamiento Heap Sort. "<<endl;

}