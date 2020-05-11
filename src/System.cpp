#include "../include/System.h"

size_t System::getDiskSpace(fs::path folderPath) {
    return fs::is_regular_file(folderPath)
       ? file_size(folderPath)
       : boost::accumulate(fs::directory_iterator{folderPath}, 0ull, [](auto a, auto folderPath){return a+getDiskSpace(folderPath);});
}