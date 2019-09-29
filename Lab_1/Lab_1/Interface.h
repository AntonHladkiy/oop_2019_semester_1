#pragma once
template <typename T>
class Interface
{
public:
	virtual void add_vertex(T) = 0;
	virtual void delete_vertex(T) = 0;
	virtual void print() = 0;
};

