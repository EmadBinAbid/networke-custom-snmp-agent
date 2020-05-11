#pragma once

#include <iostream>
#include <boost/filesystem.hpp>
#include <boost/range/numeric.hpp>

#include "Program.h"

using namespace std;

namespace fs = boost::filesystem;

class System : public Program
{
    public:
        static size_t getDiskSpace(fs::path folderPath);
};