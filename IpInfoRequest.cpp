#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <jsoncpp/json/json.h>

using namespace std;
using namespace curlpp::options;

class IPInfoRequest {
public:
    std::pair<double, double> getLocation() {
        try {
            curlpp::Easy ipInfoRequest;
            ipInfoRequest.setOpt<curlpp::options::Url>("https://ipinfo.io/json");
            std::ostringstream responseStream;
            ipInfoRequest.setOpt(new curlpp::options::WriteStream(&responseStream));
            ipInfoRequest.perform();

            std::string jsonResponse = responseStream.str();
            Json::Value root;
            Json::Reader reader;
            bool parsingSuccessful = reader.parse(jsonResponse, root);
            if (parsingSuccessful) {
                std::string loc = root["loc"].asString();
                std::size_t commaPos = loc.find(',');
                std::string latitudeStr = loc.substr(0, commaPos);
                std::string longitudeStr = loc.substr(commaPos + 1);
                double latitude = std::stod(latitudeStr);
                double longitude = std::stod(longitudeStr);
                return {latitude, longitude};
            } else {
                cerr << "Erro ao analisar JSON: " << reader.getFormattedErrorMessages() << endl;
                return {0.0, 0.0}; // Retorna valores padrão em caso de erro
            }
        } catch (curlpp::RuntimeError &e) {
            cerr << "Erro de tempo de execução: " << e.what() << endl;
            return {0.0, 0.0}; // Retorna valores padrão em caso de erro
        } catch (curlpp::LogicError &e) {
            cerr << "Erro lógico: " << e.what() << endl;
            return {0.0, 0.0}; // Retorna valores padrão em caso de erro
        }
    }
};