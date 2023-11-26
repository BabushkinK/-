#include<iostream>

// Уравнение, которое нужно решить: E - eccentric anomaly, M - mean anomaly
double phi(double E, double M) {
	return E + M;
}

// Метод итераций
double iterativeMethod(double M) {
	double E_k = M; // Начальное значение
	double epsilon = 0.0001; // Точность вычислений
	double diff;
	do {
		double E_k1 = phi(sin(E_k), M); // Следующая итерация
		diff = std::abs(E_k1 - E_k); // Проверка точности
		E_k = E_k1;
	} while (diff >= epsilon);

	return E_k;
}

int main() {
	double M = 0.33; // Масса центрального тела (планеты)
	double E = iterativeMethod(M);
	std::cout << "Eccentric Anomaly E: " << E << std::endl;

	return 0;
}



#include<iostream>

// Функция, для которой мы ищем корень
double f(double E, double M) {
	return E - sin(E) - M;
}

// Метод половинного деления (метод бисекции) для нахождения корня
double bisectionMethod(double a, double b, double M, double epsilon) {
	double c = (a + b) / 2;

	while ((b - a) >= 2 * epsilon) {
		c = (a + b) / 2;

		if (f(a, M) * f(c, M) < 0)
			b = c;
		else
			a = c;
	}

	return c;
}

int main() {
	double M = 0.33; // Масса центрального тела (планеты)
	double a = -5; // Любое a такое, что f(a) < 0
	double b = 5; // Любое b такое, что f(b) > 0
	double epsilon = 1e-8; // Требуемая точность

	double E = bisectionMethod(a, b, M, epsilon);

	std::cout << "Корень уравнения Кеплера: " << E << std::endl;

	return 0;
}







#include <iostream>

// Функция, для которой мы ищем корень
double f(double E, double M) {
	return E - sin(E) - M;
}

// Производная функции
double fPrime(double E) {
	return 1 - cos(E);
}

// Метод Ньютона (метод касательных) для нахождения корня
double newtonRaphsonMethod(double M, double epsilon) {
	double E0 = M;
	double E1 = E0 - f(E0, M) / fPrime(E0);

	while (std::abs(E1 - E0) > epsilon) {
		E0 = E1;
		E1 = E0 - f(E0, M) / fPrime(E0);
	}

	return E1;
}

int main() {
	double M = 0.33; // Масса центрального тела (планеты)
	double epsilon = 1e-8; // Требуемая точность

	double E = newtonRaphsonMethod(M, epsilon);

	std::cout << "Корень уравнения Кеплера: " << E << std::endl;

	return 0;
}


#include<iostream>

double f(double E, double M) {
	return E - sin(E) - M; // Функция, для которой ищем корень
}

double goldenSectionMethod(double M) {
	const double phi = (1 + std::sqrt(5)) / 2; // Значение золотого сечения

	double a = -1; // Инициализация левого конца
	double b = 1; // Инициализация правого конца
	double epsilon = 0.0001; // Точность вычислений

	while (std::abs(b - a) > epsilon) {
		double c = b - (b - a) / phi; // Вычисление точки с
		double d = a + (b - a) / phi; // Вычисление точки d

		if (f(c, M) < f(d, M)) {
			b = d;
		}
		else {
			a = c;
		}
	}

	return (a + b) / 2;
}

int main() {
	double M = 0.33; // Масса центрального тела (планеты)
	double E = goldenSectionMethod(M);
	std::cout << "Eccentric Anomaly E: " << E << std::endl;

	return 0;
}

