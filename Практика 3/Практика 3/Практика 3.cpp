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

struct Node {
	short day;
	Node* next = NULL;
};

struct Node* head;
int countItem = 0;

void addItem(short data) {
	struct Node* newItem = new Node();

	newItem->day = data;

	if (countItem == 0) {
		newItem->next = NULL;
	}
	else {
		newItem->next = head;
	}
	head = newItem;
	countItem++;
}

void insertItem(int index, short data) {
	if (not(index >= 0 and index <= countItem and countItem >= 0)) {
		return;
	}
	if (index == 0) {
		addItem(data);
	}
	else {
		struct Node* current = head;
		struct Node* newItem = new Node();
		newItem->day = data;
		for (int i = 0; i < index - 1; i++) {
			current = current->next;
		}
		newItem->next = current->next;
		current->next = newItem;
		countItem++;
	}
}

void deleteItem(int index) {
	struct Node* current = head;
	struct Node* old;
	if (index == 0) {
		old = head;
		head = current->next;
		delete old;
		countItem--;
	}
	else {
		for (int i = 0; i != index - 1; i++) {
			current = current->next;
		}
		old = current->next->next;
		current->next = old;
		countItem--;
	}
}

void print_all() {
	struct Node* current = head;
	while (current) {
		cout <<"Адрес(next): " << current->next << "	";
		cout << "Значение: " << current->day << endl;
		current = current->next;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	culture cul[10];
	cul[0] = { "Соя", "Б", "13000", "45",{3,3,2022} };
	cul[1] = { "Чумиза", "З", "8000", "17", {3,4,2022} };
	cul[2] = { "Рис", "З", "25650", "24", {4,3,2022} };
	cul[3] = { "Гречка", "З", "28840", "65", {20,6,2022} };
	cul[4] = { "Пшено", "З", "2440", "79", {14,9,2022} };

	for (int i = 0; i < 2; i++) {
		addItem(cul[0].date.day);
		addItem(cul[1].date.day);
		addItem(cul[2].date.day);
	}

	print_all();
	cout << endl << endl << endl;

	insertItem(0, cul[3].date.day);
	insertItem(4, cul[4].date.day);

	print_all();
	cout << endl << endl << endl;

	deleteItem(2);
	deleteItem(5);

	print_all();

	cout << endl << endl;

	cout << "Введите значение поля:" << endl;
	short new_day;
	cin >> new_day;
	cout << endl;

	Node* current = head;
	int i = 0;
	bool Flag = false;

	while(current) {
		if (current->day == new_day) {
			insertItem(i+1, new_day);
			i++;
			current = current->next;
			Flag = true;
		}
		i++;
		current = current->next;
	}

	if (!Flag) {
		insertItem(0, new_day);
	}

	print_all();
	cout << endl << endl << endl;

	int count = countItem;
	for (int i = 0; i < count; i++) {
		deleteItem(0);
	}

	print_all();
}
