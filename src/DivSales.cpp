#include "DivSales.h"
#include <iostream>
#include <cstdlib>

using namespace std;
double DivSales::totalCorporateSales = 0.0;

DivSales::DivSales(int numberOfPeriods){
    if (numberOfPeriods <=0){
        cerr << "invalid Number of Periods.\n";
        exit(1)
    }


    numPeriods = numberOfPeriods;
    sales = new double[numPeriods];

    for (int i = 0; i < numPeriods; i++) {
        sales[i] = 0.0;
    
    }
}

DivSales::~DivSales() {
    delete[] sales; 
}
DivSales::DivSales(const DivSales& other) {
    numPeriods = other.numPeriods;
    sales = new double[numPeriods];

    for (int i = 0; i < numPeriods; i++) {
        sales[i] = other.sales[i];
    }
}

DivSales& DivSales:: operator=(const DivSales& other) {
    if (this == &other) {
        return *this;
    }

    delete[] sales;

    numPeriods = other.numPeriods;
    sales = new double[numPeriods];

    for (int i = 0; i<numPeriods; i++) {
        sales[i] = other.sales[i];
    }
    return *this;
}

const double& DivSales:: operator[](int index) const {
    if (index < 0 || index >= numPeriods){
        cerr << "Index out of bounds.\n";
        exit(1);
    }
    return sales[index];
}

const double& DivSales:: operator[](int index) const {
    if (index < 0 || index >= numPeriods) {
        cerr << "Index out of bounds.\n";
        exit(1);
    }
    return sales[index];
}

int DivSales:: getNumPeriods() const {
    return numPeriods;
}

double DivSales::getDivisionTotal() const{
    double sum = 0.0;
    for (int i = 0; i < numPeriods; i++) {
        sum += sales[i];
    }
    return sum;
}

double DivSales:: getCorporateSales(){
    return totalCorporateSales;
}

void DivSales::resetCorporateSales() {
    totalCorporateSales = 0.0;
}

void DivSales::addDivisionToCorporateSales(double divTotal) {
    totalCorporateSales += divTotal;
}