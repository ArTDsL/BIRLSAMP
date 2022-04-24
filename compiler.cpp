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
#include <iterator>
#include <regex>
#include <string>
#include "compiler.h"
#include "stdio.h"
using namespace std;

void replaceBirl(std::string& gamemodeString, std::string const& theBirlCode, std::string const& theCCode){
    std::ostringstream str_stream;
    std::size_t position = 0;
    std::size_t lastPosition = position;
    while(true){
        lastPosition = position;
        position = gamemodeString.find(theBirlCode, position);
        if(position == std::string::npos){
            break;
        }
        str_stream << gamemodeString.substr(lastPosition, position - lastPosition);
        str_stream << theCCode;
        position += theBirlCode.size();
    }
    str_stream << gamemodeString.substr(lastPosition);
    gamemodeString = str_stream.str();
}
std::string compileBirl(std::string birlCode){
	std::string birlCode_Adrress;
	birlCode_Adrress = birlCode;
    //Birl Dictionary
	std::string birlDictionary[] = {
        "0x0D", 
        "\n", 
        "\r\n", 
        "HORA DO SHOW", 
        "BIRL", 
        "CE QUER VER ESSA PORRA?", 
        "BORA", 
        "NOVO", 
        "TRAPEZIO:", 
        "ELE QUE A GENTE QUER?", 
        "NAO VAI DAR NAO", 
        "QUE NAO VAI DAR O QUE?", 
        "VAMO CUMPADE", 
        "NEGATIVA BAMBAM", 
        "MAIS QUERO MAIS", 
        "VAMO MONSTRO", 
        "SAI FILHO DA PUTA", 
        "AUUU", 
        "MONSTRAO", 
        "ELE TA OLHANDO PRA GENTE", 
        "O MONSTRO TA CHEGANDO",
        "CADE ELE PORRA?", 
        "AJUDA O MALUCO QUE TA DOENTE", 
        "OLHA O HOMI ALI", 
        "AVISA LA O HOMI", 
        "AVISA LA AVISA LA ELE", 
        "VAMO INCLUI", 
        "VAMO DEFINI", 
        "E MONSTRO?", 
        "VAI PRO INTERIOR MONSTRO", 
        "OLHA A HORA PORRA", 
        "TA SEM DINHEIRO CUMPADI", 
        "MUTANTE TA CHEIO DA GRANA RAPA",
        "OLHA ALI CUMPADI",
        "VAI LA CUMPADI",
        "PEGA QUALQUER UM",
        "OLHA O TAMANHO",
        "DA UMA ARMA PRO MUTANTE",
        "MATADOR DE MONSTRO",
        "CADE ELE PORRA",
        "QUANTO CE TEM AI?",
        "FILMA AQUI MONSTRO",
        "APONTA A CAMERA PRA CA",
        "E A CAIXA QUE A GENTE QUER",
        "E A LETRA QUE A GENTE QUER",
        "E A FONTE QUE A GENTE QUER",
        "E A SOMBRA QUE A GENTE QUER",
        "E A BORDA QUE A GENTE QUER",
        "E A COR QUE A GENTE QUER",
        "E O FUNDO QUE A GENTE QUER",
        "ESCREVE AI PO:",
        "CHAMA LA PO",
        "E A COR DA CAIXA QUE A GENTE QUER",
        "E O TAMANHO DO TEXTO QUE A GENTE QUER",
        "OLHA AQUI MUTANTE",
        "TEM NADA AQUI NAO PARCEIRO",
        "ESCUTA ISSO AQUI MONSTRO",
        "OLHA O MONSTRO",
        "VAI FICAR SO OLHANDO?",
        "O MOSTRO TA CHEGANDO",
        "A CAMINHADA E ESSA",
        "COMO ELE TA?",
        "SO OLHANDO NE PARCEIRO",
        "FICA DE OLHO NO MONSTRO",
        "COMO QUE CHAMA?",
        "DA PRA ENTRAR EM TUDO?",
        "ESSA REGIAO E TODA ABERTA CUMPADI",
        "VE O NOME DAQUELE MUTANTE ALI",
        "EU NAO VOU GRITAR PRA SABER O NOME DO CARA",
        "SE PATINAR E CAIR GANHA ALGUMA COISA PELO MENOS?",
        "PORTA TA TRANCADA ELE NAO TA EM CASA",
        "BOTA CABECA NA JANELA VE SE VAI CHOVER",
        "VE SE TA CLARO LA FORA",
        "ESCOLHE QULQUER UM AI",
        "O CARRO JA TA LA CUMPADI?",
        "FALA AI O RESULTADO PORRA!",
        "O MUTANTE TA AI?",
        "O QUE ELE TA SEGURANDO?",
        "SAI DAQUI RAPA!",
        "ELE FEZ O QUE?"
    };
	//SAMP-Pawn Translator
    std::string birlConvertedDictionary[] = {
        "0x0D", 
        "\n", 
        "\n", 
        "main(){", 
        "}", 
        "print", 
        "{", 
        "new", 
        "Float:", 
        "if", 
        "else",  
        "else if", 
        "return", 
        "while", 
        "for", 
        "continue", 
        "break", 
        "public", 
        "playerid", 
        "OnGameModeInit", 
        "OnPlayerConnect", 
        "OnPlayerDisconnect", 
        "OnPlayerDeath", 
        "OnPlayerSpawn", 
        "SendClientMessage", 
        "GameTextForPlayer", 
        "#include", 
        "#define", 
        "IsPlayerNPC", 
        "SetPlayerInterior", 
        "TogglePlayerClock", 
        "ResetPlayerMoney", 
        "GivePlayerMoney",
        "SetPlayerFacingAngle",
        "SetPlayerPos",
        "random",
        "sizeof",
        "GivePlayerWeapon",
        "killerid",
        "INVALID_PLAYER_ID",
        "GetPlayerMoney",
        "SetPlayerCameraPos",
        "SetPlayerCameraLookAt",
        "TextDrawUseBox",
        "TextDrawLetterSize",
        "TextDrawFont",
        "TextDrawSetShadow",
        "TextDrawSetOutline",
        "TextDrawColor",
        "TextDrawBackgroundColor",
        "Text:",
        "TextDrawCreate",
        "TextDrawBoxColor",
        "TextDrawTextSize",
        "TextDrawShowForPlayer",
        "TextDrawHideForPlayer",
        "PlayerPlaySound",
        "GetPlayerKeys",
        "TogglePlayerSpectating",
        "OnPlayerRequestClass",
        "classid",
        "GetPlayerState",
        "PLAYER_STATE_SPECTATING",
        "OnPlayerUpdate",
        "SetGameModeText",
        "ShowPlayerMarkers",
        "PLAYER_MARKERS_MODE_GLOBAL",
        "ShowNameTags",
        "SetNameTagDrawDistance",
        "EnableStuntBonusForAll",
        "DisableInteriorEnterExits",
        "SetWeather",
        "SetWorldTime",
        "AddPlayerClass",
        "LoadStaticVehiclesFromFile",
        "printf",
        "IsPlayerConnected",
        "GetPlayerWeapon",
        "Kick",
        "reason"
    };
    int birlDictionarySize = sizeof(birlDictionary) / sizeof(birlDictionary[0]);
    for(int i = 0; i < birlDictionarySize; i++){
	    replaceBirl(birlCode_Adrress, birlDictionary[i], birlConvertedDictionary[i]);
    }
	return birlCode_Adrress;
}