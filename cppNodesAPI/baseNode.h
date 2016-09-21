//
//  baseNode.cpp
//  karmaMapper
//
//  Created by Daan de Lange on 18/09/2016.
//
//	Base structure for every node based class.
//

#pragma once

#include "nodeHost.h"
#include "nodeConfig.h"
#include "nodePin.h"
#include "nodeFactory.h"
#include <stdio.h>
#include <stdlib.h>
//#include <string>
//#include <map>

using namespace std;

// fwd declaration needed

class baseNode {
	
public:
	baseNode( nodeHost& _host, const string& _defaultName = "baseNode");
	virtual ~baseNode();
	
	// null node reference
	static shared_ptr<baseNode> nullNode;
	
	// utils
	const string& setName( const string& _name );
	const string& getName();
	
	// getParentNodes -> upstream
	// getChildNodes -> downstream
	
	// import/export methods
	string toXML() const;
	bool fromXML( string _xml );
	
protected:
	
	
	
private:
	string uniqueName;
	nodeHost& host;
	
	//vector<pins> inPins;
	//vector<pins> outPins;
};

// PIN CLASS
// onconnected
// ondisconnected

