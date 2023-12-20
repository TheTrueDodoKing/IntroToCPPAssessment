#pragma once
class Actor;

class ActorArray
{
public:
	/// <summary>
	/// Adds an actor to the end of the array
	/// </summary>
	/// <param name="actor">The new actor to add to the array</param>
	void addActor(Actor* actor);

	/// <summary>
	/// Removes the actor from the array
	/// </summary>
	/// <param name="actor">The actor to remove</param>
	/// <returns>False if the actor is not in the array</returns>
	bool removeActor(Actor* actor);
	/// <summary>
	/// Removes an actor from the array
	/// </summary>
	/// <param name="index">The index to remove from the array</param>
	/// <returns>False if the index is out of bounds</returns>
	bool removeActor(int index);

	/// <summary>
	/// Gets an actor from the array
	/// </summary>
	/// <param name="index">The index of the desired actor</param>
	/// <returns>The actor found at the index or nullptr if the index was out of bounds</returns>
	Actor* getActor(int index);

	/// <summary>
	/// Gets the length of the array
	/// </summary>
	int getLength() { return m_actorCount; }

	/// <summary>
	/// Checks if the actor is in the array
	/// </summary>
	/// <param name="actor">A reference to the actor to use to check</param>
	/// <returns>False if the actor is not in the array</returns>
	bool contains(Actor* actor);

private:
	Actor** m_actors;
	int m_actorCount;
};


