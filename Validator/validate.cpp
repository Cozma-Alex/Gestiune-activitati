#include "validate.h"
#include <sstream>

void Activitate_Validator::validate(const Activitate &a) {
    vector<string> msgs;
    if(a.get_titlu().empty())
        msgs.emplace_back("titlu invalid!\n");
    if(a.get_descriere().empty())
        msgs.emplace_back("descriere invalida!\n");
    if(a.get_durata() <= 0)
        msgs.emplace_back("durata invalida!\n");
    if(a.get_tip().empty())
        msgs.emplace_back("tip invalid!\n");
    if(!msgs.empty())
        throw Validare(msgs);
}

ostream& operator<<(ostream& out, const Validare& ex){
    for(const auto& msg : ex.msg)
        out<< msg<<" ";
    return out;
}