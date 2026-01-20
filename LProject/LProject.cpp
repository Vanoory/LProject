#include <windows.h>
#include <clocale>
#include <iostream>
#include "Catalogue.h"

using namespace std;
using namespace Store;

int main()
{
    setlocale(LC_ALL, "Ukrainian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Catalogue myStore;

    int choice;
    do {
        cout << "\n=== МЕНЮ ===" << endl;
        cout << "1. Показати всі товари" << endl;
        cout << "2. Додати товар" << endl;
        cout << "3. Видалити товар" << endl;
        cout << "4. Редагувати ціну товару" << endl;
        cout << "5. Пошук за назвою" << endl;
        cout << "6. Сортувати за ціною" << endl;
        cout << "7. Зберегти у файл" << endl;
        cout << "8. Завантажити з файлу" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        try {
            if (choice == 1) {
                myStore.showAll();
                cout << "Всього створено товарів: " << Product::getTotalCount() << endl;
            }
            else if (choice == 2) {
                int type;
                cout << "Тип (1-Крихкий, 2-Швидкопсувний, 3-Габаритний): ";
                cin >> type;
                string c, n, d;
                double p;
                cout << "Код: "; cin >> c;
                cout << "Назва: "; cin >> n;
                cout << "Ціна: "; cin >> p;
                cout << "Опис: "; cin.ignore(); getline(cin, d);

                if (type == 1) {
                    double coef;
                    cout << "Коеф. крихкості: "; cin >> coef;
                    myStore.addProduct(new FragileProduct(c, n, p, d, coef));
                }
                else if (type == 2) {
                    int days;
                    cout << "Днів зберігання: "; cin >> days;
                    myStore.addProduct(new PerishableProduct(c, n, p, d, days));
                }
                else if (type == 3) {
                    double h, w, l;
                    cout << "В/Ш/Д: "; cin >> h >> w >> l;
                    myStore.addProduct(new OversizedProduct(c, n, p, d, h, w, l));
                }
            }
            else if (choice == 3) {
                string code;
                cout << "Введіть код для видалення: "; cin >> code;
                myStore.removeProduct(code);
            }
            else if (choice == 4) {
                string code;
                cout << "Введіть код товару: "; cin >> code;
                Product* p = myStore.getProductByCode(code);
                if (p) {
                    double newPrice;
                    cout << "Нова ціна: "; cin >> newPrice;
                    p->setPrice(newPrice);
                    cout << "Ціну змінено." << endl;
                }
                else {
                    cout << "Товар не знайдено." << endl;
                }
            }
            else if (choice == 5) {
                string name;
                cout << "Введіть назву: "; cin >> name;
                myStore.findByName(name);
            }
            else if (choice == 6) {
                myStore.sortProducts();
            }
            else if (choice == 7) {
                myStore.saveToFile("database.txt");
            }
            else if (choice == 8) {
                myStore.loadFromFile("database.txt");
            }
        }
        catch (const char* msg) {
            cout << "ОШИБКА " << msg << endl;
        }

    } while (choice != 0);

    return 0;
}