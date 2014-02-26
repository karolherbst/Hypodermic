#include <boost/functional/hash.hpp>
#include "TypedService.h"


namespace Hypodermic
{

    TypedService::TypedService(const std::type_info& typeInfo)
        : typeInfo_(typeInfo)
    {
    }

    const std::type_info& TypedService::typeInfo() const
    {
        return typeInfo_;
    }

    bool TypedService::operator==(const Service& rhs) const
    {
        return std::strcmp(typeInfo_.name(), rhs.typeInfo().name()) == 0;
    }

    std::size_t TypedService::hashValue() const
    {
        return boost::hash< std::string >()(std::string(typeInfo_.name()));
    }

} // namespace Hypodermic