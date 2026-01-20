#include "Catalogue.h"

Catalogue::Catalogue()
{
}

Catalogue::~Catalogue()
{
    for (auto p : products) {
        delete p;
    }
    products.clear();
}

void Catalogue::addProduct(Product* obj)
{
    products.push_back(obj);
}

void Catalogue::removeProduct(string code)
{
    // Використання ітератора для пошуку і видалення
    for (auto it = products.begin(); it != products.end(); ++it) {
        if ((*it)->getCode() == code) {
            delete* it; // Звільняємо пам'ять
            products.erase(it); // Видаляємо з вектора
            cout << "product has been removed." << endl;
            return;
        }
    }
    cout << "Product not found." << endl;
}

void Catalogue::showAll() const
{
    if (products.empty()) {
        cout << "directory is empty." << endl;
        return;
    }
    for (auto item : products) {
        item->showInfo();
    }
}

void Catalogue::findByName(string name) const
{
    bool found = false;
    for (auto item : products) {
        if (item->getName() == name) {
            item->showInfo();
            found = true;
        }
    }
    if (!found) cout << "Nothing found." << endl;
}

void Catalogue::sortProducts()
{
    sort(products.begin(), products.end(), CmpByPrice());
    cout << "Catalog sorted by price." << endl;
}

Product* Catalogue::getProductByCode(string code)
{
    for (auto item : products) {
        if (item->getCode() == code) {
            return item;
        }
    }
    return nullptr;
}

void Catalogue::saveToFile(string filename)
{
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    file << products.size() << endl;
    for (auto item : products) {
        item->save(file);
    }
    file.close();
    cout << "Data saved." << endl;
}

void Catalogue::loadFromFile(string filename)
{
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File not found." << endl;
        return;
    }

    // Очищаємо поточні дані перед завантаженням
    for (auto p : products) delete p;
    products.clear();

    int count;
    file >> count;

    for (int i = 0; i < count; i++) {
        int type;
        file >> type;
        Product* temp = nullptr;

        if (type == 1) temp = new FragileProduct();
        else if (type == 2) temp = new PerishableProduct();
        else if (type == 3) temp = new OversizedProduct();

        if (temp != nullptr) {
            temp->load(file);
            products.push_back(temp);
        }
    }
    file.close();
    cout << "Data has been loaded." << endl;
}