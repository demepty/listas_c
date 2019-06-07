#include <iostream>
#include <stdlib.h>



struct nodo{
	int dato;
	int exp;
	struct nodo * sgt;
};

//Declaro mis funciones
typedef struct nodo*Tlista;
void agregar(Tlista & );
void mostrar(Tlista &);
int calcular(Tlista &);
void sumar(Tlista &, Tlista &, Tlista &);
void poli(int sum, int expo ,Tlista &);
void menu(int op);

Tlista lista1=NULL;
Tlista lista2=NULL;
Tlista lista3=NULL;


using namespace std;
int main (){
int opc;

do{
	system("cls");
	cout <<"1) Cargar lista "<<endl;	
	cout <<"3) Imprimir lista"<<endl;	
	cout <<"4) Calcular el tamaño de la lista"<<endl;	
	cout <<"6) sumar"<<endl;	
	cout<<"5) Para salir"<<endl;	
	cin>>opc;
	menu(opc);
	system("pause");
}while(opc!=5);

 return 0;
}

void menu(int opcion){
	Tlista aux=NULL;
	int opc,res,dato;
	switch(opcion){
	system("cls");
	case 1 : 
	cout<<" Ingrese el numero para la lista "<<endl;
	cout<<" 1"<<endl;
	cout<<" 2 "<<endl;	
	cin>>dato;
	if(dato==1)	
	{
		agregar(lista1);
	}
	else
	{
		agregar(lista2);
	}	
	break;
	case 3: 
	cout<<" Ingrese el numero para la lista "<<endl;
	cout<<" 1"<<endl;
	cout<<" 2 "<<endl;	
	cin>>dato;
	if(dato==1)	
	{
		mostrar(lista1);
	}
	else if(dato==2){
		mostrar(lista2);
	}
	else
	{
		mostrar(lista3);
	}	
	break;
	case 6: sumar(lista1,lista2,lista3); break;
	
	case 4:
	cout<<" Ingrese el numero para la lista "<<endl;
	cout<<" 1"<<endl;
	cout<<" 2 "<<endl;	
		cin>>dato;
	if(dato==1)	
	{
		res= calcular(lista1);
		cout<<"res"<<res;
	}
	else
	{
		res= calcular(lista3);
		cout<<"res"<<res;
	}	
	break;		
	default: break;	
	}

}

void agregar(Tlista &lista){
int ndato;
int exp;
Tlista p;
Tlista q;
Tlista t;
do{
system("cls");
cout<<" Ingrese el coeficiente o '0' para salir::";
cin>>ndato;
cout<<" Ingrese el exponente :";
cin>>exp;
if(ndato==0){
	cout<<" No se agregan mas elementos a la lista..\n "<<endl;;
}
else{
		p= new nodo();	
		p->dato=ndato;
		p->exp=exp;
		p->sgt=lista;
		
	if(lista==NULL){	
		
		lista=p;
		cout<<" elemento agregado correctamente"<<endl;;		
		system("pause");		
	}
	else
	{
		cout<<" ya tenia datos"<<endl;;
		q=lista;//->1
		
		while((q!=NULL)&&(p->exp <= q->exp)){
			t=q;
			q=q->sgt;				
		}
		if(lista==q){
			p->sgt=q;
			lista=p;
		}	
		else{
			t->sgt=p;
		}
		p->sgt=q;	
	}	
}

}while(ndato!=0);

}



void mostrar(Tlista &lista){
	
	cout<<" Imprimir lista "<<endl;
	nodo *lis_aux;
	lis_aux=lista;
	int i=0;
	
	while(lis_aux != NULL)
	{	
		cout<<lis_aux->dato<<"x^"<<lis_aux->exp<<" ";	
		lis_aux=lis_aux->sgt;
		i++;
	}

}

int calcular( Tlista &lista){
	nodo *l;
	int n=0;
	l=lista;
	while(l!= NULL){
	n++;	
	l=l->sgt;
	cout<<"n"<<n;
	}
	return n;

}

void sumar(Tlista &lista1,Tlista &lista2,Tlista &lista3){
	
	nodo *lis_aux1,*lis_aux2,*lis_aux3;
	lis_aux1=lista1;
	lis_aux2=lista2;
	lis_aux3=lista3;
	int suma;
	
	while(lis_aux1!=NULL && lis_aux2!=NULL)
      {
           if(lis_aux1->exp==lis_aux2->exp)
           {
               suma=lis_aux1->dato+lis_aux2->dato;
               if(suma!=0)
               {                    
                  	poli(suma,lis_aux1->exp,lis_aux3);
                    lis_aux1=lis_aux1->sgt;
                    lis_aux2=lis_aux2->sgt;
               }
           }
           else
           {
                if(lis_aux1->exp > lis_aux2->exp)
                {                
                   poli(lis_aux1->dato,lis_aux1->exp,lis_aux3);
                   lis_aux1=lis_aux1->sgt;
                }
                else
                {                 
                poli(lis_aux2->dato,lis_aux2->exp,lis_aux3);
                lis_aux2=lis_aux2->sgt;                   
                }
           }
      }
      while(lis_aux1!=NULL)
      {
       
          poli(lis_aux3->dato,lis_aux1->exp,lis_aux3);
          lis_aux1=lis_aux1->sgt;
      }
      while(lis_aux2!=NULL)
      {
       
         poli(lis_aux2->dato,lis_aux2->exp,lis_aux3);
          lis_aux2=lis_aux2->sgt;
      }
      //cout<<"P(x)+Q(x)= ";f->recorre(f);
	
	 
}

void poli(int sum,int expo,Tlista &lista){
int ndato=sum;
int exp=expo;
Tlista p;
Tlista q;
Tlista t;

		p= new nodo();	
		p->dato=ndato;
		p->exp=exp;
		p->sgt=lista;
		
	if(lista==NULL){	
		
		lista=p;
		//cout<<" elemento agregado correctamente"<<endl;;
		//system("pause");		
	}
	else
	{
		cout<<" no esta null"<<endl;;
		q=lista;//->1
		
		while((q!=NULL)&&(p->exp <= q->exp)){
			t=q;
			q=q->sgt;				
		}
		if(lista==q){
			p->sgt=q;
			lista=p;
		}	
		else{
			t->sgt=p;
		}
		p->sgt=q;	
	}	


}




