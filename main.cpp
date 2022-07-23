#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//Declaring Functions


int main() {

    std::cout << "\nHello! Welcome to the matix multiplier we are going to genereate two NxN matrices and multiply them.\n";
    int n = 0;
    std::cout << "Enter the size of the NxN matices you want multuply: ";
    std::cin >> n;

    std::cout << "\n\n\nMatrix A is as follows:\n";

    //Matrix A
    vector<vector<int>> matrixA(n, vector<int>(n));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            
            //Go through every position and set value
            matrixA[i][j] = (1 + (rand() % 10000));

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            std::cout << matrixA[i][j] <<" ";
        }   
        std::cout<<endl;         
    }

    std::cout << "\n\n\nMatrix B is as follows:\n";

    //Matrix B
    vector<vector<int>> matrixB(n, vector<int>(n));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){

            //Go through every position and set value
            matrixB[i][j] = 1 + (rand() % 10000);
        
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            std::cout << matrixB[i][j] <<" ";
        } 
        std::cout<<endl;     
    }

    //Multipilcation Time\

    

    vector<vector<int>> matrixResult(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            int sum =0;
            for(int k=0; k<n; k++){
                sum += (matrixA[i][k] * matrixB[k][j]);
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


    return 0;
}

