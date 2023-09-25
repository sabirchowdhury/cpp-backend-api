#pragma once

#include "IService.h"

#include "IResourceFactory.h"
#include "IServiceSettingsFactory.h"

class CalcService : public IService {

private:

    Service _service;
    shared_ptr<IServiceSettingsFactory> _settings_factory;

    // service from restbed
    // factory settings shared pointer


public:

    CalcService(
        shared_ptr<IResourceFactory> resource_factory, 
        shared_ptr<IServiceSettingsFactory> settings_factory);

    // Constructor

    void start() final;
    // non override


};