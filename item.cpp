/**
* Engenharia de Software Moderna - Testes  (Cap. 8)
* Prof. Marco Tulio Valente
* 
* Exemplo simples de teste (ShoppingCart)
*
*/

/* Itens que serão armazenados no carrinho de compras */


#include <iostream>
#include <string>
using namespace std;


class Item {
private:
    string name;
    double price;

public:
    Item(const std::string& name, double price) : name(name), price(price) {}

    
    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }
};
