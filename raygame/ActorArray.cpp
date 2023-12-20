#include "ActorArray.h"
void ActorArray::addActor(Actor* actor)
{
    //Create a new array with a size one greater than our old array
    Actor** appendedArray = new Actor * [m_actorCount + 1];
    //Copy the values from the old array to the new array
    for (int i = 0; i < m_actorCount; i++)
    {
        appendedArray[i] = m_actors[i];
    }

    //Set the last value in the new array to be the actor we want to add
    appendedArray[m_actorCount] = actor;
    //Set old array to hold the values of the new array
    m_actors = appendedArray;
    m_actorCount++;
}

bool ActorArray::removeActor(Actor* actor)
{
    //Check to see if the actor was null
    if (!actor)
    {
        return false;
    }

    bool actorRemoved = false;
    //Create a new array with a size one less than our old array
    Actor** newArray = new Actor * [m_actorCount - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_actorCount; i++)
    {
        if (actor != m_actors[i])
        {
            newArray[j] = m_actors[i];
            j++;
        }
        else
        {
            actorRemoved = true;
        }
    }
    //Set the old array to the new array
    if (actorRemoved)
    {
        m_actors = newArray;
        m_actorCount--;
    }
    //Return whether or not the removal was successful
    return actorRemoved;
}

bool ActorArray::removeActor(int index)
{
    //Check to see if the index is outside the bounds of our array
    if (index < 0 || index >= m_actorCount)
    {
        return false;
    }

    bool actorRemoved = false;

    //Create a new array with a size one less than our old array 
    Actor** newArray = new Actor * [m_actorCount - 1];
    //Create variable to access tempArray index
    int j = 0;
    //Copy values from the old array to the new array
    for (int i = 0; i < m_actorCount; i++)
    {
        //If the current index is not the index that needs to be removed,
        //add the value into the old array and increment j
        if (i != index)
        {
            newArray[j] = m_actors[i];
            j++;
        }
        else
        {
            delete m_actors[i];
            actorRemoved = true;
        }
    }

    //Set the old array to be the tempArray
    m_actors = newArray;
    m_actorCount--;
    return actorRemoved;
}

Actor* ActorArray::getActor(int index)
{
    //Return false if the index is out of bounds
    if (index < 0 || index >= m_actorCount)
        return nullptr;

    return m_actors[index];
}

bool ActorArray::contains(Actor* actor)
{
    //Iterate through actor array
    for (int i = 0; i < m_actorCount; i++)
    {
        //return true if the current actor if it matches the argument
        if (m_actors[i] == actor)
            return true;
    }

    return false;
}