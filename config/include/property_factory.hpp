#pragma once

#include "property.hpp"
#include "token.hpp"

#include <unordered_map>
#include <typeindex>
#include <functional>

namespace config {

class PropertyFactory {
private:
    using creator_function = std::function<property_ptr(const std::string &)>;
    std::unordered_map<std::type_index, creator_function> table;
public:
    PropertyFactory();

    property_ptr create(const token_ptr &token);
};

}