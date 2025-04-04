/**
* Taller 3. Arboles
* Autores: Tomas Silva, Juan Pabon Vargas
* Arbol AVL
**/
#include "ArbolBinarioAVL.h"
#include <queue>
#include <iostream>

using namespace std;

template <class T>
//Constructores
ArbolBinarioAVL<T>::ArbolBinarioAVL(){
	this->raiz=NULL;
}

template <class T>
ArbolBinarioAVL<T>::~ArbolBinarioAVL(){
}
//get y set de raiz
template <class T>
void ArbolBinarioAVL<T>::setRaiz(NodoBinarioAVL<T>* raiz){
	this->raiz=raiz;
	return;
}
//devuelve la raiz
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::getRaiz(){
	return this->raiz;
}
//Revisa si el arbol esta vacio
template <class T>
bool ArbolBinarioAVL<T>::esVacio(){
	if(this->raiz==NULL){
		return true;
	}
	return false;
}
//Obtener el dato de raiz
template <class T>
T& ArbolBinarioAVL<T>::datoRaiz(){
	return (this->raiz)->getDato();
}
//devuelve la altura del arbol
template <class T>
int ArbolBinarioAVL<T>::altura(NodoBinarioAVL<T> *inicio){
	int alturaIzq=0;
	int alturaDer=0;
	if(inicio==NULL){
		return -1;
	}
	if(inicio->getHijoIzq()==NULL && inicio->getHijoDer()==NULL){
		return 0;
	}
	if(inicio->getHijoIzq()!=NULL){
	    //Aumenta la altura con cada nodo hijo a izquierda
		alturaIzq+=altura(inicio->getHijoIzq())+1;
	}
	if(inicio->getHijoDer()!=NULL){
	    //Aumenta la altura con cada nodo hijo a derecha
		alturaDer+=altura(inicio->getHijoDer())+1;
	}
	//Revisa que rama es mas alta y toma esa altura, si son iguales (equilibrado), toma la rama derecha
	if(alturaIzq>alturaDer){
		return (alturaIzq);
	}else{
		return (alturaDer);
	}
}
//devuelve la cantidad de nodos en el arbol
template <class T>
int ArbolBinarioAVL<T>::tamano(NodoBinarioAVL<T> *inicio){
	int nodosIzq=0;
	int nodosDer=0;
	//Sumara las cantidades de nodos izquierdos y derechos para el tamaño total
	if(inicio==NULL){
		return 0;
	}
	if(inicio->getHijoIzq()==NULL && inicio->getHijoDer()==NULL){
		return 1;
	}
	
	//En caso de que el arbol tenga mas de un nodo
	if(inicio->getHijoIzq()!=NULL){
		nodosIzq+=tamano(inicio->getHijoIzq());
	}
	if(inicio->getHijoDer()!=NULL){
		nodosDer+=tamano(inicio->getHijoDer());
	}
	return nodosIzq+nodosDer+1;
	
}
//Rotacion de los nodos hacia la derecha
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerecha(NodoBinarioAVL<T>* &padre){
	NodoBinarioAVL<T> *n_padre=padre->getHijoIzq();
	padre->setHijoIzq(n_padre->getHijoDer());
	n_padre->setHijoDer(padre);
	return n_padre;
}
//Rotacion de los nodos hacia la izquierda
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierda(NodoBinarioAVL<T>* &padre){
	NodoBinarioAVL<T> *n_padre=padre->getHijoDer();
	padre->setHijoDer(n_padre->getHijoIzq());
	n_padre->setHijoIzq(padre);
	return n_padre;
}
//Rotacion especifica de la secuencia nodo - izquierda - derecha
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroIzquierdaDerecha(NodoBinarioAVL<T>* &padre){
	NodoBinarioAVL<T> **primGiro=&(padre->hijoIzq);
	padre->setHijoIzq(giroIzquierda(*primGiro));
	return giroDerecha(padre);
}
//Rotacion especifica de la secuencia nodo - derecha - izquierda
template <class T>
NodoBinarioAVL<T>* ArbolBinarioAVL<T>::giroDerechaIzquierda(NodoBinarioAVL<T>* &padre){
	NodoBinarioAVL<T> **primGiro=&(padre->hijoDer);
	padre->setHijoDer(giroDerecha(*primGiro));
	return giroIzquierda(padre);
}

