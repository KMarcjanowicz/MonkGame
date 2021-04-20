#pragma once
class IFightObserver
{
public:
	virtual ~IFightObserver();
	virtual void Update() = 0;	
};

