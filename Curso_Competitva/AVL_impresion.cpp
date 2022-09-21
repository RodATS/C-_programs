#include <iostream>
#include <queue>
#include <math.h>
#include <fstream>//libreria para trabajar con txt
using namespace std;

template <class T>
string int2char(T number){
    string tmp = to_string(number);
    return tmp;
}

template <class T>
struct CBinTreeNode
{
    CBinTreeNode(T v)
    {
        value = v;
        nodes[0] = nodes[1] = 0;
    }
    T value;
    CBinTreeNode<T>* nodes[2]; //0 left, 1 right
};

template <class T>
class CBinTree
{
public:
    CBinTree();
    ~CBinTree();
    void DestructorR(CBinTreeNode<T>*& n);
    bool Find(T x, CBinTreeNode<T>**& p);
    bool FindFatherRecursive(T x, CBinTreeNode<T>**& p, CBinTreeNode<T>* padre);
    bool Ins(T x);
    void Ins2(T x);
    CBinTreeNode<T>* insert(CBinTreeNode<T>*r, int x);
    bool Rem(T x);
    CBinTreeNode<T>** Rep(CBinTreeNode<T>** p);
    void InOrder(CBinTreeNode<T>* n);
    void PreOrder(CBinTreeNode<T>* n);
    void PosOrder(CBinTreeNode<T>* n);
    void ReverseOrder(CBinTreeNode<T>* n);
    void LevelOrder(CBinTreeNode<T>* n);
    void Print();
    void Print_Niveles_N(CBinTreeNode<T>* r, ofstream *archivo);
    void Print_Niveles_S(CBinTreeNode<T>* r, ofstream *archivo);
    void Print_Niveles_E(CBinTreeNode<T>* r, ofstream *archivo);
    void Print_Niveles_O(CBinTreeNode<T>* r, ofstream *archivo);

    void Nivel(CBinTreeNode<T>* n, int altura,priority_queue<string>& q);
    void Podar(CBinTreeNode<T>* n);
    CBinTreeNode<T>* Root();
    int MaxDepth(CBinTreeNode<T>* n);
    CBinTreeNode<T>* llBalance(CBinTreeNode<T>* p);
    CBinTreeNode<T>* rrBalance(CBinTreeNode<T>* p);
    CBinTreeNode<T>* lrBalance(CBinTreeNode<T>* p);
    CBinTreeNode<T>* rlBalance(CBinTreeNode<T>* p);
    int Desbalance(CBinTreeNode<T>* p);
    CBinTreeNode<T>* Balance(CBinTreeNode<T>* &p);
    
private:
    CBinTreeNode<T>* root;
    bool brep;
};

template <class T>
CBinTree<T>::CBinTree()
{
    root = 0;
    brep = 0;
}

template <class T>
CBinTree<T>::~CBinTree()
{
    DestructorR(root);
}

template <class T>
void CBinTree<T>::DestructorR(CBinTreeNode<T>*& n){
  if(n){
    DestructorR(n->nodes[0]);
    DestructorR(n->nodes[1]);
    delete n;
    n=0;
  }
}

template <class T>
CBinTreeNode<T>* CBinTree<T>::Root(){
  return (this)->root;
}

template <class T>
bool CBinTree<T>::Find(T x, CBinTreeNode<T>**& p)
{
    for (   p = &root;
            *p && (*p)->value != x;
            p = &((*p)->nodes[ (*p)->value < x ])
        );
    return *p != 0;
}

template <class T>
bool CBinTree<T>::FindFatherRecursive(T x, CBinTreeNode<T>**& p, CBinTreeNode<T>* padre)
{ 
    if (!(padre->nodes[padre->value < x])){
      p=&padre;
      return 1;
    }
    else if (padre->nodes[padre->value < x]->value == x){
      p=&padre;
      return 1;
    }
    FindFatherRecursive(x,p,padre->nodes[ padre->value < x ]);
    Balance(padre);
    return  1;
}

template <class T>
bool CBinTree<T>::Ins(T x)
{
    CBinTreeNode<T>** p;
    CBinTreeNode<T>** q;
    if ( Find(x,p) ) return 0;
    *p = new CBinTreeNode<T>(x);
    return 1;
}
template <class T>
void CBinTree<T>::Ins2(T x)
{
    root = insert(root, x);
} 

