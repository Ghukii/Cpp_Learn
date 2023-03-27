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

char* space(int n) {
	char* str = new char[n];
	for (int i = 0; i < n; i++) {
		str[i] = ' ';
	}
	str[n] = '\0';
	return str;
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
	cout << year << space(delta)<<'|';
}

void vivod(struct culture* a) {
	cout << '|' << a->name << space(19 - size(a->name));
	cout << '|' << a->type << space(4 - size(a->type));
	cout << '|' << a->square << space(39 - size(a->square));
	cout << '|' << a->uroj << space(29 - size(a->uroj));
	print_date(a->date[0], a->date[0], a->date[0], 20);
}


void wrong_table(struct culture* cul) {
	setlocale(LC_ALL, "Russian");
	Line();
	cout << '|' << "Сельскохозяйственные культуры" << space(95 - size("Сельскохозяйственные культуры")) << '|' << endl;
	Line();
	cout << '|' << "Наименование" << space(20 - size("Наименование"));
	cout << '|' << "Тип" << space(5 - size("Тип"));
	cout << '|' << "Посевная площадь(га)" << space(40 - size("Посевная площадь(га)"));
	cout << '|' << "Урожайность(ц/га)" << space(30 - size("Урожайность(ц/га)"));
	cout << '|' << "Дата начала посевной" << space(40 - size("Дата начала посевной")) << '|' << endl;
	Line();
	vivod(cul[0]);
	Line();
	vivod(cul[1]);
	Line();
	vivod(cul[2]);
	Line();
	cout << '|' << "Примечание: З - зерновые, Б - бобовые" << space(95 - size("Примечание: З - зерновые, Б - бобовые")) << '|' << endl;
	Line();
}


int main() {
	culture cul[3];
	cul[0] = { "Соя", "Б", "13000", "45",{3,3,2022} };
	cul[1] = {"Чумиза", "З", "8000", "17", {3,4,2022}};
	cul[2] = {"Рис", "З", "25650", "24", {4,3,2022}};
	wrong_table(cul);
}