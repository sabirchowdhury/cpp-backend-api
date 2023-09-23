#pragma once

#include "IResourceFactory.h"
#include <tuple>
#include <string>

class CalcResourceFactory : public iResourceFactory
{

public:
    shared_ptr<Resource> get_resource() const final;

private:
    
    string to_json(float result);
    float calculate(float num1, float num2, string operation);
    tuple<float, float, string> get_path_parameters(const shared_ptr<Session> session) const;
    void get_handler(const shared_ptr<Session> session);
    shared_ptr<Resource> _resource;
    
};