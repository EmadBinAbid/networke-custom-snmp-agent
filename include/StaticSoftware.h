#pragma once

#include <iostream>

#include "Program.h"

using namespace std;

class StaticSoftware : public Program
{
    inline static string versionNumber = "6.1.1";
    public:
        string getVersionNumber()
        {
            return StaticSoftware::versionNumber;
        }
};