template <class T> //Algoritmo de inserción
bool ArbolBinarioAVL<T>::insertar(T& val){
	NodoBinarioAVL<T> *nodoActual=this->raiz;
	NodoBinarioAVL<T> *nNodo=new NodoBinarioAVL<T>();
	NodoBinarioAVL<T> *n_padre, *n_padre2;
	bool nodoInsertado,valorTomado=false;
	while(!valorTomado){
		if(nodoActual==NULL){
			nNodo->setDato(val);
			(this->raiz)=nNodo;
			nodoActual=this->raiz;
			nodoInsertado=true;
			valorTomado=true;
			break;
		}
		else if(val==nodoActual->getDato()){
			nodoInsertado=false;
			valorTomado=true;
			break;
		}
		else if(val>nodoActual->getDato() && nodoActual->getHijoDer()==NULL){
			nNodo->setDato(val);
			nodoActual->setHijoDer(nNodo);
			nodoInsertado=true;
			valorTomado=true;
			break;
		}
		else if(val<nodoActual->getDato() && nodoActual->getHijoIzq()==NULL){
			nNodo->setDato(val);
			nodoActual->setHijoIzq(nNodo);
			nodoInsertado=true;
			valorTomado=true;
			break;
		}
		
		if(val>nodoActual->getDato()){
			nodoActual=nodoActual->getHijoDer();
		}else{
			nodoActual=nodoActual->getHijoIzq();
		}

	}
	if(nodoInsertado){
		NodoBinarioAVL<T> **nBalanceo=&(this->raiz);
		while((*nBalanceo)!=NULL){
			if(altura((*nBalanceo)->getHijoIzq())-altura((*nBalanceo)->getHijoDer())>1 && altura(((*nBalanceo)->getHijoIzq())->getHijoIzq())>altura(((*nBalanceo)->getHijoIzq())->getHijoDer())){
				*nBalanceo=giroDerecha(*nBalanceo);
			}else if(altura((*nBalanceo)->getHijoIzq())-altura((*nBalanceo)->getHijoDer())>1 && altura(((*nBalanceo)->getHijoIzq())->getHijoIzq())<altura(((*nBalanceo)->getHijoIzq())->getHijoDer())){
				*nBalanceo=giroIzquierdaDerecha(*nBalanceo);
			}else if(altura((*nBalanceo)->getHijoDer())-altura((*nBalanceo)->getHijoIzq())>1 && altura(((*nBalanceo)->getHijoDer())->getHijoDer())>altura(((*nBalanceo)->getHijoDer())->getHijoIzq())){
				*nBalanceo=giroIzquierda(*nBalanceo);
			}else if(altura((*nBalanceo)->getHijoDer())-altura((*nBalanceo)->getHijoIzq())>1 && altura(((*nBalanceo)->getHijoDer())->getHijoDer())<altura(((*nBalanceo)->getHijoDer())->getHijoIzq())){
				*nBalanceo=giroDerechaIzquierda(*nBalanceo);
			}
			
			if((*nBalanceo)->getDato()<val){
				nBalanceo=&((*nBalanceo)->hijoDer);
			}else{
				nBalanceo=&((*nBalanceo)->hijoIzq);
			}
		} 
	}
	return nodoInsertado;
}

