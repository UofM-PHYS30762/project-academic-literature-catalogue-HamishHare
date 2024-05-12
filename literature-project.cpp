// PHYS 30762 Programming in C++
// Literature Catalogue Project
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Main functionality
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
// Hamish Hare

#include <memory> // smart pointers
#include <filesystem> // file paths
#include "authors.h"
#include "authorlist.h"
#include "literature-element.h"
#include "book.h"
#include "thesis.h"
#include "journal.h"
#include "literature-catalogue.h"

Catalogue prepare_sample_catalogue()
{
  // Books
  Book b0{"A Tale of Two Cities", AuthorList{Author{"Charles", "", "Dickens"}},
          "Chapman & Hall", "Historical novel", 18.99};
  Book b1{"Harry Potter and the Philosopher's Stone",
          AuthorList{Author{"J", "K", "Rowling"}},
          "Bloomsbury", "Childrens Fantasy", 14.99};
  Book b2{"Harry Potter and the Chamber of Secrets",
          AuthorList{Author{"J", "K", "Rowling"}},
          "Bloomsbury", "Childrens Fantasy", 15.99};
  Book b3{"The Da Vinci Code", AuthorList{Author{"Dan", "", "Brown"}},
          "Doubleday", "Mystery Thriller", 23.99};
  Book b4{"The Hobbit", AuthorList{Author{"J", "R R", "Tolkien"}},
          "George Allen & Unwin", "Childrens Fantasy", 42.99};
  Book b5{"Watership Down", AuthorList{Author{"Richard", "", "Adams"}},
          "Rex Collings", "Fantasy", 21.99};
  Book b6{"To Kill a Mockingbird", AuthorList{Author{"Harper", "", "Lee"}},
          "J B Lippincott & Co", "Southern Gothic, Bildungsroman", 14.49};
  Book b7{"War and Peace", AuthorList{Author{"Leo", "", "Tolstoy"}},
          "The Russian Messenger", "Historical novel", 33.50};
  Book b8{"Cosmos", AuthorList{Author{"Carl", "", "Sagan"}},
          "Random House", "Popular science, Cosmology", 13.88};
  Book b9{"Angels & Demons", AuthorList{Author{"Dan", "", "Brown"}},
          "Robert Langdon", "Mystery-thriller", 13.88};
  
  // Thesis
  Thesis t0{"Logical Team Q-learning:", AuthorList{Author{"Lucas", "", "Cassano"}},
            "Ali H. Sayed", "Ecole Polytechnique Federale de Lausanne"};
  Thesis t1{"Great Stuff", AuthorList{Author{"Will", "B", "Good"}},
            "Super Visor", "Universe City"};
  Thesis t2{"Uncovering Attacking Strategies For Breakdown",
            AuthorList{Author{"Adam", "", "Myers"}},
            "Terry Wyatt", "University of Manchester"};
  Thesis t3{"Playing football with deep reinforcement learning",
            AuthorList{Author{"Oscar", "", "Fraley"}},
            "Terry Wyatt", "University of Manchester"};

  // Journals
  Journal nature{"Nature", AuthorList{Author("Nature", "Editor", "A"),
          Author("Nature", "Editor", "B"), Author("Nature", "Editor", "C"),
          Author("Nature", "Editor", "D")}, 65.0, 2, 60, 40,
          set<string>{"Multidisciplinary"}};
  Journal prl{"Physical Review Letters", AuthorList{Author("Joe", "", "Bloggs"),
          Author("Amy", "Lee", "Addams")}, 10.0, 3, 50, 30, set<string>{"Physics"}};
  Journal prd{"Physical Review D", AuthorList{Author("Jason", "owen", "Banks"),
          Author("Mandy", "", "Cooper")}, 4.0, 2, 40, 23, set<string>{"Particle Physics"}};
  Journal jhep{"Journal of High Energy Physics", AuthorList{Author("Peter", "Liam", "Mallard"),
          Author("Ian", "", "Macron")}, 5.0, 5, 58, 40, set<string>{"High Energy Physics"}};
  Journal nano{"Nano Research", AuthorList{Author("Nano", "Editor", "A"),
          Author("Nano", "Editor", "B"), Author("Nano", "Editor", "C")},
          10, 1, 57, 45, set<string>{"Nanoscience", "Nano-technology"}};
  Journal nuclear{"Nuclear Physics B", AuthorList{Author("Mary", "Ball", "Shelley"),
          Author("New", "Cleo", "Urr")}, 3, 4, 57, 45,
          set<string>{"High Energy Physics", "Particle", "Cosmology", "Mathematical Physics"}};
  Journal mnras{"Monthly Notices of the Royal Astronomical Society",
          AuthorList{Author("Mike", "", "Peterson"), Author("Little", "Green", "Man")},
          5, 2, 34, 26, set<string>{"Astrophysics"}};

  // Catalogue
  Catalogue c1{std::make_shared<Book>(b0), std::make_shared<Book>(b1),
               std::make_shared<Book>(b2), std::make_shared<Book>(b3),
               std::make_shared<Book>(b4), std::make_shared<Book>(b5),
               std::make_shared<Book>(b6), std::make_shared<Book>(b7),
               std::make_shared<Book>(b8), std::make_shared<Book>(b9),
               std::make_shared<Thesis>(t0), std::make_shared<Thesis>(t1),
               std::make_shared<Thesis>(t2), std::make_shared<Thesis>(t3),
               std::make_shared<Journal>(nature), std::make_shared<Journal>(prl),
               std::make_shared<Journal>(prd), std::make_shared<Journal>(jhep),
               std::make_shared<Journal>(nano), std::make_shared<Journal>(nuclear),
               std::make_shared<Journal>(mnras)};
  return c1;
}

