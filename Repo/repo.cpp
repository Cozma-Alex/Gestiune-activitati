#include "repo.h"
#include <iostream>

using namespace std;

void RepoActivitate::plan(const Activitate &a) {
    if(exist(a)){
        throw RepoException("Exista deja activitatea!");
    }
    all.push_back(a);
}

void RepoActivitate::sterge(int poz) {
    all.erase(all.begin()+poz);
}

void RepoActivitate::modifica(const Activitate &a, int poz) {
    all[poz] = a;
}

bool RepoActivitate::exist(const Activitate &a) const {
    try{
        find(a.get_titlu());
        return true;
    }
    catch(RepoException&){
        return false;
    }
}

const Activitate& RepoActivitate::find(const string& titlu) const {
    for (const auto& a:all) {
        if(a.get_titlu() == titlu){
            return a;
        }
    }
    throw RepoException("Nu exista activitatea!");
}

const vector<Activitate>& RepoActivitate::getAll() const noexcept {
    return all;
}

ostream& operator<<(ostream& out, const RepoException& ex){
    out<<ex.msg;
    return out;
}