#pragma once

#include <memory>
#include <restbed>

using namespace restbed;
using namespace std;

class iResourceFactory
{

public:
    virtual shared_ptr<Resource> get_resource() const = 0;
};