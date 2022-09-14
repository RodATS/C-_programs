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
