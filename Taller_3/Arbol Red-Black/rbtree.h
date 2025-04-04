/**
* Taller 03. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol rojo-negro
**/

#ifndef RBTREE_H
#define RBTREE_H

enum Color {RED, BLACK};

#include <bits/stdc++.h>
using namespace std;
struct Node
   {
       int data;
       bool color;
       Node *left, *right, *parent;
    
       //Constructor
       Node(int data)
       {
          this->data = data;
          left = right = parent = NULL;
       }
   };

class RBTree
   {
   private:
       Node *root;
   protected:
        //Rotaciones
       void rotateLeft(Node *&, Node *&);
       void rotateRight(Node *&, Node *&);
       void fixViolation(Node *&, Node *&);
   public:
       //Constructor
       RBTree() { root = NULL; }
       //Impresiones
       void insert(const int &n);
       void inorder();
       void preorder();
       void postorder();
       void levelOrder();
   };
    
   #include "rbtree.hxx"


#endif //RBTREE_H
