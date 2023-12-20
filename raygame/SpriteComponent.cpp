#include <Vector2.h>
#include <Vector4.h>
#include <Matrix3.h>
#include "Transform2D.h"
#include "SpriteComponent.h"
#include "Actor.h"
#include "raylib.h"
#include <cmath>
#include <iostream>

MathLibrary::Vector4 color;

SpriteComponent::~SpriteComponent()
{
    RAYLIB_H::UnloadTexture(*m_texture);
    delete m_texture;
}

SpriteComponent::SpriteComponent(Actor* owner, Texture2D* texture) : Component(owner, "SpriteComponent")
{
    m_texture = texture;
    color = { 1,1,1,1 };
}

SpriteComponent::SpriteComponent(Actor* owner, const char* path) : Component(owner, "SpriteComponent")
{
    m_texture = new Texture2D(RAYLIB_H::LoadTexture(path));
    color = { 1,1,1,1 };
}

int SpriteComponent::getWidth()
{
    return m_texture->width;
}

void SpriteComponent::setWidth(int value)
{
    m_texture->width = value;
}

int SpriteComponent::getHeight()
{
    return m_texture->height;
}

void SpriteComponent::setHeight(int value)
{
    m_texture->height = value;
}

void SpriteComponent::setColor(float r, float g, float b, float a)
{
    color = MathLibrary::Vector4(r, g, b, a);
}

void SpriteComponent::draw()
{
    MathLibrary::Matrix3* transform = getOwner()->getTransform()->getGlobalMatrix();
    //Finds the scale of the sprite
    float xMagnitude = (float)round(MathLibrary::Vector2(transform->m00, transform->m10).getMagnitude());
    float yMagnitude = (float)round(MathLibrary::Vector2(transform->m01, transform->m11).getMagnitude());
    setWidth((int)xMagnitude);
    setHeight((int)yMagnitude);

    //Sets the sprite center to the transform origin
    MathLibrary::Vector2 pos = MathLibrary::Vector2(transform->m02, transform->m12);
    MathLibrary::Vector2 forward = MathLibrary::Vector2(transform->m00, transform->m10);
    MathLibrary::Vector2 up = MathLibrary::Vector2(transform->m01, transform->m11);
    pos = pos - (forward.getNormalized() * getWidth() / 2);
    pos = pos - (up.getNormalized() * getHeight() / 2);

    //Find the transform rotation in radians 
    float rotation = atan2(transform->m10, transform->m00);
    RAYLIB_H::Vector2 rayPos = { pos.x, pos.y };

    MathLibrary::Vector4 colorConverted = color * 255;

    Color spriteColor = { colorConverted.x, colorConverted.y, colorConverted.z, colorConverted.w };

    //Draw the sprite
    RAYLIB_H::DrawTextureEx(*m_texture, rayPos,
        (float)(rotation * 180.0f / PI), 1, spriteColor);

    //DrawRectangleLines(pos.x, pos.y, getWidth(), getHeight(), RED);
}

