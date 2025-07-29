#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <stdexcept>

namespace config {

    enum class PropertyType {
        Integer,
        Float,
        Bool,
        String,
        Array
    };

    class Property;
    
    using property_ptr = std::shared_ptr<Property>;
    using property_map = std::unordered_map<std::string, property_ptr>;

    class Property {
    public:
        virtual ~Property() = default;

        virtual PropertyType get_type() const = 0;

        virtual int to_int() const {
            throw std::runtime_error("Property is not an integer");
        }

        virtual float to_float() const {
            throw std::runtime_error("Property is not a float");
        }

        virtual bool to_bool() const {
            throw std::runtime_error("Property is not a bool");
        }

        virtual std::string to_string() const {
            throw std::runtime_error("Property is not a string");
        }

        virtual const std::vector<property_ptr>& to_array() const {
            throw std::runtime_error("Property is not an array");
        }

        virtual void add(const property_ptr&) {
            throw std::runtime_error("Cannot add to non-array property");
        }
    };

    // Integer
    class IntegerProperty : public Property {
        int value;
    public:
        explicit IntegerProperty(int val) : value(val) {}

        PropertyType get_type() const override { return PropertyType::Integer; }
        int to_int() const override { return value; }
    };

    // Float
    class FloatProperty : public Property {
        float value;
    public:
        explicit FloatProperty(float val) : value(val) {}

        PropertyType get_type() const override { return PropertyType::Float; }
        float to_float() const override { return value; }
    };

    // Bool
    class BoolProperty : public Property {
        bool value;
    public:
        explicit BoolProperty(bool val) : value(val) {}

        PropertyType get_type() const override { return PropertyType::Bool; }
        bool to_bool() const override { return value; }
    };

    // String
    class StringProperty : public Property {
        std::string value;
    public:
        explicit StringProperty(std::string val) : value(std::move(val)) {}

        PropertyType get_type() const override { return PropertyType::String; }
        std::string to_string() const override { return value; }
    };

    // Array
    class ArrayProperty : public Property {
        std::vector<property_ptr> items;
        PropertyType element_type;
    public:
        explicit ArrayProperty(std::vector<property_ptr> children);

        PropertyType get_type() const override { return PropertyType::Array; }
        const std::vector<property_ptr>& to_array() const override { return items; }

        void add(const property_ptr& child) override;
    };

} // namespace config
