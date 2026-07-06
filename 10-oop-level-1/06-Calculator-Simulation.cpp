#include <iostream>
using namespace std;

class clCalculator {

    float _LastNum = 0;
    float _Result = 0;
    float _PreviousResult = 0;
    string _LastOperation = "Clear";

    bool _IsZero(float Num) {
        return (Num == 0);
    }

public:

    void Add(float Num) {
        _LastNum = Num;
        _PreviousResult = _Result;
        _LastOperation = "Adding";
        _Result += Num;
    }

    void Subtract(float Num) {
        _LastNum = Num;
        _PreviousResult = _Result;
        _LastOperation = "Subtracting";
        _Result -= Num;
    }

    void Divide(float Num) {
        _LastNum = Num;
        if (_IsZero(Num)) {
            Num = 1;
            _LastNum = 1;
        }
        _PreviousResult = _Result;
        _LastOperation = "Dividing";
        _Result /= Num;
    }

    void Multiply(float Num) {
        _LastNum = Num;
        _PreviousResult = _Result;
        _LastOperation = "Multiplying";
        _Result *= Num;
    }

    void Clear() {
        _LastNum = 0;
        _Result = 0;
        _PreviousResult = 0;
        _LastOperation = "clear";
    }

    void CancelLastOperation() {
        _Result = _PreviousResult ;
        _LastNum = 0;
        _LastOperation = "Cancelling Last Operation";
    }

    void PrintResult() {
        cout << "Result After " << _LastOperation << " is: " << _Result << "\n";
    }
};

int main() {
    clCalculator Calculator;

    Calculator.Add(10);
    Calculator.PrintResult();

    Calculator.Add(100);
    Calculator.PrintResult();

    Calculator.Divide(0);
    Calculator.PrintResult();

    Calculator.Divide(2);
    Calculator.PrintResult();

    Calculator.Multiply(3);
    Calculator.PrintResult();

    Calculator.CancelLastOperation();
    Calculator.PrintResult();

    Calculator.Clear();
    Calculator.PrintResult();
}
