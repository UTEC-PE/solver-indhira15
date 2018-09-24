#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

class node{
public:
    string data;
    node* izq;
    node* der;
};

class arbol {

public:
    node* raiz;
    int pos;
    arbol():raiz(nullptr),pos(0){}
    //float solver(char*

    void split (string str, string& left, string& right){
        for(int i = 0 ; i < str.length(); i++){
            int aa=0;
            if (str[i] == '+' || str[i] == '-') {
                    aa=1;
                    pos = i;
                    break;
            }

            if(aa==0){
                if (str[i] == '*' || str[i] == '/') {
                    pos = i;
                    break;
                }
            }


        }

        for(int j = 0; j < pos ; j ++){
            left.push_back(str[j]);
        }
        for(int k = pos+1; k < str.length(); k++){
            right.push_back(str[k]);
        }
    }


    bool insert(string dato, node* Nodo){
        string left,right;
        if(dato.length() != 1){
            split(dato,left,right);
        }
        else{
            return false;
        }
        if(raiz== nullptr){
            raiz = new node;
            raiz->data= dato[pos];
            raiz->der= new node {right, nullptr, nullptr};
            raiz->izq= new node {left, nullptr, nullptr};
        }
        else {
            Nodo->izq = new node {left, nullptr, nullptr};
            insert(left,Nodo->izq);
            Nodo->der = new node {right, nullptr, nullptr};
            insert(right,Nodo->der);
            return true;
        }

            /*node* temp = new node*;
            if (Nodo->izq == nullptr) {
                Nodo->izq = nuevo;
                return (true);
            } else if (Nodo->der == nullptr) {
                raiz->der = nuevo;
                return (true);
            } else {
                return (false);
            }
             */
        }

    /*
    void opp(int& a){
        if((raiz->data=='+')){
            int x= (raiz->der->data)-'0';
            int y= (raiz->izq->data)-'0';
            a=x+y;
        }
        if((raiz->data=='-')){
            int x= (raiz->der->data)-'0';
            int y= (raiz->izq->data)-'0';
            a=y-x;
        }
        if((raiz->data=='*')){
            int x= (raiz->der->data)-'0';
            int y= (raiz->izq->data)-'0';
            a=x*y;
        }
    }
     */

    //NUEVAS FUNCIONES

};


void menu() {
    cout<<"==========================================================="<<endl;
    cout<<"\t\tPractica Operaciones"<<endl;
    cout<<"==========================================================="<<endl;


    char* str = "3*4+5";
    //char* str="7/4*((a+b)*a)+3";
    //char* str="7/4*((a+-+--b)*a)+3";
    //char* str="2+(3)";
    //char* str="7/4*((a+b)^4*a)+3";
    arbol arbolito;
    arbolito.insert(str,arbolito.raiz);
}

int main(int argc, char const *argv[]) {
    menu();
    cout << "\nPress enter to continue ...";
    cin.get();

    return EXIT_SUCCESS;
}

