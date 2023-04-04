//Вариант 5 Захаров Андрей
#include<iostream>
#include<string>
using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

void get_date(Date* A, int i) {
	if (A[i].day < 9) {
		cout<< '0';
		cout<< A[i].day;
	}
	else {
		cout<< A[i].day / 10;
		cout<< A[i].day % 10;
	}
	cout<< '.';
	if (A[i].month < 9) {
		cout<< '0';
		cout<< A[i].month;
	}
	else {
		cout<< A[i].month / 10;
		cout<< A[i].month % 10;
	}
	cout<< '.';
	cout<< A[i].year / 1000;
	cout<< A[i].year / 100 % 10;
	cout<< A[i].year % 100 / 10;
	cout<< A[i].year % 10;
}

void vivod(Date* a, Date * b) {
	for (int i = 0; i < 10; i++) {
		cout << "Адрес A[i]: " << &a[i] << " " << "Значение A[i]->"; get_date(a, i); cout << " Адрес B[i]: " << &b[i] << " " << "Значение B[i]->"; get_date(b, i); cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	Date date[3];
	date[0] = { 3,3,2022 };
	date[1] = { 3,4,2022 };
	date[2] = { 4,3,2022 };

	Date* A;
	A = (Date*)calloc(3, sizeof(Date));

	for (int i = 0; i < 3; i++) {
		A[i].day = date[i].day;
		A[i].month = date[i].month;
		A[i].year = date[i].year;
	}
	A = (Date*)realloc(A, 10 * sizeof(Date));

	Date* B = new Date[10];

	for (int i = 0; i < 10; i++){
		B[i].day = A[i].day;
		B[i].month = A[i].month;
		B[i].year = A[i].year;
	}

	vivod(A, B);



	return 0;
}