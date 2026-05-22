#pragma once

class IGraphicsWrapper
{
private:

public:
	virtual ~IGraphicsWrapper() {};
	void virtual Run() = 0;
};