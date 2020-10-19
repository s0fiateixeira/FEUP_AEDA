#include "parque.h"
#include <vector>

using namespace std;

ParqueEstacionamento::ParqueEstacionamento(unsigned int lot, unsigned int nMaxCli):lotacao(lot), numMaximoClientes(nMaxCli)
{
    vagas = lot;
}

unsigned ParqueEstacionamento::getNumLugares() const
{
    return(lotacao);
}

unsigned ParqueEstacionamento::getNumMaximoClientes() const
{
    return(numMaximoClientes);
}

int ParqueEstacionamento::posicaoCliente(const string & nome) const
{
    for (int i = 0; i < clientes.size(); i++)
    {
        if (nome == clientes[i].nome) {
            return (i);
        }
    }
    return (-1);
}

bool ParqueEstacionamento::adicionaCliente(const string & nome)
{
    if ((clientes.size() < numMaximoClientes) && ((vagas > 0) || (clientes[posicaoCliente(nome)].presente == false) || (posicaoCliente(nome) == (-1))))
    {
        InfoCartao newcard;
        newcard.nome = nome;
        newcard.presente = false;       //by default the client is outside the parking lot
        clientes.push_back(newcard);
        return(true);
    }
    else
    {
        return(false);
    }
}

bool ParqueEstacionamento::entrar(const string & nome)
{
    if (posicaoCliente(nome) != (-1))
    {
        if (clientes[posicaoCliente(nome)].presente == false)
        {
            if (vagas != 0)
            {
                clientes[posicaoCliente(nome)].presente = true;
                vagas -= 1;
                return (true);
            }
        }
    }
    return (false);
}

bool ParqueEstacionamento::retiraCliente(const string &nome)
{
    if (clientes[posicaoCliente(nome)].presente == false)
    {
        if (posicaoCliente(nome) == (-1))
        {
            return (false);
        } else
        {
            clientes.erase(clientes.begin() + posicaoCliente(nome));
            return (true);
        }
    }
    return (false);
}

bool ParqueEstacionamento::sair(const string &nome)
{
    if (nome != clientes[posicaoCliente(nome)].nome || clientes[posicaoCliente(nome)].presente == false)
    {
        return (false);
    }
    clientes[posicaoCliente(nome)].presente = false;
    vagas += 1;
    return (true);
}

unsigned ParqueEstacionamento::getNumLugaresOcupados() const
{
    return(lotacao - vagas);
}

unsigned ParqueEstacionamento::getNumClientesAtuais() const
{
    return(clientes.size());
}