#include <iostream>
#include <stdexcept>
using namespace std;

class Calculator
{
private:
    long double firstNum;
    long double secondNum;
    char op;

    //Operations' Functions
    static long double add(const Calculator& obj)
    {
        return obj.firstNum + obj.secondNum;
    }
    static long double subtract(const Calculator& obj)
    {
        return obj.firstNum - obj.secondNum;
    }
    static long double multiply(const Calculator& obj)
    {
        return obj.firstNum * obj.secondNum;
    }
    static double divide(const Calculator& obj)
    {
        if(obj.secondNum == 0)
            throw runtime_error("Division by zero is not allowed");
        return obj.firstNum / obj.secondNum;
    }
public:
    //Constructor
    Calculator(long double f = 0, long double s = 0, char op = '+') {
        setFirstNum(f);
        setSecondNum(s);
        setOperation(op);
    }

    //Destructor
    ~Calculator() {}

    //Is the operation valid ?
    static bool isOpValid(char x){
        if (x == '+' || x == '-' || x == '*' || x == '/')
            return 1;
        else
            return 0;
    }

    //Setters
    void setFirstNum(long double a)
    {
        firstNum = a;
    }
    void setSecondNum(long double b)
    {
        secondNum = b;
    }
    void setOperation(char x)
    {
        if (isOpValid(x))
            op = x;
        else
            throw invalid_argument("Invalid operation: use +, -, *, /");
    }

    //Getters
    long double getFirstNum()const
    {
        return firstNum;
    }
    long double getSecondNum()const
    {
        return secondNum;
    }
    char getoperation()const
    {
        return op;
    }

    //Calculation
    static long double calculation(const Calculator& obj)
    {
        switch(obj.op)
        {
        case '+':
            return add(obj);
            break;
        case '-':
            return subtract(obj);
            break;
        case '*':
            return multiply(obj);
            break;
        case '/':
            return divide(obj);
            break;
        default:
            throw invalid_argument("Invalid operation: use +, -, *, /");
        }
    }
};
