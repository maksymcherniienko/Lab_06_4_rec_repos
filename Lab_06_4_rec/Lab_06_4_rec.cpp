#include<iostream>
#include<iomanip>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
}

int Find(int* a, const int size, int i, int max, int maxindex)
{
	if (i >= size) {
		return maxindex;
	}
	if (a[i] > max) { 
		max = a[i];
		maxindex = i;
	}
	return Find(a, size, i + 1, max, maxindex);
}

int Calculate(int* a, int size, int i, int first, int product)
{
	if (i >= size) {
		return 1; // досягнуто кінця масиву, повертаємо 1.
	}

	if (a[i] == 0) {
		if (first == -1) {
			// перший нульовий елемент
			return Calculate(a, size, i + 1, i, product);
		}
		else {
			// другий нульовий елемент
			int second = i;
			if (first != second - 1) {
				// Є елементи між двома нульовими
				product = 1;
				for (int i = first + 1; i < second; i++) {
					product *= a[i];
				}
				return product;

			}
			if (first == second - 1) {
				product = 0;
			}
			return product;
		}
		return 0;
	}

	return Calculate(a, size, i + 1, first, product);
}

void ModifyMas(int* a, int* result, const int size, int currentIndex, int evenIndex, int oddIndex)
{
	if (currentIndex >= size) {
		for (int i = 0; i < size; i++) {
			a[i] = result[i];
		}
		return;
	}
	if (currentIndex % 2 != 0) {
		result[evenIndex] = a[currentIndex];
		evenIndex++;
	}
	else {
		result[oddIndex] = a[currentIndex];
		oddIndex++;
	}

	ModifyMas(a, result, size, currentIndex + 1, evenIndex, oddIndex);
}

void ModifyMas(int* a, const int size)
{
	int* result = new int[size];
	ModifyMas(a, result, size, 0, 0, size / 2);
	delete[] result;
}


int main()
{
	srand((unsigned)time(NULL));
	int n1;
	cout << "n = "; cin >> n1;
	const int n = n1;
	int* a = new int[n];    // виділення пам'яті для масиву
	int Low = 0;
	int High = 7;
	Create(a, n, Low, High, 0);
	cout << "mas =          ["; Print(a, n, 0);
	cout << "  ]" << endl;
	cout << "Index of the max: [" << Find(a, n, 0, -1, -1) << "]" << endl;
	cout << "0 .... 0 = " << Calculate(a, n, 0, -1, -1) << endl;
	ModifyMas(a, n);
	cout << "modifyed mas = ["; Print(a, n, 0);cout << "  ]";
	return 0;
}