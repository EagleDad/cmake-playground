public class MyTestClass
{
    // Constructor that takes no arguments:
    public MyTestClass()
    {
        Name = "unknown";
    }

    // Constructor that takes one argument:
    public MyTestClass(string name)
    {
        Name = name;
    }

    // Auto-implemented readonly property:
    public string Name { get; }

    // Method that overrides the base class (System.Object) implementation.
    public override string ToString()
    {
        return Name;
    }
}