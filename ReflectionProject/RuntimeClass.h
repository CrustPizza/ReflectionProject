#pragma once

#define DeclareClass(className) \
private:\
	static ##className ##clasNameInstance;\
public:\
	const RuntimeClass& GetThisClass()\
{\
	return ##clasNameInstance;\
}

class RuntimeClass
{

};