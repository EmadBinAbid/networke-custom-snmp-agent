#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class SnmpConfGenerator
{
    private:
        int numberOfCommands;
        string fullConfString;

    public:
        SnmpConfGenerator();

        static string getTemplateString();
        void resetConf();
        void addCommand(string cmd);
        void registerConf();
};