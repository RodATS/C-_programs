//Impresion normal

void Print_lineas( int espacios, int cuando, int salto, int &lon){
  string esp((espacios*2)+salto,' ');
  string esp_2((espacios),' ');
  string lin((espacios*4)+salto/2+1,'-');
  while(cuando!=salto/2 and lon!=0){
    cout<<esp<<lin<<esp_2;
    cuando++;
    lon--;
  }
  cout<<endl;
}

void Print_N(vector<int> arbol){
  int t=arbol.size();
  int aux_lon=t/2;
  int profundidad=sqrt(t);
  if(t%2>0 or t%8==0) profundidad++;
  
  int salto=1;
  int cuando=0;
  int espacios=pow(2,profundidad)-1;
  for(int i=0;i<t;i++){
    
    string esp(espacios*2,' ');
    cout <<esp<<arbol[i]<<esp;
    cuando++;
    if(cuando==salto){
      cout<<endl;
      salto=salto*2;
      cuando =0;
      espacios=espacios/2;
      Print_lineas(espacios, cuando, salto,aux_lon);
    }
  
  }
  cout<<endl;
}
