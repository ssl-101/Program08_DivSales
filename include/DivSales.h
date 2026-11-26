#ifndef DIVSALES_H
#define DIVSALES_h

class DivSales {
private:
   double* sales;
   int numPeriods;
   static double totalCorporateSales;

public:
   DivSales(int numberOfPeriods);
   ~DivSales();
   DivSales(const DivSales& other);
   DivSales& operator=(const DivSales& other);

   double& operator[](int index);
   const double& operator[](int index) const;

   int getNumPeriods() const;
   double getDivisionTotal() const;

   static double getCorporateSales();
   static void resetCorporateSales();
   static void addDivisionToCorporateSales(double divTotal);

};

#endif