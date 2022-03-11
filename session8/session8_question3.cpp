#include <iostream>
#include <vector>
#include <climits>

int main()
{
    int count; // number of real number entered
    double average;
    double minimum;
    double maximum;
    std::vector<double> realNumbers;
    std::cout << "Enter number of real numbers: ";
    std::cin >> count;
    double temp_for_input;
    for (int i = 0; i < count; i++) {
        std::cout << "Enter real number: ";
        std::cin >> temp_for_input;
        realNumbers.push_back(temp_for_input);
    }
    average = 0;
    minimum = DBL_MAX;
    maximum = DBL_MIN;
    for (int i = 0; i < realNumbers.size(); i++) {
        average += realNumbers[i];
        if (realNumbers[i] > maximum) {
            maximum = realNumbers[i];
        }
        if (realNumbers[i] < minimum) {
            minimum = realNumbers[i];
        }
    }
    std::cout << "Average: " << average << "\n";
    std::cout << "Minimum: " << minimum << "\n";
    std::cout << "Maximum: " << maximum << "\n";
}