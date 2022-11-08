#include <iostream>

#include "object.h"
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
    std::cout << "LAB 4: Inheritence: Virtual Inheritance\n\n";

    if (testcase == 1)      //Test Task 1
    {
        Container *mainPage = new Container;
        mainPage->setName("MainPage");
        mainPage->setPosition(0, 0);
        mainPage->setSize(1920, 1080);

        Container *page1 = new Container;
        page1->setName("Page1");
        page1->setPosition(0, 0);
        page1->setSize(960, 640);

        Button *button11 = new Button;
        button11->setName("Button11");
        button11->setPosition(0, 0);
        button11->setSize(100, 300);
        button11->setText("Press This!");
        button11->setTrigger("You have pressed button11!");

        TextBox *tBox11 = new TextBox;
        tBox11->setName("TextBox11");
        tBox11->setPosition(0, 0);
        tBox11->setSize(100, 300);
        tBox11->setText("Welcome");

        Object *obj1;
        obj1 = page1;
        obj1->display();
        obj1 = button11;
        obj1->display();
        obj1 = tBox11;
        obj1->display();

        page1->addObject(button11);
        page1->addObject(tBox11);
        mainPage->addObject(page1);
        mainPage->display();

        delete mainPage;
        return 0;
    }

    else if (testcase == 2)     //Test Task 1&2
    {
        Container *mainPage = new Container;
        mainPage->setName("MainPage");
        mainPage->setPosition(0, 0);
        mainPage->setSize(1920, 1080);

        Container *page1 = new Container;
        page1->setName("Page1");
        page1->setPosition(100, 100);
        page1->setSize(960, 640);

        TextBox *tBox11 = new TextBox;
        tBox11->setName("TextBox11");
        tBox11->setPosition(100, 100);
        tBox11->setSize(100, 300);
        tBox11->setText("Welcome");

        Button *button11 = new Button;
        button11->setName("Button11");
        button11->setPosition(400, 100);
        button11->setSize(100, 300);
        button11->setText("Press This!");
        button11->setTrigger("You have pressed button11!");

        TextBox *tBox12 = new TextBox;
        tBox12->setName("TextBox12");
        tBox12->setPosition(100, 300);
        tBox12->setSize(100, 300);
        tBox12->setText("Back");

        Button *button12 = new Button;
        button12->setName("Button12");
        button12->setPosition(100, 400);
        button12->setSize(100, 100);
        button12->setText("Do not press me!");
        button12->setTrigger("You have pressed button12!");

        page1->addObject(tBox11);
        page1->addObject(button11);
        page1->addObject(tBox12);
        page1->addObject(button12);

        TextBox *tBox1 = new TextBox;
        tBox1->setName("TextBox1");
        tBox1->setPosition(100, 100);
        tBox1->setSize(100, 300);
        tBox1->setText("Welcome Main!");

        Button *button1 = new Button;
        button1->setName("Button1");
        button1->setPosition(400, 100);
        button1->setSize(100, 300);
        button1->setText("Press This Button!");
        button1->setTrigger("You have pressed button1!");

        mainPage->addObject(page1);
        mainPage->addObject(tBox1);
        mainPage->addObject(button1);

        mainPage->display();

        delete mainPage;
        return 0;
    }
    else if (testcase == 3) //Test Task 1&3
    {
        Container *mainPage = new Container;
        mainPage->setName("MainPage");
        mainPage->setPosition(100, 100);
        mainPage->setSize(1920, 1080);

        Container *page1 = new Container;
        page1->setName("Page1");
        page1->setPosition(100, 100);
        page1->setSize(960, 640);

        TextBox *tBox11 = new TextBox;
        tBox11->setName("TextBox11");
        tBox11->setPosition(100, 100);
        tBox11->setSize(100, 300);
        tBox11->setText("Welcome");

        Button *button11 = new Button;
        button11->setName("Button11");
        button11->setPosition(400, 100);
        button11->setSize(100, 300);
        button11->setText("Press This!");
        button11->setTrigger("You have pressed button11!");

        TextBox *tBox12 = new TextBox;
        tBox12->setName("TextBox12");
        tBox12->setPosition(100, 300);
        tBox12->setSize(100, 300);
        tBox12->setText("Back");

        Button *button12 = new Button;
        button12->setName("Button12");
        button12->setPosition(100, 400);
        button12->setSize(100, 100);
        button12->setText("Do not press me!");
        button12->setTrigger("You have pressed button12!");

        Container *page11 = new Container;
        page11->setName("Page11");
        page11->setPosition(300, 300);
        page11->setSize(200, 200);

        TextBox *tBox13 = new TextBox;
        tBox13->setName("TextBox13");
        tBox13->setText("Welcome");
        tBox13->setPosition(-1, 100);
        tBox13->setPosition(100, -1);
        tBox13->setPosition(100, 100);
        tBox13->setSize(-1, 300);
        tBox13->setSize(100, -1);
        tBox13->setSize(2000, 2000);
        tBox13->setSize(870, 550);

        page1->addObject(tBox11);
        page1->addObject(button11);
        page1->addObject(tBox12);
        page1->addObject(button12);
        page1->addObject(page11);
        page1->addObject(tBox13);

        tBox13->setSize(860, 540);
        page1->addObject(tBox13);

        TextBox *tBox1 = new TextBox;
        tBox1->setName("TextBox1");
        tBox1->setPosition(100, 100);
        tBox1->setSize(100, 300);
        tBox1->setText("Welcome Main!");

        Button *button1 = new Button;
        button1->setName("Button1");
        button1->setPosition(400, 100);
        button1->setSize(100, 300);
        button1->setText("Press This Button!");
        button1->setTrigger("You have pressed button1!");

        mainPage->addObject(page1);
        mainPage->addObject(tBox1);
        mainPage->addObject(button1);

        mainPage->display();

        delete mainPage;
        return 0;
    }
}