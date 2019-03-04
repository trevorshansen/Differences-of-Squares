#include <iostream>
#define NUMBER 100
using namespace std;

//Computes i^3 of 0 <= i >= 99
//Prints out computation
void cubes(int expo[]){
    for(int i = 0; i <  NUMBER; i++){
        expo[i] =  i*i*i;
        cout << expo[i] << "(" << i <<") ";
        if ((i + 1) % 3 == 0){
            cout << endl;
        };
    }
};

//Difference of (i + 1)^3 - i^3
void diffCubes(int expo[],int expoDiff[]){
    cout << endl << endl;
    cout << "Difference of (i + 1)^n - i^n"
         << "(i + 1)^3 - i^3" << endl
         << "= i^3 + 3i^2 + 3i + 1 - i^3" << endl
         << "= 3i^2 + 3i + 1" << endl << endl;

    for(int j = 0; j < NUMBER - 1; j++){
        expoDiff[j] = expo[j + 1] - expo[j];
        cout << expoDiff[j] << "(" << j + 1 << " - " << j <<") ";
        if ((j + 1) % 3 == 0){
            cout << endl;
        };
    }
    cout << endl;
};

//Computers difference of the difference of cubes
//(i + 2)^3 - (i + 1)^3 - ((i + 1)^3 - i^3)
//Prints out computation
void diffOfDiffCubes(int expoDiff[], int diffExpoDiff[]){
    cout << "Difference of the difference =" << endl
         << "(i + 2)^3 - (i + 1)^3 - ((i + 1)^3 - i^3)" << endl
         << "= (i + 2)^3 - 2(i + 1)^3 + i^3" << endl
         << "= i^3 + 6i^2 + 12i + 8 - 2(i^3 + 3i^2 + 3i + 1) + i^3" << endl
         << "= 6i - 6" << endl
         << "= 6(i - 1)" << endl << endl;

    for(int j = 0; j < NUMBER - 2; j++){
        diffExpoDiff[j] = expoDiff[j + 1] - expoDiff[j];
        cout << diffExpoDiff[j] << "(" << j + 2 << ") ";
        if ((j + 1) % 3 == 0){
            cout << endl;
        };
    }
};

//Will add all the digits up until a single digit number is achieved.
//i.e.: 27->10(2 + 7)->1(1 + 0)
//Prints out computation
void addDigits(int expoDiff[],int expoDiffDigitsAdded[]){
    cout << endl << endl;

    cout << "The digits of the Diff should add up to 7 or 1" << endl << endl;

    for(int j = 0; j < NUMBER - 1; j++){
        int holder = 0;
        for(int k = 0; k < 5; k++){
            holder += expoDiff[j] % 10;
            expoDiff[j] = expoDiff[j] / 10;
        }
        if (holder >= 10){
            int holder2 = 0;
            holder2 += holder % 10;
            holder /= 10;
            holder2 += holder % 10;
            holder = holder2;
            if (holder >= 10){
                int holder2 = 0;
                holder2 += holder % 10;
                holder /= 10;
                holder2 += holder % 10;
                holder = holder2;
            }
        }
        expoDiffDigitsAdded[j] =  holder;
        cout << expoDiffDigitsAdded[j] << "(" << j + 1 << ") ";
        if ((j + 1) % 3 == 0){
            cout << endl;
        };
    }
};


int main(){
    int expo[NUMBER];
    int expoDiff[NUMBER];
    int diffExpoDiff[NUMBER - 1];
    int expoDiffDigitsAdded[NUMBER];
    cubes(expo);
    diffCubes(expo,expoDiff);
    diffOfDiffCubes(expoDiff, diffExpoDiff);
    addDigits(expoDiff,expoDiffDigitsAdded);
return 0;
}
