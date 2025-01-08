#pragma once
#include <iostream>
#include <ostream>

enum class OperationSystem
{
    UNDEFINED = -1,
    WINDOW,
    MAC
};

struct AppConfig
{
public:
    OperationSystem operationSystem = OperationSystem::UNDEFINED;
};

class Button
{
public:
    virtual      ~Button() = default;
    virtual void paint() const = 0;
};

class WinButton : public Button
{
public:
    void paint() const override
    {
        std::cout << "WinButton::paint" << '\n';
    }
};

class MacButton : public Button
{
public:
    void paint() const override
    {
        std::cout << "MacButton::paint" << '\n';
    }
};

class CheckBox
{
public:
    virtual      ~CheckBox() = default;
    virtual void paint() const = 0;
};

class WinCheckBox : public CheckBox
{
public:
    void paint() const override
    {
        std::cout << "WinCheckBox::paint" << '\n';
    }
};

class MacCheckBox : public CheckBox
{
public:
    void paint() const override
    {
        std::cout << "MacCheckBox::paint" << '\n';
    }
};

class GUIFactory
{
public:
    virtual           ~GUIFactory() = default;
    virtual Button*   createButton() const = 0;
    virtual CheckBox* createCheckBox() const = 0;
};

class WinGUIFactory : public GUIFactory
{
public:
    Button* createButton() const override
    {
        return new WinButton();
    }

    CheckBox* createCheckBox() const override
    {
        return new WinCheckBox();
    }
};

class MacGUIFactory : public GUIFactory
{
public:
    Button* createButton() const override
    {
        return new MacButton();
    }

    CheckBox* createCheckBox() const override
    {
        return new MacCheckBox();
    }
};
