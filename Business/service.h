#pragma once

#include "..//Repo/repo.h"
#include "..//Validator/validate.h"
#include <string>
#include <vector>
#include <functional>

using namespace std;

class ServiceActivitate{
    RepoActivitate& repo;

public:
    ServiceActivitate(RepoActivitate& rep, Activitate_Validator& val): repo{rep}{}

    ServiceActivitate(const ServiceActivitate& ot) = delete;

    const vector<Activitate>& getAll() noexcept{
        return repo.getAll();
    }

    /// preia parametrii din ui si ii trimite sub forma de Activitate in repo pentru adaugare
    /// \param titlu const string& - titlul noii activitati
    /// \param descriere const string& - descrierea noii activitati
    /// \param tip const string& - tipul noii activitati
    /// \param durata int - durata noii activitati
    void adauga_activitate(const string& titlu, const string& descriere, const string& tip, int durata);

    /// sterge activitatea cu titlul titlu
    /// \param titlu const string&
    /// \return 1 - se realizeaza stergerea
    ///         0 - nu se realizeaza stergerea
    int sterge_activitate(const string& titlu);

    /// modifica activitatea cu titlul titlu
    /// \param titlu const string& - titlul activitatii modificate
    /// \param descriere const string& - descrierea activitatii modificate
    /// \param tip const string& - tipul activitatii modificate
    /// \param durata int - durata activitatii modificate
    /// \return 1 - se realizeaza modificarea
    ///         0 - nu se realizeaza modificarea
    int modifica_activitate(const string& titlu, const string& descriere, const string& tip, int durata);
};
