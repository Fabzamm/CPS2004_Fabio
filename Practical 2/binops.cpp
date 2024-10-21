#include <iostream>
#include <fstream> 
#include <stdexcept>
#include <limits> // For std::numeric_limits

// Wherever you want to use the namespace, it will be included
using namespace std;

/*
struct binops {
    float opnd1;
    char op;
    float opnd2;
};
*/

class binops {
private:
    double opnd1;
    double opnd2;
    char op;

    // Private method to validate operator
    bool isValidOperator(char op) {
        return op == '+' || op == '-' || op == '*' || op == '/';
    }

public:
    // Getters
    double getOpnd1() const { return opnd1; }
    double getOpnd2() const { return opnd2; }
    char getOp() const { return op; }

    // Setters with validation
    void setOpnd1(double value) { opnd1 = value; }
    void setOpnd2(double value) { opnd2 = value; }

    void setOp(char value) {
        if (!isValidOperator(value)) {
            throw invalid_argument("Invalid operator. Please use one of {+, -, *, /}.");
        }
        op = value;
    }

    // Method to evaluate the expression
    double evaluate() const {
        switch (op) {
            case '+': return opnd1 + opnd2;
            case '-': return opnd1 - opnd2;
            case '*': return opnd1 * opnd2;
            case '/': 
                if (opnd2 == 0) {
                    throw domain_error("Division by zero.");
                }
                return opnd1 / opnd2;
            default: return 0; // This should not happen
        }
    }
};

int main(){
    const int MAX_BINOPS = 10; //Fixed size of the array
    binops* binopsArray = new binops[MAX_BINOPS]; // Allocate array on the heap
    int count = 0;

    cout << "Enter binary operations (opnd1 op opnd2):" << endl;

    while (count < MAX_BINOPS) {
        try {
            double op1, op2;
            char operation;

            cout << "Input: ";
            cin >> op1 >> operation >> op2;

            // Check for input failure
            if (cin.fail()) {
                cin.clear(); // Clear the error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
                throw invalid_argument("Invalid input. Please enter valid numbers and an operator.");
            }

            // Create a Binops object and set its values
            binopsArray[count].setOpnd1(op1);
            binopsArray[count].setOpnd2(op2);
            binopsArray[count].setOp(operation);

            count++;
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl; // Invalid operator
            continue;
        } catch (const domain_error& e) {
            cout << "Error: " << e.what() << endl; // Division by zero
            continue;
        } catch (...) {
            cout << "An unexpected error occurred." << endl;
            break;
        }
    }

    ofstream outFile("results.txt"); // Open a text file to write the results

    cout << "\nResults (also written to results.txt):" << endl;
    for (int i = 0; i < count; ++i) {
        try {
            double result = binopsArray[i].evaluate();
            string expression = to_string(binopsArray[i].getOpnd1()) + " " 
                                + binopsArray[i].getOp() + " " 
                                + to_string(binopsArray[i].getOpnd2());
            string resultString = expression + " → " + to_string(result);

            cout << resultString << endl; // Output to console
            outFile << resultString << endl; // Write to the file
        } catch (const domain_error& e) {
            cout << "Error evaluating expression: " << e.what() << endl;
            outFile << "Error evaluating expression: " << e.what() << endl; // Write error to file
        }
    }

    outFile.close(); // Close the file
    delete[] binopsArray; // Free the allocated memory
    return 0;
}