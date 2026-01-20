#include "OversizedProduct.h"

using namespace Store;

OversizedProduct::OversizedProduct() : Product()
{
    height = 0; width = 0; length = 0;
}

OversizedProduct::OversizedProduct(string code, string name, double price, string description, double height, double width, double length)
    : Product(code, name, price, description)
{
    this->height = height;
    this->width = width;
    this->length = length;
}

OversizedProduct::~OversizedProduct()
{
    cout << "Deleted OversizedProduct" << endl;
}

void OversizedProduct::showInfo() const
{
    cout << "\n--- Oversize product ---" << endl;
    Product::showInfo();
    cout << "size (H W L ): " << height << "x" << width << "x" << length << endl;
}

void OversizedProduct::save(ofstream& file) const
{
    file << 3 << endl;
    Product::save(file);
    file << height << endl;
    file << width << endl;
    file << length << endl;
}

void OversizedProduct::load(ifstream& file)
{
    Product::load(file);
    file >> height >> width >> length;
}

int OversizedProduct::getType() const { return 3; }