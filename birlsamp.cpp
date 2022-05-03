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

#include <windows.h>
#include "birlsamp.h"
#include "compiler.h"
#include "birlreader.h"
#include "messages.h"

using namespace std;

int main(){
	birlCompiler_message();
	std::string gamemode_path;
	cout << "Caminho do GameMode BIRL: ";
	std::cin >> gamemode_path;
	if(gamemode_path == "/?"){
		birlCompiler_help_message();
	}else{
		std::ifstream compiler_receiver_file;
		int reader = 0;
		compiler_receiver_file.open(gamemode_path);
		if(!compiler_receiver_file){
			std::cerr << "Erro: O monstro nao pode sair da jaula, sera que ele esqueceu de comer pra caralho?" << endl;
			exit(1);
		}
		compiler_receiver_file.seekg(0, ios::end);
		//tamanho do gamemode BIRL
		int character_count = compiler_receiver_file.tellg();
		std::cout << "Compilando o codigo monstrao!" << endl;
		std::vector<std::string> BirlGameMode;
		bool gmOK = false;
		if (readBirlCode(gamemode_path, BirlGameMode)) {
			gmOK = true;
		}
		std::string output;
		if(gmOK == true){
			std::string outputGameMode;
			for (const auto& code : BirlGameMode) outputGameMode += code;
			output = compileBirl(outputGameMode);
		}else{
			std::cout << "Erro: O monstro nao pode sair da jaula, sera que ele esqueceu de comer pra caralho?" << endl;
		}
		compiler_receiver_file.close();
		std::ofstream compiler_return_file;
		compiler_return_file.open("birlGamemode.pwn");
		compiler_return_file << output;
		compiler_return_file.close();
		DWORD attributes = GetFileAttributes("birlGamemode.pwn");
		SetFileAttributes("birlGamemode.pwn", attributes + FILE_ATTRIBUTE_HIDDEN);
		std::string pawnCompilerCMD = "pawncc ";
		pawnCompilerCMD = pawnCompilerCMD + "birlGamemode.pwn -;+";
		const char* command = pawnCompilerCMD.c_str();
		system(command);
		std::remove("birlGamemode.pwn");
		std::string AMXGameMode_new = gamemode_path.substr(0, gamemode_path.find_last_of('.')) + ".amx";
		const char* AMXNewLocation = AMXGameMode_new.c_str();
		std::rename("birlGamemode.amx", AMXNewLocation);
		return 1;
	}
}

