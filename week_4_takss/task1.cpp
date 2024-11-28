#include <iostream>  
#include <vector>  
#include <string>  
#include <algorithm>  
using namespace std;

struct Control {  
    int id;
    std::string type; 
    std::string state; 
};  

int main() {  
  
    std::vector<Control> controls = {  
        {1, "button", "visible"},  
        {2, "button", "invisible"},  
        {3, "button", "disabled"},  
        {4, "slider", "visible"},  
        {5, "slider", "invisible"},  
        {6, "slider", "disabled"},  
        {7, "button", "visible"},  
        {8, "button", "disabled"},  
        {9, "slider", "visible"},  
        {10, "slider", "visible"}  
    };  

  
    std::for_each(controls.begin(), controls.end(), [](const Control& ctrl) {  
        std::cout << "ID: " << ctrl.id  << ctrl.type << ", State: " << ctrl.state << std::endl;  
    });  

    int x;
    cout<<"Enter the Choice: ";
    cin>>x;
    
    auto foundControl = std::find_if(controls.begin(), controls.end(), [x](const Control& ctrl) { return ctrl.id == x; });  
    if (foundControl != controls.end()) {  
        std::cout << "Found Control ID:"<<x <<" "<<  foundControl->type << " State: " << foundControl->state << std::endl;  
    }  
      auto it = adjacent_find(
        controls.begin(),
        controls.end(),
        [](const Control &a, const Control &b) {
            return a.state == b.state; 
        });

    if (it != controls.end()) {
        cout << "Consecutive controls with the same state found:" << endl;
        cout << "Control 1: ID = " << it->id << ", Type = " << it->type
             << ", State = " << it->state << endl;

        auto next = it + 1; 
        cout << "Control 2: ID = " << next->id << ", Type = " << next->type
             << ", State = " << next->state << endl;
    } else {
        cout << "No consecutive controls with the same state found." << endl;
    }


   
    

    return 0;  
}