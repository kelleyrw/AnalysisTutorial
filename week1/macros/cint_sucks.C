#include <vector>

class MySimpleClass
{
    public:
        MySimpleClass(const int v) : x(v) {}
        int x;
};

void cint_sucks()
{
    std::vector<MySimpleClass> vec;
    vec.push_back(MySimpleClass(7));
    return;
}
