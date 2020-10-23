#include <iostream>
#include <new>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;
class Array {
	int* mas;
	int n;
	int imax;
	int imin;
	
public:
	
	Array(int N);
	~Array();
 friend void change(Array&, Array&, int, int);
	void AddEl();
	void print();
	int funk1();
	int funk2();

};

Array::Array(int N) {
	n = N; 
	mas = new int [n];
}

Array::~Array() {
	delete[]mas;
}

void Array::print() {
	
	for (int i = 0; i < n;i++)
		cout<< setw(4)<< mas[i];
	cout << endl;
	//system("pause");
}
int Array::funk1() {
	int max = *mas;
	int imax = 0;
	for (int i = 0; i < n;i++)
		if (max < mas[i]) {
			max = mas[i];
			imax = i;
		}
	cout << "Максимальное число = " << max << endl;
	return imax;

}
int Array::funk2() {
	int min = *mas;
	int imin =0;
	for (int i = 0; i < n;i++)
		if (min > mas[i]) {
			min = mas[i];
			imin = i;
		}
	cout << "Минимальное число = " << min << endl;
	return  imin;

}
void change (Array& m1, Array& m2, int imax, int imin){
	
	int t;
	
	t = m1.mas[imax];
	m1.mas[imax] = m2.mas[imin];
	m2.mas[imin]= t;
	cout << "Первый массив: " << endl;
	m1.print();
	cout << "Второй массив: " << endl;
	m2.print();
	}
	
void Array::AddEl() {
		
		for (int i = 0; i < n; i++) {
			cin >> mas[i];
		}
	}



int main() {
	setlocale(LC_ALL, "rus");
	int n = 0, m = 0;
	cout << "Введите размер массивов : " << endl;
	cout << "N = ";
	cin >> n;
	Array m1(n);
	Array m2(n);
	cout << "Введите элементы массива 1: ";
	m1.AddEl();
	cout << "Введите элементы массива 2: " ;
	m2.AddEl();
	
	int imax=m1.funk1();

	
	int imin =	m2.funk2();

    change(m1, m2, imax, imin);

	system("pause");
	return 0;
}