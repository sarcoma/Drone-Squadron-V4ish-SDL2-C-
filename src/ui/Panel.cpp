//
// Created by sarcoma on 22/03/18.
//

#include <SDL_rect.h>
#include <SDL_render.h>
#include <iostream>
#include "Panel.h"
#include "../constants.h"

Panel::Panel(int width, int height, int x, int y)
{
    panel.x = x;
    panel.y = y;
    panel.w = width;
    panel.h = height;
}

void Panel::draw()
{
    SDL_SetRenderDrawColor(gRenderer, colour[0], colour[1], colour[2], colour[3]);
    SDL_RenderFillRect(gRenderer, &panel);
    drawChildren();
}

void Panel::drawChildren() const
{
    for (Panel* child : children) {
        child->draw();
    }
}

void Panel::add(Panel* child)
{
    children.push_back(child);
}

void Panel::setBackgroundColour(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    colour[0] = r;
    colour[1] = g;
    colour[2] = b;
    colour[3] = a;
}

