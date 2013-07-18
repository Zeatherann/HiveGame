#ifndef RESOURCE_HPP
#define RESOURCE_HPP
template<typename ResourceType>class Resource
{
public:
    // Variables
    map<std::string,std::unique_ptr<ResourceType>> Data;
    // Functions
    ResourceType& Load(const std::string& Name)
    {
        ResourceType& Ret=Data[Name];
        if(Ret.loadFromFile(Name))return Ret;
        cerr<<"Failed to load resource '"<<Ret<<"'!"<<endl;
        exit(1);
    }
    // Operators
    ResourceType& operator[](const std::string& Name)
    {
        return Data[Name];
    }
};
#endif // RESOURCE_HPP
