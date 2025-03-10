// exercise2.cpp (Andrea Rueda)
// based on:
// main.cc (Andrew Gilpin, agg1@cec.wustl.edu)

// This file contains a modification of the example program used in the 
// gdb debugging tutorial. The tutorial can be found on the web at
// http://students.cec.wustl.edu/~agg1/tutorial/

#include <iostream>

using namespace std;

int numb_inst = 0;

template <class T>
class Node {
public:
//Solo cambia el conteo de contador de nodos, tras agregar o eliminar un nodo
  Node (const T &value, Node<T> *next = 0) {
    value_ = value;
    next_ = next;
    cout << "Creating Node, "
         << ++numb_inst
         << " are in existence right now" << endl;
  }
  ~Node () {
    cout << "Destroying Node, "
         << --numb_inst
         << " are in existence right now" << endl;
    next_ = 0;
  }
  //variables del template nodo (get y set en otras palabaras)
  Node<T>* next () const { 
    return next_; 
  }
  void next (Node<T> *new_next) { 
    next_ = new_next; 
  };
  const T& value () const { 
    return value_; 
  }
  void value (const T &value) { 
    value_ = value; 
  }

private:
  Node ();
  T value_;
  Node<T> *next_;
};
  
template <class T>
class LinkedList {
public:
  LinkedList () : head_(0) {};
  ~LinkedList () { delete_nodes (); };

  // returns 0 on success, -1 on failure
  int insert (const T &new_item) {
    return ((head_ = new Node<T>(new_item, head_)) != 0) ? 0 : -1;
  }

  // returns 0 on success, -1 on failure
  int remove (const T &item_to_remove) {
    Node<T> *marker = head_;
    Node<T> *temp = 0;  // temp points to one behind as we iterate

    while (marker != 0) {
      if (marker->value() == item_to_remove) {
        if (temp == 0) { // En caso de que el marcador sea el primero en la lista
          if (marker->next() == 0) {
            head_ = 0;
            delete marker; // Y si fuese el UNICO elemento de esa lista
            marker = 0;
          } else {
            head_ = new Node<T>(marker->value(), marker->next()); //No es necesaria esta linea de codigo
            delete marker;
            marker = 0;
            //Crea el nodo y borra el contenido de inmediato
          }
          return 0;
        } else {
          temp->next (marker->next());
          delete temp;
          temp = 0;
          return 0;
        }
      }
      marker = 0;  // reinicia el marcador
      temp = marker;
      marker = marker->next();
    }

    return -1;	// en caso de fallo
  }

  void print (void) {
    //Imprime el marcador (es la funcion principal de impresión)
    Node<T> *marker = head_;
    while (marker != 0) {
      cout << marker->value() << endl;
      marker = marker->next();
    }
  }

private:
  //Elimina los marcadores del nodo
  void delete_nodes (void) {
    Node<T> *marker = head_;
    while (marker != 0) {
      Node<T> *temp = marker;
      delete marker;
      marker = temp->next();
    }
  }
        
  Node<T> *head_;
};

int main (int argc, char **argv) {
  LinkedList<int> *list = new LinkedList<int> ();
  //Inserta a la lista los valores en orden
  list->insert (1);
  list->insert (2);
  list->insert (3);
  list->insert (4);
  //Muestra la lista creada
  cout << "The fully created list is:" << endl;
  list->print ();

  cout << endl << "Now removing elements:" << endl;
  //Elimina los nodos uno tras otro usando el metodo de "remove()" creado anteriormente
  list->remove (4);
  list->print ();
  cout << endl;

  list->remove (1);
  list->print ();
  cout << endl;

  list->remove (2);
  list->print ();
  cout << endl;

  list->remove (3);
  list->print ();

  //Borra la lista de memoria
  delete list;

  return 0;
}
