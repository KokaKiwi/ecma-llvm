#ifndef ECMA_RUNTIME_OBJECT_H_
#define ECMA_RUNTIME_OBJECT_H_

#include <string>
#include <map>

namespace ecma
{
    namespace runtime
    {
        class Object
        {
        public:
            virtual void setProperty(const std::string &name, Object *value);
            virtual Object *getProperty(const std::string &name);

            virtual void setIndex(Object *index, Object *value);
            virtual Object *getIndex(Object *index);

            virtual Object *call(Object *env, Object *thisValue, int argc, Object **argv);

            virtual std::string toString(void) const;

        private:
            std::map<std::string, Object *> m_properties;
        };
    }
}

#endif /* ECMA_RUNTIME_OBJECT_H_ */
