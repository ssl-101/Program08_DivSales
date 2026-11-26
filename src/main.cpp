#include <iostream>
#include <fstream>
#include <iominip>
#include  "DivSales.h"

using namespace std;

int main() {
    const int NUM_DIVISIONS = 6;
    string filename;

    cout << "Enter sales filename ( quarterly.txt or monthly.txt)";
    cin >> filename;

    ifstream inFile(filename);
    if (!inFile) {
        cerr << "could not open" << filename << "\n";
        return 1;
    }

    int periods;
    if(!(inFile >> periods) || periods <= 0) {
        cerr << "Error period count in file\n";
        return 1;
    }

    DivSales divisions[NUM_DIVISIONS] = {
        DivSales(periods),
        DivSales(periods),
        DivSales(periods),
        DivSales(periods),
        DivSales(periods),
        DivSales(periods),
        };
    DivSales::resetCorporateSales();

    for (int d = 0; d < NUM_DIVISIONS; d++){
        for (int p = 0; p < periods; p++){
            if (!inFile >> divisions [d][p]) || divisions[d][p] <= 0.0{
                cerr << "Invalid sales value in file\n";
                return 1;
            }
        }
        divSales:: addDivisionToCorporateSales(division[d]. getDivisionTotal());
    }
    cout << fixed << setpercision(2);
    cout << "\nDivision ";
    for (int p = 0; p < periods; p++){
        cout << setw(12) << ("Period" + to_string(p + 1));
    }
    cout << setw(14) << "Total\n";

    for (int d = 0; d < NUM_DIVISIONS; d++){
        cout << "Div" << (d + 1) << "      ";
        for (int p = 0; p < periods; p++){
            cout << setw(12) << divisions[d][p];
        }
        cout << setw(14) << division[d].getDivisionTotal() << "\n";
    }

    cout << "\nCorporate Total:"
<< DivSales:: getCorporateSales() << "\n";
   
    return 0;
}