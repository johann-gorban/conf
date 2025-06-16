#pragma once

#include "property.hpp"
#include "token.hpp"

#include <unordered_map>
#include <typeindex>
#include <functional>
#include <vector>

namespace config {

class PropertyFactory {
private:
    using creator_function = std::function<property_ptr(const std::string &)>;
    std::unordered_map<std::type_index, creator_function> table;
public:
    PropertyFactory();

    property_ptr create(const token_ptr &token);

    property_ptr create(const std::vector<token_ptr> &token_array);
};

}