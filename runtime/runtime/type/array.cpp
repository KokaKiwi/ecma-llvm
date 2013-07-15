#include <string>
#include <sstream>
#include "ecma/runtime/capi.h"
#include "ecma/runtime/object.h"
#include "ecma/runtime/type/array.h"

using namespace ecma;
using namespace ecma::runtime;
using namespace ecma::runtime::type;

Array *Ecma_Array_create(int size, Object **elems)
{
    return new Array(size, elems);
}

Array::Array(int size, Object **elems)
{
    for (int i = 0; i < size; i++)
    {
        m_elems.push_back(elems[i]);
    }
}

std::string Array::toString(void) const
{
    std::stringstream ss;
    int i = 0;

    ss << "[";

    for (Object *elem : m_elems)
    {
        ss << elem->toString();
        if (i < m_elems.size() - 1)
        {
            ss << ", ";
        }
        i++;
    }

    ss << "]";
    return ss.str();
}
