#include <iostream>

using namespace std;

char** GenerarMatriz(int);
//Metodo Generar Matriz

char** Tablero(char**, int);
//Crear el tablero

void ImpTablero(char**, int, int, int, int);
//Imprime el tablero

char** GenerarBarcosJ1(char**, int);
//Generar barcos del jugador1

char** GenerarBarcosJ2(char**, int);
//Generar barcos del jugador2

bool VerificarCoordenada(char**, int, int);
// Verifica la coordenada ingresada
int main(){
	int size = 8;
	char** Matrix = GenerarMatriz(8);
	int TerminarJuego = 0;
	int Turno = 1;
	int cantidadcaracter = 0;
	int CantidadBarcosJ1 = 0;
	//while(TerminarTurno = 0){
		Matrix = Tablero(Matrix, size);	
		//ImpTablero(Matrix, 0, 0, size, size);
		char** MatrixJ1 = GenerarMatriz(8);
		MatrixJ1 = GenerarBarcosJ1(MatrixJ1, 8);
		//ImpTablero(MatrixJ1, 0, 0, 8, 8);
		char** MatrixJ2 = GenerarMatriz(8);
		MatrixJ2 = GenerarBarcosJ2(MatrixJ2, 8);
		//ImpTablero(MatrixJ2, 0, 0, 8, 8);
		if(Turno == 1){
			cout<<"Turno J1"<<endl;
			int i;
			int j;
			cout<<"Ingrese Coordenada i: ";
			cin>>i;
			cout<<endl;
			cout<<"Ingrese Coordenada j: ";
			cin>>j;
			bool VerCoor = VerificarCoordenada(MatrixJ1, i, j);
			if(bool == true){
				cout<<"Ha Disparado en una Parte de Barco"<<endl;
				cantidadcaracter++;
			}else{
				cout<<"Ha Fallado"<<endl;
			}
			if(cantidadcaracter == 3){
				CantidadBarcosJ1++;
				catidadcaracter = 0;
			}
			Turno = 2;
		}else if(Turno == 2){
				
		}//if/else if()
	//}//while()
	return 0;
}//main()

char** GenerarMatriz(int size){
	char** tablero = new char*[size];
	for(int i=0; i<size; i++){
		tablero[i] = new char[size];
	}//for()

	return tablero;
}//GenerarMatriz()

char** Tablero(char** tablero, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			tablero[i][j] = '*';
		}//for2()
	}//for1()
	return tablero;
}//Tablero()

void ImpTablero(char** tablero, int x, int y, int fila, int columna){
	int inicio = 0;
	//(inicio == 0){
		if(x < fila){
			if (y < columna){
				cout<<tablero[x][y];
				ImpTablero(tablero, x, y+1, fila, columna);
			}	
			if(y == columna){
				cout<<endl;
				ImpTablero(tablero, x+1, 0, fila, columna);
			}
		}else{
			inicio = 1;
		}
	
	//}	
}//ImpTablero()

char** GenerarBarcosJ1(char** tablero, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(i == 1 && j>0 && j<4){
				tablero[i][j] = '#';
			}else if(i == size-1 && j>0 && j<4){
				tablero[i][j] = '#';
			}else if(j == 4 && i>2 && i<6){
				tablero[i][j] = '#';
			}else if(j == size-1 && i>1 && i<5){
				tablero[i][j] = '#';
			}else{
				tablero[i][j] = '*';
			}//if/else if()
		}//for2()
	}//for1()
	return tablero;
}//GenerarBarcosJ1()

char** GenerarBarcosJ2(char** tablero, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(i==0 && j>0 && j<4){
				tablero[i][j] = '#';
			}else if(i==3 && j>4 && j<=size-1){
				tablero[i][j] = '#';
			}else if(j==1 && i>4 && i<=size-1){
				tablero[i][j] = '#';
			}else if(j==4 && i>3 && i<7){
				tablero[i][j] = '#';
			}else{
				tablero[i][j] = '*';
			}
		}//for2()
	}//for1()
	return tablero;
}//GenerarBarcosJ2()

bool VerificarCoordenada(char** tablero, int x, int y){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(i==x && j==y){
				if(tablero[i][j] == '#';){
					return true;
				}else{
					return false;
				}//if/else()
			}
		}//for2()
	}//for1()
}//VerificarCoordenada()
