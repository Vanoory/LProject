#pragma once
#include "Product.h"

namespace Store {
    class OversizedProduct : public Product
    {
    protected:
        double height;
        double width;
        double length;

    public:
        OversizedProduct();
        OversizedProduct(string code, string name, double price, string description, double height, double width, double length);
        ~OversizedProduct();

        void showInfo() const override;
        void save(ofstream& file) const override;
        void load(ifstream& file) override;
        int getType() const override;
    };
}