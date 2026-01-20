#pragma once
#include "Product.h"

namespace Store {
    class FragileProduct : public Product
    {
    protected:
        double fragilityCoeff;

    public:
        FragileProduct();
        FragileProduct(string code, string name, double price, string description, double fragilityCoeff);
        ~FragileProduct();

        void showInfo() const override;
        void save(ofstream& file) const override;
        void load(ifstream& file) override;
        int getType() const override;
    };
}