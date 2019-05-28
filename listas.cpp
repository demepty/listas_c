#include <iostream>
#include <stdlib.h>



struct nodo{
	int dato;
	struct nodo * sgt;
};

//Declaro mis funciones
typedef struct nodo*Tlista;
void agregar(Tlista & );
void mostrar(Tlista &);
int calcular(Tlista &);
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
	else
	{
		mostrar(lista2);
	}	
	break;	
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
		res= calcular(lista2);
		cout<<"res"<<res;
	}	
	break;		
	default: break;	
	}

}

void agregar(Tlista &lista){
int ndato;
Tlista p;
do{
system("cls");
cout<<" Ingrese el numero para la lista, '0' para salir ";
cin>>ndato;
if(ndato==0){
	cout<<" No se agregan mas elementos a la lista..\n "<<endl;;
}
else{
	p= new nodo();
	p->dato=ndato;
	p->sgt=lista;
	lista=p;
	cout<<" elemento agregado correctamente"<<endl;;
	system("pause");
}

}while(ndato!=0);

}

void mostrar(Tlista &lista){
	
cout<<" Imprimir lista ";
nodo *lis_aux;
lis_aux=lista;
int i=0;

while(lis_aux != NULL)
{
	
	cout<<lis_aux->dato<<" -->";	
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




