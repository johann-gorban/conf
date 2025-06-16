#include "property.hpp"

#include <stdexcept>

namespace config {

Property::Property(const std::string &data) 
    : data(data) {}

int Property::to_int() const {
    throw std::runtime_error("Cannot convert to integer");
}

bool Property::to_bool() const {
    throw std::runtime_error("Cannot convert to bool");
}

float Property::to_float() const {
    throw std::runtime_error("Cannot convert to float");
}

std::string Property::to_string() const {
    throw std::runtime_error("Cannot convert to string");
}

std::vector<property_ptr> Property::to_array() const {
    throw std::runtime_error("Cannot convert to array");
}

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

ArrayProperty::ArrayProperty(const std::vector<property_ptr> &properties) {
    this->childs = properties;
}

std::vector<property_ptr> ArrayProperty::to_array() const {
    std::vector<property_ptr> properties;

    for (auto &child : this->childs) {
        if (auto child_array = dynamic_cast<const ArrayProperty *>(child.get())) {
            auto subarray = child_array->to_array();
            properties.insert(properties.end(), subarray.begin(), subarray.end());
        }
        else {
            properties.push_back(child);
        }
    }

    return properties;
}

}