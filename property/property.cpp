#include "property.hpp"

namespace config {

    static void validate_array_type(const std::vector<property_ptr>& items) {
        if (items.empty()) return;
        PropertyType first = items[0]->get_type();
        for (const auto& item : items) {
            if (item->get_type() != first) {
                throw std::runtime_error("All elements in the array must have the same type");
            }
        }
    }

    ArrayProperty::ArrayProperty(std::vector<property_ptr> children) {
        validate_array_type(children);
        if (!children.empty()) {
            element_type = children[0]->get_type();
        }
        items = std::move(children);
    }

    void ArrayProperty::add(const property_ptr& child) {
        if (items.empty()) {
            element_type = child->get_type();
        } else if (child->get_type() != element_type) {
            throw std::runtime_error("Cannot add element of different type to array");
        }
        items.push_back(child);
    }

}