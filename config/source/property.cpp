#include "property.hpp"

namespace config {

Property::Property(const std::string &data) 
    : data(data) {}

const std::string Property::get_data() const {
    return this->data;
}

IntegerProperty::IntegerProperty(const std::string &data) 
    : Property(data) {}

int IntegerProperty::to_int() const {
    const std::string &data = this->get_data();
    return std::stoi(data);
}

FloatProperty::FloatProperty(const std::string &data) 
    : Property(data) {}

float FloatProperty::to_float() const {
    const std::string &data = this->get_data();
    return std::stof(data);
}

BoolProperty::BoolProperty(const std::string &data) 
    : Property(data) {}

bool BoolProperty::to_bool() const {
    const std::string &data = this->get_data();
    return (data == "true") ? true : false;
}

StringProperty::StringProperty(const std::string &data) 
    : Property(data) {}

std::string StringProperty::to_string() const {
    // May complain about const qualifier
    return this->get_data();
}

}