/* Ищенко лабораторная работа №5 Вариант 3 */
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Employee {
protected:
	Employee* next; // ссылка на след. объект в списке
	static Employee* top; // верхний элемент
	string name; // имя сотрудника
public:

	Employee();
	void Add();
	// виртуальные методы
	static void see_list();
	virtual void show() = 0;
	virtual ~Employee() = default;
};

Employee* Employee::top = nullptr;

Employee::Employee() { // описание конструктора
	cout << "Имя сотрудника: ";
	cin >> name;
	Add();
}

void Employee::Add() { // описание метода добавления
	next = top;
	top = this;
}

void Employee::see_list() { // описание метода просмотра связного списка
	Employee* p = top;
	for (;;) { // бесконечный цикл
		if (!p) break;
		p->show();
		p = p->next;
	}
}

class Admin : public Employee
{
protected:
	string pos; // должность
public:
	Admin() {
		pos = "Администратор";
	}

	void show() override {
		cout << name << " - " << pos << endl;
	}
	~Admin() = default;
};

class Engineer : public Employee
{
protected:
	string pos; // должность
public:
	Engineer() {
		pos = "Инженер";
	}

	void show() override {
		cout << name << " - " << pos << endl;
	}
	~Engineer() = default;
};

class Worker : public Employee
{
protected:
	string pos; // должность
public:
	Worker() {
		pos = "Рабочий";
	}

	void show() override {
		cout << name << " - " << pos << endl;
	}
	~Worker() = default;
};

int main() {
	SetConsoleCP(1251);        //Кодировка
	SetConsoleOutputCP(1251);   //Консоли
	for (;;) {
		system("cls"); // очистка консоли
		cout << "Что сделать?\n1. Добавить админа\n2. Добавить рабочего\n3. Добавить Инженера\n4. Просмотреть список\n0. Выход\n";
		int choice; // переменная выбора
		cin >> choice;
		system("cls");
		if (choice == 0) { // условие выхода из программы
			cout << "Вы уверены? (1/2)\n";
			cin >> choice;
			if (choice == 1) break;
			else continue;
		}
		switch (choice) // выбор действия
		{
		case 1:
		{auto* p = new Admin;} // создание нового объекта Admin
		cout << "Админ был добавлен в список!";
		system("timeout 2"); // пауза в консоли
		break;
		case 2:
		{auto* p = new Worker;} // создание нового объекта Worker
		cout << "Рабочий был добавлен в список!";
		system("timeout 2");
		break;
		case 3:
		{auto* p = new Engineer;} // создание нового объекта Engineer
		cout << "Инженер был добавлен в список!";
		system("timeout 2");
		break;
		case 4:
			Employee::see_list();
			system("pause");
			break;
		default:
			break;
		}
	}

	return 0;
}