template <class T>
CBinTreeNode<T>* CBinTree<T>::insert(CBinTreeNode<T>*r, int x) {
   if (r == NULL) {
      r = new CBinTreeNode<T>(x);
      return r;
   } 
   else {
      (r->nodes[r->value < x]) = insert(r->nodes[r->value < x], x);
      r = Balance(r);
   } 
   return r;
}

template <class T>
bool CBinTree<T>::Rem(T x)
{
    CBinTreeNode<T>** p;
    if ( !Find(x,p) ) return 0;
    if ( (*p)->nodes[0] && (*p)->nodes[1] )
    {
        CBinTreeNode<T>** q = Rep(p);
        (*p)->value = (*q)->value;
        p = q;
    }
    CBinTreeNode<T>* t = *p;
    *p = (*p)->nodes[ (*p)->nodes[1] != 0 ];
    delete t;
    return 1;
}

template <class T>
CBinTreeNode<T>** CBinTree<T>::Rep(CBinTreeNode<T> ** p)
{
    CBinTreeNode<T>** q;
    for ( q = &(*p)->nodes[!brep];
         (*q)->nodes[brep];
         q = &(*q)->nodes[brep] );
    brep = !brep;
    return q;
}

template <class T>
void CBinTree<T>::InOrder(CBinTreeNode<T>* n)
{
    if ( !n ) return;
    InOrder(n->nodes[0]);
    cout<<n->value<<" ";
    InOrder(n->nodes[1]);
}

template <class T>
void CBinTree<T>::PreOrder(CBinTreeNode<T>* n)
{
    if ( !n ) return;
    cout<<n->value<<" ";
    PreOrder(n->nodes[0]);
    PreOrder(n->nodes[1]);
}

template <class T>
void CBinTree<T>::PosOrder(CBinTreeNode<T>* n)
{
    if ( !n ) return;
    PosOrder(n->nodes[0]);
    PosOrder(n->nodes[1]);
    cout<<n->value<<" ";
}

template <class T>
void CBinTree<T>::ReverseOrder(CBinTreeNode<T>* n)
{
    if ( !n ) return;
    ReverseOrder(n->nodes[1]);
    cout<<n->value<<" ";
    ReverseOrder(n->nodes[0]);
}

template <class T>
void CBinTree<T>::LevelOrder(CBinTreeNode<T>* n)
{
    if ( !n) return;
    queue< CBinTreeNode<T>* > q;
    for ( q.push(n); !q.empty(); q.pop() )
    {
        cout<<q.front()->value<<" ";
        if ( q.front()->nodes[0] ) q.push( q.front()->nodes[0] );
        if ( q.front()->nodes[1] ) q.push( q.front()->nodes[1] );
    }
}

template <class T>
int CBinTree<T>::MaxDepth(CBinTreeNode<T>* n)
{
  if ( !n ) return 0;
  int Prof_h1=MaxDepth(n->nodes[0])+1;
  int Prof_h2=MaxDepth(n->nodes[1])+1;
  return Prof_h1>Prof_h2 ? Prof_h1:Prof_h2;
}

template <class T>
void CBinTree<T>::Print()
{
    InOrder(root);
    cout<<"\n";
}

/*
void Print_lineas( int espacios, int cuando, int salto){
  string esp((espacios*2)+salto/2,' ');
  string esp_2((espacios),' ');
  string lin((espacios*4),'-');
  while(cuando!=salto/2){
    cout<<esp<<lin<<esp_2;
    cuando++;
  }
  cout<<endl;
}
*/

template <class T>
void CBinTree<T>::Print_Niveles_N(CBinTreeNode<T>* r, ofstream *archivo){
    if ( !r ) return;
    int h = MaxDepth(r);//profundidad
    int d = h;
    priority_queue<string> q;
    for ( ; h; h--)
    {   int num_esp;
        num_esp=(pow(2,h-1)-1);
        string espacios(num_esp*2,' ');
        cout<<espacios;
        *archivo<<espacios;
        Nivel(r,d-h,q);
        //Print_lineas(num_esp, 0, q.size());
        for (; !q.empty(); q.pop())
          cout<<q.top()<<espacios<<"  "<<espacios;
          *archivo<<q.top();
          *archivo<<espacios; 
          *archivo<<"  ";
          *archivo<<espacios;
        cout<<endl;
        *archivo<<"\n";
    }
}

