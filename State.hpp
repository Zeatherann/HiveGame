#ifdef TESTRUN
#ifndef STATE_HPP
#define STATE_HPP
class State
{
public:
    // Variables
    EventHandler Events;
    sf::Color Color;
    // Destructor
    virtual ~State();
    // Functions
    virtual void Init()=0;
    virtual void Uninit()=0;
    virtual void Render()=0;
    virtual void Update()=0;
};
#endif // STATE_HPP
#endif
