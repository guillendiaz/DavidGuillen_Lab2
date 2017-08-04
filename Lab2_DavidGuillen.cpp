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

bool VerificarCoordenada(char**, int, int, int);
// Verifica la coordenada ingresada

char** NuevoTablero(char**, int, int, int);
//Pone donde disparo el jugador

int VerificarBarcoJ1(char**, int, int, int);
//Verifica las vidas de los barcos

int VerificarBarcoJ2(char**, int, int, int);

int main(){
	int size = 8;
	char** Matrix = GenerarMatriz(8);
	int TerminarJuego = 0;
	int Turno = 1;
	int CantidadBarcosJ1 = 0;
	int CantidadBarcosJ2 = 0;
	int VerBarcoJ1 = 0;
	int BarJ1_1 = 0;
	int BarJ1_2 = 0;
	int BarJ1_3 = 0;
	int BarJ1_4 = 0;
	int VerBarcoJ2 = 0;
	int BarJ2_1 = 0;
	int BarJ2_2 = 0;
	int BarJ2_3 = 0;
	int BarJ2_4 = 0;
	char** Matrix2 =GenerarMatriz(8);
	Matrix2 = Tablero(Matrix2, size);
	Matrix = Tablero(Matrix, size);	
	ImpTablero(Matrix, 0, 0, size, size);
	char** MatrixJ1 = GenerarMatriz(8);
	MatrixJ1 = GenerarBarcosJ1(MatrixJ1, 8);
	//ImpTablero(MatrixJ1, 0, 0, 8, 8);
	char** MatrixJ2 = GenerarMatriz(8);
	MatrixJ2 = GenerarBarcosJ2(MatrixJ2, 8);
	//ImpTablero(MatrixJ2, 0, 0, 8, 8);
	while(TerminarJuego == 0){
		if(Turno == 1){
			cout<<"Turno J1"<<endl;
			int i;
			int j;
			cout<<"Ingrese Coordenada i: ";
			cin>>i;
			cout<<"Ingrese Coordenada j: ";
			cin>>j;
			if(i>7 || j>7){
				cout<<"Fuera de Rango";
			}else{
				
				bool VerCoor = VerificarCoordenada(MatrixJ1, i, j, size);
				if(VerCoor == true){
					cout<<"Ha Disparado en una Parte de Barco"<<endl;
				}else{
					cout<<"Ha Fallado"<<endl;
				}
				VerBarcoJ1 = VerificarBarcoJ1(MatrixJ1, i, j, size);
				if(VerBarcoJ1 == 1){
					BarJ1_1++;
					VerBarcoJ1 = 0;
				}else if(VerBarcoJ1 == 2){
					BarJ1_2++;
					VerBarcoJ1 = 0;
				}else if(VerBarcoJ1 == 3){
					BarJ1_3++;
					VerBarcoJ1 = 0;
				}else if(VerBarcoJ1 == 4){
					BarJ1_4++;
					VerBarcoJ1 = 0;
				}
				if(BarJ1_1 == 3 || BarJ1_2 ==3 || BarJ1_3 == 3 || BarJ1_4 == 3){
					CantidadBarcosJ1++;
				}
				Turno = 2;
				Matrix = NuevoTablero(Matrix, i, j, size);
				ImpTablero(Matrix, 0, 0, size, size);
			}
		}//ifJ1
	       
		if(Turno == 2){
			cout<<"Turno J2"<<endl;
			int i;
			int j;
			cout<<"Ingrese Coordenada i: ";
			cin>>i;
			cout<<"Ingrese Coordenada j: ";
			cin>>j;
			if(i>7 || j>7){
				cout<<"Fuera de Rango"<<endl;
			}else{
				
				bool VerCoor2 = VerificarCoordenada(MatrixJ2, i, j, size);
				if(VerCoor2 == true){
					cout<<"Ha Disparado en una Parte de Barco"<<endl;
				}else{
					cout<<"Ha Fallado"<<endl;
				}
				VerBarcoJ2 = VerificarBarcoJ2(MatrixJ2, i, j, size);
				if(VerBarcoJ2 == 1){
					BarJ2_1++;
					VerBarcoJ2 = 0;
				}else if(VerBarcoJ2 == 2){
					BarJ2_2++;
					VerBarcoJ2 = 0;
				}else if(VerBarcoJ2 == 3){
					BarJ2_3++;
					VerBarcoJ2 = 0;
				}else if(VerBarcoJ2 == 4){
					BarJ2_4++;
					VerBarcoJ2 = 0;
				}
				if(BarJ2_1 == 3 || BarJ2_2 ==3 || BarJ2_3 == 3 || BarJ2_4 == 3){
					CantidadBarcosJ2++;
				}
				Turno = 1;
				Matrix2 = NuevoTablero(Matrix2, i, j, size);
				ImpTablero(Matrix2, 0, 0, size, size);
			}	
		}//ifJ2
	}//while()
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

bool VerificarCoordenada(char** tablero, int x, int y, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(i==x && j==y){
				if(tablero[i][j] == '#'){
					return true;
					tablero[i][j] = '*';
				}else{
					return false;
				}//if/else()
			}
		}//for2()
	}//for1()
}//VerificarCoordenada()

char** NuevoTablero(char** tablero, int x, int y, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(i==x && j==y){
				tablero[i][j] = 'x';
			}
		}//for2()
	}//for1()
	return tablero;
}//NuevoTablero()

int VerificarBarcoJ1(char** tablero, int x, int y, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(i == 1 && j>0 && j<4 && tablero[i][j] == '#'){
				return 1;
			}else if(i == size-1 && j>0 && j<4 && tablero[i][j] == '#'){
				return 2;
			}else if(j == 4 && i>2 && i<6 && tablero[i][j] == '#'){
				return 3;
			}else if(j == size-1 && i>1 && i<5 &&tablero[i][j] == '#'){
				return 4;
			}else{
				return 0;
			}//if/else if()
		}//for2()
	}//for1()
}//VerificarBarcosJ1()

int VerificarBarcoJ2(char** tablero, int x, int y, int size){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			if(i == 1 && j>0 && j<4 && tablero[i][j] == '#'){
				return 1;
			}else if(i == size-1 && j>0 && j<4 && tablero[i][j] == '#'){
				return 2;
			}else if(j == 4 && i>2 && i<6 && tablero[i][j] == '#'){
				return 3;
			}else if(j == size-1 && i>1 && i<5 &&tablero[i][j] == '#'){
				return 4;
			}else{
				return 0;
			}//if/else if()
		}//for2()
	}//for1()
}//VerificarBarcosJ1()
