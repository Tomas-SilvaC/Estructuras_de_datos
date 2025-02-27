#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Palabra{
    public:
    string Word;
    int NumeroLinea;
    void setWord(string vec){
        Word=vec;
    }
    void setNumLinea(int num){
        NumeroLinea=num;
    }
    int getNumLinea(){
        return NumeroLinea;
    }
    string getWord(){
        return Word;
    }
};

class ArchivoTexto{
  public:
  vector <Palabra> Lineastexto;


  void setLineas(vector<Palabra> vec){
    Lineastexto=vec;
  }
  vector<Palabra> getLineas(){
    return Lineastexto;
  }


  /*Da las líneas de texto, no incluyendo las primeras dos
  *@param: nada
  *@return: numero de lineas de texto (int)
  */
  int ObtenerNumeroDeLineas(){
      return Lineastexto[0].getNumLinea();
  }
  /*Busca las palabras que tengan la subcadena al principio de la palabra
  *@param: Subcadena (string)
  *@return: nada
  */
  void BuscarPrincipio(string Subcadena){
      queue <Palabra> ColaPalabras;
      int TamSub=Subcadena.length();
      for(int i=2; i<Lineastexto.size(); i++){
          if(Lineastexto[i].getWord().substr(0,TamSub)==Subcadena){
              ColaPalabras.push(Lineastexto[i]);
          }
      }
      cout<<"Hay un total de "<<ColaPalabras.size()<<" palabras que inician con: "<<Subcadena<<endl;
      while(!ColaPalabras.empty()){
        cout<<"Linea: "<<ColaPalabras.front().getNumLinea()<<" - "<<ColaPalabras.front().getWord()<<endl;
        ColaPalabras.pop();
      }
  }
  /*Busca las palabras que contengan la subcadena
  *@param: Subcadena (string)
  *@return: nada
  */
  void BuscarContiene(string Subcadena){
        queue <Palabra> ColaPal;
        for(int i=2; i<Lineastexto.size(); i++){
            if (Lineastexto[i].getWord().find(Subcadena) != string::npos ) {
              ColaPal.push(Lineastexto[i]);
            }
    
        }
    
        cout<<"Hay un total de "<< ColaPal.size() <<" palabras que contienen: "<<Subcadena<<endl;
        while(!ColaPal.empty()){
          cout<<"Linea: "<<ColaPal.front().getNumLinea()<<" - "<<ColaPal.front().getWord()<<endl;
          ColaPal.pop();
    }
  }

};

int main() {
  string linea;
  ArchivoTexto Arc;
  vector<Palabra> PalabrasEnToTal;
  Palabra P;
  stack<char> ST;
  cout<<"Escriba el nombre del archivo: "<<endl;
  string NombreArchivo;
  cin>>NombreArchivo;
  ifstream fichero (NombreArchivo);
  //Para asignar el número de la línea donde se encuentra la palabra actual
  int conta=0;
  if(fichero.is_open()){
      while(getline(fichero,linea)){
        stringstream Palabras(linea);
        string palabra;
          while (Palabras >> palabra){
            //Hay unas palabras que empiezan en mayúscula y si no se pasa a minúscula,
            //el programa no las va a contar si tienen la subcadena al principio.
            transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower); 
            P.setWord(palabra);
            P.setNumLinea(conta - 2);
            PalabrasEnToTal.push_back(P); 
          }
        conta++;
      }
      fichero.close();
  }
  else{
      cout<<"Archivo no encontrado"<<endl;
  }

  Arc.setLineas(PalabrasEnToTal);

  Arc.BuscarContiene(Arc.getLineas()[1].getWord());
  cout<<endl;
  Arc.BuscarPrincipio(Arc.getLineas()[1].getWord());
  cout<<endl;
  string s;
  //Se usa una pila para invertir la subcadena
  for (char c : Arc.getLineas()[1].getWord()){
    ST.push(c);
  }
  while (!ST.empty()) {  
      s.push_back(ST.top());
      ST.pop();
  }
  Arc.BuscarContiene(s);
}
