#pragma once
#include "Entity.h"
#include <string>

using namespace std;

class IFightSubject
{
public:
	virtual ~IFightSubject();
	virtual void Attach(Entity* entity_) = 0;
	virtual void Detach(Entity* entity_) = 0;
	virtual void Notify() = 0;
};

