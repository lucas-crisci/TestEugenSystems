#include "InputOutput.h"

InputOutput::InputOutput()
{

}

bool InputOutput::YesNoChoice()
{
    std::cout << "y = yes / n = no" << std::endl;
    while (true)
    {
        if (GetAsyncKeyState(0x59)) // Y Choice
            return true;
        else if (GetAsyncKeyState(0x4E)) // N Choice
            return false;
    }
}

bool InputOutput::ABChoices(std::string AChoice, std::string BChoice)
{
    std::cout << "1 = " << AChoice << " / 2 = " << BChoice << std::endl;
    while (true)
    {
        if (GetAsyncKeyState(VK_NUMPAD1) || GetAsyncKeyState(0x31)) // Choice 1
        {
            while (true)
            {
                if (!GetAsyncKeyState(VK_NUMPAD1) && !GetAsyncKeyState(0x31))
                    return true;
            }
        }
        else if (GetAsyncKeyState(VK_NUMPAD2) || GetAsyncKeyState(0x32)) // Choice 2
        {
            while (true)
            {
                if (!GetAsyncKeyState(VK_NUMPAD2) && !GetAsyncKeyState(0x32))
                    return false;
            }
        }
    }
}

void InputOutput::PressEnter()
{
    std::cout << std::endl << "\nPress Enter to continue or Q to quit the game" << std::endl;

    bool EnterPressed = false;
    bool EnterReleased = false;
    while (!EnterPressed)
    {
        if (GetAsyncKeyState(VK_RETURN))
        {
            EnterPressed = true;
            while (!EnterReleased)
            {
                if (!GetAsyncKeyState(VK_RETURN))
                    EnterReleased = true;
            }
        }
        if (GetAsyncKeyState(0x51)) // Q Key
        {
            bool Choice = YesNoChoice();
            if (Choice)
            {
                std::cout << "Good bie Players !" << std::endl;
                Sleep(1000);
                exit(0);
            }
            else
            {
                EnterPressed = true;
                PressEnter();
            }
        }
    }

    system("CLS");
}

void InputOutput::Refresh()
{
    system("CLS");
}
