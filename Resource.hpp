#ifndef RESOURCE_HPP
#define RESOURCE_HPP
template<typename ResourceType>class Resource
{
public:
    // Variables
    typedef map<std::string,std::unique_ptr<ResourceType>> DataType;
    DataType Data;
    // Functions
    ResourceType& Load(const std::string& Name)
    {
        unique_ptr<ResourceType> Ptr(new ResourceType());
        if(Ptr->loadFromFile(Name)){
            unique_ptr<ResourceType>& Holder=Data[Name];
            Holder.swap(Ptr);
            return *Holder;
        }
        cerr<<"Failed to load resource '"<<Name<<"'!"<<endl;
        exit(1);
    }
    // Operators
    ResourceType& operator[](const std::string& Name)
    {
        const typename DataType::const_iterator Iter=Data.find(Name);
        if(Iter!=Data.cend())return *Iter->second;
        return *(Data[Name]=unique_ptr<ResourceType>(new ResourceType));
    }
};
extern Resource<sf::Texture> Textures;
extern Resource<sf::Image> Images;
#endif // RESOURCE_HPP
