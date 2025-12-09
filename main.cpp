#include <Calculator.h>

int main()
{
    cout << "====================== This is my simple calculator ======================\n";
    //try and catch To handle the exceptions
    try
    {
        Calculator obj;
        long double x, y;
        char op;
        cout << "Enter the first number : ";
        cin >> x;
        //To handle if x is not a number and enter it again
        while (cin.fail())
        {
            try
            {
                throw runtime_error("Not a number!");
            }
            catch(const runtime_error& e)
            {
                cerr << "Error: " << e.what() << "\n\n";
                //clear the stream and the buffer
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter a valid first number : ";
                cin >> x;
            }
        }
        obj.setFirstNum(x);

        cout << "\n=====================\n\n";

        //End of first number input

        cout << "Enter the operation : ";
        cin >> op;
        auto isOpValid = Calculator::isOpValid;
        while (!isOpValid(op))
        {
            try
            {
                obj.setOperation(op);
            }
            catch(const exception& e)
            {
                cerr << "Error: " << e.what() << "\n\n";
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter a valid operation : ";
                cin >> op;
            }
        }
        obj.setOperation(op);

        cout << "\n=====================\n\n";

        //End of operation input

        cout << "Enter the second number : ";
        cin >> y;
        while (cin.fail())
        {
            try
            {
                throw runtime_error("Not a number!");
            }
            catch(const runtime_error& e)
            {
                cerr << "Error: " << e.what() << "\n\n";
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Enter a valid second number : ";
                cin >> y;
            }
        }
        obj.setSecondNum(y);

        cout << "\n=====================\n\n";

        //End of second number input

        cout << "The Result : ";
        auto calculation = Calculator::calculation;
        cout << calculation(obj);
        cout << endl << endl;
        //Calculate the result

    }
    catch (const exception& e)
    {
        cerr << "Error: " << e.what() << "\n\n";
    }

    return 0;
}
