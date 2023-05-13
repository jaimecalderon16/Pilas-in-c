#include <iostream>
#include <conio.h>
using namespace std;
#define MAX_SIZE 20

struct nodo {
  string nombre;
  string apellido;
  int edad;
};


// Estructura para la pila
struct stack {
  nodo items[MAX_SIZE];
  int top;
};

// Función para inicializar la pila
void initializeStack(stack *s) {
  s->top = -1;
}

// Función para comprobar si la pila está vacía
bool isEmpty(stack *s) {
  return s->top == -1;
}

// Función para comprobar si la pila está llena
bool isFull(stack *s) {
  return s->top == MAX_SIZE - 1;
}

// Función para añadir un elemento a la pila
void push(stack *s, nodo item) {
  if (isFull(s)) {
    cout << "La pila está llena" << endl;
  } else {
    s->top++;
    s->items[s->top] = item;
  }
}

// Función para quitar un elemento de la pila
nodo pop(stack *s) {
  if (isEmpty(s)) {
    cout << "La pila está vacía" << endl;
    return nodo();
  } else {
    nodo temp = s->items[s->top];
    s->top--;
    return temp;
  }
}

// Función para copiar los elementos de una pila a otra
void copyStack(stack *s, stack *temp) {
  while (!isEmpty(s)) {
    push(temp, pop(s));
  }
}

// Función para unir dos pilas en una sola
void joinStacks(stack *s1, stack *s2, stack *s3) {
  // Copiamos los elementos de la primera pila a la nueva pila
  copyStack(s1, s3);

  // Copiamos los elementos de la segunda pila a la nueva pila
  copyStack(s2, s3);
}

// Función para imprimir los elementos de la pila

void printStack(stack *s) {
  cout << "Elementos de la pila: ";
  while (!isEmpty(s)) {
    cout<< "\n"<<pop(s).nombre<<" ";
  }
  cout << "\nterminado ";
  cout << endl;
}


int main() {
  // Inicializamos las pilas
  int cont = 0;
  stack s1, s2, s3;
  initializeStack(&s1);
  initializeStack(&s2);
  initializeStack(&s3);

        while(cont < 2){
            cout<<"-> FIRST PILA";
            nodo persona;
            cout<<"\n"<<"ingrese nombre: ";
            cin>>persona.nombre;
            cout<<"\n"<<"ingrese apellido: ";
            cin>>persona.apellido;
            cout<<"\n"<<"ingrese edad: ";
            cin>>persona.edad;
            
            push(&s1, persona); //
            cont ++;
        }
        cont = 0;
        
        while(cont < 2){
            cout<<"-> SECOND PILA";
            nodo persona;
            cout<<"\n"<<"ingrese nombre: ";
            cin>>persona.nombre;
            cout<<"\n"<<"ingrese apellido: ";
            cin>>persona.apellido;
            cout<<"\n"<<"ingrese edad: ";
            cin>>persona.edad;
            
            push(&s2, persona);
            cont++;
        };
  joinStacks(&s1,&s2,&s3);
 printStack(&s3);

 _getch();

};

