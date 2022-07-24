#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <thread>
using namespace std;

//Declaring Functions
vector<vector<int>> makeMatrix(int n);
vector<vector<int>> MatrixMultiply(vector<vector<int>> A, vector<vector<int>> B, int n);

int main() {

    int n = 0;
    std::cout << "\nHello! Welcome to the matix multiplier we are going to genereate two NxN matrices and multiply them.\n";
    std::cout << "Enter the size of the NxN matices you want multuply: ";
    std::cin >> n;
    std::cout << "\n\n\nMatrix A is as follows:\n";

    int timeOne = clock();
    //Matrix A    std::cout << "\n\n\nThe results of A*B are as follows:\n";
    std::cout << "\nMatrix A: ";
    vector<vector<int>> matrixA = makeMatrix(n);

    //Matrix B
    std::cout << "\nMatrix B: ";  
    vector<vector<int>> matrixB = makeMatrix(n);

    //Multipilcation Time
    std::cout << "\nResult: ";  
    vector<vector<int>> Result = MatrixMultiply(matrixA, matrixB, n); 

    int timeTwo = clock();
    int totalTime = timeTwo - timeOne;
    std::cout << "\n\n\n\nThe total time taken in clock units was: " << totalTime << "\n";

    //Multithreading
    int next = 0;
    std::cout << "\n\nWe will now try multithreading this, please press enter yes(y) to continue: \n";
    std::cin >> next;


    return 0;
}


vector<vector<int>> makeMatrix(int n){

    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            
            //Go through every position and set value
            matrix[i][j] = (1 + (rand() % 10000));

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            std::cout << matrix[i][j] <<" ";
        }   
        std::cout<<endl;         
    }

    return matrix;
}

vector<vector<int>> MatrixMultiply(vector<vector<int>> A, vector<vector<int>> B, int n) {
    
    vector<vector<int>> matrixResult(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int sum =0;
            for(int k=0; k<n; k++){
                sum += (A[i][k] * B[k][j]);
            }
            matrixResult[i][j] = sum;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            std::cout << matrixResult[i][j] <<" ";
        }   
        std::cout<<endl;         
    }

    return matrixResult;
}