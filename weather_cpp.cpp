#include "IpInfoRequest.cpp"
#include <sqlite3.h>
using namespace std;


int main(int argc, char* argv[]) {
    IPInfoRequest request;
    auto location = request.getLocation();
    double latitude = location.first;
    double longitude = location.second;

    cout << "Latitude: " << latitude << endl;
    cout << "Longitude: " << longitude << endl;
    


    
    return 0;
}
