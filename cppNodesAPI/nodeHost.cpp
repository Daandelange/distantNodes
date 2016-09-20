//
//  nodeHost.cpp
//  karmaMapper
//
//  Created by Daan de Lange on 19/09/2016.
//

#include "baseNode.h"
#include "nodeHost.h"

nodeHost::nodeHost(){
	
}

nodeHost::~nodeHost(){
	
}

shared_ptr<baseNode>& nodeHost::findNode(baseNode &_node){
	auto& nodes = getAllNodeInstances();
	
	for( auto it=nodes.begin(); it!=nodes.end(); ++it ){
		if( (*it).second.get() == &_node ){
			return (*it).second;
		}
	}
	
	// 404 not found
	return nullNode;
}

bool nodeHost::registerNode(baseNode& _node){
	auto& nodes = getAllNodeInstances();
	
	// check if not already registered
	if( findNode(_node) ){
		return true;
	}
	
	// add node
	nodes.insert( std::pair<string, shared_ptr<baseNode> >(_node.getName(), std::make_shared<baseNode>(_node)) );
	
	return true;
}

bool nodeHost::removeNode(baseNode &_node){
	
}

map<string, shared_ptr<baseNode> >& nodeHost::getAllNodeInstances(){
	static map<string, shared_ptr<baseNode> > allNodeInstances;
	return allNodeInstances;
}

void nodeHost::incrementName(string& _name){
	// force non-empty name
	if(strlen(_name.c_str())==0){
		_name="defaultNode";
	}
	
	int numberLenght = 0;
	auto lastChar = _name.end();
	lastChar --;
	while( isdigit(*lastChar) ){
		++numberLenght;
		--lastChar;
	}
	
	// cache number
	int curNumber = 0;
	if(numberLenght!=0){
		curNumber = stoi( _name.substr( strlen(_name.c_str())-numberLenght ) );
		
		// separate name from number
		_name.erase(lastChar);
	}
	
	// set new number
	_name.append( to_string(curNumber+1) );
	
	//		// simply add number at the end
	//		if(numberLenght==0){
	//			_name.append("1");
	//			return;
	//		}
	//
	//		std::advance(lastChar,numberLenght-1);
	//
	//		int curNum = atoi( lastChar.base() );
	//		if(curNum < 9){
	//				*lastChar = *lastChar + 1;
	//			}
	//			else {
	//				if(lastChar!=_name.begin()){
	//					*lastChar = '0';
	//					lastChar--;
	//
	//				}
	//			}
	//		}
	//		// or add number
	//		else {
	//			_name.append(" 1");
	//		}
}