/**
* Taller 03. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol rojo-negro
**/
 
   #include <bits/stdc++.h>
   #include "rbtree.h"
   using namespace std;

//Main del programa
   int main()
   {
       RBTree tree;
       char m='I';
       int i=0;
       cout<<"Digite si desea insertar o finalizar (I o F)"<<endl;
       cin>>m;
       while(m != 'f' && m != 'F'){
           if(m == 'I' || m == 'i'){
               cout<<"Digite el valor a insertar"<<endl;
               cin>>i;
               tree.insert(i);
           }
           
           cout<<"Digite si desea insertar o finalizar (I o F)"<<endl;
           cin>>m;
       }
       
       cout << "Inscripcion en forma Inorder para el arbol rojo-negro\n";
       tree.inorder();
       cout<<"\n";
       cout << "Inscripcion en forma Preorder para el arbol rojo-negro\n";
       tree.preorder();
       cout<<"\n";
       cout << "Inscripcion en forma Postorder para el arbol rojo-negro\n";
       tree.postorder();
       cout<<"\n";
       cout << "Inscripcion en forma Nivel-order para el arbol rojo-negro\n";
       tree.levelOrder();
       cout<<"\n";
       
       return 0;
   }
