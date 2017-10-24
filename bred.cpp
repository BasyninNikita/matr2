#include <iostream>
using namespace std;
float **matrix, **matrix1, **matrix2;
int rows1, rows2, columns1, columns2;
char op, k;
int main ()
{
	float ** matrix;
	cin >> rows1;
	op=cin.get();
	cin >> columns1;
	float ** matrix1 = new float *[ rows1 ];
	for( unsigned int i = 0; i < rows1; ++i ) {
    	matrix1[ i ] = new float[ columns1 ];
    	for( unsigned int j = 0; j < columns1; ++j ) {		
       	 matrix1[ i ][ j ] = 0.0f;
    	}
	}
	for (int i=0; i<rows1; i++) {
		for (int j=0; j<columns1; j++){		
			cin >> matrix1[i][j];
		}
	}
	cin >> op;
	if (op == 'T') {
		matrix = new float *[ columns1 ];
		for( unsigned int i = 0; i < columns1; ++i ) {
    		matrix[ i ] = new float[ rows1 ];
    		for( unsigned int j = 0; j < rows1; ++j ) {	
       	 		matrix[ i ][ j ] = 0.0f;
    		}
		}
	}
	else {
		matrix = new float *[ rows1 ];
		for( unsigned int i = 0; i < rows1; ++i ) {
    		matrix[ i ] = new float[ columns1 ];
    		for( unsigned int j = 0; j < columns1; ++j ) {		
       	 		matrix[ i ][ j ] = 0.0f;
    		}
		}
	}
	switch (op){
		case '+': {
			cin >> rows2;
			op=cin.get();
			cin >> columns2;
			float ** matrix2 = new float *[ rows2 ];
			for( unsigned int i = 0; i < rows2; ++i ) {
    			matrix2[ i ] = new float[ columns2 ];
    			for( unsigned int j = 0; j < columns2; ++j ) {
       	 			matrix[ i ][ j ] = 0.0f;
    			}
			}
			for (int i=0; i<rows2; i++) {
				for (int j=0; j<columns2; j++){
					cin >> matrix2[i][j];
				}
			}
			if (rows1 == rows2 && columns1 == columns2){
				k=1;
				for (int i = 0; i<rows1; i++){
	 				for (int j = 0; j<columns1; j++){		
	 		  			matrix[i][j] = matrix1[i][j]+matrix2[i][j];
					}
				}
			}
			else cout << "An error has occured while reading input data";	
			break;
		}
		case '-': {
			cin >> rows2;
			op=cin.get();
			cin >> columns2;
			float ** matrix2 = new float *[ rows2 ];
			for( unsigned int i = 0; i < rows2; ++i ) {
    			matrix2[ i ] = new float[ columns2 ];
    			for( unsigned int j = 0; j < columns2; ++j ) {
       	 			matrix[ i ][ j ] = 0.0f;
    			}
			}
			for (int i=0; i<rows2; i++) {
				for (int j=0; j<columns2; j++){
					cin >> matrix2[i][j];
				}
			}
			if (rows1 == rows2 && columns1 == columns2){
				k=1;
				for (int i = 0; i<rows1; i++){
	 				for (int j = 0; j<columns1; j++){		
	 		  			matrix[i][j] = matrix1[i][j]-matrix2[i][j];
					}
				}
			}
			else cout << "An error has occured while reading input data";	
			break;
		}
		case '*': {
			cin >> rows2;
			op=cin.get();
			cin >> columns2;
			float ** matrix2 = new float *[ rows2 ];
			for( unsigned int i = 0; i < rows2; ++i ) {
    			matrix2[ i ] = new float[ columns2 ];
    			for( unsigned int j = 0; j < columns2; ++j ) {
       	 			matrix[ i ][ j ] = 0.0f;
    			}
			}
			for (int i=0; i<rows2; i++) {
				for (int j=0; j<columns2; j++){
					cin >> matrix2[i][j];
				}
			}
			if (columns1 == rows2) {
				for( int i = 0; i < rows1; ++i ){
    				for( int j = 0; j < columns1; ++j ){
      		  			int result = 0;
      		   			for( int k = 0; k < columns1; ++k ){	
       			 			result += matrix1[i][k] * matrix2[k][j];
      		   			}		
      		  			matrix[i][j] = result;
    		 		}
  				}
	 			std::cout << std::endl;	
	 			k=1;
			}
			else cout << "An error has occured while reading input data";	
	 		break;
		}
		case 'T': {
			for (int i=0; i<rows1; i++){
				k=1;
				for (int j=0; j<columns1; j++){		
					matrix[j][i]=matrix1[i][j];
				}
			}	
			break;
		}
		//float** gaus_obr(int cnt_str, float **mass, float **M_obr) {matrix=gaus_obr(rows1, matrix1, matrix);
		case 'R': {
			if (columns1==rows1){
			k=1;	
			int i, j, k;
	        matrix=new float* [rows1];
	        for(i=0; i<rows1; i++) {
		    matrix[i]=new float [rows1];
		    for(j=0; j<rows1; j++) matrix[i][j]=0;	
		    matrix[i][i]=1; 
	        }
	        double a, b;
	        for(i=0; i<rows1; i++) {
		    a=matrix1[i][i];
		    for(j=i+1; j<rows1; j++) {
			    b=matrix1[j][i];
			    for(k=0; k<rows1; k++) {
				    matrix1[j][k]=matrix1[i][k]*b-matrix1[j][k]*a;			
				    matrix[j][k]=matrix[i][k]*b-matrix[j][k]*a; 
			    } 
		    } 
	    }
	    double sum;
	    for(i=0; i<rows1; i++) {
		    for(j=rows1-1; j>=0; j--) {
			    sum=0;
			    for(k=rows1-1;k>j;k--){
				    sum+=matrix1[j][k]*matrix[k][i];
				    if(matrix1[j][j]==0) {
					    for(i=0;i<rows1;i++){
						    delete []matrix[i];
						    delete []matrix;		
						    return 0; 
					    }
				    }
			    }	
		    matrix[j][i]=(matrix[j][i]-sum)/matrix1[j][j]; 
		    } 
	    }	
	    
}	

			else cout << "An error has occured while reading input data";		
			break;
		}
	}
	cout << endl;
	if (op == 'T') {
		for (int i=0; i<columns1; i++){
			for (int j=0; j<rows1; j++){
				cout << matrix[i][j] << ' ';
			}	
			cout << endl;
		}
	}
	else {
		if (k==1){
			for (int i=0; i<rows1; i++){
				for (int j=0; j<columns1; j++){
					cout << matrix[i][j] << ' ';
				}
				cout << endl;
			}
		}	
	}	
	cin.get();
	return 0;
}
