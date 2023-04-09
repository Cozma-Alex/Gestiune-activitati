#include "service.h"

void ServiceActivitate::adauga_activitate(const std::string &titlu, const std::string &descriere,
                                          const std::string &tip, int durata) {
    Activitate a{titlu, descriere, tip,durata};
    Activitate_Validator::validate(a);
    repo.plan(a);
}

int ServiceActivitate::sterge_activitate(const std::string &titlu) {
    int poz = 0;
    for (const auto& activitate: getAll()){
        {
            if(titlu == activitate.get_titlu()){
            repo.sterge(poz);
                return 1;
        }
        poz++;
        }
    }
    return 0;
}

int ServiceActivitate::modifica_activitate(const std::string &titlu, const std::string &descriere,
                                            const std::string &tip, int durata) {
    int poz = 0;
    Activitate a{titlu,descriere,tip,durata};
    Activitate_Validator::validate(a);
    for (const auto& activitate: getAll()){
        {
            if(titlu == activitate.get_titlu()){
                repo.modifica(a,poz);
                return 1;
            }
            poz++;
        }
    }
    return 0;
}
