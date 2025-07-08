#ifndef CONTABANCO_H
#define CONTABANCO_H
#include <iostream>
#include <cctype>

class ContaBanco{
public:
    int numConta;

    //Metodos:

    void abrir_conta(std::string t);
    void fechar_conta();
    void depositar(float d);
    void sacar(float s);
    void pagamento_mensal();
    void estadoAtual();
    ContaBanco();

    // Metodos especiais

    // Metodos GET:
    int getNumConta();
    std::string getTipo();
    std::string getDono();
    float getSaldo();
    bool getStatus();

    // Metodos SET:
    void setNumConta(int n);
    void setTipo(std::string t);
    void setDono(std::string d);
    void setSaldo(float s);
    void setStatus(bool st);
protected:
    std::string tipo; // CP - CONTA POUPANÇA | CC - CONTA CORRENTE
private:
    std::string dono;
    float saldo;
    bool status;
};

//Construtor
ContaBanco::ContaBanco(){
    this->setStatus(false);
    this->setSaldo(0);
    this->setNumConta(1);
}
int ContaBanco::getNumConta(){
    return numConta;
}

std::string ContaBanco::getTipo(){
    return tipo;
}

std::string ContaBanco::getDono(){
    return dono;
}

float ContaBanco::getSaldo(){
    return saldo;
}

bool ContaBanco::getStatus(){
    return status;
}

void ContaBanco::setNumConta(int n){
    numConta = n;
}

void ContaBanco::setTipo(std::string t) {
    for (int i = 0; i <= t.length(); i++) {
        t[i] = toupper(t[i]);
    }

    if (t == "CC" || t == "CP") {
        tipo = t;
        std::cout << "Você escolheu: " << this->getTipo() << std::endl;
    } else {
        std::cout << "Tipo de conta inválido. Use 'cc' ou 'cp'." << std::endl;
    }
}


void ContaBanco::setDono(std::string d){
    dono = d;
}

void ContaBanco::setSaldo(float s){
    if(saldo <= s){
        saldo = s;
    }
    else{
        std::cout << "Erro: Saldo não pode ser negativo" << std::endl;
    }
}

void ContaBanco::setStatus(bool st){
    status = st;
}

void ContaBanco::abrir_conta(std::string t){
    setStatus(true);
    this->setTipo(t);
    if(t == "cp"){
        this->setSaldo(50);
    }
    else if(t == "cc"){
        this->setSaldo(150);
    }
    std::cout << "Conta aberta com sucesso!" << std::endl;


}
void ContaBanco::fechar_conta(){
    if(this->getSaldo() > 0){
        std::cout << "Voce ainda tem R$: " << getSaldo() << "Sua conta não pode ser fechada" << std::endl;
    }
    else if(this->getSaldo() < 0){
        std::cout << "Você tem debito em conta ainda! \n Saldo: " << getSaldo() << std::endl;
    }
    else{
        this->setStatus(false);
        std::cout << "Conta fechada com sucesso!" << std::endl;
    }
}

void ContaBanco::depositar(float d){
    if(this->getStatus()){
        this->setSaldo(getSaldo() + d);
        std::cout << "Saldo realizado na conta de: " << this->getDono() << std::endl;
    }
    else{
        std::cout << "Sua conta está desativada!" << std::endl;
    }
}

void ContaBanco::sacar(float s){
    if(getStatus()){
        if(getSaldo() <= 0){
            std::cout << "Você não tem saldo para sacar!" << std::endl;
        }
        else{
            this->setSaldo(this->getSaldo() - s);
            std::cout << "Olá " << this->getDono() << "!\n" << std::endl;
            std::cout << "Você sacou: " << getSaldo() << std::endl;
        }
    }
    else{
        std::cout << "Sua conta ainda está fechada! \n Status da conta: " << getStatus() << std::endl;
    }
}

void ContaBanco::pagamento_mensal(){
    float taxa = (getTipo() == "cc") ? 12.0f : 20.0f;
if(getStatus()){
    if(getSaldo() >= taxa){
        setSaldo(getSaldo() - taxa);

        std::cout << "Pagamento mensal efetuado!" << "seu saldo é de: " << getSaldo() << std::endl; 
    }
    else{
        std::cout << "Pagamento mensal não efetuado! \n Saldo indisponivel!" << std::endl;
        setStatus(false);
        std::cout << "Sua conta foi fechada!" << std::endl;
    }
}
else{
    std::cout << "Sua conta está fechada!! - Impossivel fazer o pagamento mensal" << std::endl;
}
}

void ContaBanco::estadoAtual(){
    std::cout << "Conta: " << this->getNumConta() << std::endl;
    std::cout << "Dono: " << this->getDono() <<  std::endl;
    std::cout << "Saldo: " << this->getSaldo() <<  std::endl;
    std::cout << "Status: " << this->getStatus() <<  std::endl;
    std::cout << "Tipo: " << this->getTipo() <<  std::endl;
}

#endif