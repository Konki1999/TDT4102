#include "LinkedList.h"

namespace LinkedList{
std::ostream & operator<<(std::ostream & os, const Node & node){
    os << node.getValue(); 
    return os;
}

Node* LinkedList::insert(Node *pos, const std::string& value){
        if(pos==head.get()){
            head = std::make_unique<Node>(value,std::move(head),nullptr);
            head->next->prev=head.get();
            return pos->prev;
        }
        else{
            std::unique_ptr<Node> newNode = std::make_unique<Node>(value,std::move(pos->prev->next),pos->getPrev());
            pos->prev->next = std::move(newNode);
            pos->prev = pos->prev->next.get();
            return pos->getPrev();
        }
    }
}
