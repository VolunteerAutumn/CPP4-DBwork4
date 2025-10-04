#include <iostream>
#include <windows.h>
using namespace std;

/// PART I
// task 1
int main()
{
	int var = 0;
	int minnum, maxnum, num;
	cout << "Enter the start and the end of a range separately >>> ";
	cin >> minnum >> maxnum;
	do
	{
		cout << "Please enter the number >>> ";
		cin >> num;
		if (num < maxnum && num > minnum) {
			var = 1;
		}
	} while (var == 0);

	cout << "Finally you realized the sequence.";
}

// task 2
int main() {
    srand(time(0));
    int totalRevenue = 0;

    int stockFireworks = 10, stockChampagne = 20, stockHats = 50, stockConfetti = 30, stockNoise = 40;
    int fireworksPack = 50, champagneBottle = 25, partyHats = 10, confettiCannon = 15, noisemakers = 12;

    bool storeOpen = true;
    while (storeOpen) {
        int DoTheyHaveADiscountCoupon = rand() % 101;
        int disc = 0;
        if (DoTheyHaveADiscountCoupon < 50) disc = rand() % 50;

        cout << "\nNew customer has arrived!\n";
        cout << "Available stock:\n";
        cout << "1. Fireworks Pack ($" << fireworksPack << ") - " << stockFireworks << " left\n";
        cout << "2. Champagne Bottle ($" << champagneBottle << ") - " << stockChampagne << " left\n";
        cout << "3. Party Hats ($" << partyHats << ") - " << stockHats << " left\n";
        cout << "4. Confetti Cannon ($" << confettiCannon << ") - " << stockConfetti << " left\n";
        cout << "5. Noisemakers ($" << noisemakers << ") - " << stockNoise << " left\n";
        cout << "0. Checkout\n";

        int sum = 0;
        while (true) {
            int prod, am;
            cout << "\nChoose product >>> ";
            cin >> prod;
            if (prod == 0) break;
            cout << "Enter amount >>> ";
            cin >> am;

            switch (prod) {
            case 1: if (am <= stockFireworks) { sum += fireworksPack * am; stockFireworks -= am; }
                  else cout << "Not enough stock!\n"; break;
            case 2: if (am <= stockChampagne) { sum += champagneBottle * am; stockChampagne -= am; }
                  else cout << "Not enough stock!\n"; break;
            case 3: if (am <= stockHats) { sum += partyHats * am; stockHats -= am; }
                  else cout << "Not enough stock!\n"; break;
            case 4: if (am <= stockConfetti) { sum += confettiCannon * am; stockConfetti -= am; }
                  else cout << "Not enough stock!\n"; break;
            case 5: if (am <= stockNoise) { sum += noisemakers * am; stockNoise -= am; }
                  else cout << "Not enough stock!\n"; break;
            default: cout << "Invalid choice\n"; break;
            }
            cout << "Current total: $" << sum << endl;
        }

        if (disc > 0) {
            int discountAmount = (sum * disc) / 100;
            sum -= discountAmount;
            cout << "Discount applied: " << disc << "%, you saved $" << discountAmount << endl;
        }

        cout << "Final bill: $" << sum << endl;
        totalRevenue += sum;
        cout << "Store revenue so far: $" << totalRevenue << endl;

        char again;
        cout << "Serve next customer? (y/n): ";
        cin >> again;
        if (again != 'y' && again != 'Y') storeOpen = false;
    }

    cout << "\nStore closed. Total revenue: $" << totalRevenue << endl;
}

/// PART II
