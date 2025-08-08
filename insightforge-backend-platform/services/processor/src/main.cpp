#include <iostream>
#include "httplib.h"
#include "nlohmann/json.hpp"
#include "processor.h"

using json = nlohmann::json;

int main() {
    httplib::Server svr;

    svr.Post("/process", [](const httplib::Request& req, httplib::Response& res) {
        try {
            json input = json::parse(req.body);
            std::string output = Processor::generateInsight(input);

            res.set_content(output, "application/json");
        } catch (const std::exception& e) {
            res.status = 400;
            res.set_content(R"({"error": "Invalid JSON input"})", "application/json");
        }
    });

    std::cout << "Processor Service running on http://localhost:8080" << std::endl;
    svr.listen("0.0.0.0", 8080);
    return 0;
}
