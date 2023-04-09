#include "tests.h"
#include <sstream>

void test_all(){
    test_adauga_activitate();
    test_sterge_activitate();
    test_modifica_activitate();
}


void test_adauga_activitate(){
    RepoActivitate repo;
    Activitate_Validator valid;
    ServiceActivitate service{repo,valid};
    service.adauga_activitate("titlu","descriere","tip",3);
    assert(service.getAll().size() == 1);

    try {
        service.adauga_activitate("","","",-1);
    }
    catch(Validare& ex){
        stringstream sout;
        sout<<ex;
    }

    try{
        service.adauga_activitate("titlu","descriere","tip",3);
    }
    catch(RepoException& ex){
        stringstream sout;
        sout<<ex;
    }
}

void test_sterge_activitate(){
    RepoActivitate repo;
    Activitate_Validator valid;
    ServiceActivitate service{repo,valid};
    service.adauga_activitate("titlu","descriere","tip",3);
    service.adauga_activitate("titlu2","descriere2","tip2",6);
    assert(service.sterge_activitate("titlu2") == 1);
    assert(service.getAll().size() == 1);
    assert(service.sterge_activitate("titlu2") == 0);
}

void test_modifica_activitate(){
    RepoActivitate repo;
    Activitate_Validator valid;
    ServiceActivitate service{repo,valid};
    service.adauga_activitate("titlu","descriere","tip",3);
    service.adauga_activitate("titlu2","descriere2","tip2",6);
    assert(service.modifica_activitate("titlu","desc","sgf",8) == 1);
    assert(service.modifica_activitate("titlu3","desc","sgf",8) == 0);
}