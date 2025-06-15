#pragma once

#include <string>
#include <unordered_map>
#include <memory>

namespace config {

class Property {
private:    
    const std::string data;
protected:
    const std::string get_data() const;
public:
    explicit Property(const std::string &data = "");

    virtual ~Property() = default;
public:
    virtual int to_int() const = 0;
    
    virtual bool to_bool() const = 0;
    
    virtual float to_float() const = 0;

    virtual std::string to_string() const = 0;
};

class IntegerProperty : protected Property {
public:
    explicit IntegerProperty(const std::string &data = "");
public:
    int to_int() const override;
};

class FloatProperty : protected Property {
public:
    explicit FloatProperty(const std::string &data = "");
public:
    float to_float() const override;
};

class BoolProperty : protected Property {
public:
    explicit BoolProperty(const std::string &data = "");
public:
    bool to_bool() const override;
};

class StringProperty : protected Property {
public:
    explicit StringProperty(const std::string &data = "");
public:
    std::string to_string() const override;
};

}

namespace config {

    using property_ptr = std::shared_ptr<Property>;

    using property_map = std::unordered_map<std::string, property_ptr>;

}