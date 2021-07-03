#include <iostream>
#include <locale.h>

using namespace std;

struct lista
{
	int info;
	lista *sig,*ant;
}

*CAB=NULL,*AUX=NULL,*P=NULL,*FD=NULL,*QD=NULL,*Fd=NULL,*Qd=NULL;

int main()
{
  setlocale(LC_CTYPE, "Spanish");
	void insertard(void);
	void extraerd(void);
	void visualizard(void);
	void visualizari(void);
	void eliminardespues();
	void eliminarantes();
	char opc;
	do{
		system("cls");
		cout << endl;
		cout << " LISTA DOBLEMENTE ENLAZADA" << endl;
		cout  << endl;
		cout << endl;
		cout << "SELECCIONE UNA OPCION" << endl;
		cout  << endl;
		cout  << endl;
		cout << "1) INSERTAR" << endl;
		cout << "2) VISUALIZAR ASCENDENTE"<< endl;
		cout << "3) VISUALIZAR DESCENDENTE" << endl;
		cout << "4) INGRESAR Y ELIMINAR SIGUIENTE" << endl;
		cout << "5) INGRESAR Y ELIMINAR ANTERIOR" << endl;
		cout << "6) SALIR" << endl;
		cout <<  endl;

		opc=cin.get();

		switch(opc)
		{
		case '1':
			insertard();
			break;
		case '2':
			visualizard();
			break;
		case '3':
			visualizari();
			break;
		case '4':
			eliminardespues();
			break;
        	case'5':
			eliminarantes();
			break;
		}
	}while(opc!='6');
	system("pause");
	return 0;
}

void insertard(void)
{
	P=CAB; /* primera ejecución de este método P = NULL */
	AUX= new lista;
	system("cls");
	cout << "INGRESE UN NUMERO ENTERO: " << endl;
	cin >> AUX->info;
	AUX->sig=CAB; //El puntero al siguiente nodo sea nulo (CAB es nulo)
	AUX->ant=CAB; //El puntero al anterior nodo sea nulo (CAB es nulo)
	if(CAB==NULL){ //Pregunto si CAB es igual igual a Nulo
		CAB=AUX;
		P=AUX;//tras primera ejecucion método P ya no es NULL pero P está apuntando a AUX
	}else{ //ESTO SI
		while(P->sig!=CAB){
			P=P->sig;
		}
	}
	P->sig=AUX; //El puntero siguiente de P toma el valor de AUX
	AUX->ant=P;
	CAB->ant=AUX;
}

void eliminardespues(){
	int x;
	system("cls");
	cout << "INGRESE UN NUMERO PARA ELIMINAR EL SIGUIENTE: " << endl;
	cin >> x;
	FD=CAB;
	QD=CAB;
	while(FD->info!=x&&FD->sig!=CAB){ //si lo que voy a eliminar es distinto al número que me ingresaron y si hay otro
		FD=FD->sig; //paso al siguiente nodo
	}
	QD=FD->sig;
	if(FD->sig==CAB&&FD->info==x){
		cout << "es el top NO SE PUEDE ELIMINAR" << endl;
	}else
	   if(FD->sig==CAB&&FD->info!=x){
		cout << "EL NUMERO INGRESADO NO SE ENCUENTRA EN LA LISTA" << endl;
	}else{
		   FD->sig=QD->sig;
		   (QD->sig)->ant=FD;
		   cout << "ELIMINADO " << QD->info;
		   delete QD; //liberar el espacio en memoeria ocupado por QD
	   }
	system("pause");
}

void eliminarantes()
{
	int xd;
	system("cls");
	cout << "INGRESE UN NUMERO PARA ELIMINAR EL ANTERIOR: " << endl;
	cin >> xd;

	Fd=CAB;	Qd=CAB;

	while(Fd->info!=xd){
		Fd=Fd->ant;
	}
  Qd=Fd->ant;
	if(Fd==CAB){
		cout << "Es el top NO SE PUEDE ELIMINAR" << endl;
	}
  else{
		if(Qd==CAB){
			CAB=CAB->sig;
			Fd->ant=Qd->ant;
			(Fd->ant)->sig=Fd;
			cout << "ELIMINADO " << Qd->info << endl;
		}else{
			Fd->ant=Qd->ant;
			(Qd->ant)->sig=Fd;
			cout << "ELIMINADO " << Qd->info << endl;
		}
		delete Qd;
	}
	system("pause");
}

void visualizard(void)
{
	system("cls");
	if(CAB==NULL){
		cout << "LISTA VACIA" << endl;
		system("pause");
	}
	AUX=CAB;
	cout << "LISTA: "<< endl;
	while(AUX->sig!=CAB){
		cout << "->" << AUX->info<< endl;
		AUX=AUX->sig;
	}
	if(AUX->sig==CAB){

		cout <<"->" << AUX->info << endl;
	}
	system("pause");
}

void visualizari(void)
{
	system("cls");
	if(CAB==NULL){
		cout << "LISTA VACIA" << endl;
		system("pause");
	}
	AUX=CAB->ant;
	cout << "LISTA: " << endl;
	do{

		cout << AUX->info << endl;
		AUX=AUX->ant;
	}while(AUX->sig!=CAB);
	system("pause");
}