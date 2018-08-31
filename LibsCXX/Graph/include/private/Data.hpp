#ifndef NODE_DATA_HPP
#define NODE_DATA_HPP

#include <string>

class Data {
public:
    virtual ~Data() {}
    virtual std::string toString() const = 0;
    virtual bool equals(const Data *obj) const = 0;
    virtual int hashCode() const = 0;
};


#endif //NODE_DATA_HPP