template <class T>
void CBinTree<T>::Print_Niveles_S(CBinTreeNode<T>* r, ofstream *archivo){
    if ( !r ) return;
    int h = MaxDepth(r);//profundidad
    int d = h;
    priority_queue<string> q;
    //for ( ; h; h--)
    for(int i=0;i<=h;i++)
    {   int num_esp;
        num_esp=(pow(2,i)-1);
        string espacios(num_esp*2,' ');
        cout<<espacios;
        *archivo<<espacios;
        //Nivel(r,d-h,q);
        Nivel(r,h-i,q);
        //Print_lineas(num_esp, 0, q.size());
        for (; !q.empty(); q.pop())
          cout<<q.top()<<espacios<<"  "<<espacios;
          *archivo<<q.top();
          *archivo<<espacios; 
          *archivo<<"  ";
          *archivo<<espacios;
        cout<<endl;
        *archivo<<"\n";
    }
}



void Llenado(vector<string> &q_aux, priority_queue<string> q){
  for(;!q.empty();q.pop()){
    q_aux.push_back(q.top());
    cout<<q.top()<<" ";
  }
  cout<<endl;
}

template <class T>
void CBinTree<T>::Print_Niveles_E(CBinTreeNode<T>* r, ofstream *archivo){
    string impresion="";
    if ( !r ) return;
    int h = MaxDepth(r);//profundidad
    int d = h;
    priority_queue<string> q;
    vector<string> q_aux;
    for ( ; h; h--)
    {   int num_esp;
        num_esp=(pow(2,h-1)-1);
        string espacios(num_esp*2,' ');
        cout<<espacios;
        impresion+=espacios;
        //*archivo<<espacios;
        Nivel(r,d-h,q);
        Llenado(q_aux,q);
        
        //Print_lineas(num_esp, 0, q.size());
        for (; !q.empty(); q.pop())
          cout<<q.top()<<espacios<<"  "<<espacios;
          impresion+=q.top()+espacios+" "+espacios;
         /* *archivo<<q.top();
          *archivo<<espacios; 
          *archivo<<"  ";
          *archivo<<espacios;*/
        cout<<endl;
        //*archivo<<"\n";
        impresion+="\n";
    }
    *archivo<<impresion;
}

template <class T>
void CBinTree<T>::Nivel(CBinTreeNode<T>* n, int altura,priority_queue<string>& q){
  if(altura==0){
    if(n){
      q.push(int2char(n->value)); return;
    }
    else{
      q.push("  ");
    }
  }
  else {
    if (n){
      Nivel(n->nodes[0], altura-1, q);
      Nivel(n->nodes[1], altura-1, q);
    }
    else{
      Nivel(NULL, altura-1,q);
      Nivel(NULL, altura-1,q);
    }
  }
}

template <class T>
void CBinTree<T>::Podar(CBinTreeNode<T>* n){
  if(n){
    if(n->nodes[0] && n->nodes[1]){
      if(n->nodes[0]->nodes[0] && n->nodes[0]->nodes[1] && n->nodes[1] && n->nodes[1]->nodes[0] && n->nodes[1]->nodes[1]){
          Podar(n->nodes[0]->nodes[0]);
          Podar(n->nodes[1]->nodes[0]);
          Podar(n->nodes[0]->nodes[1]);
          Podar(n->nodes[1]->nodes[1]);
          }
      else{
          DestructorR(n->nodes[0]->nodes[0]);
          DestructorR(n->nodes[1]->nodes[0]);
          DestructorR(n->nodes[0]->nodes[1]);
          DestructorR(n->nodes[1]->nodes[1]);
        }
      Podar(n->nodes[0]);
      Podar(n->nodes[1]);
    }

  }
}

template <class T>
CBinTreeNode<T>* CBinTree<T>::llBalance(CBinTreeNode<T>* p){
  CBinTreeNode<T>* t = p->nodes[0];
  p->nodes[0] = t->nodes[1];
  t->nodes[1] = p;
  return t;
}

template <class T>
CBinTreeNode<T>* CBinTree<T>::rrBalance(CBinTreeNode<T>* p){
  CBinTreeNode<T>* t = p->nodes[1];
  p->nodes[1] = t->nodes[0];
  t->nodes[0] = p;
  return t;
}

template <class T>
CBinTreeNode<T>* CBinTree<T>::lrBalance(CBinTreeNode<T>* p){
  CBinTreeNode<T>* t = p->nodes[0];
  CBinTreeNode<T>* b = t->nodes[1];
  p->nodes[0] = b->nodes[1];
  t->nodes[1] = b->nodes[0];
  b->nodes[0] = t;
  b->nodes[1] = p;
  return b;
}

