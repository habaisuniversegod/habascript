#include "HSReadSource.h"
#include "../../HSGlobals.h"
#include <fstream>
#include "../../HSErrorPrinter.h"

HSReadSource::HSReadSource()
{
}

HSReadSource::~HSReadSource()
{
}

void HSReadSource::read(const std::string &path, int module_id)
{
    std::ifstream src_file(path, std::ios::in);
    if (!src_file){
        HS_ERR_SRCREADERROR(-1, module_id, path.c_str());
    }

    for (std::string line; std::getline(src_file, line);){
        full_text += line + '\n';
    }
}

const std::string &HSReadSource::get_text() const
{
    return full_text;
}

void HSReadSource::clear()
{
    full_text.clear();
    full_text.shrink_to_fit();
}
