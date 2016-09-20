//
//  nodeFactory.h
//  karmaMapper
//
//  Created by Daan de Lange on 18/09/2016.
//
//	The node factory handles registration of all different node types
//

#pragma once

// Standard libraries
#include <map>
#include <string>
#include <utility>

class baseNode;

namespace node {
	
	namespace factory {
		
		typedef baseNode* (*CreateNodeFunc)();
		typedef std::map<std::string, CreateNodeFunc> nodeRegistry;
		
		inline nodeRegistry& getAllNodeTypes(){
			static nodeRegistry nodeTypes;
			return nodeTypes;
		}
		
		template<class T>
		baseNode* createNode() {
			return new T;
		}
		
		template<class T>
		struct NodeRegistryEntry {
		public:
			static NodeRegistryEntry<T>& Instance(const std::string& name){
				
				static NodeRegistryEntry<T> inst(name);
				return inst;
			}
			
		private:
			NodeRegistryEntry(const std::string& name){
				NodeRegistryEntry& reg = getAllNodeTypes();
				CreateNodeFunc func = createNode<T>;
				
				std::pair<nodeRegistry::iterator, bool> ret =
				reg.insert(nodeRegistry::value_type(name, func));
				
				if (ret.second == false) {
					// already registered
				}
			}
			
			NodeRegistryEntry(const NodeRegistryEntry<T>&) = delete; // C++11 feature
			NodeRegistryEntry& operator=(const NodeRegistryEntry<T>&) = delete;
		};
		
	} // namespace factory
	
} // namespace effect


// allow node registration
#define REGISTER_NODE(TYPE, NAME)                                        \
namespace node {                                                         \
namespace factory {                                                       \
namespace                                                                 \
{                                                                         \
template<class T>                                                         \
class nodeRegistration;                                                  \
\
template<>                                                                \
class nodeRegistration<TYPE>                                             \
{                                                                         \
static const ::node::factory::NodeRegistryEntry<TYPE>& reg;                  \
};                                                                        \
\
const ::node::factory::NodeRegistryEntry<TYPE>&                              \
nodeRegistration<TYPE>::reg =                                            \
::node::factory	::NodeRegistryEntry<TYPE>::Instance(NAME);                \
}}}
