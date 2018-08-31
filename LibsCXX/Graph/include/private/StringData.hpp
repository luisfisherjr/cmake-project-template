#ifndef STRING_DATA_HPP
#define STRING_DATA_HPP

#include <boost/functional/hash.hpp>
#include "Data.hpp"

class StringData : public Data {

private:

    std::string *data;

public:

    StringData(std::string *data) {
        this->data = data;
    }

    ~StringData() {}

    std::string toString() const {
        return *data;
    }

    bool equals(const Data *obj) const {
        return this->hashCode() == obj->hashCode();
    }

    virtual int hashCode() const {
        boost::hash<std::string> string_hash;
        return string_hash(*data);
    }
};

#endif //STRING_DATA_HPP
