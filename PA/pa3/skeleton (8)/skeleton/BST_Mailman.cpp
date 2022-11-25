//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_Mailman.h"

// TODO: Constructors and Destructors
BST_Mailman::BST_Mailman(): root(nullptr)
{
}

BST_Mailman_Node::BST_Mailman_Node(Mail *mail):left(nullptr), right(nullptr), currentMailsStored(0), mailPtr{}
{
    if (!mail)
        return ;
    else{
        mailPtr[0] =mail; // since the mail is distributed to mailman, the mail do not need to dynamically allocated new deep copied mail?
        streetName = mail->getStreetName();
        currentMailsStored += 1;
    }
}

BST_Mailman::~BST_Mailman()
{
    delete root;
}

BST_Mailman_Node::~BST_Mailman_Node()
{   
    for (int i = 0; i < currentMailsStored; i++)
        delete mailPtr[i];
    if (left)
        delete left;
    if(right)
        delete right;
}

// TODO: Getters
std::string BST_Mailman_Node::getStreetName() const
{
    return streetName;
}

BST_Mailman * BST_Mailman_Node::getRightBST() const
{
    return right;
}

BST_Mailman * BST_Mailman_Node::getLeftBST() const
{
    return left;
}


// TODO add mail to the array mailPtr[] - NOTE: WE WILL NEVER ASK YOU TO
//  PUT TOO MANY MAILS. (a max of MAX_NUM_MAILS add_mail calls)
void BST_Mailman::addMail(Mail *mail)
{
    if (!root) {
        root = new BST_Mailman_Node(mail);
    }else {
        if (root->streetName == mail->getStreetName()) {
            root->BST_Mailman_Node::addMail(mail);
            return ;
        }else if (root->left &&mail->getStreetName() < root->streetName) 
                root->left->addMail(mail);
        else if (root->right && mail->getStreetName() > root->streetName)
            root->right->addMail(mail);
        else if (!root->left && mail->getStreetName() < root->streetName) {
            root->left = new BST_Mailman();
            root->left->root = new BST_Mailman_Node(mail);
        }else if (!root->right && mail->getStreetName() > root->streetName) {
            root->right = new BST_Mailman();
            root->right->root = new BST_Mailman_Node(mail);
        }
    }
}

void BST_Mailman_Node::addMail(Mail *mail)
{
    mailPtr[currentMailsStored++] = mail;
}

// TODO: Remove a mail, given its street name and ID
bool BST_Mailman::remove(int id, std::string streetName)
{   
    if (root) {
        if (streetName == root->streetName) 
            return root->remove(id);
        else if (root->left && streetName < root->streetName) 
            return root->left->remove(id, streetName);
        else if (root->right && streetName > root->streetName)
            return root->right->remove(id, streetName);

        return false;
    }else
        return false;
}

bool BST_Mailman_Node::remove(int id)
{
    for (int i = 0; i < currentMailsStored; i++) {
        if (mailPtr[i]) {
            if (mailPtr[i]->getId() == id) {
                delete mailPtr[i];
                mailPtr[i] = nullptr;
                return true;
            }
        }
    }
    return false;
}

// TODO: Find a mail item, given its street name and ID
Mail * BST_Mailman::find(int id, std::string streetName)
{
    if (root) {
        if (streetName == root->streetName) 
            return root->find(id);
        else if (root->left && streetName < root->streetName)
            return root->left->find(id, streetName);
        else if (root->right && streetName > root->streetName)
            return root->right->find(id, streetName);

        return nullptr;
    }else 
        return nullptr;
}

Mail *BST_Mailman_Node::find(int id)
{
    for (int i = 0; i < currentMailsStored; i++) {
        if (mailPtr[i])
            if (mailPtr[i]->getId() == id) 
                return mailPtr[i];
    }
    return nullptr;
}


// TODO: Print functions. See example outputs for the necessary formats.
void BST_Mailman::printInOrder() const
{
    if (root) {
        if (root->left)
            root->left->printInOrder();
        root->print();
        if(root->right)
            root->right->printInOrder();
    }
}

void BST_Mailman::printPostOrder() const
{
    if (root) {
        if (root->left)
            root->left->printPostOrder();
        if(root->right)    
            root->right->printPostOrder();
        root->print();
    }
}

void BST_Mailman::printPreOrder() const
{
    if (root) {
        root->print();
        if(root->left)
            root->left->printPreOrder();
        if(root->right)
            root->right->printPreOrder();
    }
}

void BST_Mailman_Node::print() const
{
    std::cout << "BST Node for Street: " << streetName << std::endl;
    for (int i = 0; i < currentMailsStored; ++i) {
        if(mailPtr[i] != nullptr)
        {
            mailPtr[i]->printMail();
        }
    }
}
