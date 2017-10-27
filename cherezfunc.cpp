#include <iostream>
using namespace std;
float ** readmatr (unsigned int rows1,unsigned int columns1, float** matr) {
	matr = new float *[ rows1 ];
	for( unsigned int i = 0; i < rows1; ++i ) {
	 	matr[ i ] = new float[ columns1 ];
	    	for( unsigned int j = 0; j < columns1; ++j ) {
	       	 	matr[ i ][ j ] = 0.0f;
	    	}
	}
	for (unsigned int i=0; i<rows1; i++) {	
		for (unsigned int j=0; j<columns1; j++){
			cin >> matr[i][j];
		}
	}
	return matr;
}
bool pl (float **matr1, int rows1, int columns1, float **matr2, int rows2, int columns2, float ** matr, int rows3, int columns3) {	
	bool succ=0.0f;
	if (rows1 == rows2 && columns1 == columns2){	
		succ=1;
		for (unsigned int i = 0; i<rows3; i++){	
	 		for (unsigned int j = 0; j<columns3; j++){
	 		  	matr[i][j] = matr1[i][j]+matr2[i][j];
			}
		}
	}
	return succ;
}
bool min (float **matr1, int rows1, int columns1, float **matr2, int rows2, int columns2, float ** matr, int rows3, int columns3) {	
	bool succ=0.0f;
	if (rows1 == rows2 && columns1 == columns2){	
		succ=1;
		for (unsigned int i = 0; i<rows3; i++){	
	 		for (unsigned int j = 0; j<columns3; j++){
	 		  	matr[i][j] = matr1[i][j]-matr2[i][j];
			}
		}
	}
	return succ;	
}
bool umn (float **matr1, int rows1, int columns1, float **matr2, int rows2, int columns2, float ** matr, int rows3, int columns3) {	
	bool succ=0.0f;
	if (columns1 == rows2) {	
		for(unsigned int i = 0; i < rows3; ++i ){
    			for(unsigned int j = 0; j < columns3; ++j ){
      		  		int result = 0;
      		   		for( int k = 0; k < columns3; ++k ){
       			 		result += matr1[i][k] * matr2[k][j];
      		   		}
      		  		matr[i][j] = result;
    			}
  		}
	 	cout << endl;
	 	succ=1;
	}
	return succ;	
}
float** obrmat(int x, float **mass, float **Obrmatr) {	
	int i, j, k;
	Obrmatr=new float* [x];
	for(i=0; i<x; i++) {
		Obrmatr[i]=new float [x];
		for(j=0; j<x; j++) {Obrmatr[i][j]=0;}
		Obrmatr[i][i]=1; 
	}
	float a, b;
	for(i=0; i<x; i++) {
		a=mass[i][i];
		for(j=i+1; j<x; j++) {
			b=mass[j][i];
			for(k=0; k<x; k++) {
				mass[j][k]=mass[i][k]*b-mass[j][k]*a;
				Obrmatr[j][k]=Obrmatr[i][k]*b-Obrmatr[j][k]*a; 
			} 
		} 
	}
	float sum;
	for(i=0; i<x; i++) {
		for(j=x-1; j>=0; j--) {
			sum=0;
			for(k=x-1;k>j;k--){
				sum+=mass[j][k]*Obrmatr[k][i];
				if(mass[j][j]==0) {
					for(i=0;i<x;i++){
						delete []Obrmatr[i];
						delete []Obrmatr;
					}
				}
			}
			Obrmatr[j][i]=(Obrmatr[j][i]-sum)/mass[j][j]; 
		} 
	} 
	return Obrmatr; 
}
float **matr, **matr1, **matr2;
	int main () {
		int rows1, rows2, rows3, columns1, columns2, columns3;
		char op;
		bool k=0;
		cin >> rows1;
		op=cin.get();
		cin >> columns1;
		matr1=readmatr (rows1, columns1, matr1);
		cin >> op;
		if (op == 'T') {
			rows3=columns1;
			columns3=rows1;
			matr = new float *[ rows3 ];
			for( unsigned int i = 0; i < rows3; ++i ) {
	    			matr[ i ] = new float[ columns3 ];
	    			for( unsigned int j = 0; j < columns3; ++j ) {
	       	 			matr[ i ][ j ] = 0.0f;
	    			}
			}
		}
		else {	
			rows3=rows1;
			columns3=columns1;
			matr = new float *[ rows3 ];
			for( unsigned int i = 0; i < rows3; ++i ) {
	    			matr[ i ] = new float[ columns3 ];
	    			for( unsigned int j = 0; j < columns3; ++j ) {
	       	 			matr[ i ][ j ] = 0.0f;
	    			}
			}
		}	
			 if(op=='+') {
				cin >> rows2;
				op=cin.get();
				cin >> columns2;
				matr2=readmatr (rows2, columns2, matr2);
				k=pl(matr1, rows1, columns1, matr2, rows2, columns2, matr, rows3, columns3);
			}
			else if(op== '-') {	
				cin >> rows2;
				op=cin.get();
				cin >> columns2;
				matr2=readmatr (rows2, columns2, matr2);
				k=min(matr1, rows1, columns1, matr2, rows2, columns2, matr, rows3, columns3);
			}
			else if(op== '*') {	
				cin >> rows2;
				op=cin.get();
				cin >> columns2;
				matr2=readmatr (rows2, columns2, matr2);
				k=umn (matr1, rows1, columns1, matr2, rows2, columns2, matr, rows3, columns3);			 
			}
			else if(op== 'T') {
				for (int i=0; i<rows1; i++){
					for (int j=0; j<columns1; j++){		
						matr[j][i]=matr1[i][j];
					}
				}
			}
			else if(op== 'R') {
				if (columns1==rows1){
					k=1;
					matr=obrmat(rows1, matr1, matr);	
				}
				else cout << "An error has occured while reading input data";		
			}
		cout << endl;
		if (op == 'T') {
			for (int i=0; i<columns1; i++){
				for (int j=0; j<rows1; j++){
	                cout << matr[i][j] << ' ';
				}	
				cout << endl;
			}
		}
		else {
			if (k==1){
				for (int i=0; i<rows1; i++){
					for (int j=0; j<columns1; j++){
						cout << matr[i][j] << ' ';
					}
					cout << endl;
				}
			}
			else {
				cout << "An error has occured while reading input data";
			}
		}
		cin.get();
		return 0;
	}
