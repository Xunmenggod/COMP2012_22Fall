#include <iostream>

#include "button.h"
#include "textbox.h"
#include "container.h"

int main()
{
    int testcase;
    std::cin >> testcase; // 1 or 2 or 3

    if (testcase != 1 && testcase != 2 && testcase != 3)
    {
        std::cout << "test case should be 1, 2 or 3! " << testcase << " found\n";
        return 0;
    }
    std::cout << "LAB 3: Inheritence\n";

    if (testcase == 1)
    {
        Container *mainPage = new Container();
        mainPage->setName("MainPage");
        mainPage->setPosition(0, 0);
        mainPage->setSize(1920, 1080);

        TextBox *tBox11 = new TextBox();
        tBox11->setName("TextBox11");
        tBox11->setPosition(100, 100);
        tBox11->setSize(100, 300);
        tBox11->setText("Welcome");

        mainPage->addTextBox(tBox11);
        mainPage->display();

        delete mainPage;
        return 0;
    }

    else if (testcase == 2)
    {
        Container *mainPage = new Container();
        mainPage->setName("MainPage");
        mainPage->setPosition(0, 0);
        mainPage->setSize(1920, 1080);

        Button *button11 = new Button();
        button11->setName("Button11");
        button11->setPosition(400, 100);
        button11->setSize(100, 300);
        button11->setText("Press This!");
        button11->setTrigger("You have pressed button11!");

        mainPage->addButton(button11);
        mainPage->display();

        delete mainPage;
    }
    else if (testcase == 3)
    {

        Container *mainPage = new Container();
        mainPage->setName("MainPage");
        mainPage->setPosition(0, 0);
        mainPage->setSize(1920, 1080);

        Container *page1 = new Container();
        page1->setName("Page1");
        page1->setPosition(100, 100);
        page1->setSize(960, 640);

        TextBox *tBox11 = new TextBox();
        tBox11->setName("TextBox11");
        tBox11->setPosition(100, 100);
        tBox11->setSize(100, 300);
        tBox11->setText("Welcome");

        Button *button11 = new Button();
        button11->setName("Button11");
        button11->setPosition(400, 100);
        button11->setSize(100, 300);
        button11->setText("Press This!");
        button11->setTrigger("You have pressed button11!");

        TextBox *tBox12 = new TextBox();
        tBox12->setName("TextBox12");
        tBox12->setPosition(100, 300);
        tBox12->setSize(100, 300);
        tBox12->setText("Back");

        Button *button12 = new Button();
        button12->setName("Button12");
        button12->setPosition(100, 400);
        button12->setSize(100, 100);
        button12->setText("Do not press me!");
        button12->setTrigger("You have pressed button12!");

        page1->addTextBox(tBox11);
        page1->addButton(button11);
        page1->addTextBox(tBox12);
        page1->addButton(button12);

        TextBox *tBox1 = new TextBox();
        tBox1->setName("TextBox1");
        tBox1->setPosition(100, 100);
        tBox1->setSize(100, 300);
        tBox1->setText("Welcome Main!");

        Button *button1 = new Button();
        button1->setName("Button1");
        button1->setPosition(400, 100);
        button1->setSize(100, 300);
        button1->setText("Press This Button!");
        button1->setTrigger("You have pressed button1!");

        mainPage->addContainer(page1);
        mainPage->addTextBox(tBox1);
        mainPage->addButton(button1);

        mainPage->display();

        delete mainPage;
    }
}