#include "rationnel.h"

std::string rationnel::toString(){
    std::stringstream ss;
    ss << num << "/" << denum;
    return ss.str();


}
