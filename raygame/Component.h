#pragma once

class Actor;

class Component
{
public:
	Component();
	Component(Actor* owner, const char* name);

	virtual ~Component() {}

	/// <summary>
	/// Gets the actor this component is attached to.
	/// </summary>
	Actor* getOwner() { return m_owner; };

	/// <summary>
	/// Gets the name of this component. Usually the same as the type name.
	/// </summary>
	/// <returns></returns>
	const char* getName() { return m_name; };

	/// <summary>
	/// Called before the first update.
	/// </summary>
	virtual void start() {};
	/// <summary>
	/// Called every time the game loops.
	/// </summary>
	/// <param name="deltaTime">The amount of time in seconds since the last frame.</param>
	virtual void update(float deltaTime) {};
	/// <summary>
	/// Called every time the game loops to update visuals.
	/// </summary>
	virtual void draw() {};
	/// <summary>
	/// Called when the scene ends or when an actor is removed from the scene.
	/// </summary>
	virtual void end() {};
	/// <summary>
	/// Called when the actor overlaps with another.
	/// </summary>
	/// <param name="other"></param>
	virtual void onCollision(Actor* other) {};
	/// <summary>
	/// Called when the actor is going to be destroyed.
	/// </summary>
	virtual void onDestroy() {};

private:
	const char* m_name;
	Actor* m_owner;
};

