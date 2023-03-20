#include <iostream>

using namespace std;

void print(int* mas, int n) {
    for (int i = 0; i < n; i++) cout << mas[i] << "\t";
    cout << endl;
}

void printF(float* mas, int n) {
    for (int i = 0; i < n; i++) cout << mas[i] << "\t";
    cout << endl;
}

int getAmount(int max) {
    int a;

    while (true) {
        cout << "Введите кол-во элементов:\t";
        cin >> a;

        if (a == 0) cout << "Кол-во элементов не может быть равно 0!" << endl;
        else if (a > max) cout << "Кол-во элементов не может быть больше " << max << endl;
        else break;
    }

    return a;
}

void fillArrayRandom(int* mas, int n) {
    for (int i = 0; i < n; i++) mas[i] = rand();
    cout << endl;
}

void fillArrayRandomFloat(float* mas, int n) {
    for (int i = 0; i < n; i++) mas[i] = (float)rand() / (float)RAND_MAX;
    cout << endl;
}

void fillArrayFloat(float* mas, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Введите значение массива:\t";
        cin >> mas[i];
    }
}

int Task1() {
    /*
        Задание 1:
        В массиве из n целых чисел (n <= 30) найти наименьший элемент и определить порядковый номер.
    */

    int k = getAmount(30),
        i;

    int* array = new int[k];
    fillArrayRandom(array, k);

    print(array, k);

    int min = array[0],
        minIndex;

    for (i = 0; i < k; i++) {
        if (array[i] < min) {
            min = array[i];
            minIndex = i;
        }
    }

    cout << "Порядковый номер минимального элемента:\t" << minIndex << endl;

    return 0;
}

int Task2() {
    /*
        Задание 2:
        В массиве из n действительных чисел (n <= 20) поменять местами наибольший и наименьший элемент.
    */

    int k = getAmount(20);

    float* array = new float[k];
    fillArrayRandomFloat(array, k);

    printF(array, k);

    float min = array[0],
        max = array[0];

    int minIndex,
        maxIndex;

    for (int i = 0; i < k; i++) {
        if (array[i] > max) {
            max = array[i];
            maxIndex = i;
        }
    }

    for (int i = 0; i < k; i++) {
        if (array[i] < min) {
            min = array[i];
            minIndex = i;
        }
    }

    //cout << max << "\t" << min << endl;

    swap(array[maxIndex], array[minIndex]);

    printF(array, k);

    return 0;
}

int Task3() {
    /*
        Задание 3:
        В массиве из n действительных чисел (n <= 20) подсчитать количество пар соседних элементов для которых предыдущий элемент равен последующему.
    */

    int k = getAmount(20);

    float* array = new float[k];
    fillArrayFloat(array, k);

    int kp = 0;

    for (int i = 0; i < k-2; i++) {
        if (array[i] == array[i + 2]) kp++;
    }

    cout << "Кол-во пар:\t" << kp << endl;

    return 0;
}

int main()
{
    setlocale(0, "");

    //Task1();
    //Task2();
    Task3();
    return 0;
}

