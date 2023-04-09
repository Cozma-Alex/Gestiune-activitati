#include "ui.h"
#include <iostream>
#include <string>

using namespace std;

void ConsoleUI::ui_tipareste(const vector<Activitate> &activitati) {
    cout<<"Activitati:\n";
    for (const auto& activitate:activitati) {
        cout<<activitate.get_titlu()<<" "<<activitate.get_descriere()<<" "<<activitate.get_tip()<<" "<<activitate.get_durata()<<endl;
    }
    cout<<"Sfarsit lista activitati!\n";
}

void ConsoleUI::ui_adauga_activitate() {
    string titlu,tip,descriere;
    int durata;
    cout<<"Dati titlu:";
    cin>>titlu;
    cout<<"Dati tip:";
    cin>>tip;
    cout<<"Dati descriere:";
    cin>>descriere;
    cout<<"Dati durata:";
    cin>>durata;
    service.adauga_activitate(titlu,descriere,tip,durata);
    cout<<"Activitate adaugata cu succes!\n";
}

void ConsoleUI::ui_sterge_activitate() {
    string titlu;
    cout<<"Dati titlu:";
    cin>>titlu;
    service.sterge_activitate(titlu);
    cout<<"Activitate stearsa cu succes!\n";
}

void ConsoleUI::ui_modifica_activitate() {
    string titlu,tip,descriere;
    int durata;
    cout<<"Dati titlu:";
    cin>>titlu;
    cout<<"Dati tip:";
    cin>>tip;
    cout<<"Dati descriere:";
    cin>>descriere;
    cout<<"Dati durata:";
    cin>>durata;
    service.modifica_activitate(titlu,descriere,tip,durata);
    cout<<"Activitate modificata cu succes!\n";
}

void ConsoleUI::start()
{
    while (true){
        cout<<"1. Adauga activitate\n";
        cout<<"2. Tipareste plan\n";
        cout<<"3. Sterge activitate\n";
        cout<<"4. Modifica activitate\n";
        cout<<"0. Exit\n";
        cout<<"Introdu comanda:";
        int comanda;
        cin>>comanda;
        try{
            switch (comanda) {
                case 1:
                    ui_adauga_activitate();
                    break;
                case 2:
                    ui_tipareste(service.getAll());
                    break;
                case 3:
                    ui_sterge_activitate();
                    break;
                case 4:
                    ui_modifica_activitate();
                    break;
                case 0:
                    return;
                default:
                    cout<<"Comanda invalida!\n";
                    break;
            }
        }
        catch(const RepoException& ex)
        {cout<<ex<<endl;}

        catch(const Validare& ev)
        {cout<<ev<<endl;}
    }
}