enum main_option
{
  VIEW_FULL = 0,
  VIEW_SUMMARY = 1,
  SEARCH = 2,
  ADD = 3,
  EDIT = 4,
  REMOVE = 5,
  QUIT = 6
};

namespace main_utils
{
  // Function to present the user with all their browsing options
  main_option get_browsing_choice_from_user()
  {
    string input;
    size_t attempts{0};
    const size_t max_attempts{5};
    
    std::cout<<"Would you like to (0) view full, (1) view summary, (2) search,"
             <<" (3) add, (4) edit, (5) remove, or (6) quit?: ";
    while(attempts<max_attempts)
    {
      std::cin>>input;
      
      if(input=="0") return VIEW_FULL;
      else if(input=="1") return VIEW_SUMMARY;
      else if(input=="2") return SEARCH;
      else if(input=="3") return ADD;
      else if(input=="4") return EDIT;
      else if(input=="5") return REMOVE;
      else if(input=="6") return QUIT;
      else
      {
        std::cout<<"Invalid input. Please enter a number 0-6: ";
        attempts++;
      }
    }
    
    std::cout<<"\nMaximum attempts reached. Defaulting to quit."<<std::endl;
    return QUIT;
  }
}

int main()
{
  // Load in the catalogue
  Catalogue catalogue{prepare_sample_catalogue()};

  // Uncomment this instead to try loading from a file
  // // Get the current working directory
  // std::filesystem::path current_dir = std::filesystem::current_path();
  // std::filesystem::path file_path = current_dir / "sample_catalogue.txt";
  // Catalogue catalogue;
  // catalogue.load_catalogue(file_path);

  bool still_browsing{true};
  main_option option{VIEW_FULL};
  std::cout<<"Your options are to:"<<std::endl
           <<"(0) view the full catalogue"<<std::endl
           <<"(1) view a summary of the catalogue"<<std::endl
           <<"(2) search the catalogue"<<std::endl
           <<"(3) add to the catalogue"<<std::endl
           <<"(4) edit an existing element"<<std::endl
           <<"(5) remove an element"<<std::endl
           <<"or (6) quit."<<std::endl;
  while(still_browsing)
  {
    // Take an action
    option = main_utils::get_browsing_choice_from_user();
    switch(option)
    {
    case VIEW_FULL:
      catalogue.print_catalogue();
      break;
    case VIEW_SUMMARY:
      catalogue.print_summary();
      break;
    case SEARCH:
      catalogue.search();
      break;
    case ADD:
      catalogue.add_entry();
      break;
    case EDIT:
      catalogue.edit_entry();
      break;
    case REMOVE:
      catalogue.remove_entry();
      break;
    default: // QUIT
      still_browsing = false;
      break;
    }
  }
  
  return 0;
}