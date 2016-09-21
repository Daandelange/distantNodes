//
//  nodeHost.cpp
//  karmaMapper
//
//  Created by Daan de Lange on 19/09/2016.
//
//	The nodeHost class handles the node instantiation and links all nodes together
//

// [Q] Does this need to be a singleton ?

#pragma once

//#include "baseNode.h"
//#include "nodeFactory.h"
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <utility>

using namespace std;

// fwd declaration needed here!
class baseNode;
//const string& baseNode::getName();

class nodeHost {

private:
	nodeHost();
	
public:
	~nodeHost();
	
	shared_ptr<baseNode>& findNode( baseNode& _node );
	bool registerNode( baseNode& _node );
	bool removeNode( baseNode& _node );
	
	// a map for easy accessing node instances
	map<string, shared_ptr<baseNode> >& getAllNodeInstances();
	
	static void incrementName( string& _name );
	
};

#include <stdexcept>
class NodeException : public std::runtime_error {
public:
	NodeException() : std::runtime_error("NodeException"){ }
};