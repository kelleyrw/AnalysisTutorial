namespace Module1 {void PrintHello();}
namespace Module2 {void PrintHello();}

int main()
{
    Module1::PrintHello();
    Module2::PrintHello();
    return 0;
}
