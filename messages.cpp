/**
*	**
*
*	BIRLSAMP
*
*	Copyright (c) 2022. Arthur 'ArTDsL' Dias dos Santos Lasso.
*	All Rights Reserved. This software is distributed for free
*	on GitHub under MIT license.
*
*	Last Update: 12/04/2022 (d/m/y)
*
*	**
*/

#include "messages.h"

using namespace std;

void birlCompiler_message() {
	std::cout << "----------------------------------------------" << endl;
	std::cout << "|                  BIRL SAMP                 |" << endl;
	std::cout << "|                                            |" << endl;
	std::cout << "|          Copyright (c) 2022. ArTDsL.       |" << endl;
	std::cout << "----------------------------------------------\n" << endl;
	//
	std::cout << "Caso queira ver os argumentos disponiveis digite /? ao inves do caminho do Game Mode.\n" << endl;
}

void birlCompiler_help_message() {
	clear_console();
	std::cout << "BIRLSAMP V1.0\t\t\t\t\t\t\t\t\t Copyright (c) 2022. ArTDsL.\n" << endl;
	std::cout << "Como usar: birlsamp <comando> [parametro]\n" << endl;
	std::cout << "Opcoes:" << endl;
	std::cout << "\t-f <local_arquivo> \t| <local_arquivo> Local do arquivo birl (arquivo .birl que sera convertido)." << endl;
	std::cout << "\t-a <local_arquivo> \t| <local_arquivo> Local do arquivo amx (saida do arquivo .AMX apos a compilacao)." << endl;
	std::cout << "\t-rv <local_arquivo> \t| Local do arquivo pwn (rv: reverso, transforma .pwn em .birl)" << endl;
	std::cout << "\t-ex <local_arquivo> \t| Executa o samp-server.exe apos a compilacao" << endl;
	std::cout << "\t-dep \t\t\t| Ativa a maquina de depuracao do pawn.\n\n\n" << endl;
	std::cout << "As opcoes devem ser separadas por \"-\" (traco) e espaco, sendo \"-f gamemode.birl -a gamemode.amx\"" << endl;
	std::cout << "e assim em diante... Nao utilize as \"\" (aspas), elas sao somente para explicacao.\n\n\n" << endl;
	std::cout << "BIRLSAMP V1.0\t\t\t\t\t\t\t\t\t Copyright (c) 2022. ArTDsL.\n\n\n\n\n\n\n\n\n" << endl;
	system("pause");
}