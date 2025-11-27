#include <iostream>
#include <fstream>
#include <random>
#include "Vector3F.h"
#include "PhoneBook.h"

using namespace std;

// --- допоміжні функції Vector3F ---
Vector3F inputFromKeyboard() {
    Vector3F v;
    cout << "Введіть x y z: ";
    cin >> v;
    return v;
}

Vector3F inputFromFile(const string& filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Файл не знайдено.\n";
        return Vector3F();
    }
    Vector3F v;
    fin >> v;
    return v;
}

Vector3F randomVector() {
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dist(-10.0f, 10.0f);

    float arr[3] = { dist(gen), dist(gen), dist(gen) };
    return Vector3F(arr);
}

void testExpressions() {
    cout << "\n=== Тест векторних виразів ===\n";

    Vector3F a = randomVector();
    Vector3F b = randomVector();
    Vector3F c(2.0f);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "c = " << c << endl;

    Vector3F r = ((a + b) * 2.0f - c) / 3.0f + ~a;
    cout << "r = ((a + b) * 2 - c) / 3 + ~a = " << r << endl;

    Vector3F t = a;
    t &= b;

    Vector3F q = -(t) * 0.5f + c++;
    cout << "q = -(a & b) * 0.5 + c++ = " << q << endl;
    cout << "c після c++ = " << c << endl;

    cout << "a > b ? " << (a > b ? "true" : "false") << endl;

    cout << "a[0] = " << a[0] << endl;

    cout << "Кількість об’єктів: " << Vector3F::getObjectCount() << endl;
}

// ---------- MAIN ----------
int main() {
    PhoneBook pb;

    int choice;
    do {
        cout << "\n=== МЕНЮ ЛАБИ 4 ===\n";
        cout << "1 - Ввести вектор\n";
        cout << "2 - Вектор з файлу\n";
        cout << "3 - Випадковий вектор\n";
        cout << "4 - Тест векторних виразів\n";
        cout << "5 - Телефонна книга (2.6)\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1) {
            Vector3F v = inputFromKeyboard();
            cout << "Ви ввели: " << v << endl;
        }
        else if (choice == 2) {
            Vector3F v = inputFromFile("vector.txt");
            cout << "З файлу: " << v << endl;
        }
        else if (choice == 3) {
            Vector3F v = randomVector();
            cout << "Випадковий вектор: " << v << endl;
        }
        else if (choice == 4) {
            testExpressions();
        }
        else if (choice == 5) {
            int c2;
            do {
                cout << "\n=== Телефонна книга ===\n";
                cout << "1 - Додати запис\n";
                cout << "2 - Видалити запис\n";
                cout << "3 - Редагувати запис\n";
                cout << "4 - Пошук за номером\n";
                cout << "5 - Вивести всі записи\n";
                cout << "6 - Зберегти у файл\n";
                cout << "7 - Завантажити з файлу\n";
                cout << "0 - Назад\n";
                cin >> c2;

                if (c2 == 1) {
                    string phone, name;
                    cout << "Телефон: "; cin >> phone;
                    cout << "ПІБ: "; cin.ignore(); getline(cin, name);
                    pb.add(phone, name);
                }
                else if (c2 == 2) {
                    string phone; cout << "Телефон: "; cin >> phone;
                    pb.remove(phone);
                }
                else if (c2 == 3) {
                    string phone, name;
                    cout << "Телефон: "; cin >> phone;
                    cout << "Нове ПІБ: "; cin.ignore(); getline(cin, name);
                    pb.edit(phone, name);
                }
                else if (c2 == 4) {
                    string phone; cout << "Телефон: "; cin >> phone;
                    cout << pb.find(phone) << endl;
                }
                else if (c2 == 5) {
                    pb.print();
                }
                else if (c2 == 6) {
                    pb.saveToFile("phonebook.csv");
                    cout << "Збережено.\n";
                }
                else if (c2 == 7) {
                    pb.loadFromFile("phonebook.csv");
                    cout << "Завантажено.\n";
                }
            } while (c2 != 0);
        }

    } while (choice != 0);

    return 0;
}
