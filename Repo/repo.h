#pragma once
#include "..//Domain/activitate.h"

#include <utility>
#include <vector>
#include <string>
#include <ostream>

using namespace std;

class RepoActivitate{
    vector<Activitate> all;

    [[nodiscard]] bool exist(const Activitate& a) const;

public:
    RepoActivitate() = default;

    RepoActivitate(const RepoActivitate& ot) = delete;

    /// adaugare in lista all noua activitate
    /// \param a - const Activitate&
    void plan(const Activitate& a);

    /// stergere din lista all activitatea de pe pozitia poz
    /// \param poz - int
    void sterge(int poz);

    /// modifica activitatea de pe pozitia poz cu activitatea a
    /// \param a - const Activitate&
    /// \param poz - int
    void modifica(const Activitate& a, int poz);

    [[nodiscard]] const Activitate& find(const string& titlu) const;

    [[nodiscard]] const vector<Activitate>& getAll() const noexcept;
};

class RepoException{
    string msg;

public:
    explicit RepoException(string m):msg(std::move( m )){}

    friend ostream& operator<<(ostream& out, const RepoException& ex);
};

ostream& operator<<(ostream& out, const RepoException& ex);