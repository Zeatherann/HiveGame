#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP
class EventHandler
{
public:
    typedef function<void(const sf::Event&)> EventFunction;
    class EventWrapper
    {
    public:
        // Variables
        EventFunction Function;
        // Constructor
        EventWrapper(const EventFunction& Function);
    };
    typedef shared_ptr<EventWrapper> EventPtr;
    typedef map<sf::Event::EventType,set<EventPtr>> EventMap;
    // Variables
    EventMap Events;
    // Functions
    void HandleEvents(sf::Window& Window)const;
    EventPtr AddEvent(const sf::Event::EventType& Type,const EventFunction& Function);
    bool RemoveEvent(const EventPtr& Event);
};
#endif // EVENT_HANDLER_HPP
