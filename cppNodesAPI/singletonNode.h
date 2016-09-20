//
//  singletonNode
//  karmaMapper
//
//  Created by Daan de Lange on 19/09/2016.
//
//	An abstract class for easily crating singleton nodes
//

#pragma once

#include "baseNode.h"
#include "nodeFactory.h"

template<typename T>
class singletonNode : public baseNode {
	
public:
	
	static T& getInstance(){
		if (singletonNode::typedSingletonInstance == 0) {
			singletonNode::typedSingletonInstance = getSingleton();
		}
		return *(singletonNode::typedSingletonInstance);
	}
	
protected:
	virtual ~singletonNode(){
		bInitialised = false;
		if (singletonNode::typedSingletonInstance != 0) {
			delete singletonNode::typedSingletonInstance;
		}
		singletonNode::typedSingletonInstance = 0;
	}
	
	inline explicit singletonNode() : baseNode(true) {
		nodeType = "singletonNode";
		nodeName = "singletonNode";
		
		if( singletonNode::typedSingletonInstance == 0 ){
			//assert(singletonNode::typedSingletonInstance == 0);
			singletonNode::typedSingletonInstance = static_cast<T*>(this);
		}
		else {
			ofLogNotice("inline explicit singletonNode()") << "Singleton already loaded, not re-instantiating...";
		};
		
	}
	
private:
	static T* typedSingletonInstance;
	// your own class has to implement its own initializer function
	static T* getSingleton(){
		return new T();
	}
	
	// prevents accidentally creating copies of your singleton
	singletonNode(singletonNode const&)     = delete;
	void operator=(singletonNode const&)  = delete;
	//	singletonNode& operator=(const singletonNode& other){
	//		// always keep the singleton version
	//		// todo: could be a better condition...
	//		if ( isSingleton ||  other.isSingleton ) {
	//			return getInstance();
	//		}
	//		else return *this;
	//	}
};

template<typename T>
T* singletonNode<T>::typedSingletonInstance = 0;
