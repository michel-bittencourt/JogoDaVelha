#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

//Prototipos
struct Telas{
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
};

int posicao[8]{ 0 };

int main() {
	Telas Telas;
	Jogo Jogo;

	Telas.TelaBoasVindas();
	Jogo.Escolha();
	Jogo.JogoPrincipal();
	

	return 0;
}

//Função
void Telas::TelaBoasVindas()
{
	std::cout << "Seja bem vindo ao Jogo da Velha\n"
		"  Criadores: Michel & Paulo\n--------------------------------\n";
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
		printf(" %d ", posicao[j]);
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
				switch(sair)
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

	int Escolha1, Escolha2{ 0 };

	for (int i = 0; i < 9; i++) {
		Telas.RetornaJogo();
		//jogador 1
		Jogo.Jogador1();
		//jogador 2
		

	}
}

void Jogo::Jogador1()
{
	bool saida = true;
	while (saida)
	{
		std::cout << "Jogador 1: ";
		std::cin >> Escolha1;
		if (Escolha1 == -1 && Escolha1 == 1) { saida= false; }
		else
		{
			posicao[Escolha1 - 1] = 1;
		}
	}
}

void Jogo::Jogador2()
{
		Telas.RetornaJogo();
		std::cout << "Jogador 2: ";
		std::cin >> Escolha2;
		posicao[Escolha2-1] = -1;
}

