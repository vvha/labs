/* Ищенко лабораторная работа №4 Вариант 3 */
#include <iostream>
#include <cmath>

using namespace std;

class Circle { // объявление класса Circle
	double R; // объявление поля, хранящего радиус окружности
	static int count; // счётчик
	const int ind; // номера объектов
public:

	Circle() : ind(++count) { // конструктор
		SetRadius(); // ввод радиуса окружности
	}

	double GetRadius() { // геттер радиуса
		return R;
	}
	// геттер номера конуса
	int GetInd() {
		return ind;
	}
	// геттер количества конусов
	static int GetTotal() {
		return count;
	}
	void SetRadius() { // сеттер радиуса
		cout << "Введите радиус: ";
		cin >> R;
	}


	double Ploshad() {
		return 3.14 * pow(GetRadius(), 2);
	}

	double GetLength() {  // длина окружности
		return 2 * 3.14 * GetRadius();
	}

	void show() { // вывод всех значений
		cout << "Радиус: " << GetRadius() << "\nДлина окружности: " << GetLength() << "\nПлощадь: " << Ploshad() << endl;
	}

};

int Circle::count = 0;

class Cone : public Circle { // объявление дочернего класса Cone от родительского класса Circle
	double h; // объявление поля для хранения высоты

public:
	Cone() { // конструктор, переопределение константы id и раелизация работы счётчика
		cout << "Введите высоту: ";
		SetHeight(); // ввод высоты конуса
	}
	// сеттер высоты
	void SetHeight() {
		cin >> h;
	}
	// геттер высоты
	double GetHeight() {
		return h;
	}
	// площадь
	double Ploshad() {
		return 3.14 * sqrt(pow(GetRadius(), 2) + pow(GetHeight(), 2)) * GetRadius() + Circle::Ploshad(); // площадь (Circle::Ploshad() - вызов метода Ploshad() из родительского класса Circle)
	}
	// объём конуса
	double OBbem() {
		return (Ploshad() * GetHeight()) / 3;
	}

	void show() { // вывод всех значений
		cout << "Радиус и высота: " << GetRadius() << ", " << GetHeight();
		cout << "\nПлощадь и объём: " << Ploshad() << ", " << OBbem();
		cout << "\nДлина окружности: " << GetLength() << endl;
	}
};


int main() {
	setlocale(LC_ALL, "ru");
	int N, M;
	cout << "Количество окружностей: ";
	cin >> N;
	cout << "Количество конусов: ";
	cin >> M;
	Circle* okr = new Circle[N]; // массив объектов класса Circle
	Cone* conus = new Cone[M]; // массив объектов класса Cone
	// подсчёт количества окружностей с площадью меньше среднего
	double sum = 0;
	// сумма площадей окружнсотей
	for (int i = 0; i < N; i++)
	{
		sum = okr[i].Ploshad();
	}
	sum /= N; // среднее значение
	int count = 0; // счётчик
	for (int i = 0; i < N; i++)
	{
		if (okr[i].Ploshad() < sum)
		{
			count++;
		}
	}
	// нахождение конуса с наибольшим объёмом
	int m = 0;
	for (int i = 0; i < M; i++) {
		if (conus[m].OBbem() < conus[i].OBbem()) m = i;
	}
	//вывод 
	cout << "Количество окружностей, площадь которых меньше средней: " << count << endl;
	cout << "Наибольший объем у конуса под номером " << conus[m].GetInd() - N << endl;

	system("pause");
}