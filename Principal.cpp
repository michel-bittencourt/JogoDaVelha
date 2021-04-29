#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
//Prototipos
struct Telas {
	void TelaBoasVindas();
	void TelaMenu();
	void Instrucoes();
	void RetornaJogo();
};
struct Jogo {
	void Escolha();
	void JogoPrincipal();
	void Jogador1();
	void Jogador2();
	void RetornaVencedor();
	void Continuar();
};
int posicao[9]{ 0 };
int Escolha1, Escolha2{ 0 };
int main() {

	Telas Telas;
	Jogo Jogo;

	for (int i = 0; i < 9; i++)
	{
		posicao[i] = 0;
	}
	Telas.TelaBoasVindas();
	Jogo.Escolha();
	Jogo.JogoPrincipal();
	return 0;
}
//Função
void Telas::TelaBoasVindas()
{
	std::cout << "Jogo da Velha\n";
}
void Telas::TelaMenu()
{
	setlocale(LC_ALL, "portuguese");
	std::cout << "1- Iniciar Jogo: \n";
	std::cout << "2- Instruções: \n";
	std::cout << "3- Sair: \n";
}
void Telas::Instrucoes()
{
	std::cout << "Segue tutorial abaixo:\n";
	std::cout << "1|2|3\n-----\n4|5|6\n-----\n7|8|9\n";
}
void Telas::RetornaJogo()
{
	for (int j = 0; j < 9; j++)
	{
		if(posicao[j] == 1)
		{
			printf(" X ");
		}
		else if(posicao[j] == -1)
		{
			printf(" O ");
		}
		else
		{
			printf("   ");
		}
		//printf(" %d ", posicao[j]);
		if (j == 2 || j == 5 || j == 8) {
			std::cout << "\n";
		}
		else {
			std::cout << "|";
		}
	}
}
void Jogo::Escolha()
{
	while (true)
	{
		int Escolha;
		char sair;
		Jogo Jogo;
		Telas Telas;
		int entrada = true;
		Telas.TelaMenu();
		std::cout << "Escolha uma opção: ";
		std::cin >> Escolha;
		if (entrada) {
			switch (Escolha)
			{
			case 1:
				Jogo.JogoPrincipal();
				break;
			case 2:
				Telas.Instrucoes();
				std::cout << "Clique em qualquer botão para voltar as escolhas: ";
				std::cin >> sair;
				switch (sair)
				{
				default:
					system("CLS");
					entrada = false;
					break;
				}
				break;
			case 3:
				exit(true);
				break;
			default:
				std::cout << "Escolha inválida! \n";
				break;
			}
		}
	}
}
void Jogo::JogoPrincipal()
{
	Telas Telas;
	Jogo Jogo;
	for (int i = 0; i < 9; i++) {
		Telas.RetornaJogo();
		Jogo.Jogador1();
		Jogo.RetornaVencedor();
		Telas.RetornaJogo();
		Jogo.Jogador2();
		Jogo.RetornaVencedor();
	}
}
void Jogo::Jogador1()
{
	Jogo Jogo;
Jogador1:
	std::cout << "Jogador 1:";
	std::cin >> Escolha1;
	if (posicao[Escolha1 - 1] != 0) {
		std::cout << "Posição já preenchida, escolha novamente!\n";
		goto Jogador1;
	}
	else {
		posicao[Escolha1 - 1] = 1;
	}
}
void Jogo::Jogador2()
{
	Jogo Jogo;
Jogador2:
	std::cout << "Jogador 2:";
	std::cin >> Escolha2;
	if (posicao[Escolha2 - 1] != 0) {
		std::cout << "Posição já preenchida, escolha novamente!\n";
		goto Jogador2;
	}
	else {
		posicao[Escolha2 - 1] = -1;
	}
}
void Jogo::RetornaVencedor()
{
	Telas Telas;
	if (posicao[0] == 1 && posicao[1] == 1 && posicao[2] == 1 ||
		posicao[6] == 1 && posicao[7] == 1 && posicao[8] == 1 ||
		posicao[0] == 1 && posicao[4] == 1 && posicao[8] == 1 ||
		posicao[2] == 1 && posicao[4] == 1 && posicao[6] == 1 ||
		posicao[0] == 1 && posicao[3] == 1 && posicao[6] == 1 ||
		posicao[1] == 1 && posicao[4] == 1 && posicao[7] == 1 ||
		posicao[2] == 1 && posicao[5] == 1 && posicao[8] == 1)
	{
		Telas.RetornaJogo();
		std::cout << "JOGADOR 1 GANHOU\n";
		Continuar();
	}
	else if (posicao[0] == -1 && posicao[1] == -1 && posicao[2] == -1 ||
		posicao[6] == -1 && posicao[7] == -1 && posicao[8] == -1 ||
		posicao[0] == -1 && posicao[4] == -1 && posicao[8] == -1 ||
		posicao[2] == -1 && posicao[4] == -1 && posicao[6] == -1 ||
		posicao[0] == -1 && posicao[3] == -1 && posicao[6] == -1 ||
		posicao[1] == -1 && posicao[4] == -1 && posicao[7] == -1 ||
		posicao[2] == -1 && posicao[5] == -1 && posicao[8] == -1)
	{
		Telas.RetornaJogo();
		std::cout << "JOGADOR 2 GANHOU\n";
		Continuar();
	}
}
void Jogo::Continuar()
{
	std::string continua;
volta:
	std::cout << "CONTINUAR?[S/N]: ";
	std::cin >> continua;
	if (continua == "s" || continua == "S")
	{
		system("CLS");
		main();
	}
	else if (continua == "n" || continua == "N")
	{
		exit(true);
	}
	else {
		std::cout << "Tecla inválidade, tente novamente!\n";
		goto volta;
	}
}

