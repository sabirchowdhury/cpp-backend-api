#pragma once

#include "iResourceFactory.h"

class calcResourceFactory : public iResourceFactory
{

public:
    shared_ptr<Resource> get_resource() const final;

private:
    shared_ptr<Resource> _resource;
};