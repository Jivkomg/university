#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double a, b, c, root1, root2, imaginary;
    cout << "a: ";
    cin >> a;

    cout << "b: ";
    cin >> b;

    cout << "c: ";
    cin >> c;
    cout << "Finding the root of the equation a * x^2 + b * x + c = 0\n";

    if(a == 0){
        cout << "This is not a quadratic equation!" << endl;
        return 1;
    }

    double discriminant = a * a - 4 * b * c;

    if (discriminant > 0)
	 {
		  root1 = (-b + sqrt(discriminant)) / (2 * a);
		  root2 = (-b - sqrt(discriminant)) / (2 * a);

		  cout << "Two distinct and real roots exist: " << root1 << " and " << root2 << endl;
	 }
	 else if (discriminant == 0)
	 {
		  root1 = root2 = -b / (2 * a);

		  cout << "Two equal and real roots exist: " << root1 << " and " << root2 << endl;
	 }
	 else if (discriminant < 0)
	 {
		  root1 = root2 = -b / (2 * a);
		  imaginary = sqrt(-discriminant) / (2 * a);

		  cout << "Two distinct complex roots exist: " << root1 << "+" << imaginary << "i and " << root2 << "-" << imaginary << "i\n";
	 }
    return 0;
}

