#include "main.hpp"
// Event Wrapper
EventHandler::EventWrapper::EventWrapper(const EventHandler::EventFunction& Function):Function(Function) {}
// EventHandler
void EventHandler::HandleEvents(sf::Window& Window)const
{
    if(Events.size()==0u)return;
    sf::Event Event;
    const EventHandler::EventMap::const_iterator ListEnd=Events.cend();
    while(Window.pollEvent(Event))
    {
        EventHandler::EventMap::const_iterator List=Events.find(Event.type);
        if(List!=ListEnd)
        {
            for(const EventHandler::EventPtr& Iter:List->second)
            {
                Iter->Function(Event);
            }
        }
        if((List=Events.find(sf::Event::Count))!=ListEnd)
        {
            for(const EventHandler::EventPtr& Iter:List->second)
            {
                Iter->Function(Event);
            }
        }
    }
}
EventHandler::EventPtr EventHandler::AddEvent(const sf::Event::EventType& Type,const EventHandler::EventFunction& Function)
{
    if(Function==NULL)return NULL;
    EventHandler::EventPtr NewEvent(new EventHandler::EventWrapper(Function));
    Events[Type].insert(NewEvent);
    return NewEvent;
}
bool EventHandler::RemoveEvent(const EventHandler::EventPtr& Event)
{
    for(EventHandler::EventMap::iterator Iter=Events.begin(); Iter!=Events.end();)
    {
        set<EventHandler::EventPtr>& List=Iter->second;
        if(List.find(Event)!=List.end())
        {
            if(List.size()==1u)
            {
                Events.erase(Iter++);
            }
            else
            {
                List.erase(Event);
                return true;
            }
        }
        else
        {
            ++Iter;
        }
    }
    return false;
}
