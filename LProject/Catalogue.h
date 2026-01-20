#pragma once
#include <vector>
#include <algorithm>
#include "FragileProduct.h"
#include "PerishableProduct.h"
#include "OversizedProduct.h"

using namespace Store;

// Функтор для сортування за ціною
struct CmpByPrice {
    bool operator()(const Product* left, const Product* right) const {
        return left->getPrice() < right->getPrice();
    }
};

class Catalogue
{
    vector<Product*> products;

public:
    Catalogue();
    ~Catalogue();

    void addProduct(Product* obj);
    void removeProduct(string code);
    void showAll() const;
    void findByName(string name) const;
    void sortProducts();

    void saveToFile(string filename);
    void loadFromFile(string filename);

    // Доступ через індекс для редагування (якщо треба)
    Product* getProductByCode(string code);
};