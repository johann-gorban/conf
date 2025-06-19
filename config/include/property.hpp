#pragma once

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

namespace config {

    class Property;

    using property_ptr = std::shared_ptr<Property>;

    using property_map = std::unordered_map<std::string, property_ptr>;

}

namespace config {

class Property {
private:    
    const std::string data;
public:
    explicit Property(const std::string &data = "");

    virtual ~Property() = default;
public:
    const std::string get_data() const;

    virtual void add(const property_ptr &property);

    virtual int to_int() const;
    
    virtual bool to_bool() const;
    
    virtual float to_float() const;

    virtual std::string to_string() const;

    virtual std::vector<property_ptr> to_array() const;
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

class ArrayProperty : public Property {
private:
    std::vector<property_ptr> childs;
public:
    explicit ArrayProperty(const std::vector<property_ptr> &properties);
public:
    std::vector<property_ptr> to_array() const override;

    void add(const property_ptr &property) override;
};

}

