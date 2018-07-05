/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: vardh
 *
 * Created on July 2, 2018, 9:47 PM
 */

#include <cstdlib>
#include "scanner.h"
using namespace std;


int main(int argc, char** argv) {

    token t;
    t.Tokenise("test_input.txt");
    return 0;
}

