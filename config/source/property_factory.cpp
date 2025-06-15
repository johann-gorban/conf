#include "property_factory.hpp"
#include "token.hpp"

#include <stdexcept>

namespace config {

property_ptr foo(const std::string &data) {
    return std::make_shared<IntegerProperty>(data);
}

PropertyFactory::PropertyFactory() {
    this->table[typeid(IntegerToken)] = [](const std::string &data) {
        return std::make_shared<IntegerProperty>(data);
    };

    this->table[typeid(FloatToken)] = [](const std::string &data) {
        return std::make_shared<FloatProperty>(data);
    };

    this->table[typeid(BoolToken)] = [](const std::string &data) {
        return std::make_shared<BoolProperty>(data);
    };

    this->table[typeid(StringToken)] = [](const std::string &data) {
        return std::make_shared<StringProperty>(data);
    };
}

property_ptr PropertyFactory::create(const token_ptr &token) { 
    if (!token) {
        throw std::runtime_error("Null token provided");
    }

    const std::string &data = token->to_string();

    auto it = this->table.find(typeid(*token));
    if (it == this->table.end()) {
        throw std::runtime_error("No property for such token");
    }

    return it->second(data);
}

}