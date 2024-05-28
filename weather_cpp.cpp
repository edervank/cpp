#include "IpInfoRequest.cpp"
#include "OpenWeatherRequest.cpp"
#include <sqlite3.h>
using namespace std;


int main(int argc, char* argv[]) {
    IPInfoRequest request;
    auto location = request.getLocation();
    double latitude = location.first;
    double longitude = location.second;


    OpenWeatherRequest owrequest(latitude, longitude); 


    return 0;
}
