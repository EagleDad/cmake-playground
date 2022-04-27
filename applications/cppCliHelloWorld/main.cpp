#include <iostream>

ref class MyClass
{
public:
    int i;

    // nested class
    ref class MyClass2
    {
    public:
        int i;
    };

    // nested interface
    interface struct MyInterface
    {
        void f( );
    };
};

ref class MyClass2 : public MyClass::MyInterface
{
public:
    virtual void f( ) { System::Console::WriteLine( "test" ); }
};

public
value struct MyStruct
{
    void f( ) { System::Console::WriteLine( "test" ); }
};

int main( int argc, char** argv )
{
    std::ignore = argc;
    std::ignore = argv;

    try
    {
        std::cout << "Hello World C++/CLI" << std::endl;

        // instantiate ref type on garbage-collected heap
        MyClass ^ p_MyClass = gcnew MyClass;
        p_MyClass->i = 4;

        // instantiate value type on garbage-collected heap
        MyStruct ^ p_MyStruct = gcnew MyStruct;
        p_MyStruct->f( );

        // instantiate value type on the stack
        MyStruct p_MyStruct2;
        p_MyStruct2.f( );

        // instantiate nested ref type on garbage-collected heap
        MyClass::MyClass2 ^ p_MyClass2 = gcnew MyClass::MyClass2;
        p_MyClass2->i = 5;

        return 0;
    }
    catch ( std::exception& e )
    {
        std::cout << "Caught std::exception" << e.what( ) << std::endl;
        return -1;
    }
    catch ( ... )
    {
        std::cerr << "Caught undetermined exception" << std::endl;
        return -1;
    }
}