template <class T>
CBinTreeNode<T>* CBinTree<T>::rlBalance(CBinTreeNode<T>* p){
  CBinTreeNode<T>* t = p->nodes[1];
  CBinTreeNode<T>* b = t->nodes[0];
  p->nodes[1] = b->nodes[0];
  t->nodes[0] = b->nodes[1];
  b->nodes[1] = t;
  b->nodes[0] = p;
  return b;
}

template <class T>
int CBinTree<T>::Desbalance(CBinTreeNode<T>* p){
  int d = MaxDepth(p->nodes[0]) - MaxDepth(p->nodes[1]);
  return d;
}

template <class T>
CBinTreeNode<T>* CBinTree<T>::Balance(CBinTreeNode<T>* &r){
  if(r){
    //if(MaxDepth(r)<5){
    int desbalance = Desbalance(r),dbl = r->nodes[0]?Desbalance(r->nodes[0]):0, dbr = r->nodes[1]?Desbalance(r->nodes[1]):0;
    //cout<<desbalance<<" "<<dbl<<" "<<dbr<<endl;

    if (desbalance > 1){
      if(dbl > 0)
        r = llBalance(r);
      else
        r = lrBalance(r);
    }
    else if (desbalance < -1){
      if(dbr > 0)
        r = rlBalance(r);
      else
        r = rrBalance(r);
    }
    return r;
  }
  return r;
}


///////////////////////////////////////////


void Print_lineas( int espacios, int cuando, int salto, int &lon){
  string esp((espacios*2)+salto/2,' ');
  string esp_2((espacios),' ');
  string lin((espacios*4),'-');
  while(cuando!=salto/2){
    cout<<esp<<lin<<esp_2;
    cuando++;
  }
  cout<<endl;
}

void Print_S(vector<int> arbol){
  int t=arbol.size();
  int profundidad=sqrt(t);//hallamos la profundidad
  int cantidad_elem=pow(2,profundidad)*2-1;//cantidad de elementos que debrian de haber para que esté completo
  
  while(arbol.size()<cantidad_elem){
    arbol.push_back(0000);
  }
  int aux=pow(2,profundidad);
  t=arbol.size();
  int aux_lon=t/2;
  
  
  int salto=pow(2,profundidad);
  int cuando=0;
  //int espacios=pow(2,profundidad)-1;
  string ceros(4,'0');
  int espacios=1;
  for(int i=t-1;i>-1;i--){
    
    string esp(espacios*2,' ');
    if(arbol[i]==0) cout <<esp<<ceros<<esp;
    else cout <<esp<<arbol[i]<<esp;
    cuando++;
    if(cuando==salto){
      cout<<endl;
      cuando =0;
      Print_lineas(espacios, cuando, salto,aux_lon);
      espacios=espacios*2;
      salto=salto/2;
    }
  
  }
  cout<<endl;
}

void print_normal(vector<int> arbol){
  for(int i=0;i<arbol.size();i++){
    cout<<arbol[i]<<endl;
  }
}

///////////////////////////////
int main()
{
    CBinTree<int> t;
    t.Ins2(5000);
    t.Ins2(1000);
    t.Ins2(2000);
    //t.Print_Niveles(t.Root());
    t.Ins2(3000);
    //t.Print_Niveles(t.Root());
    t.Ins2(4300);
    //t.Print_Niveles(t.Root());
    t.Ins2(9500);
    //t.Print_Niveles(t.Root());
    t.Ins2(6000);
    t.Ins2(3500);
    t.Ins2(7003);
    t.Ins2(7000);
    t.Ins2(2008);
    t.Ins2(9000);
    t.Ins2(9900);
    t.Ins2(9009);//permite repeticiones



    string Norte= "Arbol_Norte" ,Sur = "Arbol_Sur",Este = "Arbol_Este";


    //estructura para generar un archivo
    ofstream archivo_N,archivo_S,archivo_E;//declarando la variable tipo archivo
    archivo_N.open(Norte.c_str(), ios::out);
    archivo_S.open(Sur.c_str(), ios::out);
    archivo_E.open(Este.c_str(), ios::out);  
    
    t.Print_Niveles_N(t.Root(),&archivo_N);
  cout<<"////////////////////////"<<endl;
 // t.Print_Niveles_S(t.Root(),&archivo_S);
    //t.Print();
  t.Print_Niveles_E(t.Root(),&archivo_E);

  archivo_N.close();
  archivo_S.close();
  archivo_E.close();
}
