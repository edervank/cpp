sudo apt update
sudo apt install libcurl4-openssl-dev g++ libcurlpp-dev libjsoncpp-dev libsqlite3-dev

g++ -o weather weather_cpp.cpp -lcurlpp -lcurl -lpthread -ljsoncpp -lsqlite3 -Ilib/sqlite



g++ -o weather weather_cpp.cpp -lcurlpp -lcurl -lpthread -ljsoncpp -Ilib/sqlite


g++ -o create_db create_db.cpp -Ilib/sqlite -lsqlite3
