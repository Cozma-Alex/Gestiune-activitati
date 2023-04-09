#pragma once
#include "..//Business/service.h"

class ConsoleUI{
    ServiceActivitate& service;

    void ui_adauga_activitate();

    static void ui_tipareste(const vector<Activitate>& activitati);

    void ui_sterge_activitate();

    void ui_modifica_activitate();

public:
    explicit ConsoleUI(ServiceActivitate& service):service{service}{}

    ConsoleUI(const ConsoleUI& ot) = delete;

    void start();
};