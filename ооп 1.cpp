#include <iostream>
#include <iomanip>
using namespace std;
void ShowMas(int** mas, int n, int m);
 void main(){
	setlocale(LC_ALL, "rus");
	int** mas;
	int n, m;
	cout << "Введите количесво строк и столбцов: ";
	cin >> n >> m;
	mas = new int* [n];
	for (int j = 0;j < n;j++)
		mas[j] = new int[m];
	cout << "Введите элементы массива"; 
	for (int i = 0; i < n;i++)
		for (int j = 0;j < m;j++)
			cin >> mas[i][j];
	
	ShowMas(mas, n, m);
	int temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				if ((mas[i][j] < mas[i][k]) && (mas[i][j] > 0))
				{
					temp = mas[i][k];
					mas[i][k] = mas[i][j];
					mas[i][j] = temp;
				}
			}
		}
	}
	ShowMas(mas, n, m);
	system("pause");
	
		delete[]mas;
}
void ShowMas(int** mas, int n, int m) {
	cout << "Двумерный массив: " << endl;
	for (int i = 0; i < n;i++) {
		cout << endl;
		for (int j = 0;j < m;j++)
			cout << setw(4) << mas[i][j];

	}
	cout << endl;
}