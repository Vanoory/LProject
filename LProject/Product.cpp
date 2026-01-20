#include "Product.h"

using namespace Store;

int Product::totalCount = 0;

Product::Product()
{
    totalCount++;
    id = totalCount;
    price = 0.0;
    name = "Undefined";
}

Product::Product(string code, string name, double price, string description)
{
    totalCount++;
    this->id = totalCount;
    this->code = code;
    this->name = name;

    if (price < 0) throw "Ціна не може бути від'ємною!";
    this->price = price;

    this->description = description;
}

Product::~Product()
{
}

int Product::getId() const { return id; }
string Product::getName() const { return name; }
double Product::getPrice() const { return price; }
string Product::getCode() const { return code; }

void Product::setName(string name) { this->name = name; }
void Product::setPrice(double price) {
    if (price < 0) throw "Ціна не може бути від'ємною!";
    this->price = price;
}

void Product::showInfo() const
{
    cout << "ID: " << id << " | Cod: " << code << endl;
    cout << "name: " << name << endl;
    cout << "price: " << price << " grn" << endl;
    cout << "description: " << description << endl;
}

void Product::save(ofstream& file) const
{
    file << code << endl;
    file << name << endl;
    file << price << endl;
    file << description << endl;
}

void Product::load(ifstream& file)
{
    file >> code;
    file.ignore();
    getline(file, name);
    file >> price;
    file.ignore();
    getline(file, description);
}

int Product::getTotalCount() { return totalCount; }

bool Product::operator==(const Product& other) const
{
    return this->code == other.code;
}