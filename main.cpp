#include <iostream>
#include <string>
#include <vector>

class ToDoList{
public:
  ToDoList(){
    id = 0; name = ""; status = false;
  }
  ~ToDoList() = default;

  void new_id(int _id){
    id = _id;
  }

  void new_name(std::string _name){
    name = _name;
  }

  void completed_status(){
    status = true;
  }

  int get_id(){
    return id;
  }

  std::string get_name(){
    return name;
  }

  bool get_status(){
    return status;
  }

private:
  int id, num;
  std::string name;
  bool status;
};

void information(){
  std::cout << "1 - add" << std::endl;
  std::cout << "2 - delete" << std::endl;
  std::cout << "3 - complete" << std::endl;
  std::cout << "4 - all clear" << std::endl;
  std::cout << "5 - chat clear" << std::endl;
  std::cout << "6 - quit" << std::endl;
}

int main(){
  int l = 1;
  ToDoList temp;
  std::vector<ToDoList> Data;
  std::vector<ToDoList>::iterator it;
  Data.clear();

  while (true){
    if (Data.empty()){
      std::cout << "todo list is empty" << std::endl;
    }

    information();

    std::cout << std::endl;

    for (it = Data.begin() ; Data.end() != it ; it++){
      std::string completed_status = (it->get_status() ? "done" : "not done");
      std::cout << it->get_id() << " " << it->get_name() << " " << completed_status << std::endl;
    }

    std::cout << std::endl << std::endl;

    int option; std::cin >> option;

    if (option == 1){
      std::string desc;
      std::cout << "Description" << std::endl;
      std::cin >> desc; temp.new_name(desc);
      temp.new_id(l);
      Data.push_back(temp); l++;
    }
    else if (option == 2){
      std::cout << "Input todo ID to delete: ";
      int id; std::cin >> id;
      bool deleted = false;
      for (it = Data.begin() ; Data.end() != it ; it++){
        if (id == it->get_id()){
          Data.erase(it); deleted = true;
          break;
        }
      }
      if (!deleted){
        std::cout << "Not Found!" << std::endl;
      }
      else{
        l = 1;
        for (it = Data.begin() ; Data.end() != it ; it++){
          it->new_id(l); l++;
        }
        std::cout << "Successful Deleted" << std::endl;
      }
    }
    else if (option == 3){
      int completed_id;
      std::cout << "Input Completed ID" << std::endl;
      std::cin >> completed_id;
      bool found = 0;
      for (it = Data.begin() ; Data.end() != it ; it++){
        if (completed_id == it->get_id()){
          it -> completed_status();
          std::cout << "Good Job!" << std::endl;
          found = 1; break;
        }
      }
      if (!found){
        std::cout << "Invalid ID, please try again!" << std::endl;
      }
    }
    else if (option == 4){
      std::cout << "Are you sure, all your todo will be clear!" << std::endl;
      std::cout << "1 - yes" << std::endl;
      std::cout << "2 - no" << std::endl;
      int valid_choise; std::cin >> valid_choise;
      if (valid_choise == 1){
        std::cout << "All todo clear!" << std::endl;
        Data.clear();
        l = 1;
      }
      else if (valid_choise == 2){
        std::cout << "it's good news" << std::endl;
      }
      else{
        std::cout << "Non valid input, try again!" << std::endl;
      }
    }
    else if (option == 5){
      system("cls");
    }
    else if (option == 6){
      std::cout << "Good Bye" << std::endl;
      break;
    }
    else{
      std::cout << "Not Valid Input!" << std::endl;
    }
  }
}
