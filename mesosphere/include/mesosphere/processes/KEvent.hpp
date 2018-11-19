#pragma once

#include <mesosphere/core/util.hpp>
#include <mesosphere/core/Result.hpp>
#include <mesosphere/interfaces/ISetAllocated.hpp>
#include <mesosphere/interfaces/ILimitedResource.hpp>
#include <mesosphere/interfaces/IClientServerParent.hpp>
#include <mesosphere/processes/KReadableEvent.hpp>
#include <mesosphere/processes/KWritableEvent.hpp>

namespace mesosphere
{

class KEvent final :
    public KAutoObject,
    public IClientServerParent<KEvent, KReadableEvent, KWritableEvent>,
    public ISetAllocated<KEvent>,
    public ILimitedResource<KEvent> {
    public:
    MESOSPHERE_AUTO_OBJECT_TRAITS(AutoObject, Event);
    MESOSPHERE_CLIENT_SERVER_PARENT_TRAITS(ReadableEvent, WritableEvent);
    MESOSPHERE_LIMITED_RESOURCE_TRAITS(10s);

    virtual ~KEvent();

    Result Initialize();

    private:
};

MESOSPHERE_AUTO_OBJECT_DEFINE_INCREF(Event);

}
