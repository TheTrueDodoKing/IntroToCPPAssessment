#pragma once
#include <Matrix3.h>
#include "Actor.h"
#include "ActorArray.h"

class Scene
{
public:
    Scene();

    /// <returns>If this scene is the current active scene in the game.</returns>
    bool getStarted() { return m_started; }

    /// <returns>The scenes matrix that represents the world transform.</returns>
    MathLibrary::Matrix3* getWorld();

    /// <summary>
    /// Adds a new UI element to the scene
    /// </summary>
    /// <param name="actor"></param>
    void addUIElement(Actor* actor);

    /// <summary>
    /// Removes the UI element from the scene
    /// </summary>
    /// <param name="index">The index of the UI element to remove</param>
    /// <returns>False if the index is outside the bounds of the array</returns>
    bool removeUIElement(int index);

    /// <summary>
    /// Removes the UI element from the scene
    /// </summary>
    /// <param name="actor">A reference to the UI element to remove</param>
    /// <returns>False if the UI element is not in the scene</returns>
    bool removeUIElement(Actor* actor);

    /// <summary>
    /// Adds the given actor to the array of actors so that the scene may call its update and draw functions.
    /// </summary>
    /// <param name="actor">The actor to add to the scene.</param>
    void addActor(Actor* actor);

    /// <summary>
    /// Removes the actor at the given index. DOES NOT DELETE THE ACTOR!!!
    /// </summary>
    /// <param name="index">The index the actor is in the scene's array.</param>
    /// <returns>False if the index given is out of bounds.</returns>
    bool removeActor(int index);

    /// <summary>
    /// Removes the actor given if it's in the array. DOES NOT DELETE THE ACTOR!!!
    /// </summary>
    /// <param name="actor">The actor to look for in the scene's array.</param>
    /// <returns>False if the actor is a nullptr or isn't in the array.</returns>
    bool removeActor(Actor* actor);



    virtual void start();

    virtual void update(float deltaTime);
    virtual void updateUI(float deltaTime);

    virtual void draw();
    virtual void drawUI();

    virtual void end();

private:
    ActorArray m_actors;
    ActorArray m_UIElements;
    MathLibrary::Matrix3* m_world;
    bool m_started;
    int m_actorCount;
    int m_UIElementCount;
};