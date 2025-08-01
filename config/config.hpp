#pragma once

#include "property.hpp"
#include <string>
#include <unordered_map>

namespace config {

    class ConfigProcessor {
    private:
        std::string config_path;
        property_map properties;
    public:
        explicit ConfigProcessor(const std::string& path);

        void process();

        void clear();

        property_ptr get(const std::string& name) const;
    };

}
