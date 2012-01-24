#ifndef		HYPODERMIC_COMPONENT_REGISTRATION_H_
# define	HYPODERMIC_COMPONENT_REGISTRATION_H_

# include <typeindex>
# include <unordered_map>
# include <vector>

# include <boost/uuid/uuid.hpp>

# include <Hypodermic/IComponentRegistration.h>
# include <Hypodermic/InstanceOwnership.h>
# include <Hypodermic/InstanceSharing.h>
# include <Hypodermic/Service.h>


namespace Hypodermic
{
    class IComponentContext;
    class IComponentLifetime;
    class IInstanceActivator;


	class ComponentRegistration : public IComponentRegistration
	{
	public:
        ComponentRegistration(const boost::uuids::uuid& id,
                              IInstanceActivator* activator,
                              IComponentLifetime* lifetime,
                              InstanceSharing::Mode sharing,
                              InstanceOwnership::Mode ownership,
                              const std::vector< Service* >& services,
                              const std::unordered_map< std::type_index, ITypeCaster* >& typeCasters);

        ComponentRegistration(const boost::uuids::uuid& id,
                              IInstanceActivator* activator,
                              IComponentLifetime* lifetime,
                              InstanceSharing::Mode sharing,
                              InstanceOwnership::Mode ownership,
                              const std::vector< Service* >& services,
                              const std::unordered_map< std::type_index, ITypeCaster* >& typeCasters,
                              IComponentRegistration* target);

        IComponentRegistration* target();

        const boost::uuids::uuid& id();

        IInstanceActivator* activator();

        IComponentLifetime* lifetime();

        InstanceSharing::Mode sharing();

        InstanceOwnership::Mode ownership();

        std::vector< Service* >& services();

        std::shared_ptr< void > castOrForward(const std::type_info& typeInfo, std::shared_ptr< void > instance);

        void raisePreparing(IComponentContext* context);

        void raiseActivating(IComponentContext* context);

        void raiseActivated(IComponentContext* context);

        std::string toString();

	private:
        boost::uuids::uuid id_;
        IInstanceActivator* activator_;
        InstanceSharing::Mode sharing_;
        InstanceOwnership::Mode ownership_;
        IComponentLifetime* lifetime_;
        std::vector< Service* > services_;
        std::unordered_map< std::type_index, ITypeCaster* > typeCasters_;
        IComponentRegistration* target_;
	};

} // namespace Hypodermic


#endif /* !HYPODERMIC_COMPONENT_REGISTRATION_H_ */