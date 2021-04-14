#pragma once

#include <fstream>
#include <iomanip>

#include "pessoa.hpp"
#include "../nlohmann/json.hpp"

using std::ios;

using json = nlohmann::json;

class Save
{
public:
    Save();
    ~Save();

    bool savePessoa(Pessoa *p);
    json recoverPessoa(const std::string email = "", const std::string senha = "");

private:
    bool isEmpty(std::ifstream &in);
};