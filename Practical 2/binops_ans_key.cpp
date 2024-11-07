#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <limits>
#include <string>

using namespace std;

struct BinOp{
    double opnd1;
    char operation;
    double opnd2;
};

double evaluate(double o1, double o2, char op){
    double out = 0;

    switch(op){
        case '+': return o1 + o2;
        case '-': return o1 - o2;
        case '*': return o1 * o2;
        case '/': 
            if (o2 != 0) {
                return o1 / o2;
            }
            else{
                cout << "Cannot divide by 0" << endl;
                return 0;
            }
        default: 
            cout << "Invalid opeartor" << endl;
            return 0;

    return out;
    }
}

int main(int,char**){
    cout << "Binops\n\n";

    const int SIZE = 10;
    BinOp* binops = new BinOp[SIZE]; //Allocate 5 struct objects

    double opnd1, opnd2; //temp var
    int i;
    char op; //temp var
    char continueFlag = 'y'; // To track if user wants to continue
    //int ActSize = 0; //Keep track of the actual size of the array

    for(i = 0; i < SIZE; i++){
        try{
            cout << i +1 << "\nEnter first operand: ";
            if(!(cin >> opnd1)){
                throw invalid_argument("Invalid input. Please enter valid numbers and an operator.");
            }
            
            cout << "Enter second operand: ";
            if(!(cin >> opnd2)){
                throw invalid_argument("Invalid input. Please enter valid numbers and an operator.");
            }
            
            cout << "Enter operator (+, -, *, /): ";
            if(!(cin >> op)){
                throw invalid_argument("Invalid input. Please enter valid numbers and an operator.");
            }
            
            cout << "\n";

            //update input array
            binops[i].opnd1 = opnd1;
            binops[i].opnd2 = opnd2;
            binops[i].operation = op;

            //ActSize += 1;

            //validate last input <<<
        } catch(const invalid_argument& e){
            cout << "Error: " << e.what() << endl; // Invalid operator
            cin.clear(); // Clear the error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
            i--;
        }

        //add a prompt to continue or quit -- TAKE HOME EXERCISE 1)
        /*if(SIZE != i){
            cout << "Do you want to enter another operation? (y/n): ";
            cin >> continueFlag;
            if (continueFlag != 'y') {
                break;
            }
        }*/
       cin.ignore(numeric_limits<streamsize>::max(), '\n');
       string input_buf;
       cout << "Do you want to enter more expressions? Press y to continue or anything else to exit." << endl;
       getline(cin, input_buf);
       cout << "Debug" <<endl;
       if(!(input_buf[0] == 'y' || input_buf[0] == 'Y')) // condition is false 
       {
            i++;
            break;
       }
    }

    cout << "Your input follows:" << endl;
    for(int j = 0; j < i; j++){ //2) SIZE --> element count
        cout << "• " << binops[j].opnd1 << " " << binops[j].operation << " " << binops[j].opnd2 << " = " << evaluate(binops[j].opnd1, binops[j].opnd2, binops[j].operation) << endl;
    }

    //write text output to disk
    ofstream outFile("eval.txt");

    for(int j = 0; j <i; j++){ //3) SIZE --> element count
        outFile << binops[j].opnd1 << " " << binops[j].operation << " " << binops[j].opnd2 << " = " << evaluate(binops[j].opnd1, binops[j].opnd2, binops[j].operation) << endl;
    }

    outFile.close();

    // Free allocated memory
    delete[] binops;

    return 0;
}