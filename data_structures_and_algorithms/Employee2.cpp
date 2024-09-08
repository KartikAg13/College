#include <iostream>

using namespace std;

class Employee {
    private:
    int associateID;
    string associateName;
    string workStatus;

    public:
    int getAssociateID() {
        return associateID;
    }

    string getAssociateName() {
        return associateName;
    }

    string getWorkStatus() {
        return workStatus;
    }

    void setAssociateID(int id) {
        associateID = id;
    }

    void setAssociateName(string name) {
        associateName = name;
    }

    void setWorkStatus(string status) {
        workStatus = status;
    }

    void updateStatusDetails(int days) {
        if(days <= 20)
            setWorkStatus("Core skills");
        else if(days > 20 && days <= 40)
            setWorkStatus("Advanced modules");
        else if(days > 40)
            setWorkStatus("Project phase");
    }
};

int main() {
    int id = 0;
    string name;
    int days = 0;
    cout << "Enter the associate id: ";
    cin >> id;
    cout << "Enter the associate name: ";
    cin >> name;
    cout << "Enter the number of days: ";
    cin >> days;
    Employee e1;
    e1.setAssociateID(id);
    e1.setAssociateName(name);
    e1.updateStatusDetails(days);
    cout << "The associate " << e1.getAssociateName() << "'s work status: " << e1.getWorkStatus() << endl;
    return 0;
}