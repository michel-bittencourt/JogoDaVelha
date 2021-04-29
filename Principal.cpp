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
	void Placar();
};
int posicao[9]{ 0 };
int Escolha1, Escolha2{ 0 };
int placarJ1=0;
int placarJ2=0;

int main() {

	Telas Telas;
	Jogo Jogo;

	
	Telas.TelaBoasVindas();
	if(placarJ1==0 && placarJ2==0)
	{
		Jogo.Escolha();
	}
	else
	{
		for (int i = 0; i < 9; i++)
		{
			posicao[i] = 0;
		}
		Jogo.JogoPrincipal();
	}
	return 0;
}
//Função
void Telas::TelaBoasVindas()
{
	Jogo jogo;

	std::cout << "Jogo da Velha\n";
	//std::cout << "Placar: J1:" << placarJ1 <<"J2:" << placarJ2 ;
	jogo.Placar();
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
		char Escolha;
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
			case '1':
				Jogo.JogoPrincipal();
				break;
			case '2':
				Telas.Instrucoes();
				std::cout << "Clique em qualquer botão para voltar as escolhas: ";
				std::cin >> sair;
				switch (sair)
				{
				case ' ':
					break;
				default:
					system("CLS");
					entrada = false;
					break;
				}
				break;
			case '3':
				exit(true);
				break;
			default:
				std::cout << "Escolha inválida! \n";
				system("CLS");
				break;
			}
		}
	}
}
void Jogo::JogoPrincipal()
{
	Telas Telas;
	Jogo Jogo;
	system("CLS");
	Telas.TelaBoasVindas();
	for (int i = 0; i < 9; i++) {
		Telas.RetornaJogo();
		Jogo.Jogador1();
		system("CLS");
		Telas.TelaBoasVindas();
		Jogo.RetornaVencedor();
		Telas.RetornaJogo();
		Jogo.Jogador2();
		system("CLS");
		Telas.TelaBoasVindas();
		Jogo.RetornaVencedor();
	}
}
void Jogo::Jogador1()
{
	Jogador1:
	std::cout << "Jogador 1:";
	std::cin >> Escolha1;

	if (posicao[Escolha1 - 1] != 0) {
		std::cout << "Jogada inválida, escolha novamente!\n";
		goto Jogador1;
	}
	else{
		posicao[Escolha1 - 1] = 1;
	}

}
void Jogo::Jogador2()
{
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
		placarJ1++;
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
		placarJ2++;
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

void Jogo::Placar()
{
	printf("PLACAR: J1: %d  -  J2: %d\n\n", placarJ1, placarJ2);
}