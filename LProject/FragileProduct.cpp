#include "FragileProduct.h"

using namespace Store;

FragileProduct::FragileProduct() : Product()
{
    fragilityCoeff = 0.0;
}

FragileProduct::FragileProduct(string code, string name, double price, string description, double fragilityCoeff)
    : Product(code, name, price, description)
{
    this->fragilityCoeff = fragilityCoeff;
}

FragileProduct::~FragileProduct()
{
    cout << "Deleted FragileProduct" << endl;
}

void FragileProduct::showInfo() const
{
    cout << "\n--- Fragile product ---" << endl;
    Product::showInfo();
    cout << "Fragility factor: " << fragilityCoeff << endl;
}

void FragileProduct::save(ofstream& file) const
{
    file << 1 << endl;
    Product::save(file);
    file << fragilityCoeff << endl;
}

void FragileProduct::load(ifstream& file)
{
    Product::load(file);
    file >> fragilityCoeff;
}

int FragileProduct::getType() const { return 1; }