#pragma once
#include "CrossPlatformUI.h"

class Application
{
private:
    AppConfig&  m_config;
    GUIFactory* m_factory  = nullptr;
    Button*     m_button   = nullptr;
    CheckBox*   m_checkBox = nullptr;

public:
    ~Application()
    {
        delete m_button;
        m_button = nullptr;
        delete m_checkBox;
        m_checkBox = nullptr;
        delete m_factory;
        m_factory = nullptr;
    }

    Application(AppConfig& config) : m_config(config)
    {
        switch (config.operationSystem)
        {
        case OperationSystem::UNDEFINED:
            throw std::exception("Operation System Undefined");
        case OperationSystem::WINDOW:
            m_factory = new WinGUIFactory();
            break;
        case OperationSystem::MAC:
            m_factory = new MacGUIFactory();
            break;
        }
    }

    void createUI()
    {
        m_button   = m_factory->createButton();
        m_checkBox = m_factory->createCheckBox();
    }

    void paint()
    {
        m_button->paint();
        m_checkBox->paint();
    }
};
