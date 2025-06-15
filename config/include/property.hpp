#pragma once

#include <string>
#include <unordered_map>
#include <memory>

namespace config {

class Property {
private:    
    const std::string data;
public:
    explicit Property(const std::string &data = "");

    virtual ~Property() = default;
public:
    const std::string get_data() const;

    virtual int to_int() const;
    
    virtual bool to_bool() const;
    
    virtual float to_float() const;

    virtual std::string to_string() const;
};

class IntegerProperty : public Property {
public:
    explicit IntegerProperty(const std::string &data = "");
public:
    int to_int() const override;
};

class FloatProperty : public Property {
public:
    explicit FloatProperty(const std::string &data = "");
public:
    float to_float() const override;
};

class BoolProperty : public Property {
public:
    explicit BoolProperty(const std::string &data = "");
public:
    bool to_bool() const override;
};

class StringProperty : public Property {
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