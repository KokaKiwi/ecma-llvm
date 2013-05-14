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
            virtual Object *getProperty(const std::string &name) const;

            virtual void setIndex(Object *index, Object *value);
            virtual Object *getIndex(Object *index) const;

            virtual Object *call(Object *env, Object *thisValue, int argc, Object **argv);

            virtual bool boolCast(void) const;

            virtual Object *operatorLogicalOr(Object *other) const;
            virtual Object *operatorLogicalAnd(Object *other) const;
            virtual Object *operatorBitwiseOr(Object *other) const;
            virtual Object *operatorBitwiseXor(Object *other) const;
            virtual Object *operatorBitwiseAnd(Object *other) const;
            virtual Object *operatorEqual(Object *other) const;
            virtual Object *operatorNotEqual(Object *other) const;
            virtual Object *operatorIdentity(Object *other) const;
            virtual Object *operatorNotIdentity(Object *other) const;
            virtual Object *operatorLesser(Object *other) const;
            virtual Object *operatorLesserOrEqual(Object *other) const;
            virtual Object *operatorGreater(Object *other) const;
            virtual Object *operatorGreaterOrEqual(Object *other) const;
            virtual Object *operatorInstanceOf(Object *other) const;
            virtual Object *operatorIn(Object *other) const;
            virtual Object *operatorLeftShift(Object *other) const;
            virtual Object *operatorRightShift(Object *other) const;
            virtual Object *operatorPlus(Object *other) const;
            virtual Object *operatorMinus(Object *other) const;
            virtual Object *operatorMul(Object *other) const;
            virtual Object *operatorDiv(Object *other) const;
            virtual Object *operatorMod(Object *other) const;

            virtual Object *operatorNot() const;
            virtual Object *operatorInv() const;
            virtual Object *operatorPositive() const;
            virtual Object *operatorNegative() const;
            virtual Object *operatorIncrementation() const;
            virtual Object *operatorDecrementation() const;
            virtual Object *operatorTypeOf() const;

            virtual std::string toString(void) const;

        private:
            std::map<std::string, Object *> m_properties;
        };
    }
}

#endif /* ECMA_RUNTIME_OBJECT_H_ */
