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
        return Data[Name];
    }
    // Operators
    ResourceType& operator[](const std::string& Name)
    {
        return Data[Name];
    }
};
#endif // RESOURCE_HPP
