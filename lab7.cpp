#include <iostream>
using namespace std;

int main(void) {
    int choice;

    cout << "1 - Collatz's hypothesis" << endl;
    cout << "2 - Value of Pi (Leibniz formula)" << endl;
    cout << "3 - Drawing squares" << endl;
    cout << "Choose a task: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        // Lab 2.3.1: Collatz's hypothesis
        long long c0;
        int steps = 0;

        cout << "Enter a natural number: ";
        cin >> c0;

        if (!cin || c0 <= 0) {
            cout << "The number must be a positive integer" << endl;
            break;
        }

        while (c0 != 1) {
            if (c0 % 2 == 0)
                c0 = c0 / 2;
            else
                c0 = 3 * c0 + 1;
            cout << c0 << endl;
            steps++;
        }
        cout << "steps = " << steps << endl;
        break;
    }
    case 2: {
        // Lab 2.3.2: Some actual evaluations – finding the value of ?
        double pi4 = 0.;
        double sign = 1.;
        long n;

        cout << "Number of iterations? ";
        cin >> n;

        if (!cin || n <= 0) {
            cout << "The number of iterations must be positive" << endl;
            break;
        }

        for (long i = 0; i < n; i++) {
            pi4 += sign / (2. * i + 1.);
            sign = -sign;
        }

        cout.precision(20);
        cout << "Pi = " << (pi4 * 4.) << endl;
        break;
    }
    case 3: {
        // Lab 2.3.5: Drawing squares (actually: rectangles)
        const int MAX_SIDE = 40;   
        int n;

        cout << "Enter the side size (2-" << MAX_SIDE << "): ";
        cin >> n;

        if (!cin) {
            cout << "Sorry, this is not a valid number" << endl;
            break;
        }
        if (n < 2) {
            cout << "Sorry, the side size is too small" << endl;
            break;
        }
        if (n > MAX_SIDE) {
            cout << "Sorry, the side size is too big" << endl;
            break;
        }

        cout << '+';
        for (int i = 0; i < n - 2; i++)
            cout << '-';
        cout << '+' << endl;

        for (int i = 0; i < n - 2; i++) {
            cout << '|';
            for (int j = 0; j < n - 2; j++)
                cout << ' ';
            cout << '|' << endl;
        }

        cout << '+';
        for (int i = 0; i < n - 2; i++)
            cout << '-';
        cout << '+' << endl;
        break;
    }
    default:
        cout << "There is no such task" << endl;
    }

    return 0;
}