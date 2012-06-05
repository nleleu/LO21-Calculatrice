#include "type.h"

type::type()
{
}

type* type::mod(type & t){
    throw typeException("erreur mod");
}


type* type::fact(){
    throw typeException("erreur fact");
}
