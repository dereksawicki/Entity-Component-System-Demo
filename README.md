# Entity-Component-System-Demo
Demo of ECS architecture, using SFML. 

# The Demo
The program demonstrates the Entity-Component-System architecture. In this framework, entities are solely a collection of
components, which determine their attributes and behaviors. Interactions between entities are managed by entity systems.
I wanted to highlight the advantage this system affords by demonstrating a way components can easily be added and removed at 
runtime. By running into pickups, an entity may exchange its shape or color. And by pressing the space bar, the entity
system can detach an input-component from one entity, and add it to another, swapping user control from one to the other.

# The Observer Pattern
In this demo, there are two event managers: One for input, and one for collisions. Observers may subscribe to specific 
types of events from these event managers. For example, when the collision system detects a collision between entities
with collision-components, it notifies the audio system so that it may play an appropriate collision sound, and the 
pickup system, so that it may handle the event where an entity collides with a pickup. Using this pattern, it is simple
for systems to subscribe and unsubscribe from events without having to modify any code pertaining to the way events are
emitted.
