//������� 5 ������� ������
#include<iostream>
#include<string>
using namespace std;

struct culture {
	char name[20];
	char type[5];
	char square[40];
	char uroj[30];
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

void vivod(culture a) {
	cout << '|' << a.name << space(19 - size(a.name));
	cout << '|' << a.type << space(4 - size(a.type));
	cout << '|' << a.square << space(39 - size(a.square));
	cout << '|' << a.uroj << space(29 - size(a.uroj)) << '|' << endl;;
}

int main() {
	setlocale(LC_ALL, "Russian");
	Line();
	cout << '|' << "�������������������� ��������" << space(95 - size("�������������������� ��������")) << '|' << endl;
	Line();
	cout << '|' << "������������" << space(20 - size("������������"));
	cout << '|' << "���" << space(5 - size("���"));
	cout << '|' << "�������� �������(��)" << space(40 - size("�������� �������(��)"));
	cout << '|' << "�����������(�/��)" << space(30 - size("�����������(�/��)")) << '|' << endl;;
	Line();
	culture a1 = { "���", "�", "13000", "45" };
	culture a2 = { "������", "�", "8000", "17" };
	culture a3 = { "���", "�", "25650", "24" };
	vivod(a1);
	Line();
	vivod(a2);
	Line();
	vivod(a3);
	Line();
	cout << '|' << "����������: � - ��������, � - �������" << space(95 - size("����������: � - ��������, � - �������")) << '|' << endl;
	Line();
}