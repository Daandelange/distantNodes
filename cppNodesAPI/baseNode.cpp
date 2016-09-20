//
//  baseNode.cpp
//  karmaMapper
//
//  Created by Daan de Lange on 18/09/2016.
//  Copyright (c) 2014 __MyCompanyName__. All rights reserved.
//

#include "baseNode.h"

baseNode::baseNode( nodeHost& _host, const string& _defaultName) : host(_host) {
	
	// set default unique name on instantiation
	uniqueName = setName(_defaultName);
	
	if(!host.registerNode(*this)){
		// unable to register the node to the host
		throw NodeException();
	}
}

baseNode::~baseNode(){
	
	host.removeNode(*this);
	
}

// returns a ref to the name of the node
const string& baseNode::setName( const string& _name) {
	
	// same name ?
	if( uniqueName.compare(_name) == 0 ){
		return uniqueName;
	}
	
	// name already exists ?
	if( host.getAllNodeInstances().find(_name) != host.getAllNodeInstances().end() ){
		string tmpName = _name;
		while( host.getAllNodeInstances().find(tmpName) != host.getAllNodeInstances().end() ){
			nodeHost::incrementName( tmpName );
		}
		
		this->uniqueName = tmpName;
	}
	
	// check if not already exists
//	for( auto it = getAllNodeInstances().begin(); it!=getAllNodeInstances().end(); ++it ){
//		
//		if(_name.first.compare( *it ) == 0){
//			
//		}
//	}
	
	return uniqueName;
}

const string& baseNode::getName(){
	return uniqueName;
}

// register effect type
//REGISTER_NODE( baseNode , "baseNode" );