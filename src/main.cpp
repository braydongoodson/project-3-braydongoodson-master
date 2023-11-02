#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double feetPerMile = 5280.0;
const double landCostPerFoot = 7.0;
const double waterCostPerFoot = 9.0;

double computeDiag(double base, double height) {
    return sqrt((base * base) + (height * height));
}

double computeWaterCost(double length, double cost) {
    return length * cost * 5280;
}

double computeLandCost(double length, double cost) {
    return length * cost * 5280;
}

int main() {
    double factoryDistance, riverWidth, landCost, waterCost;

    cout << "Enter the distance downstream to the factory in miles: ";
    cin >> factoryDistance;
    cout << "Enter the width of the river in miles: ";
    cin >> riverWidth;
    cout << "Enter the dollar cost per foot to run power over land: ";
    cin >> landCost;
    cout << "Enter the dollar cost per foot to run the power under water: ";
    cin >> waterCost;

    double minTotalCost = 99999999999;
    double landLength = 0.0, waterLength = 0;

    for (double i = 0.00; i <= factoryDistance; i += 0.25) {
        double waterDistance = computeDiag(factoryDistance - i, riverWidth);
        double landDistance = i;

        double totalCost = computeLandCost(landDistance, landCost) + computeWaterCost(waterDistance, waterCost);

        if (totalCost < minTotalCost) {
            minTotalCost = totalCost;
            landLength = landDistance;
            waterLength = waterDistance;
        }
        cout << "Checking distance over water when land distance is " << fixed << setprecision(2) << landDistance << " miles..." << setprecision(2) << totalCost << endl;
    }
    cout << endl;

    cout << "The most cost-effective solution is:" << endl << endl << endl;
    cout << "Lay power line across land for " << fixed << setprecision(4) << landLength << " miles at a cost of $" << fixed << setprecision(2) << computeLandCost(landLength, landCostPerFoot) << endl;
    cout << "Lay power line under water for " << fixed << setprecision(4) << (waterLength) << " miles at a cost of $" << fixed << setprecision(2) << computeWaterCost(waterLength, waterCostPerFoot) << endl;
    cout << "The total cost = $" << fixed << setprecision(2) << minTotalCost << "." << endl;

    return 0;
}
