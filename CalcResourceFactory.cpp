#include "CalcResourceFactory.h"

CalcResourceFactory::CalcResourceFactory() {
    _resource = make_shared<Resource>();
    _resource->set_path(
        "/{operation: add|subtract|multuply|divide}"
        "/{num1: [-+]?[0-9]*\\.?[0-9]*}"
        "/{num2: [-+]?[0-9]*\\.?[0-9]*}"
    );
    _resource->set_method_handler("GET", [&](const shared_ptr<Session> session){
        get_handler(session);
    });

}

tuple<float, float, string> CalcResourceFactory::get_path_parameters(
    const shared_ptr<Session> session) {
    
        const auto& request = session->get_request();
        auto operation = request->get_path_parameters("operation");
        auto num1 = atof(request->get_path_parameters("num1").c_str());
        auto num2 = atof(request->get_path_parameters("num2").c_str());
        return make_tuple(num1, num2, operation);
}

float CalcResourceFactory::calculate(float num1, float num2, string operation) {
    if (operation == "add") {
        return num1 + num2;
    }

    else if (operation == "subtract") {
        return num1 - num2;
    }
    else if (operation == "multiply") {
        return num1 * num2;
    }
    else if (operation == "divide") {
        return num1 / num2;
    }
};

void CalcResourceFactory::get_handler(const shared_ptr<Session> session) {
    const auto [num1, num2, operation] = get_path_parameters(session);
    const auto result = calculate(num1, num2, operation);


}