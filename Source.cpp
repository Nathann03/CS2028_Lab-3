#include <iostream>
#include <chrono>
#include <string>

#include <type_traits>
#include <format>


#define NULL nullptr

class Node{
public:
    Student data;
    Node* next;
    Node* prev;
};


class LL {
private:
    Node* head = NULL;
    Node* tail = NULL;
    int size = 0;
    Node* curr = head;
    int curr_index = 0;


public:


    void AddItem(Student new_data)
    {
        Node* new_node = new Node();

        new_node->data = new_data;

        if (head == NULL) {
            head = new_node;
            tail = new_node;
            new_node->next = NULL;
            new_node->prev = NULL;
            return;
        }

        Node* current = head;
        bool exit = false;

        while (new_data < current->data) {
            if (current->next == NULL) {
                exit = true;
                break;
            }
            current = current->next;
        }

        if (exit) {
            new_node->next = NULL;
            new_node->prev = current;
            tail = new_node;
            current->next = new_node;
            return;
        }

        new_node->next = current;
        new_node->prev = current->prev;
        current->prev->next = new_node;
        current->prev = new_node;


    }


    void GetItem(Student key) {
        Node* curr_node = head;

        while (curr_node->data != key) {
            if (curr_node->next == NULL) {
                return NULL;
            }
            curr_node = curr_node->next;
        }

        if (curr_node->next != NULL) {
            curr->next->prev = curr->prev;
        }

        if (curr->prev != NULL) {
            curr->prev->next = curr->next;
        }

        free(curr_node);
    }

    bool IsEmpty() {
        return head == NULL;
    }

    bool IsInList(Student key)
    {

        Node* temp = head;
        Node* prev = NULL;

        if (temp != NULL && temp->data == key) {
            *head = temp->next;

            return true;
        }
        else {
            while (temp != NULL && temp->data != key) {
                prev = temp;
                temp = temp->next;
            }

            if (temp == NULL) {
                return false;
            }
            else {
                return true;
            }
        }
    }


    int Size() {
        return size;
    }

    Node* SeeNext() {
        curr = curr->next;
        curr_index++;
        return curr;
    }

    Node* SeeAt(int location) {
        if (curr_index > size) {
            std::cout << "Invalid location/index!";
            return;
        }
        
        while (curr_index != location) {
            curr = curr->next;
            curr_index++;
        }
        return curr;
    }

    void Reset() {
        curr = head;
        curr_index = 0;
    }


    void printList()
    {
        Node* node = head;
        while (node != NULL)
        {
            std::cout << " " << node->data;
            node = node->next;
        }
    }
};

class Student {
private:
    std::string FirstName;
    std::string LastName;
    int MNumber;
    int GPA;
    int byear, bmonth, bday;
public:

    Student(std::string First, std::string Last, int Mnum, int BirthYear, int BirthMonth, int BirthDay, int curr_gpa = 0.0) {
        FirstName = First;
        LastName = Last;
        MNumber = Mnum;
        byear, bmonth, bday = BirthYear, BirthMonth, BirthDay;
        GPA = curr_gpa;
    }

    std::string GetName() {
        return FirstName + LastName;
    }

    int GetMNumber() {
        return MNumber;
    }

    int GetAge(int curr_year, int curr_month, int curr_day) {
        if (curr_year >= byear) {
            if (curr_month >= bmonth) {
                if (curr_month == bmonth && curr_day >= bday) {
                    return curr_year - byear;

                } else if(curr_month == bmonth && curr_day < bday) {
                    return curr_year - byear - 1;

                }

                return curr_year - byear;

            }
            else {
                return curr_year - byear - 1;
            }
        }
        else {
            throw "Enter a real birthday or Current Date!";
        }
    }

    friend std::ostream& operator<< (std::ostream& out, const Student& s) {
        out << s.FirstName << " " << s.LastName << "(M" << s.MNumber << ") :" << s.GPA;
        return out;
    };

    friend bool operator> (const Student& left, const Student& right) {
        return left.MNumber > right.MNumber;
    }

    friend bool operator< (const Student& left, const Student& right) {
        return left.MNumber < right.MNumber;
    }

    friend bool operator== (const Student& left, const Student& right) {
        return left.MNumber == right.MNumber;
    }

    Student(const Student&) = default;
};



int main() {
    LL<Student> students;
    students.AddItem(Student("Kevin", "Le", 1, 2001, 5, 6, 3));
    students.printList();

    return 0;
}