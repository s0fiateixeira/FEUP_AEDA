#ifndef SRC_VETERINARY_H_
#define SRC_VETERINARY_H_

#include <string>
using namespace std;

class Veterinary {
    string name;
    long codOrder;
public:
    Veterinary(string nome, int cod): name(nome), codOrder(cod){};
    string getName() const;
    string getInfo() const{return (name + ", " + to_string(codOrder));};
};



#endif /* SRC_VETERINARY_H_ */
