#include <iostream>
using namespace std;
float **matr, **matr1, **matr2;
int rows1, rows2, columns1, columns2;
char op, k;
int main ()
{
	float ** matr;
	cin >> rows1;
	op=cin.get();
	cin >> columns1;
	float ** matr1 = new float *[ rows1 ];
	for( unsigned int i = 0; i < rows1; ++i ) {
    	matr1[ i ] = new float[ columns1 ];
    	for( unsigned int j = 0; j < columns1; ++j ) {		
       	 matr1[ i ][ j ] = 0.0f;
    	}
	}
	for (int i=0; i<rows1; i++) {
		for (int j=0; j<columns1; j++){		
			cin >> matr1[i][j];
		}
	}
	cin >> op;
	if (op == 'T') {
		matr = new float *[ columns1 ];
		for( unsigned int i = 0; i < columns1; ++i ) {
    		matr[ i ] = new float[ rows1 ];
    		for( unsigned int j = 0; j < rows1; ++j ) {	
       	 		matr[ i ][ j ] = 0.0f;
    		}
		}
	}
	else {
		matr = new float *[ rows1 ];
		for( unsigned int i = 0; i < rows1; ++i ) {
    		matr[ i ] = new float[ columns1 ];
    		for( unsigned int j = 0; j < columns1; ++j ) {		
       	 		matr[ i ][ j ] = 0.0f;
    		}
		}
	}
	if(op=='+'){
			cin >> rows2;
			op=cin.get();
			cin >> columns2;
			float ** matr2 = new float *[ rows2 ];
			for( unsigned int i = 0; i < rows2; ++i ) {
    			matr2[ i ] = new float[ columns2 ];
    			for( unsigned int j = 0; j < columns2; ++j ) {
       	 			matr[ i ][ j ] = 0.0f;
    			}
			}
			for (int i=0; i<rows2; i++) {
				for (int j=0; j<columns2; j++){
					cin >> matr2[i][j];
				}
			}
			if (rows1 == rows2 && columns1 == columns2){
				k=1;
				for (int i = 0; i<rows1; i++){
	 				for (int j = 0; j<columns1; j++){		
	 		  			matr[i][j] = matr1[i][j]+matr2[i][j];
					}
				}
			}
			else cout << "An error has occured while reading input data";	
		}
	else if(op=='-')
	{
			cin >> rows2;
			op=cin.get();
			cin >> columns2;
			float ** matr2 = new float *[ rows2 ];
			for( unsigned int i = 0; i < rows2; ++i ) {
    			matr2[ i ] = new float[ columns2 ];
    			for( unsigned int j = 0; j < columns2; ++j ) {
       	 			matr[ i ][ j ] = 0.0f;
    			}
			}
			for (int i=0; i<rows2; i++) {
				for (int j=0; j<columns2; j++){
					cin >> matr2[i][j];
				}
			}
			if (rows1 == rows2 && columns1 == columns2){
				k=1;
				for (int i = 0; i<rows1; i++){
	 				for (int j = 0; j<columns1; j++){		
	 		  			matr[i][j] = matr1[i][j]-matr2[i][j];
					}
				}
			}
			else cout << "An error has occured while reading input data";	
		}
		else if(op== '*') {
			cin >> rows2;
			op=cin.get();
			cin >> columns2;
			float ** matr2 = new float *[ rows2 ];
			for( unsigned int i = 0; i < rows2; ++i ) {
    			matr2[ i ] = new float[ columns2 ];
    			for( unsigned int j = 0; j < columns2; ++j ) {
       	 			matr[ i ][ j ] = 0.0f;
    			}
			}
			for (int i=0; i<rows2; i++) {
				for (int j=0; j<columns2; j++){
					cin >> matr2[i][j];
				}
			}
			if (columns1 == rows2) {
				for( int i = 0; i < rows1; ++i ){
    				for( int j = 0; j < columns1; ++j ){
      		  			int result = 0;
      		   			for( int k = 0; k < columns1; ++k ){	
       			 			result += matr1[i][k] * matr2[k][j];
      		   			}		
      		  			matr[i][j] = result;
    		 		}
  				}
	 			cout << endl;	
	 			k=1;
			}
			else cout << "An error has occured while reading input data";
		}
		else if(op=='T') {
			for (int i=0; i<rows1; i++){
				k=1;
				for (int j=0; j<columns1; j++){		
					matr[j][i]=matr1[i][j];
				}
			}
		}
		else if(op=='R') {
			if (columns1==rows1){
			k=1;	
			int i, j, k;
	        matr=new float* [rows1];
	        for(i=0; i<rows1; i++) {
		    matr[i]=new float [rows1];
		    for(j=0; j<rows1; j++) matr[i][j]=0;	
		    matr[i][i]=1; 
	        }
	        double a, b;
	        for(i=0; i<rows1; i++) {
		    a=matr1[i][i];
		    for(j=i+1; j<rows1; j++) {
			    b=matr1[j][i];
			    for(k=0; k<rows1; k++) {
				    matr1[j][k]=matr1[i][k]*b-matr1[j][k]*a;			
				    matrix[j][k]=matrix[i][k]*b-matrix[j][k]*a; 
			    } 
		    } 
	    }
	    double sum;
	    for(i=0; i<rows1; i++) {
		    for(j=rows1-1; j>=0; j--) {
			    sum=0;
			    for(k=rows1-1;k>j;k--){
				    sum+=matr1[j][k]*matr[k][i];
				    if(matr1[j][j]==0) {
					    for(i=0;i<rows1;i++){
						    delete []matr[i];
						    delete []matr;		
						    return 0; 
					    }
				    }
			    }	
		    matr[j][i]=(matr[j][i]-sum)/matr1[j][j]; 
		    } 
	    }	
	    
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
	}	
	cin.get();
	return 0;
}
