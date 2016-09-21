//
//  nodePin.cpp
//  karmaMapper
//
//  Created by Daan de Lange on 19/09/2016.
//
//
//

#pragma once

#include "baseNode.h"

template<class T>
class nodePin {
	
public:
	nodePin();
	~nodePin();
	
private:
	
protected:
	T value;
	baseNode& parentNode;
};