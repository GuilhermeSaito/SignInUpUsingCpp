#include "save.hpp"

Save::Save()
{
}
Save::~Save()
{
}

bool Save::savePessoa(Pessoa *p)
{
    std::ifstream in("../save/save.json");
    // Testa se o arquivo existe ou estah vazio
    if (!in || isEmpty(in))
    {
        // Se nao existir, quer dizer que eh o primeiro save
        std::ofstream out("../save/save.json", ios::out | ios::trunc);
        json jSave = json::object();
        json jArray = json::array();
        json j = json::object();

        j["nome"] = p->getNome();
        j["cpf"] = p->getCpf();
        j["rg"] = p->getRg();
        j["dataNascimento"] = p->getDataNascimento();
        j["naturalidade"] = p->getNaturalidade();
        j["estadoNascimento"] = p->getEstadoNascimento();
        j["genero"] = p->getGenero();
        j["estadoCivil"] = p->getEstadoCivil();
        j["cep"] = p->getCep();
        j["numeroCasa"] = p->getNumeroCasa();
        j["telefoneResidencial"] = p->getTelefoneResidencial();
        j["telefoneCelular"] = p->gettelefoneCelular();
        j["email"] = p->getEmail();
        j["senha"] = p->getSenha();
        jArray.push_back(j);
        jSave["clientes"] = jArray;

        try
        {
            out << std::setw(4) << jSave << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "[!] Erro no salvamento do arquivo ../save/save.json.";
            std::cerr << e.what() << '\n';
            return false;
        }
        out.close();
        in.close();
        return true;
    }

    json jtemp = json::object();
    try
    {
        in >> jtemp;
    }
    catch (json::exception &e)
    {
        std::cerr << "[!] Erro na leitura do arquivo ../save/save.json." << std::endl;
        std::cerr << e.what() << std::endl;
        return false;
    }
    in.close();

    json jSave = json::object();
    json jArray = json::array();
    json j = json::object();

    for (auto &s : jtemp["clientes"])
        jArray.push_back(s);

    j["nome"] = p->getNome();
    j["cpf"] = p->getCpf();
    j["rg"] = p->getRg();
    j["dataNascimento"] = p->getDataNascimento();
    j["naturalidade"] = p->getNaturalidade();
    j["estadoNascimento"] = p->getEstadoNascimento();
    j["genero"] = p->getGenero();
    j["estadoCivil"] = p->getEstadoCivil();
    j["cep"] = p->getCep();
    j["numeroCasa"] = p->getNumeroCasa();
    j["telefoneResidencial"] = p->getTelefoneResidencial();
    j["telefoneCelular"] = p->gettelefoneCelular();
    j["email"] = p->getEmail();
    j["senha"] = p->getSenha();
    jArray.push_back(j);
    jSave["clientes"] = jArray;

    std::ofstream out("../save/save.json", ios::out | ios::trunc);
    try
    {
        out << std::setw(4) << jSave << std::endl;
    }
    catch (std::ofstream::failure e)
    {
        std::cerr << "[!] Erro no salvamento do arquivo ../save/save.json.";
        std::cerr << e.what() << '\n';
        return false;
    }
    out.close();

    return true;
}

json Save::recoverPessoa(const std::string email, const std::string senha)
{
    std::ifstream in("../save/save.json");
    // Testa se o arquivo existe
    if (!in)
    {
        std::cout << "There is no save!" << std::endl;
        exit(1);
    }
    if (isEmpty(in))
    {
        std::cout << "There is no save!" << std::endl;
        json temp;
        return temp;
    }

    json jtemp = json::object();
    try
    {
        in >> jtemp;
    }
    catch (json::exception &e)
    {
        std::cerr << "[!] Erro na leitura do arquivo ../save/save.json." << std::endl;
        std::cerr << e.what() << std::endl;
        return false;
    }
    in.close();

    for (auto &j : jtemp["clientes"])
        if ((j["email"] == email) && (j["senha"] == senha))
            return j;
    std::cout << "Didn't find the person with email: " << email << "\tWith the password" << std::endl;

    json temp;
    return temp;
}

bool Save::isEmpty(std::ifstream &in)
{
    return in.peek() == std::ifstream::traits_type::eof();
}