#include <sstream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Easy.hpp>
#include <curlpp/Options.hpp>
#include <jsoncpp/json/json.h>

using namespace std;
using namespace curlpp::options;


class OpenWeatherRequest {
public:
        OpenWeatherRequest(const double lat, const double lng)  {
        try {
            std::string API_KEY = "64bfcc7b00b175b36d8c92f5375232c4";
            std::string url = "api.openweathermap.org/data/2.5/forecast?lat=" + std::to_string(lat) + "&lon=" + std::to_string(lng) + "&appid=" + API_KEY;
            curlpp::Easy openWeatherRequest;
            openWeatherRequest.setOpt<curlpp::options::Url>(url);
            std::ostringstream responseStream;
            openWeatherRequest.setOpt(new curlpp::options::WriteStream(&responseStream));
            openWeatherRequest.perform();
            std::string jsonResponse = responseStream.str();
            std::cout << jsonResponse << endl;

            Json::Value root;
            Json::Reader reader;
            bool parsingSuccessful = reader.parse(jsonResponse, root);
            if (parsingSuccessful) {
                Json::Value list = root["list"];
                for (Json::Value::iterator it = list.begin(); it != list.end(); ++it) {
                    Json::Value item = *it;
                    // Armazena cada item em uma variável separada
                    double dt = item["dt"].asDouble();
                    Json::Value mainItem = item["main"];
                    double temp = mainItem["temp"].asDouble();
                    double feels_like = mainItem["feels_like"].asDouble();
                    double temp_min = mainItem["temp_min"].asDouble();
                    double temp_max = mainItem["temp_max"].asDouble();
                    int pressure = mainItem["pressure"].asInt();
                    int sea_level = mainItem["sea_level"].asInt();
                    int grnd_level = mainItem["grnd_level"].asInt();
                    int humidity = mainItem["humidity"].asInt();
                    double temp_kf = mainItem["temp_kf"].asDouble();

                    Json::Value weatherItem = item["weather"][0];
                    int weatherId = weatherItem["id"].asInt();
                    std::string weatherMain = weatherItem["main"].asString();
                    std::string weatherDescription = weatherItem["description"].asString();
                    std::string weatherIcon = weatherItem["icon"].asString();

                    Json::Value cloudsItem = item["clouds"];
                    int cloudsAll = cloudsItem["all"].asInt();

                    Json::Value windItem = item["wind"];
                    double windSpeed = windItem["speed"].asDouble();
                    int windDeg = windItem["deg"].asInt();
                    double windGust = windItem["gust"].asDouble();

                    int visibility = item["visibility"].asInt();
                    int pop = item["pop"].asInt();

                    Json::Value sysItem = item["sys"];
                    std::string sysPod = sysItem["pod"].asString();
                    
                    std::cout << "==================================================" << std::endl;
                    std::cout << "dt: " << dt << std::endl;
                    std::cout << "temp: " << temp << std::endl;
                    std::cout << "feels_like: " << feels_like << std::endl;
                    std::cout << "temp_min: " << temp_min << std::endl;
                    std::cout << "temp_max: " << temp_max << std::endl;
                    std::cout << "pressure: " << pressure << std::endl;
                    std::cout << "sea_level: " << sea_level << std::endl;
                    std::cout << "grnd_level: " << grnd_level << std::endl;
                    std::cout << "humidity: " << humidity << std::endl;
                    std::cout << "temp_kf: " << temp_kf << std::endl;
                    std::cout << "weatherId: " << weatherId << std::endl;
                    std::cout << "weatherMain: " << weatherMain << std::endl;
                    std::cout << "weatherDescription: " << weatherDescription << std::endl;
                    std::cout << "weatherIcon: " << weatherIcon << std::endl;
                    std::cout << "cloudsAll: " << cloudsAll << std::endl;
                    std::cout << "windSpeed: " << windSpeed << std::endl;
                    std::cout << "windDeg: " << windDeg << std::endl;
                    std::cout << "windGust: " << windGust << std::endl;
                    std::cout << "visibility: " << visibility << std::endl;
                    std::cout << "pop: " << pop << std::endl;
                    std::cout << "sysPod: " << sysPod << std::endl;
                }
            } else {
                cerr << "Erro ao analisar JSON: " << reader.getFormattedErrorMessages() << endl;
            }
        } catch (curlpp::RuntimeError &e) {
            cerr << "Erro de tempo de execução: " << e.what() << endl;
        } catch (curlpp::LogicError &e) {
            cerr << "Erro lógico: " << e.what() << endl;
        }
    }
};
