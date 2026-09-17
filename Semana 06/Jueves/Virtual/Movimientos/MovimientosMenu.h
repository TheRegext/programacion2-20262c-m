#pragma once
#include "Menu.h"
#include "MovimientosManager.h"

class MovimientosMenu: public Menu
{
    public:
        MovimientosMenu();
        void run();
    protected:

    private:
    MovimientosManager _movimientoManager;
};
