#include "test.h"

void testVector(){
    vector<string> wordVec{"Lorem","Ipsum","Dolor","Sit","Amet","Consectetur"};
    for(vector<string>::iterator it = wordVec.begin(); it != wordVec.end(); it++){
        cout << *it << ' ';
    }
    cout << endl;

    for(vector<string>::reverse_iterator it = wordVec.rbegin(); it != wordVec.rend(); it++){
        cout << *it << ' ';
    }
    cout << endl;

    vecReplace(wordVec,"Lorem","Latin");
    for(vector<string>::iterator it = wordVec.begin(); it != wordVec.end(); it++){
        cout << *it << ' ';
    }
    cout << endl;

}

void testSet(){
    set<string> wordSet{"Lorem","Ipsum","Dolor","Sit","Amet","Consectetur"};
    for(set<string>::iterator it = wordSet.begin(); it != wordSet.end(); it++){
        cout << *it << ' ';
    }
    cout << endl;

    for(set<string>::reverse_iterator it = wordSet.rbegin(); it != wordSet.rend(); it++){
        cout << *it << ' ';
    }
    cout << endl;

    setReplace(wordSet,"Lorem","Latin");
    for(set<string>::iterator it = wordSet.begin(); it != wordSet.end(); it++){
        cout << *it << ' ';
    }
    cout << endl;
}

void testPerson(){
    Person p1{"Elias Oddvar","Slettevoll"};
    Person p2{"Konrad","Jervell"};
    Person p3{"Astrid", "Blund"};
    Person p4{"Anders Alfonso", "Tidemann"};

    list<Person> l1;
    insertOrdered(l1,p2);
    insertOrdered(l1,p1);
    insertOrdered(l1,p3);
    insertOrdered(l1,p4);
    for(list<Person>::iterator it = l1.begin(); it != l1.end(); it++){
        cout << *it << ", ";
    }
    cout << endl;
}

void testLinkedList(){
    LinkedList::LinkedList list;
    list.insert(list.end(),"hei");
    list.insert(list.begin(),"du");
    for(auto it = list.begin(); it != list.end(); it++){
        cout << it->getValue() << ' ';
    }
    cout << endl;
}
