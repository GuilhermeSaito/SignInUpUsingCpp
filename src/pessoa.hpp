#pragma once

#include <iostream>

class Pessoa
{
private:
    std::string nome;
    std::string cpf;
    std::string rg;
    std::string dataNascimento;
    std::string naturalidade;
    std::string estadoNascimento;
    std::string genero;
    std::string estadoCivil;
    std::string cep;
    const int numeroCasa;
    std::string telefoneResidencial;
    std::string telefoneCelular;
    std::string email;
    std::string senha;

public:
    Pessoa(const std::string n = "",
           const std::string c = "",
           const std::string r = "",
           const std::string dN = "",
           const std::string nat = "",
           const std::string eN = "",
           const std::string g = "",
           const std::string eC = "",
           const std::string cp = "",
           const int nC = -1,
           const std::string tR = "",
           const std::string tC = "",
           const std::string em = "",
           const std::string se = "");
    ~Pessoa();

    const std::string getNome() const;
    const std::string getCpf() const;
    const std::string getRg() const;
    const std::string getDataNascimento() const;
    const std::string getNaturalidade() const;
    const std::string getEstadoNascimento() const;
    const std::string getGenero() const;
    const std::string getEstadoCivil() const;
    const std::string getCep() const;
    const int getNumeroCasa() const;
    const std::string getTelefoneResidencial() const;
    const std::string gettelefoneCelular() const;
    const std::string getEmail() const;
    const std::string getSenha() const;
};