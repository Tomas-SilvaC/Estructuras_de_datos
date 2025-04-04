/**
* Taller 03. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol rojo-negro
**/

#include "rbtree.h"

//Para impresión en inorder
void inorderHelper(Node *root)
{
    if (root == NULL)
        return;
 
    inorderHelper(root->left);
    cout << root->data << "  ";
    inorderHelper(root->right);
}
//Para impresión en preorder
void preorderHelper(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << "  ";
    inorderHelper(root->left);
    inorderHelper(root->right);
}
//Para impresión en postorder
void postorderHelper(Node *root)
{
    if (root == NULL)
        return;
    
    inorderHelper(root->left);
    inorderHelper(root->right);
    cout << root->data << "  ";
}

//Para hacer impresión en nivel-order
void levelOrderHelper(Node *root)
{
    if (root == NULL)
        return;
 
    std::queue<Node *> q;
    q.push(root);
 
    while (!q.empty())
    {
        Node *temp = q.front();
        cout << temp->data << "  ";
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
 
        if (temp->right != NULL)
            q.push(temp->right);
    }
}
//Insertar un nodo con una llave
Node* BSTInsert(Node* root, Node *pt)
{
    //Revisa si esta vacia, de ser asu, retorna el nuevo nodo
    if (root == NULL)
       return pt;
    
    //Si no esta vacio, viajara por el arbol hasta encontrar el valor necesario
    if (pt->data < root->data)
    {
        root->left  = BSTInsert(root->left, pt);
        root->left->parent = root;
    }
    else if (pt->data > root->data)
    {
        root->right = BSTInsert(root->right, pt);
        root->right->parent = root;
    }
 
    //Retorna el puntero del nodo
    return root;
}
 

//Rotación izquierda
void RBTree::rotateLeft(Node *&root, Node *&pt)
{
    //Reasigna los valores a sus nuevas posiciones revisando su valor y comparando con otros
    Node *pt_right = pt->right;
 
    pt->right = pt_right->left;
 
    if (pt->right != NULL)
        pt->right->parent = pt;
 
    pt_right->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_right;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;
 
    else
        pt->parent->right = pt_right;
 
    pt_right->left = pt;
    pt->parent = pt_right;
}

//Rotación derecha
void RBTree::rotateRight(Node *&root, Node *&pt)
{
    //Funciona igual a la rotación anterior, pero en sentido contrario
    Node *pt_left = pt->left;
 
    pt->left = pt_left->right;
 
    if (pt->left != NULL)
        pt->left->parent = pt;
 
    pt_left->parent = pt->parent;
 
    if (pt->parent == NULL)
        root = pt_left;
 
    else if (pt == pt->parent->left)
        pt->parent->left = pt_left;
 
    else
        pt->parent->right = pt_left;
 
    pt_left->right = pt;
    pt->parent = pt_left;
}
 
//Arregla la necesidad de color del arbol rojo-negro (un nodo rojo no puede tener otro nodo rojo como hijo)
void RBTree::fixViolation(Node *&root, Node *&pt)
{
    Node *parent_pt = NULL;
    Node *grand_parent_pt = NULL;
 
    while ((pt != root) && (pt->color != BLACK) &&
           (pt->parent->color == RED))
    {
 
        parent_pt = pt->parent;
        grand_parent_pt = pt->parent->parent;
 
        //  Si el nodo padre para pt es el hijo izquierdo del nodo abuelo de pt
        if (parent_pt == grand_parent_pt->left)
        {
 
            Node *uncle_pt = grand_parent_pt->right;
 
            //Recolor en caso de que el nodo tio sea rojo tambien
            if (uncle_pt != NULL && uncle_pt->color == RED)
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
 
            else
            {
                //Si pt es hijo derecho de su padre - rotación izquierda
                if (pt == parent_pt->right)
                {
                    rotateLeft(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                //Si pt es hijo izquierdo de su padre - rotación derecha
                rotateRight(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
 
        //  Si el nodo padre para pt es el hijo derecho del nodo abuelo de pt
        else
        {
            Node *uncle_pt = grand_parent_pt->left;
 
            //Recolor en caso de que el nodo tio sea rojo tambien
            if ((uncle_pt != NULL) && (uncle_pt->color == RED))
            {
                grand_parent_pt->color = RED;
                parent_pt->color = BLACK;
                uncle_pt->color = BLACK;
                pt = grand_parent_pt;
            }
            else
            {
                //Si pt es hijo derecho de su padre - rotación izquierda
                if (pt == parent_pt->left)
                {
                    rotateRight(root, parent_pt);
                    pt = parent_pt;
                    parent_pt = pt->parent;
                }
 
                //Si pt es hijo izquierdo de su padre - rotación derecha
                rotateLeft(root, grand_parent_pt);
                swap(parent_pt->color, grand_parent_pt->color);
                pt = parent_pt;
            }
        }
    }
    //Define el color de la nueva raiz como negro
    root->color = BLACK;
}
 
// Insertar un nodo
void RBTree::insert(const int &data)
{
    Node *pt = new Node(data);
 
    // Genera una inserción normal
    root = BSTInsert(root, pt);
 
    // Luego corrige segun la necesidad del arbol
    fixViolation(root, pt);
}
 
// Funciones de impresión
void RBTree::inorder()     { inorderHelper(root);}
void RBTree::preorder()     { preorderHelper(root);}
void RBTree::postorder()  { postorderHelper(root);}
void RBTree::levelOrder()  {  levelOrderHelper(root); }
