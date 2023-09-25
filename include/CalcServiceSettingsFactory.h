#pragma once

#include "IServiceSettingsFactory.h"

class CalcServiceSettingsFactory : public IServiceSettingsFactory {


private:

    std::shared_ptr<Settings> _settings;


public:

    CalcServiceSettingsFactory();  // constructor

    shared_ptr<Settings> get_settings() const final;
    // final does not allow to be overridden


};