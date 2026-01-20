#include "PerishableProduct.h"

using namespace Store;

PerishableProduct::PerishableProduct() : Product()
{
    maxStorageDays = 0;
}

PerishableProduct::PerishableProduct(string code, string name, double price, string description, int maxStorageDays)
    : Product(code, name, price, description)
{
    this->maxStorageDays = maxStorageDays;
}

PerishableProduct::~PerishableProduct()
{
    cout << "Deleted PerishableProduct" << endl;
}

void PerishableProduct::showInfo() const
{
    cout << "\n--- perishables ---" << endl;
    Product::showInfo();
    cout << "Storage period " << maxStorageDays << " D" << endl;
}

void PerishableProduct::save(ofstream& file) const
{
    file << 2 << endl;
    Product::save(file);
    file << maxStorageDays << endl;
}

void PerishableProduct::load(ifstream& file)
{
    Product::load(file);
    file >> maxStorageDays;
}

int PerishableProduct::getType() const { return 2; }