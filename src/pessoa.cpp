#include "pessoa.hpp"

Pessoa::Pessoa(const std::string n,
               const std::string c,
               const std::string r,
               const std::string dN,
               const std::string nat,
               const std::string eN,
               const std::string g,
               const std::string eC,
               const std::string cp,
               const int nC,
               const std::string tR,
               const std::string tC,
               const std::string em,
               const std::string se) : nome(n),
                                       cpf(c),
                                       rg(r),
                                       dataNascimento(dN),
                                       naturalidade(nat),
                                       estadoNascimento(eN),
                                       genero(g),
                                       estadoCivil(eC),
                                       cep(cp),
                                       numeroCasa(nC),
                                       telefoneResidencial(tR),
                                       telefoneCelular(tC),
                                       email(em),
                                       senha(se)
{
}
Pessoa::~Pessoa()
{
}

const std::string Pessoa::getNome() const { return nome; }
const std::string Pessoa::getCpf() const { return cpf; }
const std::string Pessoa::getRg() const { return rg; }
const std::string Pessoa::getDataNascimento() const { return dataNascimento; }
const std::string Pessoa::getNaturalidade() const { return naturalidade; }
const std::string Pessoa::getEstadoNascimento() const { return estadoNascimento; }
const std::string Pessoa::getGenero() const { return genero; }
const std::string Pessoa::getEstadoCivil() const { return estadoCivil; }
const std::string Pessoa::getCep() const { return cep; }
const int Pessoa::getNumeroCasa() const { return numeroCasa; }
const std::string Pessoa::getTelefoneResidencial() const { return telefoneResidencial; }
const std::string Pessoa::gettelefoneCelular() const { return telefoneCelular; }
const std::string Pessoa::getEmail() const { return email; }
const std::string Pessoa::getSenha() const { return senha; }