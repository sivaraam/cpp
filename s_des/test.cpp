#include <iostream>
#include "s_des.hpp"

int main() {
    s_des::key_type key;
    std::cin>>key;
    std::cout<<"sizeof(key): "<<sizeof(key)<<'\n';
    s_des::generate_subkey(key);
}
