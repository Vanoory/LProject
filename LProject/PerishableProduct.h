#pragma once
#include "Product.h"

namespace Store {
    class PerishableProduct : public Product
    {
    protected:
        int maxStorageDays;

    public:
        PerishableProduct();
        PerishableProduct(string code, string name, double price, string description, int maxStorageDays);
        ~PerishableProduct();

        void showInfo() const override;
        void save(ofstream& file) const override;
        void load(ifstream& file) override;
        int getType() const override;
    };
}