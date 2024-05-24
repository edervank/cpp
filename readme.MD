sudo apt update
sudo apt install libcurl4-openssl-dev g++
sudo apt install libcurlpp-dev

sudo apt-get install libjsoncpp-dev
sudo apt install libsqlite3-dev


g++ -o weather weather_cpp.cpp -lcurlpp -lcurl -lpthread -ljsoncpp -Ilib/sqlite