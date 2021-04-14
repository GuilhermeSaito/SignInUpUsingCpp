#pragma once

#include "save.hpp"

class Menu
{
private:
    Save save;

public:
    Menu();
    ~Menu();

    void executar();

private:
    void signIn();
    void signUp();
};