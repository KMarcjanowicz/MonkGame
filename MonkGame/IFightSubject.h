#pragma once
#include "Entity.h"

class IFightSubject
{
public:
	virtual ~IFightSubject() {};
	virtual void Attach(Entity* observer) = 0;
	virtual void Detach(Entity* observer) = 0;
	virtual void Notify() = 0;
private:

};

