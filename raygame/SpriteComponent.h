#pragma once
#include "Component.h"

class Texture2D;
class Transform2D;

class SpriteComponent : public Component
{
public:
    SpriteComponent() {}
    ~SpriteComponent();
    /// <summary>
    /// Loads the given texture
    /// </summary>
    /// <param name="texture">Sets the sprites image to be the given texture</param>
    SpriteComponent(Actor* owner, Texture2D* texture);

    /// <summary>
    /// Loads the texture at the given path
    /// </summary>
    /// <param name="path">The file path of the texture</param>
    SpriteComponent(Actor* owner, const char* path);

    /// <summary>
    /// Returns the width of the Sprite
    /// </summary>
    int getWidth();

    /// <summary>
    /// Returns the width of the Sprite
    /// </summary>
    void setWidth(int value);

    /// <summary>
    /// Returns the height of the Sprite
    /// </summary>
    int getHeight();

    /// <summary>
    /// Returns the height of the Sprite
    /// </summary>
    void setHeight(int value);

    /// <summary>
    /// Changes the color tint applied to this sprite.
    /// </summary>
    /// <param name="r">The red value of the new color.</param>
    /// <param name="g">The green value of the new color.</param>
    /// <param name="b">The blue value of the new color.</param>
    /// <param name="a">The alpha transparency of the new color.</param>
    void setColor(float r, float g, float b, float a);

    /// <summary>
    /// Draws the sprite using the rotation, translation, and scale
    /// of the given transform
    /// </summary>
    /// <param name="transform"></param>
    void draw() override;

private:
    Texture2D* m_texture;
};

