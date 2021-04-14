#include "menu.hpp"

Menu::Menu()
{
    executar();
}
Menu::~Menu()
{
}

void Menu::executar()
{
    int option = 1;

    while (option != 0)
    {
        std::cout << "Please, chose a option: " << std::endl
                  << "1 - Sign in" << std::endl
                  << "2 - Sign up" << std::endl
                  << "0 - Exit" << std::endl
                  << std::endl
                  << std::endl;
        std::cin >> option;

        switch (option)
        {
        case 1:
            signIn();
            std::cout << std::endl
                      << std::endl
                      << std::endl
                      << std::endl;
            break;

        case 2:
            signUp();
            std::cout << std::endl
                      << std::endl
                      << std::endl
                      << std::endl;
            break;

        case 0:
            std::cout << "Thank you!!" << std::endl;
            break;

        default:
            std::cout << "Invalid option, please, try again!" << std::endl;
            break;
        }
    }
}

void Menu::signIn()
{
    std::string email;
    std::string senha;

    std::cout << "To sign in, please, inform these data: " << std::endl;
    std::cout << "email: " << std::endl;
    std::cin >> email;
    std::cout << "password: " << std::endl;
    std::cin >> senha;

    json j = json::object();
    j = save.recoverPessoa(email, senha);

    if (!j.empty())
    {
        std::cout << "Welcome " << j["nome"] << std::endl;
        std::cout << "How are you? " << std::endl;

        /* Teste para verificar se foi a pessoa mesmo
        std::cout << "Name: " << j["nome"] << std::endl;
        std::cout << "CPF: " << j["cpf"] << std::endl;
        std::cout << "RG: " << j["rg"] << std::endl;
        std::cout << "Birth date: " << j["dataNascimento"] << std::endl;
        std::cout << "Place of birth: " << j["naturalidade"] << std::endl;
        std::cout << "State of birth: " << j["estadoNascimento"] << std::endl;
        std::cout << "Gender: " << j["genero"] << std::endl;
        std::cout << "Martal status: " << j["estadoCivil"] << std::endl;
        std::cout << "CEP: " << j["cep"] << std::endl;
        std::cout << "House's number: " << j["numeroCasa"] << std::endl;
        std::cout << "Home phone: " << j["telefoneResidencial"] << std::endl;
        std::cout << "Cell phone number: " << j["telefoneCelular"] << std::endl;
        */
    }
}

void Menu::signUp()
{
    std::string nome;
    std::string cpf;
    std::string rg;
    std::string dataNascimento;
    std::string naturalidade;
    std::string estadoNascimento;
    std::string genero;
    std::string estadoCivil;
    std::string cep;
    int numeroCasa;
    std::string telefoneResidencial;
    std::string telefoneCelular;
    std::string email;
    std::string senha;

    std::cout << "To sign up, please, inform these datas (press enter after every input): " << std::endl;
    std::cout << "Name: " << std::endl;
    std::cin >> nome;
    std::cout << "CPF: " << std::endl;
    std::cin >> cpf;
    std::cout << "RG: " << std::endl;
    std::cin >> rg;
    std::cout << "Birth date: " << std::endl;
    std::cin >> dataNascimento;
    std::cout << "Place of birth: " << std::endl;
    std::cin >> naturalidade;
    std::cout << "State of birth: " << std::endl;
    std::cin >> estadoNascimento;
    std::cout << "Gender: " << std::endl;
    std::cin >> genero;
    std::cout << "Martal status: " << std::endl;
    std::cin >> estadoCivil;
    std::cout << "CEP: " << std::endl;
    std::cin >> cep;
    std::cout << "House's number: " << std::endl;
    std::cin >> numeroCasa;
    std::cout << "Home phone: " << std::endl;
    std::cin >> telefoneResidencial;
    std::cout << "Cell phone number: " << std::endl;
    std::cin >> telefoneCelular;
    std::cout << "Email: " << std::endl;
    std::cin >> email;
    std::cout << "Password: " << std::endl;
    std::cin >> senha;

    Pessoa *p = new Pessoa(nome,
                           cpf,
                           rg,
                           dataNascimento,
                           naturalidade,
                           estadoNascimento,
                           genero,
                           estadoCivil,
                           cep,
                           numeroCasa,
                           telefoneResidencial,
                           telefoneCelular,
                           email,
                           senha);

    if (save.savePessoa(p))
        std::cout << "Successfully registered person" << std::endl;
    else
        std::cout << "Was not possible to register the person" << std::endl;
}