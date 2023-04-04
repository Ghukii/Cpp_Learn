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
	for (int i = 0; i < 138; i++) {
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

char* space(int n) {
	char* str = new char[n];
	for (int i = 0; i < n; i++) {
		str[i] = ' ';
	}
	str[n] = '\0';
	return str;
}

void print_centr(string stroka, int line_width) {
	int delta = (line_width - size(stroka)) / 2 - 1;
	cout << '|' << space(delta) << stroka << space(delta);
}

void print_date(unsigned short day, unsigned short month, unsigned short year, int line_size) {
	cout << '|';
	int w = 10;
	int delta = (line_size - w) / 2;
	if (day < 9) {
		cout << space(delta) << '0' << day << '.';
	}
	else {
		cout << space(delta) << day << '.';
	}
	if (month < 9) {
		cout << '0' << month << '.';
	}
	else {
		cout << month << '.';
	}
	if (year == 0) {
		cout << "0000" << space(delta) << '|' << endl;
	}
	else {
		cout << year << space(delta) << '|' << endl;
	}
}

void vivod(struct culture* a) {
	cout << '|' << a->name << space(20 - size(a->name));
	cout << '|' << a->type << space(5 - size(a->type));
	cout << '|' << a->square << space(40 - size(a->square));
	cout << '|' << a->uroj << space(29 - size(a->uroj));
	print_date(a->date.day, a->date.month, a->date.year, 38);
}


void table(struct culture* cul) {
	setlocale(LC_ALL, "Russian");
	Line();
	cout.width(137); cout << left << "|Сельскохозяйственные культуры"; cout << '|' << endl;
	Line();
	print_centr("Наименование", 22);
	print_centr("Тип", 7);
	print_centr("Посевная площадь(га)", 42);
	print_centr("Урожайность(ц/га)", 32);
	print_centr("Дата начала посевной", 40);
	cout << "|" << endl;

	for (int i = 0; i < 3; i++) {
		Line();
		vivod(cul + i);
	}
	Line();
	cout << '|' << "Примечание: З - зерновые, Б - бобовые" << space(137 - size("Примечание: З - зерновые, Б - бобовые")) << '|' << endl;
	Line();
}

void delete_date(struct culture* cul) {
	for (int i = 0; i < 3; i++) {
		cul[i].date.day = 0;
		cul[i].date.month = 0;
		cul[i].date.year = 0;
	}
}

int main() {
	culture cul[10];
	cul[0] = { "Соя", "Б", "13000", "45",{3,3,2022} };
	cul[1] = { "Чумиза", "З", "8000", "17", {3,4,2022} };
	cul[2] = { "Рис", "З", "25650", "24", {4,3,2022} };
	table(cul);
	delete_date(cul);
	cout << endl << endl << endl;
	table(cul);
	return 0;
}
