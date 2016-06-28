#include "test.pb.h"
#include <iostream>
#include <stdlib.h>

#include <sstream>

using namespace std;
int main()
{
    TestInfo hw;
    hw.set_id(123);
    hw.set_str("abc");

    cout << hw.id() << endl;
    cout << hw.str() << endl;

    TestInfos infos;
    stringstream ss; 
    TestInfo *info;
    for (int i=0; i<15; i++) {
        ss.str("");
        info = infos.add_infos();
        info->set_id(i);
        ss << i+5;
        info->set_str("xx"+ss.str());
        ss.clear();
    }

    string str;
    infos.SerializeToString(&str);
    cout << "str:" << str << endl;

    TestInfos infos2;
    infos2.ParseFromArray(str.c_str(), str.size());
    cout << "size:" << infos2.infos_size() << endl;
    for (int i=0; i<infos2.infos_size(); i++) {
        cout << infos2.infos(i).id() << "=" << infos2.infos(i).str() << endl;
    }
    return 0;
}
