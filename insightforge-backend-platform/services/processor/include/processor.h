#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <nlohmann/json.hpp>

class Processor {
public:
    static std::string generateInsight(const nlohmann::json& inputData);
};

#endif // PROCESSOR_H
