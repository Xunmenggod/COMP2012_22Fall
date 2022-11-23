//
// Created by Yigit Sen on 27/10/2022.
//

#include "BST_PostOffice.h"

// TODO: Constructors and Destructors

//TIP: root will be nullptr at first, and we'll add a node once we try to add a mail object.
BST_PostOffice::BST_PostOffice():root(nullptr)
{
}

BST_PostOffice_Node::BST_PostOffice_Node(Mail *mail):district(mail->getDistrict()), left(nullptr), right(nullptr)
{
    mailman[mail->getAddressHash() % HASH_MODULO].addMail(mail);
}

BST_PostOffice::~BST_PostOffice()
{
    delete root;
}

BST_PostOffice_Node::~BST_PostOffice_Node()
{
    delete left;
    delete right;
}

// TODO: Accessor functions.
BST_PostOffice * BST_PostOffice_Node::getLeftBST() const
{
    return left;
}

BST_PostOffice * BST_PostOffice_Node::getRightBST() const
{
    return right;
}

District BST_PostOffice_Node::getDistrict() const
{
    return district;
}


//TODO: Given a district, id and street name, find the mail object.
Mail *BST_PostOffice::find(District dist, int id, std::string streetName)
{
    if (root) {
        if (dist == root->district)
            return root->find(id, streetName);
        else if (root->left && dist < root->district)
            root->left->find(dist, id, streetName);
        else if (root->right && dist > root->district)
            root->right->find(dist, id, streetName);  
        
        return nullptr;
    }else
        return nullptr;
}

Mail *BST_PostOffice_Node::find(int id, std::string streetName)
{
    Mail* mail = nullptr;
    for (int i = 0; i < HASH_MODULO; i++) {
        mail = mailman[i].find(id, streetName);
        if (mail)
            break;
    }   
    return mail;
}


// TODO: Given a district, id and street name, remove the mail object from the
// system.
bool BST_PostOffice::remove(District dist, int id, std::string streetName)
{   
    if (root){
        if (dist == root->district)
            return root->remove(id, streetName);
        else if (root->left && dist < root->district)
            root->left->remove(dist, id, streetName);
        else if (root->right && dist > root->district)
            root->right->remove(dist, id, streetName);  
        
        return false;
    }else
        return false;
}

bool BST_PostOffice_Node::remove(int id, std::string streetName)
{
    for (int i = 0; i < HASH_MODULO; i++) {
        if (mailman[i].remove(id, streetName))
        return true;
    }   
    return false;
}

// TODO: Add mail to the system
void BST_PostOffice::addMail(Mail *mail)
{
    if (!root) {
        root = new BST_PostOffice_Node(mail);
    }else {
        if (mail->getDistrict() == root->district)
            root->addMail(mail);
        else if (root->left && mail->getDistrict() < root->district)
            root->left->addMail(mail);
        else if (root->right && mail->getDistrict() > root->district)
            root->right->addMail(mail);  
        else if (!root->left && mail->getDistrict() < root->district) {
            root->left = new BST_PostOffice();
            root->left->root = new BST_PostOffice_Node(mail);
        }else if (!root->right && mail->getDistrict() > root->district) {
            root->right = new BST_PostOffice();
            root->right->root = new BST_PostOffice_Node(mail);
        }
    }
}

void BST_PostOffice_Node::addMail(Mail *mail)
{
    mailman[mail->getAddressHash() % HASH_MODULO].addMail(mail);
}

// TODO: Given a district, print all of the data in it.
// TIP: Print style depends on type.
void BST_PostOffice::printDistrict(District dist, printType type) const
{
    if (root) {
        if (dist == root->district) {
            // print all the mailman info, header print
            root->print(type);
        }else if (root->left && dist < root->district)
            root->left->printDistrict(dist, type);
        else if (root->right && dist > root->district)
            root->right->printDistrict(dist, type);
    }
}

void BST_PostOffice_Node::print(printType type) const
{
    std::cout << "The District Mail Report for district: " << district << std::endl;
    for (int i = 0; i < HASH_MODULO; i++)
        this->printMailman(i, type);
}

// TODO: Given a district and ID of the mailman, print all mail in it
// TIP: Print style depends on type - see the header file
void BST_PostOffice::printMailman(District district, int i, printType type) const
{
    if (root) {
        if (district == root->district) {
            // print all the mailman info, header print
            root->printMailman(i, type);
        }else if (root->left && district < root->district)
            root->left->printMailman(district, i, type);
        else if (root->right && district > root->district)
            root->right->printMailman(district, i, type);
    }
}

void BST_PostOffice_Node::printMailman(int i, printType type) const
{
    switch (type)
        {
            case printType::inorder:
                std::cout<<"For Mailman: "<<i<<std::endl;
                mailman[i].printInOrder();
                break;
            
            case printType::postorder:
                mailman[i].printPostOrder();
                break;

            case printType::preorder:
                mailman[i].printPreOrder();
                break;
            
            default:
                break;
        }
}

// TODO: Other print functions.
void BST_PostOffice::printInOrder() const
{
    if (root) {
        if (root->left)
            root->left->printInOrder();
        root->print(printType::inorder);
        if (root->right)
            root->right->printInOrder();
    }
}

void BST_PostOffice::printPostOrder() const
{
    if (root) {
        if (root->left)
            root->left->printPostOrder();
        if (root->right)
            root->right->printPostOrder();
        root->print(printType::postorder);
    }
}

void BST_PostOffice::printPreOrder() const
{
    if (root) {
        root->print(printType::preorder);
        if (root->left)
            root->left->printPreOrder();
        if (root->right)
            root->right->printPreOrder();
    }
}