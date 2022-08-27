#include <iostream>
using namespace std;

class CVector
{
private:
  int *m_pVect, // Pointer to the buffer
    m_nCount=0, // Control how many elements are actually used
    m_nMax=10, // Control how many are allocated as maximum
    m_nDelta=0; // To control the growing
    void Init(int delta); // Init our private variables, etc
    
  void Resize(){
    
    int *Aux=new int[m_nMax+m_nDelta];
    for(int i=0;i<m_nCount;i++){
      Aux[i]=m_pVect[i];
    }
    m_pVect=Aux;
    m_nMax+=m_nDelta;
  }
public:
  CVector(int delta=10){
    m_nDelta=delta;
    m_pVect=new int[m_nMax+m_nDelta];
  }

  

  void Insert(int elem){
    if( m_nCount == m_nMax ) // Verify the overflow
    Resize(); // Resize the vector before inserting elem
    m_pVect[m_nCount++] = elem; // Insert the element at the end
  }

  void Print(){
    for(int i=0;i<m_nCount;i++){
      cout<<m_pVect[i]<<"\t";
    }
    cout<<"\n";
  }
  
};


int main() {
  CVector vect;
  vect.Insert(5);
  vect.Insert(3);
  vect.Insert(15);
  vect.Insert(5);
  vect.Insert(3);
  vect.Insert(15);
  vect.Print();
}