template <class T>//Algoritmo de eliminación
bool ArbolBinarioAVL<T>::eliminar(T& val){
	NodoBinarioAVL<T> *buscaNodo=this->raiz;
	if(this->raiz==NULL){
		return false;
	}else{
		while(buscaNodo->getHijoDer()!=NULL || buscaNodo->getHijoIzq()!=NULL || buscaNodo->getDato()==val){
			if(buscaNodo->getDato()==val){
				if(buscaNodo->getHijoDer()==NULL && buscaNodo->getHijoIzq()==NULL){
					NodoBinarioAVL<T> *buscaNodo3=this->raiz;
					if(this->raiz==buscaNodo){
						this->raiz=NULL;
					}
					else{
						while(buscaNodo3->getHijoIzq()!=NULL || buscaNodo3->getHijoDer()!=NULL){
							if(buscaNodo3->getHijoIzq()!=NULL){
								if((buscaNodo3->getHijoIzq())->getDato()==buscaNodo->getDato()){
									buscaNodo3->setHijoIzq(NULL);
									break;
								}
							}
							if(buscaNodo3->getHijoDer()!=NULL){
								if((buscaNodo3->getHijoDer())->getDato()==buscaNodo->getDato()){
									buscaNodo3->setHijoDer(NULL);
									break;
								}
							}
							if(buscaNodo->getDato()>buscaNodo3->getDato()){
								buscaNodo3=buscaNodo3->getHijoDer();
							}else{
								buscaNodo3=buscaNodo3->getHijoIzq();
							}
						}
					}
					delete(buscaNodo);
				}else if(buscaNodo->getHijoDer()==NULL){
					*(buscaNodo)=*(buscaNodo->getHijoIzq());
				}else if(buscaNodo->getHijoIzq()==NULL){
					*(buscaNodo)=*(buscaNodo->getHijoDer());
				}else{
					NodoBinarioAVL<T> *buscaNodo2=buscaNodo->getHijoIzq();
					while(buscaNodo2->getHijoDer()!=NULL){
						buscaNodo2=buscaNodo2->getHijoDer();
					}
					buscaNodo->setDato(buscaNodo2->getDato());
					if(buscaNodo2->getHijoIzq()==NULL){
						if((buscaNodo->getHijoIzq())->getHijoDer()!=NULL){
							NodoBinarioAVL<T> *buscaNodo3=buscaNodo->getHijoIzq();
							while((buscaNodo3->getHijoDer())->getDato()!=buscaNodo2->getDato()){
								buscaNodo3=buscaNodo3->getHijoDer();
							}
							buscaNodo3->setHijoDer(NULL);
						}else{
							buscaNodo->setHijoIzq(NULL);
						}
						delete(buscaNodo2);
					}else{
						*(buscaNodo2)=*(buscaNodo2->getHijoIzq());
					}
				}
				NodoBinarioAVL<T> **nBalanceo=&(this->raiz);
				while((*nBalanceo)!=NULL){
					if(altura((*nBalanceo)->getHijoIzq())-altura((*nBalanceo)->getHijoDer())>1 && altura(((*nBalanceo)->getHijoIzq())->getHijoIzq())>altura(((*nBalanceo)->getHijoIzq())->getHijoDer())){
						*nBalanceo=giroDerecha(*nBalanceo);
					}else if(altura((*nBalanceo)->getHijoIzq())-altura((*nBalanceo)->getHijoDer())>1 && altura(((*nBalanceo)->getHijoIzq())->getHijoIzq())<altura(((*nBalanceo)->getHijoIzq())->getHijoDer())){
						*nBalanceo=giroIzquierdaDerecha(*nBalanceo);
					}else if(altura((*nBalanceo)->getHijoDer())-altura((*nBalanceo)->getHijoIzq())>1 && altura(((*nBalanceo)->getHijoDer())->getHijoDer())>altura(((*nBalanceo)->getHijoDer())->getHijoIzq())){
						*nBalanceo=giroIzquierda(*nBalanceo);
					}else if(altura((*nBalanceo)->getHijoDer())-altura((*nBalanceo)->getHijoIzq())>1 && altura(((*nBalanceo)->getHijoDer())->getHijoDer())<altura(((*nBalanceo)->getHijoDer())->getHijoIzq())){
						*nBalanceo=giroDerechaIzquierda(*nBalanceo);
					}
			
					if((*nBalanceo)->getDato()<val){
						nBalanceo=&((*nBalanceo)->hijoDer);
					}else{
						nBalanceo=&((*nBalanceo)->hijoIzq);
					}
				}
				return true;
			}else if(val<buscaNodo->getDato() && buscaNodo->getHijoIzq()!=NULL){
				buscaNodo=buscaNodo->getHijoIzq();
			}else if(val>buscaNodo->getDato() && buscaNodo->getHijoDer()!=NULL){
				buscaNodo=buscaNodo->getHijoDer();
			}else if(val<buscaNodo->getDato() && buscaNodo->getHijoIzq()==NULL){
				return false;
			}else if(val>buscaNodo->getDato() && buscaNodo->getHijoDer()==NULL){
				return false;
			}
		}
	}
	return false;
}



