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

#pragma once

#include "birlreader.h"

bool readBirlCode(const std::string& gamemode, std::vector<std::string>& gmLines){
	std::ifstream compiler_receiver_file(gamemode);
	if(!compiler_receiver_file){
		return false;
	}
	std::string gamemodeLine;
	while(std::getline(compiler_receiver_file, gamemodeLine)){
		gmLines.push_back(gamemodeLine + "\n");
	}
	if(!compiler_receiver_file.bad()){
		return true;
	}else{
		return false;
	}
}