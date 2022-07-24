#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <thread>

using namespace std;

const int NUM_THREADS = 8; 

//Declaring Functions
vector<vector<int>> makeMatrix(int n);
vector<vector<int>> MatrixMultiply(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> Result, int n);
vector<vector<int>> MatrixMultiplyThreadedStriped(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> Result, int n, int threadIndex);
vector<vector<int>> MatrixMultiplyThreadedChunked(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> Result, int n, int threadIndex);

int main() {

    int n = 0;
    std::cout << "\nHello! Welcome to the matix multiplier we are going to genereate two NxN matrices and multiply them.\n";
    std::cout << "Enter the size of the NxN matices you want multuply: ";
    std::cin >> n;

    std::cout << "\nGenerating Matricies: \n";
    //std::cout << "\n\n\nMatrix A is as follows:\n";
    //Matrix A    std::cout << "\n\n\nThe results of A*B are as follows:\n";
    //std::cout << "\nMatrix A: \n";
    vector<vector<int>> matrixA = makeMatrix(n);
    //Matrix B
    //std::cout << "\nMatrix B: \n";  
    vector<vector<int>> matrixB = makeMatrix(n);

    vector<vector<int>> matrixResult(n, vector<int>(n));

    //Multipilcation Time
    //std::cout << "\nResult: \n";
    std::cout << "\nMultiplying Matricies: \n";
    int timeOne = clock();    
    vector<vector<int>> Result = MatrixMultiply(matrixA, matrixB, matrixResult, n); 

    int timeTwo = clock();
    int totalTime = (timeTwo - timeOne) *1000 / CLOCKS_PER_SEC;
    std::cout << "\n\n\n\nThe total time taken in ms was: " << totalTime << "\n";

    //Multithreading
    int next = 0;
    std::cout << "\n\nWe will now try multithreading this, please press enter yes(y) to continue: \n";
    std::cin >> next;

    vector<thread> threadVector = {};
    timeOne = clock(); 
    //opening threads
    for(int i = 0; i < NUM_THREADS; ++i){
        threadVector.push_back(std::thread(MatrixMultiplyThreadedStriped, matrixA, matrixB, matrixResult, n, i));
    }

    for(int i = 0; i < NUM_THREADS; ++i){
        threadVector[i].join(); 
    }

    //wait for all threads

    timeTwo = clock();
    totalTime = (timeTwo - timeOne) *1000 / CLOCKS_PER_SEC;
    std::cout << "\n\n\n\nThe total time taken in ms was using striped: " << totalTime << "\n";

    //empty thread vector
    threadVector.clear();

    timeOne = clock(); 
    for(int i = 0; i < NUM_THREADS; ++i){
        threadVector.push_back(std::thread(MatrixMultiplyThreadedStriped, matrixA, matrixB, matrixResult, n, i));
    }

    for(int i = 0; i < NUM_THREADS; ++i){
        threadVector[i].join(); 
    }

    timeTwo = clock();
    totalTime = (timeTwo - timeOne) *1000 / CLOCKS_PER_SEC;
    std::cout << "\n\n\n\nThe total time taken in ms was using chunks: " << totalTime << "\n";

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

    /*
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            std::cout << matrix[i][j] <<" ";
        }   
        std::cout<<endl;         
    }
    */

    return matrix;
}

vector<vector<int>> MatrixMultiply(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> Result, int n) {

    for(int i=0; i < n; ++i){
        for(int j=0; j < n; ++j){

            for(int k=0; k < n; ++k){
                Result[i][j] += (A[i][k] * B[k][j]);
            }

        }
    }

    return Result;
}

vector<vector<int>> MatrixMultiplyThreadedStriped(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> Result, int n, int threadIndex) {

    for(int i=threadIndex; i < n; i += NUM_THREADS){
        for(int j=0; j<n; ++j){
        
            for(int k=0; k<n; ++k){
                Result[i][j] += (A[i][k] * B[k][j]);
            }
            
        }
    }

    return Result;
}

vector<vector<int>> MatrixMultiplyThreadedChunked(vector<vector<int>> A, vector<vector<int>> B, vector<vector<int>> Result, int n, int threadIndex) {
    
    int chunkSize = n / NUM_THREADS;
    int chunkStart = chunkSize * threadIndex;
    int chunkEnd = chunkStart + chunkSize;

    for(int i=chunkStart; i < chunkEnd; ++i){
        for(int j=0; j<n; ++j){
            for(int k=0; k<n; ++k){
                Result[i][j] += (A[i][k] * B[k][j]);
            }

        }
    }

    return Result;
}