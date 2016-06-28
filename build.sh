protoc -I=./ --cpp_out=./ test.proto 
g++ -g -Wall test.cpp test.pb.cc -o test  -lprotobuf -pthread
