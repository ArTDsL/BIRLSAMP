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

#include <iostream>

void birlCompiler_message();
void birlCompiler_help_message();

void clear_console(){
    #if defined _WIN32
        system("cls");
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        system("clear");
    #elif defined (__APPLE__)
        system("clear");
    #endif
}