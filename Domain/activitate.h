#pragma once
#include <string>
#include <iostream>
#include <utility>

using namespace std;

class Activitate {
    string titlu;
    string descriere;
    string tip;
    int durata;
public:
    Activitate(string  titl, string  descr,string  t, int dur):titlu{std::move(titl)},descriere{std::move(descr)},tip{std::move(t)},durata{dur}{
        //cout<<"Construit cu parametri\n";
    }

    Activitate(const Activitate& ot):titlu{ot.titlu}, descriere{ot.descriere}, tip{ot.descriere}, durata{ot.durata}{
        //cout<<"Construit prin copiere!\n";
    }

    [[nodiscard]] string get_titlu() const{
        return titlu;
    }

    [[nodiscard]] string get_descriere() const{
        return descriere;
    }

    [[nodiscard]] string get_tip() const{
        return tip;
    }

    [[nodiscard]] int get_durata() const{
        return durata;
    }

    ~Activitate(){
        //out<<"Distrus\n";
    }
};
