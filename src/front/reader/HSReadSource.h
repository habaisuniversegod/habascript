#pragma once

#include <string>

class HSReadSource {
    std::string full_text;
    uint64_t position = 0;

public:
    HSReadSource();
    ~HSReadSource();

    void read(const std::string& path, int module_id);
    const std::string& get_text() const;
    void clear();
};