template <class T>//Algoritmo de busqueda
bool ArbolBinarioAVL<T>::buscar(T& val){
	NodoBinarioAVL<T> *buscaNodo=this->raiz;
	if(this->raiz==NULL){
		return false;
	}else{
		while(buscaNodo->getHijoDer()!=NULL || buscaNodo->getHijoIzq()!=NULL || buscaNodo->getDato()==val){
			if(buscaNodo->getDato()==val){
				return true;
			}else{
				if(val>buscaNodo->getDato() && buscaNodo->getHijoDer()!=NULL){
					buscaNodo=buscaNodo->getHijoDer();
				}else if(val<buscaNodo->getDato() && buscaNodo->getHijoIzq()!=NULL){
					buscaNodo=buscaNodo->getHijoIzq();
				}else if(val>buscaNodo->getDato() && buscaNodo->getHijoDer()==NULL){
					return false;
				}else{
					return false;
				}
			}
		}
		return false;
	}
}

//Imprime el recorrido preOrden del arbol
template <class T>
void ArbolBinarioAVL<T>::preOrden(NodoBinarioAVL<T> *inicio) {
	cout<<inicio->getDato()<<" ";
	if(inicio->getHijoIzq()!=NULL){
		preOrden(inicio->getHijoIzq());
	}
	if(inicio->getHijoDer()!=NULL){
		preOrden(inicio->getHijoDer());
	}
	return;
}
//Imprime el recorrido inOrden del arbol
template <class T>
void ArbolBinarioAVL<T>::inOrden(NodoBinarioAVL<T> *inicio){
	if(inicio->getHijoIzq()!=nullptr){
		inOrden(inicio->getHijoIzq());
	}
	cout<<inicio->getDato()<<" ";
	if(inicio->getHijoDer()!=nullptr){
		inOrden(inicio->getHijoDer());
	}
	return;
}
//Imprime el recorrido posOrden del arbol
template <class T>
void ArbolBinarioAVL<T>::posOrden(NodoBinarioAVL<T> *inicio){
	if(inicio->getHijoIzq()!=nullptr){
		posOrden(inicio->getHijoIzq());
	}
	if(inicio->getHijoDer()!=nullptr){
		posOrden(inicio->getHijoDer());
	}
	cout<<inicio->getDato()<<" ";
	return;
}

template <class T>
//Funcionamiento de Nivel Orden
void ArbolBinarioAVL<T>::nivelOrden(NodoBinarioAVL<T> *inicio){
    //crea una cola en lugar de pasarla como parametro de entrada, 
    //al igual que utiliza un while en lugar de un for para su analisis
	queue<NodoBinarioAVL<T>> colaNivel;
	NodoBinarioAVL<T> nodo;
	colaNivel.push(*inicio);
	
	while(!colaNivel.empty()){
	    //Por cada nivel
		nodo=colaNivel.front();
		//Primero la raiz
		colaNivel.pop();
		cout<<nodo.getDato()<<" ";
		//El valor a la izquierda
		if(nodo.getHijoIzq()!=nullptr){
			colaNivel.push(*nodo.getHijoIzq());
		}
		//El valor a la derecha
		if(nodo.getHijoDer()!=nullptr){
			colaNivel.push(*nodo.getHijoDer());
		}
	}
	return;
}
