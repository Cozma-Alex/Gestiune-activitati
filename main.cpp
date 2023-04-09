#include <iostream>
#include "Console/ui.h"
#include "Tests/tests.h"
#include "Validator/validate.h"

int main() {
    test_all();
    RepoActivitate repo;
    Activitate_Validator valid;
    ServiceActivitate service{repo, valid};
    ConsoleUI ui{service};
    ui.start();

}
