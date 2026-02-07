#include <iostream>
#include <cstdlib>

//this is 10‰~ for campanys.
//Hello World!

void SwapXor(int &x, int &y) {
	int temp = x;
	x ^= y;
	x ^= temp;
	y ^= x;
	y ^= temp;
}

void SwapPtr(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void SwapRef(int &x, int &y) {
	int temp = x;
	x = y;
	y = temp;
}

template<typename T>
void SwapTemplate(T &x, T &y) {
	T temp = x;
	x = y;
	y = temp;
}

void ShowABCD(int A, int B, int C, int D) {
	std::cout << "A: " << A << ", B: " << B << ", C: " << C << ", D: " << D << std::endl;
}

void ShowABCDRnd(int *A, int *B, int *C, int *D) {
	*A = rand() % 100;
	*B = rand() % 100;
	*C = rand() % 100;
	*D = rand() % 100;
}

void shuffle(int* ptr[], int size){
	for (int i = 0; i < size; i++) {
		int r = rand() % size;
		SwapPtr(ptr[i], ptr[r]);
	}
}

void sort(int* ptr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (*ptr[j] > *ptr[j + 1]) {
				SwapPtr(ptr[j], ptr[j + 1]);
			}
		}
	}
}


int main() {
	//srand((unsigned int)time(NULL));
	srand(0); // For consistent testing
	int  A, B, C, D;
	std::cout << "Input four value." << std::endl;
	std::cout << "And Random?" << std::endl;
	int W = 0;
	std::cin >> W;
	if (W) {
		ShowABCDRnd(&A, &B, &C, &D);
	}
	else
	{
		std::cin >> A >> B >> C >> D;
	}

	ShowABCD(A, B, C, D);

	int* ptr[] = { &A, &B, &C, &D };

	std::cout << "Input two value." << std::endl;
	int x, y;
	std::cin >> x >> y;
	if (x > 3 || y > 3 || x < 0 || y < 0) {
		std::cout << "Index out of range." << std::endl;
		return 1;
	}

	SwapXor(*ptr[x], *ptr[y]);
	ShowABCD(A, B, C, D);

	std::cout << std::endl;

	shuffle(ptr, 4);
	ShowABCD(A, B, C, D);
	sort(ptr, 4);
	ShowABCD(A, B, C, D);


	return 0;

}