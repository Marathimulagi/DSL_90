#include <iostream>
using namespace std;

int main() {
    int A[2][2]={{1,2},{3,4}};
    int B[2][2]={{5,6},{7,8}};
    int c[2][2];
    int choice;

    cout << "\n--Matrix Operations Menu--";
    cout << "\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division";
    cout << "\nEnter your choice: ";
    cin >> choice;

    switch(choice) {

        case 1:
            cout << "Addition is:\n";
            for(int i=0;i<2;i++) {
                for(int j=0;j<2;j++) {
                    c[i][j] = A[i][j] + B[i][j];
                    cout << c[i][j] << " ";
                }
                cout << endl;
            }
            break;

        case 2:
            cout << "Subtraction is:\n";
            for(int i=0;i<2;i++) {
                for(int j=0;j<2;j++) {
                    c[i][j] = A[i][j] - B[i][j];
                    cout << c[i][j] << " ";
                }
                cout << endl;
            }
            break;

        case 3:
            cout << "Multiplication is:\n";
            for(int i=0;i<2;i++) {
                for(int j=0;j<2;j++) {
                    c[i][j] = A[i][j] * B[i][j]; // element-wise
                    cout << c[i][j] << " ";
                }
                cout << endl;
            }
            break;

        case 4:
            cout << "Division is:\n";
            for(int i=0;i<2;i++) {
                for(int j=0;j<2;j++) {
                    c[i][j] = A[i][j] / B[i][j];
                    cout << c[i][j] << " ";
                }
                cout << endl;
            }
            break;

        default:
            cout << "Invalid choice!";
    }

    return 0;
}
