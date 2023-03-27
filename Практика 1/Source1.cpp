//Вариант 5 Захаров Андрей
#include<iostream>
#include<string>
using namespace std;

struct Date {
	unsigned short day;
	unsigned short month;
	unsigned short year;
};

struct culture {
	char name[20];
	char type[5];
	char square[40];
	char uroj[30];
	struct Date date;
};

void Line() {
	for (int i = 0; i < 96; i++) {
		cout << '-';
	}
	cout << endl;
}

int size(char* stroka) {
	int i = 0;
	while (stroka[i] != '\0') {
		i++;
	}
	return i;
}