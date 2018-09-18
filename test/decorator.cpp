#include <iostream>
#include <string>

using  std::string;
using std::cout;
using std::endl;

class Beverage {
public:

    virtual void getDescription() = 0;
    virtual double getCost() = 0 ;

private:
  string _description = "Unknown";
};

class Black : public Beverage {
public:
  Black(string name) : _description(name) {}
  void getDescription() { cout << _description;}
  double getCost() {return 8.0;}
private:
  string _description;

};


class Condiment : public Beverage {

public:
  Condiment(Beverage * bev) : _bev(bev) {}
  void getDescription() {_bev->getDescription(); cout << "Condiment";}
  double getCost() {return _bev->getCost() + 0.99;}

private:
  Beverage * _bev;
};



int main(int argc, char ** argv) {

  Black myback("this is a black");
  Condiment mycon(&myback);
  mycon.getDescription();

  return 0;
}
