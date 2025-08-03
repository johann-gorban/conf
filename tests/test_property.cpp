#include <iostream>
#include <cassert>
#include "property.hpp"

using namespace config;

void test_integer_property() {
    IntegerProperty int_prop(42);

    assert(int_prop.get_type() == PropertyType::Integer);
    assert(int_prop.to_int() == 42);

    try {
        int_prop.to_float();
        assert(false); // Should not reach here
    } 
    catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Property is not a float");
    }
}

void test_float_property() {
    FloatProperty float_prop(3.14f);

    assert(float_prop.get_type() == PropertyType::Float);
    assert(float_prop.to_float() == 3.14f);
}

void test_bool_property() {
    BoolProperty bool_prop(true);

    assert(bool_prop.get_type() == PropertyType::Bool);
    assert(bool_prop.to_bool() == true);
}

void test_string_property() {
    StringProperty str_prop("hello");

    assert(str_prop.get_type() == PropertyType::String);
    assert(str_prop.to_string() == "hello");
}

void test_array_property_creation() {
    auto p1 = std::make_shared<IntegerProperty>(1);
    auto p2 = std::make_shared<IntegerProperty>(2);
    auto p3 = std::make_shared<IntegerProperty>(3);

    ArrayProperty arr({p1, p2, p3});

    assert(arr.get_type() == PropertyType::Array);

    const auto& items = arr.to_array();

    assert(items.size() == 3);
    assert(items[0]->to_int() == 1);
}

void test_array_property_add_valid() {
    ArrayProperty arr({});

    arr.add(std::make_shared<FloatProperty>(1.1f));
    arr.add(std::make_shared<FloatProperty>(2.2f));

    const auto& items = arr.to_array();

    assert(items.size() == 2);
    assert(items[0]->to_float() == 1.1f);
    assert(items[1]->to_float() == 2.2f);
}

void test_array_property_add_invalid() {
    ArrayProperty arr({});

    arr.add(std::make_shared<BoolProperty>(true));

    try {
        arr.add(std::make_shared<StringProperty>("bad"));
        assert(false);
    } 
    catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "Cannot add element of different type to array");
    }
}

void test_array_property_type_mismatch_on_creation() {
    auto p1 = std::make_shared<IntegerProperty>(1);
    auto p2 = std::make_shared<FloatProperty>(2.5f);
    
    try {
        ArrayProperty arr({p1, p2});
        assert(false);
    } 
    catch (const std::runtime_error& e) {
        assert(std::string(e.what()) == "All elements in the array must have the same type");
    }
}

int main() {
    test_integer_property();
    test_float_property();
    test_bool_property();
    test_string_property();
    test_array_property_creation();
    test_array_property_add_valid();
    test_array_property_add_invalid();
    test_array_property_type_mismatch_on_creation();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}
